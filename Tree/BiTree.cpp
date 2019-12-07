#include <iostream>
#include <cstdlib>
using namespace std;
typedef struct BNode{
    int data;
    struct BNode *lchild;
    struct BNode *rchild;
}BNode;

typedef struct QUEUE{
    BNode *data[50];
    int left;
    int right;
}QUEUE;

void Creat(BNode *BTree){
    int l,r;
    BNode *BTreeNode;
    cin>>l>>r;
    if(l == 0){
        BTreeNode = NULL;
        BTree->lchild = BTreeNode;
    }
    else{
        BTreeNode = (BNode *)malloc(sizeof(BNode));
        BTreeNode->data = l;
        BTree->lchild = BTreeNode;
        Creat(BTree->lchild);
    }
    if(r == 0){
        BTreeNode = NULL;
        BTree->rchild = BTreeNode;
    }
    else{
        BTreeNode = (BNode *)malloc(sizeof(BNode));
        BTreeNode->data = r;
        BTree->rchild = BTreeNode;
        Creat(BTree->rchild);
    }
}

BNode *creat(){
    BNode *BTree;
    int n;
    cin>>n;
    if(n == 0){
        BTree = NULL;
    }else{
        BTree = (BNode *)malloc(sizeof(BNode));
        BTree->data = n;
        BTree->lchild = creat();
        BTree->rchild = creat();
    }
    return BTree;
}

void PreOrder(BNode *BTree){
    if(BTree != NULL){
        cout<<BTree->data;
        PreOrder(BTree->lchild);
        PreOrder(BTree->rchild);
    }
}

void InOrder(BNode *BTree){
    if(BTree != NULL){
        InOrder(BTree->lchild);
        cout<<BTree->data;
        InOrder(BTree->rchild);
    }
}

void PostOrder(BNode *BTree){
    if(BTree != NULL){
        PostOrder(BTree->lchild);
        PostOrder(BTree->rchild);
        cout<<BTree->data;
    }
}

void LevelOrder(BNode *BTree){
    QUEUE q;
    q.left = -1;
    q.right = -1;
    q.right++;
    q.data[q.right] = BTree;
    while(q.left < q.right){
        q.left = q.left + 1;
        // cout<<"this is left:"<<q.left<<" "<<q.right<<endl;
        BNode *t;
        t = q.data[q.left];
        cout<<t->data;
        if(t->lchild != NULL){
            q.right++;
            q.data[q.right] = t->lchild;
        }
        if(t->rchild != NULL){
            q.right++;
            q.data[q.right] = t->rchild;
        }

    }

}

int main(){
    BNode *BTree;
    //BTree = (BNode *)malloc(sizeof(BNode));
    //BTree->data = 9;
    //Creat(BTree);
    BTree = creat();
    PreOrder(BTree);
    cout<<endl;
    InOrder(BTree);
    cout<<endl;
    LevelOrder(BTree);
    cout<<endl;
    return 0;
}
//9 1 2 0 0 3 0 0 4 5 6 0 0 0 7 0 0