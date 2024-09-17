#include <stdio.h>
#include "numconv1.h"

void test_dec_to_int();
void test_binstr_to_int();
void test_hex_to_int();
void test_oct_to_int();
void test_int_to_dec();
void test_int_to_bin();
void test_int_to_hex();
void test_int_to_oct();


int main() 
{
    printf("Testing convert_num()\n");

    printf("----------------------\n");
    printf("dec_to_int()\n");
    test_dec_to_int();
    printf("----------------------\n");

    printf("binstr_to_integer()\n");
    test_binstr_to_int();
    printf("----------------------\n");

    printf("hex_to_integer()\n");
    test_hex_to_int();
    printf("----------------------\n");

    printf("oct_to_integer()\n");
    test_oct_to_int();
    printf("----------------------\n");

    printf("int_to_dec()\n");
    test_int_to_dec();
    printf("----------------------\n");

    printf("int_to_bin()\n");
    test_int_to_bin();
    printf("----------------------\n");

    printf("int_to_hex()\n");
    test_int_to_hex();
    printf("----------------------\n");

    printf("int_to_oct()\n");
    test_int_to_oct();
    printf("----------------------\n");
    return 0;
}

void test_dec_to_int()
{
    char str[] = "1234";
    int result = dec_to_int(str); 
    printf("Expected: 1234\n");
    printf("Actual: %d\n", result);
    printf("\n");
}

void test_binstr_to_int()
{
    char str[] = "1101";
    int result = binstr_to_int(str); 
    printf("Expected: 13\n");
    printf("Actual: %d\n", result);
    printf("\n");
}

void test_hex_to_int()
{
    char str[] = "1A";
    int result = hex_to_int(str); 
    printf("Expected: 26\n");
    printf("Actual: %d\n", result);
    printf("\n");
}

void test_oct_to_int()
{
    char str[] = "12";
    int result = oct_to_int(str); 
    printf("Expected: 10\n");
    printf("Actual: %d\n", result);
    printf("\n");
}

void test_int_to_dec()
{
    int value = 12;
    printf("Expected: 12\n");
    printf("Actual: ");
    int_to_dec(value);
    printf("\n");
}

void test_int_to_bin()
{
    int value = 12;
    printf("Expected: 1100\n");
    printf("Actual: ");
    int_to_bin(value);
    printf("\n");
}

void test_int_to_hex()
{
    int value = 12;
    printf("Expected: C\n");
    printf("Actual: ");
    int_to_hex(value);
    printf("\n");
}

void test_int_to_oct()
{
    int value = 12;
    printf("Expected: 14\n");
    printf("Actual: ");
    int_to_oct(value);
    printf("\n");
}