#include<bits/stdc++.h>
using namespace std;

class long_sub
{
    public:
        int val;
        char t;
        long_sub *point;
};

int main()
{
    string a,b;
    cin>>a>>b;
    int n1=a.length(),n2=b.length();
    long_sub** arr = new long_sub*[n1+1];
    for (int i=0;i<n1+1;i++)
    {
        arr[i] = new long_sub[n2+1];
        arr[i][0].val=0;
    }
    for (int i=0;i<n2+1;i++)
    {
        arr[0][i].val=0;
    }
    for (int i=0;i<n1;i++) 
    {
        for (int j=0;j<n2;j++)
        {
            if (a[i]==b[j])
            {   
                arr[i+1][j+1].val=arr[i][j].val+1;
                arr[i+1][j+1].t=a[i];
                arr[i+1][j+1].point=(arr[i]+j);
            }
            else 
            {
                arr[i+1][j+1].val=max(arr[i][j+1].val,arr[i+1][j].val);
                if (arr[i][j+1].val>=arr[i+1][j].val) arr[i+1][j+1].point = (arr[i]+j+1);
                else arr[i+1][j+1].point=(arr[i+1]+(j));
            }
        }
    }
    long_sub *temp = arr[n1]+n2;
    string s="";
    while (temp->val)
    {
        if (temp->val>temp->point->val) s = temp->t+s;
        temp=temp->point;
    }
    cout<<s<<"\n"<<s.length();
    return 0;
}