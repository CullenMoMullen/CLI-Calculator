#include <iostream>
#include <iomanip>
#include "CDisplay.h"
#include "CRegister.h"
using namespace std;

CDisplay::CDisplay(CCalculator* pCalc) : m_pCalc(pCalc)
{
}

CDisplay::~CDisplay()
{
}

void CDisplay::ShowRegister(CRegister& rReg)
{
	cout << endl << setw(12) << rReg.Get() << endl;
}
