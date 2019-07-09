#include<iostream>
#include<stdlib.h>
#define MaxSize 50
using namespace std;
// 循环左移
// 如果是右移，可以转换为左移。
typedef struct{
    int *data;
    int length;
}SqlList;
// 初始化
bool InitList(SqlList &L){
    L.data = (int*)malloc(sizeof(int)*MaxSize);
    L.length = 0;
}
bool Insert(SqlList &L,int site,int e){
    if(site < 1 || site > L.length + 1){
        return false;
    }
    if(L.length >= MaxSize){
        return false;
    }
    for(int i = L.length; i >= site;i--){
        L.data[i+1] = L.data[i];
    }
    L.data[site] = e;
    L.length += 1;
    return true;
}
void Outer(SqlList &L){
    for(int i = 1;i <= L.length;i++){
        cout<<L.data[i]<<" ";
    }
    cout<<endl;
}
bool Reverse(SqlList &L,int l,int r){
    if(l < 1||r > L.length){
        return false;
    }
    for(int i = 0;i < (r - l + 1)/2;i++){
        int t = L.data[l+i];
        L.data[l+i] = L.data[r-i];
        L.data[r-i] = t;
    }
    return true;
}

void work(SqlList &L,int time){
    Reverse(L,1,L.length);
    Outer(L);
    Reverse(L,1,L.length - time);
    Outer(L);
    Reverse(L,L.length - time + 1,L.length);
}

int main(){
    SqlList L;
    InitList(L);
    for(int i = 1;i <= 10;i++){
        Insert(L,i,rand()%10);
    }
    Outer(L);
    work(L,2);
    Outer(L);
    system("pause");
    return 0;
}