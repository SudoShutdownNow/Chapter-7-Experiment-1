#include <iostream>
#include <vector>
using namespace std;

vector<int> seperate(int target)
{
	vector<int> res;
	for (int i = 1; i <= target; i++)
	{
		if (target % i == 0)
		{
			res.push_back(i);
		}
	}
	return res;
}

int main()
{
	int temp;
	vector<int> sep;
	while (cin >> temp)
	{
		if (temp == -1)
		{
			break;
		}
		sep = seperate(temp);
		cout << temp << ": " << sep.size() << endl;
	}
}