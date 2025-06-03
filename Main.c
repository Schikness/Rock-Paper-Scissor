#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

//take player input --> done
//set computer input --> done
//calculate the winner --> done
//update score


//do best of code: give option to pick best of three or best of 5,



void game(char playerInput, char *comput, char *winner, int *playerScore, int *computerScore){
    //pass variables as pointers
    //need pointers for malloc
    //this will take player and computer input, then calculate and declare the winner in 'winner'and update score
        //first computer takes input
        srand(time(0));
        char *array = malloc(3*sizeof(char));

        //check for memory allocation error
        if (array == NULL)
        {
            printf("Memory Allocation error for array.");
            exit(1);
        }


        
        ///allocation memory
        array [0] = 'r';     
        array [1] = 'p';
        array [2] = 's';

        //taking the computer input
        *comput = array[rand()%3]; 

        // calulate the winner, set *winner
        //print winner later
            if(playerInput == *comput)
            {
                strcpy(winner, "Draw");
            }
            else if (playerInput == 'r' && *comput == 's' ||
                    playerInput == 's' && *comput == 'p' ||
                    playerInput == 'p' && *comput == 'r' )
            {
                strcpy(winner, "Player");
                (*playerScore)++;
            }
            else
            {
                strcpy(winner, "Computer");
                (*computerScore)++;
            }

            free(array);
            
        
        
}


int main(){
    //cant pass variables from local function to main, use pointers instead and pass on the address
    char *input = malloc(sizeof(char));
    char *comput = malloc (sizeof(char));
    //char *winner = malloc(sizeof(char)); causes
    /*warning: multi-character character constant [-Wmultichar]
   46 |                 *winner = 'Player';
      |                           ^
    Main.c:46:27: warning: character constant too long for its type
    Main.c:50:27: warning: multi-character character constant [-Wmultichar]
   50 |                 *winner = 'Computer';
      |                           ^ */
    //to fix this write the following
    char *winner = malloc(8);//max is computer which is 1x8=8 bytes so malloc(8)
    int *playerScore = malloc(sizeof(int));
    int *computerScore = malloc (sizeof(int));
    int *bestOf = malloc(sizeof(int));
    int *round = malloc(sizeof(int));
    // check for memory allocation error
    if(input == NULL || comput == NULL || winner == NULL || playerScore == NULL || computerScore == NULL || bestOf == NULL || round == NULL){
        printf("Memory Allocation Failed!");
        return 1;
    }

    *playerScore = 0;
    *computerScore = 0;
    *bestOf = 0;
    *round = 0;
    printf("Play best of 3 or best of 5?\n");
    scanf(" %d", bestOf);
    //player gives input rock paper or scissor, if wins gets score, else computer gets score, computer chooses a random 
    while (*round < *bestOf)
    {
        
        //take input
        printf("Enter r for rock, p for paper and s for stone. to exit press y\n");
        //Add space before %c to ignore newline (\n) in buffer, else just prints invalid input everytime
        //If you don’t put a space before %c in scanf(), the leftover \n (newline) from the previous input stays in the input buffer.
        scanf(" %c", input);

        //check if exited the game
        if (*input == 'y' )
        {
            printf("Exiting Game.");
            break;
        }

        //check if invalid input
        if (*input != 'r' && *input != 'p' && *input != 's' && *input != 'y' )
        {
            printf("Invalid Input.");
            continue;
        }

                
        game(*input, comput, winner, playerScore, computerScore);//set parameters in game function


        printf("You entered: %c\n", *input);
        printf("computer entered: %c\n", *comput);
        printf("Winner: %s\n", winner);//when using %s for characters, dont use *winner because * refers to the char *winner, just use the pointer instead
        

        (*round)++;
        /*You're writing:

            *round++;

This does not increment the value pointed to by round.
Instead, it increments the pointer itself (round) — not the value it points to.

This messes up your memory and causes strange behavior, like "Invalid Input" (because the next scanf() might be reading garbage from an invalid pointer location).
You need to increment the value pointed to by round, like this:

(*round)++;

This properly increases the integer stored at the memory location that round points to.
Why This Fix Works:

    round++ means "increment the pointer round" (moves the pointer by sizeof(int) bytes).

    *round++ means "dereference the pointer, then increment the pointer" — it does not change the value.

    (*round)++ means "increment the value pointed to by round" — this is what you actually want.*/


        if(*round == *bestOf){
            printf("Score: You --> %d\nComputer --> %d\n", *playerScore, *computerScore);
            if(*playerScore > *computerScore){
                printf("You Win!");
            }
            else if(*computerScore > *playerScore){
                printf("You Lose!");
            }
            else{printf("It is a Draw");}
        }
        
    }
    //remember to free up memory to avoid memory leaks
    free(input);
    free(comput);
    free(winner);
    free(playerScore);
    free(computerScore);
    free(round);
    free (bestOf);
    
    return 0;
}
