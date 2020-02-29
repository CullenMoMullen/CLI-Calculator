#include "CSubtract.h"
#include "CLogicUnit.h"


void CSubtract::DoOperation(CLogicUnit* pLogicUnit)
{
	pLogicUnit->m_AddReg -= pLogicUnit->m_DisplayReg;
	pLogicUnit->m_DisplayReg = pLogicUnit->m_AddReg;
}
