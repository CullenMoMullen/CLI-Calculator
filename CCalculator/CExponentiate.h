#pragma once
#include "COperation.h"

class CLogicUnit;

class CExponentiate :
	public COperation
{
	// Inherited via COperation
	virtual void DoOperation(CLogicUnit* pLogicUnit);

	
};

