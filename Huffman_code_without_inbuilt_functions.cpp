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

class min_heap
{
    public:
        vector<node*> a;
        int s;
        min_heap() {
        s=0;
        }
        void push(node* t)
        {
            int i=0;
            for (;i<this->s;i++) if (a[i]->val<t->val) break;
            a.insert(a.begin()+i,t);
            this->s++;
        }
        node* top()
        {
            return this->a[s-1];
        }
        void pop()
        {
            a.pop_back();
            this->s--;
        }
        int size()
        {
            return this->s;
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
    int n;
    cin>>n;
    min_heap* temp = new min_heap();
    vector<string> s;
    node *head,*t1,*t2,*t3;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
        node* t = new node(arr[i]);
        t->ref='a'+i;
        temp->push(t);
    }
    while (temp->size()>1)
    {
        t1 = temp->top();
        temp->pop();
        t2 = temp->top();
        temp->pop();
        t3=new node(t1->val+t2->val);
        t3->left=t1;
        t3->right=t2;
        temp->push(t3);
    }
    head=t3;
    for (int i=0;i<n;i++)
    {
        search(i+'a',head,s);
        cout<<s[i]<<" ";
    }
    return 0;
}