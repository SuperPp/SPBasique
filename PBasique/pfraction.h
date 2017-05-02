#ifndef PFRACTION_H
#define PFRACTION_H

#include <iostream>
#include <numeric>

inline int pgcd(int a, int b){    return b ? pgcd(b, a%b) : a;
}

class PFraction
{
protected:
    int _num;
    int _den;
    void reduce();
public:
    PFraction();
    explicit PFraction(int num);
    explicit PFraction(int num, int den);
    PFraction(const PFraction &other);

    int num() const;
    void setNum(int num);
    int den() const;
    void setDen(int den);

    PFraction abs();

    operator double() const;
    void print(std::ostream &os) const;

    PFraction& operator+=(const PFraction &other);
    PFraction& operator+=(int i);
    PFraction& operator-=(const PFraction &other);
    PFraction& operator-=(int i);
    PFraction& operator*=(const PFraction &other);
    PFraction& operator*=(int i);
    PFraction& operator/=(const PFraction &other);
    PFraction& operator/=(int i);

    friend PFraction operator+(const PFraction &f1, const PFraction &f2);
    friend PFraction operator+(const PFraction &f, int i);
    friend PFraction operator+(int i, const PFraction &f);
    friend PFraction operator-(const PFraction &f1, const PFraction &f2);
    friend PFraction operator-(const PFraction &f, int i);
    friend PFraction operator-(int i, const PFraction &f);
    friend PFraction operator*(const PFraction &f1, const PFraction &f2);
    friend PFraction operator*(const PFraction &f, int i);
    friend PFraction operator*(int i, const PFraction &f);
    friend PFraction operator/(const PFraction &f1, const PFraction &f2);
    friend PFraction operator/(const PFraction &f, int i);
    friend PFraction operator/(int i, const PFraction &f);

    friend PFraction operator-(const PFraction &f);

    friend bool operator==(const PFraction &f1, const PFraction &f2);
    friend bool operator==(const PFraction &f, int i);
    friend bool operator==(int i, const PFraction &f);
    friend bool operator!=(const PFraction &f1, const PFraction &f2);
    friend bool operator!=(const PFraction &f, int i);
    friend bool operator!=(int i, const PFraction &f);
    friend bool operator<=(const PFraction &f1, const PFraction &f2);
    friend bool operator<=(const PFraction &f, int i);
    friend bool operator<=(int i, const PFraction &f);
    friend bool operator>=(const PFraction &f1, const PFraction &f2);
    friend bool operator>=(const PFraction &f, int i);
    friend bool operator>=(int i, const PFraction &f);
    friend bool operator<(const PFraction &f1, const PFraction &f2);
    friend bool operator<(const PFraction &f, int i);
    friend bool operator<(int i, const PFraction &f);
    friend bool operator>(const PFraction &f1, const PFraction &f2);
    friend bool operator>(const PFraction &f, int i);
    friend bool operator>(int i, const PFraction &f);
};

template<class T>
auto operator<<(std::ostream& os, const T& t) -> decltype(t.print(os), os)
{
    t.print(os);
    return os;
}
#ifdef QDEBUG_H

#endif

#endif // PFRACTION_H
