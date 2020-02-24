#include<vector>
#include<string>
using namespace std;
class Solution {
private:
    string s;
    string p;
public:
    bool isMatch(string st, string pt) {
        s = st;
        p = pt;
        return dfs(s.size()-1,p.size()-1);
    }
    bool dfs(int s_index,int p_index){
        if(p_index  == -1){
            return s_index == - 1? true:false;
        }

        if(p[p_index] == '*' ){
            bool noMatch = dfs(s_index,p_index - 2);
            bool matchOne = (s_index != -1 && (p[p_index-1] == s[s_index]|| p[p_index-1] == '.' )) && dfs(s_index-1,p_index);
            return noMatch || matchOne;
        }
        if(s_index == -1){
            return false;
        }                                        
        if( p[p_index] == '.' || p[p_index] == s[s_index]){
            return dfs(s_index-1,p_index-1);
        }
        return false;
    }
};