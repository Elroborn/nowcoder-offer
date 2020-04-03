public class Solution {
    public String LeftRotateString1(String str,int n) {
        int len = str.length();
        if(len<n){
            return "";
        }
        str +=str;
        str = str.substring(n, n+len);
        return str;
    }
    // YX = (XTYT)T
    public String LeftRotateString(String str,int n) {
        if(str.length()<n){
            return "";
        }
        str = reverse(str, 0, n-1);
        str = reverse(str, n, str.length()-1);
        str = reverse(str, 0, str.length()-1);
        return str;

    }
    public String reverse(String s,int left,int right){
        StringBuffer sb = new StringBuffer(s);
        for(int i=left,j=right;i<j;i++,j--){
            char t = sb.charAt(i);
            sb.setCharAt(i, sb.charAt(j));
            sb.setCharAt(j, t);
        }
        return sb.toString();
    }
    public static void main(String[] args) {
        String str = "abcXyzder";
        System.out.println(new Solution().LeftRotateString(str, 3));
    }
}