//Dawid Oleksy
#include<cmath>
#include<iostream>
#include "funkcja.h"

using namespace std;

class dzet
{

public:
     double wartosc;
     double fx;
     double fy;
     double fxy;
     double fxx;
     double fyy;
    dzet();
    dzet(double, int);
    ~dzet();
    dzet(const dzet&);
    dzet operator-() const {
        dzet temp;
        temp.wartosc = -wartosc; temp.fx = -fx; temp.fy = -fy; temp.fxy = -fxy; temp.fxx = -fxx; temp.fyy = -fyy;
        return temp;
    };
    dzet operator=(const dzet& X) {
        wartosc = X.wartosc; fx = X.fx; fy = X.fy; fxy = X.fxy; fxx = X.fxx; fyy = X.fyy;
        return *this;
    }

};

//ostream& operator<< (std::ostream& out, const dzet X) {
  //  cout << fixed;
    //out << setprecision(15 - Cyfry(X.wartosc)) << X.wartosc << " " << setprecision(15 - Cyfry(X.fx)) << X.fx << " " << setprecision(15 - Cyfry(X.fy)) << X.fy << " " << setprecision(15 - Cyfry(X.fxx)) << X.fxx << " " << setprecision(15 - Cyfry(X.fxy)) << X.fxy << " " << setprecision(15 - Cyfry(X.fyy)) << X.fyy << "\n";
    //return out;
//}
dzet::dzet(const dzet& X) { wartosc = X.wartosc; fx = X.fx; fy = X.fy; fxy = X.fxy; fxx = X.fxx; fyy = X.fyy; }

dzet::dzet(double a, int X)
{
    wartosc = a;

    if (X == 1)
    {
        fx = 1; fy = 0;
    }

    else
    {
        fx = 0; fy = 1;
    }
    fxy = 0; fxx = 0; fyy = 0;
}
dzet::dzet()
{
    wartosc = 0; fx = 0; fy = 0; fxy = 0; fxx = 0; fyy = 0;
}
dzet::~dzet()
{
}


dzet operator+(dzet X, dzet Y)
{
    dzet temp;
    temp.wartosc = X.wartosc + Y.wartosc;
    temp.fx = X.fx + Y.fx;
    temp.fy = X.fy + Y.fy;
    temp.fxy = X.fxy + Y.fxy;
    temp.fxx = X.fxx + Y.fxx;
    temp.fyy = X.fyy + Y.fyy;
    return temp;
}

dzet operator-(dzet X, dzet Y)
{
    dzet temp;
    temp.wartosc = X.wartosc - Y.wartosc;
    temp.fx = X.fx - Y.fx;
    temp.fy = X.fy - Y.fy;
    temp.fxy = X.fxy - Y.fxy;
    temp.fxx = X.fxx - Y.fxx;
    temp.fyy = X.fyy - Y.fyy;
    return temp;
}

dzet operator*(dzet X, dzet Y)
{
    dzet temp;
    temp.wartosc = X.wartosc * Y.wartosc;
    temp.fx = X.fx * Y.wartosc + X.wartosc * Y.fx;
    temp.fy = X.fy * Y.wartosc + X.wartosc * Y.fy;
    temp.fxy = X.fx * Y.fy + X.fy * Y.fx + X.fxy * Y.wartosc + X.wartosc * Y.fxy;
    temp.fxx = 2 * X.fx * Y.fx + X.fxx * Y.wartosc + X.wartosc * Y.fxx;
    temp.fyy = 2 * X.fy * Y.fy + X.fyy * Y.wartosc + X.wartosc * Y.fyy;
    return temp;
}

