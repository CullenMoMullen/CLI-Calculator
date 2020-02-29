#include "CExponentiate.h"
#include "CLogicUnit.h"
#include <math.h>

void CExponentiate::DoOperation(CLogicUnit* pLogicUnit)
{
	pLogicUnit->m_ExponentReg ^= pLogicUnit->m_DisplayReg;
	pLogicUnit->m_DisplayReg = pLogicUnit->m_ExponentReg;
}
