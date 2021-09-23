/** pex02funcs.c
 * =========================================================== 
 * Name: Riley Deans, 9/22
 * Section: T1A
 * Project: Pig! the game
 * Purpose: The pex02funcs.c file provides the code for the functions
 * used in the Pig! game. These functions check character validity, randomize
 * the die, create the game loop, return the scrores, determine the winner, and 
 * return the winning player.
 * =========================================================== */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "pex02funcs.h"

char getCharSafe(){
    char chari;
    //gets input
    int input=scanf(" %c", &chari);
        if ((input!=1)){
            exit(1);
        }
        else{
            fflush(stdin);
            return chari;
        }
    }

int rollDie(){
    int number = rand() % 6 + 1;
    return number;
}

int takeTurn(char* playerName, int playerScore){

    printf("It's your turn, %s\n", playerName);
    int turnscore=0;
    bool truth=false;
    
    do{
        //gets score
        int score=rollDie();        
        if (playerScore>100){
            break;
        }
        if (score==1){
            printf("You pigged out! Turn over.");
            playerScore-=turnscore;
            turnscore=0;
            break;
        }
        else{
        //increments score
        turnscore+=score;
        playerScore+=score;
        printf("You rolled a %d and have a turn score of %d, bringing your total to %d\n",score,turnscore,playerScore);
        printf("Roll Again? ");
        }
        
        switch(getCharSafe()){
            case 'Y':
            case 'y':
            truth=true;
            break;
            default:
            truth=false;
            break;   
        }
    }while((truth==true)&&(playerScore<100));
return playerScore;
}

void displayGameState(char* player1Name, int player1Score, char* player2Name, int player2Score){
    printf("   Score Player\n       %d %s\n       %d %s\n\n",player1Score,player1Name,player2Score,player2Name);
}

int winningPlayer(int player1Score, int player2Score){
    int score=player1Score-player2Score;
    //determines winner
    if (score>0){
        return 1;
    }
    if(score<0){
        return 2;
    }
    if((score=0)){
        return 3;
    }
    if ((player1Score<100) & (player2Score<100)){
        return 0;
    }
    return 0;
}

void displayWinner(char* player1Name, int player1Score, char* player2Name, int player2Score){
    switch(winningPlayer(player1Score,player2Score)){
    case 1:
    printf("%s, you won!\n",player1Name);
    break;
    case 2:
    printf("%s, you won!\n",player2Name);
    break;
    case 3:
    printf("It's a tie!\n");
    break;
    default:
    printf("No winner\n");
}}