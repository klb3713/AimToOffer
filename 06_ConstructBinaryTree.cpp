#include <iostream>
#include <vector>
#include <stdexcept>
using namespace std;

struct BinaryTreeNode
{
	int value;
	BinaryTreeNode *left;
	BinaryTreeNode *right;

	BinaryTreeNode(int val) {
        value = val;
        left = NULL;
        right = NULL;
	}
};

BinaryTreeNode* ConstructTree(vector<int>::const_iterator prebeg,
				  vector<int>::const_iterator preend,
				  vector<int>::const_iterator inbeg,
				  vector<int>::const_iterator inend)
{
	BinaryTreeNode *root = new BinaryTreeNode(*prebeg);

	if (prebeg == preend)
	{
		if (inbeg == inend && *inbeg == *prebeg)
			return root;
		else
			throw runtime_error("Invalid input.");
	}

	vector<int>::const_iterator index;

	index = inbeg;
	while(*index != root->value && index != inend)
		index ++;
	if (index == inend && *index != root->value)
		throw runtime_error("Invalid input.");

	int leftlength = index - inbeg;

	if (leftlength > 0)
	{
		root->left = ConstructTree(prebeg + 1, prebeg + leftlength, inbeg, index - 1);
	}
	if (inend > index)
	{
		root->right = ConstructTree(prebeg + leftlength + 1, preend, index + 1, inend);
	}

	return root;
}

int AfterOrder(BinaryTreeNode *root)
{
	if (root == NULL)
		return 0;
	if (root->left)
		AfterOrder(root->left);
	if (root->right)
		AfterOrder(root->right);
	cout << root->value << " ";
	return 0;
}


int main(void)
{
	int n, i = 0;

	while (cin >> n)
	{
		vector<int> preorder(n);
		vector<int> inorder(n);
		i = 0;
		while (i < n)
		{
			cin >> preorder[i];
			i ++;
		}
		i = 0;
		while (i < n)
		{
			cin >> inorder[i];
			i ++;
		}

		if (n == 0)
		{
			cout << "No" << endl;
			continue;
		}

		BinaryTreeNode *root;
		vector<int>::const_iterator prebeg = preorder.begin();
		vector<int>::const_iterator preend = preorder.end();
		vector<int>::const_iterator inbeg = inorder.begin();
		vector<int>::const_iterator inend = inorder.end();
		root = ConstructTree(prebeg, preend-1, inbeg, inend-1);
		if (root == NULL)
			continue;

		AfterOrder(root);

		cout << endl;
	}

	return 0;
}
