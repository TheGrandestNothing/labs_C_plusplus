
#include <iostream>
#include "Matrix2D.h"
#include "Matrix3D.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    Matrix2D m2a, m2b;
    Matrix3D m3a, m3b;
    int cnt = 1;
    for (unsigned int i = 0; i < m2a.size(); i++)
        for (unsigned int j = 0; j < m2a.size(); j++)
        {
            m2a.element(i, j) = cnt;
            m2b.element(i, j) = cnt++;
        }
    cnt = 1;
    for (unsigned int i = 0; i < m3a.size(); i++)
        for (unsigned int j = 0; j < m3a.size(); j++)
        {
            m3a.element(i, j) = cnt;
            m3b.element(i, j) = cnt++;
        }
    cout << "Первая 2д матрица " << endl << m2a;

    cout << "Вторая 2д матрица " << endl << m2b;

    cout << "Первая 3д матрица " << endl << m3a;

    cout << "Вторая 3д матрица " << endl << m3a;


    m2a += m2b;
    m2b *= 10;
    m3a += m3b;
    m3b *= 5;
    cout << "Первая 2д матрица  + вторая" << endl;
    cout << m2a << endl;
    cout << "Вторая 2д матрица умноженная на 10" << endl;
    cout << m2b << endl;
    cout << "Первая 3д матрица + вторая" << endl;
    cout << m3a << endl;
    cout << "Вторая 3д матрица умноженная на 5" << endl;
    cout << m3b << endl;

    return 0;
}
