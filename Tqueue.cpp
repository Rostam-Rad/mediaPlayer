/*****************************************
** File:    Tqueue.cpp
** Project: CMSC 202 project 5, Fall 2020
** Author:  Rostam Boroumand Rad
** Date:    12/7/20
** Section: 20/23
** E-mail:  r66@umbc.edu
** Description: This program is a template class that allows the user to queue, dequeue, and sort a list.
**
***********************************************/


#ifndef TQUEUE_H
#define TQUEUE_H

#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

template <class T, int N> //T is the data type and N is the container's capacity
class Tqueue {
public:
  Tqueue(); //Default Constructor
  Tqueue( const Tqueue<T,N>& x ); //Copy Constructor
  ~Tqueue(); //Destructor
  //Adds item to the back of queue (checks for capacity)
  //Precondition: Existing Tqueue
  //Postcondition: Size is incremented if successful and m_back increases
  void Enqueue(T data); //Adds item to queue (to back)
  //Name: Dequeue
  //Desc: Removes item from queue (from front)
  //      **Automatically moves all data to start at index 0 (using loop**
  //Precondition: Existing Tqueue
  //Postcondition: Size is decremented if successful.
  //               Data in m_front is removed and remaining data is move to the front.
  void Dequeue();
  //Name: Sort
  //Desc: Sorts the contents of the Tqueue (any algorithm you like)
  //Precondition: Existing Tqueue
  //Postcondition: Contents of Tqueue is sorted (low to high)
  void Sort();
  //Name: IsEmpty
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is empty else 0
  int IsEmpty(); //Returns 1 if queue is empty else 0
  //Name: IsFull
  //Precondition: Existing Tqueue
  //Postcondition: Returns 1 if queue is full else 0
  int IsFull(); //Returns 1 if queue is full else 0
  //Name: Size
  //Desc: Returns size of queue
  //Precondition: Existing Tqueue
  //Postcondition: Returns size of queue (difference between m_back and m_front)
  int Size();
  //Name: Overloaded assignment operator
  //Precondition: Existing Tqueue
  //Postcondition: Sets one Tqueue to same as a second Tqueue using =
  Tqueue<T,N>& operator=( Tqueue<T,N> y); //Overloaded assignment operator for queue
  //Name: At
  //Precondition: Existing Tqueue with index starting at 0
  //Postcondition: Returns object from Tqueue using At() 
  T& At(int x);//Returns data from queue at location
  //Name: DisplayAll()
  //Precondition: Existing Tqueue (not used in MediaPlayer)
  //Postcondition: Outputs all items in Tqueue (must be cout compatible -
  //               may require overloaded << in object)
  void DisplayAll();
private:
  T* m_data; //Data of the queue (Must be dynamically allocated array)
  int m_front; //Front of the queue (for this project should always remain at 0)
  int m_back; //Back of the queue (will increase as the size increases)
};

//**** Add class definition below ****
template <class T, int N>
Tqueue<T, N>::Tqueue(){
    m_front = 0;
    m_back = 0;
    m_data = new T[N];
}

template <class T, int N>
Tqueue<T, N>::Tqueue( const Tqueue<T,N>& x ){
    m_back = x.m_back;
    m_front = x.m_front;
    m_data = new T[N];
    //copies list
    for (int i = 0; i < m_back; i++){
        m_data[i] = x.m_data[i];
    }
}

template <class T, int N>
Tqueue<T, N>::~Tqueue(){
    delete [] m_data;
    m_back = 0;
}

template <class T, int N>
void Tqueue<T, N>::Enqueue(T data){
    if (IsEmpty()){
        //adds data to front
        m_data[m_front] = data;
    }else{
        //adds to back
        m_data[m_back] = data;
    }
    m_back++;
}

template <class T, int N>
void Tqueue<T, N>::Dequeue(){
    if (IsEmpty()){
        cout << "Nothing to dequeue." << endl;
    }else{
        //data in m_front is replaced by moving list down one
        for (int i = 0; i < (Size() - 1); i++){
            m_data[i] = m_data[i + 1];
        }
        //removed duplicate last element
        m_data[m_back] = {};
        //size decremented
        m_back--;
    }
}

template <class T, int N>
void Tqueue<T, N>::Sort() {
    //sorts every element
    for (int j = 0; j < Size(); j++) {
        //bubble sort
        for (int i = 0; i < (Size() - 1); i++) {
            //if next letter is larger
            if (m_data[i] > m_data[i + 1]) {
                //switches them
                T temp = m_data[i];
                m_data[i] = m_data[i + 1];
                m_data[i + 1] = temp;
            }
        }
    }
}

template <class T, int N>
int Tqueue<T, N>::IsEmpty(){
    if (Size() != 0){
        //not empty
        return 0;
    }else{
        //empty
        return 1;
    }
}

template <class T, int N>
int Tqueue<T, N>::IsFull() {
    if (Size() != 10){
        //not full
        return 0;
    }else{
        //full
        return 1;
    }
}

template <class T, int N>
int Tqueue<T, N>::Size(){
    //returns size
    return (m_back - m_front);
}

template <class T, int N>
Tqueue<T,N>& Tqueue<T, N>::operator=( Tqueue<T,N> y){
    if (this != &y){
        m_back = y.m_back;
        m_front = y.m_front;
        for (int i = 0; i<Size(); i++){
            m_data[i] = y.m_data[i];
        }
    }
    return *this;
}

template <class T, int N>
T& Tqueue<T, N>::At(int x) {
    return m_data[x];
}

template <class T, int N>
void Tqueue<T, N>::DisplayAll(){
    //loops through list
    for (int i = 0; i < Size(); i++){
        //displays data
        cout << m_data[i] << endl;
    }
}


#endif
