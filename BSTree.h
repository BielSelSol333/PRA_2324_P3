#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T> class BSTree{
 private:
  int nelem;
  BSNode<T> *root;

  BSNode<T>* search(BSNode<T>* n, T e) const{
     if(n  == nullptr){
       throw std::runtime_error("El elemento no se encuentra en el arbol");
     }else if(e > n->elem && n->right != nullptr){
       search(n->right, e);
     }else if(e < n->elem && n->left != nullptr){
       search(n->left, e);
     }else{
       return n;
     }
  }

  BSNode<T>* insert(BSNode<T>* n, T e){
    if(n == nullptr){
      return new BSNode(e);
    }else if(e == n->elem){
      throw std::runtime_error("El elemento ya existe en el arbol");
    }else if(e > n->elem){
      n->right = insert(n->right, e);
    }else{
      n->left = insert(n->left, e);
    }
    return n;
  }

  void print_inorder(std::ostream &out, BSNode<T>* n) const{
    if(n != nullptr){
      print_inorder(out, n->left);
      out << n->elem << " ";
      print_inorder(out, n->right);
    }    
  }

   BSNode<T>* remove(BSNode<T>* n, T e){
     BSNode<T>* aux = n;
     if(n == nullptr){
       throw std::runtime_error("El árbol está vacio");
     }else if(e > aux->elem && aux->right != nullptr){
       aux = n;
       aux->right = remove(aux->right, e);
     }else if(e < aux->elem && aux->left != nullptr){
       aux = n;
       aux->left = remove(aux->left, e);
     }else{
       
     }
     return n;
   }

   T max(BSNode<T>* n) const{
     if(n == nullptr){
       throw std::runtime_error("No hay elementos en el árbol");
     }else if(n->right != nullptr){
       return max(n->right);
     }else{
       return n->elem;
     }
   }

   BSNode<T>* remove_max(BSNode<T>* n){
      if(n->right == nullptr){
       return n->left;
     }else{
       n->right = remove_max(n->right);
       return n;
     }
   }

   void delete_cascade(BSNode<T>* n){
     if(n != nullptr){
       BSNode<T> *aux = n;
       delete_cascade(n->left);
       delete_cascade(n->right);
       delete aux;
     }
   }
   
 public:
  BSTree(){
    nelem = 0;
    root = nullptr;
  }
  
  int size() const{
    return nelem;
  }

  T search(T e) const{
    return search(root, e)->elem;
  }

  T operator[](T e) const{
    return search(e);
  }

  void insert(T e){
    root = insert(root, e);
    nelem++;
  }

  friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst){
    bst.print_inorder(out, bst.root);
    return out;
  }

  void remove(T e){
    root = remove(root, e);
    nelem--;
  }

  ~BSTree(){
    delete_cascade(root);
  }
};
