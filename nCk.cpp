#include<bits/stdc++.h>
#define ve vector
#define pb push_back
#define ll long long
using namespace std;



ll nCk(int n, int k)
{
	ll ans=1;
	for(int i=1;i<=k;i++)
	{
		ans = (ans*(n-k+i))/i;
	}
	return ans;
}


int main()
{
	int n;
	int k;
	cin>>n>>k;
	cout<<nCk(n,k)<<endl;
	return 0;
}
