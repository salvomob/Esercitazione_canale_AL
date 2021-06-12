#ifndef CAR_H
#define CAR_H

#include<iostream>

class Car : public Veicolo
{
private:
	
	std::string marca;
	int cavalli;
	Car *right,*left,*parent;

public:

	~Car(){}

	Car(std::string marca, int cavalli) : Veicolo(marca,cavalli){}
	
	Car* getLeft()
	{
		return left;
	}
	
	Car* getRight()
	{
		return right;
	}
	
	Car* getParent()
	{
		return parent;
	}
	
	void setLeft(Car* left)
	{
		this->left = left;
	}
	
	void setRight(Car* right)
	{
		this->right = right;
	}
	
	void setParent(Car* parent)
	{
		this->parent = parent;
	}
	
};

std::ostream& operator<<(std::ostream& os, const Car& c)
{
	os << "Macchina di marca " << c.getMarca() << " con " << c.getCavalli() << "cc\n";
	return os;
}

#endif


