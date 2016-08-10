
/*The tree node has data, left child and right child 
struct node
{
    int data;
    node* left;
    node* right;
};

*/
int height(node * root)
{
    if (root == NULL) 
        return -1;   
    int l = (height(root->left) + 1);
    int r = (height(root->right) + 1);
    return (l > r) ? (l) : (r) ;
}
