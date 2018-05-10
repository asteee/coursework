#include "stdafx.h"
#include "Singleton.h"

Singleton* Singleton::Instance()
{
	if (!_self)
	{
		_self = new Singleton();
	}
	return _self;
}

bool Singleton::DeleteInstance()
{
	if (_self)
	{
		delete _self;
		_self = 0;
		return true;
	}
	return false;
}