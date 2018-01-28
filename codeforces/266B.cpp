#include <bits/stdc++.h>
using namespace std;

int main()
{
	int n,t,j,i;
	string str;
	cin>>n>>t;
	cin>>str;
	for(j=1;j<=t;j++)
	{
		for(i=0;i<n-1;i++)
		{	
			if(str[i]=='B' && str[i+1]=='G')
			{
				swap(str[i],str[i+1]);
				i++;
			}
		}	
	}
	cout<<str;
}
