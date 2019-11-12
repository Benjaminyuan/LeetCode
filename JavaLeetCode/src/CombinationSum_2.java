 import com.sun.jdi.IntegerType;

import java.util.List;
import java.util.ArrayList;
import java.util.Arrays;
public class CombinationSum_2 {
    public List<List<Integer>> combinationSum2(int[] candidates, int target) {
        List<List<Integer>> resList = new ArrayList<List<Integer>>();
        if(candidates.length == 0|| candidates==null){
            return resList;
        }
        ArrayList<Integer> singleList = new ArrayList<Integer>();
        Arrays.sort(candidates);
        dfs(candidates,resList,singleList,target,0);
        return resList;
    }
    public void dfs(int[] candidates, List<List<Integer>> resList,List<Integer> singleList,int target,int level){
        if(target==0){
            resList.add(new ArrayList<Integer>(singleList));
            return ;
        }else if(target<0){
            return ;
        }
        for(int i=level;i<candidates.length;i++){
            if (i>level && candidates[i] == candidates[i-1]){
                continue;
            }
            //校验很重要
            if(candidates[i]>target){
                break;
            }
            singleList.add(candidates[i]);
            dfs(candidates,resList,singleList,target-candidates[i],i+1);
            singleList.remove(singleList.size()-1);
        }

    }
}
