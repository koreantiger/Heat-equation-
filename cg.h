#pragma once
#ifndef CG_HPP
#define CG_HPP

#include "matrix.h"

template<typename T>
int cg(const Matrix<T> &A, const Vector<T> &b, Vector<T> &x, T tol, int maxiter)
{
	Vector<T> r = b - A * x;
	Vector<T> p = r;
	auto rsold = dot(r, r);
	for (int k = 0; k < maxiter; k++) {
		auto Ap = A * p;
		auto a = rsold / dot(p, Ap);
		x = x + a * p;
		r = r - a * Ap;
		auto rsnew = dot(r, r);
		if (rsnew < tol*tol) {
			return k;
		}
		p = r + (rsnew / rsold) * p;
		rsold = rsnew;
	}
	return -1;
}
#endif // CG_HPP
