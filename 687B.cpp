#include <bits/stdc++.h>
using namespace std;

const int mx=1e6+6;
bool prime[mx];
int pf[mx];

void sieve()
{
	int i,j;
	memset(prime,1,sizeof prime);
	prime[0]=prime[1]=0;
	for(i=2;i<mx;i++)
	{
		if(prime[i])
		{
			pf[i]=i;
			for(j=2*i;j<mx;j+=i)
			{
				pf[j]=i;
				prime[j]=0;
			}
		}
	}
}

int main()
{
	int n,k,i,a,flag=1;
	map<int,int> mps,mpc,mptemp;
	cin>>n>>k;
	sieve(); // O(mx * log2(log2(mx))) -> 0.1993 s
	while(k>1) // O(log2(k)) 
	{
		mps[pf[k]]++;
		k/=pf[k];
	}
	for(i=1;i<=n;i++) // O(n * log2(a) + log2(a)) -> 0.1993 s
	{
		cin>>a;
		mptemp.clear();
		while(a>1)
		{
			mptemp[pf[a]]++;
			a/=pf[a];
		}
		for(auto it=mptemp.begin();it!=mptemp.end();it++)
		{
			a=it->first;
			mpc[a]=max(mpc[a],mptemp[a]);
		}
	}	
	for(auto it=mps.begin();it!=mps.end();it++) // O(log2(k))
	{
		a=it->first;
		if(mps[a]>mpc[a])
		{
			flag=0;
			break;
		}
	}
	if(flag)
		cout<<"Yes";
	else
		cout<<"No";
}
