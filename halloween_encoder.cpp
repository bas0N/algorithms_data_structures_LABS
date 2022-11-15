#include <iostream>
#define COUNT 10
#include <vector>
#include <set>
#include <algorithm>


using namespace std;

//define necessary data structures
class Data {
public:
	char letter;
	int occurence;
	string translation;
	Data(char c, int occ) {
		letter = c;
		occurence = occ;
		translation = "";

	}
};
class Node {
public:
	char letter;
	int occurence;
	Node* left;
	Node* right;

	// Val is the key or the value that
	// has to be added to the data part
	Node(char c, int occ)
	{
		letter = c;
		occurence = occ;

		// Left and right child for node
		// will be initialized to null
		left = NULL;
		right = NULL;
	}
	Node( int occ)
	{
		occurence = occ;
		letter = ' ';
		// Left and right child for node
		// will be initialized to null
		left = NULL;
		right = NULL;
	}


	
};
// Function to print binary tree in 2D
// It does reverse inorder traversal
//credit: https://www.geeksforgeeks.org/print-binary-tree-2-dimensions/
void print2DUtil(Node* root, int space)
{
	// Base case
	if (root == NULL)
		return;

	// Increase distance between levels
	space += COUNT;

	// Process right child first
	print2DUtil(root->right, space);

	// Print current node after space
	// count
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << root->occurence<<" "<<root->letter << "\n";

	// Process left child
	print2DUtil(root->left, space);
}

// Wrapper over print2DUtil()
void print2D(Node* root)
{	
	cout << endl;
	cout << "TREE VISUALISATION" << endl;
	// Pass initial space count as 0
	print2DUtil(root, 0);
	cout << endl;

}

//recursive method allowing to find a 'path' to a letter inside of a tree
string findLetter(Node root,char c) {
	if (root.left->letter == c) {
		
		return "0";
	}
	else {
		if (root.right->letter == c) {
			return"1";
		}
		else {
			return '1' + findLetter(*root.right, c);
		}
	
	}
	
	
}
//for object sorting
//credit: https://stackoverflow.com/a/1380496
struct less_than_key
{
	inline bool operator() (const Data& val1, const Data& val2)
	{
		return (val1.occurence > val2.occurence);
	}
};
//general method for outputing encoded string
void encodeString(string input) {
	vector <Data> vectorOfData;
	set<char> s;

	// Traverse the Vector
	for (char x : input) {

		// Insert each element
		// into the Set
		s.insert(x);
	}
	cout << "Set of letters: ";
	for (int x : s) {
		cout << char(x) << " ";
	}
	cout << endl;
	//count the occurence of each letter
	for (char x : s) {
		int count = 0;
		for (char y : input) {
			if (y == x) {
				count = count + 1;
			}

		}
		//push the data to the vector
		vectorOfData.push_back(Data(x, count));
	}
	//sort the data
	std::sort(vectorOfData.begin(), vectorOfData.end(), less_than_key());




	for (Data lo : vectorOfData) {
		string times = (lo.occurence > 1) ? " times" : " time";
		cout << "letter: " << lo.letter << " occurs: " << lo.occurence << times << endl;
	}
	int lastIndex2 = vectorOfData.size() - 1;
	//cout << "the size is: " << lastIndex2 <<"and first el is: "<<vectorOfData[0].letter<<"occurs : "<<vectorOfData[0].occurence << endl;

	Node* rightSide2 = new  Node(vectorOfData[lastIndex2].letter, vectorOfData[lastIndex2].occurence);
	lastIndex2 = lastIndex2 - 1;
	//create the tree
	while (lastIndex2 >= 0) {
		int newRootOccurence = vectorOfData[lastIndex2].occurence + rightSide2->occurence;
		//create new root with value of right side and value from array
		Node* newRoot = new Node(newRootOccurence);
		if (rightSide2->occurence >= vectorOfData[lastIndex2].occurence) {
			newRoot->right = rightSide2;
			newRoot->left = new Node(vectorOfData[lastIndex2].letter, vectorOfData[lastIndex2].occurence);
		}//2nd case value from array is greater
		else {
			newRoot->right = new Node(vectorOfData[lastIndex2].letter, vectorOfData[lastIndex2].occurence);
			newRoot->left = rightSide2;
		}

		rightSide2 = newRoot;
		lastIndex2 = lastIndex2 - 1;
	}
	//print the tree created
	print2D(rightSide2);

	int iterator = 0;
	for (Data data : vectorOfData) {
		string path = findLetter(*rightSide2, data.letter);
		vectorOfData[iterator].translation = path;
		iterator++;
	}
	cout << "DICTIONARY" << endl;
	for (Data data : vectorOfData) {

		cout << data.letter << " : " << data.translation << endl;
	}
	cout << endl;
	//
	//
	//
	//decoding part
	cout << "input: " << input << endl;
	cout << "encoded string: ";
	for (char x : input) {

		for (Data y : vectorOfData) {
			if (y.letter == x) {
				cout << y.translation;
			}
		}

	}
}
int main()
{
	bool execute = true;
	while (execute) {
	string command = "";
	cout << "\nParty Invitation Encoder" << endl << endl;
	cout << "Press char on the keyboard and click enter: " << endl<<endl;
	cout << "   i - enter the input" << endl<<endl;
	cout << "   x - exit the program" << endl << endl;

	cin >> command;
	if (command == "x") {
		execute = false;
	}
	else if (command == "i") {
		cout << "Enter your input: " << endl;
		cin >> command;
		encodeString(command);
	}
	else {
		cout << "Invalid command, try one more time!" << endl << endl << endl;

	}
}
	

	return 0;
}
