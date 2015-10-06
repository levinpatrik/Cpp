#ifndef SafeVector_H
#define SafeVector_H  

#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <typeinfo>
#include <type_traits>
#include <mutex>



template <typename T>
class SafeVector
{
  public:
    std::mutex MUTEX;
    T *SafeVector_ptr;
    std::size_t length;
    std::size_t tot_capacity;


    SafeVector ();                                          //Default
    explicit SafeVector (std::size_t i);                    //Size_t
    SafeVector (std::size_t i, T);                          //Special constructor
    SafeVector (std::initializer_list<T> list);             //List
    SafeVector (SafeVector const& obj);                     //Copy
    SafeVector (SafeVector&& obj);                          //Move
    ~SafeVector ();                                         //Destructor

    SafeVector& operator= (SafeVector const& obj);          //ASSIGNMENT
    SafeVector& operator= (SafeVector&& obj);               //Move-ASSIGNMENT      
    T& operator[] (std::size_t index);                      //Modify
    const T operator[] (std::size_t index) const;           //Access
    
    void reset();
    void clear();
    void push_back(T);
    void insert(std::size_t , T);
    void erase(std::size_t);
    std::size_t size() const;
    std::size_t capacity() const;
    T const *  begin() const;
    T const *  end() const;
    T const * find(T const&) const;
    T* begin();
    T* end();
    T* find(T const&);
    void safeswap(std::size_t, std::size_t);




};

// ------------------  DEFUALT 
template<typename T> 
SafeVector<T>::SafeVector()
{
  // std::cout << "DEFUALT"<< std::endl;
  static_assert(std::is_move_constructible<T>::value 
    && std::is_move_assignable<T>::value,
  "The type must be move constructable/assignable");

  length = 0; tot_capacity = length*2 + 10; 
  SafeVector_ptr = new T[tot_capacity];
  // reset();
}



// ------------------  SIZE         
template<typename T> 
SafeVector<T>::SafeVector(std::size_t i)
{
  // std::cout << "SIZE"<< std::endl;
  static_assert(std::is_move_constructible<T>::value 
    && std::is_move_assignable<T>::value,
  "The type must be move constructable/assignable");

  length = i; tot_capacity = length*2 + 10; 
  SafeVector_ptr = new T[tot_capacity]();
  // reset();
}

// ------------------ SPECIAL CONSTRUCTOR
template<typename T>
SafeVector<T>::SafeVector(std::size_t i, T start_value)
{
  // std::cout << "SPECIAL CONSTRUCTOR"<< std::endl;
  static_assert(std::is_move_constructible<T>::value 
  && std::is_move_assignable<T>::value,
  "The type must be move constructable/assignable");

  length = i; tot_capacity = length*2 + 10; 
  SafeVector_ptr = new T[tot_capacity]();
  for(int i = 0; i<length; i++){
    SafeVector_ptr[i] = start_value;
  }
}


// ------------------  LIST        
template<typename T> 
SafeVector<T>::SafeVector (std::initializer_list<T> list)
{
  // std::cout << "LIST"<< std::endl;
  static_assert(std::is_move_constructible<T>::value 
    && std::is_move_assignable<T>::value,
  "The type must be move constructable/assignable");

  length = list.size(); tot_capacity = length*2 + 10; 
  SafeVector_ptr = new T[tot_capacity];

  int i = 0;
  for(auto it = list.begin(); it != list.end(); it++)
  {
    SafeVector_ptr[i] = *it;
    i++;
  }
}

// ------------------  COPY        
template<typename T> 
SafeVector<T>::SafeVector(SafeVector const& obj)
{
  // std::cout << "COPY"<< std::endl;
  static_assert(std::is_move_constructible<T>::value 
    && std::is_move_assignable<T>::value,
  "The type must be move constructable/assignable");

  SafeVector_ptr = new T[obj.tot_capacity]; length = obj.length;
  tot_capacity = obj.tot_capacity;
  for(std::size_t i = 0; i < obj.length; i++)
  {
    SafeVector_ptr[i] = obj.SafeVector_ptr[i];
  }
}

// ------------------  MOVE       
template<typename T> 
SafeVector<T>::SafeVector(SafeVector && obj)
{
  // std::cout << "MOVE"<< std::endl;
  static_assert(std::is_move_constructible<T>::value 
    && std::is_move_assignable<T>::value,
  "The type must be move constructable/assignable");

  SafeVector_ptr = obj.SafeVector_ptr; length = obj.length; tot_capacity = obj.tot_capacity;
  obj.length = 0; obj.SafeVector_ptr = nullptr; obj.tot_capacity = 0;

}

// ------------------  DESTRUCTOR  
template<typename T> 
SafeVector<T>::~SafeVector()
{
  delete[] SafeVector_ptr;
}


// ------------------  OPERATOR  =    ASSIGNMENT
template<typename T>      
SafeVector<T>& SafeVector<T>::operator= (SafeVector<T> const& obj)
{
  // std::cout << "OPERATOR  =    ASSIGNMENT"<< std::endl;
  if(this != &obj)
  {
    delete[] SafeVector_ptr;
    length = obj.length;
    tot_capacity = obj.tot_capacity;
    SafeVector_ptr = new T[tot_capacity];
    for(std::size_t i = 0; i < length; i++)
    {
      SafeVector_ptr[i] = obj.SafeVector_ptr[i];
    }
  }
  return *this;
}

