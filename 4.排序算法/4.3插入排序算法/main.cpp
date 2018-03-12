#include <iostream>
#include <ctime>

#define SIZE 10

using namespace std;

void PrintData(int* a,int len);
void InsertionSort(int* a,int len);

// 插入排序算法
void InsertionSort(int* a,int len){
    int temp,j;
    for(int i = 1;i<len;i++){
        temp = a[i];
        j = i-1;
        while(j>=0 && temp<a[j]){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;        
        cout<<"第"<<(i)<<"步排序的结果为：";
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
    
    InsertionSort(data,SIZE);

    cout<<"排序之后的数据为:"<<endl;
    PrintData(data,SIZE);
    system("pause");
    return 0;
}