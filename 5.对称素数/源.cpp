#include <iostream>
#pragma warning (disable : 4996)
using namespace std;

bool isPrime(int x)//�ж�һ�����ǲ�������
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
	char a[10], b[10],c[20];//aΪǰ��Σ�b���Σ�c��������
	sprintf(c, "%d", x);
	char* p = c;//pʼ��ָ��洢���������ֵ��ַ���c
	char* q = a;//q��ָ���ַ���a��ת¼ǰ���
	for (int i = 1; i <= strlen(c) / 2; i++)//��ǰ���ת¼��a��
	{
		*q = *p;
		q++;
		p++;
	}
	*q = 0;

	if (strlen(c) % 2 == 1)//������ֵ�λ���ǵ����Ļ���p��ǰŲһλ�Աܿ��м���
	{
		p++;
	}

	q = b;//ָ��q��ָ��b��ת¼����
	for (int i = ceil(strlen(c) / 2) + 1; i <= strlen(c); i++)//ת¼���ε�b��
	{
		*q = *p;
		q++;
		p++;
	}
	*q = 0;

	strrev(b);//�Ѻ��η�ת
	if (strcmp(a, b) == 0)//��ת����ĺ�����ǰ��ζԱ�
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