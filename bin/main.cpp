#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <math.h>
#include <algorithm>

#include "myHashTable.hpp"

struct teststruct{
	int number;
	std::string str;
	teststruct(int _number, std::string _str): number(_number), str(_str){};
	bool operator==(const teststruct& a) const{
		return a.number == number;
	}

};
typedef struct teststruct teststructtype;

void testvector(const std::vector<int>& test_vector, int numbers){
	struct timeval time_start, time_stop;

	std::cout << "Vector: ";
	std::cout << "Numbers: " << numbers << " ... " << std::flush;
	gettimeofday(&time_start, NULL);

	for(int i=0; i<numbers; i++) find(test_vector.begin(), test_vector.end(), i);

	gettimeofday(&time_stop, NULL);
	std::cout << 1000 * (time_stop.tv_sec - time_start.tv_sec) + (time_stop.tv_usec - time_start.tv_usec) / 1000 << " msec" << std::endl;
}

void testhash(const mns::HashTable::HashTable<int>& test_hashtable, int numbers){
	struct timeval time_start, time_stop;

	std::cout << "HashTable: ";
	std::cout << "Numbers: " << numbers << " ... " << std::flush;
	gettimeofday(&time_start, NULL);

	for(int i=0; i<numbers; i++) test_hashtable.find(i);

	gettimeofday(&time_stop, NULL);
	std::cout << 1000 * (time_stop.tv_sec - time_start.tv_sec) + (time_stop.tv_usec - time_start.tv_usec) / 1000 << " msec" << std::endl;
}

