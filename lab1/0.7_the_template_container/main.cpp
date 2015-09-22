#include "TemplateContainer.h"
using namespace std;

int main(){

	cout << "	DEFAULT CONSTRUCTOR TEST" << endl;
	cout << "(1)	-	Create Vector<int> " << endl;
	Vector<int> a1;
	cout << "Size: " << a1.size() <<" ptr " << a1.vector_ptr << endl;
	cout << "(2)	-	Create Vector<char> " << endl;
	Vector<char> a2;
	cout << "Size: " << a2.size() <<" ptr " << a2.vector_ptr << endl;
	cout << "(3)	-	Create Vector<double> " << endl;
	Vector<double> a3;
	cout << "Size: " << a3.size() <<" ptr " << a3.vector_ptr << endl;
	cout << "(4)	-	Create Vector<char> " << endl;
	Vector<float> a4;
	cout << "Size: " << a4.size() <<" ptr " << a4.vector_ptr << endl;
	cout << "(5)	-	Create Vector<unsigned int>" << endl;
	Vector<unsigned int> a5;
	cout << "Size: " << a5.size() <<" ptr " << a5.vector_ptr << endl<< endl<< endl;



	cout << "	SIZE CONSTRUCTOR TEST" << endl;
	cout << "(1)	-	Create Vector<int> = 0 " << endl;
	Vector<int> b1(0);
	cout << "Size: " << b1.size() <<" ptr " << b1.vector_ptr << endl;
	cout << "(2)	-	Create Vector<char> = 11" << endl;
	Vector<char> b2(11);
	cout << "Size: " << b2.size() <<" ptr " << b2.vector_ptr << endl;
	cout << "(3)	-	Create Vector<double> = 12" << endl;
	Vector<double> b3(12);
	cout << "Size: " << b3.size() <<" ptr " << b3.vector_ptr << endl;
	cout << "(4)	-	Create Vector<char> = 13" << endl;
	Vector<float> b4(13);
	cout << "Size: " << b4.size() <<" ptr " << b4.vector_ptr << endl;
	cout << "(5)	-	Create Vector<unsigned int> = 14" << endl;
	Vector<unsigned int> b5(14);
	cout << "Size: " << b5.size() <<" ptr " << b5.vector_ptr << endl<< endl<< endl;


	std::initializer_list<int> list1 = {1,2,3}; initializer_list<char> list2 = {'b','d','p'};
	initializer_list<double> list3 = {-1.33132,2.313}; initializer_list<float> list4 = {-1123133,0.01,0};
	std::initializer_list<unsigned int> list5 = {};

	cout << "	SIZE LIST TEST" << endl;
	cout << "(1)	-	Create Vector<int> = {1,2,3} " << endl;
	Vector<int> c1(list1);
	cout << "Size: " << c1.size() <<" ptr " << c1.vector_ptr << endl;
	cout << "[0],[2]" << c1[0] << " " << c1[2] << endl;
	cout << "(2)	-	Create Vector<char> = {'b','d','p'}" << endl;
	Vector<char> c2(list2);
	cout << "[0],[2]" << c2[0] << " " << c2[2] << endl;
	cout << "Size: " << c2.size() <<" ptr " << c2.vector_ptr << endl;
	cout << "(3)	-	Create Vector<double> = {-1.33132,2.313} " << endl;
	Vector<double> c3(list3);
	cout << "[0]" << c3[0]  << endl;
	cout << "Size: " << c3.size() <<" ptr " << c3.vector_ptr << endl;
	cout << "(4)	-	Create Vector<char>  = {-1123133,0.01,0};" << endl;
	Vector<float> c4(list4);
	cout << "[0]" << c4[0]  << endl;
	cout << "Size: " << c4.size() <<" ptr " << c4.vector_ptr << endl;
	cout << "(5)	-	Create Vector<unsigned int> = {} " << endl;
	Vector<unsigned int> c5(list5);
	cout << "Size: " << c5.size() <<" ptr " << c5.vector_ptr << endl<< endl<< endl;



	cout << "	COPY TEST" << endl;
	cout << "(1)	-	Create Vector<int> = {1,2,3} " << endl;
	Vector<int> d1(c1);
	cout << "Size: " << d1.size() <<" ptr " << d1.vector_ptr << endl;
	cout << "[0],[2]" << d1[0] << " " << d1[2] << endl;
	cout << "(2)	-	Create Vector<char> = {'b','d','p'}" << endl;
	Vector<char> d2(c2);
	cout << "[0],[2]" << d2[0] << " " << d2[2] << endl;
	cout << "Size: " << d2.size() <<" ptr " << d2.vector_ptr << endl;
	cout << "(3)	-	Create Vector<double> = {-1.33132,2.313} " << endl;
	Vector<double> d3(c3);
	cout << "[0]" << d3[0]  << endl;
	cout << "Size: " << d3.size() <<" ptr " << d3.vector_ptr << endl;
	cout << "(4)	-	Create Vector<char>  = {-1123133,0.01,0};" << endl;
	Vector<float> d4(c4);
	cout << "[0]" << d4[0]  << endl;
	cout << "Size: " << d4.size() <<" ptr " << d4.vector_ptr << endl;
	cout << "(5)	-	Create Vector<unsigned int> = {} " << endl;
	Vector<unsigned int> d5(c5);
	cout << "Size: " << d5.size() <<" ptr " << d5.vector_ptr << endl<< endl<< endl;


	//OBS vector ptr till chars är jobbiga att skriva ut (blir ej adressen utan värdet)
	cout << "	MOVE	TEST" << endl;
	cout << "(1)	-	Create Vector<int> " << endl;
	Vector<int> e1(move(c1)); 
	cout << "From size: " << c1.size() <<" ptr:" << c1.vector_ptr << endl;
	cout << "To size: " << e1.size() <<" ptr:" << e1.vector_ptr << endl;
	cout << "(2)	-	Create Vector<char> " << endl;
	Vector<char> e2(move(c2)); 
	cout << "From size: " << c2.size() << endl;
	cout << "To size: " << e2.size() <<" ptr:" << e2.vector_ptr << endl;
	cout << "(3)	-	Create Vector<double> " << endl;
	Vector<double> e3(move(c3)); 
	cout << "From size: " << c3.size() <<" ptr:" << c3.vector_ptr << endl;
	cout << "To size: " << e3.size() <<" ptr:" << e3.vector_ptr << endl;
	cout << "(4)	-	Create Vector<char> " << endl;
	Vector<float> e4(move(c4)); 
	cout << "From size: " << c4.size() <<" ptr:" << c4.vector_ptr << endl;
	cout << "To size: " << e4.size() <<" ptr:" << e4.vector_ptr << endl;
	cout << "(5)	-	Create Vector<unsigned int>" << endl;
	Vector<unsigned int> e5(move(c5)); 
	cout << "From size: " << c5.size() <<" ptr:" << c5.vector_ptr << endl;
	cout << "To size: " << e5.size() <<" ptr:" << e5.vector_ptr << endl << endl << endl;





	cout << "	ASSIGNMENT =  TEST" << endl;
	cout << "(1)	-	Create Vector<int> " << endl;
	cout << "Innan a " << a1.size() << " d " << d1.size() << endl;
	a1 = d1;
	cout << "efter a " << a1.size() << " d " << d1.size() << endl;
	
	cout << "(2)	-	Create Vector<char> " << endl;
	cout << "Innan e2 " << e2.size() << " a2 " << a2.size() << endl;
	e2 = a2;
	cout << "efter e2 " << e2.size() << " a2 " << a2.size() << endl;

	cout << "(3)	-	Create Vector<double> " << endl;
	cout << "Innan c3 " << c3.size() << " c3 " << c3.size() << endl;
	c3 = c3;
	cout << "efter c3 " << c3.size() << " c3 " << c3.size() << endl;

	cout << "(4)	-	Create Vector<char> " << endl;
	cout << "Innan e4 " << e4.size() << " b4 " << b4.size() << endl;
	e4 = b4;
	cout << "efter e4 " << e4.size() << " b4 " << b4.size() << endl;

	cout << "(5)	-	Create Vector<unsigned int>" << endl;
	cout << "Innan a " << b5.size() << " d5 " << d5.size() << endl;
	b5 = d5;
	cout << "efter a " << b5.size() <<"  d5 " << d5.size() << endl<< endl<< endl;




	cout << "	ASSIGNMENT =  MOVE-ASSIMENT	" << endl;
	cout << "(1)	-	Till sig själv " << endl;
	cout << "Innan e1 " << e1.size() << " ptr " << e1.vector_ptr << endl;
	e1 = move(e1);
	cout << "Efter e1 " << e1.size() << " ptr " << e1.vector_ptr << endl;

	cout << "(2)	-	Annan <int> -> <int> " << endl;
	cout << "Innan d1 " << d1.size() << " ptr " << d1.vector_ptr << endl;
	e1 = move(d1);
	cout << "Efter e1 " << e1.size() << " ptr " << e1.vector_ptr << endl;
	cout << "Efter d1 " << d1.size() << " ptr " << d1.vector_ptr << endl;

	cout << "(3)	-	Annan <int> -> <int> " << endl;
	cout << "Innan e1 " << c3.size() << " ptr " << c3.vector_ptr << endl;
	b3 = move(c3);
	cout << "Efter e1 " << c3.size() << " ptr " << c3.vector_ptr << endl;
	cout << "Efter b3 " << b3.size() << " ptr " << b3.vector_ptr << endl<< endl<< endl;




	cout << "	OPERATOR  []  READ-WRITE 	" << endl;
	Vector<int> f1(list1); Vector<char> f2(list2); Vector<float> f3(list4);
	cout << "(1)	-	Create Vector<int> " << endl;
	cout << "size: " << f1.size() << endl;
	cout << "Ta ut f1[2]" << f1[2] << endl;

	cout << "(2)	-	Create Vector<char> " << endl;
	cout << "size: " << f2.size() << endl;
	cout << "f2[1] = 1;" << endl;
	f2[1] = 1;

	cout << "(3)	-	Create Vector<float> " << endl;
	cout << "size: " << f3.size() << endl;
	cout << "Ta ut f3[0]" << f3[0] << endl << endl << endl;



	cout << "	OPERATOR  []  OPERATOR  []  READ-ONLY 	" << endl;
	
	const Vector<int> aa(list1);
	cout << "(1)	aa[2]" << "size" << aa.size() << endl;
	cout << "aa[2]" << aa[2] << endl;

	const Vector<char> cc(list2);
	cout << "(2)	cc[2]" << "size" << cc.size() << endl;
	cout << "cc[2]" << cc[2] << endl;

	const Vector<float> dd(list4);
	cout << "(3)	dd[2]" << "size" << dd.size() << endl;
	cout << "dd[2]" << dd[2] << endl;

	return 0;
}