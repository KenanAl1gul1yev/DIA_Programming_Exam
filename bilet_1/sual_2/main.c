#include <stdio.h>
#include <stdlib.h>

int arr[36];
int sum = 0;

void readFile(){
    int sira_num, n1, n2, n3;
    int i = 0;
    FILE* fptr = fopen("vals.txt", "r");
    while(fscanf(fptr, "%d %d %d %d", &sira_num, &n1, &n2, &n3) != EOF){
        arr[i] = n1;
        arr[i+1] = n2;
        arr[i + 2] = n3;
        i += 3;
    }
    fclose(fptr);
}

void sumNums(){
    for (int i = 0; i < 36; i++){
            sum += arr[i];
    }
    printf("Sum : %d", sum);
}

int main()
{
    readFile();
    sumNums();
    return 0;
}
