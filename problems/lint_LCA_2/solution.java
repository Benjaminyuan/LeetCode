import java.util.*;
class ParentTreeNode {
    public ParentTreeNode parent, left, right;
 }

public class Solution {
    /*
     * @param root: The root of the tree
     * @param A: node in the tree
     * @param B: node in the tree
     * @return: The lowest common ancestor of A and B
     */
    public ParentTreeNode lowestCommonAncestorII(ParentTreeNode root, ParentTreeNode A, ParentTreeNode B) {
        // write your code here
        List<ParentTreeNode> a = path(A);
        List<ParentTreeNode> b = path(B);
        ParentTreeNode lca = null;
        int indexA = a.size()-1;
        int indexB = b.size()-1;
        while(indexA >=0 && indexB>= 0){
            if(a.get(indexA) != b.get(indexB)){
                break;
            }
            lca = a.get(indexA);
            indexA--;
            indexB--;
        }
        return lca;
    }
    public List<ParentTreeNode> path(ParentTreeNode root){
        List<ParentTreeNode> res = new ArrayList<>();
        while(root != null ){
            res.add(root);
            root = root.parent;
        }
        return res;
    }
}