//
// Created by Jacob Yeung on 10/18/23.
//

//#include "complexType.h"
//Implementation file complexType.cpp

#include <iostream>
#include "complexType.h"

using namespace std;

ostream& operator<< (ostream& os, const complexType& complex)
{
    os << "(" << complex.realPart << ", "
       << complex.imaginaryPart << ")";
    return os;
}

istream& operator>> (istream& is, complexType& complex)
{
    char ch;

    is >> ch;                     //read and discard (
    is >> complex.realPart;       //get the real part
    is >> ch;                     //read and discard,
    is >> complex.imaginaryPart;  //get the imaginary part
    is >> ch;                     //read and discard)

    return is;
}

//friend bool operator==(const complexType& one,
//                       const complexType& two);
bool operator==(const complexType& one, const complexType& two){
    return one.realPart == two.realPart &&
            one.imaginaryPart == two.imaginaryPart;
}

//constructor
complexType::complexType(double real, double imag)
{
    realPart = real;
    imaginaryPart = imag;
}

void complexType::setComplex(const double& real, const double& imag)
{
    realPart = real;
    imaginaryPart = imag;
}

void complexType::getComplex(double& real, double& imag) const
{
    real = realPart;
    imag = imaginaryPart;
}

//overload the operator +
//friend complexType operator+(const complexType& one,
//                             const complexType& two);
complexType operator+(const complexType& one,
                             const complexType& two){
    complexType temp;

    temp.realPart = one.realPart + two.realPart;
    temp.imaginaryPart = one.imaginaryPart + two.imaginaryPart;

    return temp;
}

//overload the operator *
//friend complexType operator*(const complexType& one,
//                             const complexType& two);
complexType operator*(const complexType& one, const complexType& two){
    complexType temp;

    temp.realPart = (one.realPart * two.realPart) -
                    (one.imaginaryPart*two.imaginaryPart);
    temp.imaginaryPart = (one.realPart * two.imaginaryPart) +
                         (one.imaginaryPart * two.realPart);
    return temp;
}

//friend complexType operator-(const complexType& one,
//                             const complexType& two);
complexType operator-(const complexType& one, const complexType& two){
    complexType temp;

    temp.realPart = one.realPart - two.realPart;
    temp.imaginaryPart = one.imaginaryPart - two.imaginaryPart;

    return temp;
}

//friend complexType operator/(const complexType& one,
//                             const complexType& two);
complexType operator/(const complexType& one, const complexType& two){
    complexType temp;

    double denominator;

    if (two.realPart == 0 && two.imaginaryPart == 0)
    {
        cout << "Cannot divide by zero" << endl;
        return two;
    }
    else
    {
        denominator = two.realPart * two.realPart +
                two.imaginaryPart * two.imaginaryPart;


        temp.realPart = ((one.realPart * two.realPart) +
                         (one.imaginaryPart * two.imaginaryPart)) /
                        denominator ;
        temp.imaginaryPart = ((- 1* one.realPart * two.imaginaryPart) +
                              (one.imaginaryPart * two.realPart)) /
                             denominator;
        return temp;
    }
}
