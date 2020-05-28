#include "MatrixBase.h"

void MatrixBase :: operator *= (int iMult)
{
    for (int i = 0; i < m_size; ++i)
        for (int j = 0; j < m_size; ++j)
            element(i, j) *= iMult;
}

void MatrixBase :: operator += (MatrixBase& iAdd)
{
    for (int i = 0; i < m_size; ++i) 
        for (int j = 0; j < m_size; ++j) 
            element(i, j) += iAdd.element(i,j);
}

 std::ostream& operator<<(std::ostream& stream, const MatrixBase& iMatrix)
{
     for (int i = 0; i < iMatrix.m_size; i++)
     {
         for (int j = 0; j < iMatrix.m_size; j++)
             stream << std::to_string(iMatrix.element(i, j)) << " ";
         stream << "\n\n";
     }
     return stream;
}