#include <stdio.h>
#include <stdlib.h>

void printIntArr(int arr[], int size);
void shuffleArr(int arr[], int len);
int getInt(char prompt[], int min, int max);
void trim(char str[]);
void reverse(char str[]);
int length(char str[]);

int main(){

    return 0;
}

void printIntArr(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Shuffle the array
void shuffleArr(int arr[], int len)
{
    for(int j = 0; j < 3; j++){
        for(int i = 0; i < len; i++){
            int randomIndex = random() % len;
            int temp = arr[i];
            arr[i] = arr[randomIndex];
            arr[randomIndex] = temp;
        }
    }
}



// Get an integer from the user.
//   Display the prompt.
//   Get input from user.
//   Check that the input is between the min and max, inclusive.
//   If not, display error message that includes the min and max,
//     then loop back to get input again.
int getInt(char prompt[], int min, int max)
{
    int num;
    printf("Enter number between %d and %d: ", min, max);
    scanf("%d", &num);
    
    while(num < min || num > max){
        printf("Number not within range. Please enter a number between %d and %d: ", min, max);
        scanf("%d", &num);
        while(getchar() != '\n');
    }
    return num;

}

int length(char str[])
{
    //loop through the string untill null is found
    int i = 0;
    while (str[i] != '\0')
    {
        i++;
    }
    return i;
}


void trim(char str[])
{
    //find the length of the string
    int len = length(str);
    
    //loop through the string
    for (int i = len - 1; i >= 0; i--)
    {
        //if we find a newline, replace it with null
        if (str[i] == '\n')
        {
            str[i] = '\0';
            break;
        }
    }
}

void reverse(char str[])
{
    int len = length(str);
    
    for (int i = 0; i < len / 2; i++)
    {
        //swap the characters, going inwards from the ends
        char temp = str[i];
        str[i] = str[len - i - 1];
        str[len - i - 1] = temp;
    }
}