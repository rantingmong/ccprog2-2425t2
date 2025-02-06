#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(void)
{
  int valueToGuess = rand() % 10;
  int valueToCheck;

  for (int i = 0; i < 5; i += 1)
  {
    printf("Guess a number between 1 to 10: ");
    scanf("%d", &valueToCheck);

    if (valueToCheck == valueToGuess)
    {
      printf("You guessed it!\n");
      return EXIT_SUCCESS;
    }
    else
    {
      printf("Try again\n");
    }
  }
}