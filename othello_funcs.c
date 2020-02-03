/* Mason Wang, masonwang */
/* CS152, Winter 2019 */
/* hw3 */



#include <stdlib.h>
#include <stdio.h>
#include "othello_funcs.h"

/* print_othello_board
 * purpose: prints othello board
 * inputs:
 *   char board[8][8] - board to print
 * outputs:
 *   prints the given board to the screen.
 */
void print_othello_board( char board[8][8] )
{
        unsigned int i, j;
        for(i=0;i<8;i++)
        {
                for(j=0;j<8;j++)
                {
                        printf("%c ",board[i][j]);
                }
                printf("\n");
        }
}



/* init_board
 * purpose: initialize the board to all '*' characters
 * inputs:
 *   char board[8][8] - array to initialize
 * outputs:
 *   None
 */
void init_board(char board[8][8])
{
    int i;

    //goes through rows
    for(i=0; i<8; i++)
    {
        int j;
        //sets array in column of a row to '*'
        for(j=0; j<8; j++)
        {
            board[i][j] = '*';
        }
    }
    board[3][3] = 'W';
    board[4][4] = 'W';
    board[3][4] = 'B';
    board[4][3] = 'B';
    return;
}



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
unsigned int row, unsigned int col)
{

    unsigned int overallaccum = 0;
    int r;
    int c;


    char opp;
    //sets a variable storing the opponents color
    if(player == 'W')
    {
        opp = 'B';
    }
    else
    {
        opp = 'W';
    }



    //ROW LOOPS BEGIN
    int tempaccum = 0;
    //checks for possible flips to the bottom
    for(r = row+1; r<8; r++)
    {
        //goes through the different possible chars you might encounter
        if(board[r][col] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][col] == player)
        {
            break;
        }
        else if(r==7)
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][col] == opp)
        {
            tempaccum++;
            continue;
        }
    }
    overallaccum += tempaccum;





    tempaccum = 0;
    //checks for possible flips above
    for(r = row-1; r>=0; r--)
    {
        //goes through the different possible chars you might encounter
        if(board[r][col] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][col] == player)
        {
            break;
        }
        else if(r==0)
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][col] == opp)
        {
            tempaccum++;
            continue;
        }
    }
    overallaccum += tempaccum;





    //COLUMN FUNCTIONS BEGIN

     tempaccum = 0;
    //checks for possible flips to the right
    for(c = col+1; c<8; c++)
    {
        //goes through the different possible chars you might encounter
        if(board[row][c] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[row][c] == player)
        {
            break;
        }
        else if(c==7)
        {
            tempaccum = 0;
            break;
        }
        else if(board[row][c] == opp)
        {
            tempaccum++;
            continue;
        }
    }
    overallaccum += tempaccum;



    tempaccum = 0;
    //checks for possible flips to the left
    for(c = col-1; c>=0; c--)
    {
        //goes through the different possible chars you might encounter
        if(board[row][c] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[row][c] == player)
        {
            break;
        }
        else if(c==0)
        {
            tempaccum = 0;
            break;
        }
        else if(board[row][c] == opp)
        {
            tempaccum++;
            continue;
        }
    }
    overallaccum += tempaccum;



    //DIAGONAL FUNCTIONS BEGIN

    tempaccum = 0;
    //checks for possible flips further down the \ diagonal
    c = col+1;
    for(r = row+1; ((c<8)&&(r<8)); c++, r++)
    {
        //goes through the different possible chars you might encounter
        if(board[r][c] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == player)
        {
            break;
        }
        else if((c==7)||(r==7))
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == opp)
        {
            tempaccum++;
            continue;
        }
    }
    overallaccum += tempaccum;



    tempaccum = 0;
    //checks for possible flips UP the \ diagonal
    c = col-1;
    for(r = row-1; ((c>=0)&&(r>=0)); c--, r--)
    {
        //goes through the different possible chars you might encounter
        if(board[r][c] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == player)
        {
            break;
        }
        else if((c==0)||(r==0))
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == opp)
        {
            tempaccum++;
            continue;
        }
    }
    overallaccum += tempaccum;


    tempaccum = 0;
    //checks for possible flips DOWN the / diagonal
    c = col-1;
    for(r = row+1; ((c>=0)&&(r<8)); c--, r++)
    {
        //goes through the different possible chars you might encounter
        if(board[r][c] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == player)
        {
            break;
        }
        else if((c==0)||(r==7))
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == opp)
        {
            tempaccum++;
            continue;
        }
    }
    overallaccum += tempaccum;



    tempaccum = 0;
    //checks for possible flips UP the / diagonal
    c = col+1;
    for(r = row-1; ((c<8)&&(r>=0)); c++, r--)
    {
        //goes through the different possible chars you might encounter
        if(board[r][c] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == player)
        {
            break;
        }
        else if((c==7)||(r==0))
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == opp)
        {
            tempaccum++;
            continue;
        }
    }
    overallaccum += tempaccum;
    //checks to see if the move was valid
    if((overallaccum == 0)||(board[row][col] != '*'))
    {
        return 0;
    }
    board[row][col] = player;
    return overallaccum + 1;
}






