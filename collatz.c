#include <stdio.h>

long getStart(){
    long x;
    do{
        scanf("Enter a starting number: %ld", &x);
    }while(x <= 0);
    return x;
}

int main(){
    long x;
    x = getStart();
    printf("the var is %ld", x);

}