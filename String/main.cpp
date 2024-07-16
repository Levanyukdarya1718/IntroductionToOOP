//String
#include<iostream>
using namespace std;
#define delimiter "\n------------------------------------\n"
class String
{
	int size;//������ ������ � ������
	char* str;//��������� �� ������ ������������ ������
public:
	int get_size() const
	{
		return size;
	}
	const char* get_str()const
	{
		return str;
	}
  char* get_str()
	{
		return str;
	}
	//				Constructors
	explicit String(int size = 80)
	{
		this->size;
		this->str = new char[size] {};
		cout << "Constructor:\t" << endl;
	}
	String(const char str[])
	{
		this->size=strlen(str)+1;
		//������� strlen() ���������� ������ ������ � ��������,
		//� ��� ����� �������� ��� ���� ���� ��� NULL-Terminator-a
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = str[i];
		cout << "Constructor:\t" << this << endl;
	}
	String(const String& other)
	{
		//Deep opy (��������� �����������)
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyConstructor:" << this << endl;
	}
	~String()
	{
		delete[]str;
		cout << "Destructor:\t" << this << endl;
	}
	// Operators
	String& operator=(const String& other)
	{
		//Deep opy (��������� �����������)
		if (this == &other)return *this;
		this->size = other.size;
		this->str = new char[size] {};
		for (int i = 0; i < size; i++)this->str[i] = other.str[i];
		cout << "CopyAssigment:" << this << endl;
		return *this;
	}
	const char& operator[](int i)const
	{
		return str[i];
	}
	 char& operator[](int i)
	{
		return str[i];
	}
	//Metods
	void print()const
	{
		cout << "Obj:\t\t" << this << endl;
		cout << "Size:\t\t" << size << endl;
		cout << "Addr:\t\t" << &str << endl;
		cout << "Str:\t" << str << endl; 
		cout << delimiter << endl;

	}
};
String operator+(const String& left, const String& right)
{
	cout << delimiter << endl;
	cout << "Operator+" << endl;
	String buffer(left.get_size() + right.get_size() - 1);
	buffer.print();
	for (int i = 0; i < left.get_size(); i++)
		buffer[i] = left[i];
		//buffer.get_str()[i] = left.get_str()[i];
	for (int i = 0; i < right.get_size(); i++)
		buffer[i + left.get_size() - 1] = right[i]; 
		//buffer.get_str()[i + left.get_size() - 1] = right.get_str()[i];
	return buffer;
}
std::ostream& operator<<(std::ostream& os, const String& obj)
{
	return os << obj.get_str();
}
void main()
{
	setlocale(LC_ALL, "");
	String str1; //Default constructor
	str1.print();

	//String str2 = 8;//conversion from 'int' to 'string'
	String str2(8); //Single-argument 'int' constructor
	str2.print();

	String str3 = "Hello";
	str3 = str3;
	str3.print();

	String str4 = "World";
	str4.print();

	cout << str3 << endl;
	cout << str4 << endl;

	//String str5 = str3 + str4;
	String str5;
	str5 = str3 + str4;//Copy assigment
	str5.print();
	cout << str5 << endl;
}