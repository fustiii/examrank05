#pragma once

#include "searchable_bag.hpp"
#include <cstddef>

class set {
	private:
		searchable_bag *inner_bag;

	public:
		set();
		set(searchable_bag &bag);
		set(const set &src);
		set& operator=(const set &rhs);
		~set();

		void insert(int item);
		void insert(int *array, int size);
		bool has(int item) const;
		void print() const;
		void clear();

		searchable_bag& get_bag() const;
};