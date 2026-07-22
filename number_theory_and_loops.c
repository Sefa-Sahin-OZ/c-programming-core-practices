#include <stdlib.h>
#include <stdio.h>

int main()
{
    printf("\nThis program was created by Sefa Sahin OZ.\n\n");
    int choice = 1;

    while (choice != 0)
    {   
        printf("\nMENU\n");
        printf("1-Problem 8.1\n");
        printf("2-Problem 8.2\n");
        printf("3-Problem 8.3\n");
        printf("4-Problem 8.32\n");
        printf("5-Problem 8.38\n");
        printf("6-Problem 8.41\n");
        printf("7-Problem 8.43\n");
        printf("8-Problem 8.53\n");
        printf("9-EXIT\n\n");
        printf("Please make your selection (9 to EXIT) : ");
        scanf("%d", &choice);
        printf("\n");
        
        switch (choice)
        {

        case 1:
            printf("------------------------------\n");
            printf("Your selection : Number %d. \n", choice);
            printf("------------------------------\n\n");
            printf("Solution to Problem 8.1 :\n\n");

            int value;
            printf("Octal and hexadecimal equivalents of numbers between 0 and 15 : \n\n");
            printf("DECIMAL |  OCTAL     |  HEXADECIMAL\n");
            
            for (value = 0; value <= 15; value++)
            {
                printf("%-8d|  %-10o|  %-10x\n", value, value, value);
                printf("------------------------------\n");
            }
               
            break;

        case 2:
            printf("------------------------------\n");
            printf("Your selection : Number %d. \n", choice);
            printf("------------------------------\n\n");
            printf("Solution to Problem 8.2 :\n\n");

            int n, counter;
            float result = 0;
            printf("For a number 'n' entered from the keyboard, this program calculates: (1+1)/1 + (2+1)/2 +...+ (n+1)/n and prints the result.\n");
            printf("Please enter a number : ");
            scanf("%d", &n);
            for (counter = 1; counter <= n; counter++)
            {
                result += (float)(counter + 1) / counter;
            }
            printf("Result = %.2f\n", result);
            
            break;

        case 3:
            printf("------------------------------\n");
            printf("Your selection : Number %d. \n", choice);
            printf("------------------------------\n\n");
            printf("Solution to Problem 8.3 :\n\n");
            
            int asciiCode;
            printf("ASCII CODE    UPPERCASE      LOWERCASE\n");
            for (asciiCode = 65; asciiCode <= 84; asciiCode++)
            {
                printf("%d             %c              %c\n", asciiCode, asciiCode, (asciiCode + 32));
            }

            break;

        case 4:
            printf("------------------------------\n");
            printf("Your selection : Number %d. \n", choice);
            printf("------------------------------\n\n");
            printf("Solution to Problem 8.32 :\n\n");  
            
            int k = 1, number, smallest1, smallest2;
            do
            {
                printf("Enter a number : ");
                scanf("%d", &number);
                
                if (k == 1)
                {
                    smallest1 = number;
                }
                if (k == 2) 
                {
                    smallest2 = number;
                }
                if (number <= smallest1)
                {
                    smallest2 = smallest1;
                    smallest1 = number;
                }
                else if (smallest2 > number)
                {
                    smallest2 = number;
                }              
                k++;
            } while (k <= 10);
           
            printf("1st smallest = %d ", smallest1);
            printf("2nd smallest = %d \n", smallest2);
            
            break;

        case 5:
            printf("------------------------------\n");
            printf("Your selection : Number %d. \n", choice);
            printf("------------------------------\n\n");
            printf("Solution to Problem 8.38 :\n\n");

            printf("This program prints the perfect numbers between 1 and 1000.\n\n");
            int j, l, sumOfDivisors = 0;
            for (j = 2; j < 1000; j++)
            {
                sumOfDivisors = 0;
                for (l = 1; l < j; l++)
                {
                    if (j % l == 0)
                    {
                        sumOfDivisors += l;
                    }
                }   
                if (sumOfDivisors == j)
                {
                    printf("%d,", j);
                }
            }
            printf("\b \n---------");
            
            break;

        case 6:   
            printf("------------------------------\n");
            printf("Your selection : Number %d. \n", choice);
            printf("------------------------------\n\n");
            printf("Solution to Problem 8.41 :\n\n");

            printf("This program checks if the number you entered is an abundant number.\n\n");
            int a, b, sumOfProperDivisors = 0, inputNumber;
            printf("Please enter a number : ");
            scanf("%d", &inputNumber);
            for (a = 1; a < inputNumber; a++)
            {
                if (inputNumber % a == 0)
                {
                    sumOfProperDivisors += a;
                }
            }
            if (sumOfProperDivisors > inputNumber)
            {
                printf("The entered number is an abundant number.\n");
            }
            else
            {
                printf("The entered number is not an abundant number.\n");
            }
            
            break;

        case 7:
            printf("------------------------------\n");
            printf("Your selection : Number %d. \n", choice);
            printf("------------------------------\n\n");
            printf("Solution to Problem 8.43 :\n\n");

            int x, y, divisorCount = 0, maxDivisors = 0, numberWithMaxDivisors;
            for (x = 2; x < 1000; x++)
            {   
                divisorCount = 0;
                for (y = 1; y <= x; y++)
                {              
                    if (x % y == 0)
                    {
                       divisorCount++;
                    }
                }
                if (divisorCount > maxDivisors)
                {
                    maxDivisors = divisorCount;
                    numberWithMaxDivisors = x;
                }
            }
            printf("Number with the most divisors : %d (Divisor count : %d)\n", numberWithMaxDivisors, maxDivisors);
            
            break;

        case 8:
            printf("------------------------------\n");
            printf("Your selection : Number %d. \n", choice);
            printf("------------------------------\n\n");
            printf("Solution to Problem 8.53 :\n\n");

            int previousNumber, currentInput;
            printf("Please enter the first number : ");
            scanf("%d", &previousNumber);
            while (1)
            {
                printf("Please enter a number (Enter the previous number to return to MENU) : ");
                scanf("%d", &currentInput);
                if (previousNumber == currentInput)
                {
                    break;
                }
                if (previousNumber < currentInput)
                {
                    printf("INCREASING\n");
                }
                else
                {
                    printf("DECREASING\n");
                }
                previousNumber = currentInput;
            }
           
            break;
            
        case 9: 
            return 0;
            
        default:
            printf("Your selection : Number %d. \n\nPlease make a valid selection.\n", choice);
        }
    }
}