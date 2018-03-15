#include<iostream>
#include"element_lists.h"
using namespace std;
template <class T> 
class List{
	public: 
		List( T* start=nullptr, T* currentPoint=nullptr):head(start),cursor(currentPoint){}
		
		T* getElement(void)
		{
			cout<<"i am inside get element cursor "<<cursor->d<<" have done"<<endl;
			return cursor; 
		}
		
		void incrementCursor(int increment)	//istElement<T>* c1)
		{
			for(int i=0;i<increment;i++)
			{
				if(cursor->next!=nullptr)
				{cursor = cursor->next;
					cout<<"incrementCursor by 1 "<<endl;
				}
				else
				{
					cursor =cursor-> next;
					std::cout<<"Reached the end cursor pointing to nullptr"<<std::endl;
					break;
				}	
			}
		}

		void insertElement(T* elem)
		{
			std::cout<<"inserting the first element"<<std::endl;
			if(head==cursor)
			{	head = elem;
				cout<<"first element"<<endl;
			}
			else{
				T* cursor_ = head;
				while(!(cursor_->next==cursor) || cursor_==nullptr)
				{
					cursor_ = cursor_->next;
				}
				cursor_->next = elem;
			}
			elem->next = cursor;
			cursor = elem;  
			cout<<"updating next"<<endl;
			std::cout<<"have inserted the element"<<cursor->d<<std::endl;
		}

		void printList(void)
		{
			T* iterate = head;
			while(iterate!=nullptr)
			{
				cout<<"Printing the entire list"<<endl;
				cout<<iterate->d<<endl;
				iterate = iterate->next;
			}
		}

	private: 
		T* head;
		T* cursor;
};
int main(int argc, char **argv)
{	
	//Assigning values
	List<ListElement<int> > mylist;
	for(int i=0;i<5;i++)
	{
		mylist.insertElement( new ListElement<int>(i+1) );
		ListElement<int> *lambda = mylist.getElement();
		std::cout<<lambda->d<<std::endl;
	}
	std::cout<<"outside for loop"<<std::endl;
	mylist.incrementCursor(2);
	ListElement<int> *lambda = mylist.getElement();
	std::cout<<lambda->d<<std::endl;
	mylist.insertElement( new ListElement<int>(7+1)  );
	lambda = mylist.getElement();
	std::cout<<lambda->d<<std::endl;
	mylist.printList();
	return 0;
}
