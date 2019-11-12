public class RBTree<T extends Comparable<T>> {
    private RBNode<T> root ;
    public RBTree(){
        root = null;
    }
    private void rightRotate(RBNode<T> x ){
        RBNode<T> y = x.left;
        x.left = y.right;
        if (y.right!=null){
            y.right.parent = x;
        }
        y.parent = x.parent;
//        判断是否为根节点
        if(x.parent==null){
            this.root = y;
        }else{
            if(x.parent.right == x){
                x.parent.right =y;
            }else{
                x.parent.left = y;
            }
        }
        y.right = x;
        x.parent = y;
    }
    private void leftRotate(RBNode<T> x){
        RBNode<T> y = x.right;
        x.right = y.left;
        if(y.left!=null){
            y.left.parent = x;
        }
        y.parent = x.parent;
        if(x.parent==null){
            this.root = y;
        }else{
            if(x.parent.right==x){
                x.parent.right = y;
            }else{
                x.parent.left=y;
            }
        }
    }
    private void insert(T key){

    }
}
