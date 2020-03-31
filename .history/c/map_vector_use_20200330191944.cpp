#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
#include<windows.h>
#include<time.h>
#include<typeinfo>
using namespace std;
////////vector_use
void vector_use(){
    //利用数组初始化
    int a[] ={1,2,3,4,5,4,6,4};
    vector<int> vec(a,a+8);
    vector<int> v1 = {1,2,3,4,5,6,7};  
    vector<int> v2(3, 0); //创建一个容量为3，全部初始化0
    vector<int> v3(5);  //创建容量为5，数据类型为int的vector
    vector<int> v4(v3);  //创建一个从v3拷贝过来的vector

    //直接遍历
    for(int i=0;i<vec.size();i++){
        cout<<vec[i];
    }
    cout<<endl;
    // 迭代器遍历
    for(vector<int>::iterator it=vec.begin();it!=vec.end();it++){
        cout<<*it;
    }
    cout<<endl;
    // 增加元素
    vec.push_back(7);
    vec.insert(vec.begin()+2,100); //在第二个位置插入
    //查看元素
    cout<<*(vec.begin()+2)<<endl;
    cout<<vec[2]<<endl;

    //修改元素
    *(vec.begin() +2) =101;
    cout<<vec[2]<<endl;
    // 查找
    vector<int>::iterator it = find(vec.begin(),vec.end(),4);
    if(it!=vec.end()){
        cout<<"find it";
    }
    //找到后删除
    if(it!=vec.end()){
        vec.erase(it);
    }

    //多个都要删除
   for(vector<int>::iterator it=vec.begin();it!=vec.end();){ //注意这个，因为it如果被删除则不能用++找下一个，所以it的更新在循环里
       if(*it==4){
           it = vec.erase(it); //如果被删除，则erase返回的就是下个元素的指针
       }else{
           it++; //没被删除，则直接++
       }
    }

}
void map_use(){
    map<string,int> mm;
    // 插入
    mm.insert(pair<string,int>("a",1));
    mm.insert(pair<string,int>("b",2));
    // 迭代器遍历
    for(map<string,int>::iterator it=mm.begin();it!=mm.end();it++){
        cout<<it->first<<":"<<it->second<<"  ";
    }
    // for each遍历
    for(auto &it:mm){
        cout<<it.first<<":"<<it.second<<"  ";
    }
    cout<<endl;
    //查看元素 不存在则返回0
    cout<<"a:"<<mm["a"];
    //遍历
    for( map<string,int>::iterator it =mm.begin();it!=mm.end();it++){
         cout<<it->first<<":"<<it->second<<"  ";
    }

    //取出
    map<string,int>::iterator it = mm.find("b");
    if(it!=mm.end()){
        cout<<"found it  "<<it->first<<":"<<it->second<<endl;
    }
    //修改元素
    mm["a"] = 101;
    //查找元素并删除
   
    if(it!=mm.end()){
        cout<<"found it";
    }



}

int main(){
    // vector_use();
    map_use();
    return 0;
}