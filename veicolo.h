#ifndef VEICOLO_H
#define VEICOLO_H

#include <string>
#include<iostream>

class Veicolo
{
private:
	std::string marca;
	int cavalli;
	Veicolo *left,*right,*parent;

public:
	
	Veicolo(std::string marca,int cavalli)
	{
		this->marca = marca;
		this->cavalli = cavalli;
		left = right = parent = NULL;
	}	
	
	//metodi set
	
	void setLeft(Veicolo* left)
	{
		this->left = left;
	}
	
	void setRight(Veicolo* right)
	{
		this->right = right;
	}
	
	void setParent(Veicolo* parent)
	{
		this->parent = parent;
	}
	
	void setMarca(std::string marca)
	{
		this->marca = marca;
	}
	
	void setCavalli(int cavalli)
	{
		this->cavalli = cavalli;
	}
	
	
	//metodi get
	
	std::string getMarca() const
	{
		return marca;
	}
	
	int getCavalli() const
	{
		return cavalli;
	}
	
	Veicolo* getLeft()
	{
		return left;
	}
	
	Veicolo* getRight()
	{
		return right;
	}
	
	Veicolo* getParent()
	{
		return parent;
	}
	
};

std::ostream& operator<<(std::ostream& os, const Veicolo& c)
{
	os << "Macchina di marca " << c.getMarca() << " con " << c.getCavalli() << "cc\n";
	return os;
}

#endif
