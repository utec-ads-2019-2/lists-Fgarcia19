#ifndef LINKED_H
#define LINKED_H

#include "list.h"
#include "bidirectional_iterator.h"

template <typename T>
class LinkedList : public List<T> {
    public:
    LinkedList() : List<T>() {}

    void imprimir_inverso(){
        auto aux=this->tail;
        if(this->head!=this->tail) {
            do {
                cout << aux->data << " ";
                aux = aux->prev;
            } while (aux != this->head);
            cout << aux->data;
        }
        else
            cout<<aux->data;
    }

    void imprimir() {
        auto aux = this->head;
        while (aux != nullptr) {
            cout << aux->data << " ";
            aux = aux->next;
        }
    }

    T front() {
        if(this->head!= nullptr)
            return this->head->data;
        else
            throw exception();

    }

    T back() {

        if(this->tail!=nullptr)
            return this->tail->data;
        else
            throw exception();
    }

    void push_front(T value) {
        auto nuevo=new Node<T>;
        nuevo->data=value;
        if(empty())
        {
            this->head=nuevo;
            this->tail=nuevo;
            nuevo->next= nullptr;
        }
        else{
            nuevo->next=this->head;
            this->head->prev=nuevo;
            this->head=nuevo;
        }
        this->nodes++;
    }

    void push_back(T value) {
        auto nuevo=new Node<T>;
        nuevo->data=value;
        if(empty())
        {
            this->head=nuevo;
            this->tail=nuevo;
            nuevo->next= nullptr;
        }
        else{
            this->tail->next=nuevo;
            nuevo->prev=this->tail;
            this->tail=nuevo;
        }
        this->nodes++;
    }

    void pop_front() {
        if(!empty())
        {
            auto temp = this->head;
            if(size()>1)
            {

                this->head = this->head->next;
                delete temp;
            }
            else if(size()==1)
            {
                this->head= nullptr;
                this->tail= nullptr;
                delete temp;
            }

            this->nodes--;
        }
        else
            throw exception();
    }

    void pop_back() {
        if(!empty())
        {
            auto temp=this->tail;
            if(size()>1)
            {
                this->tail=this->tail->prev;
                this->tail->next= nullptr;
                delete temp;
            }
            else{
                this->head= nullptr;
                this->tail= nullptr;
                delete temp;
            }
            this->nodes--;
        }
        else
            throw exception();

    }

    T operator[](int index) {
        if(index!=size()){
            auto aux=this->head;
            for(int i=0;i<index;i++)
                aux=aux->next;
            return aux->data;
        }
        else throw exception();
    }

    bool empty() {
        if(size()==0)
            return true;
        else
            return false;
    }

    int size() {
        return this->nodes;
        // TODO
    }

    void clear() {
        while(!empty()){
            pop_back();
        }
    }

    void sort() {
        bool desordenado = true;
        while (desordenado) {
            desordenado=false;
            for (auto i=this->head; i->next != nullptr; i=i->next) {\
                    if (i->data > i->next->data) {
                    auto valor=i->data;
                    i->data=i->next->data;
                    i->next->data=valor;
                    desordenado=true;
                }
            }
        }
    }

    void swap(Node<T>* nodo){
        auto aux=nodo->next;
        nodo->next=nodo->prev;
        nodo->prev=aux;
    }

    void reverse() {
        auto aux=this->tail->prev;
        while(aux!=this->head)
        {
            auto temp=aux->prev;
            swap(aux);
            aux=temp;
        }
        this->head->prev=this->head->next;
        this->head->next= nullptr;
        this->tail->next=this->tail->prev;
        auto temp=this->tail;
        this->tail=this->head;
        this->head=temp;
    }

    string name() {
        return "Linked List";
    }

    BidirectionalIterator<T> begin() {
        auto aux= BidirectionalIterator<T>(this->head);
        return aux;
    }

    BidirectionalIterator<T> end() {
        auto aux= BidirectionalIterator<T>(nullptr);
        return aux;
    }

    void merge(LinkedList<T> list) {
        auto aux=list.head;
        while(aux!=nullptr){
            push_back(aux->data);
            aux=aux->next;
        }
    }
};

#endif