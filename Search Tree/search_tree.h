#ifndef __SEARCHTREE__
#define __SEARCHTREE__

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using std::cout;
using std::cerr;
using std::cin;
using std::endl;
using std::string;

struct Node 
{
	int val;
	Node *left, *mid, *right;

	Node(int val) {this->val = val;}
};

class Tree
{
public:
	Tree();
	void Inorder();
	void insert(int );
	void remove(int );
	void Inorder(int );
	void Inorder(Node *);

	bool isLeafNode(Node *);
	bool isLeftChild(Node *);
	bool isRightChild(Node *);
	bool hasOneSibling(Node *);
	bool hasTwoSiblings(Node *);
	bool hasThreeSiblings(Node *);

	Node* getRoot();
	Node* find(int );
	Node* parent_node(Node *);
	Node* Inorder_predecessor(Node *);
	Node* Inorder_successor(Node *);

protected:
	Node *root;
};

#include "search_tree.cpp"

#endif