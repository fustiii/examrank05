#include "vect2.hpp"

//! OCF
vect2::vect2(void) {
	this->_v[0] = 0;
	this->_v[1] = 0;
}

vect2::vect2(int x, int y) {
	this->_v[0] = x;
	this->_v[1] = y;
}

// Copy constructor
vect2::vect2(const vect2 &src) {
	//this->_v[0] = src._v[0];
	//this->_v[1] = src._v[1];

	*this = src;
}

// Assignement constructor
vect2& vect2::operator=(const vect2 &rhs) {
	if (this != &rhs) {
		this->_v[0] = rhs._v[0];
		this->_v[1] = rhs._v[1];
	}
	return (*this);
}

vect2::~vect2(void) {
	// Empty
}

//! Injección en flujos
std::ostream& operator<<(std::ostream &os, const vect2 &v) {
	os << "{" << v[0] << ", " << v[1] << "}";

	return os;
}

//! Operador acceso
int& vect2::operator[](int idx) {
	return this->_v[idx];
}
const int& vect2::operator[](int idx) const {
	return this->_v[idx];
}

//! Operadores operaciones
//suma
vect2& vect2::operator+=(const vect2 &rhs) {
	this->_v[0] += rhs._v[0];
	this->_v[1] += rhs._v[1];
	return (*this);
}

vect2 operator+(vect2 lhs, const vect2 &rhs) {
	lhs += rhs;  // Reutilizamos el operador += que acabamos de crear
	return lhs;  // Devolvemos la copia modificada
}

//resta
vect2& vect2::operator-=(const vect2 &rhs) {
	this->_v[0] -= rhs._v[0];
	this->_v[1] -= rhs._v[1];
	return (*this);
}

vect2 operator-(vect2 lhs, const vect2 &rhs) {
	lhs -= rhs;  // Reutilizamos el operador += que acabamos de crear
	return lhs;  // Devolvemos la copia modificada
}


//multiplicación
vect2& vect2::operator*=(int scalar) {
	this->_v[0] *= scalar;
	this->_v[1] *= scalar;
	return (*this);
}

vect2 operator*(vect2 lhs, int scalar) {
	lhs *= scalar;
	return (lhs);
}

vect2 operator*(int scalar, vect2 rhs) {
	return (rhs * scalar);
}

//! Incremento/decremento
//pre-incremento
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


//post-incremento
vect2 vect2::operator++(int) {
	vect2 tmp = *this;

	++(*this);

	return (tmp);
}

vect2 vect2::operator--(int) {
	vect2 tmp = *this;

	--(*this);

	return (tmp);
}

//! Operador urinario
vect2 vect2::operator-() const {
	return vect2(-this->_v[0], -this->_v[1]);
}

//! Operadores comparación
bool vect2::operator==(const vect2 &rhs) const {
	return (this->_v[0] == rhs._v[0] && this->_v[1] == rhs._v[1]);
}

bool vect2::operator!=(const vect2 &rhs) const {
	return !(*this == rhs);
}