#include <iostream>

using namespace std;

// 使用递归算法实现阶乘n!=n*(n-1)*...2*1
long fact(int n){
    if(n<=1){
        return 1;
    }
    return n*fact(n-1);
}

int main(){
    int i;
    cout<<"利用递归算法计算阶乘"<<endl;
    cout<<"输入一个叫计算阶乘的整数:";
    cin>>i;
    cout<<i<<"!="<<fact(i)<<endl;
    return 0;
}