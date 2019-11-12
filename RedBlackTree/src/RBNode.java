public class RBNode<T extends Comparable<T>> {
    boolean color ;
    //颜色
    T key;
    RBNode<T> left;
    RBNode<T> right;
    RBNode<T> parent;
    public RBNode(T key,boolean color,RBNode<T> parent,RBNode<T> left,RBNode<T> right){
        this.color = color;
        this.parent = parent;
        this.left = left;
        this.right = right;
        this.key = key;
    }
    public T getKey(){
        return this.key;
    }
    public String toString(){
        return""+key+(this.color==true?"R":"B");
    }
}
