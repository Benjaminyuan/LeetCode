public class SearchInRotatedSortArray {
    public int search(int[] nums,int target ){
        int left = 0, right= nums.length-1;
        int mid ;
        while(left<=right){
            mid = (left+right)/2;
            if(nums[mid]==target){
                return mid;
            }
            if(nums[left]<=nums[mid]){
                if(nums[left]<=target&&nums[mid]>target){
                    right = mid-1;
                }else{
                    left = mid+1;
                }
            }else{
                if(nums[mid]<target&&nums[right]>=target){
                    left = mid+1;
                }else{
                    right = mid-1;
                }
            }
        }
        return -1;
    }
    public static void main(String[] arg){
        SearchInRotatedSortArray searchInRotatedSortArray = new SearchInRotatedSortArray();
        int[] nums = {1,3};
        searchInRotatedSortArray.search(nums, 0);

    }
}
