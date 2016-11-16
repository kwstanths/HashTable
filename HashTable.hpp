#ifndef __HASHTABLE_HPP__
#define __HASHTABLE_HPP__

#include <iostream>
#include <vector>

#include "mylist.hpp"

namespace mns{
      template<typename T> class HashTable{
      private:
            std::vector<mns::list<T> * > * hashtable;
            long long int size;

      public:
            HashTable(int _size){
                  hashtable = new std::vector<mns::list<T> * >(_size, NULL);
                  size = _size;
            }

            ~HashTable(){
                  for(typename std::vector<mns::list<T> *>::iterator itr = hashtable->begin(); itr!=hashtable->end(); ++itr) delete *itr;
            }

            long long int getHash(T _value){
                  return std::hash<T>{}(_value) % size;
            }

            bool insert(T _value){
                  long long int hash_value = getHash(_value);

                  if (hashtable->at(hash_value) == NULL) hashtable->at(hash_value) = new mns::list<T>(_value);
                  else if (hashtable->at(hash_value)->find_forward(_value) == -1) hashtable->at(hash_value)->push_top(_value);
            }

            bool find(T _value){
                  long long int hash_value = getHash(_value);

                  if (hashtable->at(hash_value) == NULL) return false;
                  int ret = hashtable->at(hash_value)->find_forward(_value);

                  if (ret == -1) return false;
                  return true;
            }

            void pretty_print(){
                  std::cout << "Hash table:" << std::endl;;
                  for(typename std::vector<mns::list<T> *>::iterator itr = hashtable->begin(); itr!=hashtable->end(); ++itr){
                        if (*itr != NULL)
                              for(int i=0; i<(*itr)->size(); i++) std::cout << "* -> ";
                        std::cout << "null" << std::endl;

                  }
            }

      };
}

#endif
