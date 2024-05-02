#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char arr[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit... Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris.";
    int count = 0;
    for (int i = 0; i < strlen(arr); i++){
        if (arr[i] == '?' || arr[i] == '!'){
            count += 1;
        }
        if (arr[i] == '.'){
            if (arr[i + 1] == '.' && arr[i + 2] == '.'){
                i += 2;
            }
            count += 1;
        }
    }

    printf("Number of sentences = %d", count);
    return 0;
}
