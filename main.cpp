#include <iostream>
#include "Pyramid_t.h"
#include <vector>

using namespace std;

int main()
{
	vector <int> tmp = {3, 6, 2, 6, 4};
	Pyramid_t <int> pyramid(tmp);
	pyramid.add(-1);
	pyramid.add(0);
	pyramid.add(4);
	pyramid.print();
	pyramid.eraseTop();
	pyramid.print();
	return 0;
}