/* place_piece
 * purpose: if valid, places piece in spot, AND flips pieces.
 * inputs:
 *   char board[8][8] - board
 *   player - player placing
 *   uint row - row to place in
 *   uint col - col to place in
 * outputs:
 *   uint - number of pieces placed or flipped
 */
unsigned int place_piece(char board[8][8], char player,
unsigned int row, unsigned int col)
{
    unsigned int result = place_piece_helper(board, player, row, col);
    if(result != 0)
    {
        flip_pieces(board, row, col);
    }
    return result;

}


/* move_valid
 * purpose: if move is valid, return something that's not zero.
 * inputs:
 *   char board[8][8] - board
 *   player - player placing
 *   uint row - row to place in
 *   uint col - col to place in
 * outputs:
 *   uint - number of pieces placed or flipped
 */
unsigned int move_valid(char board[8][8], char player, unsigned int row,
unsigned int col)
{
    unsigned int overallaccum = 0;
    int r;
    int c;


    char opp;
    //sets a variable storing the opponents color
    if(player == 'W')
    {
        opp = 'B';
    }
    else
    {
        opp = 'W';
    }



    //ROW LOOPS BEGIN
    int tempaccum = 0;
    //checks for possible flips to the bottom
    for(r = row+1; r<8; r++)
    {
        //goes through the different possible chars you might encounter
        if(board[r][col] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][col] == player)
        {
            break;
        }
        else if(r==7)
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][col] == opp)
        {
            tempaccum++;
            continue;
        }
    }
    overallaccum += tempaccum;





    tempaccum = 0;
    //checks for possible flips above
    for(r = row-1; r>=0; r--)
    {
        //goes through the different possible chars you might encounter
        if(board[r][col] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][col] == player)
        {
            break;
        }
        else if(r==0)
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][col] == opp)
        {
            tempaccum++;
            continue;
        }
    }
    overallaccum += tempaccum;





    //COLUMN FUNCTIONS BEGIN

     tempaccum = 0;
    //checks for possible flips to the right
    for(c = col+1; c<8; c++)
    {
        //goes through the different possible chars you might encounter
        if(board[row][c] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[row][c] == player)
        {
            break;
        }
        else if(c==7)
        {
            tempaccum = 0;
            break;
        }
        else if(board[row][c] == opp)
        {
            tempaccum++;
            continue;
        }
    }
    overallaccum += tempaccum;



    tempaccum = 0;
    //checks for possible flips to the left
    for(c = col-1; c>=0; c--)
    {
        //goes through the different possible chars you might encounter
        if(board[row][c] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[row][c] == player)
        {
            break;
        }
        else if(c==0)
        {
            tempaccum = 0;
            break;
        }
        else if(board[row][c] == opp)
        {
            tempaccum++;
            continue;
        }
    }
    overallaccum += tempaccum;



    //DIAGONAL FUNCTIONS BEGIN

    tempaccum = 0;
    //checks for possible flips further down the \ diagonal
    c = col+1;
    for(r = row+1; ((c<8)&&(r<8)); c++, r++)
    {
        //goes through the different possible chars you might encounter
        if(board[r][c] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == player)
        {
            break;
        }
        else if((c==7)||(r==7))
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == opp)
        {
            tempaccum++;
            continue;
        }
    }
    overallaccum += tempaccum;



    tempaccum = 0;
    //checks for possible flips UP the \ diagonal
    c = col-1;
    for(r = row-1; ((c>=0)&&(r>=0)); c--, r--)
    {
        //goes through the different possible chars you might encounter
        if(board[r][c] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == player)
        {
            break;
        }
        else if((c==0)||(r==0))
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == opp)
        {
            tempaccum++;
            continue;
        }
    }
    overallaccum += tempaccum;


    tempaccum = 0;
    //checks for possible flips DOWN the / diagonal
    c = col-1;
    for(r = row+1; ((c>=0)&&(r<8)); c--, r++)
    {
        //goes through the different possible chars you might encounter
        if(board[r][c] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == player)
        {
            break;
        }
        else if((c==0)||(r==7))
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == opp)
        {
            tempaccum++;
            continue;
        }
    }
    overallaccum += tempaccum;



    tempaccum = 0;
    //checks for possible flips UP the / diagonal
    c = col+1;
    for(r = row-1; ((c<8)&&(r>=0)); c++, r--)
    {
        //goes through the different possible chars you might encounter
        if(board[r][c] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == player)
        {
            break;
        }
        else if((c==7)||(r==0))
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == opp)
        {
            tempaccum++;
            continue;
        }
    }
    overallaccum += tempaccum;
    //sees if the move was valid
    if((overallaccum == 0)||(board[row][col] != '*'))
    {
        return 0;
    }
    return overallaccum + 1;
}


