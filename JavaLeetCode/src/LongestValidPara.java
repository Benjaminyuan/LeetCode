import java.util.HashMap;
import java.util.Map;

public class LongestValidPara {
    public int longestValidParentheses(String s){
        int MaxNum = 0;
        if(s.equals("")||s==null){
            return 0;
        }else{
            int left=0 ,right=0;
            for(int i=0;i<s.length();i++){
                if(s.charAt(i)=='('){
                    left++;
                }else{
                    right++;
                }
                if(left==right){
                    MaxNum = Math.max(MaxNum, left*2);
                }else if(left < right){
                    left = right= 0;
                }
            }
            left =right=0;
            for(int i=s.length()-1;i>=0;i--){
                if(s.charAt(i)==')'){
                    right++;
                }else{
                    left++;
                }
                if (left == right){
                    MaxNum = Math.max(MaxNum,left*2);
                }else if (left > right){
                    left= right=0;
                }
            }
            return MaxNum;
        }
    }
    public static void main(String[] arg){
        LongestValidPara LVP = new LongestValidPara();
        System.out.println(LVP.longestValidParentheses("((())"));
    }

}

