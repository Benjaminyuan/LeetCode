#include<vector>
#include<cmath>
using namespace std;
class Solution {
public:

    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0){
            return 0;
        }
        int maxP = 0;
        int cur =0;
        
        for(int i=0;i<prices.size()-1;i++){
            int t = prices[i+1]-prices[i];
            if(cur>0){
                cur+= t;
            }else{
                cur = t;
            }
            maxP = max(cur,maxP);
        }
        return maxP;
    }
};