#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        return getNSum(4,target,nums);
    }
    void kSum(int start,int k,int target,vector<int>& nums,vector<vector<int>>& res,vector<int>& cur){
        if(k == 2){
            int left = start,right = nums.size()-1;
            while(left < right){
                int temp = nums[left] + nums[right];
                if(temp < target){
                    left++;
                }else if(temp > target){
                    right--; 
                }else{
                    cur[cur.size()-2] = nums[left];
                    cur[cur.size()-1] = nums[right];
                    res.push_back(cur);
                    left++;
                    right--;
                    while(left < right && nums[left-1] == nums[left]){
                        left ++;
                    }
                    while(left < right && nums[right] == nums[right+1]){
                        right --;
                    }
                    
                }
            }
            return;
        }
        for(int i = start;i< nums.size()-k+1;i++){
            if(i == start || nums[i-1] != nums[i]){
                cur[cur.size()-k] = nums[i];
                kSum(i+1,k-1,target-nums[i],nums,res,cur); 
            }
        }
        return ;
        
    }
    vector<vector<int>> getNSum(int k,int target,vector<int>& nums){
        vector<vector<int>> res;
        if(nums.size() < k){
            return res;
        }
        sort(nums.begin(),nums.end());
        vector<int> cur(k,0);
        kSum(0,k,target,nums,res,cur);
        return res;
    }
};