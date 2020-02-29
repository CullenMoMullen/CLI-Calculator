#include "CMultiply.h"
#include "CLogicUnit.h"

void CMultiply::DoOperation(CLogicUnit* pLogicUnit)
{
	pLogicUnit->m_MultiplyReg *= pLogicUnit->m_DisplayReg;
	pLogicUnit->m_DisplayReg = pLogicUnit->m_MultiplyReg;
}
