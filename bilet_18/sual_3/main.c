#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char str[30];
    char elements[100][30];
    int k = 0;
    while (scanf("%s", &str)){
        for (int i = 0; i < strlen(str); i++){
            if (str[i] == 'k'){
                strcpy(elements[k], str);
                k += 1;
                break;
            }
        }
        if (str[strlen(str) - 1] == '#' || str == '#'){
            break;
        }
    }
    for (int i = 0; i < k; i++){
        printf("%s  ", elements[i]);
    }
    return 0;
}
