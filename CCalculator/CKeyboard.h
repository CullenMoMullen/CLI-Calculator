#pragma once

#include "CCalculator.h"
#include "CDisplay.h"
#include "CLogicUnit.h"
#include "CRegister.h"

class CCalculator;

class CKeyboard
{
public:
	CKeyboard(CCalculator* pCalc);
	virtual ~CKeyboard();
	double getKey() const;

private:
	CCalculator* m_pCalc;

};

