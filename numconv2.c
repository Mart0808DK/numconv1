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

bool is_hex_digit(char c)
{
    if (c >= '0')
    {
        if (c <= '9')
        {
            return true;
        }
        else
        {
            if (c >= 'A')
            {
                if (c <= 'F')
                {
                    return true;
                }
                else
                {
                    if (c >= 'a')
                    {
                        if (c <= 'f')
                        {
                            return true;
                        }
                        else
                        {
                            return false;
                        }
                    }
                    else
                    {
                        return false;
                    }
                }
            }
            else
            {
                return false;
            }
        }
    }
    else
    {
        return false;
    }
}

bool is_bin_digit(char c)
{
    if (c == '0')
    {
        return true;
    }
    else
    {
        if (c == '1')
        {
            return true;
        }
        else
        {
            return false;
        }
    }
}

bool is_octal_digit(char c)
{
    return (c >= '0') ? (c <= '7') : false;
}

void dec_to_int(int num, char str[])
{
    int value = 0;
    int position = (str[0] == '-') ? 1 : 0;
    bool is_negative = (str[0] == '-');
    bool is__valid = true;

    while (str[position] != '\0')
    {
        if (is_digit(str[position]) != false)
        {
            value = (value << 3) + (value << 1) + str[position] - '0';
            position++;
        }
        else
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

void bin_to_int(int num, char str[])
{
    int value = 0;
    int position = (str[0] == '-') ? 1 : 0;
    bool is_negative = (str[0] == '-');
    bool is__valid = true;

    while (str[position] != '\0')
    {
        if (is_bin_digit(str[position]) != false)
        {
            value = (value << 1) + str[position] - '0';
            position++;
        }
        else
        {
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

void hex_to_int(int num, char str[])
{
    int value = 0;
    int position = (str[0] == '-') ? 1 : 0;
    bool is_negative = (str[0] == '-');
    bool is__valid = true;

    while (str[position] != '\0')
    {
        if (is_hex_digit(str[position]) != false)
        {
            value <<= 4;
            if (str[position] >= '0' && str[position] <= '9')
            {
                value |= (str[position] - '0');
            }
            else if (str[position] >= 'A' && str[position] <= 'F')
            {
                value |= (str[position] - 'A' + 10);
            }
            else if (str[position] >= 'a' && str[position] <= 'f')
            {
                value |= (str[position] - 'a' + 10);
            }
            position++;
        }
        else
        {
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

void oct_to_int(int num, char str[])
{
    int value = 0;
    int position = (str[0] == '-') ? 1 : 0;
    bool is_negative = (str[0] == '-');
    bool is__valid = true;

    while (str[position] != '\0')
    {
        value <<= 3;
        if (is_octal_digit(str[position]) != false)
        {
            value |= (str[position] - '0');
            position++;
        }
        else
        {
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

void int_to_bin(int num, char str[])
{
    unsigned int remain = num;
    int position = 0;

    do
    {
        str[position++] = '0' + (remain & 1);
        remain >>= 1;
    } while (remain > 0);

    str[position] = '\0';

    int len = position;
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void int_to_hex(int num, char str[])
{
    unsigned int remain = num;
    int position = 0;

    do
    {
        int digit = remain & 0xF;
        if (digit < 10)
            str[position++] = '0' + digit;
        else
            str[position++] = 'A' + (digit - 10);
        remain >>= 4;
    } while (remain > 0);

    str[position] = '\0';

    int len = position;
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}

void int_to_oct(int num, char str[])
{
    unsigned int remain = num;
    int position = 0;

    do
    {
        str[position++] = '0' + (remain & 7);
        remain >>= 3;
    } while (remain > 0);

    str[position] = '\0';

    int len = position;
    for (int i = 0; i < len / 2; i++)
    {
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}