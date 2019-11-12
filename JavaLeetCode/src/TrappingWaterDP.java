public class TrappingWaterDP {
    public int trap(int[] height){
        if (height.length == 0|| height == null){
            return 0;
        }
        int capacity = 0;
        int len = height.length;
        int[] left_max = new int[len];
        int[] right_max = new int[len];
        left_max[0] = height[0];
        right_max[0]= height[len-1];
        for(int i =1;i<len;i++){
            left_max[i] = Math.max(height[i],left_max[i-1]);
        }
        for(int i =len-2;i>=0;i--){
            right_max[i] = Math.max(height[i],right_max[i+1]);
        }
        for(int i =0;i<len;i++){
            capacity+= Math.min(left_max[i], right_max[i])-height[i];
        }
        return capacity;
    }
    public int trap_1(int[] height){
        if(height.length<=2|| height==null){
            return 0;
        }
        int left = 0;
        int len = height.length;
        int right = len-1;
        int capacity = 0;
        int left_max = -1;
        int  right_max= -1;
        while(left<right){
            if(left_max<right_max){
                while(left<right&&left_max>=height[left]){
                    capacity += left_max-height[left];
                    left++;
                }
                if(left>=right){
                    break;
                }else{
                    left_max = height[left];
                }
            }else{
                while(left<right&& right_max>= height[right]){
                    capacity += right_max-height[right];
                    right--;
                }
                if(left>=right){
                    break;
                }else{
                    right_max = height[right];
                }
            }
        }
        return capacity;
    }
}
