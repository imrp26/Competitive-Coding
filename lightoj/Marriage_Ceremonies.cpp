#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
ll n,dp[17][1<<17];
 
ll memoize(ll i,ll mask)
{
    if(dp[i][mask]!=-1)
        return dp[i][mask];
    ll ans=0,k;
    for(k=0;k<n;k++)
    {
        if((1<<k) & mask)
            ans=max(ans,memoize(i-1,mask & (~(1<<k)))+dp[i][1<<k]);
    }
    return (dp[i][mask]=ans);
}
 
int main()
{
    ll tc,t,i,j,res;
    cin>>t;
    for(tc=1;tc<=t;tc++)
    {
        cin>>n;
        for(i=0;i<n;i++)
        {
            memset(dp[i],-1,sizeof dp[i]);
            for(j=0;j<n;j++)
                cin>>dp[i][1<<j];
        }
        res=memoize(n-1,(1<<n)-1);
        cout<<"Case "<<tc<<": "<<res<<endl;
    }
}
