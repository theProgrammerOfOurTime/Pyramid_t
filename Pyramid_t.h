#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

template <class Item>
class Pyramid_t
{
private:
	std::vector<Item> pyramid;
public:
	Pyramid_t(std::vector<Item>);
	Pyramid_t() {}
	void add(Item);
	Item getTop() const;
	bool empty() const;
	void eraseTop();
	Item top();
	void print() const;
};

template<class Item>
Pyramid_t<Item>::Pyramid_t(std::vector<Item> listValue)
{
	for (auto it : listValue)
	{
		add(it);
	}
}

template<class Item>
inline Item Pyramid_t<Item>::getTop() const
{
	return pyramid[0];
}

template<class Item>
inline bool Pyramid_t<Item>::empty() const
{
	return pyramid.size() == 0;
}

template<class Item>
Item Pyramid_t<Item>::top()
{
	Item result = pyramid[0];
	eraseTop();
	return result;
}

template<class Item>
void Pyramid_t<Item>::print() const
{
	for (auto it : pyramid)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;
	return;
}

template <class Item>
void Pyramid_t<Item>::add(Item item)
{
	pyramid.push_back(item);
	int indexRoot = (pyramid.size() - 2) / 2, indexCurrent = pyramid.size() - 1;
	while (indexCurrent != 0)
	{
		if (pyramid[indexRoot] > pyramid[indexCurrent])
		{
			int tmp = pyramid[indexRoot];
			pyramid[indexRoot] = pyramid[indexCurrent];
			pyramid[indexCurrent] = tmp;
			indexCurrent = indexRoot;
			indexRoot = (indexCurrent - 1) / 2;
		}
		else { break; }
	}
	return;
}


template<class Item>
void Pyramid_t<Item>::eraseTop()
{
	pyramid[0] = pyramid[pyramid.size() - 1];
	pyramid.erase(pyramid.end() - 1);
	//FIXEME
	return;
}