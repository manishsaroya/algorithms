#include<iostream>
template <class T>
class ListElement{
	public:
		ListElement(T n=0, ListElement* ptr=nullptr):d(n),next(ptr){}

		T d;
		ListElement* next;
};
