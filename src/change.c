#include <stdio.h>

int bills(int amount){
    int count = 0;
    while(amount >= 100){
        amount -= 100;
        count++;
    }
    while(amount >= 20){
        amount -= 20;
        count++;
    }
    while(amount >= 10){
        amount -= 10;
        count++;
    }
    while(amount >= 5){
        amount -= 5;
        count++;
    }
    while(amount >= 1){
        amount -= 1;
        count++;
    }
    return count;
}

int getAmount(){
    int x;
    do{
        printf("Enter the amount: ");
        scanf("%d", &x);
        if(x < 0){
            printf("The amount should be a positive integer.\n");
        }
    }while(x < 0);
    return x;
}

int main(){
    int amount = getAmount();
    int count = bills(amount);
    printf("You get %d bills back.\n", count);
}