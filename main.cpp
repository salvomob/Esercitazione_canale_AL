#include "veicolo.h"
#include "list.h"
#include "car.h"
#include "boat.h"
#include "queue.h"
#include "bike.h"
#include "stack.h"
#include "BSTC.h"
#include "BSTB.h"
#include "BSTBO.h"

#include<iostream>
#include<fstream>


using namespace std;

int main()
{
	
	// LIST TO BSTC
	
	/*List<Car> *list = new List<Car>();
	Car *v,*v1,*v2,*v3,*v4,*v5,*v6,*v7,*v8,*v9,*v10;
	v = new Car("maserati",1000);
	v1 = new Car("ferrari",1200);
	v2 = new Car("porsche", 2000);
	v3 = new Car("fiat", 700);
	v4 = new Car("audi",1300);
	v5 = new Car("alfa",1400);
	v6 = new Car("opel", 2100);
	v7 = new Car("kia", 1700);
	v8 = new Car("smart",500);
	v9 = new Car("renault",200);
	v10 = new Car("peugeot", 2200);
	list->ins(v).ins(v1).ins(v2).ins(v3).ins(v4).ins(v5).ins(v6).ins(v7).ins(v8).ins(v9).ins(v10);
	Car ** allc = list->extract();
	BSTC<Car> *mbare = new BSTC<Car>();
	for(int i = 0; i < list->size(); i++)
	{
		mbare->ins(allc[i]->getMarca(), allc[i]->getCavalli());
	}
	mbare->inorder(cout);
	mbare->cancLessThen(1200);
	cout << "\n\n\n\n\n";
	mbare->inorder(cout);
	cout << "\n\n\n\n\n";*/
	
	//QUEUE TO BSTBO
	
	/*Queue<Boat> *q = new Queue<Boat>();
	Queue<Boat> q1;
	Boat *b1,*b2,*b3,*b4;
	
	b1 = new Boat("non so",1000);
	b2 = new Boat("non saprei",1200);
	b3 = new Boat("non so di sicuro",1100);
	b4 = new Boat("non so",900);
	q->enqueue(b1).enqueue(b2).enqueue(b3).enqueue(b4);
	Boat ** allbo = q->extract();
	BSTBO<Boat> *mbare2 = new BSTBO<Boat>();
	for(int i = 0; i < q->size(); i++)
	{
		mbare2->ins(allbo[i]->getMarca(), allbo[i]->getCavalli());
	}
	mbare2->inorder(cout);
	mbare2->cancLessThen(1100);
	cout << "\n\n\n\n\n";
	mbare2->inorder(cout);
	cout << "\n\n\n\n\n";
	*/
	
	// STACK TO BSTB
	
	/*Stack<Bike> *s = new Stack<Bike>();
	Bike *m1,*m2,*m3,*m4;
	m1 = new Bike("Ducati" ,1200);
	m2 = new Bike("Honda" ,1300);
	m3 = new Bike("Yamaha" ,1100);
	m4 = new Bike("Harley" ,1800);
	s->push(m1).push(m2).push(m3).push(m4);
	Bike ** allb = s->extract();		
	BSTB<Bike> *mbare3 = new BSTB<Bike>();
	for(int i = 0; i< s->size() ; i++)
	{
		mbare3->ins(allb[i]->getMarca(), allb[i]->getCavalli());
	}
	
	mbare3->inorder(cout);
	mbare3->cancLessThen(1300);
	cout << "\n\n\n\n\n";
	mbare3->inorder(cout);*/
	List<Car> *l = new List<Car>();
	Stack<Bike> *s = new Stack<Bike>();
	Queue<Boat> *q = new Queue<Boat>();
	string line;
	cout << "Quanti oggetti di tipo CAR vuoi creare?\n";
	int n;
	cin>>n;
	for(int i = 0; i < n; i++)
	{
		cout << "Marca: ";
		string tmp;
		cin>>tmp;
		cout << "Cavalli: ";
		int tmp1;
		cin>>tmp1;
		Car *c = new Car(tmp,tmp1);
		l->ins(c);
	}
	cout << "Quanti oggetti di tipo BIKE vuoi creare?\n";
	int n2;
	cin>>n2;		
	for(int i= 0; i<n2; i++)
	{
		cout << "Marca: ";
		string tmp;
		cin>>tmp;
		cout << "Cavalli: ";
		int tmp1;
		cin>>tmp1;
		Bike *b = new Bike(tmp,tmp1);
		s->push(b);
	}
	cout << "Quanti oggetti di tipo BOAT vuoi creare?\n";
	int n3;
	cin>>n3;		
	for(int i= 0; i<n3; i++)		
	{
		cout << "Marca: ";
		string tmp;
		cin>>tmp;
		cout << "Cavalli: ";
		int tmp1;
		cin>>tmp1;
		Boat *bo = new Boat(tmp,tmp1);
		q->enqueue(bo);
	}

	BSTC<Car> *bst1 = new BSTC<Car>();
	BSTB<Bike> *bst2 = new BSTB<Bike>();
	BSTBO<Boat> *bst3 = new BSTBO<Boat>();
	
	// CAR FROM LIST TO BST
	Car ** allc = l->extract();
	for(int i = 0; i < l->size(); i++)
	{
		bst1->ins(allc[i]->getMarca(), allc[i]->getCavalli());
	}
	
	// BIKE FROM STACK TO BST
	Bike ** allb = s->extract();		
	for(int i = 0; i< s->size() ; i++)
	{
		bst2->ins(allb[i]->getMarca(), allb[i]->getCavalli());
	}
	
	// BOAT FROM QUEUE TO BST
	Boat ** allbo = q->extract();
	for(int i = 0; i < q->size(); i++)
	{
		bst3->ins(allbo[i]->getMarca(), allbo[i]->getCavalli());
	}
	
	cout << "\n\nCreazione avvenuta con successo seguita da inserimento in strutture adeguate\n\n";
	cout << "\n\nEcco come appare la visita inorder del BST di oggetti CAR :\n\n";
	bst1->inorder(cout);
	cout << "\n\nEcco come appare la visita inorder del BIKE di oggetti CAR :\n\n";
	bst2->inorder(cout);
	cout << "\n\nEcco come appare la visita inorder del BOAT di oggetti CAR :\n\n";
	bst3->inorder(cout);
	cout << "Vuoi eliminare oggetti dal BST di CAR? Rispondi 'si' o 'no'\n";
	string answ1;
	cin>>answ1;
	if(answ1 == "si")
	{
		cout << "Sotto quale soglia eliminare?\n";
		int soglia;
		cin>>soglia;
		bst1->cancLessThen(soglia);
		cout << "\n\nEcco come appare la visita inorder del BST di oggetti BIKE :\n\n";
		bst1->inorder(cout);
	}
	else if(answ1 =="no")
	{
		cout << "Non verranno eliminati elementi dal BST di CAR\n\n";				
	}
	else
	{
		cout << "Scelta non contemplata , non verranno eliminati elementi dal BST di CAR\n";
	}	
	
	string answ2;
	cout << "Vuoi eliminare oggetti dal BST di BIKE? Rispondi 'si' o 'no'\n";
	cin>>answ2;
	if(answ2 == "si")
	{
		cout << "Sotto quale soglia eliminare?\n";
		int soglia;
		cin>>soglia;
		bst2->cancLessThen(soglia);
	    cout << "\n\nEcco come appare la visita inorder del BST di oggetti BIKE :\n\n";
		bst2->inorder(cout);
	}
	else if(answ2 =="no")
	{
		cout << "Non verranno eliminati elementi dal BST di BIKE\n\n";				
	}
	else
	{
		cout << "Scelta non contemplata ,  non verranno eliminati elementi dal BST di BIKE \n";
	}
	
	
	string answ3;
	cout << "Vuoi eliminare oggetti dal BST di BOAT? Rispondi 'si' o 'no'\n";
	cin>>answ3;
	if(answ3 == "si")
	{
		cout << "Sotto quale soglia eliminare?\n";
		int soglia;
		cin>>soglia;
		bst3->cancLessThen(soglia);
		cout << "\n\nEcco come appare la visita inorder del BST di oggetti BOAT :\n\n";
		bst3->inorder(cout);
	}
	else if(answ3 =="no")
	{
		cout << "Non verranno eliminati elementi dal BST di BOAT\n\n";				
	}
	else
	{
		cout << "Scelta non contemplata, non verranno eliminati elementi dal BST di BOAT\n";
	}
	
	cout << "Operazioni concluse! Vuoi salvare i valori dei tre BST generati? 'si' o 'no'\n";
	string save;
	cin>>save;
	if(save == "si")
	{
		ofstream out("save.txt");
		out << "Visita inorder BST di Car:\n";
		bst1->inorder(out);
		out << "Visita inorder BST di Bike:\n";
		bst2->inorder(out);
		out << "Visita inorder BST di Boat:\n";
		bst3->inorder(out);
		cout << "Salvataggio avvenuto in save.txt\n";
		cout << "Arrivederci\n";
		return 0;
	}
	
	else
	{
		cout << "Nessun salvataggio avvenutoo, Arrivederci!\n";
	}
}
