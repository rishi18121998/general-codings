#include<iostream>
#include<bits/stdc++.h>
typedef 	long long int 	ll;
#define 	mod 	1000000007
#define	rep(i,a,n)	for(int i=a;i<n;i++)
#define	all(v)	v.begin(),v.end()
#define	yes	std::cout<<"YES"
#define	no	std::cout<<"NO"
using	namespace	std;
void run()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
}
struct node{
    int val;
    node* left;
    node* right;
    node(int x)
    {
        val = x;
        left = NULL;
        right = NULL;
    }
};
void itrpre(node* root)
{
    node* t = root;
    stack<node*> s;
    while(!s.empty() || t!=NULL)
    {
        if(t!=NULL)
        {
            s.push(t);
            cout<<t->val<<" ";
            t = t->left;

        }
        else
        {
            t = s.top()->right;
            s.pop();

        }
        
    }
}
void itrinorder(node* root)
{
    stack<node*> s;
    node* t = root;
    while (!s.empty() || t!=NULL)
    {
        if(t!=NULL)
        {
            s.push(t);
            t = t->left;
        }
        else
        {
            cout<<s.top()->val<<" ";
            t = s.top()->right;
            s.pop();
        }
    }
}
void itrpostorder(node* root)
{
    node* t = root;
    stack<node*> s;
    while(!s.empty() || t!=NULL)
    {
        if(t!=NULL)
        {
            s.push(t);
            t = t->left;
        }
        else
        {
            t = s.top();
            if(t>0)
            {
                                
            }
        }
    }
}
void levelorder_traversal(node* root)
{
    queue<node*> q;
    q.push(root);
    while(!q.empty())
    {
        node* t = q.front();
        q.pop();
        cout<<t->val<<" ";
        if(t->left!=NULL)
            q.push(t->left);
        if(t->right!=NULL)
            q.push(t->right);
    }
}
void levelorder_traversal_2(node* root)
{
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty())
    {
        node* t = q.front();
        q.pop();
        if(t!=NULL)
        {
            cout<<t->val<<" ";
            if(t->left!=NULL)
                q.push(t->left);
            if(t->right!=NULL)
                q.push(t->right);
        }
        else if(!q.empty())
        {
            q.push(NULL);
            //level++ - yha tk next level khatam hoga
            
        }
    }
}
int count_nodes(node *root)
{
    int x,y;
    if(root!=NULL)
    {
        x = count_nodes(root->left);
        y = count_nodes(root->right);
        return x+y+1;
    }
    return 0; //if null return
}

int nodes_with_degree2(node *root)
{
    int x,y;
    if(root!=NULL)
    {
        x = nodes_with_degree2(root->left);
        y = nodes_with_degree2(root->right);
        if(root->left && root->right)
            return x+y+1;
        else
            return x+y;
    }
    return 0; //if null return
}
int height(node *root)
{
    int x,y;
    if(root!=NULL)
    {
        x = height(root->left);
        y = height(root->right);
        return x>y ? x+1:y+1;
    }
    return 0; //if null return
}
int count_leaf_node(node *root)
{
    int x,y;
    if(root!=NULL)
    {
        x = count_leaf_node(root->left);
        y = count_leaf_node(root->right);
        if(!root->left && !root->right)
            return x+y+1;
        else
            return x+y;
    }
    return 0; //if null return
}
int main()
{
    run();
    node* root = new node(10);
    root->left = new node(11);
    root->left->left = new node(7);
    root->right = new node(9);
    root->right->left = new node(15);
    root->right->right = new node(8);
    cout<<height(root)<<endl;
    cout<<nodes_with_degree2(root)<<endl;
    cout<<count_nodes(root)<<endl;
    itrpre(root);
    cout<<endl;
    levelorder_traversal(root);
    cout<<endl;
    itrinorder(root);
    cout<<endl;
    cout<<count_leaf_node(root);
    return 0;
}