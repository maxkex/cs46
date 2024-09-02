#include <stdio.h>

long getStart(){
    long x;
    do{
        printf("Enter the starting number: ");
        scanf("%ld", &x);
        if(x <= 0){
            printf("The number should be a positive integer.\n");
        }
    }while(x <= 0);
    return x;
}

long nextCollatz(long x){
    if(x % 2 == 0){
        return x / 2;
    }else{
        return (x * 3) + 1;
    }
}
int main(){
    long x = getStart();
    int count = 1; // starts at 1 because we already have the first number
    printf("Collatz sequence: %ld, ", x);
    while(x != 1){
        x = nextCollatz(x);
        printf("%ld", x);
        count++;
        if(x != 1){
            printf(", ");
        }
    }
    printf("\nLength: %d\n", count);


}