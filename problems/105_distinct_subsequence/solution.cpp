#include<string>
#include<iostream>
using namespace std;    
class Solution {
public:
    int numDistinct(string s, string t) {
        int n = t.length();
        long long int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0] =1;
        for(int i=0;i<s.length();i++){
            for(int j= t.length()-1;j>-1;j--){
                if(s[i] == t[j]){
                    dp[j+1] += dp[j];
                }
            }
        }
        return (int)dp[n];
    }
};