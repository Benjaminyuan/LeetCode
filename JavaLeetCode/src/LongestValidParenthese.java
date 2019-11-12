import java.util.List;

public class LongestValidParenthese {
    public int longestValidParentheses(String s) {
        if(s.equals("") || s==null){
            return 0;
        }else{
            char[] strList = s.toCharArray();
            return 2*findNormal(strList, 0, strList.length-1);

        }
    }
    public int findNormal(char[] list,int start,int end){
       int  Validnum = 0;
        if(end-start<1){
            return 0;
        }else{

            if(list[start]=='('){
                int right = findNormal(list,start,end-1);
                if(list[end]==')'){
                    int left = findNormal(list, start+1,end);
                    Validnum =1+ (right>left?left:right);
                }else{
                    Validnum = right;
                }
            }else if(list[start]==')'){
                Validnum = list[end]=='('?findNormal(list, start+1, end-1):findNormal(list,start+1,end);
            }
        }
        return Validnum;
    }
    public static void main(String[] arg){
        LongestValidParenthese LVP = new LongestValidParenthese();
        System.out.println(LVP.longestValidParentheses("()()())))"));
    }

}
