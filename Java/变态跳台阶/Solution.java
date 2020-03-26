public class Solution {
	// 和跳台阶一样，比如一个台阶 则1种；2个台阶则2种；
	// 3个台阶时，青蛙可以在第2个或第1个或地上跳，则有 1 + 1 +2 = 4
	// 4个台阶时，青蛙可以在第3个或第2个或第1个或地上跳，则有 1 + 1 + 2 + 4 = 8 种
	//所以n个台阶即 1 + 1 + 2 + 4 + 8 + ..  = 2^(n -1)
    public int JumpFloorII(int target) {
		return 1<<(target-1);
	}
	public static void main(String[] args) {
		System.out.println(new Solution().JumpFloorII(4));
	}
}