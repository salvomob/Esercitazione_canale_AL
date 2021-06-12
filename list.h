#ifndef LIST_H
#define LIST_H

#include "car.h"

template <class T> class List{

private:
	int n;//numero elementi inseriti
	Car *head, *tail, *current;
		
	Car* _ricerca(std::string marca, int cavalli)
	{
		Car* tmp = head;
		while(tmp && tmp->getCavalli() != cavalli && tmp->getMarca()!= marca) tmp = tmp->getRight();
		if(tmp->getCavalli() == cavalli && tmp->getMarca()== marca) return tmp;
		return NULL;
	}

public:
		
	List()
	{
		n = 0;
		head = tail = current = NULL;
	}
	
	List<T>& ins(Car* x)
	{
		Car *tmp = head;
		while(tmp && tmp->getCavalli() < x->getCavalli())
		{
			tmp = tmp->getRight();
		}
		n++;
		x->setRight(tmp);
		if(head==NULL){//lista vuota
			x->setLeft(NULL);
			head = tail = x;
			return *this;	
		}
		if(tmp!=NULL){
			// Head ->      <-[tmp]
			//        <-[x]->
			x->setLeft(tmp->getLeft());
			if(head==tmp) head = x;	//inserimento in testa	
			else tmp->getLeft()->setRight(x);
			tmp->setLeft(x);
		}
		else{//tmp == NULL -> inserimento in coda
			tail->setRight(x);
			x->setLeft(tail);
			tail=x;
		}				
		return *this;
	}
	
	List<T>& canc(Car *v)
	{
		int cavalli = v->getCavalli();
		std::string marca = v->getMarca();
		Car *x = _ricerca(marca,cavalli);
		if(x!=NULL){
			Car *y = x->getLeft();
			Car *z = x->getRight();
			if(y) y->setRight(z);
			else head = z;
			if(z) z->setLeft(y);
			else tail = y;
			n--;
			//delete x;
			delete v;
		}	
		return *this;
	}
	
	int ricerca(std::string marca, int cavalli)
	{
		return (_ricerca(marca,cavalli)!=NULL);
	}
	
	int size()
	{
		return n;
	}
	
	int isEmpty()
	{
		return (n==0);
	}
	
	//iteratore
	
	void reset()
	{
		current = head;
	}
	
	int hasNext()const
	{
		return (current!= NULL); 
	}
	
	Car* next()
	{
		if(hasNext())
		{
			Car *tmp = new Car(current->getMarca() , current->getCavalli());
			current = current->getRight();
			return tmp;
		}
		else return NULL;
		
	}
	
	Car *getHead() const
	{
		return head;
	}
	
	Car *getTail() const
	{
		return tail;
	}
	
	Car **extract()
	{
		int i = 0;
		Car **all;
		all = new Car*[this->size()];
		Car *tmp = head;
		while(tmp)
		{
			all[i] = new Car(tmp->getMarca(),tmp->getCavalli());
			tmp = tmp->getRight();
			i++;
		}
		return all;
	}
		
};

template <class T> std::ostream& operator<<(std::ostream& os, const List<T>& l)
{
/*	
	equivalenti!!! vanno bene entrambi

	List<T> tmp = l;
	tmp.reset();
	while(tmp.hasNext()){
		out << *(tmp.next()) << "\n"; 
	}
	return out;*/
	
	Car *tmp = l.getHead();
	while(tmp )
	{
		os << *tmp << "\n";
		tmp = tmp->getRight();
	}
	
	return os;
}

#endif
