#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,c3,c4,temp;
    cin>>n;
    vector<int> a1;
    int a[2][n],t[2][n-1],e[2],x[2],arr[2][n-1];
    for (int i=0;i<n;i++) cin>>a[0][i];
    for (int i=0;i<n;i++) cin>>a[1][i];
    for (int i=0;i<n-1;i++) cin>>t[0][i];
    for (int i=0;i<n-1;i++) cin>>t[1][i];
    cin>>e[0]>>e[1];
    cin>>x[0]>>x[1];
    int c1=e[0]+a[0][0],c2=e[1]+a[1][0];
    for (int i=0;i<n-1;i++)
    {
        int a2=c1+t[0][i]+a[1][i+1],b1=c2+a[1][i+1],a1=c1+a[0][i+1],b2=c2+t[1][i]+a[0][i+1];
        c3=min(a2,b1);
        c4=min(a1,b2);
        arr[0][i]=(a1>b2);
        arr[1][i]=(a2>b1);
        c2=c3,c1=c4;
    }
    c1+=x[0];
    c2+=x[1];
    temp =c1>c2;
    for (int i=n-2;i>-2;i--) 
    {
        a1.push_back(a[temp][i+1]);
        temp=arr[temp][i];
    }
    reverse(a1.begin(),a1.end());
    for (int i=0;i<n;i++) 
    {
        cout<<a1[i];
        if (i!=n-1) cout<<" - ";
    }
    cout<<"\n"<<min(c1,c2);
    return 0;
}
/*
5
8 10 4 5 9
9 6 7 5 6
2 3 1 3
2 1 2 2
3 5 
2 1
*/
