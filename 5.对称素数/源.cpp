#include <iostream>
#pragma warning (disable : 4996)
using namespace std;

bool isPrime(int x)//判断一个数是不是质数
{
	for (int i = 2; i * i < x; i++)
	{
		if (x % i == 0)
		{
			return false;
			break;
		}
	}
	return true;
}

bool isSymmetry(int x)
{
	char a[10], b[10],c[20];//a为前半段，b后半段，c完整数字
	sprintf(c, "%d", x);
	char* p = c;//p始终指向存储有完整数字的字符串c
	char* q = a;//q先指向字符串a以转录前半段
	for (int i = 1; i <= strlen(c) / 2; i++)//将前半段转录到a中
	{
		*q = *p;
		q++;
		p++;
	}
	*q = 0;

	if (strlen(c) % 2 == 1)//如果数字的位数是单数的话，p向前挪一位以避开中间数
	{
		p++;
	}

	q = b;//指针q再指向b以转录后半段
	for (int i = ceil(strlen(c) / 2) + 1; i <= strlen(c); i++)//转录后半段到b中
	{
		*q = *p;
		q++;
		p++;
	}
	*q = 0;

	strrev(b);//把后半段反转
	if (strcmp(a, b) == 0)//反转过后的后半段与前半段对比
	{
		return true;
	}
	else
	{
		return false;
	}

}

int main()
{
	int temp;
	int res = 0;
	while (cin >> temp)
	{
		if (isPrime(temp) && isSymmetry(temp))
		{
			res++;
		}
	}
	cout << res;
	return res;
}