#include <stdio.h>

void swap(float *a, float *b);
void getPrices(float *x, float *y, float *z);

int main(){

    float x, y, z;

    getPrices(&x, &y, &z);


    printf("Sorted Prices: %.2f, %.2f, %.2f\n", x, y, z);

    return 0;

}


void swap(float *a, float *b){
    float temp = *a;
    *a = *b;
    *b = temp;
}

void getPrices(float *x, float *y, float *z){
    printf("Enter the price of the first item: ");
    scanf("%f", x);
    printf("Enter the price of the second item: ");
    scanf("%f", y);
    printf("Enter the price of the third item: ");
    scanf("%f", z);

    if(*x > *y){
        swap(x, y);
    }
    if(*x > *z){
        swap(x, z);
    }
    if(*y > *z){
        swap(y, z);
    }
    
}