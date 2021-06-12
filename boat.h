#ifndef BOAT_H
#define BOAT_H

#include<iostream>

class Boat : public Veicolo
{
private:
	
	std::string marca;
	int cavalli;
	Boat *left,*right,*parent;
	
public:
		
	
	~Boat(){}

	Boat(std::string marca, int cavalli) : Veicolo(marca,cavalli){}
	
	Boat* getLeft()
	{
		return left;
	}
	
	Boat* getRight()
	{
		return right;
	}
	
	Boat* getParent()
	{
		return parent;
	}
	
	void setLeft(Boat* left)
	{
		this->left = left;
	}
	
	void setRight(Boat* right)
	{
		this->right = right;
	}
	
	void setParent(Boat* parent)
	{
		this->parent = parent;
	}
};

std::ostream& operator<<(std::ostream& os, const Boat& b)
{
	os << "Barca di marca " << b.getMarca() << " con " << b.getCavalli() << "kw/h\n";
	return os;
}


#endif
