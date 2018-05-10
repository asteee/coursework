#pragma once
class Singleton
{
protected:
	static Singleton* _self;
	Singleton() {}
	virtual ~Singleton() {}

public:
	static Singleton* Instance();

	static bool DeleteInstance();
};

Singleton* Singleton::_self = 0;