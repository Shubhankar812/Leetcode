#include <bits/stdc++.h>
using namespace std;

bool check(vector<vector<char>> &grid, int row, int col, char c)
{

    for (int i = 0; i < 9; i++)
    {
        if (grid[row][i] == c)
            return false;
        if (grid[i][col] == c)
            return false;

        if (grid[3 * (row / 3) + i / 3][3 * (col / 3) + i % 3] == c)
        {
            return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>> &grid)
{
    for (int i = 0; i < grid.size(); i++)
    {
        for (int j = 0; j < grid[0].size(); j++)
        {
            if (grid[i][j] == '.')
            {
                for (char c = '1'; c <= '9'; c++)
                {
                    if (check(grid, i, j, c))
                    {
                        grid[i][j] = c;

                        if (solve(grid))
                            return true;
                        else
                            grid[i][j] = '.';
                    }
                }
                return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<char>> &board)
{
    solve(board);
}

int main() {
    vector<vector<char>> board ={{"5","3",".",".","7",".",".",".","."},{"6",".",".","1","9","5",".",".","."},
    {".","9","8",".",".",".",".","6","."},{"8",".",".",".","6",".",".",".","3"},{"4",".",".","8",".","3",".",".","1"},
    {"7",".",".",".","2",".",".",".","6"},{".","6",".",".",".",".","2","8","."},{".",".",".","4","1","9",".",".","5"},
    {".",".",".",".","8",".",".","7","9"}};
    
    solveSudoku(board);

    for(int i=0;i<board.size();i++) {
        for(int j=0;board[0].size();j++) {
            cout<<board[i][j]<<" ";
        }
        cout<<"\n";
    }
}