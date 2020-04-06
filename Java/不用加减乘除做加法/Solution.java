public class Solution {
	//相加用异或模拟，仅为用与左移模拟
    public int Add(int num1,int num2) {
		while(num2!=0){
			int tmp = num1^num2;//模拟相加
			num2 = (num1&num2)<<1; //模拟进位
			num1 = tmp;
		}
		return num1;
	}
	public static void main(String[] args) {
		System.out.println(new Solution().Add(2, 3));
	}
}