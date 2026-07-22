#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure Definitions
struct Book {
    char *title;
    char *author;
    int pages;
    int year;
};

struct UserInfo {
    char *username;
    int age;
};

// Enum Definition
enum Flag {
    FLAG_FALSE = 0,
    FLAG_TRUE = 1
};

// Function Prototypes
void printUserInfoByValue(struct UserInfo user);
void printUserInfoByPointer(const struct UserInfo *userPtr);

int main()
{
    char choice = '1';

    do
    {
        puts("\n                              ---------------MENU---------------\n");
        puts("1.) Book Information System (Structs & Arrays)");
        puts("2.) User Information System (Pass-by-Value & Pass-by-Reference)");
        puts("3.) Status Check System (Enum Control)");
        puts("0.) Exit");
        printf("\nPlease make a selection (0 to exit) : ");
        scanf(" %c", &choice);
        printf("\n");

        switch (choice)
        {
        case '1':
        {
            printf("-----------------------------------\n");
            printf("1. Book Information System\n");
            printf("-----------------------------------\n");

            struct Book books[2];

            books[0].title = "Harry Potter and the Philosopher's Stone";
            books[0].author = "J.K. Rowling";
            books[0].pages = 238;
            books[0].year = 1999;

            books[1].title = "This Country";
            books[1].author = "Cemil Meric";
            books[1].pages = 245;
            books[1].year = 1960;

            for (int i = 0; i < 2; i++)
            {
                printf("\nBook %d :\n", i + 1);
                printf("-----------------------------------\n");
                printf("Book Title   : %s\n", books[i].title);
                printf("Author       : %s\n", books[i].author);
                printf("Page Count   : %d\n", books[i].pages);
                printf("Release Year : %d\n", books[i].year);
            }
            break;
        }

        case '2':
        {
            printf("-----------------------------------\n");
            printf("2. User Information System\n");
            printf("-----------------------------------\n");

            // Pass-by-value demonstration
            struct UserInfo user1;
            user1.username = "Sefa";
            user1.age = 18;

            printf("[Pass-by-Value Output]:\n");
            printUserInfoByValue(user1);

            // Pass-by-reference (pointer) demonstration
            struct UserInfo user2;
            struct UserInfo *userPtr = &user2;
            (*userPtr).username = "Sefa";
            (*userPtr).age = 18;

            printf("\n[Pass-by-Reference Output]:\n");
            printUserInfoByPointer(userPtr);

            break;
        }

        case '3':
        {
            printf("-----------------------------------\n");
            printf("3. Status Check System (Enum)\n");
            printf("-----------------------------------\n");

            enum Flag status;
            status = FLAG_TRUE;

            if (status)
            {
                printf("Operation successful.\n");
            }
            else
            {
                printf("Operation failed.\n");
            }
            break;
        }

        case '0':
            printf("Exiting program...\n");
            break;

        default:
            printf("Please make a valid selection! (0 to exit).\n");
            break;
        }

    } while (choice != '0');

    return 0;
}

void printUserInfoByValue(struct UserInfo user)
{
    printf("Username : %s\n", user.username);
    printf("Age      : %d\n", user.age);
}

void printUserInfoByPointer(const struct UserInfo *userPtr)
{
    // Arrow operator (->) usage for pointer access
    printf("Username : %s\n", userPtr->username);
    printf("Age      : %d\n", userPtr->age);
}