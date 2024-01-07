#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"
#include "../PRA_2324_P1/ListLinked.h"

template <typename V> class HashTable : public Dict<V>{
 private:
  int n;
  int max;
  ListLinked<TableEntry<V>> *table;
  
  int h(std::string key){
    int sum_ASCII =  0;
    
    for(int i=0; i<key.size(); i++){
      sum_ASCII += (key[i] - '0');
    }
    
    return (sum_ASCII % max);     
  }

  
 public:
  HashTable(int size){
    table = new ListLinked<TableEntry<V>> [size];
    n = 0;
    max = size;
  }
  
  ~HashTable(){
    delete [] table;
    n = 0;
    max = 0;
  }
  
  int capacity(){
    return max;
  }
  
  friend std::ostream& operator<<(std::ostream &out, const HashTable<V> &th){
    out << "Hash table [Entires: " << th.n << ", Capacity: " << th.max << "]\n\n";
    for(int i=0; i<th.max; i++){
      out << "=> Bucket " << i << " <=\n\n";
      out << th.table[i] << "\n\n";
    }
    return out;
  }
  
  V operator[](std::string key){
    return search(key);
  }
  
  void insert(std::string key, V value)override{
    int bucket = h(key);
    TableEntry<V> new_p(key, value);
    bool state = false;
    
    for(int i=0; i<table[bucket].size(); i++){
      TableEntry<V> aux = table[bucket].get(i);
      if(new_p == aux){
	state = true;
      }
    }
    
    if(state == true){
      throw std::runtime_error("Ya existe esa clave");
    }else{
      table[bucket].prepend(new_p);
      n++;
    }
  }
  
  V search(std::string key)override{
    int bucket = h(key), pos;
    TableEntry<V> key_s(key);
    bool state = false;
    
    for(int i=0; i<table[bucket].size(); i++){
      TableEntry<V> aux = table[bucket].get(i);
      if(aux == key_s){
	pos = i;
	state = true;
      }
    }
    
    if(state == false){
      throw std::runtime_error("La clave no existe en la tabla");
    }else{
      return table[bucket].get(pos).value;
    }
  }
  
  V remove(std::string key)override{
    int bucket = h(key), pos;
    TableEntry<V> key_s(key);
    bool state = false;
    
    for(int i=0; i<table[bucket].size(); i++){
      TableEntry<V> aux = table[bucket].get(i);
      if(aux == key_s){
	pos = i;
	state = true;
      }
    }
    
    if(state == false){
      throw std::runtime_error("La clave no existe en la tabla");
    }else{
      n--;
      return table[bucket].remove(pos).value;
    }
  }
  
  int entries()override{
    return n;
  }
};
