import java.util.*;
public class MergeOverlapping{
    public int[][] merge(int[][] intervals) {
        if(intervals == null || intervals.length == 0){
            return Arrays.copyOf(intervals,0);
        }
        sort(intervals,0,intervals.length-1);
        // Arrays.sort(intervals,(i,j)->Integer.compare(i[0],j[0]) );
        int start=intervals[0][0] ,end=intervals[0][1];
        int resIndex =0;
        int cur =1;
        while(cur < intervals.length){
            int[] temp = intervals[cur];
            if(end >= temp[0]){
                end = temp[1] > end ? temp[1] : end;
                start = start > temp[0] ? temp[0]:start;
                intervals[resIndex][0] = start;
                intervals[resIndex][1] = end;
            }else{
                resIndex++;
                start = intervals[resIndex][0] = intervals[cur][0];
                end   = intervals[resIndex][1] = intervals[cur][1];
                
            }
            cur++;
        }
        return Arrays.copyOf(intervals,resIndex+1);
    }
    public void sort(int[][] array,int start,int end){
        if(start<end){
            int i = partition(array,start,end);
            sort(array,start,i-1);
            sort(array,i+1,end);
        }
    }
    public int partition(int[][] array,int start,int end ){
        int pos = start -1;
        int num = array[end][0];
        for(int i= start;i<end;i++){
            int temp = array[i][0];
            if(temp < num ){
                pos++;
                swap(array,pos,i);
            }
        }
        swap(array,end,++pos);
        return pos;
    }
    public void swap(int[][] array,int i,int j){
        int[] temp = array[i];
        array[i]  = array[j];
        array[j] = temp;
    }
    public static void main(String[] args) {
       MergeOverlapping mergeOverlapping = new MergeOverlapping();
       int[][] intervals = new int[][]{{2,3},{2,2},{3,3},{1,3},{5,7},{2,2},{4,6}};
       System.out.println(mergeOverlapping.merge(intervals));     
    }
}