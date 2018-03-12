#include <iostream>
#include <cstdlib>
#include <ctime>

#define SIZE 10

using namespace std;

void PrintData(int* a,int len);
void BubbleSort(int* a,int len);

// 冒泡法排序(交换排序)
void BubbleSort(int* a,int len){
    int flag,temp;
    for(int i = 0;i<len-1;i++){ 
        flag = 0;
        for(int j = len-1;j>i;j--){
            if(a[j]<a[j-1]){
                temp = a[j];
                a[j] = a[j-1];
                a[j-1] = temp;
                flag = 1;
            }
        }
        cout<<"第"<<(i+1)<<"趟排序的结果：";
        PrintData(a,len);
        if(!flag){
            return;
        }
    }
}

void PrintData(int* a,int len){
    for(int i = 0;i<len;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

int main(){
    int data[SIZE];
    cout<<"使用冒泡排序法排序："<<endl;
    srand(time(NULL));
    for(int i = 0;i<SIZE;i++){
        data[i] = rand()%100+1;        
    }

    cout<<"排序之前的数组:"<<endl;
    PrintData(data,SIZE);

    BubbleSort(data,SIZE);
    cout<<"排序之后的数组:"<<endl;
    PrintData(data,SIZE);
    return 0;
}