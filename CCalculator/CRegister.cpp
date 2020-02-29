#include "CRegister.h"
#include <math.h>

CRegister::CRegister()
{
	this->Reset();
}

CRegister::~CRegister()
{

}

void CRegister::OnDecimalPoint()
{
	if (m_bBeginValue) {
		m_bBeginValue = false;
		m_Store = 0.0;
	}
	m_Factor = 1.0;
}

void CRegister::OnDigit(const int& digit)
{
	if (m_bBeginValue) {
		m_bBeginValue = false;
		m_Store = 0.0;
		m_Factor = 0.0;
	}
	if (m_Factor > 0.0) {
		m_Factor *= 0.1;
		m_Store += (m_Factor * digit);
	}
	else {
		m_Store *= 10.0;
		m_Store += digit;
	}
}

void CRegister::Reset()
{
	m_Store = 0.0;
	m_Factor = 0.0;
	m_bBeginValue = true;
}

void CRegister::SetBeginValue()
{
	m_bBeginValue = true;
}

double CRegister::Get() const
{
	return m_Store;
}

void CRegister::Set(const double& value)
{
	m_Store = value;
}

CRegister& CRegister::operator+=(const CRegister& rhs)
{
	// TODO: insert return statement here
	m_Store += rhs.m_Store;
	return *this;
}

CRegister& CRegister::operator-=(const CRegister& rhs)
{
	// TODO: insert return statement here
	m_Store -= rhs.m_Store;
	return *this;
}

CRegister& CRegister::operator*=(const CRegister& rhs)
{
	// TODO: insert return statement here
	m_Store *= rhs.m_Store;
	return *this;
}

CRegister& CRegister::operator/=(const CRegister& rhs)
{
	// TODO: insert return statement here
	m_Store /= rhs.m_Store;
	return *this;
}

CRegister& CRegister::operator^=(const CRegister& rhs)
{
	// TODO: insert return statement here
	m_Store = pow(m_Store, rhs.m_Store);
	return *this;
}
