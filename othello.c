/* Mason Wang, masonwang */
/* CS152, Winter 2019 */
/* hw3 */


#include <stdlib.h>
#include <stdio.h>
#include "othello_funcs.h"


/* test_init_board
 * purpose: tests the init_board
 * inputs:
 *   same as init_board
 * outputs:
 *   to screen
 */
void test_init_board(char array[8][8])
{
    printf("\n\nCalling init_board on this board:\n");
    print_othello_board(array);
    printf("\n\nResulting array: \n");
    init_board(array);
    print_othello_board(array);
}



/* test_place_piece_helper
 * purpose: tests the place_piece_helper function
 * inputs:
 *   uint expected --- expected result
 *   char board[8][8] - board
 *   player - player placing
 *   uint row - row to place in
 *   uint col - col to place in
 * outputs:
 *   void - to scren
 */
void test_place_piece_helper(char board[8][8], char player, unsigned int row,
unsigned int col, unsigned int expected)
{
    printf("\n\nCalling place_piece_helper(board, %c, %u, %u) on this board:\n"
           , player, row, col);
    print_othello_board(board);
    unsigned int result = place_piece_helper(board, player, row, col);
    printf("\nResulting board: \n");
    print_othello_board(board);
    printf("\nOutput = %u, expected %u", result, expected);
}



/* test_place_piece
 * purpose: tests the place_piece function.
 * Note: most of the robust testing is done in
 * place_piece_helper, so most of the tests there should
 * convince you that this function works.
 * inputs:
 *   uint expected --- expected result
 *   char board[8][8] - board
 *   player - player placing
 *   uint row - row to place in
 *   uint col - col to place in
 * outputs:
 *   void - to screen
 */
void test_place_piece(char board[8][8], char player, unsigned int row,
unsigned int col, unsigned int expected)
{
    printf("\n\nCalling place_piece(board, %c, %u, %u) on this board:\n"
           , player, row, col);
    print_othello_board(board);
    unsigned int result = place_piece(board, player, row, col);
    printf("\nResulting board: \n");
    print_othello_board(board);
    printf("\nOutput = %u, expected %u", result, expected);
}




/* test_flip_pieces
 * purpose: tests the flip_pieces function
 * inputs:
 *   uint expected --- expected result
 *   char board[8][8] - board
 *   uint row - row just placed in
 *   uint col - col just placed in
 * outputs:
 *   void - to screen
 */
void test_flip_pieces(char board[8][8], unsigned int row,
unsigned int col, unsigned int expected)
{
    printf("\n\nCalling flip_pieces(board, %u, %u) on this board:\n"
           , row, col);
    print_othello_board(board);
    unsigned int result = flip_pieces(board, row, col);
    printf("\nResulting board: \n");
    print_othello_board(board);
    printf("\nOutput = %u, expected %u", result, expected);
}



/* test_player_won
 * purpose: tests the player_won function
 * inputs:
 *   char expected - expected result
 *   char board[8][8] - board
 * outputs:
 *   void - to screen
 */
void test_player_won(char board[8][8], char expected)
{
    printf("\n\nCalling player_won on this board:\n");
    print_othello_board(board);
    char result = player_won(board);
    printf("\nOutput = %c, expected %c", result, expected);
}






/* test_computer_move
 * purpose: test the computer_move function
 * inputs:
 *   int expected - expected output
 *   char board[8][8] - board to move on
 *   char player - board for computer to play as
 *   uint *row - location of place to put output row in
 *   uint *col - location of place to place output col value in
 * outputs:
 *   int - 1 if moved, 0 if the board is full
 */
void test_computer_move(char board[8][8], char player, unsigned int *row,
unsigned int *col, int expected)
{
    printf("\n\nCalling computer_move(%c) on this board:\n"
           , player);
    print_othello_board(board);
    int result = computer_move(board, player, row, col);
    printf("\n\nMove: (%u , %u)", *row, *col);
    printf("\nOutput = %d, expected %d", result, expected);
}




