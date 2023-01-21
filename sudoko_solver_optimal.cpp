#include <bits/stdc++.h>
using namespace std;

bool safe(int n,vector<vector<char>> s,int r,int c,char num)
{
     for (int i=0;i<9;i++)
        {
            if (s[r][i]==num) return false; 
            if (s[i][c]==num) return false; 
            if (s[(r/n)*n+i/3][(c/n)*n+i%3]==num) return false;
        }
        return true;
}

vector<vector<char>> a;

bool queen(int n,vector<vector<char>> &s)
{
    for (int i=0;i<n*n;i++)
    {
        for (int j=0;j<n*n;j++)
        {
            if (s[i][j]=='.')
            {
                for (char k='1';k<='9';k++)
                {
                    if (safe(n,s,i,j,k))
                    {
                        s[i][j]=k;
                        if (queen(n,s)) return true;
                        else s[i][j]='.'; 
                    }
                }
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int n;
    cin>>n;
    vector<vector<char>> s;
    vector<char> temp;
    char t;
    for (int i=0;i<(n*n);i++)
    {
        for (int j=0;j<(n*n);j++)
        {
            cin>>t;
            temp.push_back(t);
        }
        s.push_back(temp);
        temp.clear();
    }
    queen(n,s);
    for (int i=0;i<(n*n);i++)
    {
        for (int j=0;j<(n*n);j++)
        {
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

/*
3
5 3 . . 7 . . . .
6 . . 1 9 5 . . .
. 9 8 . . . . 6 .
8 . . . 6 . . . 3
4 . . 8 . 3 . . 1
7 . . . 2 . . . 6
. 6 . . . . 2 8 .
. . . 4 1 9 . . 5
. . . . 8 . . 7 9
*/