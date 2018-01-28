#include <bits/stdc++.h>
using namespace std;
#define ll long long

set<ll> factors;

void factorise(ll n)
{
	factors.clear();
	for(ll i=1;i*i<=n;i++)
	{
		if(!(n%i))
		{
			factors.insert(i);
			factors.insert(n/i);
		}
	}
	factors.erase(n);
}

int main()
{
	ll i,n,m,powers[150004],dp[150004];
	cin>>n>>m;
	powers[0]=1;
	for(i=1;i<=150000;i++)
		powers[i]=(powers[i-1]*2)%m;
	dp[1]=2;
	for(i=2;i<=n;i++)
	{
		factorise(i);
		dp[i]=powers[i];
		for(auto it=factors.begin();it!=factors.end();it++)
		{
			dp[i]-=dp[*it];
			dp[i]=(dp[i]+m)%m;
		}
	}
	cout<<dp[n];
}
