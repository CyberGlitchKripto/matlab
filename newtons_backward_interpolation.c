#include<stdio.h>
#define MAX 100 // tarbesi handle kora sombhob noy


// Function to calculate backward difference table
void backward_difference(float x[], float y[][MAX], int n) {  // ekahne backward diff theke float nebo 2 tor-> x,y er, x-single, y mingle with max gf with n bitch.
    for (int i = 1; i < n; i++) { // i mane akta gf hobei
        for (int j = n - 1; j >= i; j--) {                                                        ///changes here
            y[i][j] = y[i - 1][j] - y[i - 1][j - 1]; // difference bar korlam, backward style
        }
    }
}

// Newton's Backward Interpolation Function
float NBI(float x[], float y[][MAX], int n, float value) {
    float h = x[1] - x[0]; // Assuming uniform spacing
    float u = (value - x[n - 1]) / h; // u from the last x-value   /// changes here
    float result = y[0][n - 1]; // Start with the last y-value    ///  changes here
    float term = 1.0;
    
    for (int i = 1; i < n; i++) {
        term = term * u / i;
            for (int j = 0; j < i - 1; j++) {
                term = term * (u + j + 1);
            }
        result += term * y[i][n - 1];
        term = 1.0;
    }
    
    return result;
}

int main() {
    int n;
    float x[MAX], y[MAX][MAX], value; // ebar x er value dekhe max gf esegache but 1ta.

    // Input number of data points
    printf("Enter the number of data points: ");
    scanf("%d", &n);

    // Input data points
    if (n <= 1) {
        printf("Number of data points should be greater than 1.\n");
        return -1;  // Early exit if n is invalid
    }

    printf("Enter data points (X Y):\n");
    for (int i = 0; i < n; i++) {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
        printf("y[%d]: ", i);
        scanf("%f", &y[0][i]);  // Store y-values in the first row
    }

    // Calculate the backward difference table
    backward_difference(x, y, n);

    // Optionally print the backward difference table
    printf("\nBackward Difference Table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {  // Print entire table for clarity
            if (j >= i) printf("%8.4f ", y[i][j]);
        }
        printf("\n");
    }

    // Input value to interpolate
    printf("Enter the value to interpolate: ");
    scanf("%f", &value);

    // Perform interpolation
    float result = NBI(x, y, n, value);
    printf("The interpolated value at x = %.2f is: %.4f\n", value, result);

    return 0;
}

/*
1. Forward vs. Backward Differences:

Forward differences use y[i][j] = y[i-1][j+1] - y[i-1][j], starting from the beginning of the data.
Backward differences use y[i][j] = y[i-1][j] - y[i-1][j-1], starting from the end of the data.


2. Innterpolation Formula:

Forward interpolation uses u = (value - x[0]) / h and terms like (u - j) / (j + 1).
Backward interpolation uses u = (value - x[n-1]) / h (relative to the last x-value) and terms like (u + j) / (j + 1).


3. Accessing the Difference Table:

Forward interpolation uses y[i][0] (first column of each row).
Backward interpolation uses y[i][n-i-1] (last non-zero element in each row).
*/