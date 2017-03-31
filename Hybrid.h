#if !defined (HYBRID_H)
#define HYBRID_H

#include "QueueLinked.h"
using CSC2110::QueueLinked;
#include "SortedListDoublyLinked.h"

template < class T >
class Hybrid
{

   private:
      QueueLinked<T>* q;
      SortedListDoublyLinked<T>* sldl;

   public:
      Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item));
      ~Hybrid();

      bool isEmpty();
      void enqueue(T* item);
      T* dequeue();
      ListDoublyLinkedIterator<T>* iterator();

};

template < class T >
Hybrid<T>::Hybrid(int (*comp_items) (T* item_1, T* item_2), int (*comp_keys) (String* key, T* item))
{
   q = new QueueLinked<T>();
   sldl = new SortedListDoublyLinked<T>(comp_items, comp_keys);
}

template < class T >
Hybrid<T>::~Hybrid()
{
   delete q;
   delete sldl;
}

//DO THIS
//complete the implementation for the Hybrid ADT in two different ways
//as outlined in the Lab 10 description
//simply comment the first implementation out when working on the second implementation
//use the getKey method to dequeue/remove

template <class T>
bool Hybrid<T>::isEmpty()
{
	if (q->isEmpty() == true)
	{
		return true;
	}
	if (sldl->isEmpty() == true)
	{
		return true;
	}
}

template <class T>
void Hybrid<T>::enqueue(T* item)
{
	/*DoubleNode<T>* dn = new DoubleNode<T>();
	
	dn = sldl->addDN(item);
	
	q->enqueue(dn);

	delete dn;*/
	if(item == NULL) return;
	q->enqueue(item);
	sldl->add(item);
	
}
template <class T>
T* Hybrid<T>::dequeue()
{
	//DoubleNode<T>* ref = new DoubleNode<T>(q->dequeue());
	if(q->isEmpty())
		return NULL;
	T* item = q->dequeue();
	sldl->remove(item->getKey());
	
	return item;
	
}
template <class T>
ListDoublyLinkedIterator<T>* Hybrid<T>::iterator()
{
	sldl->iterator();
}

#endif
