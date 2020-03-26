#include<iostream>
#include<vector>
using namespace std;

//链接：https://www.nowcoder.com/questionTerminal/a861533d45854474ac791d90e447bafd?f=discussion
// 来源：牛客网

// BST的后序序列的合法序列是，对于一个序列S，最后一个元素是x （也就是根），如果去掉最后一个元素的序列为T，
// 那么T满足：T可以分成两段，前一段（左子树）小于x，后一段（右子树）大于x，且这两段（子树）都是合法的后序序列。
// 完美的递归定义 : ) 。
class Solution {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
    	if(!sequence.size()){
    		return false;
		}
		return judge(sequence,0,sequence.size()-1);

    }
private:
	bool judge(vector<int> a,int l,int r){
		if(l>=r){
			return true;
		}
		int i=0;
		for(;i<r;i++){
			if(a[i]>a[r]){
				break;
			}
		}
		int k = i-1;
		for(;i<r;i++){
			if(a[i]<=a[r]){
				return false;
			}
		}
		return judge(a,l,k) && judge(a,k+1,r-1);
	}
};
int main(){
	int a[] = {2,4,3,6,8,7,5};
	vector<int> sq(a,a+7);
	cout<<Solution().VerifySquenceOfBST(sq);
	return 0;
}
