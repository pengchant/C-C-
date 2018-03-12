#include <iostream>
#include <cstdlib>
#include <ctime>

#define SIZE 10

using namespace std;

void PrintData(int* a,int len){
    for(int i = 0;i<len;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

// 快速排序
void QuickSort(int* a,int left,int right){
    int f,t;  
    int ltemp,rtemp;
    ltemp = left;
    rtemp = right;
    f = a[(left+right)/2];
    while(ltemp<rtemp){
        while(a[ltemp]<f){
            ++ltemp;
        }
        while(a[rtemp]>f){
            rtemp--;
        }
        if(ltemp<=rtemp){
            t = a[ltemp];
            a[ltemp] = a[rtemp];
            a[rtemp] = t;
            --rtemp;
            ++ltemp;
        }
    }
    if(ltemp==rtemp){
        ltemp++;    
    }

    if(left<rtemp){
        QuickSort(a,left,ltemp-1);
    }
    if(ltemp<right){
        QuickSort(a,rtemp+1,right);
    }
}

int main(){
    int data[SIZE];
    srand(time(NULL));
    for(int i = 0;i<SIZE;i++){
        data[i] = rand()%100+1;
    }
    cout<<"排序前的数据:"<<endl;
    PrintData(data,SIZE);
    
    QuickSort(data,0,SIZE-1);

    cout<<"排序之后的数据为:"<<endl;
    PrintData(data,SIZE);
    system("pause");
    return 0;
}