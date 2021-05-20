#pragma once
#include <vector>
#include <algorithm>
#include <iostream>

template <class Item, bool(*func)(Item, Item)>
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
	Item popTop();
	void print() const;
	int size() const;
	void clear();
};

template<class Item, bool(*func)(Item, Item)>
void Pyramid_t<Item, func>::clear()
{
	pyramid.clear();
	return;
}

template<class Item, bool(*func)(Item, Item)>
inline int Pyramid_t<Item, func>::size() const
{
	return pyramid.size();
}

template<class Item, bool(*func)(Item, Item)>
Pyramid_t<Item, func>::Pyramid_t(std::vector<Item> listValue)
{
	for (auto it : listValue)
	{
		add(it);
	}
}

template<class Item, bool(*func)(Item, Item)>
inline Item Pyramid_t<Item, func>::getTop() const
{
	return pyramid[0];
}

template<class Item, bool(*func)(Item, Item)>
inline bool Pyramid_t<Item, func>::empty() const
{
	return pyramid.size() == 0;
}

template<class Item, bool(*func)(Item, Item)>
Item Pyramid_t<Item, func>::popTop()
{
	Item result = pyramid[0];
	eraseTop();
	return result;
}

template<class Item, bool(*func)(Item, Item)>
void Pyramid_t<Item, func>::print() const
{
	for (auto it : pyramid)
	{
		std::cout << it << " ";
	}
	std::cout << std::endl;
	return;
}

template<class Item, bool(*func)(Item, Item)>
void Pyramid_t<Item, func>::add(Item item)
{
	pyramid.push_back(item);
	int indexRoot = (pyramid.size() - 2) / 2, indexCurrent = pyramid.size() - 1;
	while (indexCurrent != 0)
	{
		if (func(pyramid[indexRoot], pyramid[indexCurrent]))
		{
			std::swap(pyramid[indexRoot], pyramid[indexCurrent]);
			indexCurrent = indexRoot;
			indexRoot = (indexCurrent - 1) / 2;
		}
		else { return; }
	}
	return;
}

template<class Item, bool(*func)(Item, Item)>
void Pyramid_t<Item, func>::eraseTop()
{
	pyramid[0] = pyramid[pyramid.size() - 1];
	pyramid.erase(pyramid.end() - 1);
	int indexRoot = 0, indexLeft = 1, indexRigth = 2;
	while (indexLeft < pyramid.size() && indexRigth < pyramid.size())
	{
		int index = (func(pyramid[indexRigth], pyramid[indexLeft])) ? indexLeft : indexRigth;
		if (func(pyramid[indexRoot], pyramid[index]))
		{
			std::swap(pyramid[indexRoot], pyramid[index]);
			indexRoot = index;
			indexLeft = 2 * indexRoot + 1;
			indexRigth = 2 * indexRoot + 2;
		}
		else { return; }
	}
	if (indexLeft >= pyramid.size() && indexRigth >= pyramid.size()) { return; }
	int index = (indexLeft < pyramid.size()) ? indexLeft : indexRigth;
	if (func(pyramid[indexRoot], pyramid[index]))
	{
		std::swap(pyramid[indexRoot], pyramid[index]);
	}
	return;
}
