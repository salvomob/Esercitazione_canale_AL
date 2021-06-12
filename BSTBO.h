#ifndef BSTBO_H
#define BSTBO_H



template <class T> class BSTBO{

private:
	int n;
	Boat *root;
	
	
	Boat* _search(Boat* x, std::string marca,int cavalli) {
        if(!x) return NULL;
        if(x->getCavalli()==cavalli && x->getMarca() == marca) return x;
        if(cavalli <= x->getCavalli())
            return _search(x->getLeft(), marca , cavalli);
        else return _search(x->getRight(), marca , cavalli);
    }
    
    Boat* _imin(Boat* x){
		if(!x) return NULL;
		Boat *tmp = x;
		while(tmp->getLeft())	tmp= tmp->getLeft();
		return tmp;
	}
    
    Boat* _min(Boat* x) {
        if(!x) return NULL;
        if(!x->getLeft()) return x;
        return _min(x->getLeft());
    }
    
    Boat* _imax(Boat* x){
		if(!x) return NULL;
		Boat *tmp = x;
		while(tmp->getRight())	tmp= tmp->getRight();
		return tmp;
	}
    
   	Boat* _max(Boat* x){
        if(!x) return NULL;
        if(!x->getRight()) return x;
        return _max(x->getRight());
    }
    
  	Boat* _successore(Boat* x) {
        if(!x) return NULL;
        if(x->getRight())
            return _min(x->getRight());
        Boat* p = x->getParent();
        while(p && p->getRight()==x) {
            x = p;
            p = p->getParent();
        }
        return p;
    }
    
    Boat* _predecessore(Boat* x) {
        if(!x) return NULL;
        if(x->getLeft())
            return _max(x->getLeft());
        Boat* p = x->getParent();
        while(p && p->getLeft()==x) {
            x = p;
            p = p->getParent();
        }
        return p;
    }
    
    void _inorder(Boat* x,std::ostream& out) {
        if(!x) return;
        _inorder(x->getLeft(),out);
        out << x->getCavalli() << " " << x->getMarca() << "\n";
        _inorder(x->getRight(),out);
    }
    
    void _preorder(Boat* x,std::ostream& out) {
        if(!x) return;
        out << x->getCavalli() << " " << x->getMarca() << "\n";
        _preorder(x->getLeft(),out);
        _preorder(x->getRight(),out);
    }
    
    void _postorder(Boat* x,std::ostream& out){
        if(!x) return;
        _postorder(x->getLeft(),out);
        _postorder(x->getRight(),out);
        out << x->getCavalli() << " " << x->getMarca() << "\n";
    }

public:
	BSTBO()
	{
		n = 0;
		root = NULL;
	}
	
	BSTBO<T>& ins(std::string marca, int cavalli)
	{
		Boat* c = new Boat(marca,cavalli);
		Boat* tmp = root;
        Boat* p = NULL;
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
	
	BSTBO<T>& canc(std::string marca, int cavalli) {
        Boat *x = _search(root, marca, cavalli);
        if(!x) return *this;
        if(x->getLeft() && x->getRight()) {
            //caso 3
            Boat *y = _successore(x);
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
        Boat* z = x->getLeft();
        if(!z) z = x->getRight();
        Boat *p = x->getParent();
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
    
    
    BSTBO<T>& cancLessThen(int cavalli)
    {
    	Boat* tmp = _min(root);
    	Boat* tmp1 = NULL;
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