/* flip_pieces
 * purpose: flips the othello pieces given a move, returns number flipped
 * inputs:
 *   char board[8][8] - board
 * outputs:
 *   int, number flipped
 */
unsigned int flip_pieces(char board[8][8], unsigned int row, unsigned int col)
{
    unsigned int overallaccum = 0;
    int r;
    int c;

    char player = board[row][col];

    char opp;
    //sets a variable storing the opponents color
    if(player == 'W')
    {
        opp = 'B';
    }
    else
    {
        opp = 'W';
    }



    //ROW LOOPS BEGIN
    int tempaccum = 0;
    //checks for possible flips to the bottom
    for(r = row+1; r<8; r++)
    {
        //goes through the different possible chars you might encounter
        if(board[r][col] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][col] == player)
        {
            break;
        }
        else if(r==7)
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][col] == opp)
        {
            tempaccum++;
            continue;
        }
    }
    overallaccum += tempaccum;
    //if there were things to flip, flip
    if(tempaccum > 0)
    {
        //same as above, just flipping instead of counting
        for(r = row+1; r<8; r++)
        {
            //goes through the different possible chars you might encounter
            if(board[r][col] == '*')
            {
                break;
            }
            else if(board[r][col] == player)
            {
                break;
            }
            else if(r==7)
            {
                break;
            }
            else if(board[r][col] == opp)
            {
                board[r][col] = player;
                continue;
            }
        }
    }





    tempaccum = 0;
    //checks for possible flips above
    for(r = row-1; r>=0; r--)
    {
        //goes through the different possible chars you might encounter
        if(board[r][col] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][col] == player)
        {
            break;
        }
        else if(r==0)
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][col] == opp)
        {
            tempaccum++;
            continue;
        }
    }
    overallaccum += tempaccum;
    //if there were things to flip, flip
    if(tempaccum > 0)
    {
        //same as above, just flipping instead of counting
        for(r = row-1; r>=0; r--)
        {
            //goes through the different possible chars you might encounter
            if(board[r][col] == '*')
            {
                break;
            }
            else if(board[r][col] == player)
            {
                break;
            }
            else if(r==0)
            {
                break;
            }
            else if(board[r][col] == opp)
            {
                board[r][col] = player;
                continue;
            }
        }
    }





    //COLUMN FUNCTIONS BEGIN

     tempaccum = 0;
    //checks for possible flips to the right
    for(c = col+1; c<8; c++)
    {
        //goes through the different possible chars you might encounter
        if(board[row][c] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[row][c] == player)
        {
            break;
        }
        else if(c==7)
        {
            tempaccum = 0;
            break;
        }
        else if(board[row][c] == opp)
        {
            tempaccum++;
            continue;
        }
    }
    overallaccum += tempaccum;
    //if there were things to flip, flip
    if(tempaccum>0)
    {
        //same as above, just flipping instead of counting
        for(c = col+1; c<8; c++)
        {
           //goes through the different possible chars you might encounter
            if(board[row][c] == '*')
            {
                break;
            }
            else if(board[row][c] == player)
            {
                break;
            }
            else if(c==7)
            {
                break;
            }
            else if(board[row][c] == opp)
            {
                board[row][c] = player;
                continue;
            }
        }
    }



    tempaccum = 0;
    //checks for possible flips to the left
    for(c = col-1; c>=0; c--)
    {
        //goes through the different possible chars you might encounter
        if(board[row][c] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[row][c] == player)
        {
            break;
        }
        else if(c==0)
        {
            tempaccum = 0;
            break;
        }
        else if(board[row][c] == opp)
        {
            tempaccum++;
            continue;
        }
    }
    overallaccum += tempaccum;
    //if there were things to flip, flip
    if(tempaccum > 0)
    {
        //same as above, just flipping instead of counting
        for(c = col-1; c>=0; c--)
        {
            //goes through the different possible chars you might encounter
            if(board[row][c] == '*')
            {
                break;
            }
            else if(board[row][c] == player)
            {
                break;
            }
            else if(c==0)
            {
                break;
            }
            else if(board[row][c] == opp)
            {
                board[row][c] = player;
                continue;
            }
        }
    }



    //DIAGONAL FUNCTIONS BEGIN

    tempaccum = 0;
    //checks for possible flips further down the \ diagonal
    c = col+1;
    for(r = row+1; ((c<8)&&(r<8)); c++, r++)
    {
        //goes through the different possible chars you might encounter
        if(board[r][c] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == player)
        {
            break;
        }
        else if((c==7)||(r==7))
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == opp)
        {
            tempaccum++;
            continue;
        }
    }
    overallaccum += tempaccum;
    //if there were things to flip, flip
    if(tempaccum>0)
    {
         c = col+1;
         //same as above, just flipping instead of counting
         for(r = row+1; ((c<8)&&(r<8)); c++, r++)
         {
            //goes through the different possible chars you might encounter
            if(board[r][c] == '*')
            {
                break;
            }
            else if(board[r][c] == player)
            {
                break;
            }
            else if((c==7)||(r==7))
            {
                break;
            }
            else if(board[r][c] == opp)
            {
                board[r][c] = player;
                continue;
            }
        }
    }



    tempaccum = 0;
    //checks for possible flips UP the \ diagonal
    c = col-1;
    for(r = row-1; ((c>=0)&&(r>=0)); c--, r--)
    {
        //goes through the different possible chars you might encounter
        if(board[r][c] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == player)
        {
            break;
        }
        else if((c==0)||(r==0))
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == opp)
        {
            tempaccum++;
            continue;
        }
    }
    overallaccum += tempaccum;
    //if there were things to flip, flip
    if(tempaccum > 0)
    {
        c = col-1;
        //same as above, just flipping instead of counting
        for(r = row-1; ((c>=0)&&(r>=0)); c--, r--)
        {
            //goes through the different possible chars you might encounter
            if(board[r][c] == '*')
            {
                break;
            }
            else if(board[r][c] == player)
            {
                break;
            }
            else if((c==0)||(r==0))
            {
                break;
            }
            else if(board[r][c] == opp)
            {
                board[r][c] = player;
                continue;
            }
        }
    }


    tempaccum = 0;
    //checks for possible flips DOWN the / diagonal
    c = col-1;
    for(r = row+1; ((c>=0)&&(r<8)); c--, r++)
    {
        //goes through the different possible chars you might encounter
        if(board[r][c] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == player)
        {
            break;
        }
        else if((c==0)||(r==7))
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == opp)
        {
            tempaccum++;
            continue;
        }
    }
    overallaccum += tempaccum;
    //if there were things to flip, flip
    if (tempaccum>0)
    {
        c = col-1;
        //same as above, just flipping instead of counting
        for(r = row+1; ((c>=0)&&(r<8)); c--, r++)
        {
            //goes through the different possible chars you might encounter
            if(board[r][c] == '*')
            {
                break;
            }
            else if(board[r][c] == player)
            {
                break;
            }
            else if((c==0)||(r==7))
            {
                break;
            }
            else if(board[r][c] == opp)
            {
                board[r][c] = player;
                continue;
            }
        }
    }




    tempaccum = 0;
    //checks for possible flips UP the / diagonal
    c = col+1;
    for(r = row-1; ((c<8)&&(r>=0)); c++, r--)
    {
        //goes through the different possible chars you might encounter
        if(board[r][c] == '*')
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == player)
        {
            break;
        }
        else if((c==7)||(r==0))
        {
            tempaccum = 0;
            break;
        }
        else if(board[r][c] == opp)
        {
            tempaccum++;
            board[r][c] = player;
            continue;
        }
    }
    overallaccum += tempaccum;
    //if there were things to flip, flip
    if(tempaccum > 0)
    {
        c = col+1;
        //same as above, just flipping instead of counting
        for(r = row-1; ((c<8)&&(r>=0)); c++, r--)
        {
            //goes through the different possible chars you might encounter
            if(board[r][c] == '*')
            {
                break;
            }
            else if(board[r][c] == player)
            {
                break;
            }
            else if((c==7)||(r==0))
            {
                break;
            }
            else if(board[r][c] == opp)
            {
                board[r][c] = player;
                continue;
            }
        }
    }
    return overallaccum;
}


