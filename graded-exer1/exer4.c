#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  int a, b, c;
  printf("Enter a: ");
  scanf("%d", &a);

  printf("Enter b: ");
  scanf("%d", &b);

  printf("Enter c: ");
  scanf("%d", &c);

  // You do not need to create an intricate set of if else statements here
  // as we are SURE that the max value will be the max value on each check
  // we do. So in the first case, we only need comparing a and b, and then
  // the max between that will be compared to c. Lastly, we are just using
  // a again to store the max value so we can save on variables.
  a = a > b ? a : b;
  a = a > c ? a : c;

  printf("Max value is %d\n", a);
}
