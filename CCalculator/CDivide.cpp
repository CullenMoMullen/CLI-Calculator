#include "CDivide.h"
#include "CLogicUnit.h"

void CDivide::DoOperation(CLogicUnit* pLogicUnit)
{
	pLogicUnit->m_MultiplyReg /= pLogicUnit->m_DisplayReg;
	pLogicUnit->m_DisplayReg = pLogicUnit->m_MultiplyReg;
}
