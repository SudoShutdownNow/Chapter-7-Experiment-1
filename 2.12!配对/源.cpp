//set�̳̣�https://www.cnblogs.com/caiyishuai/p/8646345.html
/*����������1 10000 159667200 9696 38373635 1000000 479001600 3 -1
720 665280
* 
*/
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

set<int> seperate(int x)//��ĳ�����ֽ�Ϊn��������˵ĸ�ʽ
{
	set<int> res;
	if (x <= 1)
	{
		res.insert(1);
		return res;
	}
	else
	{
		res.insert(1);
		for (int i = 2; i <= (x / 2); i++)//��2��ʼ������x���
		{
			if (x % i == 0)//��������������������ִ���set�У�����x=x/i
			{
				res.insert(i);
				x /= i;
			}
		}
		res.insert(x);
		return res;
	}

}

bool isCouple(int a,int b)//����������Ƿ�Ϊ12!
{



	int multiple = a * b;
	set<int> sep = seperate(multiple);

	set<int>::iterator iter = sep.begin();
	for (int i = 1; i <= 12; i++)
	{
		if (iter != sep.end()&&*iter == i)
		{
			iter++;
		}
		else
		{
			return false;
			break;
		}
	}
	if (iter == sep.end())
	{
		return true;
	}
	else
	{
		return false;
	}

}

void testmain()//���ڵ��Ե�������
{
	vector<int> i;
	i.push_back(1);
	vector<int>::iterator itera = i.begin();
	vector<int>::iterator iterb = i.begin();
	i.erase(itera);
	system("pause");


	set<int> res = seperate(665280);
	for (set<int>::iterator iter = res.begin(); iter != res.end(); iter++)
	{
		cout << *iter << " ";
	}
	cout << endl;

	/*set<int> a;
	for (int i = 1; i <= 6; i++)
	{
		a.insert(i);
	}
	
	set<int> b;
	for(int i = 7; i <= 12; i++)
	{
		b.insert(i);
	}*/

	cout << isCouple(720,665281) << endl;
}

int main()
{
	//testmain();
	vector<int> input;

	int temp;
	int res = 0;
	while (cin >> temp)//ѭ������
	{
		if (temp == -1)//��⵽-1ֹͣ����
		{
			break;
		}
		input.push_back(temp);
	}

	for (vector<int>::iterator itera = input.begin(); itera < input.end(); itera++)//˫ָ�뿪ʼ�������
	{
		for (vector<int>::iterator iterb = itera + 1; iterb < input.end(); iterb++)
		{
			if (isCouple(*itera,*iterb) == true)//�����Գɹ�
			{
				res++;//res+1
				*itera = 0;//��������Թ�������ȫ���ĳ�0��ȷ��ÿ������ȫ��ֻ���һ��
				*iterb = 0;
				break;
			}
		}
	}

	cout << res;
	return res;
	
	
}