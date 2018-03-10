#include <iostream>
#include <cstdlib>

using namespace std;

// 穷举法求鸡兔同笼问题：今有鸡兔同笼，上有三十五头，下有九十四足，问鸡兔各几何？
int qiongjvjt(int head,int foot,int* chicken,int* rabbit){
    int re,i,j;
    for(i = 0;i<head;i++){
        j = head - i;
        if(2*i+j*4==foot){
           re = 1;
           *chicken = i;
           *rabbit = j; 
        }
    }
    return re;
}

int main(){
    int head,foot,ck,rbt;
    int re;
    cout<<"鸡兔同笼问题,输入头数,脚数:";
    cin>>head>>foot;
    re = qiongjvjt(head,foot,&ck,&rbt);
    if(re){
        cout<<"计算结果为:鸡"<<ck<<"只"<<","<<"兔子"<<rbt<<"只";
    }else{
        cout<<"问题无解!"<<endl;
    }
    return 0;
}