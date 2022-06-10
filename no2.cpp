#include <bits/stdc++.h>

using namespace std;

float simpsons13(int t[], float v[], float size)
{
    float summing = 0;
    float y = 0;
    for (int i = 0; i < size / 2 + 1; i++)
    {
        if (i == size / 2)
            y = v[i];
        if (i % 2 == 0 && i != size / 2)
            y = 2 * v[i];
        else if (i % 2 != 0 && i != size / 2)
            y = 4 * v[i];

        summing = summing + y;
    }
    return (size / 2) / 3 * (summing);
}

float simpsons38(int t[], float v[], float size)
{
    float summing = 0;
    float y = 0;
    int pengali = 1;
    for (int j = size / 2; j < size; j++)
    {
        if (j == size / 2 || j == size - 1)
            y = v[j];
        if (pengali <= 2 && j != size / 2 && j != size - 1)
        {
            y = 3 * v[j];
            pengali++;
        }
        else if (pengali == 3 && j != size / 2 && j != size - 1)
        {
            y = 2 * v[j];
            pengali = 0;
        }
        summing = summing + y;
    }
    return (3 * size / 2) / 8 * summing;
}

float percepatan1(int atas, int bawah, int t[], float v[])
{
    return (v[atas] - v[bawah]) / (2 * 4);
}

float percepatan2(int atas, int bawah, int t[], float v[])
{

    return ((-3 * v[0]) + (4 * v[atas]) - v[bawah]) / (2 * 4);
}

int main()
{
    int t[] = {0, 4, 8, 12, 16, 20, 24, 28, 32, 36};
    float v[] = {0, 34.7, 61.8, 82.8, 99.2, 112, 121.9, 129.7, 135.7, 140.4};
    float size;

    size = (sizeof(t) / sizeof(t[0]) - 2);
    cout << simpsons13(t, v, size) << endl;
    cout << simpsons38(t, v, size) << endl;

    cout << "Total nilai: " << simpsons13(t, v, size) + simpsons38(t, v, size) << " m" << endl;

    cout << "Kecepatan pada t = 28s" << endl;

    int full_size = sizeof(t) / sizeof(t[0]);
    int kecepatan = 28 + 4;
    int kecepatanbawah = 28 - 4;

    auto itr = find(t, t + full_size, kecepatan);
    auto itr2 = find(t, t + full_size, kecepatanbawah);

    int batasatas = distance(t, itr);
    int batasbawah = distance(t, itr2);

    cout << "Percepatan pada 28: " << percepatan1(batasatas, batasbawah, t, v) << " m/s^2" << endl;

    int full_size2 = sizeof(t) / sizeof(t[0]);
    int adder = 4;
    auto itr_2 = find(t, t + full_size2, 0 + adder);
    int nilaipertama = distance(t, itr_2);

    auto itr2_2 = find(t, t + full_size2, 2 * adder);
    int nilaikedua = distance(t, itr2_2);

    cout << "Perc pada 0: " << percepatan2(nilaipertama, nilaikedua, t, v) << " m/s^2" << endl;
}