#include <iostream>
#include <vector>
#include <stack>
#include <string>
#include <stdexcept>

using namespace std;

int push(stack<int> &stack1, int num)
{
	stack1.push(num);
	return 0;
}

int pop(stack<int> &stack1, stack<int> &stack2)
{
	int num;
	if (!stack2.empty())
	{
		num = stack2.top();
		stack2.pop();
		return num;
	}
	if (stack1.empty())
		return -1;
	while (!stack1.empty())
	{
		num = stack1.top();
		stack2.push(num);
		stack1.pop();
	}
	stack2.pop();
	return num;

}

template <typename T> class CQueue {
public:
	CQueue() {};
	~CQueue() {};

	void push(const T& node);
	T pop();

private:
	stack<T> stack1;
	stack<T> stack2;
};


template<typename T> void CQueue::push(const T& node) {
	stack1.push(node);
}


template<typename T> T CQueue::pop() {
    if(stack2.empty()) {
		while(!stack1.empty()) {
			stack2.push(stack1.top());
			stack1.pop();
		}
	}
	if(stack2.empty()) {
		throw runtime_error("The Queue is empty.");
	}


	T node = stack2.top();
	stack2.pop();

	return node;
}


int main(void)
{
    /*int n, num;
	string cmds;
	stack<int> stack1;
	stack<int> stack2;
	cin >> n;
	while (n --)
	{
		cin >> cmds;
		if (cmds == "PUSH")
		{
			cin >> num;
			push(stack1, num);
		}
		if (cmds == "POP")
		{
			num = pop(stack1, stack2);
			cout << num << endl;
		}
	}*/

	cin >> n;
	CQueue<int> myQueue;
	myQueue.push(1);
	myQueue.push(3);
	myQueue.pop();
	myQueue.push(4);
	myQueue.push(5);
	myQueue.pop();
	myQueue.pop();
	myQueue.pop();
	myQueue.pop();

	return 0;
}