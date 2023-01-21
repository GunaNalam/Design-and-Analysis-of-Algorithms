#include <bits/stdc++.h>
using namespace std;

bool safe(int graph[101][101],int colour[],int col,int n,int node)
{
    for (int i=0;i<n;i++) 
    {
        if (i!=node && graph[node][i]==1 && colour[i]==col) return false;
    }
    return true;
}

bool solve(int graph[101][101],int colour[],int m,int n,int node=0)
{
    if (node==n) return true;
    for (int i=1;i<=m;i++)
    {
        if (safe(graph,colour,i,n,node))
        {
            colour[node]=i;
            if (solve(graph,colour,m,n,node+1)) return true;
            colour[node]=0;
        }
    }
    return false;
}

int main()
{
    int graph[101][101];
    for (int i=0;i<101;i++) 
        for (int j=0;j<101;j++) 
            graph[i][j]=0;
    int n,a,b,m;
    cin>>n;
    cin>>a>>b;
    while (a!=-1 && b!=-1) 
    {    
        graph[a][b]=1;
        graph[b][a]=1;
        cin>>a>>b;
    }
    cin>>m;
    int color[n]={0};
    if (solve(graph,color,m,n)) cout<<"Yes";
    else cout<<"No";
    return 0;
}

/*
4
0 1 
0 2
0 3
2 1
1 3
-1 -1
3
*/