// main.cpp

//Referencias: PDFs disponibilizados no moodle, e o site alphacodingskills.com

//Nomes:
//Thiago Leandro Liporace 42128481
//Lucas Goulart de Farias Meres 42127459

//Autoavaliacao:
//Thiago: Eu considero este trabalho um 10, ja que todas as operacoes funcionam como o esperado e a lista funciona sendo dupla e circular. Trabalhamos muito duro durante uma tarde inteira para finaliza-lo, apos montar algumas operacoes a mao pois nao encontravamos as respostas em nenhum local.

//Lucas: Acho que considerando todo o codigo e suas funcoes, nos merecemos uma nota entre 9.5 a 10, pois colocamos bastante esforco em fazer todas as funcoes funcionarem como o desejado e o esperado delas. Abracos prof sz.
#include <iostream>
#include "LinkedList.h"
using namespace std;
void Print(const LinkedList* lista)
{
  cout << "Lista com " << lista -> count << " elementos:\n";
  Node *aux = lista -> head;
  for (int i = 0;i < lista -> count;i++){
    cout << "[" << aux -> id << "]" << " " << aux -> nome << "\n";
    aux = aux -> next;
  }
}
void PrintReverse(const LinkedList* lista)
{
  cout << "Lista com " << lista -> count << " elementos - ordem invertida:\n";
  Node *aux = lista -> tail;
  for (int i = 0;i < lista -> count;i++){
    cout << "[" << aux -> id << "]" << " " << aux -> nome << "\n";
    aux = aux -> previous;
  }
}
void PrintDoubleListInfo(const LinkedList* lista)
{
 if (IsEmpty(lista))
 {
 cout << "Lista vazia!\n";
 }
 else
 {
 Print(lista);
 PrintReverse(lista);
 }
}
int main()
{
 cout << "*** Lista Circular Duplamente Ligada/Encadeada (Doubly Circular Linked List) ***\n";
 LinkedList* lista = Create();
 PrintDoubleListInfo(lista);
 Insert(lista, 1, "Carol");
 Insert(lista, 2, "Eric");
 Insert(lista, 3, "John");
 Append(lista, 4, "Leo");
 Append(lista, 5, "Julia");
 Append(lista, 6, "Lisa");
 PrintDoubleListInfo(lista);
 Clear(lista);
 PrintDoubleListInfo(lista);
 Insert(lista, 11, "Paulo");
 Append(lista, 22, "Thomas");
 Insert(lista, 33, "Olga");
 Append(lista, 44, "Bia");
 Insert(lista, 55, "Angela");
 Append(lista, 66, "Karen");
 Insert(lista, 77, "Adauto");
 PrintDoubleListInfo(lista);
 Node* temp = RemoveNode(lista, 44);
 cout << "Nó removido -> id: " << temp->id << ", name: " << temp->nome << '\n';
 delete temp;
 PrintDoubleListInfo(lista);
 temp = RemoveHead(lista);
 cout << "Nó removido -> id: " << temp->id << ", name: " << temp->nome << '\n';
 delete temp;
 PrintDoubleListInfo(lista);
 temp = RemoveTail(lista);
 cout << "Nó removido -> id: " << temp->id << ", name: " << temp->nome << '\n';
 delete temp;
 PrintDoubleListInfo(lista);
 temp = GetHead(lista); 
 cout << "Nome e id do primeiro nodo da lista:\n" << "[" << temp -> id << "]" << " " <<     temp -> nome << "\n"; 
 temp = GetTail(lista); 
 cout << "Nome e id do ultimo nodo da lista:\n" << "[" << temp -> id << "]" << " " <<       temp -> nome << "\n"; 
 temp = GetNode(lista,77);
 delete temp;
 cout << "Fim.\n";
}
