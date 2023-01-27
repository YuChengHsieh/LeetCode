#include <iostream>
#include <vector>
#include<unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<bool>> visited;
    vector<vector<char>> board_global;
    vector<pair<int,int>> change;
    int rows,cols;
    bool DFS(int row, int col){
        if(row<0 or row>=rows or col<0 or col>=cols){
            // cout << row << ' ' << col <<endl;
            return true;
        }
        if(board_global[row][col] == 'X' or visited[row][col]) return false;
        change.push_back(make_pair(row,col));
        visited[row][col] = true;
        // cout << '1' << ' ' << row << ' ' << col <<endl;
        bool left =DFS(row-1,col);
        bool right = DFS(row+1,col);
        bool up = DFS(row,col-1);
        bool down = DFS(row,col+1);
        return left or right or up or down;
    }
    void solve(vector<vector<char>>& board) {
        rows = board.size();
        cols = board[0].size();
        board_global = board;
        // construct visited
        visited = vector(rows, vector(cols,false));
        for(int i=0; i<rows; i++){
            for(int j=0; j<cols; j++){
                change={};
                if(board_global[i][j] == 'O' and !visited[i][j]){
                    bool find = DFS(i,j);
                    cout << find << endl;
                    if(!find){
                        for(auto &i:change){
                            board_global[i.first][i.second] = 'X';
                        }
                    }
                }
            }
        }
        board = board_global;
    }
};