#include<queue>

/*
struct node
{
    int data;
    node* left;
    node* right;
}*/

void LevelOrder(node * root)
{  
  if (root == NULL) return;
        queue<node*> q;
        for (q.push(root); !q.empty(); q.pop()) {
                cout << q.front()->data << " ";
                if (q.front()->left) q.push(q.front()->left);
                if (q.front()->right) q.push(q.front()->right);
        }
}
