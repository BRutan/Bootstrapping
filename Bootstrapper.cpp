/* Bootstrapper.cpp



*/


#include <array>
#include <map>
#include <vector>
#include "Bootstrapper.hpp"


bool BootStrapper::CheckContainer(const std::map<double, std::array<double, 3>> &input)
{
	bool satisfied = false;
	for (auto iter = input.begin(); iter != input.end(); iter++)
	{
		if (iter->second.at(0) == 0)
		{
			satisfied = true;
			break;
		}
	}
	return satisfied;
}
/////////////////////////////
// Constructors/Destructor:
/////////////////////////////
BootStrapper::BootStrapper() : _Contents()
{

}
BootStrapper::BootStrapper(const std::map<double, std::array<double, 3>> &input)
{
	// Throw exception if at least one zero coupon bond is not found (1st column in array element is 0):
	if (!this->CheckContainer(input))
	{
		// Throw exception since could not find at least one zero coupon bond:
		throw std::exception("Array needs at least one zero coupon bond.");
	}
	else
	{
		// Copy passed container:
		this->_Contents = input;
	}
}
BootStrapper::BootStrapper(std::map<double, std::array<double, 3>> &&input)
{
	// Throw exception if at least one zero coupon bond is not found (1st column in array element is 0):
	bool satisfied = false;
	for (auto &iter : input)
	{
		if (iter.second.at(0) == 0)
		{
			satisfied = true;
			break;
		}
	}
	if (!satisfied)
	{
		// Throw exception since could not find at least one zero coupon bond:
		throw std::exception("Array needs at least one zero coupon bond.");
	}
	else
	{
		// Move passed container:
		this->_Contents = std::move(input);
	}
}
BootStrapper::BootStrapper(const std::vector<std::array<double, 4>> &input)
{
	// Ensure that vector has at least one zero coupon bond:
	bool satisfied = false;
	for (auto &iter : input)
	{
		if (iter.at(1) == 0.0)
		{
			satisfied = true;
			break;
		}
	}
	if (!satisfied)
	{
		throw std::exception("Array needs at least one zero coupon bond.");
	}
	else
	{
		// Convert vector into the container type:
		for (auto &iter : input)
		{
			
		}
	}
}
BootStrapper::~BootStrapper()
{

}
/////////////////////////////
// Accessors:
/////////////////////////////
std::map<double, std::array<double, 2>> BootStrapper::GetContent()
{

}
/////////////////////////////
// Mutators:
/////////////////////////////
void BootStrapper::SetContent(const std::map<double, std::array<double, 3>> &input)
{
	if (!this->CheckContainer(input))
	{
		throw std::exception("Array needs at least one zero coupon bond.");
	}
	else
	{
		this->_Contents = input;
	}
}
void BootStrapper::SetContent(std::map<double, std::array<double, 3>> &&input)
{
	if (!this->CheckContainer(input))
	{
		throw std::exception("Array needs at least one zero coupon bond.");
	}
	else
	{
		this->_Contents = std::move(input);
	}
}
/////////////////////////////
// Overloaded Operators:
/////////////////////////////
BootStrapper& BootStrapper::operator=(const BootStrapper &input)
{
	if (this != &input)
	{
		this->_Contents = input;
	}
	return *this;
}