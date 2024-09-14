#include <stdio.h>

// Max string length
#define STR_MAX 100
#define RATE 2.75 // $/kg

// prototoypes
int length(char str[]);
void trim(char str[]);
float getWeight(char myChar);

int main()
{

    char input[STR_MAX];
    float totalCost = 0;
    int numContainers = 0;

    // Loop until . is entered

    while (1)
    {
        printf("Enter cotainer string: ");
        fgets(input, STR_MAX, stdin);

        if (input[0] == '.')
        {
            break;
        }

        // Trim the newline
        trim(input);

        // get two halves of the string
        char half1[STR_MAX/2] = {0}; //initialize the array with nulls
        char half2[STR_MAX/2] = {0}; //if no nulls, its junk values,
        float weight1 = 0;
        float weight2 = 0;

        //split the string in half
        for (int i = 0; i < length(input)/2; i++)
        {
            half1[i] = input[i];
        }
        for (int i = length(input)/2; i < length(input); i++)
        {
            half2[i - length(input)/2] = input[i];
        }
        

        //debugging: print the half strings
        //printf("Half 1: %s\n", half1);
        //printf("Half 2: %s\n", half2);

        //get the weight of each half
        for (int i = 0; i < length(half1); i++)
        {
            weight1 += getWeight(half1[i]);
        }
        for (int i = 0; i < length(half2); i++)
        {
            weight2 += getWeight(half2[i]);
        }

        //calculate the cost of the heavier half
        float cost = 0;
        if (weight1 > weight2)
        {
            cost = weight1 * RATE;
        }
        else
        {
            cost = weight2 * RATE;
        }

        //add the cost to the total
        totalCost += cost;

        //increment the number of containers
        numContainers++;
    }

    //print the total cost and number of containers
    printf("%d containers, shiping fee $%.2f\n", numContainers, totalCost);
    

    
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

float getWeight (char myChar){


    if ((myChar >= 'a' && myChar <= 'z')){
        // 0.1kg through 2.7kg represented by the letters a through z
        return (myChar - 'a' + 1)/10.0;
    }
    else if(myChar >= 'A' && myChar <= 'Z'){
        // 2.7kg through 5.2kg represented by of the letters A through Z
        return (myChar - 'A' + 27)/10.0;
    }
    else{
        //return 0 if the character is not a letter, thus not adding to the weight
        return 0;
    }
    
}