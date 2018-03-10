#include <iostream>
#include <cstdlib>
#include <cstring>

#define MANLEN 20

using namespace std;

// 定义二叉树数据结构
typedef char DATA;
typedef struct CBT{
    DATA data;
    struct CBT* left;
    struct CBT* right;
}CBTType;

// 初始化二叉树
CBTType* InitTree(){
    CBTType* node;
    if(node=(CBTType*) malloc(sizeof(CBTType))){
        cout<<"请先输入一个根结点数据"<<endl;
        cin>>node->data;
        node->left = NULL;
        node->right = NULL;
        return node;
    }
    return NULL;
}

// 查询结点
CBTType* TreeFindNode(CBTType* treeNode,DATA data){
    CBTType* ptr;
    if(treeNode==NULL){
        return NULL;
    }else{
        if(treeNode->data==data){
            return treeNode;
        }else{
            ptr = TreeFindNode(treeNode->left,data);
            if(!ptr){
                return TreeFindNode(treeNode->right,data); 
            } 
            return ptr;        
        }
    }    
}

// 添加结点
void AddTreeNode(CBTType* treeNode){
    CBTType* pnode;
    CBTType* parent;
    DATA data;
    char menusel;

    if(pnode=(CBTType*)malloc(sizeof(CBTType))){
        cout<<"输入二叉树结点数据:"<<endl;
        cin>>pnode->data;
        pnode->left = NULL;
        pnode->right = NULL;

        cout<<"输入该结点的父节点数据"<<endl;
        cin>>data;
        parent = TreeFindNode(treeNode,data);
        if(!parent){
            cout<<"未曾找到该结点！"<<endl;
            free(pnode);
            return;
        } 
        do{
            cout<<"1.添加到该结点的左子树,2.添加到该结点的右子树:";
            cin>>menusel;
            switch(menusel){
                case 1:
                    if(parent->left){
                        cout<<"左子树结点不为空，无法添加到该结点的左子树上!"<<endl;
                    }else{
                        parent->left = pnode;
                    }                    
                    break;
                case 2:
                    if(parent->right){
                        cout<<"右子树的结点不能为空，无法添加到该结点的右子树上!"<<endl;                        
                    }else{
                        parent->right = pnode;
                    }
                    break;
                default:
                    cout<<"无效的参数"<<endl;
            }
        }while(menusel!=1 && menusel!=2);
    }
}

// 获取左子树
CBTType* TreeLeftNode(CBTType* treeNode){
    if(treeNode){
        return treeNode->left;
    }
    return NULL;
}

// 获取右子树
CBTType* TreeRightNode(CBTType* treeNode){
    if(treeNode){
        return treeNode->right;
    }
    return NULL;
}

// 判断空树
int TreeIsEmpty(CBTType* treeNode){
    if(treeNode){
        return 0;
    }
    return 1;
}

// 计算二叉树的深度(递归算法)
int TreeDepth(CBTType* treeNode){
    int depleft;
    int depright;
    if(!treeNode){
        return 0;
    }
    depleft = TreeDepth(treeNode->left);    
    depright = TreeDepth(treeNode->right);
    return depleft>depright?(depleft+1):(depright+1);
}

// 清空二叉树
void ClearTree(CBTType* treeNode){
    if(treeNode){
        ClearTree(treeNode->left);
        ClearTree(treeNode->right);
        free(treeNode);
        treeNode = NULL;
    }
}

// 显示结点的数据
void TreeNodeData(CBTType* p){
    cout<<p->data<<endl;
}

// 按层次遍历算法(用到了循环队列,队列为空的条件为tail==head)
void LevelTree(CBTType* treeNode){
    CBTType* p;
    CBTType* q[MANLEN];
    int head = 0,tail = 0;

    if(treeNode){
        tail = (tail+1)%MANLEN;
        q[tail] = treeNode;
    }
    while(head!=tail){
        head = (head+1)%MANLEN;
        p = q[head];
        TreeNodeData(p);
        if(p->left){
            tail = (tail+1)%MANLEN;
            q[tail] = p->left;
        }
        if(p->right){
            tail = (taile+1)%MANLEN;
            q[tail] = p->right;
        }
    }
}

// 先序遍历算法
void DLRTree(CBTType* treeNode){
    if(treeNode){
        TreeNodeData(treeNode);
        DLRTree(treeNode->left); 
        DLRTree(treeNode->right);
    }
}

// 中序遍历
void LDRTree(CBTType* treeNode){
    if(treeNode){
        LDRTree(treeNode->left);
        TreeNodeData(treeNode);
        LDRTree(treeNode->right);
    }
}

// 后续遍历
void LRDTree(CBTType* treeNode){
    if(treeNode){
        LRDTree(treeNode->left); 
        LRDTree(treeNode->right);
        TreeNodeData(treeNode);
    }
}

int main(){

    return 0;
}