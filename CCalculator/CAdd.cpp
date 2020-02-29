#include "CAdd.h"
#include "CLogicUnit.h"

void CAdd::DoOperation(CLogicUnit* pLogicUnit)
{
	pLogicUnit->m_AddReg += pLogicUnit->m_DisplayReg;
	pLogicUnit->m_DisplayReg = pLogicUnit->m_AddReg;
}
