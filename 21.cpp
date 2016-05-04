#include <iostream>
#include <stack>

template<typename T>
class Stack
{
public:
	void push(T x);
	void pop();
	T top();
	T min();

private:
	int min_num;
	std::stack<T> s1;
	std::stack<T> s2;
};

template<typename T>
void Stack<T>::push(T x)
{
	if (s1.empty())
		min_num = x;
	if (x < min_num)
		min_num = x;

	s1.push(x);
	s2.push(min_num);
}

template<typename T>
void Stack<T>::pop()
{
	if (s1.empty())
		std::cout << "Stack is empty" << std::endl;

	s1.pop();
	s2.pop();

	min_num = s2.top();
}

template<typename T>
T Stack<T>::top()
{
	if (s1.empty())
		std::cout <<"Stack is empty." << std::endl;
	return s1.top();
}

template<typename T>
T Stack<T>::min()
{
	if (s1.empty())
		std::cout << "Stack is empty." << std::endl;
	return s2.top();
}

int main(int argc, char* argv[])
{
	Stack<int> s;
	s.push(3);
	s.push(4);
	s.push(1);
	s.push(2);

	std::cout << s.min() << std::endl;

	s.pop();
	s.pop();

	std::cout << s.min() << std::endl;

	return 0;
}
