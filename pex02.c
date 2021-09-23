/** pex02.c
 * =========================================================== 
 * Name: Riley Deans, 9/22
 * Section: T1A
 * Project: Pig! game
 * Purpose: The purpose of this program is to utilize 6 functions to 
 * create the game "Pig!". Pig! is a dice game involving two players
 * where a player will roll the die until they decide to "hold" (saving
 * their score) or a 1 is rolled. If the player rolls a 1, their score 
 * is not saved and it is the next players turn. The first player to reach 
 * 100 wins the game.
 * Documentation: Colonel Neff helped me with an error I had in the function
 * getCharSafe() function because I was using pointers as the parameters instead
 * of a character.
 * =========================================================== */

#include <stdio.h>
#include "pex02funcs.h"
#define LEN 25

int main(){

  int player1Score=0;
  int player2Score=0;

  printf("Player one, what is your name: ");
  char name1[LEN];
  scanf("%s",name1);

  printf("Player two, what is your name: ");
  char name2[LEN];
  scanf("%s",name2);

//game loop
  while((player1Score<100) && (player2Score<100)){
    displayGameState(name1,player1Score,name2,player2Score);
    player1Score=takeTurn(name1,player1Score);
    //check if player has reached over 100 points
    if (player1Score<100){
    displayGameState(name1,player1Score,name2,player2Score);
    player2Score=takeTurn(name2,player2Score);
    }
}

  displayWinner(name1,player1Score,name2,player2Score);
  printf("thanks for playing Pig!\n");

}
