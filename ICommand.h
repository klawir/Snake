#pragma once
#include "libraries.h"

class ICommand
{
public:
	virtual void Execute() = 0;
};