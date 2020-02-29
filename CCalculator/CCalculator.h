#pragma once

class CDisplay;
class CKeyboard;
class CLogicUnit;

class CCalculator
{
public:
	CCalculator();
	virtual ~CCalculator();
	CCalculator(const CCalculator& rCalc);
	CCalculator& operator=(const CCalculator& rhs);


	CKeyboard* getKeyBoard();
	CLogicUnit* getLogicUnit();
	CDisplay* getDisplay();
	double Run() const;

private:
	CKeyboard* m_pKeyboard;
	CLogicUnit* m_pLogicUnit;
	CDisplay* m_pDisplay;
};

