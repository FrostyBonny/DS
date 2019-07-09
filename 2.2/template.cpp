#include<iostream.h>
#include<stdlib.h>
#define MaxSize 50
using namespace std;
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
int main(){
    SqlList L;
    InitList(L);
    for(int i = 1;i <= 10;i++){
        Insert(L,i,rand()%10);
    }
    for(int i = 1;i <= L.length;i++){
        cout<<L.data[i]<<endl;
    }
    return 0;
}