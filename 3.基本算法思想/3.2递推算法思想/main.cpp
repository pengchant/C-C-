#include <iostream>
#include <cstdlib>

using namespace std;

// 斐波那契数列 Fn = F(n-2) + F(n-1)
int Fibonacci(int n){
    int t1,t2;
    if(n == 1 || n == 2){
        return 1;
    }
    t1 = Fibonacci(n-1);
    t2 = Fibonacci(n-2);
    return t1+t2;
}

int main(){
    int n,num;
    cout<<"使用递推算法求解斐波那契数列问题"<<endl;
    cout<<"请输入时间(月份)";
    cin>>n;
    num = Fibonacci(n);
    cout<<"经过"<<n<<"月的时间,共繁殖"<<num<<"对兔子"<<endl;
    return 0;
}