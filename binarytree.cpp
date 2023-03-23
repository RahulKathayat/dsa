#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int d)
    {
        data = d;
        left = NULL;
        right = NULL;
    }
};

void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

node *buildtree(node *root)
{
    int data;
    cout << "enter data : ";
    cin >> data;
    root = new node(data);
    if (data == -1)
    {
        return NULL;
    }
    cout << "value at left of " << data << endl;
    root->left = buildtree(root->left);
    cout << "value at right of " << data << endl;
    root->right = buildtree(root->right);
    return root;
}

void levelorder(node *root, vector<vector<int>> &ans)
{
    if (root == NULL)
    {
        return;
    }
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        vector<int> level;
        int s = q.size();
        for (int i = 0; i < s; i++)
        {
            node *nd = q.front();
            q.pop();
            if (nd->left)
            {
                q.push(nd->left);
            }
            if (nd->right)
            {
                q.push(nd->right);
            }
            level.push_back(nd->data);
        }
        ans.push_back(level);
    }
}


void morristrav(node* root){
    node* cur=root;
    while(cur!=NULL){
        if(cur->left==NULL){
            cout<<cur->data<<" ";
            cur=cur->right;
        }
        else{
            node* prev=cur->left;
            while(prev->right && prev->right!=cur){
                prev=prev->right;
            }
            if(prev->right==NULL){
                prev->right=cur;
                cur=cur->left;
            }
            else{
                prev->right=NULL;
                cout<<cur->data<<" ";
                cur=cur->right;
            }
        }
    }
}

int main()
{
    node *root = NULL;
    root = buildtree(root);
    cout << endl;
    inorder(root);
    cout << endl;
    preorder(root);
    cout << endl;
    postorder(root);
    cout << endl;
    vector<vector<int>> ans;
    levelorder(root, ans);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"inorder using morris traversal : ";
    morristrav(root);
    return 0;
}
// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1