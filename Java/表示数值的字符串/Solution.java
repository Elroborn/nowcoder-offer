public class Solution {
    public boolean isNumeric(char[] str) {
		boolean hasE=false,hasDot=false,hasSign=false;
		for(int i=0;i<str.length;i++){
			if(str[i]=='.'){
				if(hasDot || hasE){
					return false;
				}
				hasDot = true;
			}
			else if(str[i]=='+'|| str[i]=='-'){
				// 第一次出现+-符号，且不是在字符串开头，则也必须紧接在e之后
				if(!hasSign && i>0 && str[i-1]!='e'&& str[i-1]!='E'){
					return false;
				}
				// 第二次出现+-符号，则必须紧接在e之后
				if(hasSign && str[i-1]!='e'&&str[i-1]!='E'){
					return false;
				}
				hasSign = true;
			}
			else if(str[i]=='e' || str[i]=='E'){
				if(i==str.length-1){ //E后边必须有内容
					return false;
				}
				if(hasE){
					return false;
				}
				hasE = true;
			}
			else if(str[i]<'0'||str[i]>'9'){
				return false;
			}
		}
		return true;
	}
	public static void main(String[] args) {
		char[] str = {'+','1'};
		System.out.println(new Solution().isNumeric(str));
	}
}