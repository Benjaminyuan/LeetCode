
#include <stack>
#include <vector>
#include <queue>
#include<deque>
#include<unordered_map>
#include<unordered_set>
using namespace std;

class Solution {

private: 
    int col_size = 0;
    int row_size = 0;
public:
    int largestIsland(vector<vector<int>>& grid) {
        if(grid.size() == 0 || grid[0].size() == 0){
            return 0;
        }
        int count = 1;
        int res = 0;
        unordered_map<int,int> m;
        row_size = grid.size();
        col_size = grid[0].size();
        for(int i=0;i<row_size;i++){
            for(int j=0;j<col_size;j++){
                if(grid[i][j] == 1){
                    count++;
                    int area = 0;
                    dfs(grid,i,j,count,area);
                    m[count] = area;
                    // 如果没有地方可填或者，填了也无法变大的情况
                    res = max(res,area);
                }
            }
        }
        unordered_set<int> s;
        for(int i=0;i<row_size;i++){
            for(int j=0;j<col_size;j++){
                if(grid[i][j] == 0){
                    int area = 0;

                    if(i > 0 && grid[i-1][j] > 1){
                        s.insert(grid[i-1][j]);
                        area += m[grid[i-1][j]];
                    }
                    if(i < row_size-1 && grid[i+1][j] > 1 && s.find( grid[i+1][j]) == s.end()){
                        s.insert(grid[i+1][j]);

                        area += m[grid[i+1][j]];
                    }
                    if(j > 0 && grid[i][j-1] > 1 && s.find( grid[i][j-1]) == s.end()){
                        s.insert(grid[i][j-1]);
                        area += m[grid[i][j-1]];
                    }
                    if(j < col_size-1 && grid[i][j+1] > 1 && s.find( grid[i][j+1]) == s.end()){
                        s.insert(grid[i][j+1]);
                        area += m[grid[i][j+1]];
                    }
                    res = max(res,area+1);
                    s.clear();
                }
            }
        }
        return res;
    }
    void dfs(vector<vector<int>> & grid,int row,int col,int island_seq,int& area){
        if(row < 0 || col < 0 || row >= row_size || col >= col_size){
            return ;
        }
        if(grid[row][col] != 1){
            return;
        }
        area++;
        grid[row][col] = island_seq;
        dfs(grid,row+1,col,island_seq,area);
        dfs(grid,row-1,col,island_seq,area);
        dfs(grid,row,col+1,island_seq,area);
        dfs(grid,row,col-1,island_seq,area);
    }
};