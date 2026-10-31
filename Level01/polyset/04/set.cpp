#include "set.hpp"

set::set() : inner_bag(NULL) {
}

set::set(searchable_bag &bag) : inner_bag(&bag) {

}

set::set(const set &src) : inner_bag(src.inner_bag) {

}

set& set::operator=(const set &rhs) {
	if (this != &rhs) {
		this->inner_bag = rhs.inner_bag;
	}
	return (*this);
}

set::~set() {
//Empty
}

void set::insert(int item) {
	if (this->inner_bag != NULL && this->has(item) != true) {
		inner_bag->insert(item);
	}
}

void set::insert(int *array, int size) {
	if (this->inner_bag != NULL) {
		for (int i = 0; i < size; i++) {
			this->insert(array[i]);
		}
	}
}

bool set::has(int item) const {
	if (this->inner_bag != NULL) {
		return (inner_bag->has(item));
	}
	return (false);
}

void set::print() const {
	if (this->inner_bag != NULL) {
		inner_bag->print();
	}
}

void set::clear() {
	if (this->inner_bag != NULL) {
		inner_bag->clear();
	}
}

searchable_bag& set::get_bag() const {
	return (*inner_bag);
}