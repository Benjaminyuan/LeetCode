public class FindFirstAndFindLast {
    public int[] searchRange(int[] nums,int target){
        if(nums.length==0|| nums==null){
            return new int[]{-1,-1};
        }
        int[] res = new int[2];
        int firstIndex = findFirst(nums,target);
        int lastIndex = findLast(nums,target);
        res[0] = firstIndex;
        res[1] = lastIndex;
        return res;
    }
    public int findFirst(int[] nums,int target){
        int start = 0,end = nums.length-1;
        while(start+1<end){
            int mid = (end+start)/2;
            if(nums[mid]>=target){
                end = mid;
            }else{
                start = mid;
            }
        }
        if(nums[start] == target ){//判断优先很重要
            return start ;
        }else if(nums[end] == target){
            return end;
        }
            return -1;

    }
    public int findLast(int[] nums, int target){
        int start = 0,end = nums.length-1;
        while(start+1<end){
            int mid = (end+start)/2;
            if(nums[mid]<=target){
                start = mid;
            }else{
                end = mid;
            }
        }
        if(nums[end] == target ){
            return end ;
        }else if(nums[start] == target){
            return start ;
        }
            return -1;
    }
}
