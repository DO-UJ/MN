//Dawid Oleksy
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <iostream>
using namespace std;

const double eps = 1e-14;

void printVector(const double* x, unsigned N){
    for(unsigned i = 0; i < N; ++i) printf("%17.17f ",x[i]);
    printf("\n");
}
typedef void (*FuncPointer)(const double* x, double* y, double* Df);


int findCurve(FuncPointer f, double* x, unsigned k, double h)
{
    for(int i=1;i<=k;i++)
    {
    double x_0 = x[0];
    double y_0 = x[1];
    double c = x[2]+ i*h;
    int max_iter=1000000;
    while(true)
    {
        if(max_iter == 0) return i;

        double Df[6];
        double war[2];
        double x1[3] = {x_0,y_0,c};

        f(x1,war,Df);
        double wyzn = Df[0]*Df[4] - Df[1]*Df[3];
        if(fabs(wyzn)<eps ) return i;

        if(max(fabs(war[0]),fabs(war[1]))<eps)break;

        swap(Df[0],Df[4]);
        Df[1]= Df[1] * -1;
        Df[3]= Df[3] * -1;

        x_0 = x_0 - (war[0]*Df[0] + war[1]*Df[1])/wyzn;
        y_0 = y_0 - (war[0]*Df[3] + war[1]*Df[4])/wyzn;
        max_iter--;

    }
    const double x_wynik[3] = {x_0,y_0,c};
    printVector(x_wynik,3);
    }

 return 0;
}

int findSurface(FuncPointer f, double* x, unsigned k1, unsigned k2, double h1, double h2)
{

    for(int i = 1;i<=k1;i++)
    {
        for(int j = 1;j<=k2;j++)
        {
            double x_0 = x[0];
            double c = x[1] + i*h1;
            double d = x[2] + j*h2;
            int max_iter = 1000000;

            while(true)
            {
                if(max_iter==0)
                return i*k1+j;

                double Df[3];
                double y;
                double x_f[3] = {x_0,c,d};
                f(x_f,&y,Df);

                if(fabs(y)< eps)
                    {printVector(x_f,3);break;}

                if(fabs(Df[0]) <eps)
                return i*k1+j;

                x_0 = x_0 - y/Df[0];
                max_iter--;           
            }
        }
    printf("\n");
    }
return 0;
}

int findFixedPoints(FuncPointer f,double* x,unsigned k1,unsigned k2,double h1,double h2)
{
    for(int i = 1;i<=k1;i++)
    {
        for(int j = 1;j<=k2;j++)
        {
            double x_0 = x[0];
            double y_0 = x[1];
            double a = x[2] + h1*i;
            double b = x[3] + h2*j;
            int max_iter = 1000000;
            while(true){
                if(max_iter==0)return i*k1+j;
                double Df[8];
                double x1[4] = {x_0,y_0,a,b};
                double war[2];

                f(x1,war,Df);       /* Df[0],Df[1],Df[2],Df[3]
                                       Df[4],Df[5],Df[6],Df[7] */ 
                war[0] -=x1[0];
                war[1] -=x1[1];             
                Df[0] -= 1.0;
                Df[5] -= 1.0;
                double wyzn = Df[0] * Df[5] - Df[1] * Df[4];

                if(fabs(wyzn)<eps)return i*k1+j;
                if(max(fabs(war[0]),fabs(war[1]))<eps)break;
                Df[1] = Df[1] * -1.0;
                Df[4] = Df[4] * -1.0;

                x_0 = x_0 - (war[0]*Df[5] + war[1]*Df[1])/wyzn;
                y_0 = y_0 - (war[0]*Df[4] + war[1]*Df[0])/wyzn;
                max_iter--;


                    }
             const double x_wynik[4] = {x_0,y_0,a,b};
             printVector(x_wynik,4); 
             

        }
        printf("\n");
    }
return 0;
}