#include<unordered_set>
#include<unordered_map>
#include<vector>
#include<queue>
#include<string>
using namespace std;
class Solution {
    public:
    /*
        The idea is to run a BFS from beginWord to endWord, while keeping track of the path.
        Once the currWord == endWord, we have found the shortest path.
        The nextLevel keeps track of all the words reachable from currLevel.
        All words in nextLevel should be erased from dict to avoid loops.( This is slight modification to the usual BFS ).
    
    */
        vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
            unordered_set< string > dict( wordList.begin(), wordList.end() );
            dict.erase( beginWord );
            queue< vector< string > > q;
            vector< vector< string > > result;
            q.push( { beginWord } );
            bool found = false;
            while( !q.empty() ) {
                int size = q.size();
                unordered_set< string > nextLevel;

                for( int i = 0 ; i < size ; ++i ) {
                    vector< string > currLevel = q.front();
                    q.pop();
                    string currWord = currLevel.back();
                    if( currWord == endWord ) {
                        found = true;
                        result.push_back( currLevel );
                    } else {
                        for( int i = 0 ; i < currWord.size() ; ++i ) {
                            char orig = currWord[ i ];
                            for( char ch = 'a' ; ch <= 'z' ; ++ch ) {
                                if( ch == orig ) continue;
                                currWord[ i ] = ch;
                                if( dict.find( currWord ) != dict.end() ) {
                                    nextLevel.insert( currWord );
                                    q.push( currLevel );
                                    q.back().push_back( currWord );
                                }
                            }
                            currWord[ i ] = orig;
                        }
                    }
                }
                if( found ) break;
                for( auto n : nextLevel ) {
                    dict.erase( n );
                }
            }
            return result;
        }

};
class Solution2 {
public:
vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
    vector<vector<string>> ans;
    unordered_set<string> dict;
    for (const auto &w: wordList){
        dict.insert(w);
    }
    if (!dict.count(endWord)) {
        return ans;
    }
    dict.erase(beginWord);
    dict.erase(endWord);
    unordered_set<string> q1{beginWord}, q2{endWord};
    unordered_map<string, vector<string>> next;
    bool reversed = false, found = false;
    while (!q1.empty()) {
        unordered_set<string> q;
        for (const auto &w: q1) {
            string s = w;
            for (size_t i = 0; i < s.size(); i++) {
                char ch = s[i];
                for (int j = 0; j < 26; j++) {
                    s[i] = j + 'a';
                    if (q2.count(s)) {
                        reversed? next[s].push_back(w): next[w].push_back(s);
                        found = true;
                    }
                    if (dict.count(s)) {
                        reversed? next[s].push_back(w): next[w].push_back(s);
                        q.insert(s);
                    }
                }
                s[i] = ch;
            }
        }
        if (found) break;
        for (const auto &w: q) {
            dict.erase(w);
        }
        if (q.size() <= q2.size()) {
            q1 = q;
        } else {
            reversed = !reversed;
            q1 = q2;
            q2 = q;
        }
    }
    if (!found) return ans;
    vector<string> path = {beginWord};
    backtracking(beginWord, endWord, next, path, ans);
    return ans;
}
void backtracking(const string &src, const string &dst, unordered_map<string, vector<string>> &next, vector<string> &path, vector<vector<string>> &ans) {
    if (src == dst) {
        ans.push_back(path);
        return;
    }
    for (const auto &s: next[src]) {
        path.push_back(s);
        backtracking(s, dst, next, path, ans);
        path.pop_back();
    }
}
};