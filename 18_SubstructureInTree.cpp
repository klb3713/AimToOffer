#include <iostream>
#include <queue>
#include <stack>

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

void CreateTree(BinaryTreeNode **root)
{
    BinaryTreeNode *pNode;
	queue<BinaryTreeNode *> Bqueue;

	int val;
	if(cin>>val && val != -1) {
		*root = new BinaryTreeNode(val);
		Bqueue.push(*root);
	}
	else {
		*root = NULL;
		return;
	}

	while(!Bqueue.empty()) {
		pNode = Bqueue.front();
		Bqueue.pop();
		if(cin>>val) {
            if(val != -1) {
                pNode->left = new BinaryTreeNode(val);
                Bqueue.push(pNode->left);
            }
		}
		else
            break;

		if(cin>>val) {
            if(val != -1) {
                pNode->right = new BinaryTreeNode(val);
                Bqueue.push(pNode->right);
            }
		}
		else
			break;
	}
}


int InOrderRecursion(BinaryTreeNode *root)
{
	if (root == NULL)
		return 0;
	InOrderRecursion(root->left);
	cout << root->value;
	InOrderRecursion(root->right);
	return 0;
}


int InOrderTraverse(BinaryTreeNode *root)
{
	stack<BinaryTreeNode *> stacks;
	BinaryTreeNode *index = root;

	while (index || !stacks.empty())
	{
		if (index)
		{
			stacks.push(index);
			index = index->left;
		}
		else
		{
			index = stacks.top();
			stacks.pop();
			if (index == NULL)
				return -1;
			cout << index->value;
			index = index->right;
		}
	}
	return 0;
}

int DeleteTree(BinaryTreeNode **root)
{
	if (*root == NULL)
		return 0;
	if ((*root)->left != NULL)
		DeleteTree(&((*root)->left));
	if ((*root)->right != NULL)
		DeleteTree(&((*root)->right));
	delete *root;
	return 0;
}

bool DoesTree1HaveTree2(BinaryTreeNode *root1, BinaryTreeNode *root2)
{
	// first to judge root2, then judge root1.
	//when they are NULL at the same time, exchange them will be wrong!
	if (root2 == NULL)
		return true;
	if (root1 == NULL)
		return false;
	if (root1->value != root2->value)
		return false;
	return DoesTree1HaveTree2(root1->left, root2->left) &&
		DoesTree1HaveTree2(root1->right, root2->right);
}


bool HasSubtree(BinaryTreeNode *root1, BinaryTreeNode *root2)
{
	bool result = false;
	if (root1 != NULL && root2 != NULL)
	{
		if (root1->value == root2->value)
			result = DoesTree1HaveTree2(root1, root2);
		if (!result)
			result = HasSubtree(root1->left, root2);
		if (!result)
			result = HasSubtree(root1->right, root2);
	}
	return result;
}


int main(void)
{
	bool TF;
	BinaryTreeNode *root1 = NULL, *root2 = NULL;
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);

	CreateTree(&root1);
	CreateTree(&root2);
	InOrderTraverse(root1);
	InOrderTraverse(root2);
	TF = HasSubtree(root1, root2);
	if (TF == true)
		cout << "YES" << endl;
	else
		cout << "NO" << endl;

	DeleteTree(&root1);
	DeleteTree(&root2);
	root1 = root2 = NULL;

	return 0;
}
