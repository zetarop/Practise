#include<bits/stdc++.h>
#define ve vector
#define pb push_back
#define ll long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	
	ve<pair<int,int> > v;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		v.pb({a,0});
	}
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		v.pb({a,1});
	}
	sort(v.begin(), v.end());

	int ans=0;
	int cnt=0;
	int time;

	for(auto a:v)
	{
		if(a.second == 0)
		{
			cnt++;
			if(ans < cnt)
			{
				ans=cnt;
				time=a.first;
			}
		}
		else
			cnt--;
	}
	cout<<ans<<" "<<time<<endl;
	return ;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
