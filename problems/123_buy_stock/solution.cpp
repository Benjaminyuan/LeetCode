#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0){
            return 0;
        }
        int n = prices.size();
        int minBefore[n];
        minBefore[0] = prices[0];
        for(int i=1;i<n;i++){
            minBefore[i] = min(minBefore[i-1],prices[i]);
        }
        int pf[n];
        pf[0] = 0;
        for(int i=1;i<n;i++){
            pf[i] = max(pf[i-1],prices[i]-minBefore[i]);
        }
        int maxAfter[n];
        maxAfter[n-1] = prices[n-1];
        for(int i= n-2;i>=0;i--){
            maxAfter[i] = max(maxAfter[i+1],prices[i]);
        }
        int pb[n];
        pb[n-1] =0;
        for(int i=n-2;i>=0;i--){
            pb[i] = max(pb[i+1],maxAfter[i]-prices[i]);
        }
        int res = 0;
        for(int i=0;i<n;i++){
            res = max(res,pb[i]+pf[i]);
        }
        return  res;
    }

};