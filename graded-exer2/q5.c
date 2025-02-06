/*
Pattern checking algorithm

I have a string that on each character:
- Should have the same amount of items
- Should be consecutive
- SHould not occur again when a different character comes after it

Examples:

abc (right)
aabbcc (right)
eerrgg (right)

asfww (wrong)

Requirements:
- Ask the user for the input string (you dont need to check if its over 100 characters).
- Print if the string is valid or not using printf
- For storage, you can use a 2D array. Col items are the character and the number of occurences, Row items are separate character occurences.
- Bonus (+0.25), use structs instead of 2D array to store your state.
- Bonus (+0.25), sort the string first before doing the comparisons
- Bonus (+0.75), do not use an array/array struct for storage.
 */
#include <stdio.h>
#include <string.h>

typedef unsigned int uint;

int main(void)
{
  char foundLettersStorage[100];
  char input[100];

  uint foundLettersCount = 0;
  uint firstLetterCount = 0;

  uint inputIndex = 0;

  printf("Enter a string: ");
  scanf("%s", input);

  while (input[inputIndex] != '\0')
  {
    char currentLetter = input[inputIndex];
    uint currentLetterCount = 1;

    while (input[inputIndex + 1] == currentLetter)
    {
      currentLetterCount++;
      inputIndex++;
    }

    if (foundLettersCount == 0)
    {
      firstLetterCount = currentLetterCount;
    }

    if (foundLettersCount > 0 && currentLetterCount != firstLetterCount)
    {
      printf("Invalid\n");
      return 0;
    }

    if (foundLettersCount > 0 && foundLettersStorage[foundLettersCount - 1] == currentLetter)
    {
      printf("Invalid\n");
      return 0;
    }

    foundLettersStorage[foundLettersCount] = currentLetter;
    foundLettersCount++;
    inputIndex++;
  }

  printf("Valid!\n");

  return 0;
}