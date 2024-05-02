#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int symbol = 0, letter = 0, number = 0;
    char str[] = "ajdad567 +-=67 ..,";
    for(int i = 0; i < strlen(str); i++){
        if (str[i] >= '0' && str[i] <= '9'){
            number +=1;
        }
        else if((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z')){
            letter += 1;
        }
        else{
            symbol +=1;
       }
    }

    printf("Symbol : %d\nLetter : %d\nNumber : %d\n", symbol, letter, number);

    return 0;
}
