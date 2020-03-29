import java.util.ArrayList;

public class Solution {
    public int GetUglyNumber_Solution(int index) {
		if(index<7){
			return index;
		}
		ArrayList<Integer> res = new ArrayList<>();
		res.add(1);
		int t2=0,t3=0,t5=0;
		for(int i=1;i<index;i++){
			res.add(Math.min(res.get(t2)*2,Math.min(res.get(t3)*3,res.get(t5)*5)));
			if(res.get(i)==res.get(t2)*2){
				t2+=1;
			}
			if(res.get(i)==res.get(t3)*3){
				t3+=1;
			}
			if(res.get(i)==res.get(t5)*5){
				t5+=1;
			}
		}
		return res.get(index-1);
	
	}
	public static void main(String[] args) {
		System.out.println(new Solution().GetUglyNumber_Solution(10));
	}
}