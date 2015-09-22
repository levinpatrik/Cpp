#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <typeinfo>

class UIntVector {

public:
  unsigned int *vector_ptr;
  unsigned int length;

  // This is the defualt constructor invoked when you pass no argument.
  UIntVector (): vector_ptr(new unsigned int[length]), length(0)
  {
    std::cout << "default-constructor" << std::endl;
  }

  //This constructor is invoked when you pass a std::size_t as argument
  //when creating a vector object, e.g UIntVector A(3);
  UIntVector (std::size_t i): vector_ptr(new unsigned int[length]), length(i)
  {
    std::cout << "length specified" << std::endl;
  }

  //This constructor is invoked when you pass a std::initializer_list<unsigned int> 
  // as argument when creating a vector object, e.g:
  // std::initializer_list<unsigned int> list = {1,2,3}; UIntVector A(list);
  UIntVector (std::initializer_list<unsigned int> list): vector_ptr(new unsigned int[length]), length(list.size())
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
  UIntVector (UIntVector const& obj): vector_ptr(new unsigned int[length]), length(obj.length)
  {
    for(int i = 0; i < length; i++)
    {
      vector_ptr[i] = obj.vector_ptr[i];
    }
    std::cout << "copy-constructor" << std::endl;
  }

  //This is the destructor which releases allocated memory from the constructor
  // by delete[].
  ~UIntVector ()
  {
    std::cout << "destructor" << std::endl;
    delete[] vector_ptr;
  }


  //This is a operator overload of the operator '='. It will turn one object to
  //copy of the other, e.g UIntVector A; UIntVector B; A = B; turns A to B. 
  UIntVector& operator= (UIntVector const& obj)
  {
   std::cout << "the assignment operator" << std::endl;
   delete[] vector_ptr;
   length = obj.length;
   vector_ptr = new unsigned int[length];
   for(int i = 0; i < length; i++)
   {
    vector_ptr[i] = obj.vector_ptr[i];
   }
   return *this;
  }


  unsigned int& operator[] (unsigned int index)
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

// när behövs const egentligen???
// Hur/varför ska man overloada [] vad är skillnaden i input?!



//This is a operator overload of '[]'. It will interpret the [] conbined with 
// UIntVector objects as a request to get the value at a given index. 
//e.g UIntVector A(30); A[3]; will yield the value at index 3.
unsigned int operator[] (unsigned int index) const
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
  void reset()
  {
    for(int i = 0; i < length; i++)
    {
      vector_ptr[i] = 0;
    }
  }

  //This function returns the size of the vector as an size_t type.
  std::size_t size() const
  {
    std::size_t length_t = length;
    return length_t; 
  }
};


int main()
{

  UIntVector A(3);
  int a = A[2];

  UIntVector B(3);
  const UIntVector& c = B;
  int x = c[2];

  std::cout << "A[]-operator " << a << std::endl;
  // std::cout << "B[]-operator " << B.vector_ptr[2] << std::endl;
  return 0;

}