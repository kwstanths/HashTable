#ifndef __HASHTABLE_HPP__
#define __HASHTABLE_HPP__

#include <iostream>
#include <vector>

#include "mylist.hpp"

namespace mns{

namespace HashTable {
      //TODO binary trees instead of list?
      template<typename T> class HashTable{
      private:
            std::vector<mns::list::list<T> * > * hashtable;
            unsigned long int size, elements;
            double max_load;

            void rehash(){
                  size = 2 * size;
                  std::vector<mns::list::list<T> * > *temp;
                  temp = hashtable;
                  hashtable = new std::vector<mns::list::list<T> * >(size, NULL);
                  elements = 0;
                  for(typename std::vector<mns::list::list<T> *>::iterator itr = temp->begin(); itr!=temp->end(); ++itr){
                        if (*itr != NULL)
                              for(typename mns::list::list<T>::iterator itr2 = (*itr)->begin(); itr2 != (*itr)->end(); itr2+=1) {
                                    insert(*itr2);
                              }
                  }
                  delete temp;
            }

            unsigned long int getHash(T _value) const {
                  return std::hash<T>{}(_value) % size;
            }

      public:
            /*
                  Initialize a hash table with size _size
                  No matter how many elements you insert, the hashtable's size won't change
            */
            HashTable(unsigned long int _size){
                  if (_size <= 0) throw std::out_of_range("Hash table size must be a positive number");
                  hashtable = new std::vector<mns::list::list<T> * >(_size, NULL);
                  size = _size;
                  elements = 0;
                  max_load = -1;
            }

            /*
                  Initialize a hash table with size _size and max load (elements/size) equal to _max_load
                  When an element is inserted if elements/size > _max_load then a rehashing will occur with
                  the new hashtable size equal to double the previous size
            */
            HashTable(unsigned long int _size, double _max_load){
                  if (_size <= 0) throw std::out_of_range("Hash table size must be a positive number");
                  hashtable = new std::vector<mns::list::list<T> * >(_size, NULL);
                  size = _size;
                  elements = 0;
                  max_load = _max_load;
            }

            ~HashTable(){
                  clear();
            }

            /*
                  Insert an element to the hashtable. If rehashing is enabled when HashTable was constructed then this operation
                  might take more time then expected in some cases.
            */
            bool insert(T _value) {
                  unsigned long int hash_value = getHash(_value);
                  bool ret = false;
                  if (hashtable->at(hash_value) == NULL) {
                        hashtable->at(hash_value) = new mns::list::list<T>(_value);
                        ret = true;
                  }
                  else if (hashtable->at(hash_value)->find_forward(_value) == -1) {
                        hashtable->at(hash_value)->push_top(_value);
                        ret = true;
                  }
                  if (ret) elements++;

                  if ((max_load > 0) && (getLoad() >= max_load)) rehash();
            }

            /*
                  Search for an element in the HashTable
            */
            bool find(T _value) const {
                  unsigned long int hash_value = getHash(_value);

                  if (hashtable->at(hash_value) == NULL) return false;
                  int ret = hashtable->at(hash_value)->find_forward(_value);

                  if (ret == -1) return false;
                  return true;
            }

            /*
                  Remove an element from the hash table
            */
            bool remove(T _value) {
                  unsigned long int hash_value = getHash(_value);

                  bool ret = false;
                  if (hashtable->at(hash_value) != NULL) ret = hashtable->at(hash_value)->remove(_value);
                  if (ret) elements--;

                  return false;
            }

            /*
                  Get hash table's current size. If rehashing is enabled then this value might differ from the one given
                  during object construction
            */
            unsigned long int getSize() const {
                  return size;
            }

            /*
                  Get number of elements inserted in the hash table
            */
            unsigned long int getNumberOfElements() const {
                  return elements;
            }

            /*
                  Get the load of the hash table as (inserted elements/ size)
            */
            double getLoad() const {
                  return (1.0*elements) / (1.0*size);
            }

            /*
                  Prints the hash table in a relatively nice format
            */
            void pretty_print() const {
                  std::cout << "Hash table:" << std::endl;;
                  for(typename std::vector<mns::list::list<T> *>::iterator itr = hashtable->begin(); itr!=hashtable->end(); ++itr){
                        if (*itr != NULL)
                              for(typename mns::list::list<T>::iterator itr2 = (*itr)->begin(); itr2 != (*itr)->end(); itr2+=1) std:: cout << (*itr2) << " -> ";
                        std::cout << "null" << std::endl;
                  }
            }

            /*
                  Removes all the inserted elements
            */
            void clear(){
                  for(typename std::vector<mns::list::list<T> *>::iterator itr = hashtable->begin(); itr!=hashtable->end(); ++itr) {
                        delete *itr;
                        *itr = NULL;
                  }
                  elements = 0;
            }

      };

}

}

#endif
