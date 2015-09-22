#ifndef VECTOR_H
#define VECTOR_H  

#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <typeinfo>
#include <type_traits>



template <typename T>
class Vector
{
  public:
    T *vector_ptr;
    std::size_t length;
    std::size_t tot_capacity;

    Vector ();                                          //Default
    explicit Vector (std::size_t i);                    //Size_t
    Vector (std::size_t i, T);                          //Special constructor
    Vector (std::initializer_list<T> list);             //List
    Vector (Vector const& obj);                         //Copy
    Vector (Vector&& obj);                              //Move
    ~Vector ();                                         //Destructor

    Vector& operator= (Vector const& obj);              //ASSIGNMENT
    Vector& operator= (Vector&& obj);                   //Move-ASSIGNMENT      
    T& operator[] (std::size_t index);                  //Modify
    T operator[] (std::size_t index) const;             //Access
    
    void reset();
    std::size_t size() const;
    void clear();
    void push_back(T);
    void insert(std::size_t , T);
    void erase(std::size_t);
    std::size_t capacity() const;
    T* begin() const;
    T* end() const;
    T* find(T const&) const;

};

// ------------------  DEFUALT 
template<typename T> 
Vector<T>::Vector()
{
  std::cout << "DEFUALT"<< std::endl;
  static_assert(std::is_move_constructible<T>::value 
    && std::is_move_assignable<T>::value,
  "The type must be move constructable/assignable");

  length = 0; tot_capacity = length*2 + 10; 
  vector_ptr = new T[tot_capacity];
  reset();
}



// ------------------  SIZE         
template<typename T> 
Vector<T>::Vector(std::size_t i)
{
  std::cout << "SIZE"<< std::endl;
  static_assert(std::is_move_constructible<T>::value 
    && std::is_move_assignable<T>::value,
  "The type must be move constructable/assignable");

  length = i; tot_capacity = length*2 + 10; 
  vector_ptr = new T[tot_capacity];
  reset();
}

// // ------------------ SPECIAL CONSTRUCTOR
template<typename T>
Vector<T>::Vector(std::size_t i, T start_value)
{
  std::cout << "SPECIAL CONSTRUCTOR"<< std::endl;
  static_assert(std::is_move_constructible<T>::value 
  && std::is_move_assignable<T>::value,
  "The type must be move constructable/assignable");

  length = i; tot_capacity = length*2 + 10; 
  vector_ptr = new T[tot_capacity];
  for(int i = 0; i<length; i++){
    vector_ptr[i] = start_value;
  }
}


// ------------------  LIST        
template<typename T> 
Vector<T>::Vector (std::initializer_list<T> list)
{
  std::cout << "LIST"<< std::endl;
  static_assert(std::is_move_constructible<T>::value 
    && std::is_move_assignable<T>::value,
  "The type must be move constructable/assignable");

  length = list.size(); tot_capacity = length*2 + 10; 
  vector_ptr = new T[tot_capacity];

  int i = 0;
  for(auto it = list.begin(); it != list.end(); it++)
  {
    vector_ptr[i] = *it;
    i++;
  }
}

// ------------------  COPY        
template<typename T> 
Vector<T>::Vector(Vector const& obj)
{
  std::cout << "COPY"<< std::endl;
  static_assert(std::is_move_constructible<T>::value 
    && std::is_move_assignable<T>::value,
  "The type must be move constructable/assignable");

  vector_ptr = new T[obj.tot_capacity]; length = obj.length;
  tot_capacity = obj.tot_capacity;
  for(std::size_t i = 0; i < obj.length; i++)
  {
    vector_ptr[i] = obj.vector_ptr[i];
  }
}

// ------------------  MOVE       
template<typename T> 
Vector<T>::Vector(Vector && obj)
{
  std::cout << "MOVE"<< std::endl;
  static_assert(std::is_move_constructible<T>::value 
    && std::is_move_assignable<T>::value,
  "The type must be move constructable/assignable");

  vector_ptr = obj.vector_ptr; length = obj.length; tot_capacity = obj.tot_capacity;
  obj.length = 0; obj.vector_ptr = nullptr; obj.tot_capacity = 0;

}

