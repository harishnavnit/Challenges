#include "search_tree.h"

Node* Tree::getRoot()
{
	return root;
}

Tree::Tree() : root(NULL)
{
}

void Tree::Inorder(Node *node)
{
	if (node == NULL) {
		return;
	} else {
		Inorder(node->left);
		if (node->mid == NULL) {
			cout << node->val << " ";
		} else {
			while (1) {
				cout << node->val << " " ;
				if (node->mid != NULL)
					node = node->mid;
				else break;
			}
		}
		Inorder(node->right);
	}

	cout << endl;
}

void Tree::Inorder(int key)
{
	Node *new_node = new Node(key);
	Inorder(new_node);
}

void Tree::Inorder()
{
	Node *node = getRoot();
	Inorder(node);
}

bool Tree::isLeafNode(Node *node)
{
	if (node == NULL) return false;
	else
		return (node->left == NULL
			&& node->right == NULL
			&& node->mid   == NULL
		);
}

bool Tree::isLeftChild(Node *node)
{
	Node *parent = parent_node(node);
	Node *p_left = parent->left;

	if (node == NULL) return false;
	else {
		if (parent != NULL && p_left != NULL) {
			if (p_left->val == node->val) return true;
			else return false;
		} else return false;
		return false;
	}
}

bool Tree::isRightChild(Node *node)
{
	Node *parent = parent_node(node);
	Node *p_right = parent->right;

	if (node == NULL) return false;
	else {
		if (parent != NULL && p_right != NULL) {
			if (p_right->val == node->val) return true;
			else return false;
		} else return false;
		return false;
	}
}

bool Tree::hasOneSibling(Node *node)
{
	if (node == NULL) return false;
	else
		return (
				(node->left != NULL && node->mid == NULL && node->right == NULL)
			||	(node->left == NULL && node->mid != NULL && node->right == NULL)
			||	(node->left == NULL && node->mid == NULL && node->right != NULL)
		);
}

bool Tree::hasTwoSiblings(Node *node)
{
	if (node == NULL) return false;
	else
		return (
				(node->left != NULL && node->mid != NULL && node->right == NULL)
			||	(node->left != NULL && node->mid == NULL && node->right != NULL)
			|| 	(node->left == NULL && node->mid != NULL && node->right != NULL)
		);
}

bool Tree::hasThreeSiblings(Node *node)
{
	if (node == NULL) return false;
	else 
		return (
			(node->left != NULL && node->mid != NULL && node->right != NULL)
		);
}

Node * Tree::parent_node(Node *node)
{
	if (node == NULL) return NULL;

	Node *curr_node = getRoot();
	Node *prev_node = NULL;

	while (curr_node != NULL) {
		if (node->val == curr_node->val) {
			return prev_node;
		} else {
			prev_node = curr_node;
			if (node->val < curr_node->val) {
				curr_node = curr_node->left;
			} else if (node->val > curr_node->val) {
				curr_node = curr_node->right;
			} else if (node->val == curr_node->val) {
				curr_node = curr_node->mid;
			}
		}
	}
	return NULL;
}

Node* Tree::find(int val)
{
	Node *temp = getRoot();

	while (temp != NULL) {
		if (val == temp->val) return temp;
		else if (val < temp->val) {
			temp = temp->left;
		} else if (val > temp->val) {
			temp = temp->right;
		}
	}

	return NULL;
}

Node* Tree::Inorder_predecessor(Node *node)
{
	Node *curr = getRoot();
	Node *target = find(node->val);

	if (target != NULL) {
		if (target->left != NULL) {
			curr = target->left;
			while (curr->right != NULL) {
				curr = curr->right;
			}
		} else return Inorder_successor(node);
		return curr;
	} else return NULL;
}

Node* Tree::Inorder_successor(Node *node)
{
	Node *curr = getRoot();
	Node *target = find(node->val);

	if (target != NULL) {
		if (target->right != NULL) {
			curr = target->right;
			while (curr->left != NULL) {
				curr = curr->left;
			}
		} else return Inorder_predecessor(node);
		return curr;
	} else return NULL;
}

void Tree::insert(int val)
{
	Node *temp = getRoot();
	Node *node_to_be_inserted = new Node(val);

	if (temp == NULL) {
		root = node_to_be_inserted;
	} else {
		while (1) {
			if ( (temp != NULL) && (temp->val > val) ) {
				if (temp->left == NULL) {
					temp->left = node_to_be_inserted;
					break;
				} else {
					temp = temp->left;
				}
			} else if (temp->val < val) {
				if (temp->right == NULL) {
					temp->right = node_to_be_inserted;
					break;
				} else {
					temp = temp->right;
				}
			} else if (temp->val == val) {
				if (temp->mid == NULL) {
					temp->mid == node_to_be_inserted;
					break;
				} else {
					temp = temp->mid;
				}
			} else {
				cerr << "\nUnable to insert. Try again" << endl;
			}
		}
	}
	return;
}

void Tree::remove(int val)
{
	Node *target = find(val);
	Node *parent = parent_node(target);

	if (target->mid != NULL) {
		while (target->mid != NULL) {
			parent = target;
			target = target->mid;
		}
		parent->mid = NULL;
		delete target;
	}
	if (isLeafNode(target)) {
		if (isLeftChild(target)) {
			parent->left = NULL;
		} else if (isRightChild(target)) {
			parent->right = NULL;
		}/* else if (isMidChild(target)) {
			parent->mid = NULL;
		}*/
		delete target;
	} else if (hasOneSibling(target)) {
		if (target->left != NULL) {
			if (isLeftChild(target)) {
				parent->left = target->left;
			} else if (isRightChild(target)) {
				parent->right = target->right;
			} else if (target == getRoot()) {
				root = target->left;
			}
			delete target;
		} else {
			if (target->right != NULL) {
				if (isRightChild(target)) {
					parent->right = target->right;
				} else if (isLeftChild(target)) {
					parent->left = target->left;
				} else if (target == getRoot()) {
					root = target->right;
				}
			} else {
				cerr << "\nNo child nodes found." << endl;
			}
			delete target;
		} 
	} else if (hasTwoSiblings(target)) {
		int deletionFlag = 0;
		Node *ipORis = NULL;		//Holds the inorder predecessor or successor

		if (deletionFlag) {
			deletionFlag = 1;
			ipORis = Inorder_predecessor(target);
		} else {
			deletionFlag = 0;
			ipORis = Inorder_successor(target);
		}
		int ipORis_val = ipORis->val;
		delete ipORis;
		target->val = ipORis_val;
	}
}