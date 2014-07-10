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


void InsertNode(ListNode **pHead, int value) {
    ListNode *pNew = new ListNode();
    pNew->next = NULL;
    pNew->value = value;

    if(*pHead==NULL || (*pHead)->value > value) {
        pNew->next = (*pHead)->next;
        *pHead = pNew;
    }
    else {
        ListNode *pNode = *pHead;
        while(pNode->next != NULL && pNode->next->value <= value) {
            pNode = pNode->next;
        }

        if(pNode->next == NULL) {
            pNode->next = pNew;
        }
        else {
            pNew->next = pNode->next;
            pNode->next = pNew;
        }
    }
}


void PrintListReversingly_Iteratively(ListNode *pHead) {
    stack<ListNode *> nodes;
	ListNode *pNode = pHead;
	while(pNode != NULL)
	{
		nodes.push(pNode);
		pNode = pNode->next;
	}

	while(!nodes.empty())
	{
		pNode = nodes.top();
		cout << pNode->value << endl;
		nodes.pop();
	}
}

void Print_TailtoHead(ListNode *pHead) {
    ListNode *pNode = pHead;

    if(pNode != NULL) {
        Print_TailtoHead(pNode->next);
        cout<<pNode->value<<endl;
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

    InsertNode(&root, 0);
    InsertNode(&root, 4);
    InsertNode(&root, 6);

    PrintListReversingly_Iteratively(root);
    Print_TailtoHead(root);

    destroy(root);

	return 0;
}
