#include<bits/stdc++.h>
using namespace std;
#define IOS ios::sync_with_stdio(false);cin.tie(0);
#define ll long long int
#define rep(a,b) for(int i=a;i<b;i++)
#define fep(a,b) for(int i=a;i>b;i--)
void solve(int k){
    ll n;cin>>n;
    if(((n>>0&1)==0)&&((n>>1&1)==0)){
        cout<<"NO"<<(k!=0?"\n":"");
        return;
    }
    cout<<"YES"<<"\n";
    vector<int> ans(32);
    /* 从右往左找到第1个1的位置 */
    int f=__builtin_ctz(n & -n);
    for(int i=f,j=f;i<32;i++,j=i){
        /* 找到下一个1的位置 */
        while(j+1<32&&(n>>(j+1)&1)==0)  j++;
        /* 当前是1，直接补 */
        if((n>>j&1)==1){
            ans[j]=1;
            continue;
        }
        ans[j] = 1;
        for(int x=i;x<j;x++) ans[x]=-1;
    }
    for(int i=0;i<32;i++)
    	cout<<ans[i]<<(i!=31?((i+1)%8==0?"\n":" "):(k!=0?"\n":""));
    return;
}
int main(){
    IOS;
    ll n;cin>>n;
    while(n--)
        solve(n);
    return 0;
}