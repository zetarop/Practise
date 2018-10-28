#include<bits/stdc++.h>
#define ve vector
#define pb push_back
#define ll long long
using namespace std;

void solve()
{
	int n;
	cin>>n;
	int time;
	
	int A[n],D[n];
	for(int i=0;i<n;i++)
		cin>>A[i];
	for(int i=0;i<n;i++)
		cin>>D[i];
	sort(A,A+n);
	sort(D,D+n);

	int ans=0;

	int i=0;
	int need=0;
	int j=0;

	while(i < n && j < n)
	{
		if(A[i] <= D[j])
		{
			need++;
			if(ans < need)
			{
				ans = need;
				time=A[i];
			}
			i++;
		}
		else
		{
			need--;
			j++;
		}
	}
	cout<<ans<<" "<<time<<endl;
	return;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
		solve();
	return 0;
}
