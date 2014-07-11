#include <iostream>
#include <stack>

using namespace std;

template <typename T>
class StackWithMin {
public:
	void push(const T& value);
	void pop();
	const T& top() const;
	const T& min() const;
private:
	typename stack<T> m_data;
	typename stack<T> m_min;
};

template <typename T> void StackWithMin<T>::push(const T& value) {
	m_data.push(value);
	if(m_min.empty() || value < m_min.top())
		m_min.push(value);
	else
		m_min.push(m_min.top());
}

template <typename T> void StackWithMin<T>::pop() {
	if(!m_data.empty() && !m_min.empty()) {
		m_data.pop();
		m_min.pop();
	}
}

template <typename T> const T& StackWithMin<T>::top() const {
	if(!m_data.empty() && !m_min.empty()) {
		return m_data.top();
	}
}

template <typename T> const T& StackWithMin<T>::min() const {
	if(!m_data.empty() && !m_min.empty()) {
		return m_min.top();
	}
}

int main(void)
{
	StackWithMin<int> min_stack;
	min_stack.push(3);
	min_stack.push(4);
	min_stack.push(2);
	min_stack.push(1);
	cout<<min_stack.min();
	min_stack.pop();
	cout<<min_stack.min();
	cout<<min_stack.top();
    return 0;
}