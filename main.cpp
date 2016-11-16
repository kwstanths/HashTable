#include <iostream>
#include <sys/time.h>
#include <unistd.h>
#include <math.h>
#include <algorithm>

#include "HashTable.hpp"

int main(int argc, char ** argv){

	mns::HashTable<std::string> testhashtable(15);
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

	std::cout << "\n---" << std::endl;

	mns::HashTable<int> testhashtable1(5);
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

	int numbers = 40000;
	std::vector<int> myvector;

	std::cout << "Creating arrays... " << std::flush;
	mns::HashTable<int> myhashtable(numbers);
	for(int i=0; i<numbers; i++) myhashtable.insert(i);
	for(int i=0; i<numbers; i++) myvector.push_back(i);
	std::cout << "Done" << std::endl;
	std::cout << "Hash table find... " << std::flush;
	for(int i=0; i<numbers; i++) myhashtable.find(i);
	std::cout << "Done" << std::endl;
	std::cout << "Vector find... " << std::flush;
	for(int i=0; i<numbers; i++) find(myvector.begin(), myvector.end(), i);
	std::cout << "Done." << std::endl;

}
