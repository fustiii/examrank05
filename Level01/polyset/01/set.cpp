#include "set.hpp"
#include <cstddef>

set::set() : inner_bag(NULL) {

}

set::set(searchable_bag &bag) : inner_bag(&bag){

}

set::set(const set &src) : inner_bag(src.inner_bag) {

}

set& set::operator=(const set &rhs) {
	if (this != &rhs) {
		//se puede poner sin el this y igual como es un puntero se debe poner sin o con .
		this->inner_bag = rhs.inner_bag;
	}
	return (*this);
}

set::~set() {
//No hacemos nada pq ya se borra en el main
}

void set::insert(int item) {
	if (inner_bag != NULL && has(item) != true) {
		inner_bag->insert(item);
	}
}

void set::insert(int *items, int count) {
	if (inner_bag == NULL) {
		return;
	}
	for (int i = 0; i < count; i++) {
		this->insert(items[i]);
	}
}

bool set::has(int item) const {
	if (inner_bag != NULL) {
		return (inner_bag->has(item));
	}
	return (false);
}

void set::print() const {
	if (inner_bag != NULL) {
		inner_bag->print();
	}
}

void set::clear() {
	if (inner_bag != NULL) {
		inner_bag->clear();
	}
}

const searchable_bag &set::get_bag() const {
	return (*inner_bag);
}