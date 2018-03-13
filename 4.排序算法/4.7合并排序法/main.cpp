#include <iostream>
#include <cstdlib>
#include <ctime>

#define SIZE 10

using namespace std;

// 这里需要重点强调一下合并排序算法的思想，以及是怎么实现的
// 代码量比较大需要作出一些说明.
// 总的来说，归并排序的精髓也简单，就是两两结合,直到合并成长度为数组长度的一个大组,排序即完成.

// 1.将原始数组看成长度为1的有序子表
// 2.把数组按照2个元素为1组合并(谁小谁在前)，剩下的不不变
// 3.把长度为2的有序表再次进行两两合并(谁小谁在前),合并成长度为4的组,剩下不变
// 4.....重复上述的步骤知道合并成一个len的大组，排序也就完成了.

// 重点!!!两个被切割的小组如A，B，他们是怎么进行归并然后排序的呢?（假设他们的长度均为len）
// 是这样的：
// 牺牲一个长度为2*len长度的空间C
// 同时遍历A和B，比较A和B中的元素,谁小谁先入队C
// 到最后一定A或者B中有多余的，剩下多的直接入队，这样小队C就是一个有序的序列，
// 可以继续和别的组合并啦,并且是同样的方法哟，就是这么简单!!

// 输出结果
void PrintData(int a[],int len){
    for(int i = 0;i<len;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
} 


// 将数组a(长度为len，并且已知数组b长度也为len)
// 以len长度划分为不同的子区间,然后按照两两之间合并成2*len长度的大的子区间，结果保存到数组b之中
void MergeOne(int a[],int b[],int n,int len){
    int s=0,e=0;// s=0开始，在a中:被看成这样的两个分组，进行合并:A[s,s+len-1],B[s+len,e]，最终结果汇集到b中
    int k=0,i=0,j=0;// k为b的索引为了与a保持同步，而i和j依次代表第一个组合第二个组的下标.
    while(s+len<n){
        e = s+2*len-1; // 第二个组的最后一个index
        if(e>=n){// 最后一段可能少于len个点
            e = n-1;
        }
        // 相邻合并
        k = s;
        i = s;
        j = s+len;
        while(i<=s+len-1 && j<=e){// 保证小组A和小组B都没有越界
            if(a[i]<=a[j]){// 小组A：a[i],小组B：a[j] --->谁小谁先插入到结果集b中
                b[k++] = a[i++];
            }else{
                b[k++] = a[j++];
            }            
        }
        while(i<=s+len-1){// 如果小组A还有剩余元素，直接插入结果集b
            b[k++] = a[i++];
        }
         while(j<=e){// 如果小组B还有剩余元素，直接插入结果集b
            b[k++] = a[j++];
        }
        s = e+1;   // 这里是继续下两个小组了，因为前面一个最后为e,下两个小组第一个下标应该为e+1，重复上述步骤
    }
    if(s<n){// 其余元素依次并入结果集b中
        for(;s<n;s++){
            b[k++] = a[s];
        }
    } 
}

// 归并排序
void MergeSort(int a[],int n){
    int* p;// 辅助内存空间
    int f = 0,len = 1,count = 0;
    if(!(p=(int*)malloc(sizeof(int)*n))){
        cout<<"内存分配失败!"<<endl;
        exit(0);
    }
    while(len<n){
        if(f==1){
            MergeOne(p,a,n,len);// p-->a
        }else{
            MergeOne(a,p,n,len);// a-->p
        }
        len=len*2;// len翻倍增长，因为两两合并呀
        f = 1-f;// 这里就是一个编程的小技巧了，因为合并是需要内存空间了这样a，p可以互为辅助内存
    }
    if(f){// 看看f是否为1，等于1时表示a--p,此时结果存放在p中，我们把结果放到a中
        for(int i = 0;i<len;i++){
            a[i] = p[i];
        }
    }
    free(p);
}

int main(){
    int data[SIZE];
    srand(time(NULL));
    for(int i = 0;i<SIZE;i++){
        data[i] = rand()%100+1;
    }
    cout<<"排序前:"<<endl;
    PrintData(data,SIZE);
    MergeSort(data,SIZE);
    cout<<"排序后:"<<endl;
    PrintData(data,SIZE);

    system("pause");
    return 0;
}