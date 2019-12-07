#include<iostream>
#include<stdlib.h>
using namespace std;
// 单链表的操作
typedef struct LinkNode{
    int data;
    struct LinkNode *next;
}LinkNode;
// headermake

void creat(LinkNode *L){
    LinkNode *node;
    for(int i = 0;i < 10;i++){
        node = (LinkNode *)malloc(sizeof(LinkNode));
        node->data = rand()%13;
        node->next = L->next;
        L->next = node;
    }
    // return L;
}

void PrintOut(LinkNode *L){
    int time = 1;
    while(L->next != NULL){
        if(time > 20) return;
        cout<<L->next->data<<" ";
        L = L->next;
        time ++;
    }
    cout<<endl;
}

//第一个为标准，前面比他小，后面比他大。practice 5
void sortA(LinkNode *L){
    int time = 1;
    LinkNode *s = L->next;
    LinkNode *p = s->next;
    LinkNode *pre;
    cout<<s->data<<endl;
    s->next = NULL;
    LinkNode *qre = s;
    while(p != NULL){
        if(time > 30) return;
        time++;
        if(p->data < s->data){
            pre = p->next;
            p->next = L->next;
            L->next = p;
            p = pre;
        }else if(p->data > s->data){
            pre = p->next;
            p->next = s->next;
            s->next = p;
            p = pre;
        }
    }
}

//practice 6  caculate the last site element
int func_6(LinkNode *L,int k){
    LinkNode *p,*q;
    p = L->next;
    q = L->next;
    while(k > 1&&q->next != NULL){
        q = q->next;
        k--;
    }
    if(q->next == NULL){
        cout<<0<<endl;
        return 0;
    }
    while(q->next != NULL){
        q = q->next;
        p = p->next;
    }
    cout<<p->data<<endl;
    return 1;
}

// reversed way 1
void func_7(LinkNode *L){
    LinkNode *p = L->next;
    LinkNode *q;
    L->next = NULL;
    while(p != NULL){
        q = p->next;
        p->next = L->next;
        L->next = p;
        p = q;
    }
}

// reversede way 2
void func_8(LinkNode *L){
    LinkNode *p,*q,*r;
    p = L->next;
    q = p->next;
    p->next = NULL;
    while(q->next != NULL){
        r = q->next;
        q->next = p;
        p = q;
        q = r;
    }
    q->next = p;
    L->next = q;

}

int main(){
    LinkNode *L;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
    creat(L);
    PrintOut(L);
    
    //practice 5
    //sortA(L);
    //PrintOut(L);
    
    //pracetice 6
    //func_6(L,4);

    //reversed without other space
    //func_7(L);
    func_8(L);
    PrintOut(L);
    return 0;
}
