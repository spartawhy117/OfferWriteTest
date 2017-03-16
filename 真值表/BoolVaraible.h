#pragma once
#include<iostream>
class BoolVaraible
{
public:
	BoolVaraible():value(true)
	{
		
	}
	BoolVaraible(bool v):value(v)
	{
		
	}
	
	BoolVaraible BoolVaraible::operator~()
	{
		BoolVaraible newValue(!this->value);
		return newValue;
	}
	BoolVaraible BoolVaraible::operator*(const BoolVaraible& rhs)
	{
		BoolVaraible newValue(this->value&&rhs.value);
		return newValue;
	}
	BoolVaraible BoolVaraible::operator+(const BoolVaraible& rhs)
	{
		BoolVaraible newValue(this->value||rhs.value);
		return newValue;
	}

	BoolVaraible BoolVaraible::operator%(const BoolVaraible& rhs)
	{
		if(this->value==!rhs.value)
		{
			BoolVaraible newValue(true);
			return newValue;
		}
		else
		{
			BoolVaraible newValue(false);
			return newValue;
		}
			
	}
	BoolVaraible BoolVaraible::operator>(const BoolVaraible& rhs)
	{
		bool v = !this->value || rhs.value;
		return BoolVaraible(v);
	}
	BoolVaraible BoolVaraible::operator^(const BoolVaraible& rhs)
	{
		BoolVaraible v = operator%(rhs);
		v.value = !v.value;
		return v;
	}
	 

	bool value;
};