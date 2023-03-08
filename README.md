# Heat-equation-

Implementation of the Heat equation as part of the final project of the C++ course.

$\frac{\partial u}{\partial t} - \alpha \Delta u = 0  ,   on   \Omega $

the initial and boundary condition given as:

$u(x,0)$ $=$ $\prod_{k=0}^{n-1}sin(\pi x_k).$

$u(x,t) = 0,    \forall x \in \Omega.$

where $n$ is the number of dimensions of the domain, $ \Omega=[0,1]^n$
 is the domain (the unit square in 2D or the unit cube in 3D), $\partial \Omega$
 is the boundary of the domain, $u$
 is the temperature as a function of space $x=(x_0,…,x_{n−1})^⊤ \in R^n$
 and time $t$ and $\Delta$ is the Laplace operator.


