# Heat-equation-

Implementation of the Heat equation in an arbitary dimension of the space as part of the final project of the C++ course. Consider the following initial boundary value problem:

$\frac{\partial u}{\partial t} - \alpha \Delta u = 0  ,   on   \Omega $

the initial and boundary condition given as:

$u(x,0)$ $=$ $\prod_{k=0}sin(\pi x_k), \forall x \in \Omega,$

$u(x,t) = 0,    \forall x \in \partial \Omega .$

where $n$ is the number of dimensions of the domain, $ \Omega = [0,1]^n$
 is the domain (the unit square in 2D or the unit cube in 3D), $\partial \Omega$
 is the boundary of the domain, $u$
 is the temperature as a function of space $x=(x_0,…,x_{n−1})^⊤ \in R^n$
 and time $t$ and $\Delta$ is the Laplace operator.


