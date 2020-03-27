import java.util.ArrayList;
public class Solution {
    private ArrayList<String>res = new ArrayList<String>();
    public ArrayList<String> Permutation(String str) {
        if (str != null && str.length() > 0) {
            String tmp ="";
            int[] book = new int[str.length()];
            dfs(str,0, tmp, book);
        }
 
     
        return res;
    }
    private void dfs(String str,int index,String tmp,int[] book){
        if(index == str.length() && !res.contains(tmp)){
            res.add(tmp);
        }
        for(int i=0;i<str.length();i++){
            if(book[i]==0){
                tmp+=str.charAt(i);
                book[i] =1;
                dfs(str,index+1, tmp, book);
                book[i]=0;
                tmp = tmp.substring(0,tmp.length()-1);
            }
        }
    }
    public static void main(String[] args) {
        String s = "aa";
        ArrayList<String>res = new Solution().Permutation(s);
        System.out.println(res);

    }
}

