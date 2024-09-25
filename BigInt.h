#ifndef BIGINT_H
#define BIGINT_H

#include<iostream>
#include<string>

class BigInt{
    private:
      std::string str;//string representation of Big Integer
    public:
    //constructors prototype
      BigInt();//Default constructor
      BigInt(std::string s);//constructor with string argument
      BigInt(const BigInt &b);//constructor with object as argument(copy)
      BigInt(long long int n);//constructor with long long integer as argument
    //prototype of overloaded operators
    void operator()(std::string s);
    BigInt operator=(const BigInt &b);
    BigInt operator+(const BigInt &b) const;
    BigInt operator*(const BigInt &b) const;
    BigInt operator++();
    BigInt operator++(int);
    BigInt operator--();
    BigInt operator--(int);
    bool operator>(const BigInt &b) const;
    bool operator<(const BigInt &b) const;
    bool operator==(const BigInt &b) const;
    bool operator!=(const BigInt &b) const;
    bool operator>=(const BigInt &b) const;
    bool operator<=(const BigInt &b) const;
    BigInt operator+=(const BigInt &b);
    BigInt operator-=(const BigInt &b);
    BigInt operator*=(const BigInt &b);
    friend BigInt operator-(BigInt a, BigInt b);
    BigInt operator/(const BigInt &b) const;
    BigInt operator%(const BigInt &b) const;
    BigInt operator^(const BigInt &b) const;
    BigInt operator/=(const BigInt &b);
    BigInt operator%=(const BigInt &b);
    BigInt operator^=(const BigInt &b);
    friend std::istream& operator>>(std::istream &cin, BigInt &a);
    friend std::ostream& operator<<(std::ostream &out, const BigInt &a);
};
#endif