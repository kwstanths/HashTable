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

	std::cout << "Search Vector: ";
	std::cout << "Numbers: " << numbers << " ... " << std::flush;
	gettimeofday(&time_start, NULL);

	for(int i=0; i<numbers; i++) find(test_vector.begin(), test_vector.end(), i);

	gettimeofday(&time_stop, NULL);
	std::cout << 1000 * (time_stop.tv_sec - time_start.tv_sec) + (time_stop.tv_usec - time_start.tv_usec) / 1000 << " msec" << std::endl;
}

void testhash(const mns::HashTable<int, int>& test_hashtable, int numbers){
	struct timeval time_start, time_stop;

	std::cout << "Search HashTable: ";
	std::cout << "Numbers: " << numbers << " ... " << std::flush;
	gettimeofday(&time_start, NULL);

	for(int i=0; i<numbers; i++) test_hashtable.Find(i);

	gettimeofday(&time_stop, NULL);
	std::cout << 1000 * (time_stop.tv_sec - time_start.tv_sec) + (time_stop.tv_usec - time_start.tv_usec) / 1000 << " msec" << std::endl;
}

int main(int argc, char ** argv){

	mns::HashTable<std::string, int> testhashtable(15);
	testhashtable.Insert("alexis", 1);
	testhashtable.Insert("ale2xis", 2);
	testhashtable.Insert("alexis", 3);
	testhashtable.Insert("alexi3s4is", 4);
	testhashtable.Insert("alex5is", 5);
	testhashtable.Insert("alex4is", 6);
	testhashtable.Insert("a5lexis", 7);
	testhashtable.Insert("alex5is", 8);
	testhashtable.Insert("ale5xis", 9);
	testhashtable.Insert("al5exis", 10);
	auto itr = testhashtable.Find("alexis");
	if (itr != testhashtable.end()) std::cout << itr.GetKey() << " " << itr.GetValue() << std::endl; 
	itr = testhashtable.Find("alexi3s");
	if (itr != testhashtable.end()) std::cout << itr.GetKey() << " " << itr.GetValue() << std::endl; 	
	itr = testhashtable.Find("alexi3s4is");
	if (itr != testhashtable.end()) std::cout << itr.GetKey() << " " << itr.GetValue() << std::endl; 	\
	itr = testhashtable.Find("alex5is");
	if (itr != testhashtable.end()) std::cout << itr.GetKey() << " " << itr.GetValue() << std::endl; 	
	itr = testhashtable.Find("ale5x7is");
	if (itr != testhashtable.end()) std::cout << itr.GetKey() << " " << itr.GetValue() << std::endl; 	
	itr = testhashtable.Find("al5exis");
	if (itr != testhashtable.end()) std::cout << itr.GetKey() << " " << itr.GetValue() << std::endl; 	
	testhashtable.PrettyPrint();

	testhashtable.Remove("alexis");
	testhashtable.Remove("alexi3s");
	testhashtable.Remove("al5exis");
	testhashtable.Remove("a5lexis");

	itr = testhashtable.Find("alexis");
	if (itr != testhashtable.end()) std::cout << itr.GetKey() << " " << itr.GetValue() << std::endl; 	
	itr = testhashtable.Find("alexi3s");
	if (itr != testhashtable.end()) std::cout << itr.GetKey() << " " << itr.GetValue() << std::endl; 	
	itr = testhashtable.Find("alexi3s4is");
	if (itr != testhashtable.end()) std::cout << itr.GetKey() << " " << itr.GetValue() << std::endl; 	
	itr = testhashtable.Find("alex5is");
	if (itr != testhashtable.end()) std::cout << itr.GetKey() << " " << itr.GetValue() << std::endl; 	
	itr = testhashtable.Find("ale5x7is");
	if (itr != testhashtable.end()) std::cout << itr.GetKey() << " " << itr.GetValue() << std::endl; 	
	itr = testhashtable.Find("al5exis");
	if (itr != testhashtable.end()) std::cout << itr.GetKey() << " " << itr.GetValue() << std::endl; 	
	std::cout << std::endl;
	testhashtable.PrettyPrint();

	std::cout << "\n---" << std::endl;

	mns::HashTable<int, int> testhashtable1(5);
	for(int i=0; i<15; i++) testhashtable1.Insert(i, i);
	testhashtable1.PrettyPrint();	
	auto itr2 = testhashtable1.Find(1);
	if (itr2!=testhashtable1.end()) std::cout << itr2.GetKey() << std::endl;
	itr2 = testhashtable1.Find(2);
	if (itr2!=testhashtable1.end()) std::cout << itr2.GetKey() << std::endl;
	itr2 = testhashtable1.Find(16);
	if (itr2!=testhashtable1.end()) std::cout << itr2.GetKey() << std::endl;
	itr2 = testhashtable1.Find(3);
	if (itr2!=testhashtable1.end()) std::cout << itr2.GetKey() << std::endl;
	itr2 = testhashtable1.Find(4);
	if (itr2!=testhashtable1.end()) std::cout << itr2.GetKey() << std::endl;
	itr2 = testhashtable1.Find(121);
	if (itr2!=testhashtable1.end()) std::cout << itr2.GetKey() << std::endl;
	itr2 = testhashtable1.Find(5);
	if (itr2!=testhashtable1.end()) std::cout << itr2.GetKey() << std::endl;
	itr2 = testhashtable1.Find(7);
	if (itr2!=testhashtable1.end()) std::cout << itr2.GetKey() << std::endl;
	itr2 = testhashtable1.Find(9);
	if (itr2!=testhashtable1.end()) std::cout << itr2.GetKey() << std::endl;
	itr2 = testhashtable1.Find(11);
	if (itr2!=testhashtable1.end()) std::cout << itr2.GetKey() << std::endl;
	itr2 = testhashtable1.Find(145);
	if (itr2!=testhashtable1.end()) std::cout << itr2.GetKey() << std::endl;
	itr2 = testhashtable1.Find(13);
	if (itr2!=testhashtable1.end()) std::cout << itr2.GetKey() << std::endl;
	itr2 = testhashtable1.Find(14);
	if (itr2!=testhashtable1.end()) std::cout << itr2.GetKey() << std::endl;
	itr2 = testhashtable1.Find(15);
	if (itr2!=testhashtable1.end()) std::cout << itr2.GetKey() << std::endl;
	itr2 = testhashtable1.Find(19);
	if (itr2!=testhashtable1.end()) std::cout << itr2.GetKey() << std::endl;

	std::cout << "\n---" << std::endl;

	testhashtable1.Clear();
	testhashtable1.PrettyPrint();
	itr2 = testhashtable1.Find(5);
	if (itr2!=testhashtable1.end()) std::cout << itr2.GetKey() << std::endl;
	itr2 = testhashtable1.Find(9);
	if (itr2!=testhashtable1.end()) std::cout << itr2.GetKey() << std::endl;
	itr2 = testhashtable1.Find(14);
	if (itr2!=testhashtable1.end()) std::cout << itr2.GetKey() << std::endl;
	itr2 = testhashtable1.Find(0);
	if (itr2!=testhashtable1.end()) std::cout << itr2.GetKey() << std::endl;
	testhashtable1.Insert(5, 5);
	testhashtable1.Insert(0, 0);
	testhashtable1.Insert(14, 14);
	testhashtable1.PrettyPrint();
	itr2 = testhashtable1.Find(5);
	if (itr2!=testhashtable1.end()) std::cout << itr2.GetKey() << std::endl;
	itr2 = testhashtable1.Find(9);
	if (itr2!=testhashtable1.end()) std::cout << itr2.GetKey() << std::endl;
	itr2 = testhashtable1.Find(14);
	if (itr2!=testhashtable1.end()) std::cout << itr2.GetKey() << std::endl;
	itr2 = testhashtable1.Find(0);
	if (itr2!=testhashtable1.end()) std::cout << itr2.GetKey() << std::endl;

	std::cout << "\n---" << std::endl;

	testhashtable1.Clear();
	std::cout << "Buckets: " << testhashtable1.GetNumberOfElements()  << " Load: " << testhashtable1.GetLoad() << std::endl;
	testhashtable1.PrettyPrint();
	std::cout << std::endl;
	testhashtable1.Insert(5, 5);
	std::cout << "Buckets: " << testhashtable1.GetNumberOfElements()  << " Load: " << testhashtable1.GetLoad() << std::endl;
	testhashtable1.PrettyPrint();
	std::cout << std::endl;
	testhashtable1.Insert(5, 5);
	std::cout << "Buckets: " << testhashtable1.GetNumberOfElements()  << " Load: " << testhashtable1.GetLoad() << std::endl;
	testhashtable1.PrettyPrint();
	std::cout << std::endl;
	testhashtable1.Insert(14, 14);
	std::cout << "Buckets: " << testhashtable1.GetNumberOfElements()  << " Load: " << testhashtable1.GetLoad() << std::endl;
	testhashtable1.PrettyPrint();
	std::cout << std::endl;
	testhashtable1.Insert(12, 12);
	std::cout << "Buckets: " << testhashtable1.GetNumberOfElements()  << " Load: " << testhashtable1.GetLoad() << std::endl;
	testhashtable1.PrettyPrint();
	std::cout << std::endl;
	testhashtable1.Insert(3, 3);
	std::cout << "Buckets: " << testhashtable1.GetNumberOfElements()  << " Load: " << testhashtable1.GetLoad() << std::endl;
	testhashtable1.PrettyPrint();
	std::cout << std::endl;
	testhashtable1.Insert(1, 1);
	std::cout << "Buckets: " << testhashtable1.GetNumberOfElements()  << " Load: " << testhashtable1.GetLoad() << std::endl;
	testhashtable1.PrettyPrint();
	std::cout << std::endl;
	testhashtable1.Insert(4, 4);
	std::cout << "Buckets: " << testhashtable1.GetNumberOfElements()  << " Load: " << testhashtable1.GetLoad() << std::endl;
	testhashtable1.PrettyPrint();
	std::cout << std::endl;
	testhashtable1.Remove(1);
	std::cout << "Buckets: " << testhashtable1.GetNumberOfElements()  << " Load: " << testhashtable1.GetLoad() << std::endl;
	testhashtable1.PrettyPrint();
	std::cout << std::endl;
	testhashtable1.Remove(3);
	std::cout << "Buckets: " << testhashtable1.GetNumberOfElements()  << " Load: " << testhashtable1.GetLoad() << std::endl;
	testhashtable1.PrettyPrint();
	std::cout << std::endl;
	testhashtable1.Remove(12);
	std::cout << "Buckets: " << testhashtable1.GetNumberOfElements()  << " Load: " << testhashtable1.GetLoad() << std::endl;
	testhashtable1.PrettyPrint();
	std::cout << std::endl;

	std::cout << "\n---" << std::endl;

	mns::HashTable<std::string, int> autosizeht(5, 1.0);
	autosizeht.Insert("hello", 1);
	autosizeht.Insert("from", 2);
	autosizeht.Insert("the", 3);
	autosizeht.Insert("other", 4);
	autosizeht.PrettyPrint();	
	autosizeht.Insert("side, ", 5);
	autosizeht.Insert("I've", 6);
	autosizeht.PrettyPrint();

	std::cout << "\n---" << std::endl;

	mns::HashTable<std::string, int> testhashtable3(5, 1);
	testhashtable3.Insert("hello", 1);
	testhashtable3.Insert("from", 2);
	testhashtable3.Insert("the", 3);
	testhashtable3.Insert("other", 4);
	testhashtable3.PrettyPrint();
	testhashtable3.Insert("side", 5);
	testhashtable3.Insert("I", 6);
	testhashtable3.Insert("must", 7);
	testhashtable3.Insert("'ve", 8);
	testhashtable3.Insert("called", 9);
	testhashtable3.PrettyPrint();
	testhashtable3.Insert("a", 10);
	testhashtable3.Insert("thousand", 11);
	testhashtable3.Insert("times", 12);
	testhashtable3.Insert("to", 13);
	testhashtable3.Insert("tell", 14);
	testhashtable3.Insert("you", 15);
	testhashtable3.PrettyPrint();


	
	std::cout << "\n---" << std::endl;
	
	int numbers = 50000;
	std::vector<int> myvector;
	std::cout << "Creating arrays... " << std::endl;
	mns::HashTable<int, int> myhashtable(numbers);
	mns::HashTable<int, int> myhashtable1(5, 1);
	struct timeval time_start, time_stop;
	
	gettimeofday(&time_start, NULL);
	for(int i=0; i<numbers; i++) myhashtable.Insert(i, i);
	gettimeofday(&time_stop, NULL);
	std::cout << "Creating without rehashing: " << 1000 * (time_stop.tv_sec - time_start.tv_sec) + (time_stop.tv_usec - time_start.tv_usec) / 1000 << " msec" << std::endl;
	
	gettimeofday(&time_start, NULL);
	for(int i=0; i<numbers; i++) myhashtable1.Insert(i, i);
	gettimeofday(&time_stop, NULL);
	std::cout << "Creating with rehashing: " << 1000 * (time_stop.tv_sec - time_start.tv_sec) + (time_stop.tv_usec - time_start.tv_usec) / 1000 << " msec" << std::endl;
	
	gettimeofday(&time_start, NULL);
	for(int i=0; i<numbers; i++) myvector.push_back(i);
	gettimeofday(&time_stop, NULL);
	std::cout << "Creating vector: " << 1000 * (time_stop.tv_sec - time_start.tv_sec) + (time_stop.tv_usec - time_start.tv_usec) / 1000 << " msec" << std::endl;
	
	testhash(myhashtable, numbers);
	testhash(myhashtable1, numbers);
	testvector(myvector, numbers);
}
