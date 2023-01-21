#include<bits/stdc++.h>
using namespace std;


class node
{
    public:
        int val;
        char ref;
        node *right,*left;
        node(int v)
        {
            val=v;
            right=nullptr;
            left=nullptr;
        }
};

class compare
{
    public:
        bool operator()(node* a,node *b)
        {
            if (a->val>b->val) return true;
            return false;
        }
};

void search(char val,node* head,vector <string> &t,string s="")
{
    if (head==nullptr) return;
    if(head->ref==val)
    {
        t.push_back(s);
        return;
    }
    search(val,head->left,t,s+'0');
    search(val,head->right,t,s+'1');
}

int main()
{
    int n,c=0;
    cin>>n;
    priority_queue<node*,vector<node*>,compare> temp;
    vector<string> s;
    node* head,*t1,*t2,*t3;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
        node* t = new node(arr[i]);
        t->ref='a'+i;
        temp.push(t);
    }
    while (temp.size()>1)
    {
        c++;
        t1 = temp.top();
        temp.pop();
        t2 = temp.top();
        temp.pop();
        t3=new node(t1->val+t2->val);
        t3->left=t1;
        t3->right=t2;
        temp.push(t3);
    }
    head=t3;
    for (int i=0;i<n;i++)
    {
        search(i+'a',head,s);
        cout<<s[i]<<" ";
    }
    return 0;
}