dzet operator/(dzet X, dzet Y)
{
    dzet temp;
    temp.wartosc = X.wartosc / Y.wartosc;
    temp.fx = (X.fx * Y.wartosc - X.wartosc * Y.fx) / (Y.wartosc * Y.wartosc);
    temp.fy = (X.fy * Y.wartosc - X.wartosc * Y.fy) / (Y.wartosc * Y.wartosc);
    temp.fxy = (-Y.wartosc * (X.fx * Y.fy + X.fy * Y.fx + X.wartosc * Y.fxy) + X.fxy * Y.wartosc * Y.wartosc + 2 * X.wartosc * Y.fy * Y.fx) / (Y.wartosc * Y.wartosc * Y.wartosc);
    temp.fxx = (-Y.wartosc * (2 * X.fx * Y.fx + X.wartosc * Y.fxx) + X.fxx * Y.wartosc * Y.wartosc + 2 * X.wartosc * Y.fx * Y.fx) / (Y.wartosc * Y.wartosc * Y.wartosc);
    temp.fyy = (-Y.wartosc * (2 * X.fy * Y.fy + X.wartosc * Y.fyy) + X.fyy * Y.wartosc * Y.wartosc + 2 * X.wartosc * Y.fy * Y.fy) / (Y.wartosc * Y.wartosc * Y.wartosc);
    return temp;
}

dzet operator+(dzet X, double C) { dzet temp; temp.wartosc = C; return X + temp; }
dzet operator+(double C, dzet X) { dzet temp; temp.wartosc = C; return temp+X; }

dzet operator-(dzet X,double C) { dzet temp; temp.wartosc = C; return X - temp; }
dzet operator-(double C, dzet X) { dzet temp; temp.wartosc = C; return temp - X; }

dzet operator*(dzet X,double C) {
    dzet temp; temp.wartosc = C; return X * temp;}
dzet operator*(double C, dzet X) {
    dzet temp; temp.wartosc = C;return temp * X;}
dzet operator/(dzet X,double C) {
    dzet temp; temp.wartosc = C; return X / temp;}
dzet operator/(double C, dzet X) { dzet temp; temp.wartosc = C; return temp / X; }

dzet sin(dzet X)
{
    dzet temp;
    temp.wartosc = sin(X.wartosc);
    temp.fx = X.fx * cos(X.wartosc);
    temp.fy = X.fy * cos(X.wartosc);
    temp.fxy = X.fxy * cos(X.wartosc) - X.fy * X.fx * sin(X.wartosc);
    temp.fxx = X.fxx * cos(X.wartosc) - X.fx * X.fx * sin(X.wartosc);
    temp.fyy = X.fyy * cos(X.wartosc) - X.fy * X.fy * sin(X.wartosc);
    return temp;
}
dzet cos(dzet X)
{
    dzet temp;
    temp.wartosc = cos(X.wartosc);
    temp.fx = X.fx * (-sin(X.wartosc));
    temp.fy = X.fy * (-sin(X.wartosc));
    temp.fxy = X.fy * X.fx * (-cos(X.wartosc)) - X.fxy * sin(X.wartosc);
    temp.fxx = X.fx * X.fx * (-cos(X.wartosc)) - X.fxx * sin(X.wartosc);  
    temp.fyy = X.fy * X.fy * (-cos(X.wartosc)) - X.fyy * sin(X.wartosc);
    return temp;
}
dzet exp(dzet X)
{
    dzet temp;
    temp.wartosc = exp(X.wartosc);
    temp.fx = exp(X.wartosc) * X.fx;
    temp.fy = exp(X.wartosc) * X.fy;
    temp.fxx = (exp(X.wartosc) * X.fx * X.fx) + (X.fxx * exp(X.wartosc));
    temp.fxy = (exp(X.wartosc) * X.fx * X.fy) + (X.fxy * exp(X.wartosc));
    temp.fyy = (exp(X.wartosc) * X.fy * X.fy) + (X.fyy * exp(X.wartosc));
    return temp;
}



int main() {

    cout.precision(17);

    int ilosc;
    cin >> ilosc;
    double a, b;
    for (int i = 0; i < ilosc; i++)
    {
        cin >> a;
        cin >> b;

        dzet X = dzet(a, 1);
        dzet Y = dzet(b, -1);
        dzet wynik = funkcja(X, Y);

        cout << wynik.wartosc << " " << wynik.fx << " " << wynik.fy << " " << wynik.fxx << " " << wynik.fxy << " " << wynik.fyy << endl;
    }
}