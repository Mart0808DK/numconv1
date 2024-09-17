#include <stdio.h>
#include "../numconv1.h"

void display_hex_menu();
int get_hex_menu_choice();
char* get_hex_to_num_choice();
int get_int_to_hex_value();
void hexidecimal_menu();

void display_hex_menu()
{
    printf("Please select an option from the hexidecimal menu below\n");
    printf("1. Integer to Heximal\n");
    printf("2. Hexidecimal to Integer\n");
    printf("3. Exit\n");
}

int get_hex_menu_choice()
{
    char input[10];
    int choice;
    printf("Enter your choice: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &choice);
    return choice;
}


char* get_hex_to_num_choice()
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

int get_int_to_hex_value()
{
    char input[10];
    int value;
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &value);
    return value;
}

void hexidecimal_menu() {
    int choice, integer;
    char* hexidecimal;

    

    while (choice != 3)
    {   
        display_hex_menu();
        switch (choice = get_hex_menu_choice())
        {
        case 1:
            printf("Enter an integer to convert to hexidecimal: ");
            integer = get_int_to_hex_value();
            int_to_hex(integer);
            break;
        case 2:
            printf("Enter a hexidecimal number to convert to an integer: ");
            hexidecimal = get_hex_to_num_choice();
            hex_to_int(hexidecimal);
            break;
        case 3:
            break;
            default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }
}