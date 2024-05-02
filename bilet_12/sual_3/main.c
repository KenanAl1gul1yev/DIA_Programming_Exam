#include <stdio.h>
#include <stdlib.h>

int main()
{
    char txt[1024];
    printf("Type your text : \n");
    fgets(txt, sizeof(txt), stdin);

    int count = 0;
    for (int i = 0; i < strlen(txt); i++){
        if (txt[i] == '#'){
            break;
        }
        if (txt[i] == 'a' && txt[i + 1] == 'b' && txt[i + 2] == 'c'){
                i += 2;
                count += 1;
        }
    }

    printf("Number of \"abc\" is : %d", count);

    return 0;
}
