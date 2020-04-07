public class Solution {
    // Parameters:
    //    numbers:     an array of integers
    //    length:      the length of array numbers
    //    duplication: (Output) the duplicated number in the array number,length of duplication array is 1,so using duplication[0] = ? in implementation;
    //                  Here duplication like pointor in C/C++, duplication[0] equal *duplication in C/C++
    //    这里要特别注意~返回任意重复的一个，赋值duplication[0]
    // Return value:       true if the input is valid, and there are some duplications in the array number
    //                     otherwise false
    public boolean duplicate(int numbers[],int length,int [] duplication) {
        //在一个长度为n的数组里的所有数字都在0到n-1的范围内 ，因为数字是在0-n-1范围，则直接利用原来的数组做hash，不需要额外
        for(int i=0;i<length;i++){
            int index = numbers[i]%length;
            if(numbers[index]>length){ //说明之前已经有过该数字，否则默认应该不会>length的
                duplication[0] = numbers[i]%length;
                return true;
            }
            numbers[index]+=length; //之所以+=length，既可以保证一会做%length时，其对应的has不变，又能对number[i]做标记说明之前出现过
        }
        return false;
    }
    public static void main(String[] args) {
        int a[] ={2,3,2,1};
        int b[] ={0};
        System.out.println(new Solution().duplicate(a, 4, b));
        System.out.println(b[0]);
    }
}