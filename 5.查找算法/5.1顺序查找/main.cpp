#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define SIZE 20

using namespace std;

// 顺序查找算法
int SearchFun(int a[],int n,int x){
    int i,f = -1;
    for(i = 0;i<n;i++){
        if(a[i] == x){
            f = i;
            break;
        }
    }
    return f;
}

int main(){
    int a[SIZE],x,n;
    srand(time(NULL));
    for(int i = 0;i<SIZE;i++){
        a[i] = rand()%100+1;
    }
    cout<<"原始序列"<<endl;
    for(int i = 0;i<SIZE;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
    cout<<"输入要查找的数据:";
    cin>>x;
    n = SearchFun(a,SIZE,x);
    if(n<0){
        cout<<"没有查找到数据"<<endl;
    }else{
        cout<<"查找到数据的索引为:"<<(n+1)<<endl;
    }
    system("pause");
    return 0;
}