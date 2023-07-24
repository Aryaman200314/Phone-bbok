#include<iostream>
#include<stdlib.h>
#include<string>

using namespace std;
struct node
{
	string name, number;
	node *next;
 };
 node *head = NULL, *newnode , *temp;
 	int len =0;
 void C_node ()
 {
 	newnode = new node; 
  	cout <<"Enter Name ";
  	cin>>newnode->name;
  	cout<<"Enter Number ";
  	cin >>newnode->number;
  	newnode->next = NULL;
  	if ( head == NULL)
  	{
  		head = newnode;
  		temp =  newnode;
  		
	}	else {
	  	head->next= newnode;
		  temp =  newnode;  
	  	}
  } 
  
  void Display()
  {
//  	int len =0;
	if (head == NULL)
  	{
  		cout<<"Their are no contacts in the phone book "<<endl;	
	}
	
	else 
	{
		node *trav = head ;
		while (trav != NULL)
		{
			cout<<"\n\tFull name "<<trav->name<<endl;
			cout<<"\t\tPhone number "<<trav->number<<endl;
			trav =trav->next;  
			len++;	
		}
		cout<<" /n Total contacts in the phone book = "<<len<<endl;
	}
  	
  }
  
  void Search_cont ()
  {
  	string srch;
  	node *search_node =  head;
  	int count = 1;
	cout<<"Enter your contact number to search ";
  	cin>>srch;
  	
  	bool found = true;
  	if (head == NULL)
  	{
  		cout <<"\n Contact book is empty "<<endl;
	  }
	  
	  else 
	  {
	  	while (search_node != NULL)
	  	{
	  		if(srch == search_node->name || srch == search_node->number)
	  		{
	  			cout<<"\n\t\tFull name: "<<search_node->name<<endl;
	  			cout<<"\t\tPhone number: "<<search_node->number<<endl;
	  			found = true;
	  			break;
			}
			search_node = search_node->next;
			count++;
		  }
	  }
  	if (found == true )
  	{
  		
	  	cout<<"Index of the contact: " <<count<<endl;
	  }
  }
  
  void menu ()
  {
  	cout<<"Enter 1 to add contact "<<endl;
  	cout<<"Enter 2 to display all contacts "<<endl;
  	cout<<"Enter 3 to search the contact "<<endl;
  	cout<<"Enter 4 to delete "<<endl;
  	cout<<"Enter 5 to delete the whole phone book"<<endl;

  	
  	
  }


void at_give_Delete()
{
	int pos;
	node *next_node;
	temp = head;
	cout<<"Enter the desired position to delete: "<<endl;
	cin>>pos;
	if(head == NULL)
	{
		cout<<"Phone book is empty "<<endl;
	}
	else if (pos > len)
	{
		cout<<"Invalid Position"<<endl;
	}
	
	else if (pos ==0 )
	{
		temp = head;
		head = head->next;
		delete temp;
		cout<<"Contact has been deleted"<<endl;
	}
	else 
	{
		for (int i = 1; i<pos; i++)
		{
			temp = temp->next;
		}
		next_node = temp->next;
		temp->next = next_node->next;
		delete next_node;
		cout<<"Contact has been deleted"<<endl;
		
	}
}

void delete_all()
{
	if (head == NULL)
	{
		cout<<"Phone book is empty "<<endl;
	}
	else 
	{
		temp = head;
		while ( head != NULL)
		{
			head = head->next;
			delete temp;
		}
		cout<<"\t\nWhole Phone book has been deleted! "<<endl;
	}
}


int main()
{
	int op;
	while (true)
	{
		menu();
		cin>>op;
		switch(op)
		{
		case 1:
			C_node();
			break;
		
		case 2:
			len =0;
			Display();
			break;
			
		case 3:
			Search_cont();
			break;
			
		case 4:
			at_give_Delete();
			break;
			
		case 5:
			delete_all();
			break;
			
			
			default:
				cout<<"Invalid ID"<<endl;
				
		}
	}
}


