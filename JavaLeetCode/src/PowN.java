public class PowN{
    public double myPow(double x, int n) {
        if( x< 0.0){
            return 0.0;
        }
        if(n == Integer.MIN_VALUE){
            if(Math.abs(x) > 1.0000){
                return 0.0;
            }
        }
        int abs = Math.abs(n);
        double res = myAbsPow(x, abs);
        System.out.printf("n:%d,abs:%d",n,abs);
        if(n != abs){
            System.out.printf("n:%d,abs:%d", n,abs);
            res = 1/res;
        }
        return res;
    }
    public double myAbsPow(double x,int n){
        if(n == 1){
            return x;
        }
        if(n == 0){
            return 1.0;
        }
        double halfRes = myAbsPow(x, n/2);
        double res;
        res = halfRes*halfRes;
        if(n%2 != 0){
            res *= x;
        }
        return res;
    }
    public static void main(String[] arg){
        PowN powN = new PowN();
        powN.myPow(2.000, -2147483648);
    }
}