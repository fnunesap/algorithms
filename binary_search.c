//BINARY SEARCH
#include <stdio.h>
#include <stdlib.h>

typedef struct{
    int pos;
    int it;
}info;

int * array_generator(int * array, int max_size, int gap, int start){
    int generator = start;
    int cout = 0;

    while(cout != max_size){
        array[cout] = generator;
        generator+= gap;
        cout++;
    }

    return array;

}  

info BS_index_searcher(int * array, int size, int value){
    info res;
    res.it = 0;
    res.pos = 0;

    int iterations = 0;
    int l = 0;
    int r = size-1;
    do{
        int m = (l+r)/2;
        if(array[m] == value){
            res.it = iterations;
            res.pos = m;
            return res;
        }else if(value < array[m]){
            iterations++;
            printf("<");
            r = m-1;
        }else{
            iterations++;
            printf(">");
            l = m+1;
        }
    }while(l <= r);

    res.it = iterations;
    res.pos = -1;

    return res;
}


int main(){
    
    int i;
    int tam;
    int gap;
    int start;
    int value;
    info answer;

    printf("What is the size of the array?\n");
    scanf("%d", &tam);
    printf("What is the gab between the elements of the array?\n");
    scanf("%d", &gap);
    printf("From how much will it start?\n");
    scanf("%d", &start);

    int * a = (int *)malloc(tam*sizeof(int));

    a = array_generator(a, tam, gap, start);
    
    printf("Your array is: \n");
    for(i = 0; i < tam; i++){
        printf("%d ", a[i]);
    }

    printf("\nWhat number are you searching for?\n");
    scanf("%d", &value);

    answer = BS_index_searcher(a,tam,value);

    answer.pos == -1 ? printf("\nSorry, this number is not in the array.\nArray accesses: %d\n", answer.it) : printf("\nNumber %d in position: %d\nArray accesses: %d\n",value, answer.pos, answer.it);

    return 0;
}