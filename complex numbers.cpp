#include <iostream>

using namespace std ;

class Complex
{
private:
	double real, imaginary;
public:
	Complex(){
		real=0;
		imaginary=0;
	}
	Complex(double real_part, double imaginary_part){
		real = real_part;
		imaginary = imaginary_part;
	}
	Complex(double real_part){
		real = real_part;
		imaginary=0;
	}
	double getR() {return real;}
	double getI() {return imaginary;}
	
	void setR(double x) {real=x;}
	void setI(double y) {imaginary=y;}	
	~Complex(){};
};

bool operator== (Complex comp1, Complex comp2);
	//compare between to complex numbers
Complex operator+ (Complex comp1, Complex como2);
	//add two complex numbers
Complex operator- (Complex comp1, Complex comp2);
	//suptract two complex numbers
Complex operator* (Complex comp1, Complex comp2);
	//multiply to complex numbers
istream& operator>> (istream& in, Complex& comp);
	//read a complex number from the user
ostream& operator<< (ostream& out, Complex comp);
	//print a complex number to screen
	
const Complex i(0, 1);

int main()
{
	Complex num1( 4 , 3 ), num2( 6 ), num3 ;
	cin >> num3;
	
	cout << "num1 + num2 = " << num1+num2 << endl;
	cout << "num2 - num3 = " << num2-num3 << endl;
	cout << "num1 * num3 = " << num1*num3 << endl;
	
	return 0;
}

//All functions decleared before
bool operator== (Complex comp1, Complex comp2){
	return ( comp1.getR()==comp2.getR() && comp1.getI()==comp2.getI() );
}

Complex operator+ (Complex comp1, Complex comp2){
	Complex comp;
	comp.setR( comp1.getR() + comp2.getR() );
	comp.setI( comp1.getI() + comp2.getI() );
	return comp;
}

Complex operator- (Complex comp1, Complex comp2){
	Complex comp;
	comp.setR( comp1.getR() - comp2.getR() );
	comp.setI( comp1.getI() - comp2.getI() );
	return comp;
}

Complex operator* (Complex comp1, Complex comp2){
	double a = comp1.getR();
	double b = comp1.getI();
	double c = comp2.getR();
	double d = comp2.getI();
	Complex comp( a*c - b*d , a*d + b*c );
	return comp;
}

istream& operator>> (istream& in, Complex& comp){
	char tmp, sign;
	double r, i;
	cout << "Enter a complex num as : a + b i \n";
	in >> r >> sign >> i >> tmp;
	if ( sign == '-' ) i*=-1;
	comp.setR(double(r));
	comp.setI(double(i));
	return in;
}

ostream& operator<< (ostream& out, Complex comp){
	if ( comp.getR() != 0 )
		out << comp.getR();
	if ( comp.getI() > 0 && comp.getR() != 0 )
		out << '+';
	if ( comp.getI() == 0 )
		return out;
	out << comp.getI() << 'i' << endl;
	return out;
}
