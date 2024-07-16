#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;
#define delimiter "-----------------------------------\n"
class Fraction;
Fraction operator*(Fraction left, Fraction right);
Fraction operator/ (const Fraction& left, const Fraction& right);

class Fraction
{
	int integer;//целая часть
	int numerator;//числитель
	int denominator;//знаменатель
public:
	int get_integer()const
	{
		return integer;
	}
	int get_numerator()const
	{
		return numerator;
	}
	int get_denominator()const
	{
		return denominator;
	}
	void set_integer(int integer)
	{
		this->integer = integer;
	}
	void set_numerator(int numerator)
	{
		this->numerator = numerator;
	}
	void set_denominator(int denominator)
	{
		if (denominator == 0)denominator = 1;
		this->denominator = denominator;
	}
	//	Constructors:
	Fraction()
	{
		integer = 0;
		numerator = 0;
		set_denominator(1);
		cout << "DefaultConstructor:\t" << this << endl;
	}
	explicit Fraction(int integer)
	{
		this->integer = integer;
		this->numerator = 0;
		set_denominator(1);
		cout << "SingleArgumentConstructor:" << this << endl;
	}
	Fraction(double decimal)
	{
		//decimal-десятичный
		denominator = 1e-10;
		integer = decimal;//сохраняем целую часть
		decimal -= integer;//убираем целую чать из десятичной дроби
		denominator = 1e+9; //Записываем максимально возможный знаменатель
		numerator = decimal * denominator;
		reduce();
		cout << "DoubleConstructor:\t" << this << endl;

	}
	Fraction(int numerator, int denominator)
	{
		this->integer = 0;
		this->numerator = numerator;
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}
	Fraction(int integer, int numerator, int denominator)
	{
		set_integer(integer);
		set_numerator(numerator);
		set_denominator(denominator);
		cout << "Constructor:\t\t" << this << endl;
	}

	
	Fraction(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "Copyconstructor:\t" << this << endl;
	}
	~Fraction()
	{
		cout << "Destructor:\t" << this << endl;
	}
	//	Operators

	Fraction& operator=(const Fraction& other)
	{
		this->integer = other.integer;
		this->numerator = other.numerator;
		this->denominator = other.denominator;
		cout << "CopyAssignment:\t\t" << this << endl;
		return *this;
	}
	Fraction& operator++()
	{
		integer++;
		return *this;
	}
	Fraction operator++(int)
	{
		Fraction result = *this;
		integer++;
		return result;
	}
	Fraction& operator--()
	{
		integer--;
		return *this;
	}
	Fraction operator--(int)
	{
		Fraction result = *this;
		integer--;
		return result;
	}


	Fraction& operator*=(Fraction& other)
	{
		return *this = *this * other;
	}
	Fraction& operator/=(Fraction& other)
	{
		return *this = *this / other;
	}
	explicit operator int()
	{
		return to_proper().integer;
		//to_proper();
		//return integer;
	}
	operator double()const
	{
		return integer +(double) numerator / denominator;
	}
	//	Metods:
	Fraction& to_improper()
	{
		numerator += integer * denominator;
		integer = 0;
		return*this;
	}
	Fraction& to_proper()
	{
		integer += numerator / denominator;
		numerator %= denominator;
		return*this;
	}
	Fraction inverted()const
	{
		Fraction inverted = *this;
		inverted.to_improper();
		swap(inverted.numerator, inverted.denominator);
		return inverted;
	}
	Fraction& reduce()
	{
		int more, less, rest;
		if (numerator)more = numerator, less = denominator;
		else less = numerator, more = denominator;
		do
		{
			rest = more % less;
			more = less;
			less = rest;
		} while (rest);
		int GCD = more; //GCD-Greatest Common Divisor
		numerator /= GCD;
		denominator /= GCD;
		return*this;
	}
	void print()const
	{
		if (integer)cout << integer;
		if (numerator)
		{
			if (integer)cout << "(";
			cout << numerator << "/" << denominator;
			if (integer)cout << ")";
		}
		else if (integer == 0)cout << 0;
		cout << endl;
	}
};

Fraction operator*( Fraction left,Fraction right)
{
	left.to_improper();
	right.to_improper();
	/*Fraction result;
	result.set_numerator(left.get_numerator() * right.get_numerator());
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;*/
	/*Fraction result(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	);
	result.to_proper();
	return result;*/
	return Fraction
	(
		left.get_numerator() * right.get_numerator(),
		left.get_denominator() * right.get_denominator()
	).to_proper().reduce();

}
Fraction operator/ (const Fraction& left, const Fraction& right)
{
	/*left.to_improper();
	right.to_improper();
	Fraction result;
	result.set_numerator(left.get_numerator() * right.get_denominator());
	result.set_denominator(left.get_denominator() * right.get_numerator());
	return result;*/
	return left * right.inverted();
}
Fraction operator+(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction result;
	result.set_numerator((left.get_numerator() * right.get_denominator()) + (left.get_denominator() * right.get_denominator()));
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;
}
Fraction operator-(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	Fraction result;
	result.set_numerator((left.get_numerator() * right.get_denominator()) - (left.get_denominator() * right.get_denominator()));
	result.set_denominator(left.get_denominator() * right.get_denominator());
	return result;
}

