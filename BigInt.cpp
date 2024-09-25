#include<iostream>
#include<string>
#include<algorithm>
#include "BigInt.h"

//constructors
BigInt::BigInt(){   //Default constructor
  str = "";
}

BigInt::BigInt(std::string s){  //constructor string as argument
  for(int i = 0; i < s.size(); i++)
  {
    if(s[i]<'0' || s[i] > '9')
      throw std::invalid_argument("Invalid character in BigInt initialization");
  }
  this->str = s;
}

BigInt::BigInt(const BigInt &b){ //constructor with object as argument
  this->str = b.str;
}

BigInt::BigInt(long long int n){ //constructor with integer as argument
  while(n != 0){
    char push = (n%10)+'0';
    this->str.insert(this->str.begin(), push);
    n = n / 10;
  }
}
//Overloading of operators 
void BigInt::operator()(std::string s){ //alternate of copy constuctor
  this->str = s;
}

BigInt BigInt::operator=(const BigInt &b){ //assignment operator
  this->str = b.str;
  return *this;
}

BigInt BigInt::operator+(const BigInt &b)const{
  if(str[0] == '-' || b.str[0] == '-'){
    throw std::invalid_argument("Negative operation is not allowed");
  }
     BigInt store; //stores addition of  objects
       int curr_size = str.size() - 1;
       int Arg_size = b.str.size() - 1;
   
       int carry = 0;
       int count = 0;
          // checks 3 conditions if a = "12" and b = "24"
          // or a = "122" and b = "24" or a = "12" and b = "2444" 
       while(curr_size >= 0 || Arg_size >= 0 ){
            if(curr_size >= 0 && Arg_size >= 0)
              count = (str[curr_size] - '0') + (b.str[Arg_size]-'0');

            else if(curr_size >= 0 && Arg_size < 0)
              count = (str[curr_size] - '0');

            else if(curr_size < 0 && Arg_size >= 0)
              count = (b.str[Arg_size] - '0');

              char ch = ((count+carry)%10) + '0';
              store.str.insert(store.str.begin(), ch);
              carry = (count+carry)/10;
              Arg_size--;
              curr_size--;
             }if(carry){
                store.str.insert(store.str.begin(), carry + '0');
             }int i = 0;
          while(store.str[i] == '0' && i != store.str.size()-1){
           i++;
          }
         store.str.erase(0,i);//Removes zeros from front part such as store.str = 00001 then result = 1
        return store;
}

BigInt BigInt::operator*(const BigInt &b)const{
  if(str[0] == '-' || b.str[0] == '-'){
    throw std::invalid_argument("Negative operation is not allowed");
  }
  BigInt add;//stores multiplication of objects
  int a_size = this->str.size() - 1;
  int b_size = b.str.size() - 1;
  for(int i = b_size; i>=0; i--){
    BigInt store;//stores multiplied digits of ith iteration
    int carry = 0;
    int ch1 = b.str[i] - '0';
    for(int j = a_size; j>=0; j--){
       int ch2 = this->str[j] - '0';
       int product = (ch1 * ch2)+carry;
       store.str.insert(store.str.begin(),(product%10)+'0');//inserts digits at the begining of string
       carry = product/10;
    }if(carry)
      store.str.insert(store.str.begin(),carry+'0');
    store.str.append(b_size-i, '0');
    add = add + store;
    store.str.clear();
  }int i = 0;
  while(add.str[i] == '0' && i != add.str.size()-1){
    i++;
  }
  add.str.erase(0,i);//Removes leading zeros from starting
  return add;
}

bool BigInt::operator>(const BigInt &b)const{
   if(str[0] == '-' || b.str[0] == '-'){
    throw std::invalid_argument("Negative operation is not allowed");
  }
    if(this->str.size() > b.str.size())//compares size
      return 1;
    else if(this->str.size() < b.str.size())
      return 0;
    else{
      for(int i = 0; i<str.size(); i++){//compares elements
        if(this->str[i] > b.str[i])
          return 1;
        else if(this->str[i] < b.str[i])
          return 0;
        }
      }
      return 0;
}

bool BigInt::operator<(const BigInt &b)const{
   if(str[0] == '-' || b.str[0] == '-'){
    throw std::invalid_argument("Negative operation is not allowed");
  }
  if(b.str.size() < this->str.size())//compares size
    return 0;
  else if(b.str.size() > this->str.size())
    return 1;
  else{
    for(int i = 0; i<str.size(); i++){//compares size
      if(b.str[i] > this->str[i])
        return 1;
      else if(b.str[i] < this->str[i])
        return 0;
    }
  }
      return 0;
}

bool BigInt::operator==(const BigInt &b)const{
   if(str[0] == '-' || b.str[0] == '-'){
    throw std::invalid_argument("Negative operation is not allowed");
  }
  if(b.str.size() == this->str.size())//if sizes are equal then proceed
    for(int i = 0; i<str.size(); i++){//compares elements
      if(b.str[i] != this->str[i])
        return 0;
      }else
        return 0;
    return 1;
}

bool BigInt::operator!=(const BigInt &b)const{
   if(str[0] == '-' || b.str[0] == '-'){
    throw std::invalid_argument("Negative operation is not allowed");
  }
  if(b.str.size() == this->str.size())//compares size
    for(int i = 0; i<str.size(); i++){
      if(b.str[i] != this->str[i])//compares digits
        return 1;
      }else
        return 1;
    return 0;
}

bool BigInt::operator>=(const BigInt &b)const{
   if(str[0] == '-' || b.str[0] == '-'){
    throw std::invalid_argument("Negative operation is not allowed");
  }
  if(*this > b || *this == b)
    return 1;
  return 0;
}

