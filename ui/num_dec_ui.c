#include <stdio.h>
#include "../numconv1.h"

void display_dec_menu();
int get_dec_menu_choice();
char* get_dec_to_num_choice();
int get_int_to_dec_value();
void decimal_menu();

void display_dec_menu()
{
    printf("Please select an option from the decimal menu below\n");
    printf("1. Decimal to Integer\n");
    printf("2. Integer to Decimal\n");
    printf("3. Exit\n");
}

int get_dec_menu_choice()
{
    char input[10];
    int choice;
    printf("Enter your choice: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &choice);
    return choice;
}

char* get_dec_to_num_choice()
{
    static char input[100];
    fgets(input, sizeof(input), stdin);
    // Manually remove newline character if present
    for (int i = 0; i < 100; i++) {
        if (input[i] == '\n') {
            input[i] = '\0';
            break;
        }
    }
    return input;
}

int get_int_to_dec_value()
{
    char input[10];
    int value;
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &value);
    return value;
}

void decimal_menu()
{
    int choice, integer;
    char* decimal;

    

    while (choice != 3)
    {
        display_dec_menu();
        switch (choice = get_dec_menu_choice())
        {
        case 1:
            printf("Enter a decimal number to convert to an integer: ");   
            decimal = get_dec_to_num_choice();
            dec_to_int(decimal);
            break;
        case 2:
            printf("Enter an integer to convert to decimal: ");
            integer = get_int_to_dec_value();
            int_to_dec(integer);
            break;
        case 3:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
}