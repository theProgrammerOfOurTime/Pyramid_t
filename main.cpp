#include <iostream>
#include "Pyramid_t.h"
#include <vector>

using namespace std;

int main()
{
	vector <int> tmp = {4, 2, 3, 1, 0, 5, 7, 1, 8, -2, 100};
	Pyramid_t <int, 
		[](int a, int b)
		{
			return a < b;
		}> pyramid(tmp);
	while (!pyramid.empty())
	{
		cout << pyramid.popTop() << " ";
	}
	return 0;
}
