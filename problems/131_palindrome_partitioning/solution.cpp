#include<vector>
#include<string>
using namespace std;
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> res;
        if(s.length() == 0  ){
            return res;
        }
        int len =  s.length();
        vector<vector<bool>> mark(len,vector<bool>(n,true));
        for(int l= 2;l<=len;l++){
            for(int i= 0 ;i< len-l+1;i++){
                int j = i+l-1;
                if(s[i] == s[j] && mark[i+1][j-1]){
                    mark[i][j] = true;
                }else
                {
                    mark[i][j] = false;
                }
            }
        } 
        vector<string> temp;
        dfs(s,mark,0,res,temp);
        return res;
    }
    void dfs(string s,vector<vector<bool>>& mark,int i,vector<vector<string>>& res,vector<string>& temp){
        int len = s.length();
        if(i >= len){
            vector<string> r(temp.begin(),temp.end());
            res.push_back(r);
            return;
        }
        for(int l=1;l<len-i+1;l++){
            int j = i+l-1 ;
            if( j < len && mark[i][j]){
                temp.push_back(s.substr(i,l));
                dfs(s,mark,j+1,res,temp);
                temp.pop_back();
            }
        }
        return ;
    }
};