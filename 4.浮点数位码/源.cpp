#include <iostream>
using namespace std;

int mymain()
{
	int m = 0;
	long double temp;
	while (cin >> temp)
	{
		//cout << (m++ ? "\n" : "");
		if (temp == -1)
		{
			break;
		}
		char* p = (char*)&temp;
		for (int i = 0; i < sizeof(long double); ++i)
		{
			for (int j = 8; j > 0; --j)
			{
				cout << (*(p + i) >> j & 1);
			}
			if ((i+1) % (sizeof(long double)/2) == 0)
			{
				cout << endl;
			}
			else
			{
				cout << ",";
			}
		}
	}
	return 0;
}

int ans()//标答，sizeof(long double)在windows上是8，与标答中预期结果10不符
{
	int m = 0;
	for (long double d; cin >> d;)
	{
		cout << (m++ ? "\n" : "");
		char* p = (char*)&d;
		for (int i = 0; i < 10; i++)
		{
			for (int j = 7; j >= 0; --j)
				cout << (*(p + i) >> j & 1);
			cout << (i % 5 == 4 ? "\n" : ",");
		}
	}
	return 0;
}

int main()
{
	mymain();

}