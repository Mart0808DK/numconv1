#include <stdio.h>
#include <stdbool.h>

bool is_digit(char c);
bool is_hex_digit(char c);
bool is_bin_digit(char c);
bool is_octal_digit(char c);


bool is_digit(char c)
{
    return (c >= '0') ? ((c <= '9') ? true : false) : false;
}

bool is_hex_digit(char c) {
    if (c >= '0') {
        if (c <= '9') {
            return true;
        } else {
            if (c >= 'A') {
                if (c <= 'F') {
                    return true;
                } else {
                    if (c >= 'a') {
                        if (c <= 'f') {
                            return true;
                        } else {
                            return false;
                        }
                    } else {
                        return false;
                    }
                }
            } else {
                return false;
            }
        }
    } else {
        return false;
    }
}

bool is_bin_digit(char c) {
    if (c == '0') {
        return true;
    } else {
        if (c == '1') {
            return true;
        } else {
            return false;
        }
    }
}

bool is_octal_digit(char c)
{
    return (c >= '0') ? (c <= '7') : false;
}


int dec_to_int(char str[])
{
    int value = 0;
    int position = (str[0] == '-') ? 1 : 0;
    bool is_negative = (str[0] == '-');
    bool is__valid = true;

    while (str[position] != '\0')
    {
        if (is_digit(str[position]) != false)
        {
            value = value*10 + str[position] - '0';
            position++;
        } else
        {   
            is__valid = false;
            return -1;
        } 
    }
    if (is_negative)
    {
        value = -value;
    }

    return is__valid ? value : -1;
    
}

int binstr_to_int(char str[])
{
    int value = 0;
    int position = (str[0] == '-') ? 1 : 0;
    bool is_negative = (str[0] == '-');
    bool is__valid = true;

    while (str[position] != '\0')
    {
        if (is_bin_digit(str[position]) != false)
        {
            value = value*2 + str[position] - '0';
            position++;
        } else {
            is__valid = false;
            return 0;
        }
    }
    
    if (is_negative)
    {
        value = -value;
    }
    
    return is__valid ? value : -1;
    
}

int hex_to_int(char str[])
{
    int value = 0;
    int position = (str[0] == '-') ? 1 : 0;
    bool is_negative = (str[0] == '-');
    bool is__valid = true;

    while (str[position] != '\0')
    {
        if (is_hex_digit(str[position]) != false)
        {
            if (str[position] >= '0' && str[position] <= '9')
            {
                value = value*16 + str[position] - '0';
            } else if (str[position] >= 'A' && str[position] <= 'F')
            {
                value = value*16 + str[position] - 'A' + 10;
            } else if (str[position] >= 'a' && str[position] <= 'f')
            {
                value = value*16 + str[position] - 'a' + 10;
            }
            position++;
        } else {
            printf("Invalid hex digit\n");
            is__valid = false;
            return 0;
        }
    }

    if (is_negative)
    {
        value = -value;
    }

    return is__valid ? value : 0;
    
}

int oct_to_int(char str[])
{
    int value = 0;
    int position = (str[0] == '-') ? 1 : 0;
    bool is_negative = (str[0] == '-');
    bool is__valid = true;

    while (str[position] != '\0')
    {
        if (is_octal_digit(str[position]) != false)
        {
            value = value*8 + str[position] - '0';
            position++;
        } else {
            is__valid = false;
            return -1;
        }
        
    }

    if (is_negative)
    {
        value = -value;
    }
    
    return value;
    
}

void int_to_dec(int value)
{
    printf("%d\n", value);
}

void int_to_bin(int value)
{
    int binary[32];
    int position = 0;

    while (value > 0)
    {
        binary[position] = value % 2;
        value = value / 2;
        position++;
    }

    for (int i = position - 1; i >= 0; i--)
    {
        printf("%d", binary[i]);
    }
    printf("\n");
}

void int_to_hex(int value)
{
    char hex[32];
    int position = 0;

    while (value > 0)
    {
        int remainder = value % 16;
        if (remainder < 10)
        {
            hex[position] = remainder + '0';
        }
        else
        {
            hex[position] = remainder - 10 + 'A';
        }
        value = value / 16;
        position++;
    }

    for (int i = position - 1; i >= 0; i--)
    {
        printf("%c", hex[i]);
    }
    printf("\n");
}

void int_to_oct(int value)
{
    int octal[32];
    int position = 0;

    while (value > 0)
    {
        octal[position] = value % 8;
        value = value / 8;
        position++;
    }

    for (int i = position - 1; i >= 0; i--)
    {
        printf("%d", octal[i]);
    }
    printf("\n");
}