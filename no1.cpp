#include <bits/stdc++.h>

using namespace std;

#define fx(x) (pow(x, 2)) / (1 + (pow(x, 2)));

float yp, p;

float error_relative(float real_n, float newton_n)
{
    return fabs((real_n - newton_n) / real_n) * 100;
}

float fx_orde_4(float a0, float a1, float a2, float a3, float a4, float x)
{
    return a0 +
           (a1 * (x)) +
           (a2 * (x) * (x - 1)) +
           (a3 * (x) * (x - 1) * (x - 2)) +
           (a4 * (x) * (x - 1) * (x - 2) * (x - 3));
}

void lagrange_interpolation(float x[], float y[], float x0, float n)
{
    yp = 0;
    for (int i = 0; i < n; i++)
    {
        p = 1;
        for (int j = 0; j < n; j++)
            if (i != j)
                p = (x0 - x[j]) / (x[i] - x[j]);
        yp = yp + p * y[i];
    }
    cout << "nilai di " << x0 << ": " << yp << endl;
}

int main()
{

    float n = 5;
    float x[] = {0, 1, 2, 3, 4};
    float x_lagrange[] = {0, 1, 2, 3, 4};
    float y[4][4];
    float y_lagrange[] = {0, 0.5, 0.8, 0.9, 0.941176};
    y[0][0] = 0;
    y[1][0] = 0.5;
    y[2][0] = 0.8;
    y[3][0] = 0.9;
    y[4][0] = 0.941176;

    float a[4];

    unsigned int adder = 1;

    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n - i; j++)
        {
            y[j][i] = (y[j + 1][i - 1] - y[j][i - 1]) /
                      (x[j + adder] - x[j]);
        }
        adder++;
    }

    for (int i = 0; i < n; i++)
    {
        cout << setw(4) << x[i]
             << "\t";
        for (int j = 0; j < n - i; j++)
            cout << setw(17) << y[i][j] << "\t";

        cout << endl;
    }
    cout << "NOMOR 1 a: " << endl;
    for (int i = 0; i < n; i++)
    {
        a[i] = y[0][i];
        cout << "a[" << i << "] = " << a[i] << endl;
    }

    cout << "Nomor 1 b: " << endl;

    float f1 = fx_orde_4(a[0], a[1], a[2], a[3], a[4], 2.3);
    float f2 = fx_orde_4(a[0], a[1], a[2], a[3], a[4], 3.7);

    cout << "fx(2.3) = " << f1 << endl;
    cout << "fx(3.7) = " << f2 << endl;

    cout << "Nomor 1 c: " << endl;

    float f1_2 = fx(2.3);
    float f2_2 = fx(3.7);
    cout << "fx(2.3) = " << f1_2;
    cout << endl
         << "fx(3.7) = " << f2_2 << endl;
    cout << setw(30) << "newton" << setw(25) << "normal" << setw(25) << "error" << endl;
    cout << "fx(2.3)" << setw(25) << f1 << setw(25) << f1_2 << setw(25) << fabs(f1 - f1_2) << endl;
    cout << "fx(3.7)" << setw(25) << f2 << setw(25) << f2_2 << setw(25) << fabs(f2 - f2_2) << endl;

    cout << "Error Relative (pada x = 2.3): " << error_relative(f1_2, f1) << "%" << endl;
    cout << "Error Relative (pada x = 3.7): " << error_relative(f2_2, f2) << "%" << endl;

    cout << "Nomor 1 d: " << endl;

    lagrange_interpolation(x_lagrange, y_lagrange, 2.3, n);
    lagrange_interpolation(x_lagrange, y_lagrange, 3.7, n);

    return 0;
}