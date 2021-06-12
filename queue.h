#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>

template <class T> class Queue{
private:
    int n, len, current, iterations;
    int head, tail;
    Boat** q;
    
public:
    Queue() {
        n = 0;
        len = 100; // lunghezza di default del vettore
        q = new Boat*[len];
        head = 0;
        tail = 0;
        iterations = 0;
    }
    Queue(int len) {
        n = 0;
        this->len = len;
        q = new Boat*[len];
        head = 0;
        tail = 0;
        iterations = 0;
    }

    Queue<T>& enqueue(Boat *b) { //O(1)
        if(n<len) {
            q[tail] = b;
            tail++;
            if(tail==len) tail = 0;
            // tail = (tail+1)%len;
            n++;
        }
        return *this;
    }
    
    Boat* dequeue() {  //O(1)
        if(n>0) {
            Boat* tmp = q[head];
            head++;
            if(head==len) head=0;
            n--;
            return tmp;
        }
        return NULL;
    }

	int size()
	{
		return n;
	}

    int isEmpty() {
        return (n==0);
    }
    
    //iteratore
    void reset() {
        current = head;
        iterations = 0;
    }
    
    int hasNext() {
        return (iterations < n);
    }
    
    Boat* next() {
        if(hasNext()) {
            Boat* tmp = q[current];
            current++;
            if(current==len) current=0;
            iterations++;
            return tmp;
        }
        return NULL;
    }
    
    Boat ** extract()
    {
    	return this->q;
    }
    
};

template <class H> std::ostream& operator<< ( std::ostream& os , const Queue<H>&q){
		Queue<H> tmp = q;
		tmp.reset();
		while(tmp.hasNext()){
			
			os << *tmp.next()  ; 		
		}
		return os;
	}

#endif
