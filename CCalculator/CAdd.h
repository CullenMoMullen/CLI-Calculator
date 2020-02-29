#pragma once
#include "COperation.h"

class CLogicUnit;

class CAdd :
	public COperation
{
	// Inherited via COperation
	virtual void DoOperation(CLogicUnit* pLogicUnit);
};

