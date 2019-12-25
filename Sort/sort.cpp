#include <iostream> 
#include <stdlib.h>
using namespace std;
void creat(int a[]){
    for(int i = 1;i <= 10;i++){
        a[i] = rand()%30;
    }
}
void printAr(int a[],int n){
    for(int i = 1;i <= n;i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

void ShellSort(int a[],int n){
    int d;
    for(d = n/2;d >= 1;d /= 2){
        for(int i = d + 1;i <= n;i++){
            cout<<i<<" ";
            if(a[i] < a[i-d]){
                int j;
                a[0] = a[i];
                for(j = i - d;a[0] < a[j]&&j > 0;j -= d){
                    a[j + d] = a[j];
                }
                a[j + d] = a[0];
            }
        }
        cout<<endl;
    }
}

void merge(int a[],int low,int mid,int high){
    int b[high + 1] = {0};
    for(int i = low;i <= high;i++){
        b[i] = a[i];
    }
    int i,j,k;
    for(i = low,j = mid + 1,k = i;i <= mid&&j <= high;k++){
        if(a[i] < b[i]){
            a[k] = b[i++];
        }else{
            a[k] = b[j++];
        }
    }
    while(i <= mid) a[k++] = b[i++];
    while(j <= high) a[k++] = b[j++];
}

void MergeSort(int a[],int low,int high){
    if(low < high){
        int mid = (low + high)/2;
        MergeSort(a,low,mid);
        MergeSort(a,mid+1,high);
        merge(a,low,mid,high);
    }
}

int main(){
    int a[11];
    creat(a);
    printAr(a,10);
    // ShellSort(a,10);
    MergeSort(a,1,10);
    printAr(a,10);

}