int main()
{
    char testarr[8][8] = {
		{'1','a', 'B', '1','a', 'B','1','a'},
        {'1','a', 'B', '1','a', 'B','1','a'},
		{'1','a', 'B', '1','a', 'B','1','a'},
		{'1','a', 'B', '1','a', 'B','1','a'},
		{'1','a', 'B', '1','a', 'B','1','a'},
		{'1','a', 'B', '1','a', 'B','1','a'},
		{'1','a', 'B', '1','a', 'B','1','a'},
		{'1','a', 'B', '1','a', 'B','1','a'}};

    test_init_board(testarr);

    //not connected
    test_place_piece_helper(testarr, 'B', 0 , 0, 0);

    //above
    test_place_piece_helper(testarr, 'B', 2, 3, 2);

    //in an already occupied space
    test_place_piece_helper(testarr, 'W', 2, 3, 0);

    //to the left
    test_place_piece_helper(testarr, 'W', 4, 2, 2);

    //below
    test_place_piece_helper(testarr, 'W', 5, 3, 2);

    //to the right
    test_place_piece_helper(testarr, 'B', 4, 5, 2);

    //diagonal \, down
    char testarr2[8][8] = {
		{'B','*', '*', '*','*', '*','*','*'},
        {'*','W', '*', '*','*', '*','*','*'},
		{'B','*', 'W', '*','*', '*','*','*'},
		{'B','*', '*', 'W','*', '*','*','*'},
		{'B','*', '*', '*','W', '*','*','*'},
		{'B','*', '*', '*','*', 'W','*','*'},
		{'B','*', '*', '*','*', '*','W','*'},
		{'B','*', '*', '*','*', '*','*','*'}};

    test_place_piece_helper(testarr2, 'B', 7, 7, 7);


    //diagonal \, up
    char testarr3[8][8] = {
		{'*','*', '*', '*','*', '*','*','*'},
        {'*','W', '*', '*','*', '*','*','*'},
		{'B','*', 'W', '*','*', '*','*','*'},
		{'B','*', '*', 'W','*', '*','*','*'},
		{'B','*', '*', '*','W', '*','*','*'},
		{'B','*', '*', '*','*', 'W','*','*'},
		{'B','*', '*', '*','*', '*','W','*'},
		{'B','*', '*', '*','*', '*','*','B'}};

    test_place_piece_helper(testarr3, 'B', 0, 0, 7);

    //diagonal /, down
    char testarr4[8][8] = {
        {'B','*', '*', '*','*', '*','*','B'},
        {'B','*', '*', '*','*', '*','W','*'},
        {'B','*', '*', '*','*', 'W','*','*'},
        {'B','*', '*', '*','W', '*','*','*'},
		{'B','*', '*', 'W','*', '*','*','*'},
		{'B','*', 'W', '*','*', '*','*','*'},
        {'*','W', '*', '*','*', '*','*','*'},
		{'*','*', '*', '*','*', '*','*','*'}};

    test_place_piece_helper(testarr4, 'B', 7, 0, 7);

    //diagonal /, up, and multiple at the same time
    char testarr5[8][8] = {
        {'B','*', '*', '*','*', '*','*','*'},
        {'B','*', '*', '*','*', '*','*','*'},
        {'B','*', '*', '*','*', 'W','W','*'},
        {'B','*', '*', '*','W', '*','W','*'},
		{'B','*', '*', 'W','*', '*','W','*'},
		{'B','*', 'W', '*','*', '*','W','*'},
        {'*','W', '*', '*','*', '*','W','*'},
		{'B','*', '*', '*','*', '*','B','*'}};

    test_place_piece_helper(testarr5, 'B', 1, 6, 11);


    //begin to test flip_pieces, at several angles, diagonally, up, and down
    test_flip_pieces(testarr5, 1, 6, 10);
    char testarr6[8][8] = {
        {'B','*', '*', '*','*', '*','*','*'},
        {'B','*', '*', '*','*', '*','B','B'},
        {'B','*', '*', '*','*', 'W','W','W'},
        {'B','*', '*', '*','W', '*','W','W'},
		{'B','*', '*', 'W','*', '*','W','W'},
		{'B','*', 'W', '*','*', '*','W','W'},
        {'*','W', '*', '*','*', '*','W','W'},
		{'B','*', '*', '*','*', '*','B','B'}};
    test_flip_pieces(testarr6, 7, 0, 5);
    test_flip_pieces(testarr6, 1, 6, 5);
    test_flip_pieces(testarr6, 7, 7, 5);

    char testarrnew[8][8] = {
        {'*','*', '*', '*','*', '*','*','*'},
        {'*','*', '*', '*','*', '*','*','*'},
        {'*','*', 'W', 'B','*', '*','*','*'},
        {'*','*', '*', 'B','B', '*','*','*'},
		{'*','*', '*', 'B','W', '*','*','*'},
		{'*','*', '*', '*','*', '*','*','*'},
        {'*','*', '*', '*','*', '*','*','*'},
		{'*','*', '*', '*','*', '*','*','*'}};

    test_flip_pieces(testarrnew, 2, 2, 1);





    test_player_won(testarr6, 'B');
    test_player_won(testarr5, 'B');
    test_player_won(testarr4, 'B');
    init_board(testarr4);
    test_player_won(testarr4, '*');
    place_piece(testarr4, 'W', 5, 3);
    test_player_won(testarr4, 'W');


    //testing computer move

    unsigned int rowplace = 0;
    unsigned int colplace = 0;
    test_computer_move(testarr4, 'W', &rowplace, &colplace, 1);
    test_computer_move(testarr4, 'B', &rowplace, &colplace, 0);
    test_computer_move(testarr4, 'W', &rowplace, &colplace, 0);
    test_computer_move(testarr4, 'B', &rowplace, &colplace, 0);

    init_board(testarr4);
    test_computer_move(testarr4, 'B', &rowplace, &colplace, 1);

    char fullarr[8][8] = {
		{'B','B', 'B', 'B','B', 'B','B','B'},
        {'B','B', 'B', 'B','B', 'B','B','B'},
		{'B','B', 'B', 'B','B', 'B','B','B'},
		{'B','B', 'B', 'B','B', 'B','B','B'},
		{'B','B', 'B', 'B','B', 'B','B','B'},
        {'B','B', 'B', 'B','B', 'B','B','B'},
		{'B','B', 'B', 'B','B', 'B','B','B'},
		{'B','B', 'B', 'B','B', 'B','B','B'}};
    test_computer_move(fullarr, 'B', &rowplace, &colplace, 0);

    init_board(testarr4);

    //All of the testing for the algorithm is done above in place_piece_helper.
    //These tests should just show that place_piece, which is just an application of
    //The helper, is working properly.
    test_place_piece(testarr4, 'B', 2,3,2);
    test_place_piece(testarr4, 'W', 2,2,2);
    test_place_piece(testarr4, 'B', 2,1,2);
    test_place_piece(testarr4, 'W', 2,4,2);
    test_place_piece(testarr4, 'B', 4,5,3);
    test_place_piece(testarr4, 'W', 5,4,3);





    //test_place_piece(2,2);



    play_othello();
    return 0;
}

