#pragma once

#include <cstddef>

#include "searchable_bag.hpp"

class set {
	private:
		searchable_bag *intter_bag;
	public:
		set();
		set(searchable_bag &bag);
		set(const set &src);
		set& operator=(const set &rhs);
		~set();

		void insert (int item);
		void insert (int *items, int n);
		bool has(int item) const;
		void print() const;
		void clear();

		searchable_bag& get_bag() const;
};