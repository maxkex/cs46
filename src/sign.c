#include <stdio.h>

int main()
{
    int height;
    printf("Enter the height of the sign: ");
    scanf("%d", &height);

    if( 3 <= height && height <= 12){
        printf("|------------+\n| Max Kebets |\n|------------+\n");
        for(int i = 0; i < height - 3; i++){
            printf("|\n");
        }
    }      
    else{
        printf("Sign height must be between 3 and 12\n");
    }

    return 0;
}