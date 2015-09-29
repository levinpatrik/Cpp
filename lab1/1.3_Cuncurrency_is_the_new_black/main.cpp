#include <thread>
#include <iostream> 
#include "kth_cprog_template_container.hpp"



int main()
{
	std::initializer_list<int> list1 = {1,2,3,4,5,6};
	SafeVector<int> vec(list1);

	std::cout << "[0] " << vec.SafeVector_ptr[0] << " [1] " << vec.SafeVector_ptr[1] << std::endl;
	std::cout << "[2] " << vec.SafeVector_ptr[2] << " [3] " << vec.SafeVector_ptr[3] << std::endl;

	std::thread first(&SafeVector<int>::safeswap, &vec,0,1);
	std::thread second(&SafeVector<int>::safeswap, &vec,2,3);

	first.join(); 				 // pauses until first finishes
	second.join();               // pauses until second finishes

	std::cout << "[0] " << vec.SafeVector_ptr[0] << " [1] " << vec.SafeVector_ptr[1] << std::endl;
	std::cout << "[2] " << vec.SafeVector_ptr[2] << " [3] " << vec.SafeVector_ptr[3] << std::endl;
	
	

	std::cout << "Both threads completed!" << std::endl;


		//	OBS:
		// Vi kanske måste locka allt som har med SafeVector_ptr att göra så att index1 & 2
		// inte kan bli ändrat "medans man swappar"
	return 0;
}