#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
ll extended_euclid(ll a,ll b,ll &x,ll &y)
{
    if(!a)
    {
        x=0;
        y=1;
        return b;
    }
    ll x1,y1,g=extended_euclid(b%a,a,x1,y1);
    x=y1-(b/a)*x1;
    y=x1;
    return g;
}
 
int main()
{
    ll t,n,a,m,j,prod,i,ans,b,x,y,g;
    vector<pair<ll,ll> > v;
    cin>>t;
    for(j=1;j<=t;j++)
    {
        cin>>n;
        v.clear();
        ans=0;
        prod=1;
        for(i=0;i<n;i++)
        {
            cin>>m>>a;
            v.push_back({a,m});
            prod*=m;
        }
        for(i=0;i<n;i++)
        {
            m=v[i].second;
            b=prod/m;
            g=extended_euclid(b,m,x,y);
            x=(x%m+m)%m;
            ans+=(v[i].first*b*x);
            ans%=prod;
        }
        cout<<"Case "<<j<<": "<<ans<<endl;
    }
}
