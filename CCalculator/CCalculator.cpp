#include "CCalculator.h"
#include "CDisplay.h"
#include "CLogicUnit.h"
#include "CKeyboard.h"


CCalculator::CCalculator()
{
	m_pDisplay = new CDisplay(this);
	m_pKeyboard = new CKeyboard(this);
	m_pLogicUnit = new CLogicUnit(this);
}

CCalculator::~CCalculator()
{
	delete m_pDisplay;
	delete m_pKeyboard;
	delete m_pLogicUnit;
}

CCalculator::CCalculator(const CCalculator& rCalc)
{
}

CCalculator& CCalculator::operator=(const CCalculator& rhs)
{
	// TODO: insert return statement here
	return *this;
}

CKeyboard* CCalculator::getKeyBoard()
{
	return m_pKeyboard;
}

CLogicUnit* CCalculator::getLogicUnit()
{
	return m_pLogicUnit;
}

CDisplay* CCalculator::getDisplay()
{
	return m_pDisplay;
}

double CCalculator::Run() const
{
	return m_pKeyboard->getKey();
}
