#pragma once
#include "COperation.h"

class CLogicUnit;

class CSubtract :
	public COperation
{
	// Inherited via COperation
	virtual void DoOperation(CLogicUnit* pLogicUnit);
};

