#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

using namespace std;

bool treeOrNot(multimap<char, char> );

int main(int argc, char *argv[])
{
	char source, dest;
	multimap<char, char> edgeList;
	multimap<char, char> :: iterator it;

	while (1) {
		cin >> source >> dest;
		if (source == 'q' || dest == 'q') break;
		else edgeList.insert(pair<char, char>(source, dest));
	}

	cout << "\nList of edges " << endl;
	for (it = edgeList.begin(); it != edgeList.end(); ++it)
		cout << it->first << " -> " << it->second << endl;

	if (treeOrNot(edgeList))
		cout << "\nThe input graph is not a tree" << endl;
	else cout << "\nThe input graph is a tree" << endl;

	return 0;
}

bool treeOrNot(multimap<char, char> el)
{
	bool notATree = false;
	for (multimap<char, char> :: iterator itr = el.begin(); itr != el.end(); itr++) {
		for (multimap<char, char> :: iterator oneMore = ++itr; oneMore != el.end(); ++oneMore) {
			if (itr->second == oneMore->second)
				notATree = true;
			if (itr->first == oneMore->first)
				notATree = true;
		}
	}

	cout << ((notATree) ? "\nTrue\n" : "\nFalse\n");
	return notATree;
}