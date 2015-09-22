#include <iostream>

#include "hello.h"

void hello (const char * name, int count) {
  
	if(count > 0)
	{
		std::cout << "Hello,";
		for(int i = 0; i < count; i++)
		{
			std::cout << " " << name;
		}
		std::cout << "!" << std::endl;
	}
}


std::pair<const char *, int> parse_args (int argc, char * argv[]) {
  
	if(argc > 2)
	{
		if((atoi(argv[2]) > 0 || *argv[2] == '0') && argc <= 3)
		{
			return std::make_pair ( argv[1], atoi(argv[2]));
		}
		else 
		{
			if(argc > 3)
			{
				std::cerr<< "error: Too many arguments!" << std::endl;	
			}
			else
			{
				std::cerr<< "error: 2nd argument must be an integral greater than zero!" 
				<< std::endl;
			}
			return std::make_pair ( argv[1], -1);
		}
	}
	else if(argc == 1)
	{
		const char* str = "world";
		return std::make_pair (str, 1);
	}
	else
	{
		return std::make_pair ( argv[1], 1);
	}
}
