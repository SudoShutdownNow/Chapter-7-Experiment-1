#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> seperate(int x)//用于分解因子
{
	vector<int> res;
	for (int i = 1; i <= x / 2; i++)
	{
		if (x % i == 0)
		{
			res.push_back(i);
		}
	}
	return res;
}

vector<int> primeSeperate(int x)//分解质因数并以向量形式返回，这个程序里用不到
{
	vector<int> res;
	if (x < 2)//小于2直接返回它本身
	{
		res.push_back(x);
	}
	else
	{
		res.push_back(1);
		for (int i = 2; i * i <= x; i++)
		{
			while (x % i == 0)
			{
				x =x/ i;
				res.push_back(i);
			}
		}
		if (x != 1)
		{
			res.push_back(x);
		}
	}
	return res;
}

bool isGoodNum(int x)
{
	vector<int> seperateRes = seperate(x);
	int sum = 0;
	for (vector<int>::iterator iter = seperateRes.begin(); iter != seperateRes.end(); iter++)
	{
		sum += *iter;
	}

	if (sum == x)
	{
		return true;
	}
	else
	{
		return false;
	}
}

vector<int> getGoodNum(int x)
{
	vector<int> res;
	for (int i = 2; i <= x; i++)
	{
		if (isGoodNum(i))
		{
			res.push_back(i);
		}
	}
	return res;
}

int main()
{
	//cout << isGoodNum(28)<<endl;
	int temp;
	while (cin >> temp)
	{
		if (temp == -1)
		{
			break;
		}
		vector<int>res = getGoodNum(temp);
		cout << temp << ":";
		for (vector<int>::iterator iter = res.begin(); iter != res.end(); iter++)
		{
			cout << " " << *iter;
		}
	}
	return 0;
}
