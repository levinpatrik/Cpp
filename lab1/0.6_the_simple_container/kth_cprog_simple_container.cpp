#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <typeinfo>
#include "kth_cprog_simple_container.hpp"


// ------------------  DEFUALT      
UIntVector::UIntVector (): vector_ptr(new unsigned int[0]), length(0)
{
  // std::cout << "DEFUALT"<< std::endl;
}

// ------------------  SIZE         
UIntVector::UIntVector(std::size_t i): vector_ptr(new unsigned int[i]), length(i)
{
  // std::cout << "SIZE"<< std::endl;
    for(std::size_t i = 0; i < length; i++)
    {
      vector_ptr[i] = 0;
    }
}

// ------------------  LIST        
UIntVector::UIntVector (std::initializer_list<unsigned int> list): vector_ptr(new unsigned int[list.size()]), length(list.size())
{
  // std::cout << "LIST"<< std::endl;
  int i = 0;
  for(auto it = list.begin(); it != list.end(); it++)
  {
    vector_ptr[i] = *it;
    i++;
  }
}

// ------------------  COPY        
UIntVector::UIntVector(UIntVector const& obj) : vector_ptr(new unsigned int[obj.length]), length(obj.length)  
{
  // std::cout << "COPY"<< std::endl;
  delete[] vector_ptr;
  length = obj.length;
  vector_ptr = new unsigned int[obj.length];
  for(std::size_t i = 0; i < obj.length; i++)
  {
    vector_ptr[i] = obj.vector_ptr[i];
  }
}

// ------------------  MOVE       
UIntVector::UIntVector(UIntVector && obj): vector_ptr(obj.vector_ptr),length(obj.length)
{
  // std::cout << "MOVE"<< std::endl;
  obj.length = 0;
  obj.vector_ptr = nullptr;

}

// ------------------  DESTRUCTOR  
UIntVector::~UIntVector()
{
  delete[] vector_ptr;
}


// ------------------  OPERATOR  =   ASSIGNMENT      
UIntVector& UIntVector::operator= (UIntVector const& obj)
{
  if(this != &obj)
  {
  delete[] vector_ptr;
  length = obj.length;
  vector_ptr = new unsigned int[length];
  for(std::size_t i = 0; i < length; i++)
  {
    vector_ptr[i] = obj.vector_ptr[i];
  }
  }
  return *this;
}

// ------------------  OPERATOR  =  MOVE-ASSIGNMENT
UIntVector& UIntVector::operator= (UIntVector&& obj)
{
  if(this != &obj)
  {
    delete[] vector_ptr;
    vector_ptr = obj.vector_ptr;
    length = obj.length;
    obj.vector_ptr = nullptr;
    obj.length = 0;
  }
  return *this;
}




// ------------------  OPERATOR  []  READ-WRITE  
unsigned int& UIntVector::operator[] (std::size_t index)
{
  if(index >= length)
  {
    throw std::out_of_range("Tried to access index out of range");
  }
  else
  {
    return vector_ptr[index];
  }
}


// ------------------  OPERATOR  []  READ-ONLY
unsigned int UIntVector::operator[] (std::size_t index) const
{
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
  return length; 
}