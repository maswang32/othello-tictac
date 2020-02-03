/* Mason Wang, masonwang */
/* CS152, Winter 2019 */
/* hw3 */


#ifndef FILENAME_H
#define FILENAME_H

/* print_othello_board
 * purpose: prints othello board
 * inputs:
 *   char board[8][8] - board to print
 * outputs:
 *   prints the given board to the screen.
 */
void print_othello_board( char board[8][8]);



/* init_board
 * purpose: initialize the board to all '*' characters
 * inputs:
 *   char board[8][8] - array to initialize
 * outputs:
 *   None
 */
void init_board(char board[8][8]);






/* place_piece
 * purpose: if valid, places piece in spot
 * inputs:
 *   char board[8][8] - board
 *   player - player placing
 *   uint row - row to place in
 *   uint col - col to place in
 * outputs:
 *   uint - number of pieces placed or flipped
 */
unsigned int place_piece(char board[8][8], char player,
unsigned int row, unsigned int col);



/* place_piece_helper
 * purpose: if valid, places piece in spot, but DOESN'T flip pieces.
 * inputs:
 *   char board[8][8] - board
 *   player - player placing
 *   uint row - row to place in
 *   uint col - col to place in
 * outputs:
 *   uint - number of pieces placed or flipped
 */
unsigned int place_piece_helper(char board[8][8], char player,
unsigned int row, unsigned int col);


/* flip_pieces
 * purpose: flips the othello pieces given a move, returns number flipped
 * inputs:
 *   char board[8][8] - board
 * outputs:
 *   int, number flipped
 */
unsigned int flip_pieces(char board[8][8], unsigned int row, unsigned int col);




/* player_won
 * purpose: determines who wins
 * inputs:
 *   char board[8][8] - board to look at
 * outputs:
 *   char of winning player
 */
char player_won(char board[8][8]);


/* computer_move
 * purpose: decides on a computer move
 * inputs:
 *   char board[8][8] - board to move on
 *   char player - board for computer to play as
 *   uint *row - location of place to put output row in
 *   uint *col - location of place to place output col value in
 * outputs:
 *   int - 1 if moved, 0 if the board is full
 */
int computer_move(char board[8][8], char player, unsigned int *row,
unsigned int *col);




/* play_othello
 * purpose: allows the user to play othello
 * inputs: none, user inputs stuf
 * outputs: onscreen
 */
void play_othello();

#endif
