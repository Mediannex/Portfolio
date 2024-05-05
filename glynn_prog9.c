/* COP 2220 spring, 2024 Program 9,
Charles A. Glynn, 4/22/2024 
program that manages, saves, & organizes information 
via data structures & arrays saving said information 
as a text file */

#define _CRT_SECURE_NO_WARNINGS //for Visual Studio compiler
#pragma warning(disable:6031) //ignore scanf warnings
#include <stdio.h>
#include <ctype.h> //for toupper and tolower
#define SIZE 50

// array structure for customer //
typedef struct {
char OrderName[50];
int OrderNumber;
double OrderAmount;
char location[100];
char validOrder;
}customer;

//(1)greet the user
void Greeting();
//(2)fill the inventory with five customers
void FillFive(customer inventory[]);
//(3)Display the menu, ask, get, and return the user choice
char GetChoice();
//(4)run the program menu (process the choice)
void ProcessMenu(char choice, customer inventory[], int *countPtr);
//(5)print ONE customer information onto the screen
void PrintOneCustomer(customer info);
//(6)print entire VALID customer inventory onto the screen
void PrintValidList(customer inventory[], int count);
//(7)print entire customer inventory(valid and invalid) into a file
void PrintListToFile(customer inventory[], int count);
//(8)Add a new customer into the inventory
void AddCustomerToList(customer inventory[], int count);
//(9)make a customer invalid
void MakeInvalid(customer inventory[], int count);
//(10) Calculate the total and the average of all the valid orders
void CalculateTotalAverage(customer inventory[], int count);

// main function // 
int main()
{
  // declare 2 ints //
  int countPtr, count;
  // assign int variable //
  countPtr = 5;
  // declare 2 arrays //
  customer inventory[50], info;
  // declare a char //
  char choice;
  // function call for customer inventory // 
  FillFive(inventory);
  // function call for greetings //
  Greeting();
  printf("\nFIVE Valid customers have been added to the inventory.\n\n");
  // while loop for menu //
  while (choice != 'Q' && choice != 'q')
  {
    // function call for menu //
    ProcessMenu(choice, inventory, &countPtr);
    // assign choice to function call //
    choice = GetChoice();
  }
  printf("Have a great day!");

  return 0;
}

//(1)greet the user
void Greeting()
{
  // print statement to greet user //
  printf("Welcome to the customer inventory program, please select an option from the menu below.\n");
}

//(2)fill the inventory with five customers
void FillFive(customer inventory[])
{
  // declare variables for array //
  customer temp1 = { "Iron Man", 1, 290.46, "Malibu", 'V' };
  // assign array to variable "temp 1" //
  inventory[0] = temp1;
  customer temp2 = { "Spider Man", 2, 329.33, "New York", 'V' };
  // assign array to variable "temp 2" //
  inventory[1] = temp2;
  customer temp3 = { "Bat Man", 3, 817.14, "Gotham", 'V' };
  // assign array to variable "temp 3" //
  inventory[2] = temp3;
  customer temp4 = { "Super Man", 4, 634.74, "Metropolis", 'V' };
  // assign array to variable "temp 4" //
  inventory[3] = temp4;
  customer temp5 = { "Thor", 5, 750.54, "Asgard", 'V' };
  // assign array to variable "temp 5" //
  inventory[4] = temp5;
}

//(3)Display the menu, ask, get, and return the user choice
char GetChoice()
{
  // declare char //
  char choice;
  // print statements for menu //
  printf("Enter ...A... to add a customer to the inventory\n");
  printf("Enter ...P... to print the information for one customer\n");
  printf("Enter ...V... to print all the valid customers in the inventory\n");
  printf("Enter ...C... to print all the customers (valid and invalid) into a text file\n");
  printf("Enter ...I... to make a customer Invalid\n");
  printf("Enter ...E... to print the orders over a certain amount\n");
  printf("Enter ...T... to calculate the total and average of all the VALID orders\n");
  printf("Enter ...Q... to quit\n");
  // scan for user input //
  scanf(" %c", &choice);

  // return char //
  return choice;
}

