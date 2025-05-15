#include <stdio.h>
#include <string.h>

// convert a hex character to a binary string and store it in result
void hex_char_to_binary(char hex, char *result)
{
    switch (hex)
    {
    case '0':
        strcpy(result, "0000");
        break;
    case '1':
        strcpy(result, "0001");
        break;
    case '2':
        strcpy(result, "0010");
        break;
    case '3':
        strcpy(result, "0011");
        break;
    case '4':
        strcpy(result, "0100");
        break;
    case '5':
        strcpy(result, "0101");
        break;
    case '6':
        strcpy(result, "0110");
        break;
    case '7':
        strcpy(result, "0111");
        break;
    case '8':
        strcpy(result, "1000");
        break;
    case '9':
        strcpy(result, "1001");
        break;
    case 'A':
    case 'a':
        strcpy(result, "1010");
        break;
    case 'B':
    case 'b':
        strcpy(result, "1011");
        break;
    case 'C':
    case 'c':
        strcpy(result, "1100");
        break;
    case 'D':
    case 'd':
        strcpy(result, "1101");
        break;
    case 'E':
    case 'e':
        strcpy(result, "1110");
        break;
    case 'F':
    case 'f':
        strcpy(result, "1111");
        break;
    default:
        strcpy(result, "????");
        break; // invalid character
    }
}

// convert a hex string to a binary string
void hex_to_binary(char *hex, char *binary)
{
    char temp[5];     // temporary storage for a single character's binary
    binary[0] = '\0'; // clear the output string
    for (int i = 0; hex[i] != '\0'; i++)
    {
        hex_char_to_binary(hex[i], temp);
        strcat(binary, temp); // concatenate the binary fragment
    }
}

// convert a binary string to a hex string
void binary_to_hex(char *binary, char *hex)
{
    int len = strlen(binary);
    int i = 0;

    // clear the output string
    hex[0] = '\0';

    // handle the case where the length of the binary string is not a multiple of 4
    // pad the binary string with leading zeros
    int padding = 0;
    if (len % 4 != 0)
    {
        padding = 4 - (len % 4);
    }

    char padded_binary[len + padding + 1];

    // add leading zeros
    for (i = 0; i < padding; i++)
    {
        padded_binary[i] = '0';
    }

    // copy the original binary string
    strcpy(padded_binary + padding, binary);

    // convert every 4 bits of binary to 1 hex character
    for (i = 0; i < strlen(padded_binary); i += 4)
    {
        char chunk[5] = {0}; // 4 bits of binary + the null terminator
        strncpy(chunk, padded_binary + i, 4);

        // convert 4 bits of binary to a hex character
        if (strcmp(chunk, "0000") == 0)
            strcat(hex, "0");
        else if (strcmp(chunk, "0001") == 0)
            strcat(hex, "1");
        else if (strcmp(chunk, "0010") == 0)
            strcat(hex, "2");
        else if (strcmp(chunk, "0011") == 0)
            strcat(hex, "3");
        else if (strcmp(chunk, "0100") == 0)
            strcat(hex, "4");
        else if (strcmp(chunk, "0101") == 0)
            strcat(hex, "5");
        else if (strcmp(chunk, "0110") == 0)
            strcat(hex, "6");
        else if (strcmp(chunk, "0111") == 0)
            strcat(hex, "7");
        else if (strcmp(chunk, "1000") == 0)
            strcat(hex, "8");
        else if (strcmp(chunk, "1001") == 0)
            strcat(hex, "9");
        else if (strcmp(chunk, "1010") == 0)
            strcat(hex, "A");
        else if (strcmp(chunk, "1011") == 0)
            strcat(hex, "B");
        else if (strcmp(chunk, "1100") == 0)
            strcat(hex, "C");
        else if (strcmp(chunk, "1101") == 0)
            strcat(hex, "D");
        else if (strcmp(chunk, "1110") == 0)
            strcat(hex, "E");
        else if (strcmp(chunk, "1111") == 0)
            strcat(hex, "F");
        else
            strcat(hex, "?"); // invalid binary
    }
}

int main()
{
    char hex[100];    // input hex string
    char binary[400]; // output binary string (each hex character is 4 bits)
    int choice;

    printf("choose the operation:\n");
    printf("1. hex to binary\n");
    printf("2. binary to hex\n");
    scanf("%d", &choice);

    if (choice == 1)
    {
        printf("input the hex number: ");
        scanf("%s", hex);

        hex_to_binary(hex, binary);
        printf("binary: %s\n", binary);
    }
    else if (choice == 2)
    {
        printf("input the binary number: ");
        scanf("%s", binary);

        binary_to_hex(binary, hex);
        printf("hex: %s\n", hex);
    }
    else
    {
        printf("invalid choice\n");
    }

    return 0;
}