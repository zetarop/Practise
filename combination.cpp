/*
    : Given an array of length n, print all combination of k integer.
*/

#include<bits/stdc++.h>
#define ve vector
#define pb push_back
#define ll long long
using namespace std;

int Cnt=0;

void comb(ve<int> v,ve<int> temp, int start, int k, int n)
{
	if(temp.size() == k)
	{
		Cnt++;
		for(auto a:temp)
			cout<<a<<" ";
		cout<<endl;
	}
	else if(start < n)
	{
		for(int i = start+1;i<n;i++)
		{
			ve<int> temp1 = temp;
			temp1.pb(v[i]);
			comb(v, temp1, i, k, n);
		}
	}
}




 int main()
 {
 	int n,k;
 	cin>>n>>k;
 	ve<int> v(n),temp;
 	for(auto &x:v)
 		cin>>x;

 	int H=n-k;

 	comb(v, temp, -1, k, n);
 	cout<<endl<<endl;
 	cout<<"Total: "<<Cnt<<endl;


 	return 0;
 }
