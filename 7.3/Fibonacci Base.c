#include <stdio.h>
#define MAX 40 // define a constant for the array size
int main()
{
  int f[MAX] = {0, 1}, B[MAX], n, m, i; // declare and initialize arrays f and B, and variables n, m, i
  for (i = 2; i < MAX; i++) // compute the Fibonacci sequence and store it in f
    f[i] = f[i-1] + f[i-2];
  scanf("%d", &n); // read the number of test cases n
  while (n--) { // loop for each test case
    scanf("%d", &m); // read the test case m
    printf("%d = ", m); // print m
    for (i = MAX - 1; i > 1; i--) { // find the largest Fibonacci number that is not greater than m
      if (f[i] <= m) { // if the current Fibonacci number is not greater than m
        B[i] = 1; // set the corresponding bit in B to 1
        m -= f[i]; // subtract the Fibonacci number from m
      } else B[i] = 0; // otherwise, set the bit to 0
    }
    i = MAX - 1;
    while (!B[i]) i--; // find the first bit that is 1 in B
    while (i > 1) printf("%d", B[i--]); // print the bits in B from left to right
    printf(" (fib)\n"); // print a newline and "(fib)"
  }
  return 0;
}
