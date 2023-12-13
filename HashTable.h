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
    int i = 0;
    do{
      i++;
    }while(key != table[i].key);
    return i;
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
    out << "List => [" << th << "]";
    return out;
  }
  
  V operator[](std::string key){
    int i = 0;
    V val;
    do{
      if(table[i].key == key){
	val = table.data.value;
      }
      table = table->next;
    }while(table != nullptr);
    return val;
  }
  
  void insert(std::string key, V value)override{
    ListLinked<TableEntry<V>> *aux = table, *prevAux = table;
    
    int i = 0;
    do{
      if(key == table[i].key){
	throw std::runtime_error("No existe esa clave");
      }
      i++;
      //aux = aux->next;
      //prevAux = prevAux->next;
    }while(table->next != nullptr);
    prevAux = new ListLinked<TableEntry<V>>((key, value), aux->next);    
  }
  
  V search(std::string key)override{
   
    throw std::runtime_error("La clave no existe en la tabla");
  }
  
  V remove(std::string key)override{
    throw std::runtime_error("La clave no existe en la tabla");
    
  }
  
  int entries()override{
    return n;
  }
};
