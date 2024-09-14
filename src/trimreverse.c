#include <stdio.h>

// Max string length
#define STR_MAX 100

// Function prototypes here:
void trim(char str[]);
void reverse(char str[]);
int length(char str[]);


// Main function
int main()
{
    char input[STR_MAX];
	
    // Loop until we break out
    while (1)
    {
        printf("Enter a string: ");
        fgets(input, STR_MAX, stdin);      // Finish this call to fgets
        if (input[0] == '.')                      // Break out of loop when first char is '.'
	    {
            break;
        }
		
        // Trim the newline
        trim(input);

        // Print the trimmed string
        printf("After trim: %s\n", input);
		
        // Reverse the string
        reverse(input);
		
        // Print the reversed string
        printf("Reversed: %s\n", input);
    }
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