#pragma once
class CLogicUnit;

class COperation
{
public:
	COperation();
	virtual ~COperation();
	virtual void DoOperation(CLogicUnit* pLogicUnit) = 0;
};

