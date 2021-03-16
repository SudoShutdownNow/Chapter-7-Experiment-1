//set教程：https://www.cnblogs.com/caiyishuai/p/8646345.html
/*测试用例：1 10000 159667200 9696 38373635 1000000 479001600 3 -1
720 665280
* 
*/
#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

set<int> seperate(int x)//将某个数分解为n个因子相乘的格式
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
		for (int i = 2; i <= (x / 2); i++)//从2开始依次与x相除
		{
			if (x % i == 0)//如果可以整除，将该数字存入set中，并且x=x/i
			{
				res.insert(i);
				x /= i;
			}
		}
		res.insert(x);
		return res;
	}

}

bool isCouple(int a,int b)//两个数相乘是否为12!
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

void testmain()//用于调试的主函数
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
	while (cin >> temp)//循环输入
	{
		if (temp == -1)//检测到-1停止输入
		{
			break;
		}
		input.push_back(temp);
	}

	for (vector<int>::iterator itera = input.begin(); itera < input.end(); itera++)//双指针开始遍历配对
	{
		for (vector<int>::iterator iterb = itera + 1; iterb < input.end(); iterb++)
		{
			if (isCouple(*itera,*iterb) == true)//如果配对成功
			{
				res++;//res+1
				*itera = 0;//把两个配对过的数字全都改成0，确保每个数字全都只配对一次
				*iterb = 0;
				break;
			}
		}
	}

	cout << res;
	return res;
	
	
}