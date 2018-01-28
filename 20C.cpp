#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct comp
{
	bool operator()(const pair<int,ll> &a,const pair<int,ll> &b)
	{
		return (a.second>b.second);
	}
};

priority_queue<pair<int,ll>,vector<pair<int,ll> >,comp> pq;
vector<vector<pair<int,ll> > > graph;

int main()
{
	int nodes,edges,u,v,i,a,b,parent[100005];
	ll dist[100005],dmax=1e15,w;
	bool vis[100005];
	vector<int> path;
	cin>>nodes>>edges;
	graph.resize(nodes+1);
	for(i=1;i<=edges;i++)
	{
		cin>>u>>v>>w;
		graph[u].push_back({v,w});
		graph[v].push_back({u,w});
	}
	for(i=1;i<=nodes;i++)
	{
		dist[i]=dmax;
		parent[i]=-1;
		vis[i]=0;
	}
	dist[1]=0;
	pq.push({1,0});
	while(!pq.empty())
	{
		u=pq.top().first;
		pq.pop();
		if(vis[u])
			continue;
		for(i=0;i<graph[u].size();i++)
		{
			v=graph[u][i].first;
			w=graph[u][i].second;
			if(!vis[v] && dist[u]+w<dist[v])
			{
				dist[v]=dist[u]+w;
				pq.push({v,dist[v]});
				parent[v]=u;
			}
		}
		vis[u]=1;
	}
	if(dist[nodes]==dmax)
		cout<<-1;
	else
	{
		u=nodes;
		while(parent[u]!=-1)
		{
			path.push_back(u);
			u=parent[u];
		}
		path.push_back(u);
		for(i=path.size()-1;i>=0;i--)
			cout<<path[i]<<' ';
	}
}
