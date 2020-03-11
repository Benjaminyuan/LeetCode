#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3){
            return res;
        }
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size()-2;i++){
            if(nums[i] > 0){
                break;
            }
            //去除重复
            
            if(i >0 && nums[i-1] == nums[i]){
                continue;
            }
            int start = i+1;
            int end = nums.size()-1;
            while(start < end){
                int sum = nums[start]+nums[end]+nums[i];
                if(sum < 0){
                    start++;
                }else if(sum > 0){
                    end--;
                }else{
                    res.push_back(vector<int>{nums[i],nums[start],nums[end]});
                    start++;
                    end--;
                    while(end > start && nums[start-1] == nums[start] ){
                        start++;
                    }
                     while(end > start && nums[end+1] == nums[end] ){
                        end--;
                    }
                }
            }
                
                

        }
        return res;
    }
};
