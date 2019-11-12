import java.util.List;
import java.util.ArrayList;
public class NQueue {
    public List<List<String>> solveNQueens(int n) {
        char[][] board = new char[n][n];
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                board[i][j] = '.';
            }
        }
        List<List<String>> res = new ArrayList<List<String>>();
        df(0,board,res);
        return res;
    }
    public boolean isValid(char[][] board,int row,int col){
        for(int i=0;i<row;i++){
            for(int j=0;j<board.length;j++){
                if(board[i][j]=='Q' && (j == col || Math.abs(col-j) == Math.abs(row-i) )){
                    return false;
                }
            }
        }
        return true;
    }
    public void df(int row,char[][] board,List<List<String>> res){
        int n = board.length;
        if(row == n-1){
            for(int i=0;i<n;i++){
                if(isValid(board,row,i)){
                    board[row][i] = 'Q';
                    ArrayList<String> temp = new ArrayList<String>(n);
                    for(int j=0;j<n;j++){
                        String str = String.valueOf(board[j]);
                        temp.add(str);
                    }
                    board[row][i] = '.';
                    res.add(new ArrayList<String>(temp));
                    break;
                }
            }
            return ;
        }
            for(int j=0;j<n;j++){
                if(isValid(board,row,j)){
                    board[row][j] = 'Q';
                    df(row+1,board,res);
                    board[row][j] = '.';
                }
            }
            return;
        
    }
    public static void main(String[] arg){
        NQueue nQueue = new NQueue();
        System.out.println(nQueue.solveNQueens(4));
    }
}