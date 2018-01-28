#include <bits/stdc++.h>
using namespace std;
 
struct comp
{
	bool operator()(const pair<int,int> &a,const pair<int,int> &b)
	{
		return (a.second>b.second);
	}
};
 
vector<vector<pair<int,int> > > graph;
priority_queue<pair<int,int>,vector<pair<int,int> >,comp> pq;
int vis[235],dist[235];
 
int main()
{
	int n,m,u,v,w,i,j,src,ans=-1;
	cin>>n>>m;
	graph.resize(n+1);
	while(m--)
	{
		cin>>u>>v>>w;
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
	}
	for(i=1;i<=n;i++)
	{
		src=i;
		memset(dist,1e9+7,sizeof dist);
		memset(vis,0,sizeof vis);
		dist[src]=0;
		pq.push({src,0});
		while(!pq.empty())
		{
			u=pq.top().first;
			pq.pop();
			if(vis[u])
				continue;
			vis[u]=1;
			for(j=0;j<graph[u].size();j++)
			{
				v=graph[u][j].first;
				w=graph[u][j].second;
				if(!vis[v] && dist[u]+w<dist[v])
				{
					dist[v]=dist[u]+w;
					pq.push({v,dist[v]});
				}
			}
		}
		for(j=1;j<=n;j++)
			ans=max(ans,dist[j]);
		while(!pq.empty())
			pq.pop();
	}
	cout<<ans;
} 
