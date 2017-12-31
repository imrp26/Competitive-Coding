#include <bits/stdc++.h>
using namespace std;
 
vector<vector<char> > graph;
vector<vector<bool> > vis;
int rows,cols,ans;
 
void recurse(int sx,int sy)
{
    if(sx<0 || sx==rows || sy<0 || sy==cols || vis[sx][sy] || graph[sx][sy]=='#')
        return;
    ans++;
    vis[sx][sy]=1;
    recurse(sx+1,sy);
    recurse(sx-1,sy);
    recurse(sx,sy+1);
    recurse(sx,sy-1);
}
 
int main()
{
    int t,i,j,k,sx,sy;
    char ch;
    cin>>t;
    for(k=1;k<=t;k++)
    {
        cin>>cols>>rows;
        graph.clear();
        graph.resize(rows);
        vis.clear();
        vis.resize(rows);
        for(i=0;i<rows;i++)
        {
            for(j=0;j<cols;j++)
            {
                cin>>ch;
                graph[i].push_back(ch);
                if(ch=='@')
                {
                    sx=i;
                    sy=j;
                }
                vis[i].push_back(0);
            }
        }
        ans=0;
        recurse(sx,sy);
        cout<<"Case "<<k<<": "<<ans<<endl;
    }
}