/* player_won
 * purpose: determines who wins
 * inputs:
 *   char board[8][8] - board to look at
 * outputs:
 *   char of winning player
 */
char player_won(char board[8][8])
{
    int blacknum = 0;
    int whitenum = 0;
    int r;
    //goes through rows
    for(r = 0; r<8; r++)
    {
        int c;
        //goes through columns
        for(c=0; c<8; c++)
        {
            //counts white and black
            if(board[r][c] == 'W')
            {
                whitenum++;
            }
            else if(board[r][c] == 'B')
            {
                blacknum++;
            }
        }
    }
    //determines and returns the winner
    if(blacknum>whitenum)
    {
        return 'B';
    }
    else if(whitenum>blacknum)
    {
        return 'W';
    }
    else
    {
        return '*';
    }
}



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
unsigned int *col)
{
    int r;
    //goes through rows
    for(r=0; r<8; r++)
    {
        int c;
        //goes through columns
        for(c =0; c<8; c++)
        {
            //if the move is valid, set the output parameters there
            if(place_piece(board, player, r, c) != 0)
            {
                *row = r;
                *col = c;
                return 1;
            }
        }
    }
    return 0;
}




/* valid_moves_remain
 * purpose: sees if valid moves remain for a player
 * inputs:
 *   char board[8][8] - board to move on
 *   char player - board for computer to play as
 * outputs:
 *   int - 1 if valid moves remain, 0 if not.
 */
