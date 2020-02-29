#pragma once

class CCalculator;
class CRegister;

class CDisplay
{
public:
	CDisplay(CCalculator* pCalc);
	virtual ~CDisplay();
	void ShowRegister(CRegister& rReg);

private:
	CCalculator* m_pCalc;
};