//(4)run the program menu (process the choice)
void ProcessMenu(char choice, customer inventory[], int *countPtr)
{
  // declare variable for array //
  customer info;
  // assign variable to array // 
  info = inventory[0];

  // if / if else statements for menu //
  if (choice == 'A' || choice == 'a')
  {
    // function call to add customer to list //
    AddCustomerToList(inventory, *countPtr);
    // increment countPtr //
    *countPtr = *countPtr + 1;
  }
  else if (choice == 'P' || choice == 'p')
  {
    // declare int //
    int num;
    // print order amount //
    printf("\nThere are %d orders\n", *countPtr);
    // ask user for order number //
    printf("Enter the order number for the customer to print: ");
    // scan for user input //
    scanf("%d", &num);
    printf("\n---------------------------------------\n");

    // count loop for array //
    for (int i = 0; i < *countPtr; i++)
    {  
      // if statement for array //
      if (inventory[i].OrderNumber == num)
      {
        // function call to print one customer //
        PrintOneCustomer(inventory[num - 1]);
      }
    }
  }
  else if (choice == 'V' || choice == 'v')
  {
    // function call to print valid list //
    PrintValidList(inventory, *countPtr);
  }
  else if (choice == 'C' || choice == 'c')
  {
    printf("Creating a report\n");
    // function call to print list to file //
    PrintListToFile(inventory, *countPtr);
  }
  else if (choice == 'I' || choice == 'i')
  {
    // function call to make invalid //
    MakeInvalid(inventory, *countPtr);    
  }
  else if (choice == 'E' || choice == 'e') 
  {
    // declare double //
    double amount;
    // ask user for amount //
    printf("Enter amount: ");
    // scan for user input //
    scanf("%lf", &amount);
    // function call to print valid list //
    PrintListToFile(inventory, *countPtr);

    // count loop for array //
    for(int i = 0; i < *countPtr; i++) 
    {
      // if statement for array //
      if(inventory[i].OrderAmount <= amount) 
      {
        // function call to print one customer //
        PrintOneCustomer(inventory[i]); 
      }
    }
  }
  else if (choice == 'T' || choice == 't')
  {
    // function call to calculate total and average //
    CalculateTotalAverage(inventory, *countPtr);
  }
}

//(5)print ONE customer information onto the screen
void PrintOneCustomer(customer info)
{ 
  // print statements for customer information //
  printf("\n---------------------------------------\n");
  printf("\nOrder number:\t\t%d", info.OrderNumber);
  printf("\nName of the order:\t\t%s", info.OrderName);
  printf("\nLocation of the order:\t%s", info.location);
  printf("\nOrder amount:\t\t%.2lf", info.OrderAmount);
  printf("\nValid or invalid:\n");
  // scan user input //
  scanf(" %c", &info.validOrder);
}

//(6)print entire VALID customer inventory onto the screen
void PrintValidList(customer inventory[], int count)
{
  // declare int //
  int i;
  // count loop for array //
  for (i = 0; i < count; i++)
  {
    // if statement for array //
    if (inventory[i].validOrder == 'V')
    {
      // function call to print one customer //
      PrintOneCustomer(inventory[i]);
    }
  }
}

//(7)print entire customer inventory(valid and invalid) into a file
void PrintListToFile(customer inventory[], int count) 
{
  // declare file pointer //
  FILE* outPtr = fopen("report.txt", "w");
  // if statement for file //
  if(outPtr == NULL) 
  {
    printf("Error opening file!");
    return;
  }
  
  // count loop for array //
  for(int i = 0; i < count; i++) 
  {
    // file stream for array //
    fprintf(outPtr,"\n---------------------------------------\n"); 
    fprintf(outPtr,"\nOrder number: %d", inventory[i].OrderNumber);
    fprintf(outPtr,"\nName: %s", inventory[i].OrderName);
    fprintf(outPtr,"\nAmount: $%.2lf", inventory[i].OrderAmount);
    fprintf(outPtr,"\nLocation: %s", inventory[i].location);
    fprintf(outPtr,"\nValid: %c\n", inventory[i].validOrder);
  }

  // close file //
  fclose(outPtr);
}

//(8)Add a new customer into the inventory
void AddCustomerToList(customer inventory[], int count)
{
  // declare variables for array //
  inventory[count].OrderNumber = count + 1;
  // ask user for name //
  printf("Please enter the name of the order: ");
  // scan for user input //
  scanf(" %s", inventory[count].OrderName);

  // ask user for amount //
  printf("Please enter the order amount: ");
  // scan for user input //
  scanf(" %lf", &inventory[count].OrderAmount);

  // ask user for location //
  printf("Please enter the location of purchase:\n");
  // scan for user input //
  scanf(" %s", inventory[count].location);
  // assign variable to array //
  inventory[count].validOrder = 'V';
}

//(9)make a customer invalid
void MakeInvalid(customer inventory[], int count)
{
  // declare int //
  int num;
  // print order amount //
  printf("\nThere are %d orders\n\n", count);
  // ask user for order number //
  printf("Please enter the order number of the customer that is now invalid: ");
  // scan for user input //
  scanf("%d", &num);
  // count loop for array //
  for (int i = 0; i < count; i++) 
  {
    // if statement for array //
    if (inventory[i].OrderNumber == num) 
    {
      // assign variable to array //
      inventory[i].validOrder = 'I';
      return; 
    }
  }
}

//(10) Calculate the total and the average of all the valid orders
void CalculateTotalAverage(customer inventory[], int count)
{
  // declare int & assign variable to 'totalCount' //
  int i, totalCount = 0;
  // declare doubles & assign variables to 'sum' & 'avg' //
  double sum = 0, avg = 0;; 

  // count loop for array //
  for (i = 0; i < count; i++) 
  {
    // if statement for array //
    if (inventory[i].validOrder == 'V') 
    {
      // increment totalCount //
      sum += inventory[i].OrderAmount;
      totalCount++; 
    }
  }   

  // if statement for average //
  if (totalCount > 0) 
  {
    // calculate average //
    avg = sum / totalCount;
  }

  // print statements for total and average //
  printf("The total of all the valid orders is $%.2lf and the avg is $%.2lf\n\n", sum, avg);
}