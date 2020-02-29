#pragma once

#include "COperation.h"

class CLogicUnit;
class CMultiply :
	public COperation
{
	// Inherited via COperation
	virtual void DoOperation(CLogicUnit* pLogicUnit);
};

