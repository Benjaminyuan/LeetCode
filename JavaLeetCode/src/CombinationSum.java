import java.util.ArrayList;
import java.util.Arrays;
import java.util.Comparator;
import java.util.List;

public class CombinationSum {
    public List<List<Integer>> combinationSum(int[] candidates, int target){
        List<List<Integer>> res = new ArrayList<List<Integer>>();
        List<Integer> singleRes = new ArrayList<Integer>();
        if(candidates.length ==0|| candidates == null){
            return res;
        }
        Arrays.sort(candidates);
        findSingle(res, candidates, target, singleRes, 0);
        return res;
    }
    public void  findSingle( List<List<Integer>>  res ,int[] candidates,int target,List<Integer> singleList,int index){
        if(target==0){
            res.add(new ArrayList<Integer>(singleList));
            return ;
        }else if(target <0|| index>=candidates.length){
            return ;
        }
        for(int i = index;i<candidates.length;i++){
                //i 是去重复的关键
                singleList.add(candidates[i]);
                findSingle(res,candidates ,target-candidates[i] ,singleList ,i );
                singleList.remove(singleList.size()-1);
        }
    }
    public static void main (String[] arg ){
        CombinationSum combinationSum = new CombinationSum();
        int[] candidates = new int[]{10,1,2,7,6,1,5};
        List<List<Integer>> res = combinationSum.combinationSum(candidates,8);
        System.out.println(res.toString());
    }
}