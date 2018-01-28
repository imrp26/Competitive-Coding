#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n,k,i,j,m,a,num,ans=1;
	map<int,int> president;
	vector<vector<int> > graph;
	vector<pair<int,int> > v;
	cin>>n>>k;
	cin>>m;
	while(m--)
	{
		cin>>a;
		president[a]++;
	}
	graph.resize(n+1);
	for(i=2;i<=n;i++)
	{
		cin>>m;
		num=0;
		while(m--)
		{
			cin>>a;
			graph[i].push_back(a);
			if(president[a])
				num++;
		}
		v.push_back({num,i});
	}
	sort(v.rbegin(),v.rend());
	for(i=0;i<v.size();i++)
	{
		a=v[i].second;
		num=0;
		for(j=0;j<graph[a].size();j++)
		{
			if(president[graph[a][j]])
				num++;
		}
		if(num<k)
			continue;
		ans++;
		for(j=0;j<graph[a].size();j++)
			president[graph[a][j]]++;
	}
	cout<<ans;
} 
