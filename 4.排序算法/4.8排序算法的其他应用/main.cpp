#include <iostream>
#include <cstdlib>
#include <cstring>
#include <ctime>

#define SIZE 40

using namespace std;

void PrintData(int* a,int len){
    for(int i = 0;i<len;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

// 反序排序(插入排序算法)
void InsertionSort(int* a,int len){
    int temp,i,j;
    for(i = 1;i<len;i++){
        temp = a[i];
        j = i - 1;
        while(j>=0 && a[j]<temp){
            a[j+1] = a[j];
            j--;
        }
        a[j+1] = temp;
    }
}

// 字符排序(快速排序算法)
void QuickSort(char* data,int left,int right){
    int temp,l,r,t;
    l = left;
    r = right;
    temp = data[(left+right)/2];
    while(l<r){
        while(temp>data[l]){
            l++;
        }
        while(temp<data[r]){
            r--;
        }
        if(l<=r){
            t = data[l];
            data[l] = data[r];
            data[r] = t;
            l++;
            r--;  
        }
        if(l == r){
            l++;
        }
        if(left<r){
            QuickSort(data,left,r);
        }
        if(l<right){
            QuickSort(data,l,right);
        }
    }
}

// 对字符串数组进行排序(使用快速排序算法)
void QuickSortCharArray(char* a[],int left,int right){
    int l,r;
    char *f,*t;
    l = left;
    r = right;
    f = a[(left+right)/2];
    while(l<r){
        while(strcmp(a[l],f)<0 && l<right){
            l++;
        }
        while(strcmp(a[r],f)>0 && r>left){
            r--;
        }
        if(l<=r){
            t = a[l];
            a[l] = a[r];
            a[r] = t;
            l++;
            r--;
        }
        if(l == r){
            l++;
        } 
        if(left<r){
            QuickSortCharArray(a,left,r);
        }
        if(l<right){
            QuickSortCharArray(a,l,right);
        }
    }    
}

int main(){
    // int a[SIZE];
    // srand(time(NULL));
    // for(int i = 0;i<SIZE;i++){
    //     a[i] = rand()%100+1;
    // }
    // cout<<"排序之前:"<<endl;
    // PrintData(a,SIZE);
    // InsertionSort(a,SIZE);

    // cout<<"排序后:"<<endl;
    // PrintData(a,SIZE);

    // char str[SIZE];
    // cout<<"输入一组字符串:";
    // cin>>str;
    // cout<<"排序前:"<<str<<endl;
    // QuickSort(str,0,strlen(str)-1);
    // cout<<"排序后:"<<str<<endl;

    char* arr[5] = {"will","never","give","up","njust"};
    cout<<"排序前:"<<endl;
    for(int i = 0;i<5;i++){
        cout<<arr[i]<<" ";
    } 
    cout<<endl;
     QuickSortCharArray(arr,0,4);
    cout<<"排序后:"<<endl;
     for(int i = 0;i<5;i++){
        cout<<arr[i]<<" ";
    } 
    cout<<endl;
    
    return 0;
}