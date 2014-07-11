#include <iostream>
using namespace std;

struct ListNode{
	int value;
	ListNode *next;
};

ListNode* FindKthToTail(ListNode *pHead, int k)
{
	if (pHead == NULL || k <= 0)
		return NULL;

	ListNode *pAhead = pHead;
	ListNode *pBehind = pHead;

	for (int i=0; i < k-1; i++)
	{
		if(pAhead->next != NULL)
			pAhead = pAhead->next;
		else
			return NULL;
	}

	while(pAhead->next != NULL)
	{
		pAhead = pAhead->next;
		pBehind = pBehind->next;
	}

	return pBehind;
}

int main()
{
	int n, k, tmp;
	while (cin >> n >> k)
	{
		if (n <= 0)
		{
			cout << "NULL" << endl;
			continue;
		}
		ListNode *root = new ListNode;
		cin >> tmp;
		root->value = tmp;
		root->next = NULL;
		ListNode *index = root;
		while (--n)
		{
			index->next = new ListNode;
			index = index->next;
			cin >> tmp;
			index->value = tmp;
			index->next = NULL;
		}
		index = root;

		cout<<FindKthToTail(root, k)->value<<endl;
	}

    return 0;
}
