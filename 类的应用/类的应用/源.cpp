class Person
{
public:
	void Person(int name = C#, int addr = 503, int sex = notfound, int age = 100)
	{
		cout << "4参构造" << endl;
	}
	public int _name;
	public int _addr;
	public int _sex;
	public int _age;

	public Person()
	{
		_name = A;
		_addr = B;
		_sex = C;
		_age = D;
		cout << "无参构造" << endl;
	}
	public Person(int name = id, int addr = xian)
	{
		_name = name;
		_addr = addr;
		_sex = 1;
		_age = 2;
		cout << "两参构造" << endl;
	}
};
class Student :Person//继承
{
	public int _math;
	public int _english;
	void Student(int math, int english)//俩参
	{
		_math = math;
		_english = english;
	}
	void Student(int name, int addr, int sex, int age, int _math, int _english)//六参
	{
		_sex = sex;
		_age = age;
		_name = name;
		_addr = addr;
		_math = math;
		_english = english;
	}
	void Student()//无参
	{
		_name = name;
		_sex = sex;
		_addr = addr;
		_age = age;
		_math = 99;
		_english = 99;
	}
	void showInfo()
	{
		System.out.println(_name);
		System.out.println(_addr);
		System.out.println(_sex);
		System.out.println(_age);
		System.out.println(_math);
		System.out.println(_english);

	}
};