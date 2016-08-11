// Lowest Common Ancestor
#include <iostream>
using namespace std;

struct node 
{
	int data;
	node *l, *r;
};


node* insert (node *root, int data) {
	if (root == NULL) {
		root = new node();
		root->data = data;
		root->l = root->r = NULL;
	}
	else if (data < root->data)
		root->l = insert (root->l, data);
	else 
		root->r = insert (root->r, data);

	return root;
}

int LCA (node *root, int data1, int data2) 
{
	if (root == NULL) return 0;
	if (root->data > data1 && root->data > data2) return LCA(root->l,data1,data2);
	if (root->data < data1 && root->data < data2) return LCA(root->r,data1,data2);
	return root->data;
}

int main () 
{
	int n,x,y;
	node *root = NULL;

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x;
		root = insert (root, x);
	}

	cin  >> x >> y;
	cout << LCA (root,x,y) << endl;
}
