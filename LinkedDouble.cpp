//
// Created by karen on 7/12/2021.
//

#include "LinkedDouble.h"

template<class T>
LinkedDouble<T>::LinkedDouble() {
    head = NULL;
    last = NULL;
}

template<class T>
bool LinkedDouble<T>::isEmpty() {
    return head == NULL && last == NULL;
}

template<class T>
void LinkedDouble<T>::addNodeFirst(T info) {
    NodeDouble<T> *nodeNew = new NodeDouble<T>(info);
    if (isEmpty()) {
        head = last = nodeNew;
    } else {
        head->previous = nodeNew;
        nodeNew->next = head;
        head = nodeNew;
    }
}

template<class T>
void LinkedDouble<T>::addNodeLast(T info) {
    NodeDouble<T> *nodeNew = new NodeDouble<T>(info);
    if (isEmpty()) {
        head = last = nodeNew;
    } else {
        last->next = nodeNew;
        nodeNew->previous = last;
        last = nodeNew;
    }
}

template<class T>
NodeDouble<T> *LinkedDouble<T>::findNode(std::string id) {
    NodeDouble<T>* aux = head;
    while( aux != NULL){
        if (id.compare(aux -> info.getId())==0){
            return aux;
        }
        aux = aux->next;
    }
    return NULL;
}

template <class T>
T *LinkedDouble<T> ::findInfo(std::string id) {
    NodeDouble<T>* aux = head;
    while(aux != NULL){
        if(id.compare(aux->info.getId()) == 0){
            return &aux->info;
        }
        aux = aux -> next;
    }
    return NULL;
}

template<class T>
void LinkedDouble<T>::addNodeAfterTo(NodeDouble<T> *node, T info) {
    NodeDouble<T> *nodeNew = new NodeDouble<T>(info);
    NodeDouble<T> * aux = head;
    if( node == last ){
        if(node != NULL){
            while(aux != node){
                aux = aux -> next;
            }
            nodeNew->previous = aux;
            nodeNew->next = aux->next;
            aux->next->previous = nodeNew;
            aux->next = nodeNew;
        }
    }else{
        last->next = nodeNew;
        nodeNew ->previous = last->previous;
        last = nodeNew;
    }
}

template<class T>
void LinkedDouble<T>::addNodeBeforeTo(NodeDouble<T>  *node, T info) {
    NodeDouble<T> *nodeNew = new NodeDouble<T>(info);
    NodeDouble<T> *aux = head;
    if( node != head ){
        if(node != NULL){
            while (aux != node){
                aux = aux ->next;
            }
            nodeNew -> next = aux;
            aux -> previous->next = nodeNew;
            aux -> previous = nodeNew;
        }
    }else{
        head -> previous = nodeNew;
        nodeNew ->next = head;
        head = nodeNew;
    }
}

template<class T>
void LinkedDouble<T>::addNodeSorted(T info) {
    NodeDouble<T> *nodeNew = new NodeDouble<T>(info);
    NodeDouble<T> * aux = head;
    if (isEmpty()) {
        addNodeFirst(info);
    } else if (info.getId().compare(head->info.getId()) < 0) {
        addNodeFirst(info);
    } else if (info.getId().compare(last->info.getId()) > 0) {
        addNodeLast(info);
    } else {
        while (aux != NULL && aux ->next != NULL) {
            if(info.getId().compare(aux->info.getId()) >0 && info.getId().compare(aux->next->info.getId())<0){
                addNodeAfterTo(aux, info);
                break;
            }
            aux = aux -> next;
        }
    }
}

template<class T>
std::vector<T> LinkedDouble<T> ::getList(bool forward) {
    std::vector<T> out;
    NodeDouble<T>* aux = forward ? head : last;
    while (aux != NULL){
        out.push_back((aux -> info));
        aux = forward ? aux -> next : aux ->previous;
    }
    return out;
}

template <class T>
T LinkedDouble<T> :: deleteNode(NodeDouble<T> *node){
    T info = node->info;
    if(node == head){
        if(node == last){
            last = last -> previous;
            head = head -> next;
        }else{
            head = head -> next;
        }
    }else{
        if(node == last){
            last = last -> previous;
            node -> previous -> next = NULL;
        }else{
            NodeDouble<T>* aux = head;
            NodeDouble<T>* auxx = aux -> next;
            while (aux -> next != node){
                aux = aux -> next;
                auxx = aux->next;
            }
            aux -> next = node ->next;
            auxx -> next -> previous = aux;
        }
    }
    delete(node);
    return info;
}

template<class T>
int LinkedDouble<T>::getSize() {
    int cont = 0;
    NodeDouble<T> *aux = head;
    while (aux != NULL) {
        aux = aux->next;
        cont++;
    }
    return cont;
}

template<class T>
T *LinkedDouble<T>::getObject(int position) {
    NodeDouble<T> *aux = head;
    int cont = 1;
    while (aux != NULL) {
        if(cont == position){
            return &aux->info;
        }
        cont++;
        aux = aux->next;
    }
    return NULL;
}

template <class T>
T LinkedDouble<T>::getFirst(){
    return head -> info;
}

template <class T>
T LinkedDouble<T>::getLast(){
    return last -> info;
}

template<class T>
LinkedDouble<T>::~LinkedDouble() {
   // NodeDouble<T> *aux;
   // while (head != NULL) {
    //    aux = head;
    //    head = head->next;
    //    delete (aux);
   // }
}
