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

void ShellSort(int* a,int len){
    int temp,j;
    for(int r = len/2;r>=1;r/=2){
        for(int i = r;i<len;i++){
            temp = a[i];
            j = i-r;
            while(j>=0 && temp<a[j]){
                a[j+r] = a[j];
                j-=r;
            }
            a[j+r] = temp;
        }
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
    
    ShellSort(data,SIZE);

    cout<<"排序之后的数据为:"<<endl;
    PrintData(data,SIZE);
    system("pause");
    return 0;
}