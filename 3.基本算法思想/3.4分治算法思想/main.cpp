#include <iostream>

#define MAXNUM 30

using namespace std;

// 利用分治算法找假币：目前有三十个钱币，但是其中有一个是假币，但是肉眼很难分别，目前只知道假币比真币轻
int FalseCoin(int coin[],int low ,int high){
    int i,sum1,sum2,sum3;
    int re;
    sum1 = sum2 = sum3 = 0;
    if(low+1 == high){// 如果找到最后的两个硬币的情况，那边轻那边就是假的
        if(coin[low]<coin[high]){
            re = low+1; 
        }else{
            re = high+1; 
        }
        return re;
    }
    if((high-low+1)%2==0){// 如果分下来是偶数个
        for(i = low;i<=low+(high-low)/2;i++){// 计算前半部分
            sum1 += coin[i];
        }
        for(i = low+(high-low)/2+1;i<=high;i++){// 计算后半部分
            sum2 += coin[i];
        }
        if(sum1>sum2){// 继续从后半部分开始分
            re = FalseCoin(coin,low+(high-low)/2+1,high); 
            return re;
        }else if(sum1<sum2){// 继续从前半部分开始分
            re = FalseCoin(coin,low,low+(high-low)/2);
            return re;
        } 
    }else{// 如果分下来是奇数个
        for(i = low;i<=low+(high-low)/2-1;i++){// 前半部分
            sum1 += coin[i];
        }
        for(i = low+(high-low)/2+1;i<=high;i++){// 后半部分
            sum2 += coin[i];
        }
        sum3 = coin[low+(high-low)/2];// 中间独苗
        if(sum1<sum2){// 继续从前半部分开始分
            re = FalseCoin(coin,low,low+(high-low)/2-1);
            return re;
        }else if(sum1>sum2){// 继续从后半部分开始分
            re = FalseCoin(coin,low+(high-low)/2+1,high);
            return re;
        }else{
            re = low+(high-low)/2+1;
            return re;
        } 
    }

}

int main(){
    int coin[MAXNUM];
    int i,n;
    int weizhi;
    cout<<"分治算法求解假币问题!"<<endl;
    cout<<"输入银币的总数:";
    cin>>n;
    cout<<"请输入银币的真假:";
    for(i = 0;i<n;i++){
        cin>>coin[i];
    }
    weizhi = FalseCoin(coin,0,n-1);
    cout<<"在上述"<<n<<"个银币中第"<<weizhi<<"个是假的"<<endl;
    return 0;    
}