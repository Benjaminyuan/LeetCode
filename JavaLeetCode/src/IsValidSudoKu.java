import java.util.*;

public class IsValidSudoKu {
    public static void main(String[] arg){
        char[][] board = {
  {'5','3','.','.','7','.','.','.','.'},
  {'6','.','.','1','9','5','.','.','.'},
  {'.','9','8','.','.','.','.','6','.'},
  {'8','.','.','.','6','.','.','.','3'},
  {'4','.','.','8','.','3','.','.','1'},
  {'7','.','.','.','2','.','.','.','6'},
  {'.','6','.','.','.','.','2','8','.'},
  {'.','.','.','4','1','9','.','.','5'},
  {'.','.','.','.','8','.','.','7','9'}};
        char[][] board_1 = {
    {'.','.','.','.','5','.','.','1','.'},
    {'.','4','.','3','.','.','.','.','.'},
    {'.','.','.','.','.','3','.','.','1'},
    {'8','.','.','.','.','.','.','2','.'},
    {'.','.','2','.','7','.','.','.','.'},
    {'.','1','5','.','.','.','.','.','.'},
    {'.','.','.','.','.','2','.','.','.'},
    {'.','2','.','9','.','.','.','.','.'},
    {'.','.','4','.','.','.','.','.','.'}};

        IsValidSudoKu isValidSudoku = new IsValidSudoKu();
       System.out.println(isValidSudoku.isValidSudoku(board));
       Set<Character> testSet = new HashSet<Character>();
       testSet.add('1');
       System.out.println(testSet.add('1'));
       System.out.println(testSet.add('2'));
    }
    public boolean isValidSudoku(char[][] board){
            for(int i = 0;i<=6;i+=3){
                for(int j=0;j<=6;j+=3){
                    if(!smallIsValid(board,i,j)){
                        return false;
                    }
                }

            }
            if(!bigIsValid(board)){
                return false;
            }
            return true;

    }
    public boolean smallIsValid(char[][] board ,int row,int col){
        Set<Character> judge = new LinkedHashSet<Character>();
        for(int i = row;i<3+row;i++){
            for(int j=col;j<3+col;j++){
                if(board[i][j]!='.'){
                  if(!judge.add(board[i][j])){
                      return false;
                    }
                }
            }
        }
        return true;
    }
    public boolean bigIsValid(char[][] board){
        //这个题涉及的更多是查找，所以用链表会快一些；
        Set<Character> row_judge = new LinkedHashSet<Character>();
        Set<Character> col_judge = new LinkedHashSet<Character>();
        for(int i = 0;i<9;i++){
            col_judge.clear();
            row_judge.clear();
            int j ;
            for(j =0 ;j<9;j++){
                if(board[i][j]!='.'){
                    if(!col_judge.add(board[i][j])){
                        return false;
                    }
                }
                if(board[j][i]!='.'){
                    if(!row_judge.add(board[j][i])){
                        return false;
                    }
                }
            }

        }
        return true;
    }
}
