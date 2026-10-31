#pragma once
#include <cstddef>

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

		void insert (int n);
		void insert (int *data, int n);
		bool has(int n) const;
		void print() const;
		void clear();

		const searchable_bag& get_bag() const;  
};
