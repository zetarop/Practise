#include<bits/stdc++.h>
#define ve vector
using namespace std;

int main()
{
	int n,d;
	cin>>n>>d;
	ve<int> v(n);
	for(auto &x:v)
		cin>>x;
	map<int, int> M;
	int ans=0;

	for(int i=0;i<n;i++)
	{
		int a = v[i]-i*d;
		M[a]++;
		ans = max(ans,M[a]);
	}
	cout<<"min_update: "<<n-ans<<endl;
	return 0;
}
