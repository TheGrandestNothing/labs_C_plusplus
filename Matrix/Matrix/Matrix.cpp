// Matrix.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include <iostream>
#include "Matrix2D.h"
#include "Matrix3D.h"

using namespace std;

int main()
{
    Matrix2D m2a, m2b;
    Matrix3D m3a, m3b;

    int cnt = 1;
    for (int i = 0; i < m2a.size(); i++)
        for (int j = 0; j < m2a.size(); j++)
        {
            m2a.element(i, j) = cnt;
            m2b.element(i, j) = cnt++;
        }

    cnt = 1;
    for (int i = 0; i < m3a.size(); i++)
        for (int j = 0; j < m3a.size(); j++)
        {
            m3a.element(i, j) = cnt;
            m3b.element(i, j) = cnt++;
        }

    m2a += m2b;
    m2b *= 10;
    m3a += m3b;
    m3b *= 5;

    cout << m2a << endl;
    cout << m2b << endl;

    cout << m3a << endl;
    cout << m3b << endl;

    return 0;
}
