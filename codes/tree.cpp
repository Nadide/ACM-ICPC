#include <iostream>
#include <queue>
using namespace std;

struct node {
	int value;
	node *l, *r;
};

bool search (node *root, int key)
{
	if (root == NULL)		return false;
	if (root->value == key)	return true;
	if (root->value > key)	return search(root->l, key);
	if (root->value > key)	return search(root->r, key);
}

node* insert (node *root, int value) 
{
	if (root == NULL) {
		root = new node();
		root->value = value;
		root->l = root->r = NULL;
	}
	else if (root->value > value) 
		root->l = insert (root->l, value);
	else 
		root->r = insert (root->r, value);
}

void preorder (node *root) {
// root, left, right
	cout << root->value << " ";
	if (root->l != NULL) preorder (root->l);
	if (root->r != NULL) preorder (root->r);
}

void inorder (node *root) {
// left, root, right
	if (root->l != NULL) preorder (root->l);
	cout << root->value << " ";
        if (root->r != NULL) preorder (root->r);
}

void postorder (node *root) {
// left, right, root
	if (root->l != NULL) preorder (root->l);
        if (root->r != NULL) preorder (root->r);
	cout << root->value << " ";
}

void levelorder (node *root) {
	if (root == NULL) return;
	queue<node*> q;
	for (q.push(root); !q.empty(); q.pop()) {
		cout << q.front()->value << " ";
		if (q.front()->l) q.push(q.front()->l);
		if (q.front()->r) q.push(q.front()->r);
	}
}

int height (node *root) {
	if (root == NULL) return 0;
	int l = height(root->l);
	int r = height(root->r);
	return (l > r) ? (l+1) : (r+1); 
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

	// height of tree
	cout << "Height: " << height (root) << endl;
	
	// print orders
	cout << "Preorder:   "; preorder (root); cout << endl;
	cout << "Inorder:    "; inorder  (root); cout << endl;  
	cout << "Postorder:  "; postorder(root); cout << endl;
	cout << "Levelorder: "; levelorder (root); cout << endl;
	
	// look for x
	cout << "Search for: "; cin  >> x; 
	cout << (search (root, x) ? "Exist" : "Non-Exist") << endl;
}
