//Dawid Oleksy
#include <iostream>
#include <cstdlib>
#include <cmath>
#include <math.h>
#include <string.h>

using namespace std;

//SOR FOR SPARSE-BANDED MATRIXES,
// a1 c1 0  0
// b1 a2 c2 0 
// 0  b2 a3 c3
// 0  0  b3 a4
//
// M, number of bands
// N x N, size of A
// max_tries, number of iterations
// w is parameter of SOR


//EDIT:przyk³adowy 1 i 2 ok

class Sparse_and_Band_matrix_SOR {
	
public:
    double **A;
    int N,M,D;                  
    double w;        
    int max_tries;           
    double *x0,*x;

    Sparse_and_Band_matrix_SOR(double **wejscie, int rozmiar, int lb_wsteg, double parmtr, int max_tries1, double *x0_1, double *x1) {
        A = wejscie;
        N = rozmiar;M = lb_wsteg;D = M / 2;w = parmtr;
        max_tries = max_tries1;
        x0 = x0_1;x = x1;
    }

    double traverse_thru_matrix(int i, int j) {
        int dij = i - j;
        if (abs(dij) > M / 2)
         return 0;
        else {
         if (dij == 0)
         return A[D][j];
         if (dij > 0)
         return A[D + dij][i - dij];
           else return A[D + dij][i];
        }
    }
    void print_sparseband_matrix() {
        for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
         cout << traverse_thru_matrix(i, j) << " ";
            }
            cout << endl;
        }
    }
     void print_Vector() {
      for (int i = 0; i < N; i++) {
       cout << x0[i] << " ";
        }
    }
 double *count_R() {
        double *V = new double[N];
        for (int i = 0; i < N; i++) {
         double wysz = traverse_thru_matrix(i, i);
         V[i] = (wysz - wysz * w) * x0[i];
         for (int j = i+1; j <= min(i + M / 2, N - 1); j++) {
           double temp_pa = traverse_thru_matrix(i, j);
            temp_pa = -w * temp_pa;
            V[i] += temp_pa * x0[j];
            }
            V[i] += w * x[i];
        }
        return V;
        }
        
        
 void main_f() {
        for (int t = 0; t < max_tries; t++) {
        double *b = count_R();
        double *V = new double[N];
        for (int i = 0; i < N; i++) {
        V[i] = b[i];
        for (int j = max(0,i-M/2); j < i; j++) {
        double temp_pa = traverse_thru_matrix(i, j);
        V[i] -= w * V[j] * temp_pa;
         }
        double temp_pa = traverse_thru_matrix(i, i);
        V[i] = V[i] / temp_pa;
           }
        x0 = V;
        }
    }

};

int main() {
    int N,M;
    cin >> N;
    cin >> M;
    double **A = new double *[M];
    double y[N],x[N];
    double w;
    int max_tries,band_length = N - (M - 1) / 2;
    for (int i = 0; i < M / 2 + 1; i++) { //spsb wpisu wsteg
        double *band = new double[band_length];
        for (int q = 0; q < band_length; q++) {
        double temp_pa;
        cin >> temp_pa;
        band[q] = temp_pa;
        }
        A[i] = band;
        band_length++;
    }

    band_length = band_length - 2;
    for (int l = 0; l < M / 2; l++) {
        double *band = new double[band_length];
        for (int q = 0; q < band_length; q++) {
        double temp_pa;
        cin >> temp_pa;
        band[q] = temp_pa;
        }
        A[l + M / 2 + 1] = band;
        band_length--;
    }

    for (int q = 0; q < N; q++) {
    double temp_pa;
    cin >> temp_pa;
    y[q] = temp_pa;
    }

    for (int z = 0; z < N; z++) {
    double temp_pa;
    cin >> temp_pa;
    x[z] = temp_pa;
    }
    cin >> w;
    cin >> max_tries;
    Sparse_and_Band_matrix_SOR macierz_wejsciowa(A, N, M, w, max_tries, x, y);
    cout.precision(16);
    cout<<scientific;
    macierz_wejsciowa.main_f();
    macierz_wejsciowa.print_Vector();
    return 0;
}


