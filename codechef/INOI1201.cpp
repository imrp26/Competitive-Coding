#include <bits/stdc++.h>
using namespace std;
#define ll long long
 
int main()
{
	ll n,a,b,c,s=0,i,ans=1e15;
	vector<pair<ll,pair<ll,ll> > > v;
	cin>>n;
	for(i=1;i<=n;i++)
	{
		cin>>a>>b>>c;
		s+=a;
		v.push_back({a,{b,c}});
	}
	for(i=0;i<n;i++)
		ans=min(ans,s+v[i].second.first+v[i].second.second);
    for(i=0;i<n;i++)
    {
        if(v[i].first+v[i].second.first+v[i].second.second>ans)
            ans=v[i].first+v[i].second.first+v[i].second.second;
    }
	cout<<ans;
} 
