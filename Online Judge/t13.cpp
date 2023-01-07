#include <iostream>
#include <string>
using namespace std;

struct Node
{
	char value;
	Node* left;
	Node* right;
};

Node* createTree(string pre, string mid) {
	if (pre.size() == 0) return NULL;
	Node* root = new Node;
	root->value = pre[0];
	int pos = mid.find(pre[0]);
	root->left = createTree(pre.substr(1, pos), mid.substr(0, pos));
	root->right = createTree(pre.substr(pos + 1), mid.substr(pos + 1));
	return root;
}

void postOrder(Node* root) {
	if (root == NULL) return;
	postOrder(root->left);
	postOrder(root->right);
	cout << root->value;
}

int main() {
	string s1, s2;
	while (cin >> s1 >> s2) {
		Node* root = createTree(s1, s2);
		postOrder(root);
		cout << endl;
	}
}