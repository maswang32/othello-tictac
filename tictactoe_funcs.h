/* Mason Wang, masonwang */
/* CS152, Winter 2019 */
/* hw3 */


#ifndef FILENAME_H
#define FILENAME_H




/* print_tac_toe_board
 * purpose: prints a tic tac toe board
 * inputs:
 *   char board[3][3] - board to print
 * outputs:
 *   prints the given board to the screen.
 */
void print_tac_toe_board(char board[3][3]);



/* init_board
 * purpose: initialize the board to all '*' characters
 * inputs:
 *   char board[3][3] - array to initialize
 * outputs:
 *   None
 */
void init_board(char board[3][3]);



/* place_piece
 * purpose: places a character into a row and column of a board
 * inputs:
 *   char board[3][3] - array to place character in
 *   char player - character to place in array
 *   unsigned int row - row to place character in
 *   unsigned int col - column to place character in
 * outputs:
 *   1 or 0, 1 if the piece is successfully placed in an available
 *   spot, zero if the board is unchanged because the spot is unavailable.
 */
unsigned int place_piece(char board[3][3], char player, unsigned int row,
unsigned int col);



/* player_won
 * purpose: checks to see if after a move a player has won
 * inputs:
 *   char board[3][3] - array to place and check
 *   char player - character to place in array
 *   unsigned int row - row to place character in
 *   unsigned int col - column to place character in
 * outputs:
 *   1 or 0, 1 if the player has won
 *   0 if the player has not won
 */
int player_won(char board[3][3], char player, unsigned int row,
unsigned int col);



/* computer_move
 * purpose: determines a computer move to win tic_tac_toe
 * inputs:
 *   char board[3][3] - array to play in
 *   char player - team of the computer
 *   unsigned int *row - output param - row to place character in
 *   unsigned int *col - output param - column to place character in
 * outputs:
 *   1 or 0, 1 if the piece is successfully placed in an available
 *   spot, zero if the board is unchanged because the spot is unavailable.
 */
 int computer_move(char board[3][3], char player, unsigned int *row,
unsigned int *col);


 /* play_tic_tac_toe
 * purpose: allows the user to play tic tac toe
 * inputs: none, user inputs numbers
 * outputs: onscreen
 */
void play_tic_tac_toe();

#endif

