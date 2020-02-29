#pragma once


class CRegister
{
public:
	CRegister();
	~CRegister();
	void OnDecimalPoint();
	void OnDigit(const int& digit);
	void Reset();
	void SetBeginValue();
	double Get() const;
	void Set(const double& vlaue);
	CRegister& operator+=(const CRegister& rhs);
	CRegister& operator-=(const CRegister& rhs);
	CRegister& operator*=(const CRegister& rhs);
	CRegister& operator/=(const CRegister& rhs);
	CRegister& operator^=(const CRegister& rhs);


private:
	double m_Store;
	double m_Factor;
	bool m_bBeginValue;
};