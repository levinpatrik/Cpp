#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <typeinfo>



template <typename T>
class Vector
{
  public:
    T *vector_ptr;
    std::size_t length;

    Vector ();                                          //Default
    explicit Vector (std::size_t i);                    //Size_t
    Vector (std::initializer_list<T> list);  //List
    Vector (Vector const& obj);                     //Copy
    Vector (Vector&& obj);                          //Move
    ~Vector ();                                         //Destructor

    Vector& operator= (Vector const& obj);          
    T& operator[] (std::size_t index);
    T operator[] (std::size_t index) const;
    void reset();
    std::size_t size() const;


};

// ------------------  DEFUALT 
template<typename T> 
Vector<T>::Vector(): vector_ptr(new T[0]), length(0)
{
  // std::cout << "DEFUALT"<< std::endl;
}

// ------------------  SIZE         
template<typename T> 
Vector<T>::Vector(std::size_t i): vector_ptr(new T[i]), length(i)
{
  // std::cout << "SIZE"<< std::endl;
    for(std::size_t i = 0; i < length; i++)
    {
      vector_ptr[i] = 0;
    }
}

// ------------------  LIST        
template<typename T> 
Vector<T>::Vector (std::initializer_list<T> list): vector_ptr(new T[list.size()]), length(list.size())
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
template<typename T> 
Vector<T>::Vector(Vector const& obj) : vector_ptr(new T[obj.length]), length(obj.length)  
{
  // std::cout << "COPY"<< std::endl;
  delete[] vector_ptr;
  length = obj.length;
  vector_ptr = new T[obj.length];
  for(std::size_t i = 0; i < obj.length; i++)
  {
    vector_ptr[i] = obj.vector_ptr[i];
  }
}

// ------------------  MOVE       
template<typename T> 
Vector<T>::Vector(Vector && obj): vector_ptr(obj.vector_ptr),length(obj.length)
{
  // std::cout << "MOVE"<< std::endl;
  obj.length = 0;
  obj.vector_ptr = nullptr;

}

// ------------------  DESTRUCTOR  
template<typename T> 
Vector<T>::~Vector()
{
  delete[] vector_ptr;
}


// ------------------  OPERATOR  =    
template<typename T>      
Vector<T>& Vector<T>::operator= (Vector<T> const& obj)
{
  if(this != &obj)
  {
  delete[] vector_ptr;
  length = obj.length;
  vector_ptr = new T[length];
  for(std::size_t i = 0; i < length; i++)
  {
    vector_ptr[i] = obj.vector_ptr[i];
  }
  }
  return *this;
}

// ------------------  OPERATOR  []  READ-WRITE 
template<typename T> 
T& Vector<T>::operator[] (std::size_t index)
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
template<typename T> 
T Vector<T>::operator[] (std::size_t index) const
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
template<typename T> 
void Vector<T>::reset()
{
  unsigned int uInt = 0;
  for(std::size_t i = 0; i < length; i++)
  {
    vector_ptr[i] = uInt;
  }
}

//This function returns the size of the vector as an size_t type.
template<typename T> 
std::size_t Vector<T>::size() const
{
  return length; 
}