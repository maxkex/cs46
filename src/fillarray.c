#include <stdio.h>
const int SIZE = 40;

long nextCollatz(long x){
    if(x % 2 == 0){
        return x / 2;
    }else{
        return (x * 3) + 1;
    }
}

void printIntArr(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int myArray[SIZE];

    for(int i = 0; i < 10; i++) {
        myArray[i] = i;
    }
    for(int i = 10; i < 20; i++) {
        myArray[i] = i * 10;
    }
    myArray[20] = 4;
    myArray[21] = 8;
    myArray[22] = 15;
    myArray[23] = 16;
    myArray[24] = 23;
    myArray[25] = 42;

    myArray[26] = 7;
    int temp = myArray[26];
    for(int i = 27; i < SIZE; i++) {
        temp = nextCollatz(temp);
        myArray[i] = temp;
    }

    printIntArr(myArray, SIZE);

    return 0;
}