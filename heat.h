#pragma once

#include "cg.h"

#ifndef HEAT_HPP
#define HEAT_HPP

double pi = acos(-1);

template <int n, typename T>
class Heat
{
	// Your implementation of the heat class starts here
private:
	double alpha;
	int m;
	int n_nodes;
	double dt;
	Matrix<T> M{ n_nodes, n_nodes };
	Vector<T> u_0 = Vector<T>(n_nodes);

public:
	// Constructor (sets length and allocates data)
	Heat(double alpha, int m, double dt)
		: alpha(alpha), m(m), n_nodes(pow(m, n)), dt(dt)
	{
		// Fill non-zero elements of M matrix
		auto dx = 1 / (double)(m + 1);
		auto c = (alpha*dt) / (double)(dx*dx);
		for (int i = 0; i < n_nodes; i++)
		{
			M[{i, i}] = 1 + c * 2 * n;
			for (int k = 0; k < n; k++)
			{
				int j = i + (int)pow(m, k);
				if (j > -1 && j < n_nodes && (j % (int)pow(m, k + 1)) != 0) {
					M[{i, j}] = -c;
				}
				j = i - (int)pow(m, k);
				if (j > -1 && j < n_nodes && (i % (int)pow(m, k + 1)) != 0) {
					M[{i, j}] = -c;
				}
			}
		}
		// Set initial condition
		for (int i = 0; i < n_nodes; i++)
		{
			u_0[i] = 1;
			for (int k = 0; k < n; k++)
			{
				auto x_k = index_to_coordinate(i, k);
				u_0[i] *= sin(pi*x_k);
			}
		}
	}

	// Convert index to coordinate
	// j is the index, k is the direction
	double index_to_coordinate(int j, int k)
	{

		return (((int)(j / pow(m, k)) % (int)pow(m, k + 1)) + 1) * (double)1 / (m + 1);
	}

	// Exact solution
	Vector<T> exact(T t) const
	{
		return exp(-n * pi*pi*alpha*t) * u_0;
	}

	// Kiarash  Solver Method
	Vector<T> solve(T t) const
	{
		if (((int)(t / dt) - t / dt) != 0) throw "t must be an integer multiple of dt!";
		Vector<T> u_l = u_0;
		Vector<T> u_l1 = u_0;
		int success;

		auto l_max = t / dt;
		for (int l = 1; l < l_max + 1; l++)
		{
			success = cg(M, u_l, u_l1, 0.001, 1e5);
			if (success == -1) throw "max iterations reached";
			u_l = u_l1;
		}
		return u_l1;
	}

	// Debugging
	void getMatrix()
	{
		for (int m = 0; m < n_nodes; m++)
		{
			for (int nn = 0; nn < n_nodes; nn++)
			{
				std::cout << M[{m, nn}] << " "; // [{i, i}]
			}
			std::cout << std::endl;
		}
	}

};

#endif // HEAT_HPP