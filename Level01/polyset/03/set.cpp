#include "set.hpp"

set::set() : intter_bag(NULL) {

}

set::set(searchable_bag &bag) 
	: intter_bag(&bag){

}

set::set(const set &src)
	: intter_bag(src.intter_bag) {

}

set& set::operator=(const set &rhs) {
	if (this != &rhs) {
		this->intter_bag = rhs.intter_bag;
	}
	return (*this);
}

set::~set() {

}

void set::insert (int item) {
	if (intter_bag != NULL && this->has(item) != true) {
		intter_bag->insert(item);
	}
}

void set::insert (int *items, int n) {
	if (intter_bag != NULL) {
		for (int i = 0; i < n; i++) {
			this->insert(items[i]);
		}
	}
}

bool set::has(int item) const {
	if (intter_bag != NULL) {
		return (intter_bag->has(item));
	}
	return (false);
}

void set::print() const {
	if (intter_bag != NULL) {
		intter_bag->print();
	}
}

void set::clear() {
	if (intter_bag != NULL) {
		intter_bag->clear();
	}
}

searchable_bag& set::get_bag() const {
	return (*intter_bag);
}