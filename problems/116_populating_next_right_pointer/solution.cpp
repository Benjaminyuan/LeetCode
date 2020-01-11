#include<queue>
using namespace std;
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
class Solution {
public:
    Node* connect(Node* root) {
        if(root == nullptr){
            return root;
        }
        queue<Node*> q;
        int level_size = 1;
        q.push(root);
        while(!q.empty()){
            Node* cur = q.front();
            q.pop();
            int next_level = 0;
            for(int i = 0;i<level_size-1;i++){
                cur->next = q.front();
                q.pop();
                if(cur->left != nullptr){
                    q.push(cur->left);                    
                    q.push(cur->right);
                    next_level+=2;
                }
                cur = cur->next;
            }
            cur->next = nullptr;
            if(cur->left != nullptr){
                q.push(cur->left);                    
                q.push(cur->right);
                next_level+=2;
            }
            level_size = next_level;
        }
        return root;
    }
};