//
// Created by Jacob Yeung on 10/18/23.
//

//Specification file complexType.h

#ifndef H_complexNumber
#define H_complexNumber

#include <iostream>

using namespace std;

class complexType
{
    // overload stream insertion and extraction operators
    friend ostream& operator<< (ostream&, const complexType&);
    friend istream& operator>> (istream&, complexType&);

    friend	complexType operator+(const complexType& one,
                                    const complexType& two);
    //overload +
    friend complexType operator*(const complexType& one,
                                 const complexType& two);
    //overload *
    friend complexType operator-(const complexType& one,
                                 const complexType& two);
    //overload -
    friend complexType operator/(const complexType& one,
                                 const complexType& two);
    //overload /

    friend bool operator==(const complexType& one,
                           const complexType& two);
    //overload ==

public:
    void setComplex(const double& real, const double& imag);
    //Function to set the complex number according to the parameters
    //Postcondition: realPart = real; imaginaryPart = imag

    void getComplex(double& real, double& imag) const;
    //Function to retrieve the complex number.
    //Postcondition: real = realPart; imag = imaginaryPart

    complexType(double real = 0, double imag = 0);
    //constructor
private:
    double realPart;      // variable to store the real part
    double imaginaryPart; // variable to store the imaginary part
};

