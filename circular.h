#ifndef CIRCULAR_H
#define CIRCULAR_H

#include "list.h"

template <typename T>
class CircularLinkedList : public List<T> {
    public:
        CircularLinkedList() : List<T>() {}

        T front() {
            if(!empty())
                return this->head->data;
            else throw exception();
        }

        T back() {
            if(!empty())
                return this->head->prev->data;
            throw exception();
        }

        void push_front(T value) {
            // TODO
        }

        void push_back(T value) {
            auto nuevo=new Node<T>();
            nuevo->data=value;

            if(this->head!=nullptr)
            {
                nuevo->next=this->head;
                this->head->prev->next=nuevo;
                nuevo->prev=this->head->prev;
                this->head->prev=nuevo;

            }
            else{
                nuevo->next=this->head;
                this->head=nuevo;
                this->head->next=nuevo;
                this->head->prev=nuevo;
            }
            this->nodes++;
        }

        void pop_front() {
            if(this->head!= nullptr){
                auto temp=this->head;
                this->nodes--;
                if(this->nodes==0){
                    this->head= nullptr;
                }
                else{
                    this->head->prev->next=this->head->next;
                    this->head->next->prev=this->head->prev;
                    this->head=this->head->next;
                }
                delete temp;
            }
        }

        void pop_back() {
            if(!empty()){
                auto temp=this->head->prev;
                this->nodes--;
                    this->head->prev->prev->next=this->head;
                    this->head->prev=this->head->prev->prev;
                delete temp;
            }
            else
                this->head= nullptr;
                this->tail= nullptr;
        }

        T operator[](int index) {
            auto aux=this->head;
            for(int i=0;i<index;i++)
                aux=aux->next;
            return aux->data;
        }

        bool empty() {
            if(size()==0){
                return true;
            }
            else
                return false;
        }

        int size() {
            return this->nodes;
        }

        void clear() {
            while(!empty())
                pop_front();
        }

        void sort() {
            bool desordenado = true;
            while (desordenado) {
                desordenado = false;
                for (auto i = this->head; i->next != this->head; i = i->next) {
                    if (i->data > i->next->data) {
                        auto valor = i->data;
                        i->data = i->next->data;
                        i->next->data = valor;
                        desordenado = true;
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
            auto aux=this->head;
            for(auto i=0;i<this->size();i++) {
                swap(aux);
                aux=aux->next;
            }
            this->head=this->head->next;
        }

        string name() {
            return "Circular Linked List";
        }

        BidirectionalIterator<T> begin() {
            auto aux= BidirectionalIterator<T>(this->head);
            return aux;
        }

	    BidirectionalIterator<T> end() {
            auto aux= BidirectionalIterator<T>(this->head);
            return aux;
        }

        void merge(CircularLinkedList<T> list) {
            auto aux=list.head;
            for(int i=0;i<list.size();i++,aux=aux->next){
                this->push_back(aux->data);
            }
        }
};

#endif