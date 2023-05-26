#include "Fixed.hpp"
#include "Point.hpp"

int	main(void) {
	Point const a(0.0f, 0.0f);
	Point const b(5.0f, 5.0f);
	Point const c(5.0f, 0.0f);

	Point const p1(3.5f, 4.0f);
	Point const p2(4.5f, 1.5f);
	Point const p3(7.0f, 50.0f);
	Point const p4(-0.7f, -0.7f);
	Point const p5(-2.2f, 1.8f);

	cout << "1: " << (bsp(a, b, c, p1) ? "yes" : "no") << endl;
	cout << "2: " << (bsp(a, b, c, p2) ? "yes" : "no") << endl;
	cout << "3: " << (bsp(a, b, c, p3) ? "yes" : "no") << endl;
	cout << "4: " << (bsp(a, b, c, p4) ? "yes" : "no") << endl;
	cout << "5: " << (bsp(a, b, c, p5) ? "yes" : "no") << endl;

	return 0;
}