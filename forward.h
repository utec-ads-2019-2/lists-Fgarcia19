#ifndef FORWARD_H
#define FORWARD_H

#include "list.h"
#include "forward_iterator.h"

template <typename T>
class ForwardList : public List<T> {
    public:
    void imprimir(){
        if(!empty()) {
            for (auto it = begin(); it != end(); ++it) {
                cout << *it << " ";
            }
        }
        else throw exception();
    }
    ForwardList() : List<T>() {}

    T front()
    {
        if(!empty())
            return this->head->data;
        else
            throw exception();
    }

    T back()
    {
        if(!empty())
            return this->tail->data;
        else
            throw exception();
    }

    void push_front(T value)
    {
        auto nuevo=new Node<T>;
        nuevo->data=value;
        if(empty())
        {
            this->head=nuevo;
            this->tail=nuevo;
            nuevo->next= nullptr;
        }
        else
        {
            nuevo->next=this->head;
            this->head=nuevo;
        }

        this->nodes++;
    }

    void push_back(T value)
    {
        auto nuevo=new Node<T>;
        nuevo->data=value;
        if(empty())
        {
            this->head=nuevo;
            this->tail=nuevo;
            nuevo->next= nullptr;
        }
        else
        {
            nuevo->next= nullptr;
            this->tail->next=nuevo;
            this->tail=nuevo;
        }

        this->nodes++;
    }

    void pop_front()
    {
        if(!empty())
        {
            auto temp = this->head;
            if(size()>1)
            {

                this->head = this->head->next;
                delete temp;
            }
            else
            {
                this->head= nullptr;
                this->tail= nullptr;
            }

            this->nodes--;
        }
        else
            throw exception();

    }

    void pop_back() {
        if(empty())
        {
            throw exception();
        }
        else{
            auto temp = this->tail;

            auto aux = this->head;
            for (int i = 1; i < size() - 1; i++)
                aux = aux->next;
            aux->next= nullptr;
            this->tail=aux;
            delete temp;
            this->nodes--;

        }


    }

    T operator[](int index) {
        if(index<size()) {
            auto aux = this->head;
            for (int i = 0; i < index; i++) {
                aux = aux->next;
            }
            return aux->data;
        }
        else throw exception();
    }

    bool empty() {
        if(this->nodes == 0){
            return true;
        }
        else {
            return false;
        }
        // TODO
    }

    int size() {
//            if(!empty())
        return this->nodes;
//            else
//                .return 0;
    }

    void clear() {
        while(!empty()){
            pop_front();
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

    void swap(int a,int b){
        auto aux1=this->head;
        auto aux2=this->head;

        for(int i=0;i<a-1;i++)
            aux1=aux1->next;
        for(int i=0;i<b-1;i++)
            aux2=aux2->next;
        aux1->next=aux2;
    }

    void reverse() {
        for(int i=size();i>1;i--){
            swap(i,i-1);
        }
        this->head->next= nullptr;
        auto temp=this->head;
        this->head=this->tail;
        this->tail=temp;

    }

    string name() {
        return "Forward List";
    }

    ForwardIterator<T> begin() {
        auto aux= ForwardIterator<T>(this->head);
        return aux;
    }

    ForwardIterator<T> end() {
        auto aux= ForwardIterator<T>(nullptr);
        return aux;
    }

    void merge(ForwardList<T> list) {
        auto aux=list.head;
        while(aux!=nullptr){
            push_back(aux->data);
            aux=aux->next;
        }
    }
};

#endif