public class StringMultiply {
    public String multiply(String num1,String num2){
        int n = num1.length();
        int m = num2.length();
        int[] result = new int[n+m];
        StringBuffer sb = new StringBuffer();
        sb.reverse();
        for(int i = n-1;i>=0;i--){
            for(int j = m-1;j>=0;j--){
                int num = (num1.charAt(i)-'0')*(num2.charAt(j)-'0')+result[j+i+1];
                result[i+j+1] = num%10;
                result[i+j] += num/10;
            }
        }
        for (int a :result){
            if(!(sb.length()==0&&a==0)){
                sb.append(a);
            }
        }
        return sb.length()==0?"0":sb.toString();
    }
}
