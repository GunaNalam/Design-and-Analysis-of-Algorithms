#include <bits/stdc++.h>
using namespace std;

vector<string> c;

void solve(string s,int n,vector<vector<int>> a,int row=0,int col=0)
{
    if (row==n-1 && col==n-1) 
    {
        c.push_back(s);
        return;
    }
    if (a[row][col])
    {
        a[row][col]=0;
        if (row+1<n) solve(s+'D',n,a,row+1,col);
        if (col-1>=0) solve(s+'L',n,a,row,col-1);
        if (col+1<n) solve(s+'R',n,a,row,col+1);
        if (row-1>=0) solve(s+'U',n,a,row-1,col);
        a[row][col]=1;
    }
    return;
}

int main()
{
    int n,k;
    cin>>n;
    vector<vector<int>> m;
    vector<int> b;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++) 
        {
            cin>>k;
            b.push_back(k);
        }
        m.push_back(b);
        b.clear();
    }
    solve("",n,m);
    for (int i=0;i<c.size();i++)
    {
        for (int j=0;j<c[i].size();j++)
        {
            cout<<c[i][j]<<" ";
        }
        cout<<"\n";
    }
    return 0;
}