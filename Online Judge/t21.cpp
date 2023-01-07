#include <iostream>
#include <vector>
using namespace std;

template <class T>
struct BSTNode {
	T value;
	BSTNode *left, *right;
	int size;
};

template <class T>
class BSTree {
public:
	BSTree() { root = NULL; }
	void insert(T value) { insert(root, value); }
	int find(T value) { return find(root, value); }
private:
	BSTNode<T>* root;
	void insert(BSTNode<T>*& node, T value);
	int find(BSTNode<T>* node, T value);
	int size(BSTNode<T>* node);
};

template <class T>
void BSTree<T>::insert(BSTNode<T>*& node, T value) {
	if (node == NULL) {
		node = new BSTNode<T>;
		node->value = value;
		node->left = node->right = NULL;
		node->size = 1;
	}
	else {
		node->size++;
		if (value < node->value)
			insert(node->left, value);
		else
			insert(node->right, value);
	}
}

template <class T>
int BSTree<T>::find(BSTNode<T>* node, T value) {
	int index = 0;
	while (node != NULL) {
		if (value < node->value) {
			node = node->left;
		}
		else if (node->value < value) {
			index += size(node->left) + 1;
			node = node->right;
		}
		else {
			index += size(node->left);
			return index;
		}
	}
	return -1;
}

template <class T>
int BSTree<T>::size(BSTNode<T>* node) {
	if (node == NULL)
		return 0;
	else
		return node->size;
}

int main() {
	BSTree<int> tree;
	int n;
	cin >> n;
	vector<int> op(n), val(n);
	for (int i = 0; i < n; i++) {
		cin >> op[i] >> val[i];
	}
	for (int i = 0; i < n; i++) {
		if (op[i] == 1) tree.insert(val[i]);
		if (op[i] == 2) cout << tree.find(val[i]) << endl;
	}
}