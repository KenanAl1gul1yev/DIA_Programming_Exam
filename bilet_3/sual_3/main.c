#include <stdio.h>
#include <stdlib.h>

char arr[] = "I'm playin with your heart .";
char tmp[sizeof(arr)];

void conCat();
void show();

int main()
{
    conCat();
    show();
    return 0;
}

void conCat(){
    for (int i = 0; i < strlen(arr); i++){
        if (arr[i] == 'm'){
                for (int j = 0; j < sizeof(tmp); j++){
                    tmp[j] = arr[i + j];
                    if (arr[i + j] == 'n'){
                        break;
                    }
                }

        }
    }
}

void show(){
    printf("%s", tmp);
}
