
#include <stack>
#include <vector>
#include <queue>
#include<deque>
using namespace std;
class Solution {
private: 
    int col_size = 0;
    int row_size = 0;
public:
    int numIslands(vector<vector<char>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0){
            return 0;
        }
        int res = 0;
        row_size = grid.size();
        col_size = grid[0].size();
        for(int i=0;i<row_size;i++){
            for(int j=0;j<col_size;j++){
                if(grid[i][j] == '1'){
                    res++;
                    dfs(grid,i,j);
                }
            }
        }
        return res;

    }
    void dfs(vector<vector<char>> & grid,int row,int col){
        if(row < 0 || col < 0 || row >= row_size || col >= col_size){
            return ;
        }
        if(grid[row][col] == '0'){
            return;
        }
        grid[row][col] = '0';
        dfs(grid,row+1,col);
        dfs(grid,row-1,col);
        dfs(grid,row,col+1);
        dfs(grid,row,col-1);
    }
};