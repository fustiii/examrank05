#include "set.hpp"

set::set() : inner_bag(NULL) {

}

set::set(searchable_bag &bag) :inner_bag(&bag) {

}

set::set(const set &src) : inner_bag(src.inner_bag) {

}

set& set::operator=(const set &rhs) {
	if (this != &rhs) {
		inner_bag = rhs.inner_bag;
	}
	return (*this);
}

set::~set() {
	//Empty
}

void set::insert (int n) {
	if (inner_bag != NULL && this->has(n) != true) {
		inner_bag->insert(n);
	}
}

void set::insert (int *data, int n) {
	if (inner_bag != NULL) {
		for (int i = 0; i < n; i++) {
			this->insert(data[i]);
		}
	}
}

bool set::has(int n) const {
	if (inner_bag != NULL) {
		return (inner_bag->has(n));
	}
	return (false);
}

void set::print() const {
	if (inner_bag != NULL) {
		return (inner_bag->print());
	}
}

void set::clear() {
	if (inner_bag != NULL) {
		return (inner_bag->clear());
	}
}

const searchable_bag& set::get_bag() const {
	return (*inner_bag);
}