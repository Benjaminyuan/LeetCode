import java.util.*;
public class GrayCode{
    public List<Integer> getGrayCodeWithN(int n) {
        List<Integer> res = new ArrayList<Integer>((int)(Math.pow(2,n)));
        res.add(0);
        if (n == 0){
            return res;
        }
        res.add(1);
        if(n==1){
            return  res;
        }
        for(int i=2;i<=n;i++){
            int border = (int)(Math.pow(2,i-1));
            int reverseIndex = border-1;
            while(reverseIndex >=0){
                res.add(res.get(reverseIndex)|(1<<i-1));
                reverseIndex--;
            }
        }
        return res;
    } 
    public List<Integer> getGrayCodeWithoutN(int n) {
        List<Integer> res = new ArrayList<Integer>();
        res.add(0);
        if (n == 0){
            return res;
        }
        res.add(1);
        if(n==1){
            return  res;
        }
        for(int i=2;i<=n;i++){
            int border = (int)(Math.pow(2,i-1));
            int reverseIndex = border-1;
            while(reverseIndex >=0){
                res.add(res.get(reverseIndex)|(1<<i-1));
                reverseIndex--;
            }
        }
        return res;
    } 
    public static void main(String[] arg){
        GrayCode grayCode = new GrayCode();
        int n=0;
        long withInitN  = 0;
        long withoutN = 0;
        for(int i=0;i<10000;i++){
            long Nstart = System.nanoTime();
            grayCode.getGrayCodeWithN(n);
            long Nend = System.nanoTime();
            withInitN = Nend - Nstart;
            System.out.println("initWith"+i+"cost time: " + withInitN);

            // ----------
            long start = System.nanoTime();
            grayCode.getGrayCodeWithoutN(n);
            long end = System.nanoTime();
            withoutN = end-start;
            System.out.println("initWithoutN"+i+" cost time: " + withoutN);
        }
    }
}