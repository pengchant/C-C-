#include <iostream>
#include <cstdlib>
#include <cstring>
#include <iomanip>

#define MaxNum 20
#define MaxValue 65535

using namespace std;

// 定义图的数据结构
typedef struct{
    char Vertex[MaxNum];               // 保存顶点的数据
    int GType;                          // 图的类型0:无向图,1:有向图
    int VertexNum;                      // 顶点的数量    
    int EdgeNum;                        // 边的数量
    int EdgeWeight[MaxNum][MaxNum];     // 保存边的权
    int isTrav[MaxNum];                 // 遍历标志
}GraphMatrix;

// 创建图
void CreateGraph(GraphMatrix* GM){
    int i,j,k;
    int weight;
    char EstartV,EendV;

    cout<<"输入图中各顶点的信息"<<endl;
    for(i = 0;i<GM->VertexNum;i++){
        getchar();
        cout<<"第"<<(i+1)<<"个顶点:";
        cin>>GM->Vertex[i];
    }
    cout<<"输入构成各边的顶点及权值:"<<endl;
    for(k = 0;k<GM->EdgeNum;k++){
        getchar();
        cout<<"第"<<(k+1)<<"条边:";
        cin>>EstartV>>EendV>>weight;
        for(i = 0;EstartV!=GM->Vertex[i];i++);
        for(j = 0;EendV!=GM->Vertex[j];j++);
        GM->EdgeWeight[i][j]=weight;
        if(GM->GType == 0){
            GM->EdgeWeight[j][i] = weight;
        }
    }
}

// 清空图
void ClearGraph(GraphMatrix* GM){
    int i,j;
    for(i = 0;i<GM->VertexNum;i++){
        for(j = 0;j<GM->VertexNum;j++){
            GM->EdgeWeight[i][j] = MaxValue;
        }
    }
}

// 显示图
void OutGraph(GraphMatrix* GM){
    int i,j;
    for(j = 0;j<GM->VertexNum;j++){
        cout<<"\t"<<GM->Vertex[j];
    }
    cout<<endl;
    for(i = 0;i<GM->VertexNum;i++){
        cout<<GM->Vertex[i];
        for(j = 0;j<GM->VertexNum;j++){
            if(GM->EdgeWeight[i][j]==MaxValue){
                cout<<"\t*";
            }else{
                cout<<"\t"<<GM->EdgeWeight[i][j];
            }            
        }
        cout<<endl;
    }    
}

// 遍历图(递归算法)深度优先遍历
void DeepTraOne(GraphMatrix* GM,int n){
    int i;
    GM->isTrav[n] = 1;
    cout<<"->"<<GM->Vertex[n]<<" ";
    for(i = 0;i<GM->VertexNum;i++){
        if(GM->EdgeWeight[n][i]!=MaxValue && !GM->isTrav[i]){
            DeepTraOne(GM,i);
        }
    }
}

void DeepTraGraph(GraphMatrix* GM){
    int i;
    for(i = 0;i<GM->VertexNum;i++){
        GM->isTrav[i] = 0;
    }
    cout<<"深度优先遍历结点:"<<endl;
    for(i = 0;i<GM->VertexNum;i++){
        if(!GM->isTrav[i]){
            DeepTraOne(GM,i);
        }
    }
    cout<<endl;
}

// 图的操作实例
int main(){
    GraphMatrix GM;
    cout<<"输入生成图的类型:";
    cin>>GM.GType;
    cout<<"输入顶点的数量:";
    cin>>GM.VertexNum;
    cout<<"输入图边的数量:";
    cin>>GM.EdgeNum;
    ClearGraph(&GM);
    CreateGraph(&GM);
    cout<<"该图的邻接矩阵如下:"<<endl;
    OutGraph(&GM);
    DeepTraGraph(&GM);
    system("pause");
    return 0;
}