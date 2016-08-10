/*
struct node
{
    int data;
    node* left;
    node* right;
};

*/

void left_order(node * root){
    if (!root) return;
    left_order(root->left);    
    cout << root->data << " ";
}

void right_order(node * root){
    if (!root) return;
    cout << root->data << " ";
    right_order(root->right);
}

void top_view (node * root){
    left_order(root->left);
    cout << root->data << " ";
    right_order(root->right);  
}
