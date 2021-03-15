#include <iostream>
using namespace std;
int main()
{
    int n, n2;
    cout << "请输入需要分解的质因数:";
        cin >> n;
    cout << n << "=";//输出等于号 
    n2 = n;
    if (n < 2) {
        return 0;//n小于2返回自身 
    }
    cout << "1*"; //输出 1* 
    for (int i = 2; i * i <= n2; i++)//for循环穷举质因数       
    {
        while (n2 % i == 0)//while循环判断质因数 
        {
            n2 = n2 / i;//获得质因数 
            cout << i;//返回质因数 
            //if (n2 != 1);//判断质因数 
                cout << "*";//输出乘号 
        }
    }
    if (n2 != 1) {//判断质因数 
        cout << n2;//输出质因数 
    }
    return 0;//返回 
}