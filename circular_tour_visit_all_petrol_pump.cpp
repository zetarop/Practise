#include<bits/stdc++.h>
#define ve vector
#define pb push_back
#define ll long long
using namespace std;

int count(int n, int C, int A[], int B[])
{
	int need[n];

	for(int i=0;i<n;i++)
		A[i+n]=A[i],
		B[i+n]=B[i];

	int start=0;  // first valid from where we can complete a cycle
	int tank=0;
	for(int i=0;i<2*n;i++)
	{
		tank += A[i];
		tank = min(tank, C);
		tank -= B[i];

		if(tank < 0)
		{
			tank=0;
			start = i+1;
		}
	}
	if(start >= n)
		return 0;

	int ans=1;
	need[start+n]=0;

	for(int i=1;i<n;i++)
	{
		int k = start+n-i;
		need[k] = max(0, need[k+1] + B[k] - min(C,A[k]));
		if(need[k] == 0)
			ans++;
	}
  
	return ans;
}

int main()
{
	int N;
	int C;
	cin>>N>>C;
	int A[2*N], B[2*N];
	for(int i=0;i<N;i++)
		cin>>A[i];
	for(int i=0;i<N;i++)
		cin>>B[i];
	cout<<count(N,C,A,B)<<endl;
	return 0;
}
