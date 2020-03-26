public class Solution {
    public String replaceSpace(StringBuffer str) {
        int i;
        String s="";
        for(i=0;i<str.length();i++){
            if(str.charAt(i)==' '){
                s += "%20";
            }
            else{
                s +=str.charAt(i);
            }
        }
    	return s;
    }
    public static void main(String[] args) {
        System.out.print(new Solution().replaceSpace(new StringBuffer("We Are Happy")));
    }
}