#include<iostream>
#include<stdlib.h>
#define MaxSize 50
using namespace std;
// 顺序表的基本操作
typedef struct{
    int *data;
    int length;
}SqlList;
// 初始化
bool InitList(SqlList &L){
    L.data = (int*)malloc(sizeof(int)*MaxSize);
    L.length = 0;
}
// 插入
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
// delete
bool Delete(SqlList &L,int site,int &e){
    if(site > L.length||site < 1){
        return false;
    }
    e = L.data[site];
    for(int i = site;i < L.length;i++){
        L.data[i] = L.data[i+1];
    }
    L.length -= 1;
    return true;
}
// search
bool Search(SqlList &L,int e){
    for(int i = 1;i <= L.length;i++){
        if(L.data[i] == e){
            return i;
        }
    }
    return 0;
}
int main(){
    SqlList L;
    InitList(L);
    for(int i = 1;i <= 10;i++){
        Insert(L,i,rand()%10);
    }
    for(int i = 1;i <= L.length;i++){
        cout<<L.data[i]<<endl;
    }
    cout<<endl;
    int e;
    Delete(L,1,e);
    cout<<e<<endl;
    cout<<endl;
    for(int i = 1;i <= L.length;i++){
        cout<<L.data[i]<<endl;
    }
    system("pause");
}