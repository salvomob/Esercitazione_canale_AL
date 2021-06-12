#ifndef STACK_H
#define STACK_H

template <class T> class Stack{

private:
    int n, len, current;
    int top;
    Bike** s;
    
public:
    Stack() {
        n = 0;
        len = 1000; // lunghezza di default del vettore
        s = new Bike*[len];
        top = 0;
    }
    Stack(int len) {
        n = 0;
        this->len = len;
        s = new Bike*[len];
        top = 0;
    }
    
    Stack<T>& push(Bike *m) { //O(1)
        if(n<len) {
            s[top] = m;
            top++;
            n++;
        }
        return *this;
    }
    
    T* pop() {  //O(1)
        if(n>0) {
            Bike* tmp = s[top-1];
            top--;
            n--;
            return tmp;
        }
        return NULL;
    }
    
    int isEmpty() {
        return (n==0);
    }
    int size(){return n;}
    //iteratore
    void reset() {
        current = top-1;
    }
    
    int hasNext() {
        return (current >= 0);
    }
    
    Bike* next() {
        if(hasNext()) {
            T* tmp = s[current];
            current--;
            return tmp;
        }
        return NULL;
    }
    
    Bike **extract()
    {
    	return this->s;
    }
    
};

template <class T>std:: ostream& operator<<(std::ostream& os, const Stack<T>& s) {
    Stack<T> tmp = s;
    tmp.reset();
    while(tmp.hasNext()) {
        os << *(tmp.next());
    }
    return  os;
}

#endif
