/* Bootstrapper.hpp
Description:
	* Base class for various bootstrapping methods. 
Class Members:
	* map<double, array<double, 2>> _Contents: Map tenor to { Coupon Rate, Price, Pmt Periods } for listed zero/coupon bonds.



*/

#ifndef BOOTSTRAPPER_HPP
#define BOOTSTRAPPER_HPP

#include <array>
#include <functional>
#include <map>
#include <vector>

class BootStrapper
{
private:
	std::map<double, std::array<double, 3>> _Contents;
	bool CheckContainer(const std::map<double, std::array<double, 3>>&);
public:
	// Constructors/Destructor:
	BootStrapper();
	BootStrapper(const std::map<double, std::array<double, 3>>&);
	BootStrapper(std::map<double, std::array<double, 3>>&&);
	BootStrapper(const std::vector<std::array<double, 4>>&);
	virtual ~BootStrapper();
	// Accessors:
	std::map<double, std::array<double, 2>> GetContent();
	// Mutators:
	void SetContent(const std::map<double, std::array<double, 3>> &);
	void SetContent(std::map<double, std::array<double, 3>> &&);
	// Abstract class methods:
	virtual std::map<double, double> Bootstrap() = 0;
	// Overloaded Operators:
	BootStrapper& operator=(const BootStrapper&);
};


#endif
