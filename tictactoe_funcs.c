/* Mason Wang, masonwang */
/* CS152, Winter 2019 */
/* hw3 */



#include <stdlib.h>
#include <stdio.h>
#include "tictactoe_funcs.h"

/* print_tac_toe_board
 * purpose: prints a tic tac toe board
 * inputs:
 *   char board[3][3] - board to print
 * outputs:
 *   prints the given board to the screen.
 */
void print_tac_toe_board(char board[3][3])
{
	unsigned int i, j;
	for(i=0;i<3;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%c ",board[i][j]);
		}
		printf("\n");
	}
}



/* init_board
 * purpose: initialize the board to all '*' characters
 * inputs:
 *   char board[3][3] - array to initialize
 * outputs:
 *   None
 */
void init_board(char board[3][3])
{
    int i;

    //goes through rows
    for(i=0; i<3; i++)
    {
        int j;
        //sets array in column of a row to '*'
        for(j=0; j<3; j++)
        {
            board[i][j] = '*';
        }
    }
	return;
}

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
unsigned int col)
{
    //error checking
    if((row>2)||(col>2))
    {
        fprintf(stderr, "error place_piece: invalid row or column");
        return -1;
    }

    //checks if empty, if so, places
    if(board[row][col] == '*')
    {
        board[row][col] = player;
        return 1;
    }
	return 0;
}


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
unsigned int col)
{
     //error checking
    if((row>2)||(col>2))
    {
        fprintf(stderr, "error player_won: invalid row or column");
        return -1;
    }
    int r;
    //goes through rows
    for(r = 0; r<3; r++)
    {
        int c;
        int accum=0;
        //goes through columns, looks for consecutive pieces
        for(c=0; c<3; c++)
        {
            //increments, if matches player piece
            if(board[r][c] == player)
            {
                accum++;
            }
        }
        //returns 1 if a player has 3 in a row
        if(accum == 3)
        {
            return 1;
        }
    }

    int c;

    //goes through the columns
    for(c = 0; c<3; c++)
    {
        int r;
        int accum=0;

        //goes through items in each row, looking for consecutive pieces
        for(r=0; r<3; r++)
        {
            //increments accum with each matching char in a row
            if(board[r][c] == player)
            {
                accum++;
            }
        }
        //returns 1 if there are 3 in a column
        if(accum == 3)
        {
            return 1;
        }
    }

    int d1;
    int accum = 0;
    //checks diagonal
    for(d1 = 0; d1<3; d1++)
    {
        //sees if a location along a diagonal matches
        if(board[d1][d1] == player)
        {
            accum++;
        }
    }
    //returns 1 if there is a match across the diagonal
    if(accum == 3)
    {
        return 1;
    }

    int d2;
    accum = 0;
    //checks the other diagonal
    for(d2 = 0; d2<3; d2++)
    {
        //increments accum with consecutive matches
        if(board[d2][2-d2] == player)
        {
            accum++;
        }
    }
    //returns 1 if the diagonal wins the game
    if(accum == 3)
    {
        return 1;
    }
    return 0;
}

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
int computer_move(char board[3][3], char player,
unsigned int *row, unsigned int *col)
{
    int r;
    //goes through the rows
    for(r = 0; r<3; r++)
    {
        int c;
        //goes through the columns
        for(c = 0; c<3; c++)
        {
            //makes sure place is empty
            if(board[r][c] == '*')
            {
                place_piece(board, player, r, c);
                *row = r;
                *col = c;
                return 1;
            }
        }
    }

    return 0;
}


/* play_tic_tac_toe
 * purpose: allows the user to play tic tac toe
 * inputs: none, user inputs numbers
 * outputs: onscreen
 */
void play_tic_tac_toe()
{
    char current = 'X';
    unsigned int response;
    char board[3][3] = {
		{'*','*', '*'} ,
		{'*', '*', '*'} ,
		{'*', '*', '*'}};
    int turns = 0;

    printf("\n\n-----------------------");
    printf("\nWelcome to Tic Tac Toe!");
    printf("\n\nInitial Board: \n\n");
    print_tac_toe_board(board);

    //loops through the game
    while(turns<9)
    {
        printf("\n\nPlayer %c, in what row (0-2) will you place your piece? "
        , current);
        scanf("%u", &response);
        //Checks for invalid answers
        if(response>2)
        {
            printf("\nInvalid row, try again");
            continue;
        }
        unsigned int row = response;

        printf("\nPlayer %c, in what column (0-2) will you place your piece? "
        , current);
        scanf("%u", &response);
        //Checks for invalid answers
        if(response>2)
        {
            printf("\nInvalid column, try again");
            continue;
        }
        unsigned int col = response;

        int taken = place_piece(board, current, row, col);
        //sees if spot is occupied
        if(taken == 0)
        {
            printf("\nSorry, that spot is taken, try again");
            continue;
        }

        printf("Excellent Move. Resulting Board:\n\n");
        print_tac_toe_board(board);

        int win_result = player_won(board, current, row, col);
        //if a player wins
        if(win_result == 1)
        {
            printf("\n\nCONGRATULATIONS! Player %c won!", current);
            return;
        }
        turns++;

        //switches player turn
        if(current == 'X')
        {
            current = 'O';
        }
        else
        {
            current = 'X';
        }
    }
    printf("\n\nTie game. Only Losers!");
    return;
}





