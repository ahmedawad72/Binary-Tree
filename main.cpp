#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node* left;
    struct Node* right;

    Node(int d){
        data=d;
        left=right=NULL;
    }
};
void PreOrder_traversal(Node *root)     // DFS
{
    if(root==NULL) return;

    cout<<root->data<<' ';
    PreOrder_traversal(root->left);
    PreOrder_traversal(root->right);
}
void InOrder_traversal(Node *root)       // DFS
{
    if(root==NULL) return;

    InOrder_traversal(root->left);
    cout<<root->data<<' ';
    InOrder_traversal(root->right);
}
void PostOrder_traversal(Node *root)     // DFS
{
    if(root==NULL) return;

    PostOrder_traversal(root->left);
    PostOrder_traversal(root->right);
    cout<<root->data<<' ';
}
void LevelOrder_traversal(Node *root)
{
    if(root==NULL) return;

    queue<Node *> level_Nodes;
    level_Nodes.push(root);
    while(! level_Nodes.empty())
    {
        int size=level_Nodes.size();
     //   vector<int> level_data;
        for(int i=0; i<size;i++)
        {
            auto node = level_Nodes.front();
            level_Nodes.pop();
            if(node->left)
            {
                level_Nodes.push(node->left);
            }
            if(node->right)
            {
                level_Nodes.push(node->right);
            }
            cout<<node->data<<' ';
            //level_data.push_back(node->data);
        }
    }
}
int main()
{
    struct Node *root = new Node(7);
    root->left = new Node(6);
    root->right = new Node(5);
    root->left->left = new Node(4);
    root->left->right = new Node(3);
    root->right->left = new Node(2);
    root->right->right = new Node(1);

    cout<<"Pre Order Traversal\n";
    PreOrder_traversal(root);

    cout<<"\nIn Order Traversal\n";
    InOrder_traversal(root);

    cout<<"\nPost Order Traversal\n";
    PostOrder_traversal(root);

    cout<<"\Level Order Traversal\n";
    LevelOrder_traversal(root);

    return 0;
}
