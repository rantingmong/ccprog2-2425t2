#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  int value;
  int result = 0;

  printf("Enter a value to reverse: ");
  scanf("%d", &value);

  if (value >= 1000000)
  {
    printf("Value is too large\n");
    return;
  }

  while (value > 0)
  {
    result = result * 10 + value % 10;
    value /= 10;
  }

  printf("Reversed value: %d\n", result);
}