bool BigInt::operator<=(const BigInt &b)const{
   if(str[0] == '-' || b.str[0] == '-'){
    throw std::invalid_argument("Negative operation is not allowed");
  }
  if(*this < b || *this == b)
    return 1;
  return 0;
}

BigInt operator-(BigInt a, BigInt b){
  if(a.str[0] == '-' || b.str[0] == '-'){
    throw std::invalid_argument("Negative operation is not allowed");
  }
  BigInt temp;
  bool is_negetive = 0;
  if(a==b){
  temp.str.insert(temp.str.begin(),'0');
  return temp;
  }
  if(a < b){//if a = 12 and b = 1235, it always subtract from bigger element
    std::swap(a,b);
    is_negetive = 1;
  }
  int a_size = a.str.size() - 1;
  int b_size = b.str.size() - 1;
  if(a > b){   //a = 1235 and b = 12 or a = 123 and b = 123
    while(b_size >= 0){
      int a_obj = a.str[a_size] - '0';//converts character to digit
      int b_obj = b.str[b_size] - '0';
        if(a_obj >= b_obj){//checks digit from end of the string
          char push = (a_obj - b_obj) + '0';
          temp.str.insert(temp.str.begin(),push);
        }else{
          a_obj = a_obj + 10;
          //decreasing 1 from next character
          if(a_size-1 >= 0)
            a.str[a_size-1] = ((a.str[a_size-1] - '0')-1) + '0';
          char push = (a_obj - b_obj) + '0';//converting digit to character
          temp.str.insert(temp.str.begin(),push);
         }
        a_size--;
        b_size--;
    }
    while(a_size >= 0){//remaining elements of 'a' object
      temp.str.insert(temp.str.begin(), a.str[a_size]);
      a_size--;
    }
   }
  int i = 0;
  while(temp.str[i] == '0' && i < temp.str.size()-1){//Removes leading zeros
    i++;
  }
  temp.str.erase(0,i);
  if(is_negetive)//if the result is in negative value
      temp.str.insert(temp.str.begin(), '-');
  return temp;
  }

BigInt BigInt::operator++(){//prefix
  BigInt i("1");
  *this = *this + i;
  return *this;
}
    
BigInt BigInt::operator++(int){//postfix
  BigInt temp = *this;
  ++(*this);
  return temp;
}

BigInt BigInt::operator--(){//prefix
  BigInt i("1");
  *this = *this - i;
  return *this;
}
    
BigInt BigInt::operator--(int){//postfix
  BigInt temp = *this;
  --(*this);
  return temp;
}

BigInt BigInt::operator+=(const BigInt &b){
  *this = *this + b;
  return *this;
}

BigInt BigInt::operator-=(const BigInt &b){
  *this = *this - b;
  return *this;
}

BigInt BigInt::operator*=(const BigInt &b){
  *this = *this * b;
  return *this;
}

BigInt BigInt::operator/(const BigInt& divisor) const {
    if (divisor.str == "0") {
        throw std::invalid_argument("Division by zero is not allowed.");
    }
    if(*this < divisor)
      return BigInt("0");

    BigInt dividend = *this; // to hold dividend value
    BigInt curr_divid("0");  // to hold the current partial dividend
    BigInt result("0");      // to store the quotient
    
    int index = 0;
    while (index < dividend.str.size()) {
        // storing next digit from the dividend
        curr_divid.str.push_back(dividend.str[index++]);
        // remove leading zeros from the current partial dividend
        while (curr_divid.str.size() > 1 && curr_divid.str[0] == '0') {
            curr_divid.str.erase(0, 1);
        }
        // determine how many times the divisor fits in curr_divid
        int count = 0;
        while (curr_divid >= divisor) {
            curr_divid = curr_divid - divisor;  
            count++;
        }
        result.str.push_back(count + '0');
    }
    // remove leading zeros from the quotient
    while (result.str.size() > 1 && result.str[0] == '0') {
        result.str.erase(0, 1);
    }
    return result;
}

BigInt BigInt::operator%(const BigInt &b)const{
   if(str[0] == '-' || b.str[0] == '-'){
    throw std::invalid_argument("Negative operation is not allowed");
  }
  BigInt mod = *this - (operator/(b) * b);//a = 8, b = 2 then a - (a/b * b) = 8 - 4*2 = 0
  return mod;
}

BigInt BigInt::operator^(const BigInt &b)const{
  if(str[0] == '-' || b.str[0] == '-'){
    throw std::invalid_argument("Negative operation is not allowed");
  }
    BigInt base = *this;
    BigInt result("1");
    BigInt one("1");
    BigInt two("2");
    BigInt power = b;
    BigInt zero("0");

    while (power > zero) {//loop iterates through odd and even values of power
        if (power % two != zero) {//if power is odd
            result = result * base;
        }
        base = base * base;//power is even
        power = power / two; 
    }
  
    return result; 
}


BigInt BigInt::operator/=(const BigInt &b){
  *this = *this / b;
  return *this;
}

BigInt BigInt::operator%=(const BigInt &b){
  *this = *this % b;
  return *this;
}

BigInt BigInt::operator^=(const BigInt &b){
  *this = *this ^ b;
  return *this;
}

std::istream& operator>>(std::istream &cin, BigInt &a){//input operator
  cin>>a.str;
  for (int i = 0; i < a.str.size(); i++){
    if(a.str[i]<'0' || a.str[i] > '9')
      throw std::invalid_argument("Invalid character in BigInt initialization");
  }
  return cin;
} 

std::ostream& operator<<(std::ostream &out, const BigInt &a){//output operator
  out<<a.str;
  return out;
}