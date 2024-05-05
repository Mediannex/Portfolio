/* COP 2220 Spring 2024 Program 7
Charles A. Glynn (STUDENT 2)
4/7/2024
--program that stores user input and converts & prints it all 
to lowercase & '!' '$' & a compound word of all 3-- 
I worked with a partner for this assignment */

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings
#include <stdio.h>
#include <ctype.h> //for toupper and tolower
#include <string.h> //for strlen and strcat and strcpy

// STUDENT 2 //
void CharlesGetInput(char inputWord[]);
void CharlesMakeLower(char inputWord[], char lowerWord[]);
void CharlesDollar(char lowerWord[], char dollarWord[]);
void CharlesCompound(char inputWord [], char lowerWord [], char dollarWord []);

// main function //
int main()
{
  // declare char again, inputWord array, lowerWord array, dollarWord array //
  char again, inputWord[100];
  char lowerWord[100];
  char dollarWord[100];

  // do while loop to keep asking for input //
  do 
  {
    // function call to get input from user //
    CharlesGetInput(inputWord);
    // function call to make input lower case //
    CharlesMakeLower(inputWord, lowerWord);
    // function call to convert input to dollars //
    CharlesDollar(lowerWord, dollarWord);
    // function call to convert input to compound words //
    CharlesCompound(inputWord, lowerWord, dollarWord);
    // prints to display the words //
    printf("The 3 words are\n");
    printf("1. %s\n", inputWord);
    printf("2. %s\n", lowerWord);
    printf("3. %s\n", dollarWord);
    printf("All together (1,2,3) is %s%s%s\n", inputWord,lowerWord,dollarWord);

    // asks user if they want to enter another word //
    printf("Want to enter two more words? (y/n)\n");
    scanf(" %c", &again);
      
  } while (again == 'y' || again == 'Y');
  
  // ends program if user inputs 'N' or 'n' //
  if (again == 'n' || again == 'N')
  {
    printf("Have a great day!");
    return 0;
  }

  return 0;
}

// function definitions //
void CharlesGetInput(char inputWord[])
{
  // get input from user //
  printf("\nEnter a word do not include any spaces in the word:\n");
  scanf(" %s", inputWord);
}

void CharlesMakeLower(char inputWord[], char lowerWord[])
{
  // declare int //
  int i;
  // string copy to lowerWord array //
  strcpy(lowerWord, inputWord); 
  // for loop to make lowerWord array lower case //
  for (i = 0; i < strlen(inputWord); i++)
  {
    lowerWord[i] = tolower(inputWord[i]);
  }
}

void CharlesDollar(char lowerWord[], char dollarWord[])
{
  // declare int //
  int i;
  // for loop to convert lowerWord array to dollarWord array //
  for (i = 0; i < strlen(lowerWord); i++)
  {
    // switch statement to convert lowerWord array to dollarWord array //
    switch (lowerWord[i])
    {
      case 'a':
      case 'e':
      case 'i':
      case 'o':
      case 'u':
      {
        dollarWord[i] = '$';
        break;
      }
        default:
      {
        dollarWord[i] = '!';
        break;
      }
    }
  }
  // null terminator for dollarWord array //
  dollarWord[i] = '\0';
}

void CharlesCompound(char inputWord[], char lowerWord[], char dollarWord[]) 
{
  // declare int & assign lowerLen & inputLen to strlen of lowerWord & inputWord //
  int lowerLen = strlen(lowerWord);
  int inputLen = strlen(inputWord);
  // allocate temp array by concatenate  lowerWord + inputWord //
  char temp[lowerLen + inputLen + 1];
  // concatenate lowerWord with inputWord to temp array //
  strcat(dollarWord, temp);
}