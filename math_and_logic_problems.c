#include <stdio.h>
#include <stdlib.h>

int main()
{

    printf("This C file was created by Sefa Sahin OZ\n");
    printf("NOTE : ALL LENGTH UNITS IN THIS PROGRAM ARE IN 'UNITS'\n\n");


    // Solution to Problem 7.3

    printf("Solution to Problem 7.3 :\n\n");
    printf("This program checks whether a 5-digit integer entered from the keyboard is a palindrome.\n");
    int inputNumber, reversedNumber;
    printf("Enter a 5-digit number: ");
    scanf("%d", &inputNumber);
    if ((inputNumber >= 10000) && (inputNumber <= 99999))
    {
        printf("-----------------------------------------\n");
        reversedNumber = (inputNumber / 10000) + ((inputNumber / 1000) % 10 * 10) + ((inputNumber / 100) % 10 * 100) + ((inputNumber / 10) % 10 * 1000) + ((inputNumber % 10) * 10000);
        if (inputNumber == reversedNumber)
        {
            printf("The number you entered is a palindrome.\n\n\n");
        }
        else
        {
            printf("The number you entered is not a palindrome.\n\n\n");
        }   
    }
    else 
    {
        printf("Please enter a 5-digit number.\n\n\n");
    }
     

    // Solution to Problem 7.12

    printf("Solution to Problem 7.12 : \n\n");
    int fourDigitInput, sumOfDigits;
    printf("This program checks whether a 4-digit integer is a 'cube-sum number' (equal to the cube of the sum of its digits).\n");
    printf("Enter a 4-digit integer: ");
    scanf("%d", &fourDigitInput);
    if ((fourDigitInput >= 1000) && (fourDigitInput <= 9999))
    {
        printf("-----------------------------------------\n");
        sumOfDigits = ((fourDigitInput / 1000) % 10) + ((fourDigitInput / 100) % 10) + ((fourDigitInput / 10) % 10) + (fourDigitInput % 10);
        if (fourDigitInput == (sumOfDigits * sumOfDigits * sumOfDigits))
        {
            printf("The number you entered is a cube-sum number.\n\n\n");
        }
        else
        {
            printf("The number you entered is not a cube-sum number.\n\n\n");
        }
    }
    else
    {
        printf("Please enter a 4-digit number.\n\n\n");
    }
    

    // Solution to Problem 7.16

    printf("Solution to Problem 7.16 :\n\n");
    int correctCount, incorrectCount;
    printf("This program determines your English course level based on your net score.\n");
    printf("4 incorrect answers remove 1 correct answer.\n");
    printf("Enter number of correct answers: ");
    scanf("%d", &correctCount);
    printf("Enter number of incorrect answers: ");
    scanf("%d", &incorrectCount);
    printf("-----------------------------------------\n");
    float netScore = correctCount - (incorrectCount / 4.0);
    printf("Your net score: %.2f\n", netScore);
    if (netScore < 10)
    {
        printf("Your Level: Beginner\n\n\n");
    }
    else if ((netScore >= 10) && (netScore < 30))
    {
        printf("Your Level: Elementary\n\n\n");
    }
    else if ((netScore >= 30) && (netScore < 50))
    {
        printf("Your Level: Pre-Intermediate\n\n\n");
    }
    else if ((netScore >= 50) && (netScore < 70))
    {
        printf("Your Level: Intermediate\n\n\n");
    }
    else 
    {
        printf("Your Level: Upper-Intermediate\n\n\n");
    }


    // Solution to Problem 7.29

    printf("Solution to Problem 7.29 :\n\n");
    printf("This program calculates the area of the selected geometric shape.\n");
    char choice;
    float side1, side2, radius, base, height, area;
    const float PI = 3.14;
    
    printf("---------Menu---------\n");
    printf("(C or c) Circle\n");
    printf("(R or r) Rectangle\n");
    printf("(S or s) Square\n");
    printf("(T or t) Triangle\n");
    printf("----------------------\n");
    printf("Make a choice: ");
    scanf(" %c", &choice);
    printf("----------------------\n");
    printf("Your choice = %c\n", choice);
    printf("----------------------\n");
    
    switch (choice)
    {
    case 's':
    case 'S':
        printf("Enter the side length of the square: ");
        scanf("%f", &side1);
        area = side1 * side1;
        printf("The area of a square with side %.1f units = %.2f square units\n\n\n", side1, area);
        break;
    case 'R':
    case 'r':
        printf("Enter the long side of the rectangle: ");
        scanf("%f", &side1);
        printf("Enter the short side of the rectangle: ");
        scanf("%f", &side2);
        area = side1 * side2;
        printf("The area of the rectangle = %.2f square units\n\n\n", area);
        break;
    case 'T':
    case 't':
        printf("Please enter the base length of the triangle: ");
        scanf("%f", &base);
        printf("Please enter the height of the triangle: ");
        scanf("%f", &height);
        area = (base * height) / 2.0;
        printf("The area of the triangle = %.2f square units\n\n\n", area);
        break;
    case 'C':
    case 'c':
        printf("Please enter the radius of the circle: ");
        scanf("%f", &radius);
        area = radius * radius * PI;
        printf("The area of the circle = %.2f square units\n\n\n", area);
        break;
    default:
        printf("Please make a valid selection.\n\n\n");
        break;
    }

    // Solution to Problem 7.44

    printf("Solution to Problem 7.44 :\n\n");
    printf("This program finds the position (from left) of the smallest digit in a 3-digit integer with unique digits.\n");
    int threeDigitNumber;
    printf("Enter a 3-digit integer with unique digits: ");
    scanf("%d", &threeDigitNumber);
    printf("----------------------\n");
    if ((threeDigitNumber >= 100) && (threeDigitNumber <= 999))
    {
        if ((threeDigitNumber / 100 == threeDigitNumber / 10 % 10) || (threeDigitNumber / 100 == threeDigitNumber % 10) || (threeDigitNumber / 10 % 10 == threeDigitNumber % 10))
        {
            printf("Please enter a number with unique digits.\n\n\n");
        }
        else 
        {
            if ((threeDigitNumber / 100 < threeDigitNumber / 10 % 10) && (threeDigitNumber / 100 < threeDigitNumber % 10))
            {
                printf("The smallest digit is the 1st digit from the left.\n\n\n");
            }
            else if ((threeDigitNumber / 10 % 10 < threeDigitNumber / 100) && (threeDigitNumber / 10 % 10 < threeDigitNumber % 10))
            {
                printf("The smallest digit is the 2nd digit from the left.\n\n\n");
            }
            else 
            {
                printf("The smallest digit is the 3rd digit from the left.\n\n\n");
            }
        }
    }
    else
    {
        printf("Please enter a 3-digit number.\n\n\n");
    }
     
    return 0;      
}