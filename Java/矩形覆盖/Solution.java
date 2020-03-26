public class Solution {
    public int RectCover1(int target) {
        if(target<=2){
            return target;
        }
        return RectCover(target-1) + RectCover(target-2);

    }
    public int RectCover(int target) {
       if(target==0){
	return 0;       
}
       int f = 1,g =2;
       while(target-1>0){
           g = f+g;
           f = g-f;
           target -=1;
       }
       return f;

    }
    public static void main(String[] args) {
        System.out.println(new Solution().RectCover(3));
    }
}