#include<iostream>
#include<vector>
using namespace std;

//���ӣ�https://www.nowcoder.com/questionTerminal/a861533d45854474ac791d90e447bafd?f=discussion
// ��Դ��ţ����

// BST�ĺ������еĺϷ������ǣ�����һ������S�����һ��Ԫ����x ��Ҳ���Ǹ��������ȥ�����һ��Ԫ�ص�����ΪT��
// ��ôT���㣺T���Էֳ����Σ�ǰһ�Σ���������С��x����һ�Σ�������������x���������Σ����������ǺϷ��ĺ������С�
// �����ĵݹ鶨�� : ) ��
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
