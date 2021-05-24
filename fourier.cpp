#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#include <cstdlib>
#include <cstdio>
#include <fstream>

using namespace std;

struct Complex {
    double Re, Im;
    Complex();
    Complex(double Re);
    Complex(double Re, double Im);
    Complex operator+(const Complex &right) const;
    Complex operator-(const Complex &right) const;
    Complex operator/(const double right) const;
    Complex operator*(const double right) const;
    Complex operator^(const double alpha) const;
};

Complex::Complex() {
    Re = 0;
    Im = 0;
}

Complex::Complex(double Re) {
    Complex::Re = Re;
    Im = 0;
}

Complex::Complex(double Re, double Im) {
    Complex::Re = Re;
    Complex::Im = Im;
}

Complex Complex::operator +(const Complex &right) const {
    return Complex(Re + right.Re, Im + right.Im);
}

Complex Complex::operator -(const Complex &right) const {
    return Complex(Re - right.Re, Im - right.Im);
}

Complex Complex::operator /(const double right) const {
    return Complex(Re / right, Im / right);
}

Complex Complex::operator *(const double right) const {
    return Complex(Re * right, Im * right);
}

Complex Complex::operator ^(const double alpha) const {
    return Complex(Re * cos(alpha) - Im * sin(alpha), Im * cos(alpha) + Re * sin(alpha));
}


//                          ********Fourier Transform********
std::vector<Complex> FT(const std::vector<Complex> &f) {
    std::vector<Complex> c;
    int n = f.size();
    c.resize(n);
    for (int k = 0; k < n; ++k) {
        for (int j = 0; j < n; ++j) {
            c[k] = c[k] + (f[j] ^ (((-2) * M_PI * k * j) / n));
        }
        c[k] = c[k] / n;
    }
    return c;
}

std::vector<Complex> IFT(const std::vector<Complex> &c) {
    std::vector<Complex> f;
    int n = c.size();
    f.resize(n);
    for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
            f[j] = f[j] + (c[k] ^ ((2 * M_PI * k * j) / n));
        }
    }
    return f;
}

//                          ******Fast Fourier Transform*******
void FFT_rec(std::vector<Complex> &f) {
    std::vector<Complex> even, odd;
    int n = f.size();
    if (n == 1) {
	return;
    }
    even.resize(n / 2);
    odd.resize(n / 2);
    for (int i = 0; i < n / 2; i++) {
	even[i] = f[i * 2];
	odd[i] = f[i * 2 + 1];
    }
    FFT_rec(even);
    FFT_rec(odd);
    for (int i = 0; i < n / 2; i++) {
        Complex var = odd[i] ^ ((-2 * M_PI * i) / n);
        f[i] = even[i] + var;
        f[i + n / 2] = even[i] - var;
    }
}

void FFT(std::vector<Complex> &f) {
    int size = f.size();
    int n = 1;
    while (size > n) {
        n = n * 2;
    }
    f.resize(n);
    for (int i = size; i < n; i++) {
        f[i] = 0;
    }
    FFT_rec(f);
}


std::vector<Complex> IFFT(std::vector<Complex> &c) {
    std::vector<Complex> f;
    int n = c.size();
    f.resize(n);
    for (int j = 0; j < n; ++j) {
        for (int k = 0; k < n; ++k) {
            f[j] = f[j] + (c[k] ^ ((2 * M_PI * k * j) / n));
        }
        f[j] = f[j] / 8;
    }
    return f;
}

void printVector(std::vector<Complex> vector) {
    for (int i = 0; i < vector.size(); i++) {
        cout << "Re: " << fixed << setprecision(3) << vector[i].Re << ' ';
        cout << "Im: " << fixed << setprecision(3) << vector[i].Im << endl;
    }
    cout << endl;
}

int main(int argc, const char** argv) {
    std::vector<Complex> function({1, 6, 2, 5, 3, 4, 5, 8});
    std::cout << "Start function:" << std::endl;
    printVector(function);
    
    std::cout << "*****Fourier Transform*****" << std::endl;
    
    std::vector<Complex> spectr = FT(function);
    std::cout << "Spectr:" << std::endl;
    printVector(spectr);
    std::vector<Complex> finalFunction = IFT(spectr);
    std::cout << "Final function:" << std::endl;
    printVector(finalFunction);
    
    std::cout << "*****Fast Fourier Transform*****" << std::endl;
    
    FFT(function);
    std::cout << "Spectr:" << std::endl;
    printVector(function);
    finalFunction = IFFT(function);
    std::cout << "Final Function:" << std::endl;
    printVector(finalFunction);
    return 0;
}
