#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
void shuixianhua(int num)
{
	int a;//��λ
	int b;//ʮλ
	int c;//��λ
	a = num / 100;
	b = (num % 100) / 10;
	c = num % 10;
	if (a*a*a + b*b*b + c*c*c == num)
	{
		printf("TRUE");
	}
	else
	{
		printf("FALSE");
	}
}
int sum()
{
	int sumQ = 0;//������
	int sumO = 0;//ż����
	for (int i = 0; i < 100; i = i + 2)
	{
		sumO = sumO + i;
	}
	for (int i = 1; i < 100; i = i + 2)
	{
		sumQ = sumQ + i;
	}
	return sumQ;
}
int jiechengsum()
{
	int sum = 1;
	for (int i = 1; i < 21; i++)
	{
		sum = sum + sum*i;
	}
	return sum;
}
int main()
{
	//shuixianhua(153);
	jiechengsum();
	/*sum();*/
	return 0;
}
class Dog
{
public:
	Dog(int name = GG, int color = green, int age = 3)
	{
		_name = name;
		_color = color;
		_age = age;
		cout << "�������" << endl;
	}
private:
	int _name;
	int _color;
	int _age;
};
int main()
{
	Dog d1;
	cout << d1.name << d1.color << d1.age << endl;
	return 0;
}