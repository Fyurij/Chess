#pragma once
#include <string>

class Figure
{
protected:
	int i;
	int j;
public:
	Figure(int i_, int j_)
		:i(i_)
		, j(j_)
	{}
	int getI()
	{
		return i;
	}
	int getJ()
	{
		return j;
	}
	virtual void Move(int i_, int j_) = 0;
	virtual bool FigureCheck(int x, int y) = 0;
	virtual std::string GetSymbol(int x, int y) = 0;
};