// ------------------  DESTRUCTOR  
template<typename T> 
Vector<T>::~Vector()
{
  delete[] vector_ptr;
}


// ------------------  OPERATOR  =    ASSIGNMENT
template<typename T>      
Vector<T>& Vector<T>::operator= (Vector<T> const& obj)
{
  std::cout << "OPERATOR  =    ASSIGNMENT"<< std::endl;
  if(this != &obj)
  {
    delete[] vector_ptr;
    length = obj.length;
    tot_capacity = obj.tot_capacity;
    vector_ptr = new T[tot_capacity];
    for(std::size_t i = 0; i < length; i++)
    {
      vector_ptr[i] = obj.vector_ptr[i];
    }
  }
  return *this;
}

// ------------------  OPERATOR  =  MOVE-ASSIGNMENT
template<typename T>      
Vector<T>& Vector<T>::operator= (Vector<T>&& obj)
{
  std::cout << "OPERATOR  =     MOVE-ASSIGNMENT"<< std::endl;
  if(this != &obj)
  {
    delete[] vector_ptr;
    vector_ptr = obj.vector_ptr; length = obj.length; tot_capacity = obj.tot_capacity;
    obj.vector_ptr = nullptr; obj.tot_capacity = 0; obj.length = 0;
  }
  return *this;
}

// ------------------  OPERATOR  []  READ-WRITE 
template<typename T> 
T& Vector<T>::operator[] (std::size_t index)
{
  // std::cout << "OPERATOR  []  READ-WRITE "<< std::endl;
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
  std::cout << " OPERATOR  []  READ-ONLY "<< std::endl;
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



template<typename T>
void Vector<T>::clear()
{
  delete[] vector_ptr;
  vector_ptr = nullptr; length = 0;
}



template<typename T>
void Vector<T>::push_back(T element)
{
  if(tot_capacity <= length)
  {
    T* old_array = vector_ptr;
    tot_capacity = tot_capacity*2;
    vector_ptr = new T[tot_capacity];

    for(std::size_t i = 0; i < length; i++)
    {
      vector_ptr[i] = old_array[i];
    }
    delete[] old_array;
  }
  vector_ptr[length] = element;
  length++;
}



template<typename T>
void Vector<T>::insert(std::size_t index, T element)
{


  if(index == length)
  {
    push_back(element);
    return;
  }
  else if(index > length)
  {
    throw std::out_of_range("Tried to access index out of range");
    return;
  }

  if(tot_capacity <= length)
  { 
    tot_capacity = tot_capacity*2;
    vector_ptr = new T[tot_capacity];
  }

  T* old_array = vector_ptr;
  for(std::size_t i = 0; i <= length; i++)
  {
    if(i == index)
    {
      vector_ptr[i] = element;
        
    }
    else if(i > index)
    {
      vector_ptr[i] = old_array[i-1];
    }
    else
    {
      vector_ptr[i] = old_array[i];
    }
  }
  length++;
}

template<typename T>
void Vector<T>::erase(std::size_t index)
{
  if(index >= length)
  {
    return;
  }

  for(int i = index; i < (length-1); i++)
  {
    vector_ptr[i] = vector_ptr[i+1];
  }
  vector_ptr[length-1] = 0;
  length--;
}

template<typename T>
std::size_t Vector<T>::capacity() const
{
  return capacity;
}

template<typename T>
T* Vector<T>::begin() const
{
  return &vector_ptr[0];
}

template<typename T>
T* Vector<T>::end() const
{
  return &vector_ptr[length-1];
}

template<typename T>
T* Vector<T>::find(T const& element) const
{
  int i = 0;
  while(*element != vector_ptr[i] || i < length)
  {
    i++;
  }

  return &vector_ptr[i];
}



#endif