int valid_moves_remain (char board[8][8], char player)
{
    int r;
    //goes through rows
    for(r=0; r<8; r++)
    {
        int c;
        //checks columns for remaining moves
        for(c =0; c<8; c++)
        {
            if(move_valid(board, player, r, c) != 0)
            {
                return 1;
            }
        }
    }
    return 0;
}

/* piece_count
 * purpose: sees how many pieces the character has
 * inputs:
 *   char board[8][8] - board
 *   char player - counting
 * outputs:
 *   number of pieces
 */
int piece_count(char board[8][8], char player)
{
    int num = 0;
    int r;
    //goes through rows
    for(r = 0; r<8; r++)
    {
        int c;
        //goes through columns
        for(c=0; c<8; c++)
        {
            //increases the count if it matches
            if(board[r][c] == player)
            {
                num++;
            }
        }
    }
    return num;
}


/* play_othello
 * purpose: allows the user to play othello
 * inputs: none, user inputs stuf
 * outputs: onscreen
 */
void play_othello()
{
    char current = 'B';
    int response;
    char board[8][8] = {
		{'B','B', 'B', 'W','W', 'B','W','*'},
        {'W','B', 'B', 'B','B', 'B','W','*'},
		{'B','B', 'B', 'B','W', 'B','W','*'},
		{'B','W', 'B', 'B','B', 'B','W','*'},
		{'W','B', 'B', 'W','W', 'B','B','*'},
		{'W','W', 'B', 'B','W', 'B','W','*'},
		{'B','W', 'B', 'B','B', 'B','B','*'},
		{'W','B', 'B', 'W','B', 'B','W','*'}};
    init_board(board);

    int turns = 0;

    printf("\n\n-----------------------");
    printf("\nWelcome to Othello!");
    printf("\n\nInitial Board: \n\n");
    print_othello_board(board);

    //loops through the game
    while(turns<64)
    {
        char opp;
        //sets opp to the opposite of the player whose turn it is
        if(current == 'B')
        {
            opp = 'W';
        }
        else
        {
            opp = 'B';
        }



        printf("\n\nPlayer %c, in what row (0-7) will you place your piece? "
        , current);
        scanf("%d", &response);
        //Checks for invalid answers
        if(response>7)
        {
            printf("\nInvalid row, try again");
            continue;
        }
        //checks for passes
        if(response < 0)
        {
            printf("\nPlayer found no valid moves. Moving on...");
            current = opp;
            continue;
        }
        unsigned int row = (unsigned int) response;

        printf("\nPlayer %c, in what column (0-7) will you place your piece? "
        , current);
        scanf("%d", &response);
        //Checks for invalid answers
        if(response>7)
        {
            printf("\nInvalid column, try again");
            continue;
        }
        //checks for passes
        if(response < 0)
        {
            printf("\nPlayer found no valid moves. Moving on...");
            current = opp;
            continue;
        }


        unsigned int col = (unsigned int)response;

        int valid = place_piece_helper(board, current, row, col);
        //sees if spot is occupied
        if(valid == 0)
        {
            printf("\nSorry, that move is invalid, try again");
            continue;
        }

        printf("Excellent Move. Resulting Board:\n\n");
        flip_pieces(board, row, col);
        print_othello_board(board);


        int whites = piece_count(board, 'W');
        int blacks = piece_count(board, 'B');

        printf("\n\nWhite: %d tiles, Black: %d tiles\n\n",
               whites, blacks);

        //sees if the game is over
        if((valid_moves_remain(board, current)==0)
           &&(valid_moves_remain(board, opp)==0))
        {
            printf("\n\nNo valid moves remain! Game Over.");
            char win_result = player_won(board);
            //sees who the winner is, prints
            if(win_result == 'B')
            {
                printf("\n\nCONGRATULATIONS, BLACK! (you won)");
                return;
            }
            else if(win_result == 'W')
            {
                printf("\n\nCONGRATULATIONS, WHITE! (you won)");
                return;
            }
            else if(win_result == '*')
            {
                printf("\n\nTie Game. Only Losers!");
            }
        }
        turns++;

        //switches player turn
        current = opp;
    }
    printf("\n\nTie game. Only Losers!");
    return;
}



