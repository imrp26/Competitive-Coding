#include <bits/stdc++.h>
using namespace std;
 
const int mx=2e4+3;
vector<int> color,vec;
vector<vector<int> > graph;
int ans;
 
void bfs(int src)
{
    int i,temp,n1=0,n2=0;
    vec.clear();
    queue<int> q;
    q.push(src);
    color[src]=1;
    n1++;
    while(!q.empty())
    {
        src=q.front();
        vec.push_back(src);
        q.pop();
        for(i=0;i<graph[src].size();i++)
        {
            temp=graph[src][i];
            if(color[temp]!=-1)
                continue;
            color[temp]=3-color[src];
            if(color[temp]==1)
                n1++;
            else
                n2++;
            q.push(temp);
        }
    }
    ans+=max(n1,n2);
}
 
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int i,j,t,n,u,v,maxval;
    cin>>t;
    for(j=1;j<=t;j++)
    {
        cin>>n;
        graph.clear();
        graph.resize(mx);
        color.clear();
        for(i=0;i<=mx;i++)
            color.push_back(0);
        while(n--)
        {
            cin>>u>>v;
            color[u]=color[v]=-1;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        ans=0;
        for(i=1;i<mx;i++)
        {
            if(color[i]==-1)
                bfs(i);
        }
        cout<<"Case "<<j<<": "<<ans<<endl;
    }
}
