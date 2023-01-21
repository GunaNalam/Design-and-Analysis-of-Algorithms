#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,j,weight;
    cin>>n;
    int v[n],key,index[n];
    float arr[n],w[n],x[n],key1;
    for (int i=0;i<n;i++) cin>>v[i];
    for (int i=0;i<n;i++) cin>>w[i];
    cin>>weight;
    for (int i=0;i<n;i++)
    {
        arr[i]=(v[i]/w[i]);
        index[i]=i;
        x[i]=0;
    }
    for (int i=1;i<n;i++)
    {
        j=i-1;
        key1=arr[i];
        key=index[i];
        while (j>=0 && arr[j]>key1)
        {
            arr[j+1]=arr[j];
            index[j+1]=index[j];
            j--;
        }
        arr[j+1]=key1;
        index[j+1]=key;
    }
    for (int i=n-1;i>=0;i--)
    {
        int t = index[i];
        if (weight)
        {
            if (weight>=w[t]) x[t]=1; 
            else  x[t]=weight/w[t];
            weight-=x[t]*w[t];
        }
        else break;
    }
    for (int i=0;i<n;i++) cout<<x[i]<<" ";
    return 0; 
}

/*
7
10 5 15 7 6 18 3
2 3 5 7 1 4 1
15
*/