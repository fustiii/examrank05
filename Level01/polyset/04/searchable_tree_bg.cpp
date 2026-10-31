#include "searchable_tree_bg.hpp"

searchable_tree_bag::searchable_tree_bag()
	: tree_bag() {

}

searchable_tree_bag::searchable_tree_bag(const searchable_tree_bag &src)
	: tree_bag(src) {

}

searchable_tree_bag& searchable_tree_bag::operator=(const searchable_tree_bag &rhs) {
	if (this != &rhs) {
		tree_bag::operator=(rhs);
	}
	return(*this);
}

searchable_tree_bag::~searchable_tree_bag() {
//Empty
}


bool searchable_tree_bag::has(int item) const {
	node *current = tree;

	while (current != NULL) {
		if (item == current->value) {
			return (true);
		} else if (item < current->value) {
			current = current->l;
		} else {
			current = current->r;
		}
	}
	return (false);
}