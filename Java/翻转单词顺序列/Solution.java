import java.util.ArrayList;
public class Solution {
    public String ReverseSentence(String str) {
    if(str.trim().equals("")){
        return str;
    }
      ArrayList<String> arr = split_space(str);
      StringBuffer sb = new StringBuffer();
       for(int i=arr.size()-1;i>=0;i--){
           sb.append(arr.get(i));
           if(i>0){
               sb.append(" ");
           }
       }
       return sb.toString();
        
    }
 
    public ArrayList<String> split_space(String str){
        ArrayList<String>res = new ArrayList<String>();
        String tmp = "";
        for(int i=0;i<str.length();i++){
            if(str.charAt(i)!=' '){
                tmp +=str.charAt(i);
            }else{
                res.add(tmp);
                tmp = "";
            }
        }
        if(tmp!=""){
            res.add(tmp);
        }
        return res;
    }
    public static void main(String[] args) {
        String s = "I am a student.";
        System.out.println(new Solution().ReverseSentence(s));
    }
}