#include "Fixed.hpp"

// ##################################################################################################
// # 										CONSTRUCTOR & DESTRUCTOR								#
// ##################################################################################################

Fixed::Fixed()
{
	_fixed_point_nb = 0;
	cout	<< "Default constructor called" 
			<< endl;
}

Fixed::Fixed(const int p)
{
	_fixed_point_nb = p;
	cout	<< "Int constructor called" 
			<< endl;
	_fixed_point_nb = p << _bits;
}

Fixed::Fixed(const float p)
{
	_fixed_point_nb = p;
	cout	<< "Float constructor called" 
			<< endl;
	_fixed_point_nb = (int)(roundf(p * (1 << _bits)));
}

Fixed::~Fixed()
{
	cout	<< "Destructor called" 
			<< endl;
}



// ##################################################################################################
// # 										COPY													#
// ##################################################################################################

Fixed::Fixed(const Fixed& obj)
{
	cout	<< "Copy constructor called" 
			<< endl;
	*this = obj;
}



// ##################################################################################################
// # 										GETTERS & SETTERS										#
// ##################################################################################################

int Fixed::getRawBits(void) const
{
	cout	<< "getRawBits member function called"
			<< endl;
	return (_fixed_point_nb);
}

void Fixed::setRawBits (int const rawBits)
{
	cout	<< "setRawBits member function called"
			<< endl;
	_fixed_point_nb = rawBits;
}



// ##################################################################################################
// # 										CONVERTERS												#
// ##################################################################################################

int Fixed::toInt( void ) const
{
	return _fixed_point_nb >> _bits;
}

float Fixed::toFloat( void ) const
{
	return (float)_fixed_point_nb / (float)(1 << _bits);
}



// ##################################################################################################
// # 										OPERATORS												#
// ##################################################################################################


Fixed& Fixed::operator=(const Fixed& obj) 
{
	cout 	<< "Copy assignment operator called" 
			<< endl;
	_fixed_point_nb = obj._fixed_point_nb;
	return *this;
}

ostream& operator<<(ostream& output, const Fixed& obj) 
{
	return (output << obj.toFloat());
}