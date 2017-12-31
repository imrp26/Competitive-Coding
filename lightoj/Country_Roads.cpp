#include <bits/stdc++.h>
using namespace std;
 
vector<int> graph[505],cost[505];
int dist[505];
 
void bfs(int src)
{
    queue<int> q;
    q.push(src);
    dist[src]=0;
    int u,v,i,temp;
    while(!q.empty())
    {
        u=q.front();
        q.pop();
        for(i=0;i<graph[u].size();i++)
        {
            v=graph[u][i];
            temp=max(dist[u],cost[u][i]);
            if(temp<dist[v])
            {
                dist[v]=temp;
                q.push(v);
            }
        }
    }
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i,j,t,nodes,edges,u,v,w,dmax=1e9;
    cin>>t;
    for(j=1;j<=t;j++)
    {
        cin>>nodes>>edges;
        for(i=1;i<=edges;i++)
        {
            cin>>u>>v>>w;
            graph[u].push_back(v);
            graph[v].push_back(u);
            cost[u].push_back(w);
            cost[v].push_back(w);
        }
        cin>>u;
        for(i=0;i<nodes;i++)
            dist[i]=dmax;
        bfs(u);
        cout<<"Case "<<j<<":\n";
        for(i=0;i<nodes;i++)
        {
            if(dist[i]==dmax)
                cout<<"Impossible\n";
            else
                cout<<dist[i]<<endl;
        }
        for(i=0;i<nodes;i++)
        {
            graph[i].clear();
            cost[i].clear();
        }
    }
}
