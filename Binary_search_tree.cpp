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
void itrinsert(node* root,int key)
{
    node* prev;
    while(root!=NULL)
    {
        prev = root;
        if(key == root->val)
            return;
        else if(key<root->val)
        {
            root = root->left;
        }
        else
        {
            root = root->right;
        }
    }
    node *newnode = new node(key);
    if(key<prev->val)
    {
        prev->left = newnode;
    }
    else
    {
        prev->right = newnode;
    }
}
node* recinsert(node* root,int key)
{
    node* prev;
    if(root == NULL)
    {
        node *newnode = new node(key);
        return newnode;
    }
    else if(key<root->val)
    {
        root->left = recinsert(root->left,key);
    }
    else
    {
        root->right = recinsert(root->right,key);
    }
    return root;
}
node* in_order_precedence(node* temp)
{
    if(temp->right == NULL)
        return temp;
    return in_order_precedence(temp->right);
}
node* in_order_successor(node* temp)
{
    if(temp->left == NULL)
        return temp;
    return in_order_successor(temp->left);
}
node* delete_node(node* p,int key)
{
    if(p==NULL)
        return NULL;

    if(p->left == NULL && p->right == NULL)
    {
        free(p);
        return NULL;
    }
    if(key<p->val)
    {
        p->left = delete_node(p->left,key);
    }
    else if(p->val<key)
    {
        p->right = delete_node(p->right,key);
    }
    else
    {
        if(height(p->left) > height(p->right))
        {
            node* val1 = in_order_precedence(p->left);

            p->val = val1->val;
            p->left = delete_node(p->left,val1->val);

        }
        else
        {
            node* val1 = in_order_successor(p->right);

            p->val = val1->val;
            p->right = delete_node(p->right,val1->val);

        }
    }
    return p;
}

int main()
{
    run();
    node* root = new node(10);
    root->left = new node(8);
    root->left->left = new node(7);
    root->right = new node(15);
    root->right->left = new node(13);
    root->right->right = new node(19);
    //cout<<height(root)<<endl;
    itrinsert(root,1);
    itrinsert(root,11);
    itrinsert(root,22);
    itrinsert(root,17);
    itrinsert(root,16);
    levelorder_traversal(root);
    cout<<endl;
    delete_node(root,15);
    levelorder_traversal(root);
    return 0;
}