#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char   gender    = 'M';
    char*  name      = "Sigfried";
    int    age       = 37;
    size_t name_size = sizeof(char*);

    printf("The decimal number of age is: %d\n", age);
    printf("The address of age is: %p\n", &age);
    printf("The char of gender is: %c\n", gender);
    printf("The string of name is: %s\n", name);
    printf("The size of name type is: %zu\n", name_size);
    return 0;
}
