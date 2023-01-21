#include<bits/stdc++.h>
using namespace std;

bool isSmaller(string str1, string str2)
{
    int n1 = str1.length(), n2 = str2.length();
    if (n1 < n2) return true;
    if (n2 < n1) return false;
 
    for (int i = 0; i < n1; i++)    
    if (str1[i] < str2[i]) return true;
    else if (str1[i] > str2[i]) return false;
    return false;
}

void equal(string &a,string &b)
{
    int l1=a.length(),l2=b.length();
    if (l1!=l2)
    {
        if (l1>l2) for (int i=0;i<l1-l2;i++) b='0'+b;
        else for (int i=0;i<l2-l1;i++) a='0'+a;
    }
}

string subtract(string a,string b)
{
    equal(a,b);
    int borrow=0,n=a.length();
    char t;
    string res="";
    for (int i=n-1;i>=0;i--)
    {
        if ((a[i]-'0')-borrow>=(b[i]-'0')) 
        {
            t = (((a[i]-'0')-borrow)-(b[i]-'0'))+'0';
            res = t + res;
            borrow=0;
        }   
        else 
        {
            t = (((a[i]-'0')-borrow)-(b[i]-'0')+10)+'0';
            res = t + res;
            borrow=1;
        }
    }
    return res;
}

string add(string a,string b)
{
    int c=0;
    string res="";
    char temp;
    equal(a,b);
    int l1=a.length();
    for (int i=l1-1;i>=0;i--)
    {
        int ct=((a[i]-'0')+(b[i]-'0'));
        char t = (ct+c)%10 +'0';
        res = t + res;
        c=(ct+c)/10;
    }
    temp = c+'0';
    if (c)
    {
        res = temp + res;
    }
    return res;
}

string power(int n)
{
    string s="";
    for (int i=0;i<n;i++) s+='0';
    return s;
}

string multiply1(string a,string b)
{
    if (a.length()==b.length() && a.length()==1)
    {
        return to_string((a[0]-'0')*(b[0]-'0'));
    }
    equal(a,b);
    if (a.length()%2!=0) a = '0'+ a;
    if (b.length()%2!=0) b = '0'+ b;
    int n=a.length();
    string ah="",al="",bh="",bl="";
    for (int i=0;i<(n/2);i++)
    {
        ah+=a[i];
        al+=a[(n/2)+i];
        bh+=b[i];
        bl+=b[(n/2)+i];
    }
    string c0=multiply1(al,bl);
    string c1=multiply1(ah,bh);
    string c2=subtract(multiply1(add(al,ah),add(bl,bh)),add(c1,c0));
    return add(add(c1+power(n),c2+power(n/2)),c0);
}

int main()
{
    string a,b;
    cin>>a>>b;
    equal(a,b);
    int i=0,n;
    string t = multiply1(a,b),res="";
    n=t.length();
    while (t[i]=='0') i++;
    while (i<n)
    {
        res+=t[i];
        i++;
    }
    if (res=="") res='0';
    cout<<res;  
    return 0;
}