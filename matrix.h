#pragma once
#ifndef MATRIX_HPP
#define MATRIX_HPP

#include "vector.h"

template <typename T>
class Matrix
{
	// Start your implementation of the matrix class here
private:
	std::array<int, 2> shape;
	std::map<std::array<int, 2>, T> data;
public:
	// Constructor (sets length and allocates data)
	Matrix(int n1, int n2)
		: shape({ n1,n2 }) {}

	// Index operator
	T& operator[](std::array<int, 2> index) {
		if (index[0] > (shape[0] - 1) || index[1] > (shape[1] - 1)) throw "Index outside shape!";
		return data[index];
	}

	// Multiplication with vector
	Vector<T> multiply_vector(Vector<T>& rhs) const {
		if (rhs.length() != shape[1]) throw "Vector and matrix have different dimension!";
		Vector<T> v(rhs.length());
		v = 0 * v;
		for (auto it = data.begin(); it != data.end(); it++) {
			int i = it->first[0];
			int j = it->first[1];
			T value = it->second;
			v[i] += value * rhs[j];
		}
		return v;

	}
	// Debugging
	std::map<std::array<int, 2>, T> get_data() {
		return data;
	}
};

template<typename T>
Vector<T> operator*(const Matrix<T>& lhs, const Vector<T>& rhs)
{
	// Your implementation of the operator* starts here
	return lhs.multiply_vector(rhs);
}

#endif // MATRIX_HPP