#include<iostream>
using namespace std;
int mon[12] = { 0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334 };
int is(int year, int month, int day)
{
	return year * 365 + year / 4 - year / 100 + year / 400 + mon[month - 1] + day - 1 + (year / 100 != 0 && year / 4 == 0 || year / 400 == 0 && month>2);
}
int main()
{
	int i, j;
	int year1, month1, day1, year2, month2, day2;
	scanf("%4d%2d%2d", &year1, &month1, &day1);
	scanf("%4d%2d%2d", &year2, &month2, &day2);
	i = is(year1, month1, day1);
	j = is(year2, month2, day2);
	cout << abs(i - j) + 1 << endl;
	return 0;
}