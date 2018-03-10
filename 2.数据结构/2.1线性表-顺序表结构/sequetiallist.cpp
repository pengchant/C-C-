#include <iostream>
#include <cstdlib> 
#include <cstring> 
#define MAXLENGTH 100 

using namespace std;

// 定义顺序表的结点
typedef struct{
    char key[10];
    char name[50];
    int age;
}DATA;
// 定义顺序表
typedef struct{
    DATA ListData[MAXLENGTH+1];
    int ListLen;
}SLType;

// 初始化顺序表
void SLInit(SLType *SL){
    SL->ListLen = 0;
}

// 计算顺序表的长度
int SLLength(SLType *SL){
    return (SL->ListLen);
}

// 插入结点
int SLInsert(SLType* SL,int n,DATA data){
    int i;
    if(SL->ListLen>=MAXLENGTH){                
        cout<<"顺序表已满，不能插入结点!"<<endl;
        return 0;
    }
    if(n<1 || n>SL->ListLen-1){
        cout<<"插入的序号错误，不能插入结点!"<<endl;
    }
    for(i = SL->ListLen;i>=n;i--){
        SL->ListData[i+1] = SL->ListData[i];
    }
    SL->ListData[n] = data;
    SL->ListLen++;
    return 1;
}

// 追加结点
int SLAdd(SLType* SL,DATA data){
    if(SL->ListLen>=MAXLENGTH){
        cout<<"顺序表已满，插入失败！"<<endl;
        return 0;
    }
    SL->ListData[++SL->ListLen] = data; 
    return 1;
}

// 删除结点
int SLDelete(SLType* SL,int n){
    int i;
    if(n<1 || n>SL->ListLen){
        cout<<"删除结点序号有误,不能删除结点!"<<endl;
        return 0;
    }
    for(i = n;i>=n;i--){
        SL->ListData[i] = SL->ListData[i+1];
    }
    SL->ListLen--;
    return 1;
}

// 查找结点(按照序号查找)
DATA* SLFindByNum(SLType* SL,int n){
    if(n<1 || n>SL->ListLen){
        cout<<"结点的序号有误，不能返回该结点!"<<endl;
        return NULL;
    }
    return &(SL->ListData[n]);
}

// 查找结点(按照关键字查找)
DATA* SLFindByCont(SLType* SL,char* key){
    int i;
    for(i = 1;i<=SL->ListLen;i++){
        cout<<SL->ListData[i].key<<strcmp(SL->ListData[i].key,key)<<endl;
        if(strcmp(SL->ListData[i].key,key)==0){
            return &(SL->ListData[i]);
        }
    } 
    return NULL;
}

// 显示所有结点
int SLAll(SLType* SL){
    int i;
    for(i = 1;i<=SL->ListLen;i++){
        cout<<"("<<SL->ListData[i].key<<","<<SL->ListData[i].name<<","<<SL->ListData[i].age<<")"<<endl;
    }
    return 0;
}


// 顺序表操作
int main(){
    int i;
    SLType SL;
    DATA data;
    DATA* pdata;
    char key[10];

    cout<<"顺序表操作"<<endl;
    SLInit(&SL);
    cout<<"顺序表初始完成"<<endl; 

    do{
        cout<<"输入添加的结点(学号 姓名 年龄):"<<endl; 
        cin>>data.key>>data.name>>data.age;
        if(data.age!=0){
            if(SLAdd(&SL,data)!=1){
                break;
            }
        }else{
            break;
        }
    }while(true);
    cout<<"顺序表中的结点的顺序为:"<<endl;
    SLAll(&SL);     

    cout<<"输入你要取出的结点的序号?";
    cin>>i;
    pdata = SLFindByNum(&SL,i);
    if(pdata){
        cout<<"第"<<i<<"个结点为:"<<pdata->key<<","<<pdata->name<<","<<pdata->age<<endl;
    } 

    cout<<"输入要查找结点的关键字:";
    cin>>key;
    pdata = SLFindByCont(&SL,key); 
    if(pdata){
        cout<<pdata->key<<","<<pdata->name<<","<<pdata->age<<endl;
    } 

    system("pause");
    return 0;
}
