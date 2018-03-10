#include <iostream>
#include <ctime>
#include <cstdlib>


using namespace std;

// 利用概率算法计算圆周率
// 通常概率算法的思想为转化为几何图形，均匀撒点，统计，得出结构，精度不够多重复上述步骤
// 概率算法的形式：1.数值概率算法;2.蒙特卡罗算法;3.拉斯维加斯算法;4.舍伍德算法
double MontePI(int n){
    double PI;
    double x,y;
    int i,sum;
    
    sum = 0;
    srand(time(NULL));
    for(i = 1;i<n;i++){
        x = (double)rand()/RAND_MAX;
        y = (double)rand()/RAND_MAX;
        if((x*x+y*y)<=1){
            sum++;
        }        
    }
    PI = 4.0*sum/n;
    return PI;
}

int main(){
    int n;
    double PI;
    cout<<"蒙特卡罗概率算法计算π:"<<endl;
    cout<<"输入点的数量:";
    cin>>n;
    cout<<"π约等于"<<MontePI(n)<<endl;
    return 0;
}