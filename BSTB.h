#ifndef BSTB_H
#define BSTB_H



template <class T> class BSTB{

private:
	int n;
	Bike *root;
	
	
	Bike* _search(Bike* x, std::string marca,int cavalli) {
        if(!x) return NULL;
        if(x->getCavalli()==cavalli && x->getMarca() == marca) return x;
        if(cavalli <= x->getCavalli())
            return _search(x->getLeft(), marca , cavalli);
        else return _search(x->getRight(), marca , cavalli);
    }
    
    Bike* _imin(Bike* x){
		if(!x) return NULL;
		Bike *tmp = x;
		while(tmp->getLeft())	tmp= tmp->getLeft();
		return tmp;
	}
    
    Bike* _min(Bike* x) {
        if(!x) return NULL;
        if(!x->getLeft()) return x;
        return _min(x->getLeft());
    }
    
    Bike* _imax(Bike* x){
		if(!x) return NULL;
		Bike *tmp = x;
		while(tmp->getRight())	tmp= tmp->getRight();
		return tmp;
	}
    
   	Bike* _max(Bike* x){
        if(!x) return NULL;
        if(!x->getRight()) return x;
        return _max(x->getRight());
    }
    
  	Bike* _successore(Bike* x) {
        if(!x) return NULL;
        if(x->getRight())
            return _min(x->getRight());
        Bike* p = x->getParent();
        while(p && p->getRight()==x) {
            x = p;
            p = p->getParent();
        }
        return p;
    }
    
    Bike* _predecessore(Bike* x) {
        if(!x) return NULL;
        if(x->getLeft())
            return _max(x->getLeft());
        Bike* p = x->getParent();
        while(p && p->getLeft()==x) {
            x = p;
            p = p->getParent();
        }
        return p;
    }
    
    void _inorder(Bike* x,std::ostream& out) {
        if(!x) return;
        _inorder(x->getLeft(),out);
        out << x->getCavalli() << " " << x->getMarca() << "\n";
        _inorder(x->getRight(),out);
    }
    
    void _preorder(Bike* x,std::ostream& out) {
        if(!x) return;
        out << x->getCavalli() << " " << x->getMarca() << "\n";
        _preorder(x->getLeft(),out);
        _preorder(x->getRight(),out);
    }
    
    void _postorder(Bike* x,std::ostream& out){
        if(!x) return;
        _postorder(x->getLeft(),out);
        _postorder(x->getRight(),out);
        out << x->getCavalli() << " " << x->getMarca() << "\n";
    }

public:
	BSTB()
	{
		n = 0;
		root = NULL;
	}
	
	BSTB<T>& ins(std::string marca, int cavalli)
	{
		Bike* c = new Bike(marca,cavalli);
		Bike* tmp = root;
        Bike* p = NULL;
        while(tmp) {
            p = tmp;
            if(c->getCavalli() <= tmp->getCavalli()) tmp = tmp->getLeft();
            else tmp = tmp->getRight();
        }
        if(!p) root = c;
        else {
            c->setParent(p);
            if(c->getCavalli() <= p->getCavalli())
                p->setLeft(c);
            else p->setRight(c);
        }
        n++;
        return *this;
	}
	
	BSTB<T>& canc(std::string marca, int cavalli) {
        Bike *x = _search(root, marca, cavalli);
        if(!x) return *this;
        if(x->getLeft() && x->getRight()) {
            //caso 3
            Bike *y = _successore(x);
            //cout << x->getKey() << endl;
            //cout << y->getKey() << endl;
            int v = x->getCavalli();
            std::string v1 = x->getMarca();
            x->setCavalli(y->getCavalli());
            y->setCavalli(v);
            x->setMarca(y->getMarca());
            y->setMarca(v1);
            //cout << x->getKey() << endl;
            //cout << y->getKey() << endl;
            x = y;
        }
        //casi 1 e 2
        Bike* z = x->getLeft();
        if(!z) z = x->getRight();
        Bike *p = x->getParent();
        if(!p) root = z;
        else {
            if(p->getLeft()==x)
                p->setLeft(z);
            else p->setRight(z);
        }
        if(z) z->setParent(p);
        n--;
        return *this;
    }
    
    
    BSTB<T>& cancLessThen(int cavalli)
    {
    	Bike* tmp = _min(root);
    	Bike* tmp1 = NULL;
    	while(tmp->getCavalli() < cavalli)
    	{
    		tmp1 = tmp;
    		this->canc(tmp1->getMarca(),tmp1->getCavalli());
			tmp = _successore(tmp);
    	}
    	return *this;
    }
	
	void inorder(std::ostream& out)
	{
		_inorder(root,out);
	}

};

#endif
