#include <stdio.h>
#include <stdlib.h>

int main()
{
    char *p = malloc(10 * sizeof(char));
    printf("Hello, World!\n");
    free(p);
    return 0;
}
