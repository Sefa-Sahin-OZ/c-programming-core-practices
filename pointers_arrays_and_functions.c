#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function Prototypes
void calculateCoinBreakdown(float*, char*, char*, char*, char*, char*);
void analyzeDigits(int*, char*, char*, char*, char*);
void findClosestToAverage(int*, float*, int*, int*, int*);
void replaceDuplicatesAlgorithm(int*, int);
void rotateFourIntegers(int*, int*, int*, int*, int, char);

int main()
{
    char choice = '1';
    do
    {
        puts("                              ---------------MENU---------------\n");
        puts("1.) Problem 12.23: Finds coin denominations required for a given monetary amount.\n");
        puts("2.) Problem 12.3: Analyzes digit values for an integer up to 4 digits.\n");
        puts("3.) Problem 12.40: Finds average, index, and value closest to average in an array.\n");
        puts("4.) Problem 12.44: Replaces duplicate elements in an integer array with '-1'.\n");
        puts("5.) Problem 12.5: Rotates 4 integer values based on direction and count.\n");
        printf("Please make a choice (0 to exit) : ");
        scanf(" %c", &choice);

        switch (choice)
        {
        case '1' :
        {
            float totalMoney;
            char oneDollar = 0, fiftyCents = 0, twentyFiveCents = 0, tenCents = 0, fiveCents = 0;
            printf("Enter the monetary amount to be converted into coins: ");
            scanf(" %f", &totalMoney);
            calculateCoinBreakdown(&totalMoney, &oneDollar, &fiftyCents, &twentyFiveCents, &tenCents, &fiveCents);
            printf("-------------------------\n%d  x $1.00 Dollar \n%d  x 50 Cents \n%d  x 25 Cents \n%d  x 10 Cents \n%d  x 5 Cents \n", 
                   oneDollar, fiftyCents, twentyFiveCents, tenCents, fiveCents);
            break;
        }

        case '2' :
        {
             int number;
             char ones, tens, hundreds, thousands;
             printf("Please enter an integer with up to 4 digits: ");
             scanf(" %d", &number);
             analyzeDigits(&number, &ones, &tens, &hundreds, &thousands);
             printf("%d -> Ones digit = %d \n%d -> Tens digit = %d \n%d -> Hundreds digit = %d \n%d -> Thousands digit = %d \n", 
                    number, ones, number, tens, number, hundreds, number, thousands);
             break;
        }

        case '3' :
        { 
            float average = 0;
            int size, index;
            printf("Please enter the size of the array: ");
            scanf(" %d", &size);
            int array[size], closestValue, i;
            for (i = 0; i < size; i++)
            {
                printf("Enter element %d of the array : ", i + 1);
                scanf(" %d", &array[i]);
            }
            findClosestToAverage(array, &average, &index, &size, &closestValue);
            printf("\nAverage = %.2f \nValue closest to average = %d // Index = %d\n", average, closestValue, index);   
            break;
        }   

        case '4' :
        {   
            int size;
            printf("Please enter the size of the array: ");
            scanf(" %d", &size);
            int numbers[size];
            for (int i = 0; i < size; i++)
            {
                printf("Enter element %d of the array : ", i + 1);
                scanf(" %d", &numbers[i]);
            }
            replaceDuplicatesAlgorithm(numbers, size);
            puts("Final state of the array after processing: ");
            for (int i = 0; i < size; i++)
            {
                printf("Element %d : %d \n", i + 1, numbers[i]);
            }
            break;
        }

        case '5' :
        {
            int num1, num2, num3, num4, rotationCount;
            char direction;
            printf("Enter 4 integers you want to rotate: ");
            scanf(" %d %d %d %d", &num1, &num2, &num3, &num4);
            printf("Enter rotation direction ('c' for Clockwise, 'a' for Anti-clockwise): ");
            scanf(" %c", &direction);
            printf("Enter how many times to rotate: ");
            scanf(" %d", &rotationCount);
            rotateFourIntegers(&num1, &num2, &num3, &num4, rotationCount, direction);
            printf("Final state of your numbers: %d %d %d %d\n", num1, num2, num3, num4);
            break;
        }

        default: 
            if (choice != '0') 
                puts("Please make a valid selection! (Zero (0) to exit).\n\n");
        }
        
    } while (choice != '0');  

    return 0;
}

void calculateCoinBreakdown(float *amount, char *oneDollar, char *fiftyCents, char *twentyFiveCents, char *tenCents, char *fiveCents)
{
    int totalCents = (int)roundf((*amount) * 100);
    *oneDollar = totalCents / 100;
    totalCents %= 100;
    *fiftyCents = totalCents / 50;
    totalCents %= 50;
    *twentyFiveCents = totalCents / 25;
    totalCents %= 25;
    *tenCents = totalCents / 10;
    totalCents %= 10;
    *fiveCents = totalCents / 5;
}    

void analyzeDigits(int *numberPtr, char *onesPtr, char *tensPtr, char *hundredsPtr, char *thousandsPtr)
{
    *onesPtr = *numberPtr % 10;
    *tensPtr = (*numberPtr / 10) % 10;
    *hundredsPtr = (*numberPtr / 100) % 10;
    *thousandsPtr = (*numberPtr / 1000) % 10; 
}

void findClosestToAverage(int *array, float *average, int *index, int *size, int *closestValue)
{
    int i;
    for (i = 0; i < *size; i++)
    {
        *average += *(array + i);
    }
    *average = (*average) / (*size);
    float minDifference = fabs(*average - *array);
    for (i = 0; i < *size; i++)
    {
        if (fabs(*average - *(array + i)) <= minDifference)
        {
            *closestValue = *(array + i);
            minDifference = fabs(*average - *(array + i));
            *index = i;
        }  
    }
}

void replaceDuplicatesAlgorithm(int *numbers, int size)
{
    int i, j, hasDuplicate;
    for (i = 0; i < size; i++)
    {
        hasDuplicate = 0;
        if (*(numbers + i) == -1) continue;
        for (j = i + 1; j < size; j++)
        {
            if (*(numbers + i) == *(numbers + j))
            {
                *(numbers + j) = -1;
                hasDuplicate = 1;
            }  
        } 
        if (hasDuplicate == 1) *(numbers + i) = -1;
    } 
}

void rotateFourIntegers(int *num1Ptr, int *num2Ptr, int *num3Ptr, int *num4Ptr, int rotationCount, char direction)
{
    int temp;
    if (direction == 'c' || direction == 'C' || direction == 'y')
    {
        for (int i = 0; i < (rotationCount % 4); i++)
        {
            temp = *num4Ptr;
            *num4Ptr = *num3Ptr;
            *num3Ptr = *num2Ptr;
            *num2Ptr = *num1Ptr;
            *num1Ptr = temp;
        }
    }
    else
    {
        for (int i = 0; i < (rotationCount % 4); i++)
        {
            temp = *num1Ptr;
            *num1Ptr = *num2Ptr;
            *num2Ptr = *num3Ptr;
            *num3Ptr = *num4Ptr;
            *num4Ptr = temp;
        }
    }
}