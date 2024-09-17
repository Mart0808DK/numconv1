#include <stdio.h>
#include "num_ui.h"

void display_main_menu()
{
    printf("Please select an option from the main menu below\n");
    printf("1. Binary\n");
    printf("2. Hexidecimal\n");
    printf("3. Octal\n");
    printf("4. Exit\n");
}

int get_menu_choice()
{
    char input[10];
    int choice;
    printf("Enter your choice: ");
    fgets(input, sizeof(input), stdin);
    sscanf(input, "%d", &choice);
    return choice;
}