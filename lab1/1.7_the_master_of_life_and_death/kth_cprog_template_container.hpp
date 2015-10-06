#ifndef VECTOR_H
#define VECTOR_H  

#include <iostream>
#include <initializer_list>
#include <stdexcept>
#include <typeinfo>
#include <type_traits>



struct T1 {
  T1 () 
  { 
    // std::cout << "T1 Default" << std::endl;
    ++object_count; 
  }
  T1 (T1 const&) 
  { 
    // std::cout << "T1 Copy" << std::endl;
    ++object_count; 
  }
  ~T1 () 
  { 
    // std::cout << "T1 Destructor" << std::endl;
    --object_count;
  }
  static unsigned int object_count;
};


template <typename T>
class Vector
{
  public:
    T** vector_ptr;
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
    const T operator[] (std::size_t index) const;       //Access
    
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

};

// ------------------  DEFUALT 
template<typename T> 
Vector<T>::Vector()
{
  // std::cout << "DEFUALT"<< std::endl;
  static_assert(std::is_move_constructible<T>::value 
    && std::is_move_assignable<T>::value,
  "The type must be move constructable/assignable");

  length = 0; tot_capacity = length*2 + 10; 
  vector_ptr = new T*[length];
}



// ------------------  SIZE         
template<typename T> 
Vector<T>::Vector(std::size_t len)
{
  // std::cout << "SIZE"<< std::endl;
  static_assert(std::is_move_constructible<T>::value 
    && std::is_move_assignable<T>::value,
  "The type must be move constructable/assignable");

  length = len; tot_capacity = length*2 + 10; 
  vector_ptr = new T*[tot_capacity];

  
  for(int i = 0; i < length; i++)
  {
    vector_ptr[i] = new T;
  }

}

// ------------------ SPECIAL CONSTRUCTOR
template<typename T>
Vector<T>::Vector(std::size_t i, T start_value)
{
  // std::cout << "SPECIAL CONSTRUCTOR"<< std::endl;
  static_assert(std::is_move_constructible<T>::value 
  && std::is_move_assignable<T>::value,
  "The type must be move constructable/assignable");

  length = i; tot_capacity = length*2 + 10; 
  vector_ptr = new T*[tot_capacity]();
  for(int i = 0; i<length; i++){
    vector_ptr[i] = new T;
    *vector_ptr[i] = start_value;
  }
}


// ------------------  LIST        
template<typename T> 
Vector<T>::Vector (std::initializer_list<T> list)
{
  // std::cout << "LIST"<< std::endl;
  static_assert(std::is_move_constructible<T>::value 
    && std::is_move_assignable<T>::value,
  "The type must be move constructable/assignable");

  length = list.size(); tot_capacity = length*2 + 10; 
  vector_ptr = new T*[tot_capacity];

  int i = 0;
  for(auto it = list.begin(); it != list.end(); it++)
  {
    vector_ptr[i] = new T;
    *vector_ptr[i] = *it;
    i++;
  }
}

// ------------------  COPY        
template<typename T> 
Vector<T>::Vector(Vector const& obj)
{
  // std::cout << "COPY"<< std::endl;
  static_assert(std::is_move_constructible<T>::value 
    && std::is_move_assignable<T>::value,
  "The type must be move constructable/assignable");

  vector_ptr = new T*[obj.tot_capacity]; length = obj.length;
  tot_capacity = obj.tot_capacity;
  for(std::size_t i = 0; i < obj.length; i++)
  {
    vector_ptr[i] = new T;
    *vector_ptr[i] = *obj.vector_ptr[i];
  }
}

// ------------------  MOVE       
template<typename T> 
Vector<T>::Vector(Vector && obj)
{
  // std::cout << "MOVE"<< std::endl;
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
  std::cout << "DESTRUCTOR"<< std::endl;
  for(int i = 0; i < length; i++)
  {
    delete vector_ptr[i];
  } 

  delete[] vector_ptr;

}

// ------------------  OPERATOR  =    ASSIGNMENT
template<typename T>      
Vector<T>& Vector<T>::operator= (Vector<T> const& obj)
{
  // std::cout << "OPERATOR  =    ASSIGNMENT"<< std::endl;
  if(this != &obj)
  {
    for(int i = 0; i < length; i++)
    {
      delete vector_ptr[i];
    }
    delete[] vector_ptr;
    length = obj.length; tot_capacity = obj.tot_capacity;
    vector_ptr = new T*[tot_capacity];
    for(std::size_t i = 0; i < length; i++)
    {
      vector_ptr[i] = new T;
      *vector_ptr[i] = *obj.vector_ptr[i];
    }
  }
  return *this;
}

