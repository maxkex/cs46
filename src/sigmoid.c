#include <stdio.h>
#include <math.h>

float sigmoid(float x){
    x = 1/(1 + pow(M_E, -x));
    return x;
}

int main(){

    for(int i = -5; i <= 5; i++){

        printf("%.3f %.3f\n", (double)i, sigmoid(i));
    }

}