#include <stdio.h>

int main()
{
    int height, width, area;
    printf("Enter height and width of the rectangle: ");
    scanf("%d %d", &height, &width);
    area = height * width;
    printf("The area is %d sq in.\n", area);
}