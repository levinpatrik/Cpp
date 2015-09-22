#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <typeinfo>
#include "vector.h"


// This is the defualt constructor invoked when you pass no argument.
UIntVector::UIntVector (): vector_ptr(new unsigned int[0]), length(0)
{
  std::cout << "default-constructor" << std::endl;
}

//This constructor is invoked when you pass a std::size_t as argument
//when creating a vector object, e.g UIntVector A(3);
UIntVector::UIntVector(std::size_t i): vector_ptr(new unsigned int[i]), length(i)
{
  std::cout << "length specified" << std::endl;
}

//This constructor is invoked when you pass a std::initializer_list<std::size_t> 
// as argument when creating a vector object, e.g:
// std::initializer_list<std::size_t> list = {1,2,3}; UIntVector A(list);
UIntVector::UIntVector (std::initializer_list<unsigned int> list): vector_ptr(new unsigned int[list.size()]), length(list.size())
{
  std::cout << "initializer_list" << std::endl;
  int i = 0;
  for(auto it = list.begin(); it != list.end(); it++)
  {
    vector_ptr[i] = *it;
    i++;
  }
}

//This is the Copy-constructor invoked when you pass a UIntVector as argument
//e.g UIntVector A; UIntVector B(A);
UIntVector::UIntVector(UIntVector const& obj): vector_ptr(new unsigned int[obj.length]), length(obj.length)
{
  for(std::size_t i = 0; i < length; i++)
  {
    vector_ptr[i] = obj.vector_ptr[i];
  }
  std::cout << "copy-constructor" << std::endl;
}

//This is the destructor which releases allocated memory from the constructor
// by delete[].
UIntVector::~UIntVector ()
{
  std::cout << "destructor" << std::endl;
  delete[] vector_ptr;
}


//This is a operator overload of the operator '='. It will turn one object to
//copy of the other, e.g UIntVector A; UIntVector B; A = B; turns A to B. 
UIntVector& UIntVector::operator= (UIntVector const& obj)
{
 std::cout << "the assignment operator" << std::endl;
 delete[] vector_ptr;
 length = obj.length;
 vector_ptr = new unsigned int[length];
 for(std::size_t i = 0; i < length; i++)
 {
    vector_ptr[i] = obj.vector_ptr[i];
 }
 return *this;
}


unsigned int& UIntVector::operator[] (std::size_t index)
{
  std::cout << "Inside operator[] READ-WRITE" << std::endl;
  if(index >= length)
  {
    throw std::out_of_range("Tried to access index out of range");
  }
  else
  {
    return vector_ptr[index];
  }
}


//This is a operator overload of '[]'. It will interpret the [] conbined with 
// UIntVector objects as a request to get the value at a given index. 
//e.g UIntVector A(30); A[3]; will yield the value at index 3.
unsigned int UIntVector::operator[] (std::size_t index) const
{
  std::cout << "Inside operator[] READ-ONLY" << std::endl;
  if(index >= length)
  {
    throw std::out_of_range("Tried to access index out of range");
  }
  else
  { 
    return vector_ptr[index];
  }
}

//This function set the entire vector to 0 by looping through it. 
void UIntVector::reset()
{
  unsigned int uInt = 0;
  for(std::size_t i = 0; i < length; i++)
  {
    vector_ptr[i] = uInt;
  }
}

//This function returns the size of the vector as an size_t type.
std::size_t UIntVector::size() const
{
  std::size_t length_t = length;
  return length_t; 
}
