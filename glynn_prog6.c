/* COP 2220 (Program 6) -
Charles A. Glynn, 3/20/24 and description here 
phone purchasing program that uses pointers */
#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings
#include<stdio.h> //for printf and scanf
#include<ctype.h> //for tolower and toupper

// function prototype that returns void & calls 2 doubles, 1 int, & 1 char //
void ProcessChoice(char choice, double *budgetPtr, int *numPtr, double *pricePtr);
// function prototype that returns void & calls 1 char pointer //
void DisplayChoices(char *choice);
// function prototype that returns void & calls void //
void Greeting(void);
// function prototype that returns double & has no call parameters //
double GetBudget();
// function prototype that returns int & calls 1 double //
int DisplayPhones(double budget);
// function prototype that returns double & calls 1 int //
double SetPrice(int itemNumber); 
// function prototype that returns void and calls 1 double pointer & 1 double //
void TryToCheckout(double *budget, double price);
// function prototype that returns void and calls 1 double //
void DisplayBalance(double balance); 

// main function //
int main()
{
  // function declaration of Greeting //
  Greeting();
  // declare doubles price & budget //
  double price, balance, budget;
  // get the initial budget value //
  budget = GetBudget();
  // declare char //
  char choice;
  // function declaration of DisplayBalance to display current budget //
  DisplayBalance(budget); 
  // function declaration of DisplayChoices to display choices //
  DisplayChoices(&choice);
  // declare int //
  int itemNumber;
  // function declaration of ProcessChoice to set choices //
  ProcessChoice(choice, &budget, &itemNumber, &price);

  return 0;
}


// function definitions //
// function definition for user menu //
void ProcessChoice(char choice, double *budgetPtr, int *itemNumberPtr, double *pricePtr)
{
  while(choice == 's'|| choice == 'S' || choice == 'u' || choice == 'U' || choice == 'c' || choice == 'C' || choice == 'q' || choice == 'Q')
  {
    switch (choice)
    {
      // if user inputs s in menu //
      case 's':
      case 'S':
        {
        // tells user budget and price // 
        printf("\nSelect the phone\n");
        // assign integer to function declaration //
        *itemNumberPtr = DisplayPhones(*budgetPtr);
        // assign double to function declaration //
        *pricePtr = SetPrice(*itemNumberPtr);
        }

      break;

      // if user inputs s in menu //
      case 'u':
      case 'U':
        {
        printf("\nUpdate your budget\n");
        // asks user for new budget //
        printf("\nHow much money can you spend for your new phone?\n");
        // scans new budget //
        scanf("%lf", &*budgetPtr);
        // function declaration of DisplayBalance to display updated budget //
        DisplayBalance(*budgetPtr);
        }

      break;

      // if user inputs c in menu // 
      case 'c':
      case 'C':
        {
        TryToCheckout(budgetPtr, *pricePtr);
        }

      break;

      // if user inputs q in menu //
      case 'q':
      case 'Q':
        {
        // ends program //
        printf("\nHave a great day!\n");
        return;
        }

      break;
    }
  // assign choice to function declaration in while loop //
  DisplayChoices(&choice);
  }
}

// function definition to greet the user //
void Greeting()
{
  // greet the user & state purpose of program //
  printf("Welcome to the FANTASTIC PHONE purchasing app\n");
  printf("You will enter your budget for your phone purchase\n");
  printf("You will be presented with a list of phones available for purchase (within your budget)\n");
  printf("Please select the number for the PHONE you wish to purchase\n");
  printf("If you do not like any of the available phones select (-1)\n");
  printf("You will checkout (purchase the phone, if you have enough in your budget)\n");
  printf("You will have the opportunity to update your budget if needed\n");
  printf("You will have the opportunity to purchase more than one phone, until you select 'Q' to QUIT");
}

// function definition to get budget // 
double GetBudget()
{
  // declare double for budget //
  double budget;
  // ask user for budget //
  printf("\nHow much money can you spend on your new phone?");
  // store double for budget //
  scanf("%lf", &budget);

  // return double budget //
  return budget;
}

