#include <iostream>
#include <cstdlib>
#include <ctime>

#define SIZE 10

using namespace std;

// 显示数据
void PrintData(int* a,int len){
    for(int i = 0;i<len;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

// 堆排序，通过大根堆根结点最大的原则，依次构造堆然后输出结果
void HeapSort(int a[],int n){
    int temp,j,k;
    // 将a[0][n-1]构造成大根堆
    for(int i = n/2-1;i>=0;i--){    // 从非叶子结点开始构造大根堆
        while(2*i+1<n){             // ★★★★★ 如果第i个结点存在子节点,know that 2*i+1 is leftnode's index
            j = 2*i+1;              // leftnode's index
            if(j+1<n){              // 如果存在右子树，max(leftnode,rightnode)
                if(a[j]<a[j+1]){
                    j++;            // j->current,must be understand j is need to be compared variable
                }
            }
            if(a[j]>a[i]){          // compare currentnode and parentnode,exchange
                temp = a[j];
                a[j] = a[i];
                a[i] = temp;
                i = j;              // ★★★★★ 堆被破坏,其子树需要继续构造堆，满足堆的定义
            }else{
                break;              // 满足大根堆的条件
            }
        }
    }
    // 输出构成的堆
    cout<<"原始数据构成的堆:"<<endl;
    PrintData(a,n);

    for(int i = n-1;i>0;i--){       // 从a[1,n-1]重新开始构造大根堆
        temp = a[0];            
        a[0] = a[i];
        a[i] = temp;                //  a[i]<-->a[0] 

        k = 0;                      // 从根结点依次向下进行判别
        while(2*k+1<i){             // 如果存在左子节点(★★★从0到i★★★,i到n-1已经排好顺序)
            j = 2*k+1;              
            if((j+1)<i){            // 如果存在右子节点(去除第i个结点)
                if(a[j]<a[j+1]){
                    j++;            // j指向较大的结点
                }
            }
            if(a[k]<a[j]){          // 如果当前节点与子节点比较不满足大根堆条件则exchange
                temp = a[k];
                a[k] = a[j];
                a[j] = temp;
                k = j;              // k则被赋值为j的较大的结点个一个
            }else{                  // 如果满足大根堆的条件直接退while继续寻找下一个较大的结点
                break;
            }
        }
        cout<<"第"<<(n-i)<<"趟排序的结果：";
        PrintData(a,n);
    }
}



int main(){
    int data[SIZE];
    srand(time(NULL));
    for(int i = 0;i<SIZE;i++){
        data[i] = rand()%100+1;
    }
    cout<<"排序前："<<endl;
    PrintData(data,SIZE);

    HeapSort(data,SIZE);

    cout<<"排序后："<<endl;
    PrintData(data,SIZE);
    system("pause");
    return 0;
}

