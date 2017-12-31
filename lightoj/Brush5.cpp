#include <bits/stdc++.h>
using namespace std;
 
struct comp
{
    bool operator()(const pair<int,int> &a,const pair<int,int> &b)
    {
        return (a.second>b.second);
    }
};
 
int main()
{
    int t,i,j,nodes,edges,dist[102],dmax=1e7,vis[102],u,v,w;
    vector<vector<pair<int,int> > > graph;
    cin>>t;
    for(j=1;j<=t;j++)
    {
        cin>>nodes>>edges;
        graph.clear();
        graph.resize(nodes+1);
        for(i=1;i<=edges;i++)
        {
            cin>>u>>v>>w;
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }
        priority_queue<pair<int,int>,vector<pair<int,int> >,comp> pq;
        for(i=1;i<=nodes;i++)
        {
            vis[i]=0;
            dist[i]=dmax;
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
                }
            }
            vis[u]=1;
        }
        w=dist[nodes];
        cout<<"Case "<<j<<": ";
        if(w==dmax)
            cout<<"Impossible\n";
        else
            cout<<w<<endl;
    }
}