void DisplayChoices(char *choice)
{
  // display menu //
  printf("\nEnter (s or S) to select a phone");
  printf("\nEnter (u or U) to update your budget");
  printf("\nEnter (c or C) to Checkout");
  printf("\nEnter (q or Q) to Quit");
  printf(" \n");
  // scan input choice by user //
  scanf(" %c", &*choice);
}

// funtion definition to display phones //
int DisplayPhones(double budget)
{
  // declare int for itemNumber //
  int itemNumber;
  //displays the phones and prices //
  do{ 
    printf("\nHere are your options (within your budget):\n");

    // if statements for each phone //
    if (budget >= 999.99)
    {
      printf("1. iPhone 15 Pro . . . . . . . . . . . . . $999.99\n");
    }
    if (budget >= 899.99)
    {
      printf("2. Google pixel 8 Pro. . . . . . . . . . . $799.99\n");
    }
    if (budget >= 1199.99)
    {
      printf("3. Samsung galaxy S23 Ultra. . . . . . . . $1199.99\n");
    }
    if (budget >= 399.99)
    {
      printf("4. Google Pixel 7a . . . . . . . . . . . . $399.99\n");
    }
    if (budget >= 699.99)
    {
      printf("5. OnePlus 11. . . . . . . . . . . . . . . $699.99\n");
    }
    if (budget >= 145.47)
    {
      printf("6. Samsung GalaxyA14 . . . . . . . . . . . $145.47\n");
    }
    if (budget >= 4850000000)
    {
      printf("7. Falcon Supernova iPhone Pink Diamond. . $48,500,000.00\n");
    }
    if (budget >= 44.24)
    {
      printf("8. Samsung Galaxy A03s . . . . . . . . . . $44.24\n\n");
    }

    printf("\nEnter your selection, if you enter a number that is not listed you will not be able to make a purchase:");
    printf("\nIf you do not want any of the options listed, enter -1:");
    // scan input choice for itemNumber //
    scanf("%d", &itemNumber);
  }while(itemNumber < -1 ||  itemNumber > 8);

  // return int itemNumber //
  return itemNumber;
}

// function definition to set the price of the phone //
double SetPrice(int itemNumber)
{ 
  // declare double for price //
  double price;
  // if statement to set price //
  if (itemNumber == -1)
  {
    price = 0;
  }
  else if (itemNumber == 1)
  {
    price = 999.99;
  }
  else if (itemNumber == 2)
  {
    price = 799.99;
  }
  else if (itemNumber == 3)
  {
    price = 1199.99;
  }
  else if (itemNumber == 4)
  {
    price = 399.99;
  }
  else if (itemNumber == 5)
  {
    price = 699.99;
  }
  else if (itemNumber == 6)
  {
    price = 145.47;
  }
  else if (itemNumber == 7)
  {
    price = 48500000.00;
  }
  else if (itemNumber == 8)
  {
    price = 44.24;
  }

  // return double price //
  return price;
}

// function definition to check if the user can afford the phone //
void TryToCheckout(double *budget, double price)
{ 
  // declare double for old balance //
  double oldBudget = *budget;
  printf("\nLet's try to checkout\n");
  // if statement to check if user can afford the phone //
  if (*budget >= price)
  {
    // assign budget pointer to budget pointer minus price //
    *budget = *budget - price;
    // display price & budget // 
    printf("\nThe price is $%.2f and your budget is $%.2f\n", price, oldBudget);
    // display budget //    printf("\nThe price is $%.2f and your budget is $%.2f\n", price, *budget);
    printf("\nThe balance is $%.2lf\n", *budget);
  }
  // else statement to tell user they can't afford the phone //
  else
  {
    // display price & budget // 
    printf("\nThe price is $%.2f and your budget is $%.2f\n", price, oldBudget);
    printf("\nYou cannot buy this phone, you will need to select a different phone OR update your budget\n");
  }

  // if statement for when user inputs -1 //
  if (price == 0)
  {
    printf("\nThe price is $%.2f, you have not selected a phone!\n", price);
  }
}

// function definition to display the balance //
void DisplayBalance(double balance)
{ 
  // print balance //
  printf("\nThe balance is $%.2lf\n", balance);
}