#include<bits/stdc++.h>
using namespace std;
int main() {
    int a[1000];
    int n, m;
    int sum=0;
    cin >> n >> m;
    for(int i=0;i<m;i++){
        cin>>a[i];
    }
    for (int i = 0; i < n; i++) {
        int type, limit;
        cin >> type >> limit;
        if(a[type-1]>limit){
            sum+=limit;
            a[type-1]-=limit;
        }else{
            sum+=a[type-1];
            a[type-1]=0;
        }
    }cout<<sum;
    return 0;
}