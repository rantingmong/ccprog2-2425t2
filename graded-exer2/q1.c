/*
Pattern solving

Create a program that would generate a pattern like this using 2D arrays:

```
******* 0
 -----  1
  ***
 -----
*******
```

Reqirements:
- Ask the user for an odd number (you dont need to check if its an odd number)
- Generate the pattern and store it in the array
- Print the contents of the array using printf
- Rows should have alternating * and -
- Values be stored in a 2D array before printing out
- Bonus points (+0.5) if done using a 1D array

   w  s  c
y  7  0  0
y  5  1  1
y  3  2  0
y  5  1  1
y  7  0  0

*/

#include <stdio.h>

int main(void)
{
  int size = 7;

  int height = size / 2 + 2;
  int width = size;
  int spacing = 0;

  printf("enter a height: ");
  scanf("%d", &size);

  for (int row = 0; row < height; row += 1)
  {
    char toRender = row % 2 == 0 ? '*' : '-';

    for (int col = 0; col < size; col += 1)
    {
      if (col >= spacing && col < (width + spacing))
      {
        printf("%c", toRender);
      }
      else
      {
        printf(" ");
      }
    }

    if (row < height / 2)
    {
      width -= 2;
      spacing += 1;
    }
    else
    {
      width += 2;
      spacing -= 1;
    }

    printf("\n");
  }
}
