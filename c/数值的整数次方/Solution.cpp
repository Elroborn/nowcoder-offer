#include<iostream>

// 快速求幂法 https://blog.csdn.net/hkdgjqr/article/details/5381028
class Solution {
public:
    double Power(double base, int exponent) {
    	double res = 1;
    	if(base==0){
    		return 0;
		}
		if(exponent==0){
			return 1;
		}
		int e = exponent;
		if(exponent<0){
			e = -exponent;
		}
		while(e>0){
			if(e&1){ //e%2==1
				res *=base;
			}
			base*=base;
			e>>=1; // e/=2
		}
		if(exponent<0){
			res = 1.0/res;
		}
		return res;
    
    }
};

int main(){
	std::cout<<Solution().Power(2,-3);
	return 0;
}
