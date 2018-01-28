#include <bits/stdc++.h>
using namespace std;

int main()
{
	int sx,sy,tx,ty,i,ans=0;
	string s,t;
	vector<string> moves;
	cin>>s;
	cin>>t;
	sy=(s[0]-'a')+1;
	sx=s[1]-'0';
	ty=(t[0]-'a')+1;
	tx=t[1]-'0';
	while(sx!=tx || sy!=ty)
	{
		ans++;
		if(sx==tx)
		{
			if(sy<ty)
			{
				sy++;
				moves.push_back("R");
			}
			else
			{
				sy--;
				moves.push_back("L");
			}
		}
		else if(sy==ty)
		{
			if(sx<tx)
			{
				sx++;
				moves.push_back("U");
			}
			else
			{
				sx--;
				moves.push_back("D");
			}
		}
		else
		{
			if(sx<tx && sy<ty)
			{
				sx++;
				sy++;
				moves.push_back("RU");
			}
			else if(sx<tx && sy>ty)
			{
				sx++;
				sy--;
				moves.push_back("LU");
			}
			else if(sx>tx && sy>ty)
			{
				sx--;
				sy--;
				moves.push_back("LD");
			}
			else
			{
				sx--;
				sy++;
				moves.push_back("RD");
			}
		}
	}
	cout<<ans<<endl;
	for(i=0;i<ans;i++)
		cout<<moves[i]<<endl;
}