int main(int argc, char ** argv){

	mns::HashTable::HashTable<std::string> testhashtable(15);
	testhashtable.insert("alexis");
	testhashtable.insert("ale2xis");
	testhashtable.insert("alexis");
	testhashtable.insert("alexi3s4is");
	testhashtable.insert("alex5is");
	testhashtable.insert("alex4is");
	testhashtable.insert("a5lexis");
	testhashtable.insert("alex5is");
	testhashtable.insert("ale5xis");
	testhashtable.insert("al5exis");
	std::cout << testhashtable.find("alexis");
	std::cout << testhashtable.find("alexi3s");
	std::cout << testhashtable.find("alexi3s4is");
	std::cout << testhashtable.find("alex5is");
	std::cout << testhashtable.find("ale5x7is");
	std::cout << testhashtable.find("al5exis");
	std::cout << std::endl;
	testhashtable.pretty_print();

	testhashtable.remove("alexis");
	testhashtable.remove("alexi3s");
	testhashtable.remove("al5exis");
	testhashtable.remove("a5lexis");

	std::cout << testhashtable.find("alexis");
	std::cout << testhashtable.find("alexi3s");
	std::cout << testhashtable.find("alexi3s4is");
	std::cout << testhashtable.find("alex5is");
	std::cout << testhashtable.find("ale5x7is");
	std::cout << testhashtable.find("al5exis");
	std::cout << std::endl;
	testhashtable.pretty_print();

	std::cout << "\n---" << std::endl;

	mns::HashTable::HashTable<int> testhashtable1(5);
	for(int i=0; i<15; i++) testhashtable1.insert(i);
	std::cout << testhashtable1.find(1);
	std::cout << testhashtable1.find(2);
	std::cout << testhashtable1.find(16);
	std::cout << testhashtable1.find(3);
	std::cout << testhashtable1.find(4);
	std::cout << testhashtable1.find(121);
	std::cout << testhashtable1.find(5);
	std::cout << testhashtable1.find(7);
	std::cout << testhashtable1.find(9);
	std::cout << testhashtable1.find(11);
	std::cout << testhashtable1.find(145);
	std::cout << testhashtable1.find(13);
	std::cout << testhashtable1.find(14);
	std::cout << testhashtable1.find(15);
	std::cout << testhashtable1.find(19);
	std::cout << std::endl;
	testhashtable1.pretty_print();

	std::cout << "\n---" << std::endl;

	testhashtable1.clear();
	std::cout << testhashtable1.find(5) << std::endl;
	std::cout << testhashtable1.find(9) << std::endl;
	std::cout << testhashtable1.find(14) << std::endl;
	std::cout << testhashtable1.find(0) << std::endl;
	testhashtable1.insert(5);
	testhashtable1.insert(0);
	testhashtable1.insert(14);
	std::cout << testhashtable1.find(5) << std::endl;
	std::cout << testhashtable1.find(9) << std::endl;
	std::cout << testhashtable1.find(14) << std::endl;
	std::cout << testhashtable1.find(0) << std::endl;

	std::cout << "\n---" << std::endl;

	testhashtable1.clear();
	std::cout << "Buckets: " << testhashtable1.getNumberOfElements()  << " Load: " << testhashtable1.getLoad() << std::endl;
	testhashtable1.pretty_print();
	std::cout << std::endl;
	testhashtable1.insert(5);
	std::cout << "Buckets: " << testhashtable1.getNumberOfElements()  << " Load: " << testhashtable1.getLoad() << std::endl;
	testhashtable1.pretty_print();
	std::cout << std::endl;
	testhashtable1.insert(5);
	std::cout << "Buckets: " << testhashtable1.getNumberOfElements()  << " Load: " << testhashtable1.getLoad() << std::endl;
	testhashtable1.pretty_print();
	std::cout << std::endl;
	testhashtable1.insert(14);
	std::cout << "Buckets: " << testhashtable1.getNumberOfElements()  << " Load: " << testhashtable1.getLoad() << std::endl;
	testhashtable1.pretty_print();
	std::cout << std::endl;
	testhashtable1.insert(12);
	std::cout << "Buckets: " << testhashtable1.getNumberOfElements()  << " Load: " << testhashtable1.getLoad() << std::endl;
	testhashtable1.pretty_print();
	std::cout << std::endl;
	testhashtable1.insert(3);
	std::cout << "Buckets: " << testhashtable1.getNumberOfElements()  << " Load: " << testhashtable1.getLoad() << std::endl;
	testhashtable1.pretty_print();
	std::cout << std::endl;
	testhashtable1.insert(1);
	std::cout << "Buckets: " << testhashtable1.getNumberOfElements()  << " Load: " << testhashtable1.getLoad() << std::endl;
	testhashtable1.pretty_print();
	std::cout << std::endl;
	testhashtable1.insert(4);
	std::cout << "Buckets: " << testhashtable1.getNumberOfElements()  << " Load: " << testhashtable1.getLoad() << std::endl;
	testhashtable1.pretty_print();
	std::cout << std::endl;
	testhashtable1.remove(1);
	std::cout << "Buckets: " << testhashtable1.getNumberOfElements()  << " Load: " << testhashtable1.getLoad() << std::endl;
	testhashtable1.pretty_print();
	std::cout << std::endl;
	testhashtable1.remove(3);
	std::cout << "Buckets: " << testhashtable1.getNumberOfElements()  << " Load: " << testhashtable1.getLoad() << std::endl;
	testhashtable1.pretty_print();
	std::cout << std::endl;
	testhashtable1.remove(12);
	std::cout << "Buckets: " << testhashtable1.getNumberOfElements()  << " Load: " << testhashtable1.getLoad() << std::endl;
	testhashtable1.pretty_print();
	std::cout << std::endl;

	std::cout << "\n---" << std::endl;

	int numbers = 40000;
	std::vector<int> myvector;
	std::cout << "Creating arrays... " << std::flush;
	mns::HashTable::HashTable<int> myhashtable(numbers);
	for(int i=0; i<numbers; i++) myhashtable.insert(i);
	for(int i=0; i<numbers; i++) myvector.push_back(i);
	std::cout << "Done" << std::endl;

	testhash(myhashtable,myhashtable.getSize());
	testvector(myvector, myvector.size());
}
