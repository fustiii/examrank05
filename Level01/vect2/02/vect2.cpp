#include "vect2.hpp"

vect2::vect2(){
	this->_v[0] = 0;
	this->_v[1] = 0;
}

vect2::vect2(int x, int y){
	this->_v[0] = x;
	this->_v[1] = y;
}

vect2::vect2(const vect2 &src) {
	*this = src;
}

vect2& vect2::operator=(const vect2 &rhs) {
	if (this != &rhs) {
		this->_v[0] = rhs._v[0];
		this->_v[1] = rhs._v[1];
	}
	return (*this);
}

vect2::~vect2() {
 //Empty
}

int& vect2::operator[](int idx) {
	return (this->_v[idx]);
}

const int& vect2::operator[](int idx) const {
	return (this->_v[idx]);
}

vect2& vect2::operator+=(const vect2 &rhs) {
	this->_v[0] += rhs._v[0];
	this->_v[1] += rhs._v[1];
	return (*this);
}

vect2& vect2::operator-=(const vect2 &rhs) {
	this->_v[0] -= rhs._v[0];
	this->_v[1] -= rhs._v[1];
	return (*this);
}

vect2& vect2::operator*=(int scalar) {
	this->_v[0] *= scalar;
	this->_v[1] *= scalar;
	return (*this);
}

vect2& vect2::operator++() {
	this->_v[0]++;
	this->_v[1]++;
	return (*this);
}

vect2& vect2::operator--() {
	this->_v[0]--;
	this->_v[1]--;
	return (*this);
}

vect2 vect2::operator++(int) {
	vect2 tmp;

	tmp = *this;
	++(*this);

	return (tmp);
}

vect2 vect2::operator--(int) {
	vect2 tmp;

	tmp = *this;
	--(*this);

	return (tmp);
}

//! Mal hecho
/*
vect2 vect2::operator-() {
	-this->_v[0];
	-this->_v[1];
	return (*this);
}
*/

vect2 vect2::operator-() {
	return vect2(-this->_v[0], -this->_v[1]);
}

bool vect2::operator==(const vect2 &rhs) const {
	if (this->_v[0] == rhs._v[0] && this->_v[1] == rhs._v[1]) {
		return (true);
	}
	return (false);
}

bool vect2::operator!=(const vect2 &rhs) const {
	return !(*this == rhs);
}

std::ostream& operator<<(std::ostream &os, const vect2 &vec) {
	os << "{" << vec._v[0] << ", " << vec._v[1] << "}";
	return (os);
}

vect2 operator+(vect2 lhs, const vect2 &rhs) {
	lhs += rhs;
	return (lhs);
}

vect2 operator-(vect2 lhs, const vect2 &rhs) {
	lhs -= rhs;
	return (lhs);
}

vect2 operator*(vect2 lhs, int scalar) {
	lhs *= scalar;
	return (lhs);
}

vect2 operator*(int scalar, vect2 rhs) {
	return (rhs * scalar);
}