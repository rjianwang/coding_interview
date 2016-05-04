#include <iostream>
#include <stack>
#include <vector>

bool isRightOrder(std::vector<int> a, std::vector<int> b)
{
	if (a.size() == 0 || b.size() == 0)
		return false;

	if (a.size() != 0 && b.size() != 0 && a.size() == b.size())
	{
		std::stack<int> s;
		int i = 0, j = 0;

		while (j < b.size())
		{
			if (!s.empty() && s.top() == b[j])
				s.pop();
			else
			{
				while (i < a.size() && a[i] != b[j])
				{
					s.push(a[i]);
					i++;
				}
				if (i == a.size())
					return false;
			}

			j++;
		}
	}

	return true;
}

int main(int argc, char* argv[])
{
	std::vector<int> a(5);
	std::vector<int> b(5);

	for (int i = 0; i < 5; i++)
	{
		a[i] = i + 1;
		b[i] = 5 - i;
	}

	std::cout << isRightOrder(a, b) << std::endl;

	b[0] = 2;
	b[1] = 1;
	std::cout << isRightOrder(a, b) << std::endl;

	return 0;
}
