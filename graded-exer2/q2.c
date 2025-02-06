/*
String any case -> uppercase

Given a string entered by the user, convert it to uppercase.

Requirements:
- Ask the user for the input string (you dont need to check if its over 100 characters)
- Convert the string regardless if its lower or upper to uppercase
- Print the resulting string using printf
- Bonus points (+0.25) if you used the same variable for input, conversion, and display
*/
#include <stdio.h>
#include <string.h>

typedef unsigned int uint;

void toUppercase(char *target)
{
  if (*target >= 'a' && *target <= 'z')
  {
    *target = *target - 32;
  }
}

#ifndef HASMAIN
int main(void)
{
  char input[100];
  uint charIndex = 0;

  printf("Enter a string: ");
  scanf("%s", input);

  for (; charIndex < strlen(input); charIndex += 1)
  {
    toUppercase(&input[charIndex]);
  }

  printf("Uppercase: %s\n", input);

  return 0;
}
#endif
