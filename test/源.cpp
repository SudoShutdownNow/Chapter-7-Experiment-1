#include <iostream>
using namespace std;
int main()
{
    int n, n2;
    cout << "��������Ҫ�ֽ��������:";
        cin >> n;
    cout << n << "=";//������ں� 
    n2 = n;
    if (n < 2) {
        return 0;//nС��2�������� 
    }
    cout << "1*"; //��� 1* 
    for (int i = 2; i * i <= n2; i++)//forѭ�����������       
    {
        while (n2 % i == 0)//whileѭ���ж������� 
        {
            n2 = n2 / i;//��������� 
            cout << i;//���������� 
            //if (n2 != 1);//�ж������� 
                cout << "*";//����˺� 
        }
    }
    if (n2 != 1) {//�ж������� 
        cout << n2;//��������� 
    }
    return 0;//���� 
}