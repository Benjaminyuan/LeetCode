import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Set;
/*
* 这个算法的结果偏小，实际上不需要严格的'V'字行排列
*
* */
public class TrappingRainWater {
    public int trap(int[] height){
        if(height.length == 0|| height==null){
            return 0;
        }
        List<List<Integer>> res = findContainer(height);
        int capacity = 0;
        for(int i =0;i<res.size();i++){
            List<Integer> list = res.get(i);
             int start = list.get(0);
             int end = list.get(2);
             int mid = list.get(1);
             int h = height[start]-height[mid]>height[end]-height[mid]?height[end]:height[start];
             System.out.println(h);
             for(int j = start;j<=end;j++){
                 int c = h - height[j];
                 if (c>0){
                     capacity += c;
                 }
             }
        }
        System.out.println(res.toString());

        return capacity ;
    }
    public List<List<Integer>> findContainer(int[] height){
        ArrayList<List<Integer>> res =  new ArrayList<List<Integer>>();
        int start = -1;
        int end = -1;
        int mid = -1;
        int i  = 1;
        boolean counting = false;
        boolean ACE = false;
        while(i<height.length){
          if (counting ==true){
                if ((ACE==false&& height[i-1] >=height[i])||(ACE==true && height[i-1]<=height[i])){
                    i++;
                }else if (ACE==false&& height[i-1] < height[i]){
                    ACE =true;
                    mid = i-1;
                    i++;
                }else /*if ((ACE==true&& height[i-1]>height[i]))*/{
                    end = i -1;
                    add(res, start ,mid ,end );
                    counting = false;
                    ACE = false ;
                }
                if(i==height.length&&ACE==true){
                    end = i-1 ;
                    add(res, start, mid,end );
                    break;

                }
            }else if (i<=height.length-1&&height[i-1]>height[i]&& counting == false) {
                start = i-1;
                counting = true;
                i++;
            }else{
                i++;
            }

        }
        return res;
    }
    public void add(List<List<Integer>> res,int start,int mid ,int end){
        if (end-start>=2){
            List<Integer> temp = new ArrayList<>();
            temp.add(start);
            temp.add(mid);
            temp.add(end);
            res.add(temp);
        }
    }
    public static void main(String[] arg){
        TrappingRainWater trappingRainWater = new TrappingRainWater();
        System.out.println(trappingRainWater.trap(new int[] {5,2,1,2,1,5}));
    }
}
