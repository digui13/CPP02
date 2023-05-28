#ifndef FIXED_HPP
#define FIXED_HPP

/*	***********************************	*/
/*	*			INCLUDES			  *	*/
/*	***********************************	*/

#include <iostream>
#include <cmath>

/*	***********************************	*/
/*	*			USINGS			  	  *	*/
/*	***********************************	*/

using std::cout;
using std::endl;
using std::ostream;

/*	***********************************	*/
/*	*			COLORS				  *	*/
/*	***********************************	*/

#define BLACK_COLOR             "\033[1;30m"
#define RED_COLOR               "\033[1;31m"
#define GREEN_COLOR             "\033[1;32m"
#define YELLOW_COLOR    		"\033[0;33m"
#define BLUE_COLOR              "\033[1;36m"
#define WHITE_COLOR             "\033[1;37m"
#define END_COLOR               "\033[0m"

/*	***********************************	*/
/*	*			CLASS				  *	*/
/*	***********************************	*/

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

/*	***********************************	*/
/*	*			FUNCTIONS			  *	*/
/*	***********************************	*/

ostream& operator<<(ostream& output, const Fixed& obj);

#endif
