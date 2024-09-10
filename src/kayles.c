#include <stdio.h>
#include <stdlib.h>

// Function prototypes
int getInt(char prompt[], int min, int max);
void fillBoard(int arr[], int len);
void printBoard(int arr[], int len);
void knockPins(int arr[], int len, int index, int numpins);

int main()
{
    // Var win will keep track of whos turn it is.
    int turn = 1;

    

    printf("Welcome to Kayles! The game is simple, you can knock down 1 or 2 pins,\n and the player who knocks down the last pin wins.\n1's represent upright pins and 0's downed ones\nKnocking down two pins happens from left to right, and the count of pins start from 0.\n");

    // Ask user for length of game, from 3-20
    int boardLength = getInt("Enter size of board, between ", 3, 20);
    
    // Create board.
    int board[boardLength];
    
    // Fill board with 1, representing the pins
    fillBoard(board, boardLength);
    printBoard(board, boardLength);
    

    do{
        
        // Check if there is a win
        int downed = 0;
        for (int i = 0; i < boardLength; i++)
        {
            if (board[i] == 0)
            {
                downed++;
            }
            
        }

        if (downed == boardLength)
        {
            
            break;
        }

        // Switch turns
        if (turn == 1)
        {
            turn = 2;
        }
        else
        {
            turn = 1;
        }

        printf("It is currently player %d's turn.\nHow many pins do you want to knock down?: ", turn);
        int numpins = 0;


        


        while (1) {
            scanf("%d", &numpins);
            
            
            // Check if the number of pins is valid
            if (numpins != 1 && numpins != 2) {
                printf("Invalid number of pins, you can knock down only 1 or 2\nPlease enter a valid number: ");
                
            }else{
                break;
            }
            while (getchar() != '\n');
      
        }

        while (1) {
            printf("Which index pin(s) do you want to knock down?: ");
            int index = 0;
            scanf("%d", &index);
            
            // Check if the index is valid
            if (index < 0 || index >= boardLength) {
                printf("Invalid index, please enter a number between 0 and %d\n", boardLength - 1);
                
            }
            
            // Check if the pin is already knocked down
            else if (board[index] == 0) {
                printf("Pin already knocked down, please enter a different pin\n");
                
            } else {
                // Knock down the pins
                knockPins(board, boardLength, index, numpins);
                
                break;
            }
            while (getchar() != '\n');
        }


        
        while (getchar() != '\n');

        printBoard(board, boardLength);



        
        
    }while(1 == 1);

    printf("Player %d wins!\n", turn);
    
    return 0;

}

int getInt(char prompt[], int min, int max)
{
    int num;
    printf("%s%d and %d: ", prompt, min, max);
    scanf("%d", &num);
    
    while(num < min || num > max){
        printf("Number not within range. Please enter a number between %d and %d: ", min, max);
        scanf("%d", &num);
        while(getchar() != '\n');
    }
    return num;

}

//fills the board with 1, representing the pins
void fillBoard(int arr[], int len)
{
    for(int i = 0; i < len; i++){
        arr[i] = 1;
    }
}

void printBoard(int arr[], int len)
{
    printf("Board:");
    for (int i = 0; i < len; i++)
    {
        printf(" %d", arr[i]);
    }
    printf("\n");
}

// knocks down 1 or 2 pins based on user input
void knockPins(int arr[], int len, int index, int numpins)
{

    
    // Knock down the pins
    if (numpins == 1)
    {
        arr[index] = 0;
    }
    else
    {
        arr[index] = 0;
        arr[index + 1] = 0;
    }
}