#pragma once
#ifndef VECTOR_HPP
#define VECTOR_HPP

// Include header file for standard input/output stream library
#include <iostream>
// Include header file for initializer list
#include <initializer_list>
// Include header file for memory
#include <memory>
// Include header file for maps
#include <map>
// Include header file for arrays
#include <array>
// Include header file for iterators
#include <iterator>
// Include header file for math
#include <cmath>

template <typename T>
class Vector
{
	// Your implementation of the Vector class starts here
private:
	T* data;
	int n;
public:
	// Default constructor
	Vector()
		: data(nullptr), n(0) {}

	// Constructor with int parameter (sets length and allocates data)
	Vector(int n)
		: data(new T[n]), n(n) {}

	// Constructor (using initializer list)
	Vector(std::initializer_list<T> list)
		: Vector((int)list.size())
	{
		std::uninitialized_copy(list.begin(), list.end(), data);
	}

	// Copy Constructor
	Vector(const Vector& other)
		: Vector(other.n)
	{
		for (auto i = 0; i < other.n; i++)
			data[i] = other.data[i];
	}

	// Destructor
	~Vector()
	{
		n = 0;
		delete[] data;
	}
	// Copy assignment
	Vector& operator=(const Vector& other)
	{
		if (this != &other)
		{
			delete[] data;
			n = other.n;
			data = new T[other.n];
			for (auto i = 0; i < other.n; i++)
				data[i] = other.data[i];
		}
		//std::cout << "copy assignment operator" <<std::endl;
		return *this;
	}

	// Move assignment
	Vector& operator=(Vector&& other)
	{
		if (this != &other)
		{
			delete[] data;
			n = other.n;
			data = other.data;
			other.n = 0;
			other.data = nullptr;
		}
		//std::cout << "move assignment operator" << std::endl;
		return *this;
	}

	// Pointwise sum operator
	Vector<T> operator+(Vector<T> other) const {
		if (n != other.n) throw "Vectors have different length!";
		Vector<T> sum(other.n);
		for (auto i = 0; i < other.n; i++)
			sum.data[i] = data[i] + other.data[i];
		return sum;
	}

	// Pointwise subtraction operator
	Vector<T> operator-(Vector<T> other) const {
		if (n != other.n) throw "Vectors have different length!";
		Vector<T> sum(other.n);
		for (auto i = 0; i < other.n; i++)
			sum.data[i] = data[i] - other.data[i];
		return sum;
	}

	// Multiply with a scalar
	Vector<T> operator*(T scalar) const
	{
		Vector<T> v(*this);
		for (auto i = 0; i < n; i++)
			v[i] *= scalar;
		return v;
	}

	// dot product
	T dot(const Vector<T>& other) const
	{
		T d = 0;
		for (auto i = 0; i < n; i++)
			d += data[i] * other.data[i];
		return d;
	}

	// Index operator
	T& operator[](int index) {
		if (index > (n - 1)) throw "Index outside shape!";
		return data[index];
	}

	// Get length
	int length() {
		return n;
	}
};
template <typename T1, typename T2>
auto operator*(T1 scalar, const Vector<T2>& v) {
	return  v * scalar;
}

template <typename T>
T dot(const Vector<T>& lhs, const Vector<T>& rhs)
{
	return lhs.dot(rhs);
}




#endif // VECTOR_HPP