#pragma once
#include "Figure.h"
#include <string>

class King : public Figure
{
public:
	King(int i_, int j_)
		:Figure(i_, j_)
	{}
	void Move(int i_, int j_) override;
	bool FigureCheck(int x, int y) override;
	std::string GetSymbol(int x, int y) override;
};

class Queen : public Figure
{
public:
	Queen(int i_, int j_)
		:Figure(i_, j_)
	{}
	void Move(int i_, int j_) override;
	bool FigureCheck(int x, int y) override;
	std::string GetSymbol(int x, int y) override;
};