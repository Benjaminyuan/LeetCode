import java.util.Scanner;

class JumpGame {
    public int jump(int[] nums) {
        if(nums == null || nums.length == 0 ||nums.length == 1 ){
            return 0;
        }
        
        int[] minStep = new int[nums.length];
        minStep[0]=0;
        minStep[1]=1;
        for(int i=2;i<nums.length;i++){
            minStep[i] = Integer.MAX_VALUE;
        }
        for(int i=0;i<nums.length;i++){
            for(int j= 1;j<=nums[i];j++){
                if(i+j >= nums.length){
                      break;
                 }
                 if(minStep[i]+1 < minStep[i+j]){
                      minStep[j+i] = minStep[i]+1;
                }
            }
        }
        return minStep[nums.length-1];
        
        
    }
    public int fastJump(int[] nums){
        int jump = 0;int start = 0; int far =0;
        for (int i=0;i<nums.length-1;i++){
            far = Math.max(far,i+nums[i]);
            if(i == start ){
                jump++;
                start = far;
            }
        }
        return jump;
    }
    public static void main(String[] arg){
        JumpGame jumpGame = new JumpGame();
        Scanner sc = new Scanner(System.in);
        while(sc.hasNextLine()){
            String a = sc.nextLine();
            String[] digital = a.split("\\s");
            for(String str : digital){
                System.out.println(str);
            }
        }
        // int[] data = new int[]{2,3,1,1,4};
        // jumpGame.jump(data);
    }
}