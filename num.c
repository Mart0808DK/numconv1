#include <stdio.h>
#include "ui/num_bin_ui.h"
#include "ui/num_dec_ui.h"
#include "ui/num_hex_ui.h"
#include "ui/num_oct_ui.h"
#include "ui/num_ui.h"

int main() {
    int choice = 0;

    printf("Welcome to the Number Converter Program!\n");

    while (choice != 4)
    {
        display_main_menu();

        printf("Enter your choice: ");

        switch (choice = get_menu_choice())
        {
        case 1:
            binary_menu();
            break;
        case 2:
            hexidecimal_menu();
            break;
        case 3:
            octal_menu();
            break;
        case 4:
            printf("Thank you for using the Number Converter Program!\n");
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }

    return 0;
}