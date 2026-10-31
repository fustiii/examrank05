#pragma once

#include "searchable_bag.hpp"

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
		void insert(int *items, int count);
		bool has(int item) const;
		void print() const;
		void clear();

		const searchable_bag &get_bag() const;
};