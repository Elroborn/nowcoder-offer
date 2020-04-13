#include <iostream>
#include<string>
using namespace std;
//cpp 可以面向过程也可以面向对象
string function(string str){
    string s = "";
    return str;
}
class Main
{
public:
    string function(string str){
        return str;
    }
};
int main() {
    string a,b; // int a,b;
    while(cin >> a >> b)//注意while处理多个case
        // cout << function(a) << endl;
        cout << Main().function(a) << endl;
}