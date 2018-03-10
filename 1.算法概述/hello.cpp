#include <iostream>
#include <ctime>
#include <cstdlib>

#define N 20
using namespace std;

int main(){
    int arr[N];
    int x = 0;
    int flag = -1;

    srand(time(NULL));
    for(int i = 0;i<N;i++){
        arr[i] = rand()%100+1;
    }
    cout<<"输入要查找的整数:"<<endl;
    cin>>x;
    for(int i = 0;i<N;i++){
        if(x == arr[i]){
            flag = i;
            break;
        }
    }
    cout<<"随机生成的序列为:"<<endl;
    for(int i = 0;i<N;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    if(flag<0){
        cout<<"抱歉没有找到该数据"<<x<<endl;
    }else{
        cout<<"数据:"<<x<<"在数组的第"<<(flag+1)<<"个位置上"<<endl;
    }
    system("pause");
    return 0;
}