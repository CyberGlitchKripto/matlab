# matlab
basic mathematical code
1. Newton Forward difference.
   Newton's Forward Interpolation (NFI):

NFI is a method to estimate the value of a function at a point between known data points. It works by using a difference table (forward differences) 
and applying them to compute the interpolated value.

Example to Understand:

Let’s say you have three data points:
x = [1, 2, 3]
y = [1, 4, 9] (just y = x^2 for simplicity).

Now, I want to find's interpolated value of y at x = 2.5.

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




2. Newton BAckward differnece.

1. Forward vs. Backward Differences:

Forward differences use y[i][j] = y[i-1][j+1] - y[i-1][j], starting from the beginning of the data.
Backward differences use y[i][j] = y[i-1][j] - y[i-1][j-1], starting from the end of the data.


2. Innterpolation Formula:

Forward interpolation uses u = (value - x[0]) / h and terms like (u - j) / (j + 1).
Backward interpolation uses u = (value - x[n-1]) / h (relative to the last x-value) and terms like (u + j) / (j + 1).


3. Accessing the Difference Table:

Forward interpolation uses y[i][0] (first column of each row).
Backward interpolation uses y[i][n-i-1] (last non-zero element in each row).
