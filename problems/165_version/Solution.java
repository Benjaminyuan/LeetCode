public class Solution {
    public static int  compareVersion(String version1, String version2) {
        String[] v1 = version1.split("\\.");
        String[] v2 = version2.split("\\.");

        int m = Math.min(v1.length,v2.length);
        for(int i=0;i<m;i++){
            int a =  Integer.parseInt(v1[i]);
            int b =  Integer.parseInt(v1[i]);
            if(a == b){
                continue;
            }else{
                return a>b?1:-1;
            }
        }
        if(v1.length == v2.length){
            return 0;
        }
        return v1.length > v2.length? 1:-1;

    }
    public static void main(String[] args) {
        compareVersion("0.1","1.1");
    }
}