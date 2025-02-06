/*
Word split

Program will ask the user for a string, your task is to break the words and print it on separate lines.

Example:

(input)
```
Enter input string: Hello there, mind if I take some of your time?
```

(output)
```
Hello
there
mind
if
I
take
some
of
your
time
```

Requirements:
- Ask the user for the input string (you dont need to check if its over 100 characters).
- Filter out special characters like (, . ? ! - _ / \) before splitting the words.
- Use the searching algorithms we disucssed to perform this exercise.
*/
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

typedef unsigned int uint;

bool contains(char *str, char c)
{
  for (uint i = 0; i < strlen(str); i++)
  {
    if (str[i] == c)
    {
      return true;
    }
  }
  return false;
}

int main(void)
{
  char disallowedChars[] = "\",.?!-_~\\/";
  char input[100];
  char sanitizedInput[100];

  uint inputIndex = 0;
  uint sanitizedInputIndex = 0;

  printf("Enter input string: ");
  scanf("%99[^\n]", input);

  printf("Input: %s\n", input);

  // step1 sanitize input
  for (; inputIndex < strlen(input); inputIndex++)
  {
    if (contains(disallowedChars, input[inputIndex]))
    {
      continue;
    }

    sanitizedInput[sanitizedInputIndex] = input[inputIndex];
    sanitizedInputIndex++;
  }

  // step2 split words

  for (inputIndex = 0; inputIndex < strlen(sanitizedInput); inputIndex++)
  {
    if (sanitizedInput[inputIndex] == ' ')
    {
      sanitizedInput[inputIndex] = '\n';
    }
  }

  printf("Output:\n%s\n", sanitizedInput);

  return 0;
}
