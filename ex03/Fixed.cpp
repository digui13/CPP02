#include "Fixed.hpp"

// ##################################################################################################
// # 										CONSTRUCTOR & DESTRUCTOR								#
// ##################################################################################################

Fixed::Fixed()
{
	_fixed_point_nb = 0;
	//cout	<< "Default constructor called" 
	//		<< endl;
}

Fixed::Fixed(const int p)
{
	_fixed_point_nb = p;
	//cout	<< "Int constructor called" 
	//		<< endl;
	_fixed_point_nb = p << _bits;
}

Fixed::Fixed(const float p)
{
	_fixed_point_nb = p;
	//cout	<< "Float constructor called" 
	//		<< endl;
	_fixed_point_nb = (int)(roundf(p * (1 << _bits)));
}

Fixed::~Fixed()
{
	//cout	<< "Destructor called" 
	//		<< endl;
}



// ##################################################################################################
// # 										COPY													#
// ##################################################################################################

Fixed::Fixed(const Fixed& obj)
{
	//cout	<< "Copy constructor called" 
	//		<< endl;
	*this = obj;
}



// ##################################################################################################
// # 										GETTERS & SETTERS										#
// ##################################################################################################

int Fixed::getRawBits(void) const
{
	//cout	<< "getRawBits member function called"
	//		<< endl;
	return (_fixed_point_nb);
}

void Fixed::setRawBits (int const rawBits)
{
	//cout	<< "setRawBits member function called"
	//		<< endl;
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
	//cout 	<< "Copy assignment operator called" 
	//		<< endl;
	_fixed_point_nb = obj._fixed_point_nb;
	return *this;
}

ostream& operator<<(ostream& output, const Fixed& obj) 
{
	return (output << obj.toFloat());
}

bool Fixed::operator>(const Fixed& obj) {
	return _fixed_point_nb > obj._fixed_point_nb;
}

bool Fixed::operator<(const Fixed& obj) {
	return _fixed_point_nb < obj._fixed_point_nb;
}

bool Fixed::operator>=(const Fixed& obj) {
	return _fixed_point_nb >= obj._fixed_point_nb;
}

bool Fixed::operator<=(const Fixed& obj) {
	return _fixed_point_nb <= obj._fixed_point_nb;
}

bool Fixed::operator==(const Fixed& obj) {
	return _fixed_point_nb == obj._fixed_point_nb;
}

bool Fixed::operator!=(const Fixed& obj) {
	return _fixed_point_nb != obj._fixed_point_nb;
}

Fixed Fixed::operator+(const Fixed& obj) {
	Fixed output = Fixed();

	output.setRawBits(_fixed_point_nb + obj._fixed_point_nb);
	return output;
}

Fixed Fixed::operator-(const Fixed& obj) {
	Fixed output = Fixed();

	output.setRawBits(_fixed_point_nb - obj._fixed_point_nb);
	return output;
}

Fixed Fixed::operator*(const Fixed& obj) {
	Fixed output = Fixed(this->toFloat() * obj.toFloat());
	return output;
}

Fixed Fixed::operator/(const Fixed& obj) {
	Fixed output = Fixed(this->toFloat() / obj.toFloat());
	return output;
}

Fixed Fixed::operator++(void) {
	Fixed output;

	output.setRawBits(++_fixed_point_nb);
	return output;
}

Fixed Fixed::operator++(int) {
	Fixed output;

	output.setRawBits(_fixed_point_nb++);
	return output;
}

Fixed Fixed::operator--(void) {
	Fixed output;

	output.setRawBits(--_fixed_point_nb);
	return output;
}

Fixed Fixed::operator--(int) {
	Fixed output;

	output.setRawBits(_fixed_point_nb--);
	return output;
}

// ##################################################################################################
// # 										MIN & MAX												#
// ##################################################################################################

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	if (a < b)
		return a;
	else 
		return b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	if ((Fixed&)a < b)
		return a;
	else
		return b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	if (a > b)
		return a;
	else
		return b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	if ((Fixed&)a > b)
		return a;
	else
		return b;
}