//		Comperison operators:
bool operator==(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return left.get_numerator() * right.get_denominator() == right.get_numerator() * left.get_denominator();

}
bool operator!=(const Fraction& left, const Fraction& right)
{
	return!(left == right);
}
bool operator<(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() <
		right.get_numerator() * left.get_denominator();
}
bool operator>(Fraction left, Fraction right)
{
	left.to_improper();
	right.to_improper();
	return
		left.get_numerator() * right.get_denominator() >
		right.get_numerator() * left.get_denominator();
}
bool operator>=(Fraction left, Fraction right)
{
	return !(left < right);
}
bool operator<=(Fraction left, Fraction right)
{
	return !(left > right);
}
std::ostream& operator<<(std::ostream& os, const Fraction& obj)
{
	if (obj.get_integer())os << obj.get_integer();
	if (obj.get_numerator())
	{
		if (obj.get_integer())os << "(";
		cout << obj.get_numerator() << "/" << obj.get_denominator();
		if (obj.get_integer())os << ")";
	}
	else if (obj.get_integer() == 0)os << 0;
	return os;
}
std::istream& operator>>(std::istream& is, Fraction& obj)
{
	/*int integer, numerator, denominator;
	is >> integer >> numerator >> denominator;
	obj = Fraction(integer, numerator, denominator);*/
	const int SIZE = 256;
	char buffer[SIZE];
	//is >> buffer;
	is.getline(buffer, SIZE);
	int numbers[3] = {};
	int n = 0;
	const char delimiters[] = " / ()";
	for (char* pch = strtok(buffer, delimiters); pch; pch = strtok(NULL, delimiters))
		numbers[n++] = atoi(pch);//Функция atoi() - 'ASCII to int' принимает строку,
								//и возвращает целочисленный аналог этой строки,
								//т.е., строку преобразует в число
	//for (int i = 0; i < n; i++)cout << numbers[i] << "\t"; cout << endl;

	switch (n)
	{
	case 1: obj = Fraction(numbers[0]); break;
	case 2: obj = Fraction(numbers[0], numbers[1]); break;
	case 3: obj = Fraction(numbers[0], numbers[1], numbers[2]); break;
	}
		return is;
}
//#define CONSTRUCTORS_CHECK
//#define ARITHMETICAL_OPERATORS_CHECK
//#define IOSTRAM_CHECK 
//#define TYPE_CONVERSIONS_BASICS
//#define CONVERSION_FROM_OTHER_TO_CLASS
//#define CONVERSION_HOME_WORK
void main()
{
	setlocale(LC_ALL, "");
#ifdef CONSTRUCTORS_CHECK
	Fraction A; //Default constructor
	A.print();
	Fraction B = 5; //Single-argument constructor
	B.print();
	Fraction C(1, 2);
	C.print();
	Fraction D(2, 3, 4);
	D.print();


#endif // CONSTRUCTORS_CHECK
#ifdef ARITHMETICAL_OPERATORS_CHECK
	Fraction A(2, 3, 4);
	A.print();

	Fraction B(3, 4, 5);
	B.print();

	A.to_improper().print();
	A.to_proper().print();

	Fraction C =A/ B;
	C.print();

	Fraction D = A / B;
	D.print();

	Fraction E = A + B;
	E.print();

	Fraction F = A - B;
	F.print();

	++A;
	A.print();

	A++;
	A.print();

	--A;
	A.print();

	A--;
	A.print();

	A *= B;
	A.print();

	A /= B;
	A.print();
#endif //ARITHMETICAL_OPERATORS_CHECK
#ifdef IOSTRAM_CHECK 

	cout << (Fraction(1, 2) < Fraction(5, 11)) << endl;



	Fraction B;
	cout << "Введите простую дробь:"; cin >> B;
	cout << B << endl;

#endif // IOSTRAM_CHECK 

#ifdef TYPE_CONVERSIONS_BASICS
	//(type)value; C-like notation
//type(value); Fanction notation
	int a = 2; //No conversions
	double b = 3; //Conversion from less to more
	float c = 4; //Conversion from less to more
	int d = 3.14; // Conversion from more to less
	//without data loss
	int e = 5.5; //Conversion from more to less with data

#endif // TYPE_CONVERSIONS_BASICS

#ifdef CONVERSION_FROM_OTHER_TO_CLASS

	Fraction A = (Fraction)5;//Conversion from less to more(from 'int' to 'Fraction'
	//Single-argument Constructor
	cout << A << endl;
	cout << delimiter << endl;
	Fraction B; //Default constructor
	cout << delimiter << endl;
	B = Fraction(8);//Conversion from less to more(from 'int' to 'Fraction'
	//CopyAssigment
	cout << delimiter << endl;
	cout << B << endl;
	cout << delimiter << endl;

#endif // CONVERSION_FROM_OTHER_TO_CLASS

#ifdef CONVERSION_HOME_WORK
	Fraction A = 3.333;//Conversion from 'double' to 'Fraction'
	cout << A << endl;
#endif // CONVERSION_HOME_WORK

	Fraction A(2, 3, 4);
	A.to_improper();
	cout << A << endl;

	int a = (int)A;
	cout << a << endl;

	double da = A;
	cout << da << endl;


}