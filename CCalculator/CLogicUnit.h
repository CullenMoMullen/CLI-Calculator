#pragma once

#include "CRegister.h"
class CCalculator;
class CRegister;
class COperation;
class CMultiply;
class CAdd;
class CDivide;
class CSubtract;
class CExponentiate;

class CLogicUnit
{
public:
	void Reset();
	void OnEnter();
	void OnDecimalPoint();
	void OnOpenParenthesis();
	double OnCloseParenthesis();
	void OnExponent();
	void OnMultiply();
	void OnDivide();
	void OnAdd();
	void OnSubtract();
	void OnDigit(const int& digit);
	double GetDisplayValue();
	CLogicUnit(CCalculator* pCalc);
	~CLogicUnit();

private:
	CCalculator* m_pCalc;
	CRegister m_DisplayReg;
	CRegister m_AddReg;
	CRegister m_MultiplyReg;
	CRegister m_ExponentReg;
	COperation* m_pExponentiate;
	COperation* m_pMultiplyDivide;
	COperation* m_pAddSubtract;

	friend class CMultiply;
	friend class CDivide;
	friend class CAdd;
	friend class CSubtract;
	friend class CExponentiate;

};

