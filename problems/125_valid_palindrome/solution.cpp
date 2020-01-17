#include<string>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        if(s.length() <= 1){
            return true;
        }
        int i=0,j=s.length()-1;
        while(i<j){
            char start = ignoreCase(s[i]);
            char end = ignoreCase(s[j]);
            if((start < 'a' || start > 'z') &&( start <'0' || start > '9' )){
                i++;
                continue;
            }
            if((end <'a' || end > 'z') && ( end <'0' || end > '9')){
                j--;
                continue;
            }
            if(start != end){
                return false;
            }
            i++;
            j--;
            
        }
        return true;
    }
    char ignoreCase(char a){
        // 转化小写
        if(a>='A' && a<= 'Z'){
            a -= 'A'-'a';
        }
        return a;
    }
};