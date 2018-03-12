#include <iostream>
#include <ctime>

#define SIZE 10

using namespace std;

void PrintData(int* a,int len);
void SelectSort(int* a,int len);

// 选择排序算法
void SelectSort(int* a,int len){
    int temp;
    for(int i = 0;i<len-1;i++){
        for(int j = i+1;j<len;j++){
            if(a[i]>a[j]){
                temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
        cout<<"第"<<(i+1)<<"步排序的结果：";
        PrintData(a,len);
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
    srand(time(NULL));
    for(int i = 0;i<SIZE;i++){
        data[i] = rand()%100+1;
    }
    cout<<"排序前的数据:"<<endl;
    PrintData(data,SIZE);
    cout<<"排序后的数据:"<<endl;
    SelectSort(data,SIZE);
    PrintData(data,SIZE);
    return 0;
}