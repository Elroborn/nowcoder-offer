public class Solution {
	public void reOrderArray(int [] array) { //插入排序思想，遇到奇数，就往前找位置插入
		if(array.length==0 || array.length==1){

			return ;
		}
		for(int i=1;i<array.length;i++){
			if((array[i]&1)==1){ //如果为奇数，前移
				int t = array[i],j = i-1;
				while(j>=0 && (array[j]&1)==0){ //如果前面是偶数
					array[j+1] = array[j];
					j--;
				}
				array[j+1] = t; //找到合适位置插入即可 
			}
		}
	}


	public static void main(String[] args) {
		int array[] = {2,4,6,1,3,5,7};
		new Solution().reOrderArray(array);
		for(int i = 0;i<array.length;i++){
			System.out.println(array[i]);
		}
	}
}