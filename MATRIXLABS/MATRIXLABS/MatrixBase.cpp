#include "MatrixBase.h"

unsigned int MatrixBase::size() const
{
	return m_size;
}

void MatrixBase::operator*=(int iMult)
{
	for (unsigned int i = 0; i < size(); i++)
		for (unsigned int j = 0; j < size(); j++)
			element(i, j) *= iMult;
}
void MatrixBase::operator+=(MatrixBase& iAdd)
{
	for (unsigned int i = 0; i < size(); i++)
		for (unsigned int j = 0; j < size(); j++)
			element(i, j) += iAdd.element(i,j);
}
std::ostream& operator<<(std::ostream& stream, const MatrixBase& iMatrix)
{
	for (unsigned int i = 0; i < iMatrix.size(); i++)
	{
		for (unsigned int j = 0; j < iMatrix.size(); j++)
			stream << std::to_string(iMatrix.element(i, j)) << " ";
		stream << "\n\n";
	}
	return stream;
}