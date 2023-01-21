#include<bits/stdc++.h>
using namespace std;

bool safe(int n,string arr[],int r,int c)
{
    for (int i=0;i<n;i++) if (arr[i][c]=='Q') return false;
    int row=r,col=c;
    while (row>=0 && col<n)
    {
        if (arr[row][col]=='Q') return false;
        row--;
        col++;
    }
    while (r>=0 && c>=0)
    {
        if (arr[r][c]=='Q') return false;
        r--;
        c--;
    }
    return true;
}

void call(int n,string arr[],int r=1,int c=0)
{
    if (r==n)
    {
        for (int i=0;i<n;i++)
        {
            for (int j=0;j<n;j++)
                cout<<arr[i][j]<<" ";
            cout<<"\n";
        }
        cout<<"\n";
        return;
    }
    for (int i=c;i<n;i++)
    {
        if (safe(n,arr,r,i))
        {
            arr[r][i]='Q';
            call(n,arr,r+1);
            arr[r][i]='.';
        }
    }
}

int main()
{
    int n;
    cin>>n;
    string arr[n],s="";
    for (int i=0;i<n;i++) s+='.';
    for (int i=0;i<n;i++) arr[i]=s;
    for (int i=0;i<n;i++)
    {
        arr[0][i]='Q';
        call(n,arr);
        arr[0][i]='.';
    }
    return 0;
}