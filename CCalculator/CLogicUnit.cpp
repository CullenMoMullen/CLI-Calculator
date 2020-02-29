#include "CLogicUnit.h"
#include "CCalculator.h"
#include "CRegister.h"
#include "CSubtract.h"
#include "CAdd.h"
#include "CMultiply.h"
#include "CDivide.h"
#include "CExponentiate.h"
#include "CDisplay.h"

CLogicUnit::CLogicUnit(CCalculator* pCalc)
{
	m_pCalc = pCalc;
	Reset();
}

CLogicUnit::~CLogicUnit()
{
	delete m_pMultiplyDivide;
	delete m_pAddSubtract;
}

void CLogicUnit::Reset()
{
	m_MultiplyReg.Reset();
	m_AddReg.Reset();
	m_DisplayReg.Reset();

	delete m_pMultiplyDivide;
	delete m_pAddSubtract;

	m_pAddSubtract = nullptr;
	m_pMultiplyDivide = nullptr;
}

void CLogicUnit::OnEnter()
{
	if (m_pExponentiate) {
		m_pExponentiate->DoOperation(this);
		delete m_pExponentiate;
		m_pExponentiate = nullptr;
	}

	if (m_pMultiplyDivide) {
		m_pMultiplyDivide->DoOperation(this);
		delete m_pMultiplyDivide;
		m_pMultiplyDivide = nullptr;
	}

	if (m_pAddSubtract) {
		m_pAddSubtract->DoOperation(this);
		delete m_pAddSubtract;
		m_pAddSubtract = nullptr;
	}
	m_pCalc->getDisplay()->ShowRegister(m_DisplayReg);
	m_DisplayReg.SetBeginValue();
}

void CLogicUnit::OnDecimalPoint()
{
	m_DisplayReg.OnDecimalPoint();
}

double CLogicUnit::OnCloseParenthesis()
{
	if (m_pExponentiate) {
		m_pExponentiate->DoOperation(this);
		delete m_pExponentiate;
		m_pExponentiate = nullptr;
	}

	if (m_pMultiplyDivide) {
		m_pMultiplyDivide->DoOperation(this);
		delete m_pMultiplyDivide;
		m_pMultiplyDivide = nullptr;
	}

	if (m_pAddSubtract) {
		m_pAddSubtract->DoOperation(this);
		delete m_pAddSubtract;
		m_pAddSubtract = nullptr;
	}
	return m_DisplayReg.Get();
}

void CLogicUnit::OnOpenParenthesis()
{
	CCalculator* pCalc = new CCalculator();
	m_DisplayReg.Set(pCalc->Run());
	delete pCalc;
}

void CLogicUnit::OnExponent()
{
	if (m_pExponentiate) {
		m_pExponentiate->DoOperation(this);
		delete m_pExponentiate;
	}
	else {
		m_ExponentReg = m_DisplayReg;
	}
	m_pExponentiate = new CExponentiate();
	m_DisplayReg.SetBeginValue();
}

void CLogicUnit::OnMultiply()
{
	if (m_pMultiplyDivide) {
		m_pMultiplyDivide->DoOperation(this);
		delete m_pMultiplyDivide;
	}
	else {
		m_MultiplyReg = m_DisplayReg;

	}

	m_pMultiplyDivide = new CMultiply();
	m_DisplayReg.SetBeginValue();

}

void CLogicUnit::OnDivide()
{
	if (m_pMultiplyDivide) {
		m_pMultiplyDivide->DoOperation(this);
		delete m_pMultiplyDivide;
	}
	else {
		m_MultiplyReg = m_DisplayReg;
	}

	m_pMultiplyDivide = new CDivide();
	m_DisplayReg.SetBeginValue();
}

void CLogicUnit::OnAdd()
{
	if (m_pMultiplyDivide) {
		m_pMultiplyDivide->DoOperation(this);
		delete m_pMultiplyDivide;
		m_pMultiplyDivide = nullptr;
	}

	if (m_pAddSubtract) {
		m_pAddSubtract->DoOperation(this);
		delete m_pAddSubtract;
	}
	else {
		m_AddReg = m_DisplayReg;
	}

	m_pAddSubtract = new CAdd();
	m_DisplayReg.SetBeginValue();
}

void CLogicUnit::OnSubtract()
{
	if (m_pMultiplyDivide) {
		m_pMultiplyDivide->DoOperation(this);
		delete m_pMultiplyDivide;
		m_pMultiplyDivide = nullptr;
	}

	if (m_pAddSubtract) {
		m_pAddSubtract->DoOperation(this);
		delete m_pAddSubtract;
	}
	else {
		m_AddReg = m_DisplayReg;
	}

	m_pAddSubtract = new CSubtract();
	m_DisplayReg.SetBeginValue();
}

void CLogicUnit::OnDigit(const int& digit)
{
	m_DisplayReg.OnDigit(digit);
}


double CLogicUnit::GetDisplayValue() {
	return m_DisplayReg.Get();
}