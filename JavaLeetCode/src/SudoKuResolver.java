import java.util.LinkedHashSet;
import java.util.Set;

public class SudoKuResolver {
    //检验当前行，列，3*3矩阵是否满足条件
    public boolean IsValid(char[][] board,int row ,int col,char num){
        for(int i=0;i<9;i++){
            if(board[row][i]==num||board[i][col]==num||board[row/3*3+i/3][col/3*3+i%3]==num){
                return false;
            }
        }
        return true;
    }
    public void solveSudoku(char[][] board){
        backTrack(board, 0);
    }
    public boolean backTrack(char[][] board,int index){
        if (index==81){
            return true;
        }
        int row = index/9;
        int col = index%9;
        char c = board[row][col];
        if (c!='.'){
           //这个位置的数字已经给定了，直接跳转下一行;
            return backTrack(board, index+1);
        }
        for(char i='1';i<='9';i++){
            if(IsValid(board,row , col, i)){
                board[row][col] = i;
                //dfs,看是否满足条件
                boolean res= backTrack(board,index+1 );
                if(res){
                    return res;
                }
            }
            //题目的要求只要一组结果就可以，所以，如果res为false不采用i,重新赋值；
            board[row][col]='.';
        }
        return false;
    }
}
