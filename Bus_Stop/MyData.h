
#pragma once



template<class T>
class MyData
{
public:
	T value;
	MyData* next = nullptr;

	MyData() {}
};