// ------------------  OPERATOR  =  MOVE-ASSIGNMENT
template<typename T>      
SafeVector<T>& SafeVector<T>::operator= (SafeVector<T>&& obj)
{
  // std::cout << "OPERATOR  =     MOVE-ASSIGNMENT"<< std::endl;
  if(this != &obj)
  {
    delete[] SafeVector_ptr;
    SafeVector_ptr = obj.SafeVector_ptr; length = obj.length; tot_capacity = obj.tot_capacity;
    obj.SafeVector_ptr = nullptr; obj.tot_capacity = 0; obj.length = 0;
  }
  return *this;
}

// ------------------  OPERATOR  []  READ-WRITE 
template<typename T> 
T& SafeVector<T>::operator[] (std::size_t index)
{
  // std::cout << "OPERATOR  []  READ-WRITE "<< std::endl;
  if(index >= length)
  {
    throw std::out_of_range("Tried to access index out of range");
  }
  else
  {
    return SafeVector_ptr[index];
  }
}


// ------------------  OPERATOR  []  READ-ONLY
template<typename T> 
const T SafeVector<T>::operator[] (std::size_t index) const
{
  // std::cout << " OPERATOR  []  READ-ONLY "<< std::endl;
  if(index >= length)
  {
    throw std::out_of_range("Tried to access index out of range");
  }
  else
  { 
    return SafeVector_ptr[index];
  }
}

// ------------------  CONST RESET
template<typename T> 
void SafeVector<T>::reset()
{
  T type;
  for(std::size_t i = 0; i < length; i++)
  {
    SafeVector_ptr[i] = type;
  }
}


// ------------------  SIZE
template<typename T> 
std::size_t SafeVector<T>::size() const
{
  return length; 
}


// ------------------  CLEAR
template<typename T>
void SafeVector<T>::clear()
{
  // delete[] SafeVector_ptr;
  // SafeVector_ptr = nullptr; 
  length = 0;
}


// ------------------  PUSH_BACK
template<typename T>
void SafeVector<T>::push_back(T element)
{
  if(tot_capacity <= length)
  {
    T* old_array = SafeVector_ptr;
    tot_capacity = tot_capacity*2;
    SafeVector_ptr = new T[tot_capacity];

    for(std::size_t i = 0; i < length; i++)
    {
      SafeVector_ptr[i] = old_array[i];
    }
    delete[] old_array;
  }
  SafeVector_ptr[length] = element;
  length++;
}



// ------------------  INSERT
template<typename T>
void SafeVector<T>::insert(std::size_t index, T element)
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
      T* old_array = SafeVector_ptr;
      tot_capacity = tot_capacity*2;
      SafeVector_ptr = new T[tot_capacity];

      for(std::size_t i = 0; i < length; i++)
      {
        SafeVector_ptr[i] = old_array[i];
      }
      delete[] old_array;
    }

  T* old_array = SafeVector_ptr;
  T temp_value;
  // std::cout << "len " << length << std::endl;
  for(int i = (length); i >= 0; i--)
  {
    // std::cout << "i " << i << " index: " << index << std::endl;
    if(i > index)
    {
      // std::cout <<"if "<< "vec" << SafeVector_ptr[i+1] << "old" << old_array[i] << std::endl;
      SafeVector_ptr[i] = old_array[i-1];
    }
    else if( i == index)
    {
      // std::cout <<"else "<< "vec" << SafeVector_ptr[i]<< std::endl;
      SafeVector_ptr[i] = element;
    }
  }
  length++;
}

// ------------------  ERASE
template<typename T>
void SafeVector<T>::erase(std::size_t index)
{
  if(index >= length)
  {
    throw std::out_of_range("Tried to access index out of range");
    return;
  }

  for(int i = index; i < (length-1); i++)
  {
    SafeVector_ptr[i] = SafeVector_ptr[i+1];
  }
  // SafeVector_ptr[length-1] = 0;
  length--;
}

// ------------------  CAPACITY
template<typename T>
std::size_t SafeVector<T>::capacity() const
{
  return tot_capacity;
}


// ------------------  BEGIN
template<typename T>
T* SafeVector<T>::begin()
{
  // std::cout << "Begin()" << std::endl;
  return &SafeVector_ptr[0];
}

// ------------------  END
template<typename T>
T* SafeVector<T>::end()
{
  // std::cout << " end()" << std::endl;
  return &SafeVector_ptr[length];
}

// ------------------  FIND
template<typename T>
T  * SafeVector<T>::find(T const& element)
{
  // std::cout << "find()" << std::endl;
  T* current_p = begin();
  T* end_p   = end();
  while(current_p != end_p)
  {
    if(*current_p == element)
    {
      return current_p;
    }
    current_p++;
  }
  return end_p;

}

// ------------------  CONST BEGIN
template<typename T>
T const * SafeVector<T>::begin() const
{
  // std::cout << "const Begin()" << std::endl;
  return &SafeVector_ptr[0];
}

// ------------------  CONST END
template<typename T>
T const * SafeVector<T>::end() const
{
  // std::cout << "const end()" << std::endl;
  return &SafeVector_ptr[length];
}


// ------------------  FIND CONST
template<typename T>
T const * SafeVector<T>::find(T const& element) const
{
  // std::cout << "find()" << std::endl;

  const T* current_p = begin();
  const T* end_p   = end();
  while(current_p != end_p)
  {
    if(*current_p == element)
    {
      return current_p;
    }
    current_p++;
  }
  return end_p;
}

// ------------------  SWAP
template<typename T>
void SafeVector<T>::safeswap (std::size_t index1, std::size_t index2)
{

  // std::cout << "SWAP" << std::endl;
  MUTEX.try_lock();

  T swap_temp = SafeVector_ptr[index1];
  SafeVector_ptr[index1] = SafeVector_ptr[index2];
  SafeVector_ptr[index2] = swap_temp;

  MUTEX.unlock();

}

#endif









