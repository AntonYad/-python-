#include<iostream>
using namespace std;
int main()
{
	int year, allday;
	int i;
	int dayarr[13] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	while (cin >> year >> allday)
	{
		if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		{
			dayarr[1] = 29;
		}
		for (i = 0; i<12; i++)
		{
			if (allday <= dayarr[i])
			{
				printf("%04d-%02d-%02d\n", year, i + 1, allday);
				break;
			}
			else
			{
				allday = allday - dayarr[i];
			}
		}
	}
	return 0;
}