
#ifndef VECTOR_H
#define VECTOR_H	

#include <initializer_list>

class UIntVector 
{
	public:
		unsigned int *vector_ptr;
		std::size_t length;

		UIntVector ();
		explicit UIntVector (std::size_t i);
		UIntVector (std::initializer_list<unsigned int> list);
		UIntVector (UIntVector const& obj);
		~UIntVector ();

		UIntVector& operator= (UIntVector const& obj);
		unsigned int& operator[] (std::size_t index);
		unsigned int operator[] (std::size_t index) const;
		void reset();
		std::size_t size() const;


};

#endif
