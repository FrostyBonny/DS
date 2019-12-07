#include<iostream>
#include<stdlib.h>
using namespace std;
// 单链表的操作
typedef struct LinkNode{
    char data;
    struct LinkNode *next;
}LinkNode;
char data1[11] = "yjgujhuikj";
char data2[4] = "ikj";
void creat_1(LinkNode *L){
    LinkNode *node;
    for(int i = 0;i < 10;i++){
        node = (LinkNode *)malloc(sizeof(LinkNode));
        node->data = data1[i];
        node->next = L->next;
        L->next = node;
    }
}
void creat_2(LinkNode *L){
    LinkNode *node;
    for(int i = 0;i < 3;i++){
        node = (LinkNode *)malloc(sizeof(LinkNode));
        node->data = data2[i];
        node->next = L->next;
        L->next = node;
    }
}
void PrintOut(LinkNode *L){
    int time = 1;
    while(L->next != NULL){
        if(time > 20) return;
        cout<<L->next->data;
        L = L->next;
        time ++;
    }
    cout<<endl;
}

int BF(LinkNode *L,LinkNode *S){
    LinkNode *p = L->next;
    LinkNode *q = S->next;
    LinkNode *t,*m;
    int index = 1;
    while(p->next != NULL){
        if(p->data == q->data){
            t = p;
            m = q;
            while(m->next != NULL&&t->data == m->data){
                m = m->next;
                t = t->next;
            }
            if(m->next == NULL){
                return index;
            }
        }
        p = p->next;
        index++;
    }
    return 0;
}

int main(){
    LinkNode *L,*S;
    L = (LinkNode *)malloc(sizeof(LinkNode));
    S = (LinkNode *)malloc(sizeof(LinkNode));
    L->next = NULL;
    S->next = NULL;
    creat_1(L);
    creat_2(S);
    cout<<BF(L,S)<<endl;
    PrintOut(L);
    PrintOut(S);
    return 0;
}
