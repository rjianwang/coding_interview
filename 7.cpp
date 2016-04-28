#include <iostream>
#include <stack>
#include <assert.h>

template <typename T>
class CQueue
{
public:
	CQueue();
	~CQueue();

	void push(const T& node);
	T pop();

	bool empty();

private:
	std::stack<T> stack1;
	std::stack<T> stack2;
};

template <typename T>
CQueue<T>::CQueue()
{

}

template <typename T>
CQueue<T>::~CQueue()
{

}

template <typename T>
void CQueue<T>::push(const T& node)
{
	stack1.push(node);
}

template <typename T>
T CQueue<T>::pop()
{
	if (stack2.empty())
	{
		while (!stack1.empty())
		{
			T node = stack1.top();
			stack1.pop();
			stack2.push(node);
		}
	}

	if (stack2.empty())
		std::cout << "Queue is empty.";

	T node = stack2.top();
	stack2.pop();
	return node;
}

template <typename T>
bool CQueue<T>::empty()
{
	if (!stack1.empty() || !stack2.empty())
		return false;

	return true;
}

int main(int argc, char* argv[])
{
	CQueue<int>	 queue;

	queue.push(1);
	queue.push(2);
	queue.push(3);
	queue.push(4);
	queue.push(5);
	queue.pop();

	while (!queue.empty())
	{
		std::cout << queue.pop() << std::endl;
	}

	return 0;
}
