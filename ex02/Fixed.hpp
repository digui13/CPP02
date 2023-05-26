#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

using std::cout;
using std::endl;
using std::ostream;

class Fixed
{
	private:

		int _fixed_point_nb;
		static const int _bits = 8;

	public:

		// CONSTRUCTORS & DESTRUCTORS
		Fixed();
		Fixed(const int p);
		Fixed(const float p);
		~Fixed();

		// COPY 
		Fixed(const Fixed& obj);

		// GETTERS & SETTERS
		int getRawBits(void) const;
		void setRawBits (int const raw);

		// OPERATORS
		Fixed& operator=(const Fixed& obj);
		bool operator>(const Fixed& other);
		bool operator<(const Fixed& other);
		bool operator>=(const Fixed& other);
		bool operator<=(const Fixed& other);
		bool operator==(const Fixed& other);
		bool operator!=(const Fixed& other);

		Fixed operator+(const Fixed& other);
		Fixed operator-(const Fixed& other);
		Fixed operator*(const Fixed& other);
		Fixed operator/(const Fixed& other);

		Fixed operator++(void);
		Fixed operator++(int);
		Fixed operator--(void);
		Fixed operator--(int);

		// CONVERTERS
		float toFloat( void ) const;
		int toInt( void ) const;

		// MIN & MAX
		static Fixed& min(Fixed& a, Fixed& b);
		static Fixed& max(Fixed& a, Fixed& b);
		static const Fixed& min(const Fixed& a, const Fixed& b);
		static const Fixed& max(const Fixed& a, const Fixed& b);

};

ostream& operator<<(ostream& output, const Fixed& obj);

#endif
