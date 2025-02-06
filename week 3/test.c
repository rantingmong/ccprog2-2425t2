#include <stdlib.h>
#include <stdio.h>

void selectionSort(int input[], int length)
{
  int i, j, minIndex, swapTemp;

  for (i = 0; i < length - 1; i++)
  {
    minIndex = i;

    for (j = i + 1; j < length; j++)
    {
      if (input[j] < input[minIndex])
      {
        minIndex = j;
      }
    }

    if (minIndex != i)
    {
      swapTemp = input[i];
      input[i] = input[minIndex];

      input[minIndex] = swapTemp;
    }

    printf("Iteration %2d#:", i + 1);
    printf(" minVal: %2d (%2d from %2d) -> ", input[i], i, minIndex);

    for (int k = 0; k < length; k++)
    {
      printf("%d ", input[k]);
    }

    printf("\n");
  }
}

int linearSearch(int input[], int length, int itemToFind)
{
  for (int i = 0; i < length; i++)
  {
    if (input[i] == itemToFind)
    {
      return i;
    }
  }

  return -1;
}

int binarySearch(int input[], int length, int itemToFind)
{
  int midPoint = 0, low = 0, high = length - 1;

  while (low <= high)
  {
    midPoint = (low + high) / 2;

    if (input[midPoint] == itemToFind)
    {
      return midPoint;
    }
    else if (input[midPoint] < itemToFind)
    {
      low = midPoint + 1;
    }
    else
    {
      high = midPoint - 1;
    }
  }

  return -1;
}

int main(void)
{
  int input[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
  int length = sizeof(input) / sizeof(input[0]);
  int itemToFind = 0;

  printf("Enter the item to find: ");
  scanf("%d", &itemToFind);

  int result = binarySearch(input, length, itemToFind);
  printf("Item found at index: %d\n", result);

  int input2[] = {3, 5, 3, 6, 7, 8, 9, 1, 2, 4, 0};
  length = sizeof(input2) / sizeof(input2[0]);

  selectionSort(input2, length);

  for (int i = 0; i < length; i++)
  {
    printf("%d ", input2[i]);
  }

  printf("\n");

  return 0;
}
