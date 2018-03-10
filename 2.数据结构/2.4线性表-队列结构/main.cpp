#include <iostream>
#include <cstdlib>
#include <cstring>

#define QUEUELEN 15

using namespace std;

// 定义队列的数据结构
typedef struct{
    char name[10];
    int age;
}DATA;
typedef struct{
    DATA data[QUEUELEN];
    int head;
    int tail;
}SQType;

// 初始化队列
SQType* SQTypeInit(){
    SQType* q;
    if(q=(SQType*)malloc(sizeof(SQType))){
        q->head = 0;
        q->tail = 0;
        return q;
    }
    return NULL;
}

// 判断空队列
int SQTypeIsEmpty(SQType* q){
    int temp;
    temp = q->head == q->tail;
    return temp;
}

// 判断满队列
int SQTypeIsFull(SQType* q){
    int temp;
    temp = q->tail == QUEUELEN;
    return temp;
}

// 清空队列
void SQTypeClear(SQType* q){
    q->head = 0;
    q->tail = 0;    
}

// 释放空间
void SQTypeFree(SQType* q){
    if(q!=NULL){
        free(q);
    }
}

// 入队列
int InSQType(SQType* q,DATA data){
    if(q->tail==QUEUELEN){
        cout<<"队列已满，操作失败"<<endl;
        return 0;
    }
    q->data[q->tail++] = data;
    return 1;
}

// 出队列
DATA* OutSQType(SQType* q){
    if(q->head==q->tail){
        cout<<"全部出列"<<endl;
        exit(0);
    }
    return &(q->data[q->head++]);
}

// 读取结点的数据
DATA* PeekSQType(SQType* q){
    if(SQTypeIsEmpty(q)){
        cout<<"空队列!"<<endl;
        return NULL;
    }
    return &(q->data[q->head]);
}

// 计算队列长度
int SQTypeLen(SQType* q){
    int temp;
    temp = q->tail-q->head;
    return temp;
}

// 队列操作测试
int main(){
    SQType* stack;
    DATA data;
    DATA* data1;

    stack = SQTypeInit();
    cout<<"如队列操作!"<<endl;
    cout<<"输入（姓名 年龄）进行入队操作"<<endl;
    do{
        cin>>data.name>>data.age;
        if(strcmp(data.name,"0")==0){
            break;
        }
        InSQType(stack,data);
    }while(1);

    do{
        cout<<"出队列操作，按任意键出队列"<<endl;
        getchar();
        data1 = OutSQType(stack);
        cout<<"出队列："<<"("<<(data1->name)<<","<<(data1->age)<<")"<<endl;
    }while(1); 

    SQTypeClear(stack);
    return 0;
}