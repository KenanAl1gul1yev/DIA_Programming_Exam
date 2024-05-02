#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node{
    int count;
}Node;

int main()
{
    int count_sentence = 0;
    int count_words = 0;

    Node elems[100];

    char str[20];
    while (scanf("%s", &str)){
        if (strcmp(str, ".") != 0 && strcmp(str, "?") != 0  && strcmp(str, "!") != 0 && strcmp(str, "#") != 0){
            count_words += 1;
        }
        if (str[strlen(str) -1] == '#' || str[0] == '#'){
            break;
        }
        if (str[strlen(str) - 1] == '.' || str[strlen(str) - 1] == '!' || str[strlen(str) - 1] == '?' || str[strlen(str) - 1] == '#'){
            elems[count_sentence].count = count_words;
            count_sentence += 1;
            count_words = 0;
        }
    }

    for (int i = 0; i < count_sentence; i++){
        printf("sentence_%d  word _count : %d\n", i + 1, elems[i].count);
    }
    return 0;
}
