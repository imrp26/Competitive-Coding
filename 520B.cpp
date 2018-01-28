#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,m,ans=0;
	cin>>n>>m;
	while(m>n)
	{
		if(m&1)
		{
			m++;
			ans++;
		}
		m/=2;
		ans++;
	}
	ans+=n-m;
	cout<<ans;
}
