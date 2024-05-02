#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[] = "Salam Lalem netersen be";

    int index = -1;
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == 'a' || str[i] == 'b' || str[i] == 's' || str[i] == 'w'){
            index = i;
        }
    }

    printf("Last index : %d\n", index);

    return 0;
}
