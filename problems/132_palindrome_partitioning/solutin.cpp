#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    int minCut(string s) {
        int len = s.length();
        if(len == 0){
            return 0;
        }
        vector<vector<bool>> mark(len,vector<bool>(len,true));
         for(int l= 2;l<=len;l++){
            for(int i= 0 ;i< len-l+1;i++){
                int j = i+l-1;
                if(s[i] == s[j] && mark[i+1][j-1]){
                    mark[i][j] = true;
                }else{
                    mark[i][j] = false;
                }
            }
        } 
        vector<int> dp(len,len);
        for(int i = 0;i<len;i++){
            if(mark[0][i]){
                dp[i] = 0;
                continue;
            }
            for(int j=1;j<=i;j++){
                if(mark[j][i]){
                    dp[i] = min(dp[i],dp[j-1]+1);   
                }
            }
        }
        return dp[len-1];
    }
};