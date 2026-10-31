#pragma once

#include <iostream>

class vect2 {
	private:
		int _v[2];
	public:

		//OCF
		vect2();
		vect2(int x, int y);
		vect2(const vect2 &src);
		vect2& operator=(const vect2 &rhs);
		~vect2();

		//[]
		int& operator[](int idx);
		const int& operator[](int idx) const;

		//+=-=
		vect2& operator+=(const vect2 &rhs);
		vect2& operator-=(const vect2 &rhs);

		//*=
		vect2& operator*=(int scalar);

		//++--
		vect2& operator++();
		vect2& operator--();

		vect2 operator++(int);
		vect2 operator--(int);

		//!Devolvemos el mismo objeto
		//-v
		vect2 operator-();

		//!Devolvemos bool
		//==!=
		bool operator==(const vect2 &rhs) const;
		bool operator!=(const vect2 &rhs) const;

		friend std::ostream& operator<<(std::ostream &os, const vect2 &vec);
};

//!Passamos 2 variables para poder reutilizar +=, -= y *=
vect2 operator+(vect2 lhs, const vect2 &rhs);
vect2 operator-(vect2 lhs, const vect2 &rhs);
vect2 operator*(vect2 lhs, int scalar);
vect2 operator*(int scalar, vect2 rhs);