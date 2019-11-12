import java.util.ArrayList;
import java.util.HashMap;
import java.util.Map;
import java.util.List;

public class GroupAnagrams{
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String,List<String>> res = new HashMap<String,List<String>>();
        for(String str : strs){
            String key = getKey(str);
            if(res.get(key) == null){
                ArrayList<String> temp = new ArrayList<>();
                temp.add(str);
                res.put(key,temp);
            }else{
                res.get(key).add(str);
            }
        }
        List<List<String>> resArray = new ArrayList<List<String>>();
        for(List<String> li : res.values()){
            resArray.add(li);
        }
        return resArray;
    }
    public String getKey(String word){
        char[] charList = word.toCharArray();
        for(int i=0;i<charList.length-1;i++){
            for(int j=i+1;j<charList.length;j++){
                if(charList[i]>charList[j]){
                    char temp = charList[i];
                    charList[i] = charList[j];
                    charList[j] = temp;
                }
            }
        }
        return new String(charList);
    }
    public static void main(String[] arg){
        String[] test = new String[]{"eat", "tea", "tan", "ate", "nat", "bat"};
        GroupAnagrams groupAnagrams = new GroupAnagrams();
        System.out.println(groupAnagrams.groupAnagrams(test));
    }
}