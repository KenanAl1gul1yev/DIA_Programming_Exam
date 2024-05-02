#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char txt[] = "Kenan Laleni sevir .";

    int count = 0;
    for (int i = 0; i < strlen(txt); i++){
        if ((txt[i] >= 'a' && txt[i] <= 'z') || (txt[i] >= 'A' && txt[i] <= 'Z')){
            count += 1;
        }
    }

    printf("%d", count);

    return 0;
}
