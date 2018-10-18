#include<bits/stdc++.h>
#define ve vector
#define pb push_back
#define ll long long
using namespace std;



void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	int k;
	cin>>k;
	int ans=0;
	for(int i=0 ; i<n ;i++)
	{
		map<char, int> M;
		int cnt=0;
		for(int j=i;j<n && cnt <=k;j++)
		{
			if(M[s[j]] == 0)
			{
				cnt++;
				M[s[j]]=1;
			}
			if(cnt == k)
				ans++;
		}
	}
	cout<<ans<<endl;
} 


int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
}
