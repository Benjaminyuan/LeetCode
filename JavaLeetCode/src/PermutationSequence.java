public class PermutationSequence {
    public String getPermutation(int n, int k) {
        int[] methodNum = new int[n];
        methodNum[0] = 1;
        for (int i = 1; i < n; i++) {
            methodNum[i] = methodNum[i - 1] * (i + 1);
        }
        int[] res = new int[n];
        boolean[] used = new boolean[n];
        int cur = 0;
        if (methodNum[n - 1] == k) {
            for(int i = n;i>=1 ;i--){
                res[n-i] = i;
            }
        } else {
            for (int i = n; i >= 2; i--) {
                if (k == 1 || k == 0) {
                    break;
                }

                int nowK = methodNum[i - 2];
                int count = k % nowK == 0 ? k/nowK : k/nowK+1 ;
                //这里是关键，k 是nowk的倍数时，应该是属于k/nowk区间的
                k = k - nowK*(count-1);
                for (int j = 0; j < n; j++) {
                    if (!used[j]) {
                        count--;
                    }
                    if (count == 0) {
                        res[cur] = j + 1;
                        cur++;
                        used[j] = true;
                        break;
                    }
                }
            }
            for (int i = 0; i < n; i++) {
                if (!used[i]) {
                    res[cur] = i + 1;
                    used[i] = true;
                    cur++;
                }
            }
        }
        
        String tempStr = "";
        for (int i = 0; i < n; i++) {
            tempStr += res[i];
        }
        return tempStr;
    }

    public static void main(String[] args) {
        PermutationSequence p = new PermutationSequence();
        System.out.println(p.getPermutation(4,9 ));
    }
}