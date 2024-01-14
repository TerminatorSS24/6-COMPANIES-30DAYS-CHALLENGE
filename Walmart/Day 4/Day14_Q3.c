/*
**********BATTLESHIPS IN A BOARD**********
Given an m x n matrix board where each cell is a battleship 'X' or empty '.', return the number of the battleships on board.

Battleships can only be placed horizontally or vertically on board. In other words, they can only be made of the shape 1 x k (1 row, k columns) or k x 1 (k rows, 1 column), where k can be of any size. At least one horizontal or vertical cell separates between two battleships (i.e., there are no adjacent battleships).

 

Example 1:

image: https://assets.leetcode.com/uploads/2021/04/10/battelship-grid.jpg

Input: board = [["X",".",".","X"],[".",".",".","X"],[".",".",".","X"]]
Output: 2
Example 2:

Input: board = [["."]]
Output: 0
*/
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int countBattleships(
    const char *const *const board,
    const int totalRow,
    const int *const totalCols)
{
    assert(totalRow >= 1);
    const int totalCol = totalCols[0];
    assert(totalCol >= 1);

    int battleShipCnt = 0;

    if (board[0][0] != '.')
        battleShipCnt += 1;

    for (int curCol = 1; curCol < totalCol; curCol += 1)
        if (board[0][curCol] != '.' && board[0][curCol - 1] == '.')
            battleShipCnt += 1;

    for (int curRow = 1; curRow < totalRow; curRow += 1)
        if (board[curRow][0] != '.' && board[curRow - 1][0] == '.')
            battleShipCnt += 1;

    for (int curRow = 1; curRow < totalRow; curRow += 1)
        for (int curCol = 1; curCol < totalCol; curCol += 1)
            if (
                board[curRow][curCol] != '.' &&
                (board[curRow - 1][curCol] == '.' && board[curRow][curCol - 1] == '.'))
                battleShipCnt += 1;

    return battleShipCnt;
}