//注意:代码模板中的代码将会被复制到任何新创建的文件中，编辑代码模板中的代码，让他帮你自动增加固定代码吧
#include <iostream> 
using namespace std;
int H(int n){
    return n%13;
}
double Cal(int Hash[],int Array[],int m,int n){
    double sum = 0;
    for(int i = 1;i <= n;i++){
        int site = H(Array[i]);
        sum += 1;
        while(Hash[site] != Array[i]){
            site = (site + 1)%m;
            sum++;
        }
    }
    return sum/n;
}
void main(){
    int Hash[16] = {33,1,13,12,34,38,27,22,0,0,0,0};
    int Array[9] = {0,1,13,12,34,38,33,27,22};
    int n = 8;
    int m = 11;
    cout<<Cal(Hash,Array,m,n)<<endl;
}