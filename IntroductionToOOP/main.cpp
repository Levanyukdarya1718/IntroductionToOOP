﻿
#include<iostream>
using namespace std;
using std::cin;
using std::cout;
using std::endl;

#define delimiter "\n-----------------------------------------\n"
class Point
{
	double x;
	double y;
public:
	double get_x()const
	{
		return x;
	}
	double get_y()const
	{
		return y;
	}
	void set_x(double x)
	{
		this->x = x;
	}
	void set_y(double y)
	{
		this->y = y;
	}

	//				Constrcutors:
	/*Point()
	{
		x = y = 0;
		cout << "DefaultConstructor:\t" << this << endl;
	}*/
	/*Point(double x)
	{
		this->x = x;
		this->y = 0;
		cout << "1ArgConstructor:\t" << this << endl;
	}*/
	Point(double x=0, double y=0)
	{
		this->x = x;
		this->y = y;
		cout << "Constrcutor:\t\t" << this << endl;
	}
	Point(const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout <<"CopyConstructor:\t"<< this << endl;

	}
	~Point()
	{
		cout << "Destructor:\t\t" << this << endl;
	}
	//			Operators
	Point& operator = (const Point& other)
	{
		this->x = other.x;
		this->y = other.y;
		cout << "CppyAssigment:\t\t" << this << endl;
		return *this;
	}
	Point& operator++()//Prefix increment
	{
		x++;
		y++;
		return *this;
	}
	Point operator++(int)
	{
		Point old = *this;
		x++;
		y++;
		return old;
	}
	//				Methods:
	void print()const
	{
		cout << "X = " << x << "\tY = " << y << endl;
	}
	double distance( const Point& other)const
	{
		double x_distance = this->x - other.x;
		double y_distance = this->y - other.y;
		double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
		return distance;
	}
	
};

double distance(const Point& A, const Point& B)
{
	double x_distance = A.get_x() - B.get_x();
	double y_distance = A.get_y() - B.get_y();
	double distance = sqrt(x_distance * x_distance + y_distance * y_distance);
	return distance;
}
Point operator+(const Point& left, const Point& right)
{
	Point result;
	result.set_x(left.get_x() + right.get_x());
	result.set_y(left.get_y() + right.get_y());
	return result;
}
bool operator ==(const Point& left, const Point& right)
{
	/*if (left.get_x() == right.get_x() && left.get_y() == right.get_y())
		return true;
	else
		return false;*/
	return left.get_x() == right.get_x() && left.get_y() == right.get_y();

}
std::ostream& operator<<(std::ostream& os, const Point& obj)
{
	return os << "X=" << obj.get_x() << "\tY=" << obj.get_y();
}
//#define STRUCT_POINT
//#define DISTANCE_CHECK
//#define CONSTRUCTOES_CHECK
//#define ASSIGMENT_CHECK
//#define ARIFMRTICAL_OPERATOR_CHECK
//#define COMPARRISON_OPERATORS_CHECK
void main()
{
	setlocale(LC_ALL, "");

#if defined STRUCT_POINT
	int a;		
	Point A;	

	A.x = 2;
	A.y = 3;
	cout << A.x << "\t" << A.y << endl;

	Point* pA = &A;
	cout << pA->x << "\t" << pA->y << endl;
#endif // STRUCT_POINT
#if defined CONSTRUCTOES_CHECK
	Point A;		//Default constructor
	//A.set_x(2);
	//A.set_y(3);
	cout << A.get_x() << "\t" << A.get_y() << endl;
	A.print();

	Point B = 5;
	B.print();


	Point C(2, 3);
	C.print();

	Point D = C;
	D.print();
	Point E;
	E = D;
	E.print();
#endif	//CONSTRUCTOES_CHECK

		/*for (int i = 0; i < 10; i++)
		{
			cout << i << "\t";
		}*/
		//cout << i << endl;
		//cout << endl;
#ifdef DISTANCE_CHECK
	Point A(2, 3);
	Point B(7, 8);

	A.print();
	B.print();

	cout << "Расстояние от точки 'A' до точки 'B':" << A.distance(B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние от точки 'B' до точки 'A':" << B.distance(A) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'A' и 'B':  " << distance(A, B) << endl;
	cout << delimiter << endl;
	cout << "Расстояние между точками 'B' и 'A':  " << distance(B, A) << endl;
	cout << delimiter << endl;
#endif // DISTANCE_CHECK
#ifdef ASSIGMENT_CHECK
	int a, b, c;
	a = b = c = 0;
	cout << a << "\t" << b << "\t" << c << endl;

	Point A, B, C;
	cout << delimiter << endl;
	A = B = C = Point(2, 3); //Point(2,3) - явно вызываем конструктор 
							//и создаем временный безымянный объект,
							//этот объект и передается как параметр
							//в первый CopyAssigment.
	cout << delimiter << endl;
	A.print();
	B.print();
	C.print();
	cout << delimiter << endl;
#endif //ASSIGMENT_CHECK
#ifdef ARIFMETICAL_OPERATORS_CHECK
	int a = 2;
	int b = 3;
	int c = a + b;

	Point A(2, 3);
	A.print();

	Point B(7, 8);
	B.print();

	Point C = A + B;
	C.print();
	
	Point D = C++;
	C.print();
	D.print();
#endif //ARIFMETICAL_OPERATORS_CHECK
#ifdef COMPARRISON_OPERATORS_CHECK
	// << (2 == 3) << endl;
	//cout << (Point(2, 3) == Point(2, 3)) << endl;
	Point A(2, 3);
	Point B(2, 3);
	cout << (A == B) << endl;
#endif // COMPARRISON_OPERATORS_CHECK
	Point A(2, 3);
	cout << A<<endl;

}

