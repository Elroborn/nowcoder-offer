import java.util.LinkedList;
public class Solution {
    public int LastRemaining_Solution(int n, int m) {
        LinkedList<Integer> ls = new LinkedList<>();
        for(int i=0;i<n;i++){
            ls.add(i);
        }
        int pos = 0;
        while(ls.size()>1){
            pos = (pos+m-1)%ls.size(); //因为是围成一圈
            ls.remove(pos);
        }
        if(ls.size()==1){
            return ls.get(0);
        }else{
            return -1;
        }
    }
    public static void main(String[] args) {
        System.out.println(new Solution().LastRemaining_Solution(5, 4));
            
    }
}