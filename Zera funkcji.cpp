//Dawid Oleksy
#include <iostream>   
#include <math.h>

using namespace std;




double secant(double (*f)(double),double a,double b,int M,double delta,double fa,double fb)
{
    double xm, x0, c,fa1,fb1;
    double max1=M;
 fa1=fa;
 fb1=fb;
 double fx0;
        do {
			
            
            x0 = (a * fb1 - b * fa1) / (fb1 - fa1);
            fx0=(*f)(x0);max1-=1;if(max1==0){return x0;}
            c = fa *fx0;
 
           
            a = b;
            b = x0;
            fa1=fb1;
            fb1=fx0;
            if (c == 0)
                return x0;
            xm = (a * fb1 - b * fa1) / (fb1 - fa1);
            
        } while (fabs(xm - x0) > delta); 
                                
       
    
     return x0;
}
 double bisection(double (*f)(double),double a,double b,int M,double eps,double delta,double fa,double fb)
{

    bool p=true;
    double fa1,fc;
    double max1=M;
    fa1=fa;
    double c=(a+b)/2;
    fc=(*f)(c);max1-=1;if(max1==0)return c;
 
    while (fabs(fc)>eps)
    {
		
		if(fabs(a-b)<0.10){double fb1=(*f)(b);max1-=1;if(max1==0)return c; return secant(*f,a,b,M,delta,fa,fb1);};
		
        if(p==true)
        {p=false;}
        
        else
        {c = (a+b)/2;
        fc=(*f)(c);max1-=1;if(max1==0)return c;}
        
        if (fc==0)
           return c;
 
       
        else if (fc*fa1 < 0)
            b = c;
        else
            {a = c;
            
            
            fa1=fc;}
  
    }
  return c;
}
 
 
 
 
 
double wyznaczMiejsceZerowe(double (*f)(double),double a,double b,int M,double eps,double delta)
{
	;
	
	double fb=(*f)(b);
	double fa=(*f)(a);
	if(fa==0) return a;
	if(fb==0) return b;
	M=M-2;
	if(M==0) return (b - (((fb*(b-a)))/(fb-fa)));
	if(fa * fb>0) return secant(*f,a,b,M,delta,fa,fb);
	if(fa * fb<=0)
	{
		
		
	return bisection(*f,a,b,M,eps,delta,fa,fb);
	}
	
	
	
	
};

	

	

	

