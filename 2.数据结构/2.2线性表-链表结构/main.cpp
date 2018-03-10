#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

// 定义数据结构
typedef struct{
    char key[10];
    char name[20];
    int age;
}Data;
typedef struct Node{
    Data nodeData;
    struct Node* nextNode;
}CLType;

//追加结点
CLType* CLAddEnd(CLType* head,Data nodeData){
    CLType* node;
    CLType* htemp;
    if(!(node=(CLType*)malloc(sizeof(CLType)))){
        cout<<"申请内存失败!"<<endl;
        return NULL;
    }
    node->nodeData = nodeData;
    node->nextNode = NULL;
    if(head==NULL){
        head = node;
        return head;
    }
    htemp = head;
    while(htemp->nextNode!=NULL){
        htemp = htemp->nextNode;
    }
    htemp->nextNode = node;
    return head;
}

// 插入头结点
CLType* CLAddFirst(CLType* head,Data nodeData){
    CLType* node; 
    if(!(node=(CLType*)malloc(sizeof(CLType)))){
        cout<<"申请内存失败!"<<endl;
        return NULL;
    }
    node->nodeData = nodeData;
    node->nextNode = head;
    head = node;
    return head;
}

// 查找结点
CLType* CLFindNode(CLType* head,char* key){
    CLType* htemp;
    htemp = head;
    while(htemp){
        if(strcmp(htemp->nodeData.key,key)==0){
            return htemp;
        }
        htemp = htemp->nextNode;
    }
    return NULL;
}

// 插入结点
CLType* CLInsertNode(CLType* head,char* findkey,Data nodeData){
    CLType* node;
    CLType* nodetemp;
    if(!(node=(CLType*)malloc(sizeof(CLType)))){
        cout<<"申请内存失败!"<<endl;
        return NULL;
    }
    node->nodeData = nodeData;
    nodetemp = CLFindNode(head,findkey);
    if(nodetemp){
        node->nextNode = nodetemp->nextNode;
        nodetemp->nextNode = node;
    }else{
        cout<<"未找到正确的插入位置!"<<endl;
        free(node);
    }
    return head;
}

// 删除结点
int CLDeleteNode(CLType* head,char* key){
    CLType* node;
    CLType* htemp;
    htemp = head;
    node = head;
    while(htemp){
        if(strcmp(htemp->nodeData.key,key)==0){
            node->nextNode = htemp->nextNode;
            free(htemp);
            return 1;
        }else{
            node = htemp;
            htemp = htemp->nextNode;
        }
    }
    return 0;
}

//计算链表长度
int CLLength(CLType* head){
    CLType* htemp;
    int len = 0;
    htemp = head;
    while(htemp){
        len++;
        htemp = htemp->nextNode;
    }
    return len;
}

// 显示所有的结点
void CLAllNode(CLType* head){
    CLType* htemp;
    htemp = head;
    Data nodeData;
    while(htemp){
        nodeData = htemp->nodeData;
        cout<<"结点"<<nodeData.key<<","<<nodeData.name<<","<<nodeData.age<<endl;
        htemp = htemp->nextNode;
    }
}

// 链表操作
int main(){
    CLType* node;
    CLType* head = NULL;
    Data nodeData;
    char key[10];
    char findkey[10];

    cout<<"链表测试，输入链表中的数据(关键字 姓名 年龄),结束输入0退出"<<endl;
    do{
        cin>>nodeData.key;
        if(strcmp(nodeData.key,"0")==0){
            break;
        }else{
            cin>>nodeData.name>>nodeData.age;
            head = CLAddEnd(head,nodeData);
        }
    }while(true);
    CLAllNode(head);

    cout<<"演示插入结点，输入插入位置的关键字:"<<endl;
    cin>>findkey;
    cout<<"输入插入结点的(关键字 姓名 年龄):"<<endl;
    cin>>nodeData.key>>nodeData.name>>nodeData.age;
    head = CLInsertNode(head,findkey,nodeData);
    CLAllNode(head);

    cout<<"演示删除结点，输入要删除的关键字："<<endl;
    cin>>key;
    CLDeleteNode(head,key);
    CLAllNode(head);

    cout<<"演示在链表中查找，输入要查询的关键字"<<endl;
    cin>>key;
    node = CLFindNode(head,key);
    if(node){
        nodeData = node->nodeData;
        cout<<"对应的结点为："<<nodeData.key<<","<<nodeData.name<<","<<nodeData.age<<endl;        
    }else{
        cout<<"在链表中未找到关键字为"<<key<<"的结点"<<endl;
    }

    return 0;
}