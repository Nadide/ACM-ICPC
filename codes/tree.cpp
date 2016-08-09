#include <iostream>
using namespace std;

struct node {
	int value;
	node *l, *r;
};

bool search (node *parent, int key)
{
	if (parent == NULL)		return false;
	if (parent->value == key)	return true;
	if (parent->value > key)	return search(parent->l, key);
	if (parent->value > key)	return search(parent->r, key);
}

node* insert (node *parent, int value) 
{
	if (parent == NULL) {
		parent = new node();
		parent->value = value;
		parent->l = parent->r = NULL;
	}
	else if (parent->value > value) 
		parent->l = insert (parent->l, value);
	else 
		parent->r = insert (parent->r, value);
}

void preorder (node *parent) {
// root, left, right
	cout << parent->value << " ";
	if (parent->l != NULL) preorder (parent->l);
	if (parent->r != NULL) preorder (parent->r);
}

void inorder (node *parent) {
// left, root, right
	if (parent->l != NULL) preorder (parent->l);
	cout << parent->value << " ";
        if (parent->r != NULL) preorder (parent->r);
}

void postorder (node *parent) {
// left, right, root
	if (parent->l != NULL) preorder (parent->l);
        if (parent->r != NULL) preorder (parent->r);
	cout << parent->value << " ";
}

int main ()
{
	int n, x;
	node *root = NULL;

	cin >> n;
	for (int i=0; i<n; ++i) {
		cin >> x;
		root = insert (root, x);
	}
	cout << root->value << endl;

	preorder (root); cout << endl;
	inorder  (root); cout << endl;  
	postorder(root); cout << endl;

	cin  >> x;
	cout << (search (root, x) ? "Exist" : "Non-Exist") << endl;
}
