/* Charles A. Glynn, 
4/12/2024, 
-- Program 8 --
STUDENT 1
reptile structure */
#define _CRT_SECURE_NO_WARNINGS
#include <string.h>
#include <stdio.h>
#define SIZE 40
typedef struct{
char name[SIZE];
char color[SIZE];
double weight;
}reptile;

// Function Prototypes // 
// function prototype that has no parameters & returns structure reptile //
reptile FillReptile();
// function prototype that has a structure reptile as a parameter & returns nothing //
void FillReptilePtr(reptile *reptilePtr);
// function prototype that has a structure reptile as a parameter & returns nothing //
void FillReptileArray(reptile reptileList[], int *size);
// function prototype that has a structure reptile as a parameter & returns nothing //
void DisplayReptile(reptile anyReptile);

// main function //
int main()
{
    // declare variables for structure reptile //
    reptile reptileList[0], reptilePtr, reptile1, reptile2, reptile3;
    // declare int //
    int size;

    // assign reptile1 to call function FillReptile //
    reptile1 = FillReptile();
    printf("\n---------Display reptile1\n");
    // call function DisplayReptile //
    FillReptilePtr(&reptile1);

    // assign reptile2 to call function FillReptile //
    reptile2 = FillReptile();
    printf("\n---------Display reptile2\n");
    // call function DisplayReptile //
    FillReptilePtr(&reptile2);

    // assign reptile3 to call function FillReptile //
    reptile3 = FillReptile();
    printf("\n---------Display reptile1\n");
    // call function DisplayReptile //
    FillReptilePtr(&reptile3);

    printf("---------Fill array numReptiles\n");
    // call function FillReptileArray //
    FillReptileArray(reptileList, &size);

    printf("\n---------Display array manyCards\n");
    // call function DisplayReptileArray //
    FillReptilePtr(&reptilePtr);
    // loop function for FillReptileArray //
    for (int i = 1; i < size; i++)
    {
      FillReptilePtr(&reptileList[i]);
    }

    return 0;
}

// Function Definitions //
reptile FillReptile()
{
    // declare variables for structure reptile //
    reptile tempReptile;
    printf("Enter the name of the reptile: ");
    scanf("%s", tempReptile.name);
    printf("Enter the color of the reptile: ");
    scanf("%s", tempReptile.color);
    printf("Enter the weight of the reptile: ");
    scanf("%lf", &tempReptile.weight);

    // return structure reptile //
    return tempReptile;
}

void FillReptilePtr(reptile *reptilePtr)
{
    printf("\n\nreptile: %s\n", reptilePtr->name);
    printf("color: %s\n", reptilePtr->color);
    printf("weight: %.2lf\n\n", reptilePtr->weight);
}

void FillReptileArray(reptile reptileList[], int *size)
{
  printf("\nEnter the number of reptiles you want to display: ");
  scanf("%d", size);

  // loop for FillReptileArray //
  for (int i = 0; i < *size; i++)
  {
      printf("Enter reptile name: ");
      scanf("%s", reptileList[i].name);

      printf("Enter reptile color: ");
      scanf("%s", reptileList[i].color);

      printf("Enter reptile weight: ");
      scanf("%lf", &reptileList[i].weight);
  }
}

void DisplayReptile(reptile anyReptile)
{
  printf("Enter the name of the reptile: ");
  scanf("%s", anyReptile.name);
  printf("Enter the color of the reptile: ");
  scanf("%s", anyReptile.color);
  printf("Enter the weight of the reptile: ");
  scanf("%lf", &anyReptile.weight);
}