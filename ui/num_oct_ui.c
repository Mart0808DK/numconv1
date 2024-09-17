#include <stdio.h>
#include "../numconv1.h"

void display_oct_menu();
int get_oct_menu_choice();
char* get_oct_to_num_choice();
int get_int_to_oct_value();
void octal_menu();

void display_oct_menu()
{
    printf("Please select an option from the octal menu below\n");
    printf("1. Octal to Integer\n");
    printf("2. Integer to Octal\n");
    printf("3. Exit\n");
}

int get_oct_menu_choice()
{
    char input[10];
    int choice;
    printf("Enter your choice: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &choice);
    return choice;
}

char* get_oct_to_num_choice()
{
    static char input[100];
    fgets(input, sizeof(input), stdin);
    for (int i = 0; i < 100; i++) {
        if (input[i] == '\n') {
            input[i] = '\0';
            break;
        }
    }
    return input;
}

int get_int_to_oct_value()
{
    char input[10];
    int value;
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &value);
    return value;
}

void octal_menu()
{
    int choice, integer;
    char* octal;

    

    while (choice != 3)
    {
        display_oct_menu();
        switch (choice = get_oct_menu_choice())
        {
        case 1:
            printf("Enter an octal number to convert to an integer: ");
            octal = get_oct_to_num_choice();
            integer = oct_to_int(octal);
            printf("%d\n", integer);
            break;
        case 2:
            printf("Enter an integer to convert to octal: ");
            integer = get_int_to_oct_value();
            int_to_oct(integer);
            break;
        case 3:
            printf("Exiting octal menu\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
}