#include<stdio.h>
#define MAX 100   // tarbesi handle kora sombhob noy


// Function to calculate forward difference table
void forward_difference(float x[], float y[][MAX], int n) {   //ekahne forward dff theke float nebo 2 tor-> x,y er, x-single, y mingle with max gf with n bitch.
    for (int i = 1; i < n; i++) {                    // i mane akta gf hobei 
        for (int j = 0; j < n - i; j++) {            // j= single sala, i er gf dekhe jole jay
            y[i][j] = y[i - 1][j + 1] - y[i - 1][j];  // difference bar korlam
        }
    }
}

// Newton's Forward Interpolation Function
float NFI(float x[], float y[][MAX], int n, float value) {// ager tai moto just x abar y ke tar value dekhachhe
    float h = x[1] - x[0];  // Assuming uniform spacing
    float u = (value - x[0]) / h;
    float result = y[0][0];  // Start with the first y-value

    for (int i = 1; i < n; i++) {
        float term = y[i][0];    // dhor i =1 nili, tahole dekhabe term =y[1][0]
        for (int j = 0; j < i; j++) {  // ebar j satisfy
            term *= (u - j) / (j + 1);   // no need to do factorial, this part did that.....
        }
        result += term; // term ke update kor
    }
    return result;
}

int main() {
    int n;
    float x[MAX], y[MAX][MAX], value;   // ebar x er value dekhe max gf esegache but 1ta.

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

    // Calculate the forward difference table
    forward_difference(x, y, n);

    // Optionally print the forward difference table
    printf("\nForward Difference Table:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i; j++) {
            printf("%8.4f ", y[i][j]);
        }
        printf("\n");
    }

    // Input value to interpolate
    printf("Enter the value to interpolate: ");
    scanf("%f", &value);

    // Perform interpolation
    float result = NFI(x, y, n, value);
    printf("The interpolated value at x = %.2f is: %.4f\n", value, result);

    return 0;
}

/*
Newton's Forward Interpolation (NFI):

NFI is a method to estimate the value of a function at a point between known data points. It works by using a difference table (forward differences) 
and applying them to compute the interpolated value.

Example to Understand:

Let’s say you have three data points:
x = [1, 2, 3]
y = [1, 4, 9] (which are just y = x^2 for simplicity).

Now, I want to find the interpolated value of y at x = 2.5.

Forward Difference Table:

1. First, I calculate the first-order differences:
   Δy0 = y[1] - y[0] = 4 - 1 = 3
   Δy1 = y[2] - y[1] = 9 - 4 = 5

2. Then calculate the second-order differences:
   Δ²y0 = Δy1 - Δy0 = 5 - 3 = 2

So the table looks like:

    1.0    4.0    9.0                 // this all y values    x like  1  2  3 given before
    3.0    5.0
    2.0

Using the Forward Difference Table to Interpolate:

3. You calculate u = (2.5 - 1) / 1 = 1.5.

4. Then apply the formula:
   f(2.5) = y[0][0] + u * Δy0 + (u(u - 1) / 2!) * Δ²y0
   Substituting the values:
   f(2.5) = 1 + 1.5 * 3 + (1.5 * (1.5 - 1) / 2) * 2
           = 6.25

The interpolated value at x = 2.5 is 6.25.
*/