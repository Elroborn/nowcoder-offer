public class Solution {
    public boolean match(char[] str, char[] pattern)
    {
        if(str==null || pattern==null){
            return false;
        }
        return match(str,0,pattern,0);
        
    }

    public boolean match(char[] str,int i, char[] pattern,int j)
    {
        
        if(j==pattern.length){
            return i==str.length;
        }
        if(j==pattern.length-1 || (j+1<pattern.length && pattern[j+1]!='*')){// !='*'  则只有当前匹配
            if(i!=str.length && (str[i]==pattern[j] || pattern[j]=='.')){ //i!=str.length  避免越界
                return match(str,i+1, pattern,j+1);
            }else{
                return false;
            }
        }
        if(j+1 < pattern.length  && pattern[j + 1] == '*') { //=='*' 则可匹配0或多次， 0次的意思就是跳过即+2 多次则将i++ 直到0次
            if(str.length != i && (str[i] == pattern[j] || pattern[j] == '.')) {// 匹配多次
                return match(str,i, pattern,j+2) || match(str,i+1,pattern,j);
            }else{
                return match(str,i, pattern,j+2);// 不等则直接跳过
            }
        }
        return false;
    }
    public static void main(String[] args) {
        char str[] = {'a'};
        char pattern[] = {'.'};
        System.out.println(str.length);
        System.out.println(new Solution().match(str, pattern));
        
    }
}