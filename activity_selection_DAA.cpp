#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int arr[n],arr2[n],arr3[n];
    for (int i=0;i<n;i++) arr[i]=i;
    for (int i=0;i<n;i++) cin>>arr2[i];
    for (int i=0;i<n;i++) cin>>arr3[i];
    for (int i=1;i<n;i++)
    {
        int key=arr[i],key1=arr2[i],key2=arr3[i],j=i-1;
        while (j>=0 && arr3[j]>key2)
        {
            arr3[j+1]=arr3[j];
            arr2[j+1]=arr2[j];
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        arr2[j+1]=key1;
        arr3[j+1]=key2;
    }
    int temp=arr3[0];
    cout<<arr[0]<<"\n";
    for (int i=1;i<n;i++)
    {
        if (arr2[i]>=temp)
        {
            cout<<i<<"\n";
            temp=arr3[i];
        }
    }
    return 0;
}