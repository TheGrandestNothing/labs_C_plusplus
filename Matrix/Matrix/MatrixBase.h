#pragma once
#include <fstream>
#include <string>

class MatrixBase
{
public:
	unsigned int size() const
	{
		return m_size;
	}
	MatrixBase() = delete;
	virtual int element(unsigned int i, unsigned int j) const = 0;
	virtual int& element(unsigned int i, unsigned int j) = 0;
	void operator *= (int iMult);
	void operator += (MatrixBase& iAdd);
	friend std::ostream& operator<<(std::ostream& stream, const MatrixBase& iMatrix);
protected:
	 MatrixBase(unsigned int iSize) : m_size(iSize) {}
private:
	const unsigned int m_size;
};

