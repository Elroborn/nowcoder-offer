import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
public class Solution {
    public String PrintMinNumber(int [] numbers) {
        ArrayList<String> list = new ArrayList<>();
        for(int i:numbers){
            list.add(i+"");
        }
        Collections.sort(list, new Comparator<String>() {
            public int compare(String str1,String str2){
                return (str1+str2).compareTo(str2+str1);
            }
        });
        String res="";
        for(String s:list){
            res+=s;
        }
        return res;
    }
    public static void main(String[] args) {
        int a[] = {3,2,11};
        System.out.println(new Solution().PrintMinNumber(a));
    }
}