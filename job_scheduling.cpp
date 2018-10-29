/*
Input : n
Input : id, deadline, profit 
*/
#include<bits/stdc++.h>
#define ve vector
#define pb push_back
#define ll long long
using namespace std;

bool comp(pair<int,int> a, pair<int,int> q)
{
	return a.first > q.first;
}

void solve()
{
	int n;
	cin>>n;
	int mx=-1;
	ve<pair<int,int> > v(n);
	for(auto &x:v)
	{
		int a;
		cin>>a>>x.second>>x.first;
	}
	sort(v.begin(), v.end(),comp);

	int A[n+1];
	fill(A,A+n+1,0);

	for(auto a:v)
	{
		int t = a.second;
		
		for(int i=min(t,n);i>=1;i--)
		{
			if(A[i] == 0)
			{
				A[i]=a.first;
				break;
			}
		}
	}
	int cnt=0;
	int sum=0;
	
	for(int i=1;i<=n;i++)
	{
		if(A[i] != 0)
		{
			cnt++;
			sum += A[i];
		}
	}
	cout<<cnt<<" "<<sum<<endl;


	return;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
}
