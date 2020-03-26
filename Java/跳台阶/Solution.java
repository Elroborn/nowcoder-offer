public class Solution {
    public int JumpFloor(int target) {
		if(target==1 || target ==2){
			return target;
		}
		return JumpFloor(target-1) + JumpFloor(target-2);
	}
	public int JumpFloor2(int target) {
		int f = 1,g = 2;
		while(target-1>0){
			g = f + g;
			f = g - f;
			target -=1;
		}
		return f;
	}
	public static void main(String[] args) {
		System.out.println(new Solution().JumpFloor(4));
	}
}