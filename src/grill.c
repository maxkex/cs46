#include <stdio.h>

int main()
{
    int width, height, i , j;
    printf("Enter grill width: ");
    scanf("%d", &width);
    printf("Enter grill height:");
    scanf("%d", &height);

    if(width >= 2 && width <= 30 && height >= 2 && height <= 12)
    {
        printf("+");
        for(i = 0; i < width - 2; i++){
            printf("-");
        }
        printf("+\n");

        for(i = 0; i < height - 2; i++){
            printf("|");
            for(j = 0; j < width - 2; j++){
                printf("-");
            }
            printf("|\n");
        }

        printf("+");
        for(i = 0; i < width - 2; i++){
            printf("-");
        }
        printf("+\n");

    } else {
        if( width < 2){
            printf("Grill is not wide enough.\n");
        } 
        else if( width > 30){
            printf("Grill is too wide.\n");
        }

        if( height < 2 ){
            printf("Grill is too short.\n");
        } 
        else if( height > 30){
            printf("Grill is too tall\n");
        }
        printf("The width must be 2-30 and the height must be 2-12\n");
    }
}