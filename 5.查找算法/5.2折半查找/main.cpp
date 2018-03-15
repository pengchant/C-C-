#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cstring>

#define SIZE 10

using namespace std;

// 快速排序算法
void QuickSort(int a[],int left,int right){
    int l = left;
    int r = right;
    int t = 0 ;
    int middle = a[(left+right)/2];
    while(l<r){
        while(a[l]<middle){
            l++;        
        }
        while(a[r]>middle){
            r--;
        }
        if(l<=r){
            t = a[l];
            a[l] = a[r];
            a[r] = t;
            l++;
            r--;
        }
    }
    if(l == r){
        l++;
    }
    if(l<right){
        QuickSort(a,l,right);
    }
    if(r>left){
        QuickSort(a,left,r);
    }

}

// 二分查找算法(请注意二分查找法的条件为必须为有序)
int MiddleSearch(int a[],int n,int x){
    int low = 0;
    int high = n-1;
    int middle,f = -1;
    while(low<=high){
        middle = (low+high)/2;
        if(x<a[middle]){
            high = middle - 1; 
        }else if(x>a[middle]){
            low = middle + 1;
        }else{
           return middle;
        }        
    }
    return -1;
}
 
int main(){
    int a[SIZE],x,n;
    srand(time(NULL));
    for(int i = 0;i<SIZE;i++){
        a[i] = rand()%100+1;
    }
    cout<<"原始序列"<<endl;
    QuickSort(a,0,SIZE-1);
    for(int i = 0;i<SIZE;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;

    cout<<"输入要查找的数据:";
    cin>>x;
    n = MiddleSearch(a,SIZE,x);
    if(n<0){
        cout<<"没有查找到数据"<<endl;
    }else{
        cout<<"查找到数据的索引为:"<<(n+1)<<endl;
    }
    system("pause");
    return 0; 
}