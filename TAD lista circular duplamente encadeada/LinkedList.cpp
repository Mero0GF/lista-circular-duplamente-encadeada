#include "LinkedList.h"

LinkedList *Create(){
  LinkedList *lista = new LinkedList;
  lista -> count = 0;
  lista -> head = lista -> tail = nullptr;
  return lista;
}

bool IsEmpty(const LinkedList *lista){
  if ((lista -> head == nullptr) && (lista -> tail == nullptr)) return true;
  return false;
}

void Insert(LinkedList *lista,int id,std::string nome){
  Node *nodo = new Node;
  nodo -> id = id;
  nodo -> nome  = nome;
  if (IsEmpty(lista) == true){
    lista -> head = nodo;
    lista -> tail = nodo;
  }
  lista -> head -> previous = nodo;
  nodo -> next = lista -> head;
  lista -> head = nodo;
  lista -> count++;
  lista -> head -> previous = lista -> tail;
  lista -> tail -> next = lista -> head;
}

void Append(LinkedList *lista, int id, std::string nome){
  Node *nodo = new Node;
  nodo -> id = id;
  nodo -> nome = nome;
  if (IsEmpty(lista) == true){
    lista -> head = nodo;
    lista -> tail = nodo;
  }
  lista -> tail -> next = nodo;
  nodo -> previous = lista -> tail;
  lista -> tail = nodo;
  lista -> count++;
  lista -> head -> previous = lista -> tail;
  lista -> tail -> next = lista -> head;
}

Node* RemoveHead(LinkedList *lista){
  if (lista -> count == 0) return NULL;
  Node *toRemove = new Node;
  toRemove -> id = lista -> head -> id;
  toRemove -> nome = lista -> head -> nome;
  lista -> head -> previous -> next = nullptr;
  lista -> head -> previous = nullptr;
  lista -> head = lista -> head -> next;
  lista -> count--;
  return toRemove;
}

Node* RemoveTail(LinkedList *lista){
  if (lista -> head == lista -> tail) RemoveHead(lista);
  Node *toRemove = new Node;
  toRemove -> id = lista -> tail -> id;
  toRemove -> nome = lista -> tail -> nome;
  lista -> tail = lista -> tail -> previous;
  lista -> tail -> next -> previous = nullptr;
  lista -> tail -> next = nullptr;
  lista -> count--;
  return toRemove;
}

Node *RemoveNode(LinkedList *lista, int value){
  Node *toRemove = new Node;
  int i = lista -> count;
  toRemove = lista -> head;
  while(toRemove -> id != value){
    toRemove = toRemove -> next;
    i--;
    if (i == 0) break;
  }
  if (toRemove -> id == value){
    toRemove -> previous -> next = toRemove -> next;
    toRemove -> next -> previous = toRemove -> previous;
    toRemove -> next = nullptr;
    toRemove -> previous = nullptr;
    lista -> count--;
    return toRemove;
    }
  else {
    delete toRemove;
    return nullptr;
  }
}

void Clear(LinkedList *lista){
  Node *aux = new Node;
  while (lista -> count != 0){
    aux = lista -> head;
    lista -> head = lista -> head -> next;
    delete aux;
    lista -> count--;
  }
  lista -> tail = nullptr;
  lista -> head = nullptr;
}

void Destroy(LinkedList *lista){
  Clear(lista);
  delete lista;
}

Node *GetHead(const LinkedList *lista){
  return lista -> head;
}

Node *GetTail(const LinkedList *lista){ 
  return lista -> tail;
}

Node *GetNode(const LinkedList *lista, int value){
  Node* nodo = new Node;
  int i = lista -> count;
  nodo  = lista -> head;
  while (nodo -> id != value){
    if (nodo -> id == value){
      std::cout << "Nome e id do primeiro nodo da lista:\n" << "[" << nodo -> id << "]" << " " <<    nodo -> nome << "\n"; 
      return nodo;
      }
    nodo = nodo -> next;
    i--;
    if (i == 0) break;
  }
  std::cout << "Nao ha nodo com o id solicitado.\n";
  delete nodo;
  return nullptr;
}

int Count(const LinkedList *lista){ 
  return lista -> count;
}