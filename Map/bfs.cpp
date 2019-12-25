#include<iostream>
#include<stdlib.h>
using namespace std;
typedef struct ArcNode{
    int node;
    struct ArcNode *next = NULL;
}ArcNode;
typedef struct VNode{
    int data;
    ArcNode *first = NULL;
}VNode,AdjList[100];
typedef struct ALMap{
    AdjList v;
    int vnum,anum;
}ALMap;
typedef struct QUEUE{
    int node;
    int parent;
}QUEUE;
int p1[15] = {1,1,2,4,3,5,4,3,4};
int p2[15] = {2,3,5,2,5,1,1,2,5};

void creat(ALMap *M){
    ArcNode *p,*q;
    M->vnum = 5;
    M->anum = 9;
    for(int i = 0;i < 9;i++){
        // 可以直接采用头插法，就是一起的了。
        //p = (ArcNode *)malloc(sizeof(ArcNode));
        //p->node = p2[i];
        //p->next = M->v[p1[i]].first;
        //M->v[p1[i]].first = p;
        if(M->v[p1[i]].first == NULL){
            p = (ArcNode *)malloc(sizeof(ArcNode));
            p->node = p2[i];
            M->v[p1[i]].first = p;
        }else{
            q = M->v[p1[i]].first;
            while(q->next != NULL) q = q->next;
            p = (ArcNode *)malloc(sizeof(ArcNode));
            p->node = p2[i];
            q->next = p;
        }
        
        if(M->v[p2[i]].first == NULL){
            p = (ArcNode *)malloc(sizeof(ArcNode));
            p->node = p1[i];
            M->v[p2[i]].first = p;
        }else{
            q = M->v[p2[i]].first;
            while(q->next != NULL) q = q->next;
            p = (ArcNode *)malloc(sizeof(ArcNode));
            p->node = p1[i];
            q->next = p;
        }
        
    }
}

void bfs_B(ALMap *M,int vi,int vj){
    QUEUE q[100];
    int dir[6] = {0};
    int l = -1,r = -1;
    r++;
    q[r].node = vi;
    q[r].parent = -1;
    dir[vi] = 1;
    while(l <= r){
        if(q[l].node == vj){
            int printIndex = l;
            while(q[printIndex].parent != -1){
                cout<<q[printIndex].node<<" ";
                printIndex = q[printIndex].parent;
            }
            cout<<q[printIndex].node<<endl;
            break;
        }
        l++;
        QUEUE t = q[l];
        if(M->v[t.node].first != NULL){
            ArcNode *p = M->v[t.node].first;
            while(p != NULL){
                if(dir[p->node] == 0){
                    r++;
                    q[r].node = p->node;
                    q[r].parent = l;
                    dir[p->node] = 1;
                }
                p = p->next;
            }
        }
    }
}

void PrintMap(ALMap *M){
    for(int i = 1;i < 6;i++){
        ArcNode *p = M->v[i].first;
        while(p != NULL){
            cout<<p->node<<" ";
            p = p->next;
        }
        cout<<endl;
    }
}

int main(){
    ALMap *Map;
    Map = (ALMap *)malloc(sizeof(ALMap));
    creat(Map);
//    PrintMap(Map);
    bfs(Map,4,3);
    return 0;
}