#include "pfraction.h"

PFraction::PFraction() : _num(0), _den(1) {}
PFraction::PFraction(int num) : _num(num), _den(1) {}
PFraction::PFraction(int num, int den) : _num(num){
    if (den == 0) throw std::logic_error("Error:Division by 0");
    _den = den;
    reduce();
}
PFraction::PFraction(const PFraction &other) : _num(other._num), _den(other._den) {}

int PFraction::num() const{
    return _num;
}
void PFraction::setNum(int num){
    _num = num;
    reduce();
}

int PFraction::den() const{
    return _den;
}
void PFraction::setDen(int den){
    _den = den;
    reduce();
}

PFraction PFraction::abs(){
    return PFraction(std::abs(_num), _den);
}

PFraction::operator double() const{
    return double(_num)/_den;
}
void PFraction::print(std::ostream &os) const{
    _den != 1 ? os << _num << "/" << _den : os << _num;
}

void PFraction::reduce(){
    int t = pgcd(_num, _den);
    _num /= t;
    _den /= t;
    if (_den < 0) { _num *= -1; _den *= -1;}
}


PFraction& PFraction::operator+=(const PFraction &other)        {
    if (other._den == _den){
        _num += other._num;
    } else {
        _num = _num * other._den + _den * other._num;
        _den *= other._den;
    }
    reduce();
    return *this;
}
PFraction& PFraction::operator+=(int i)                         {
    _num += i;
    reduce();
    return *this;
}
PFraction& PFraction::operator-=(const PFraction &other)        {
    if (other._den == _den){
        _num -= other._num;
    } else {
        _num = _num * other._den - _den * other._num;
        _den *= other._den;
    }
    reduce();
    return *this;
}
PFraction& PFraction::operator-=(int i)                         {
    _num -= i;
    reduce();
    return *this;
}
PFraction& PFraction::operator*=(const PFraction &other)        {
    _num *= other._num;
    _den *= other._den;
    reduce();
    return *this;
}
PFraction& PFraction::operator*=(int i)                         {
    _num *= i;
    reduce();
    return *this;
}
PFraction& PFraction::operator/=(const PFraction &other)        {
    _num *= other._den;
    _den *= other._num;
    reduce();
    return *this;
}
PFraction& PFraction::operator/=(int i)                         {
    _den *= i;
    reduce();
    return *this;
}

PFraction operator+(const PFraction &f1, const PFraction &f2)   {
    if (f1._den == f2._den) return PFraction(f1._num + f2._num, f1._den);
    else return PFraction(f1._num * f2._den + f1._den * f2._num, f1._den * f2._den);
}
PFraction operator+(const PFraction &f, int i)                  {
    return PFraction(f._num + i * f._den, f._den);
}
PFraction operator+(int i, const PFraction &f)                  {
    return PFraction(f._num + i * f._den, f._den);
}
PFraction operator-(const PFraction &f1, const PFraction &f2)   {
    if (f1._den == f2._den) return PFraction(f1._num - f2._num, f1._den);
    else return PFraction(f1._num * f2._den - f1._den * f2._num, f1._den * f2._den);
}
PFraction operator-(const PFraction &f, int i)                  {
    return PFraction(f._num - i * f._den, f._den);
}
PFraction operator-(int i, const PFraction &f)                  {
    return PFraction(f._num - i * f._den, f._den);
}
PFraction operator*(const PFraction &f1, const PFraction &f2)   {
    return PFraction(f1._num * f2._num, f1._den * f2._den);
}
PFraction operator*(const PFraction &f, int i)                  {
    return PFraction(f._num * i, f._den);
}
PFraction operator*(int i, const PFraction &f)                  {
    return PFraction(f._num * i, f._den);
}
PFraction operator/(const PFraction &f1, const PFraction &f2)   {
    return PFraction(f1._num * f2._den, f1._den * f2._num);
}
PFraction operator/(const PFraction &f, int i)                  {
    return PFraction(f._num, i * f._den);
}
PFraction operator/(int i, const PFraction &f)                  {
    return PFraction(f._num, i * f._den);
}

PFraction operator-(const PFraction &f)                         {
    return PFraction(-f._num, f._den);
}

