#include <bits/stdc++.h>
using namespace std;
int fact(int n)
{
    if (n==1 || n==0) return 1;
    return n*fact(n-1);
}

string func(string s,vector<int> a,int k,int n,int fac)
{
    if (n==1) 
    {
        s+=to_string(a[0]);
        return s;
    }
    int t = (k/fac);
    s+=to_string(a[t]);
    a.erase(a.begin()+t);
    return func(s,a,(k%fac),n-1,fac/(n-1));
}

int main()
{
    int n,k;
    cin>>n>>k;
    vector<int> a;
    for (int i=1;i<=n;i++) a.push_back(i);
    k--;
    cout<<func("",a,k,n,fact(n-1));
}

/*
1234


2134
*/