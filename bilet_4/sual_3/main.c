#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    char str[] = "Lorem ipsum dolor sit ame, consectetur adipiscing eli. Sed do eiusmod tempor incididunt ut labore et dolore magna aliqua. Ut enim ad minim veniam, quis nostrud exercitation ullamco laboris nisi ut aliquip ex ea commodo consequat.";
    for (int i = 0; i < strlen(str); i++){
        if (str[i] == ' '){
            if (( str[i + 1] >= 'a' && str[i + 1] <= 'z') || (str[i + 1] >= 'A' && str[i + 1] <= 'Z')){
                if (( str[i + 2] >= 'a' && str[i + 2] <= 'z') || (str[i + 2] >= 'A' && str[i + 2] <= 'Z')){
                    if (( str[i + 3] >= 'a' && str[i + 3] <= 'z') || (str[i + 3] >= 'A' && str[i + 3] <= 'Z')){
                        if (str[i + 4] >= 32 && str[i + 4] <= 47){
                            printf("%c%c%c ", str[i + 1], str[i + 2], str[i + 3]);
                            i += 3;
                        }
                    }
                }
            }
        }
    }
    return 0;
}
