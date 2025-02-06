/*
Palindrome check

A palindrome is basically any string that when reversed contains the same exact word.
Examples include kayak, rotor, level, etc.

Requirements:
- Ask the user for the input string (you dont need to check if its over 20 characters)
- Use algorithm in problem 2 to convert string to uppercase (or lowercase)
- Create a palindrome version of the string
- Use strcmp to check if both strings are equivalent
- Print the result using printf
- DO NOT USE ARRAY ACCESSORS WHEN COMPARING STRINGS, ONLY USE STRCMP
 */

#define HASMAIN
#include "q2.c"

#include <stdio.h>
#include <string.h>

int main(void)
{
  char input[20];
  char palin[20];

  uint inputIndex;
  uint palinIndex;

  printf("Enter a string: ");
  scanf("%s", input);

  inputIndex = 0;
  palinIndex = strlen(input) - 1;

  // leveraging array accessors math to reverse the string
  for (; inputIndex < strlen(input); inputIndex += 1)
  {
    toUppercase(&input[palinIndex - inputIndex]);
    palin[inputIndex] = input[palinIndex - inputIndex];
  }

  if (strcmp(input, palin) == 0)
  {
    printf("Palindrome\n");
  }
  else
  {
    printf("Not a palindrome\n");
  }

  return 0;
}
