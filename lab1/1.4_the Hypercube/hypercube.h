#include <iostream>
#include <vector>

template<unsigned N> class Hypercube
{
	Hypercube();
	Hypercube(std::size_t i);
	~Vector ();

    Hypercube& operator= (Hypercube const& obj);              //ASSIGNMENT
    Hypercube& operator= (Hypercube&& obj);                   //Move-ASSIGNMENT 
};