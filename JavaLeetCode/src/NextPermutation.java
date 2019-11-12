public class NextPermutation {
        public void nextPermutation(int[] nums ){
            if(nums==null|| nums.length == 0){
                return ;
            }
            int firstSmall = -1;
            for(int i= nums.length-2;i>=0;i--){
                if(nums[i]<nums[i+1]){
                    firstSmall = i;
                    break;
                }
                //find the  first one a[i] < a[i+1] start form the right
            }
            int firstLarge = nums.length-1;
            if(firstSmall>=0){
                for(int i= nums.length-1;i>=0;i--){
                    if(nums[i]> nums[firstSmall]){
                        firstLarge = i;
                        break;
                    }
                }
                //find a[j] > a[i] from range length -1 to i+1
                swap(nums,firstSmall,firstLarge);
            }
            reverse(nums,firstSmall+1,nums.length-1);
            //swap i+1 to length -1 to get a larger num

        }
        public void swap(int[] nums,int i, int j ){
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
        public void reverse(int[] nums,int i,int j){
            while (i < j) {
                swap(nums,i,j);
                i++;
                j--;
            }
        }

}
