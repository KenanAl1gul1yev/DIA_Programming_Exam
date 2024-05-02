#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int n;
    printf("N : ");
    scanf("%d", &n);
    char str[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris.";

    int count = 0;
    int count_space = 0;

    if (n == 0){
        for (int j = 0; j < strlen(str); j++){
            if (str[j] == ' ' || str[j] == '.' || str[j] == ',' || str[j] == '?' || str[j] == '!'){
                break;
            }
            printf("%c", str[j]);
            count += 1;
        }
    }
    else{
        for (int i = 0; i < sizeof(str); i++){
            if (str[i] == ' '){
                count_space += 1;

                if (count_space == n){
                    for (int j = i + 1; j < strlen(str); j++){
                        if (str[j] == ' ' || str[j] == '.' || str[j] == ',' || str[j] == '?' || str[j] == '!'){
                            break;
                        }
                        printf("%c", str[j]);
                        count += 1;
                    }
                }
            }
        }
    }
    printf("\nLen : %d\n", count);

    return 0;
}
