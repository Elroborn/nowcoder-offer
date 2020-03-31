import java.util.ArrayList;
import java.util.HashMap;

public class Solution {
    public int FirstNotRepeatingChar(String str) {
        HashMap<String,Integer>char_map = new HashMap<>();
        ArrayList<String> single = new ArrayList<>();
        for(int i=0;i<str.length();i++){
            Integer v = char_map.get(str.charAt(i)+"");
            if(v==null){ //第一次出现
                char_map.put(str.charAt(i)+"",1);
                single.add(str.charAt(i)+"");
            }else{ //第多次
                char_map.put(str.charAt(i)+"",++v);
                single.remove(str.charAt(i)+"");
            }
        }
        for(int i=0;i<str.length();i++){
            if(single.contains(str.charAt(i)+"")){
                return i;
            }
        }
        
        return -1;
    }
    public static void main(String[] args) {
        System.out.println(new Solution().FirstNotRepeatingChar("acah"));
    }
}