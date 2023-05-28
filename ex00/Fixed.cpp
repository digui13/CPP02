#include "Fixed.hpp"

// ##################################################################################################
// # 										CONSTRUCTOR & DESTRUCTOR								#
// ##################################################################################################

Fixed::Fixed()
{
	this->_fixed_point_nb = 0;
	cout	<< "Default constructor called" 
			<< endl;
}

Fixed::Fixed(Fixed& obj)
{
	cout	<< "Copy constructor called" 
			<< endl;
	*this = obj;
}

Fixed::~Fixed()
{
	cout	<< "Destructor called" 
			<< endl;
}

// ##################################################################################################
// # 										OPERATORS												#
// ##################################################################################################

Fixed& Fixed::operator=(Fixed& obj) {
	cout 	<< "Copy assignment operator called" 
			<< endl;
	this->_fixed_point_nb = obj.getRawBits();
	return *this;
}

// ##################################################################################################
// # 										GETTERS & SETTERS										#
// ##################################################################################################

int Fixed::getRawBits(void) const
{
	cout	<< "getRawBits member function called"
			<< endl;
	return (this->_fixed_point_nb);
}

void Fixed::setRawBits (int const rawBits)
{
	cout	<< "setRawBits member function called"
			<< endl;
	this->_fixed_point_nb = rawBits;
}
