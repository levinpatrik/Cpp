#include <iostream>
struct Data {
    int x, y, z;
};  

Data ** foo(Data ** v, int x) {
    for (int i = 0; i < x; i++)
      //   if (v[i] != 0)
    		// std::cout << "inne i if" << std::endl;
            v[i] = new Data;
    return v;
}

int main () {
    const int size = 5;
    Data ** v = new Data * [size];
    //std::cout << v[0] << std::endl;
    // v = foo(v, size);

    Data ** p = foo(v, size);
    for (int i = 0; i < size; i++)
    {
    	delete v[i];
    }
    // delete [] p;
}
