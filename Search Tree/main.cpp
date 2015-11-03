#include "search_tree.h"

#include <stdio.h>
#include <cstdlib>

using namespace std;

int main(int argc, char *argv[])
{
	int data;
	string cmd = "print";
	Tree *t = new Tree();
	vector<int> insertData, removeData;

	while (1) {
		cin >> cmd;
		if (cmd == "Insert" || cmd == "insert") cin >> data;
		if (cmd == "Remove" || cmd == "remove") cin >> data;

		if (cmd == "Insert" || cmd == "insert") {
			if (data == 'Y' || data == 'y') exit(0);
			insertData.push_back(data);
			for (int i = 0; i < insertData.size(); i++) {
				t->insert(insertData[i]);
			}
		} else if (cmd == "Remove" || cmd == "remove") {
			removeData.push_back(data);
			for (int i = 0; i < removeData.size(); i++) {
				t->remove(removeData[i]);
			}
		} else if (cmd == "Print" || cmd == "print") {
			t->Inorder();
		} else if (cmd == "Exit" || cmd == "exit") {
			break;
		} else {
			cerr << "Command unknown" << endl;
		}
	}

	return 0;
}