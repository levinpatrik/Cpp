
#include <iostream> 
#include "kth_cprog_template_container.hpp"



int main()
{

	//Test some constructors
	Vector<int> A_size(10);
	Vector<int> A_default; Vector<int> B_default;
	std::initializer_list<int> list; Vector<int> A_list(list);
	Vector<int> A_copy(A_default);

	for(int i = 0; i < 10; i++)
	{
		A_default.push_back(i);
	}


	
	return 0;
}