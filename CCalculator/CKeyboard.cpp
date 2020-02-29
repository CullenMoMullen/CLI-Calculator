#include "CKeyboard.h"
#include <iostream>

using namespace std;


CKeyboard::CKeyboard(CCalculator* pCalc):m_pCalc(pCalc)
{
}

CKeyboard::~CKeyboard()
{
}

double CKeyboard::getKey() const
{
	CLogicUnit* pLogicUnit = m_pCalc->getLogicUnit();
	char chKey = 0;
	bool bExit = false;

	while (!bExit) {
		chKey = cin.get();
	
		switch (chKey) {
			case '0':
			case '1':
			case '2':
			case '3':
			case '4':
			case '5':
			case '6':
			case '7':
			case '8':
			case '9':
				pLogicUnit->OnDigit(chKey - '0');
				break;
			case '.':
				pLogicUnit->OnDecimalPoint();
				break;
			case '(':
				pLogicUnit->OnOpenParenthesis();
				break;
			case ')':
				return pLogicUnit->OnCloseParenthesis();
				break;
			case '*':
				pLogicUnit->OnMultiply();
				break;
			case '/':
				pLogicUnit->OnDivide();
				break;
			case '+':
				pLogicUnit->OnAdd();
				break;
			case '-':
				pLogicUnit->OnSubtract();
				break;
			case 'q':
			case 'Q':
				bExit = true;
				break;
			case 'c':
			case 'C':
				pLogicUnit->Reset();
				break;
			case '\n':
				pLogicUnit->OnEnter();
				break;
			case '^':
				pLogicUnit->OnExponent();
				break;
			default:
				bExit = true;
				break;
		}
	
	
	
	
	}

	return pLogicUnit->GetDisplayValue();

}
