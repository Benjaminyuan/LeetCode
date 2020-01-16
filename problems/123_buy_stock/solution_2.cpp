#include<vector>
using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() == 0){
            return 0;
        }
        int buy_1 = -prices[0];
        int sold_1 = 0;
        int buy_2 = INT_MIN;
        int sold_2 = 0;
        for(int i=1;i<prices.size();i++){
            buy_1 =  max(buy_1,-prices[i]);
            sold_1 = max(sold_1,buy_1+prices[i]);
            buy_2 = max(buy_2,sold_1-prices[i]);
            sold_2 = max(sold_2,buy_2+prices[i]);
        }
        return  sold_2;
    }

};