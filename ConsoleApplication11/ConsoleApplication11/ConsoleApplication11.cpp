#include <iostream>
#include <cstdlib>

class Fraction {
private:
    int num;
    int den;

    int gcd(int a, int b) const {
        a = std::abs(a);
        b = std::abs(b);
        while (b) {
            int t = b;
            b = a % b;
            a = t;
        }
        return a;
    }

    void reduce() {
        if (den == 0) throw "Denominator cannot be zero";
        if (den < 0) { num = -num; den = -den; }
        int g = gcd(num, den);
        num /= g;
        den /= g;
    }

public:
    Fraction(int n, int d) : num(n), den(d) { reduce(); }
    Fraction() : Fraction(0, 1) {}

    void display() const {
        if (den == 1) std::cout << num;
        else std::cout << num << "/" << den;
    }

    Fraction& add(const Fraction& f) {
        num = num * f.den + f.num * den;
        den *= f.den;
        reduce();
        return *this;
    }

    Fraction& sub(const Fraction& f) {
        num = num * f.den - f.num * den;
        den *= f.den;
        reduce();
        return *this;
    }

    Fraction& mul(const Fraction& f) {
        num *= f.num;
        den *= f.den;
        reduce();
        return *this;
    }

    Fraction& add(int x) {
        num += x * den;
        reduce();
        return *this;
    }

    Fraction& sub(int x) {
        num -= x * den;
        reduce();
        return *this;
    }

    Fraction& mul(int x) {
        num *= x;
        reduce();
        return *this;
    }
};

int main() {
    try {
        Fraction a(2, 3);
        Fraction b(1, 4);

        std::cout << "a = "; a.display(); std::cout << std::endl;
        std::cout << "b = "; b.display(); std::cout << std::endl;

        Fraction c(2, 3);
        c.add(b).mul(2).sub(1);
        std::cout << "c = "; c.display(); std::cout << std::endl;

        Fraction d(8, 12);
        std::cout << "8/12 = "; d.display(); std::cout << std::endl;

    }
    catch (const char* msg) {
        std::cerr << msg << std::endl;
    }

    return 0;
}