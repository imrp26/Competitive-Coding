#include <bits/stdc++.h>
using namespace std;
#define ll long long

struct comp
{
	bool operator()(const pair<ll,pair<ll,ll> > &a,const pair<ll,pair<ll,ll> > &b)
	{
		return (a.second.first>b.second.first);
	}
};

int main()
{
	ll tc,j,t,alt,nodes,edges,u,v,w,i,dist[3][5005],dmax=1e15;
	bool vis[3][5005];
	vector<vector<pair<ll,ll> > > graph;
	cin>>tc;
	for(j=1;j<=tc;j++)
	{
		cin>>nodes>>edges;
		graph.clear();
		graph.resize(nodes+1);
		for(i=0;i<edges;i++)
		{
			cin>>u>>v>>w;
			graph[u].push_back({v,w});
			graph[v].push_back({u,w});
		}
		priority_queue<pair<ll,pair<ll,ll> >,vector<pair<ll,pair<ll,ll> > >,comp> pq;
		for(i=1;i<=nodes;i++)
		{
			dist[1][i]=dist[2][i]=dmax;
			vis[1][i]=vis[2][i]=0;
		}
		dist[1][1]=0;
		pq.push({1,{0,1}});
		while(!pq.empty())
		{
			t=pq.top().first;
			u=pq.top().second.second;
			pq.pop();
			if(vis[t][u])
				continue;
			vis[t][u]=1;
			for(i=0;i<graph[u].size();i++)
			{
				v=graph[u][i].first;
				alt=dist[t][u]+graph[u][i].second;
				if(alt<dist[1][v])
				{
					dist[2][v]=dist[1][v];
					pq.push({2,{dist[2][v],v}});
					dist[1][v]=alt;
					pq.push({1,{dist[1][v],v}});
				}
				else if(alt>dist[1][v] && alt<dist[2][v])
				{
					dist[2][v]=alt;
					pq.push({2,{dist[2][v],v}});
				}
			}
		}
		cout<<"Case "<<j<<": "<<dist[2][nodes]<<endl;
	}
}
