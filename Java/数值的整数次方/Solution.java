public class Solution {
    public double Power(double base, int exponent) {
      double res =1;
      if(base==0){
        return 0;
      }
      if(exponent==0){
        return 1;
      }
      if(exponent<0){
        for(int i=0;i<(-exponent);i++){
          res *=base;
        }
        return 1.0/res;
      }
      for(int i=0;i<exponent;i++){
        res *=base;
      }
      return res;
  }
    // 快速求幂法 https://blog.csdn.net/hkdgjqr/article/details/5381028
    public double Power2(double base, int exponent) {
      double res = 1;
      if(base==0){
        return 0;
      }
      if(exponent==0){
        return 1;
      }
      int e = 0;
      if(exponent<0){
        e = -exponent;
      }else{
        e = exponent;
      }
      while(e>0){
        if(e%2==1){
          res = res*base;
        }
        base = base*base;
        e = e/2;
      }
      if(exponent<0){
       return 1.0/res;
      }else{
        return res;
      }


    }
  public static void main(String[] args) {
    System.out.println(new Solution().Power2(2, 3));
  }
}