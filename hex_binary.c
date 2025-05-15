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

int main()
{
    char hex[100];    // input hex string
    char binary[400]; // output binary string (each hex character is 4 bits)

    printf("input a hex number: ");
    scanf("%s", hex);

    hex_to_binary(hex, binary);
    printf("binary: %s\n", binary);

    return 0;
}