public class Solution {
    String s = "";
    int[] hash = new int[256];
    //Insert one char from stringstream
    public void Insert(char ch)
    {
        s+=ch;
        hash[ch] +=1;
        
    }
  //return the first appearence once char in current stringstream
    public char FirstAppearingOnce()
    {
        for(int i=0;i<s.length();i++){
            if(hash[s.charAt(i)]==1){
                return s.charAt(i);
            }
        }
        return '#';
    }
    public static void main(String[] args) {
        // Solution s = new Solution();
        // s.Insert('g');
        // s.Insert('o');
        // s.Insert('o');
        // s.Insert('g');
        // s.Insert('l');
        // s.Insert('e');
        // System.out.println(s.FirstAppearingOnce());

    }
}