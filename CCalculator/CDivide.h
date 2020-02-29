#pragma once
#include "COperation.h"

class CLogicUnit;

class CDivide :
	public COperation
{
	// Inherited via COperation
	virtual void DoOperation(CLogicUnit* pLogicUnit);
};

