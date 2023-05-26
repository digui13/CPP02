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

		// CONVERTERS
		float toFloat( void ) const;
		int toInt( void ) const;

};

ostream& operator<<(ostream& output, const Fixed& obj);

#endif
