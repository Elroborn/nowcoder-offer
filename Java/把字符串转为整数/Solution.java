public class Solution {
    public int StrToInt(String str) {
		if(str.length()==0){
			return 0;
		}
		int is_minus = 1;
		int begin=0;
		if(str.charAt(0)=='-'){
			is_minus = -1;
			begin=1;
		}else if(str.charAt(0)=='+'){
			is_minus = 1;
			begin=1;
		}else{
			is_minus = 1;
			begin=0;
		}
		int res = 0;
		for(int j=begin;j<str.length();j++){
			char c = str.charAt(j);
			if(c>='0' && c<='9'){
				res = (res*10)+(c-'0');
			}else{
				return 0;
			}

			if( ((is_minus>0) && (res > Integer.MAX_VALUE)) ||
							((is_minus<0) && (res < Integer.MIN_VALUE))) //溢出
						{
							res = 0;
							break;
						}
		}
		return res*is_minus;
	}
	
	public static void main(String[] args) {
		System.out.println(new Solution().StrToInt("-123"));
	}
}