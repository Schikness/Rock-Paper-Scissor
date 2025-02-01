#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void game(char playerInput){
    //this will take player and computer input, then calculate and declare the winner in 'winner'and update score
        //first computer takes input
        srand(time(0));
        char array[3];
        ///allocation memory
        array [0] = malloc(strlen("r") +1);
        array [1] = malloc(strlen("p")+1);
        array [2] = malloc(strlen("s") + 1);

        char comput = array[rand()%3]; 
        
        
}


int main(){
    //player gives input rock paper or scissor, if wins gets score, else computer gets score, computer chooses a random 
    while (1)
    {
        char input;
        printf("Enter r for rock, p for paper and s for stone. to exit press y");
        scanf("%c", &input);
        if (input = ' ' )
        {
            break;
        }
        game(input);
        printf("You entered: %c", &input);
        printf("computer entered: %c", &comput);
        printf("Winner: %c", &winner);
        printf("Score: You --> %d\nComputer --> %d", &playerScore, &computerScore);

        
        
    }
    //remember to free up memory to avoid memory leaks
    
    return 0;
}
