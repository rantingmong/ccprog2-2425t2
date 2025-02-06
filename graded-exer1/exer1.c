#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/*
  Print an array that'll look like this given an input:
  ~~~*~~~
  ~~***~~
  ~*****~
  *******

  Initialization:

    midStart: The middle point of the pyramid, we decrease this by 1 each row
    midSize: The size of the middle part of the pyramid, we increase this by 2 each row

    Explanation

    Let's check the pyramid above:

    ~~~*~~~ // midStart = 3, midSize = 1
    ~~***~~ // midStart = 2, midSize = 3
    ~*****~ // midStart = 1, midSize = 5
    ******* // midStart = 0, midSize = 7

    That's how we know that we should decrease midStart by 1 and increase midSize by 2 each row

    height: The height of the pyramid, we get the placement of the specified size by
    dividing it by 2 and rounding it up. Its because that for example, if we have a size of 9
    its placement is 5 because 1, 3, 5, 7, **9**.

  The for loop:

    We do not need to create three for loops here, just check the midpoint and the size vs the
    x position in the pyramid and if its in the range of midpoint...(midpoint + midSize) we print *
    otherwise we print ~.
 */
void printArray(int size)
{
  int midStart = size / 2;
  int midSize = 1;
  int height = ceil((float)size / 2);

  for (int y = 0; y < height; y += 1)
  {
    for (int x = 0; x < size; x += 1)
    {
      if (x >= midStart && x < midStart + midSize)
      {
        printf("*");
      }
      else
      {
        printf("~");
      }
    }

    midStart -= 1;
    midSize += 2;

    printf("\n");
  }
}

int main(void)
{
  int size;
  printf("enter size ");
  scanf("%d", &size);

  printArray(size);

  return EXIT_SUCCESS;
}
