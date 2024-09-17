#include <stdio.h>
#include "num_bin_ui.h"
#include "../numconv1.h"

void display_bin_menu();
int get_bin_menu_choice();
int get_int_to_bin_value();
char* get_bin_to_num_choice();
int binary_menu();

void display_bin_menu()
{
    printf("Please select an option from the binary menu below\n");
    printf("1. Binary to Integer\n");
    printf("2. Integer to Binary\n");
    printf("3. Exit\n");
}

int get_bin_menu_choice()
{
    char input[10];
    int choice;
    printf("Enter your choice: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &choice);
    return choice;
}

int get_int_to_bin_value()
{
    char input[10];
    int value;
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &value);
    return value;
}

char* get_bin_to_num_choice()
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

int binary_menu()
{
    int choice, integer;
    char* binary;

    

    while (choice != 3)
    {
        display_bin_menu();
        printf("Enter your choice: ");

        switch (choice = get_bin_menu_choice()) 
        {
        case 1:
            printf("Enter a binary number to convert to an integer: ");
            binary = get_bin_to_num_choice();

            integer = binstr_to_int(binary);

            printf("The integer value of %s is %d\n", binary, integer);
            break;
        case 2:
            printf("Enter an integer to convert to binary: ");
            integer = get_int_to_bin_value();
            int_to_bin(integer);
            break; 
        case 3:
            printf("Exiting binary menu\n");
            break;
        default:
            printf("Invalid choice\n");
            break;
        }
    }
    
    
    return 0;
}