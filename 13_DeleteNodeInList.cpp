#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
	int value;
	ListNode *next;
};

ListNode *create_list(ListNode **root)
{
	ListNode *tmp = NULL, *head = NULL;
	int value;
	cin >> value;
	if (value == -1)
		return 0;
	head = new(ListNode);
	if (head == NULL) return 0;
	head->value = value;
	tmp = head;
	cin >> value;
	while (value != -1)
	{
		tmp->next = new(ListNode);
		tmp = tmp->next;
		tmp->value = value;
		cin >> value;
	}
	tmp->next = NULL;
	*root = head;
	return head;
}


void DeleteNode(ListNode **pHead, ListNode* pToBeDeleted) {
    if(pHead == NULL || pToBeDeleted == NULL)
        return;

    if(pToBeDeleted->next != NULL) {
        ListNode *pNext = pToBeDeleted->next;
        pToBeDeleted->value = pNext->value;
        pToBeDeleted->next = pNext->next;

        delete pNext;
        pNext = NULL;
    }
    else if(*pHead == pToBeDeleted) {
        *pHead = NULL;
        delete pToBeDeleted;
        pToBeDeleted = NULL;
    }
    else {
        ListNode *pNode = *pHead;
        while(pNode != NULL && pNode->next != pToBeDeleted) {
            pNode = pNode->next;
        }

        if(pNode == NULL) {
            return;
        }
        else {
            pNode->next = NULL;
            delete pToBeDeleted;
            pToBeDeleted = NULL;
        }
    }
}

void PrintList(ListNode *pHead) {
    ListNode *pNode = pHead;
    while(pNode != NULL) {
        cout<<pNode->value<<endl;
        pNode = pNode->next;
    }
}

void destroy(ListNode *pHead) {
	ListNode *tmp = NULL;

	while(pHead != NULL)
	{
		tmp = pHead->next;
		delete pHead;
		pHead = tmp;
	}
}


int main(void)
{

	ListNode *root = NULL;
	create_list(&root); //input 1, 2, 5, -1
    PrintList(root);
    DeleteNode(&root, root->next);
    PrintList(root);

    destroy(root);

	return 0;
}
