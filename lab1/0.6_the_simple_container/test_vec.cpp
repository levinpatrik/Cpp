#include <iostream>
#include <stdexcept>
#include "kth_cprog_simple_container.hpp"

int main()
{
    // Några saker som ska fungera:
    UIntVector a(10);               // initiering med 7 element
    std::cout << "a(10)"<< a.length << std::endl;
    std::cout << "kopiering" << std::endl;
    UIntVector b(a);           // kopieringskonstruktor 
    std::cout << "kopiering" << std::endl;
    a = a;
    std::cout << "slut" << std::endl;
    UIntVector c = a;          // kopieringskonstruktor 

    //Extra tester för alla Requirments
    a = b;                 // tilldelning genom kopiering
    a[5] = 7;              // tilldelning till element

    const UIntVector e(100000);    // konstant objekt med 10 element
    int i = e[5];          // const int oper[](int) const körs
    i = a[0];              // vektorn är nollindexerad
    i = a[5];              // int oper[](int) körs
    
    a[5]++;                // öka värdet till 8
    
    //Extra tester för alla Requirments
    std::cout << "(1)TEST" << std::endl;
    int aa = e[9];
    int ab = e[0];
    std::cout << "(1)SLUT" << aa << ab << std::endl;


    std::cout << "(2)TEST" << std::endl;
    for(long int i = 0; i < 100000; i++)
    {
        e[i];
    } 
    std::cout << "(2)SLUT" << std::endl;




    std::cout << "(3)TEST" << std::endl;
    UIntVector a3(10); UIntVector b3(0); UIntVector c3(0);
    b3 = a3;
    a3 = c3;
    std::cout << "(3)SLUT" << std::endl;




    std::cout << "(4) START" << std::endl;
    std::initializer_list<unsigned int> list = {1,2,3};
    UIntVector a4(list); UIntVector b4(0);
    a4 = b4;
    std::cout << "length a" << a4.size() << "len b " << b4.size() << std::endl;
    std::cout << "(4) SLUT" << std::endl;



    std::cout << "(5)TEST" << std::endl;
    UIntVector b5(list);
    UIntVector a5(std::move(b5));
    std::cout << "(5)SLUT" << std::endl;





    std::cout << "(6)TEST" << std::endl;
    UIntVector a6(30);
    UIntVector b6(a6);
    std::cout << "(6)SLUT" << std::endl;


    std::cout << "(7)TEST" << std::endl;
    UIntVector a7(1); 
    std::cout << "a) len innan " <<a7.length << std::endl;
    UIntVector b7(std::move(a7));
    std::cout << "b) len " <<b7.length << std::endl;
    std::cout << "a) len " <<a7.length << std::endl;
    std::cout << "(7)SLUT" << std::endl;

    std::cout << "(8)TEST" << std::endl;
    UIntVector a8(10);
    a8.reset();
    UIntVector b8(11);
    std::cout << "a) INNAN len " <<a8.size() << "ptr " << a8.vector_ptr <<std::endl;
    UIntVector c8(std::move(a8));
    std::cout << "c) len " <<c8.size() << "ptr" << c8.vector_ptr <<std::endl;
    std::cout << "a) len " <<a8.size() << "ptr " << a8.vector_ptr <<std::endl;
    std::cout << "(8)SLUT" << std::endl;


    std::cout << "(9)TEST COPY TO SELF" << std::endl;
    b8 = b8;
    std::cout << "(9)SLUT" << std::endl;
    try {
        i = e[10];             // försöker hämta element som ligger utanför e
    } catch (std::out_of_range e) {
        std::cout << e.what() << std::endl;
    }

    
#if 0
    // Diverse saker att testa
    e[5] = 3;              // fel: (kompilerar ej) tilldelning till const
    b = b;                 // hmm: se till att inte minnet som skall behållas frigörs
#endif

    return 0;
}