// ------------------  OPERATOR  =  MOVE-ASSIGNMENT
template<typename T>      
Vector<T>& Vector<T>::operator= (Vector<T>&& obj)
{
  // std::cout << "OPERATOR  =     MOVE-ASSIGNMENT"<< std::endl;
  if(this != &obj)
  {
    for(int i = 0; i < length; i++)
    {
      delete vector_ptr[i];
    }
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
    return *vector_ptr[index];
  }
}


// ------------------  OPERATOR  []  READ-ONLY
template<typename T> 
const T Vector<T>::operator[] (std::size_t index) const
{
  // std::cout << " OPERATOR  []  READ-ONLY "<< std::endl;
  if(index >= length)
  {
    throw std::out_of_range("Tried to access index out of range");
  }
  else
  { 
    return *vector_ptr[index];
  }
}

// ------------------  RESET
template<typename T> 
void Vector<T>::reset()
{
  T type;
  for(std::size_t i = 0; i < length; i++)
  {
    *vector_ptr[i] = type;
  }
}


// ------------------  SIZE
template<typename T> 
std::size_t Vector<T>::size() const
{
  return length; 
}


// ------------------  CLEAR
template<typename T>
void Vector<T>::clear()
{
  // delete[] vector_ptr;
  // vector_ptr = nullptr; 
  length = 0;
}


// ------------------  PUSH_BACK
template<typename T>
void Vector<T>::push_back(T element)
{
  // std::cout << "PUSH_BACK" << std::endl;
  if(tot_capacity <= length)
  {
    T** old_array = vector_ptr;
    tot_capacity = tot_capacity*2;
    vector_ptr = new T*[tot_capacity];
    for(std::size_t i = 0; i < length; i++)
    {
      vector_ptr[i] = old_array[i];
      // delete old_array[i];
    }
    // delete[] old_array;
  }
  vector_ptr[length] = new T;
  *vector_ptr[length] = element;
  length++;
}



// ------------------  INSERT
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
      T** old_array = vector_ptr;
      tot_capacity = tot_capacity*2;
      vector_ptr = new T*[tot_capacity];

      for(std::size_t i = 0; i < length; i++)
      {
        vector_ptr[i] = new T;
        *vector_ptr[i] = *old_array[i];
      }
      delete[] old_array;
    }

  T** old_array = vector_ptr;
  T temp_value;
  // std::cout << "len " << length << std::endl;
  for(int i = (length); i >= 0; i--)
  {
    // std::cout << "i " << i << " index: " << index << std::endl;
    if(i > index)
    {
      // std::cout <<"if "<< "vec" << vector_ptr[i+1] << "old" << old_array[i] << std::endl;
      *vector_ptr[i] = *old_array[i-1];
    }
    else if( i == index)
    {
      // std::cout <<"else "<< "vec" << vector_ptr[i]<< std::endl;
      *vector_ptr[i] = element;
    }
  }
  length++;
}

// ------------------  ERASE
template<typename T>
void Vector<T>::erase(std::size_t index)
{
  if(index >= length)
  {
    throw std::out_of_range("Tried to access index out of range");
    return;
  }

  delete vector_ptr[index];
  for(int i = index; i < (length-1); i++)
  {
    vector_ptr[i] = vector_ptr[i+1];
  }
  // vector_ptr[length-1] = 0;
  length--;
}

// ------------------  CAPACITY
template<typename T>
std::size_t Vector<T>::capacity() const
{
  return tot_capacity;
}


// ------------------  BEGIN
template<typename T>
T* Vector<T>::begin()
{
  // std::cout << "Begin()" << std::endl;
  return &(*vector_ptr[0]);
}

// ------------------  END
template<typename T>
T* Vector<T>::end()
{
  // std::cout << " end()" << std::endl;
  return &(*vector_ptr[length]);
}

// ------------------  FIND
template<typename T>
T  * Vector<T>::find(T const& element)
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
T const * Vector<T>::begin() const
{
  // std::cout << "const Begin()" << std::endl;
  return &(*vector_ptr[0]);
}

// ------------------  CONST END
template<typename T>
T const * Vector<T>::end() const
{
  // std::cout << "const end()" << std::endl;
  return &(*vector_ptr[length]);
}


// ------------------  FIND CONST
template<typename T>
T const * Vector<T>::find(T const& element) const
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
#endif