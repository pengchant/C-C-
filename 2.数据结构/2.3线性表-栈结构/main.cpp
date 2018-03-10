#include <iostream>
#include <cstring>
#include <cstdlib>

#define MAXLEN 50

using namespace std;

// 定义栈的数据结构
typedef struct{
    char name[10];
    int age;
}DATA;
typedef struct stack{
    DATA data[MAXLEN+1];
    int top;
}StackType;

// 初始化栈
StackType* STInit(){
    StackType* p;
    if(p = (StackType*)malloc(sizeof(StackType))){
        p->top = 0;
        return p;
    }
    return NULL;
}

// 判断空栈
int STIsEmpty(StackType* s){
    if(s&&s->top!=0){
        return 0;
    }
    return 1;
}

// 判断满栈
int STIsFull(StackType* s){
    if(s&&s->top==MAXLEN){
        return 1;
    }
    return 0;
}

// 清空栈
void STClear(StackType* s){
    s->top = 0;
}

// 释放空间
void STFree(StackType* s){
    if(s){
        free(s);
    }
}

// 入栈
int PushST(StackType* s,DATA data){
    if((s->top+1)>MAXLEN){
        cout<<"栈溢出!"<<endl;
        return 0;
    }
    s->data[++s->top] = data;
    return 1;
}

// 出栈
DATA PopST(StackType* s){
    if(STIsEmpty(s)){
        cout<<"栈为空"<<endl;
        exit(0);
    }
    return (s->data[s->top--]);
}

// 读取结点数据
DATA PeekST(StackType* s){
    if(STIsEmpty(s)){
        cout<<"栈为空"<<endl;
        exit(0);
    }
    return (s->data[s->top]);
}

// 栈结构操作实例
int main(){
    StackType* stack;
    DATA data,data1;
    stack = STInit();

    cout<<"入栈操作"<<endl;
    cout<<"输入姓名 年龄进入栈操作"<<endl;
    do{
        cin>>data.name>>data.age;
        if(strcmp(data.name,"0")==0){
            break;
        }
        PushST(stack,data);
    }while(1);

    do{
        cout<<"出栈操作"<<endl;
        getchar();
        data1 = PopST(stack);
        cout<<"出栈的数据是:"<<data1.name<<data1.age<<endl;
    }while(1);  

    STFree(stack);

    getchar();
    return 0;
}

 
