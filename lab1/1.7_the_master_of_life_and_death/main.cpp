#include "kth_cprog_template_container.hpp"
#include <assert.h>
unsigned int T1::object_count = 0;


int main () 
{
	{
		Vector<T1> v1(3); 			assert (T1::object_count == 3 && v1.capacity () >= 3);
		Vector<T1> v2;				assert (T1::object_count == 3);
		v1.push_back (T1{}); 		assert (T1::object_count == 4 && v1.capacity () >= 4);
		v2 = v1; 					assert (T1::object_count == 8);
		v2.erase (1); 				assert (T1::object_count == 7);
		v2.erase (1); 				assert (T1::object_count == 6);
		std::cout << "Slutet av scope main" << std::endl;

		// std::cout << "TEST  (1) PUSH-BACK " << std::endl;
		// Vector<int> v3;
		// for(int i = 0; i < 10; i++)
		// {
		// 	v3.push_back(30);	
		// 	// std::cout << "i: " << i << "tot: " << v3.tot_capacity << " len: " << v3.length << std::endl;
		// }
		// std::cout << "Slutet av scope main" << std::endl;
	}
	assert (T1::object_count == 0);
}