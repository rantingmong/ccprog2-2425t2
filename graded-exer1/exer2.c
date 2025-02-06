#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  int value;
  printf("Enter a value: ");
  scanf("%d", &value);

  // Its actually 15 because the only multiple of 3 and 5 are 15
  // because in your discrete math 3 and 5 is 3 * 5 = 15
  if (value % 15 == 0)
  {
    printf("FizzBuzz\n");
  }
  else if (value % 3 == 0)
  {
    printf("Fizz\n");
  }
  else if (value % 5 == 0)
  {
    printf("Buzz\n");
  }
  else
  {
    printf("%d\n", value);
  }
}
