/** pex02funcs.h
 * =========================================================== 
 * Name: your name
 * Section: your section
 * Project: assignment information 
 * Purpose: high level description of purpose of the program
 *          could be multiple lines
 * =========================================================== */

/**
 * @brief checks validity of character input
 * @param no parameters
 * @return character or exits if invalid input
 * @pre must be a scanf call
 * @post if input is valid, check case of Y or y
 */

char getCharSafe();

/**
 * @brief gets random number 1-6
 * @param no parameters
 * @return random number 1-6
 * @pre will be used to get score from die in game loop
 * @post provides score
 */

int rollDie();

/**
 * @brief creates game loop
 * @param playerName the name of the player whose turn it is
 * @param playerScore the score of the player (total)
 * @return the score of the player after the turn is finished
 * @pre score must be less than 100
 * @post allows turns to be taken in game
 */

int takeTurn(char* playerName, int playerScore);

/**
 * @brief displays the score of the game
 * @param player1Name the name of player 1
 * @param player1Score the score of player 1
 * @param player2Name the name of player 2
 * @param player2Score the score of player 2
 * @return no return
 * @pre scores must be less than 100 (unless obtained on that turn)
 * @post will print the current score of the game after the 
 * turn is over
 */

void displayGameState(char* player1Name, int player1Score, char* player2Name, int player2Score);

/**
 * @brief gives an integer corresponding with a game result
 * @param player1Score the score of player 1
 * @param player2Score the score of player 2
 * @return integer corresponding with a game result
 * @pre integers cannot be negative
 * @post will determine whether there is a win, tie, or no game result
 */

int winningPlayer(int player1Score, int player2Score);

/**
 * @brief checks validity of character input
 * @param player1Name the name of player 1
 * @param player1Score the score of player 1
 * @param player2Name the name of player 2
 * @param player2Score the score of player 2
 * @return N/A
 * @pre must use winningPlayer function
 * @post will print the winning player or indicate a tie or no result
 */

void displayWinner(char* player1Name, int player1Score, char* player2Name, int player2Score);
