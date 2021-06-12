#ifndef BIKE_H
#define BIKE_H

class Bike : public Veicolo
{
private:
	
	std::string marca;
	int cavalli;
	Bike *left,*right,*parent;
	
public:
		
	Bike(std::string marca, int cavalli) : Veicolo(marca,cavalli)	{}
	
	Bike* getLeft()
	{
		return left;
	}
	
	Bike* getRight()
	{
		return right;
	}
	
	Bike* getParent()
	{
		return parent;
	}
	
	void setLeft(Bike* left)
	{
		this->left = left;
	}
	
	void setRight(Bike* right)
	{
		this->right = right;
	}
	
	void setParent(Bike* parent)
	{
		this->parent = parent;
	}
};

std::ostream& operator<<(std::ostream& os, const Bike& c)
{
	os << "Motocicletta di marca " << c.getMarca() << " con " << c.getCavalli() << "cc\n";
	return os;
}


#endif
