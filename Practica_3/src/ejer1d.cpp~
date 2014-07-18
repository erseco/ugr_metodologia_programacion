#include <iostream>

using namespace std;

int main() {

	int a = 5, *p = &a, **p2 = &p;

	**p2 = *p + (**p2 / a);
	*p = a+1;
	a = **p2 / 2;

	cout << "a es igual a: " << a << endl;

	return 0;

}
