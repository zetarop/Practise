#include<map>
#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;


void printMatrixSpiral(int* A[], int n, int m)
{
    int T=0;
    int B=n-1;
    
    int L=0;
    int R=m-1;
    int turn=0;
    
    while(L <= R && T <= B)
    {
        if(turn == 0)
        {
            for(int i=L;i<=R;i++)
                cout<<A[T][i]<<"  ";
            turn = 1;
            T++;
        }
        else if(turn == 1)
        {
            for(int i=T;i<=B;i++)
                cout<<A[i][R]<<"  ";
            turn = 2;
            R--;
        }
        else if(turn == 2)
        {
            for(int i=R;i>=L;i--)
                cout<<A[B][i]<<"  ";
            turn = 3;
            B--;
        }
        else
        {
            for(int i=B;i>=T;i--)
                cout<<A[i][L]<<"  ";
            turn =0;
            L++;
        }
    }
    cout<<endl;
    return;
}

void printMatrix(int* A[], int n, int m)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            cout<<A[i][j]<<"  ";
        }
        cout<<endl;
    }
    cout<<endl;
}


void solve()
{
    int n,m;
    cin>>n>>m;
    int* A[n];
    for(int i=0;i<n;i++)
        A[i] = new int[m];
    
    for(int i=0;i<n;i++)
        for(int j =0;j<m;j++)
            cin>>A[i][j];

    //printMatrix(A,n,m);
    printMatrixSpiral(A,n,m);
}

int main()
{
//    int T;
//    cin>>T;
//    while(T--)
        solve();
}
