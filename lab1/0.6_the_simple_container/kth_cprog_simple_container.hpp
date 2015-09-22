#ifndef VECTOR_H
#define VECTOR_H  

#include <initializer_list>

class UIntVector 
{
  public:
    unsigned int *vector_ptr;
    std::size_t length;

    UIntVector ();                                          //Default
    explicit UIntVector (std::size_t i);                    //Size_t
    UIntVector (std::initializer_list<unsigned int> list);  //List
    UIntVector (UIntVector const& obj);                     //Copy
    UIntVector (UIntVector&& obj);                          //Move
    ~UIntVector ();                                         //Destructor

    UIntVector& operator= (UIntVector const& obj);          //Assigment  
    UIntVector& operator= (UIntVector&& obj);               //Move-assigment 
    unsigned int& operator[] (std::size_t index);           //Modify 
    unsigned int operator[] (std::size_t index) const;      //Access 
    void reset();
    std::size_t size() const;


};

#endif