
/* Mason Wang, masonwang */
/* CS152, Winter 2019 */
/* hw3 */



#include <stdlib.h>
#include <stdio.h>
#include "tictactoe_funcs.h"

/* test_init_board
 * purpose: tests the init_board
 * inputs:
 *   same as init_board
 * outputs:
 *   to screen
 */
void test_init_board(char array[3][3])
{
    printf("\n\nCalling init_board this 3x3 array:\n");
    print_tac_toe_board(array);
    printf("\n\nResulting array: \n");
    init_board(array);
    print_tac_toe_board(array);
}

/* test_place_piece
 * purpose: tests the place_piece function
 * inputs:
 *   unsigned int expected - expected output
 *   same as place_piece
 * outputs:
 *   to screen
 */
void test_place_piece(char board[3][3], char player, unsigned int row,
unsigned int col, unsigned int expected)
{
    printf("\n\nCalling place_piece(board, %c, %u, %u) on this 3x3 board:\n"
           , player, row, col);
    print_tac_toe_board(board);
    printf("\n\nResulting array: \n");
    int result = place_piece(board, player, row, col);
    print_tac_toe_board(board);
    printf("\nOutput = %u, expected %u", result, expected);

}

/* test_player_won
 * purpose: test the player won function
 * inputs:
 *   expected - 1 or 0, depending on if the input should be win or not
 *   rest are same as player_won
 * outputs:
 *   1 or 0, 1 if the player has won
 */
void test_player_won(char board[3][3], char player, unsigned int row,
unsigned int col, unsigned int expected)
{
    printf("\n\nCalling player_won(board, %c, %u, %u) on this 3x3 board:\n"
           , player, row, col);
    print_tac_toe_board(board);
    //printf("\n\nResulting array: \n");
    int result = player_won(board, player, row, col);
    //print_tac_toe_board(board);
    printf("\nOutput = %u, expected %u", result, expected);
}


/* test_computer_move
 * purpose: tests the computer move function
 * inputs:
 *   unsigned int expected - 0 or 1, based off of expected filled board or
 *   expected success
 *   char board[3][3] - array to play in
 *   char player - team of the computer
 *   unsigned int *row - output param - row to place character in
 *   unsigned int *col - output param - column to place character in
 * outputs:
 *   void - prints to screen
 */
void test_computer_move(char board[3][3], char player, unsigned int *row,
unsigned int *col, int expected)
{
    printf("\n\nCalling computer_move(board, %c) on this 3x3 board:\n"
           , player);
    print_tac_toe_board(board);
    printf("\n\nResulting move: \n");
    int result = computer_move(board, player, row, col);
    printf("\nrow: %u, column: %u\n", *row, *col);
    printf("\nResulting board: \n");
    print_tac_toe_board(board);
    printf("\nOutput = %d, expected %u", result, expected);
}






/* place_piece
 * purpose: tests the place_piece function
 * inputs:
 *   uint expected --- expected result
 *   char board[8][8] - board
 *   player - player placing
 *   uint row - row to place in
 *   uint col - col to place in
 * outputs:
 *   uint - number of pieces placed or flipped
 */
void test_place_piece(char board[8][8], char player, unsigned int row, unsigned int col, unsigned int expected)
{
    printf("\n\nCalling computer(board, %c) on this 3x3 board:\n"
           , player);
    print_tac_toe_board(board);
    printf("\n\nResulting move: \n");
    int result = computer_move(board, player, row, col);
    printf("\nrow: %u, column: %u\n", *row, *col);
    printf("\nResulting board: \n");
    print_tac_toe_board(board);
    printf("\nOutput = %d, expected %u", result, expected);

}







int main()
{
    char testarr[3][3] = {
		{'1','a', 'B'} ,
		{'2', 'f' , 'u'} ,
		{'3', '*', '*'}};

    test_init_board(testarr);

    test_place_piece(testarr, 'X', 2, 1, 1);
    test_place_piece(testarr, 'O', 2, 0, 1);
    test_place_piece(testarr, 'F', 2, 1, 0);

    //testing different patterns
    place_piece(testarr, 'X', 1, 1);
    test_player_won(testarr, 'X', 1, 1, 0);
    place_piece(testarr, 'X', 0, 1);
    test_player_won(testarr, 'X', 0, 1, 1);


    init_board(testarr);
    place_piece(testarr, 'O', 0, 0);
    test_player_won(testarr, 'O', 0, 0, 0);
    place_piece(testarr, 'O', 1, 1);
    test_player_won(testarr, 'O', 1, 1, 0);
    place_piece(testarr, 'O', 2, 2);
    test_player_won(testarr, 'O', 2, 2, 1);


    init_board(testarr);
    place_piece(testarr, 'Z', 2, 0);
    test_player_won(testarr, 'Z', 2, 0, 0);
    place_piece(testarr, 'Z', 1, 1);
    test_player_won(testarr, 'Z', 1, 1, 0);
    place_piece(testarr, 'Z', 0, 2);
    test_player_won(testarr, 'Z', 0, 2, 1);



    init_board(testarr);
    place_piece(testarr, 'Q', 0, 0);
    test_player_won(testarr, 'Q', 0, 0, 0);
    place_piece(testarr, 'Q', 0, 1);
    test_player_won(testarr, 'Q', 0, 1, 0);
    place_piece(testarr, 'Q', 0, 2);
    test_player_won(testarr, 'Q', 0, 2, 1);




    init_board(testarr);
    unsigned int r1;
    unsigned int c1;
    test_computer_move(testarr, 'X', &r1, &c1, 1);

    unsigned int r2;
    unsigned int c2;
    test_computer_move(testarr, 'X', &r2, &c2, 1);

    char fullarr[3][3] = {
		{'1','a', 'B'} ,
		{'2', 'f' , 'u'} ,
		{'3', 'A', 'F'}};
    test_computer_move(fullarr, 'X', &r2, &c2, 0);

    play_tic_tac_toe();







    return 0;
}
