// Complete Linked List Operations in C++
// Developed by Rochak Tiwari
#include  <iostream>
#include<conio.h>
using namespace std;

int get()
{
	int a;
    	cin>>a;
    	return a;
}

// Singly Linked List

struct s_node
{
        int s_data;
        struct s_node*s_next;   
};
struct s_node*s_head=NULL;

void s_display()
{
        s_node*temp=s_head;
        while (temp!=NULL)
        {    
                cout<<temp->s_data<<"->";
                temp=temp->s_next; 
        }
        cout<<"null\n";
}

void s_create() 
{
        if (s_head == NULL) 
        {
                s_node* temp = new s_node;
                cout << "Enter the value/data you want to insert: ";
                int d = get();
                temp->s_data = d;
                temp->s_next = NULL;
                s_head = temp;
                cout << "Done! Your linked list is successfully created:\n";
                s_display();
        } 
        else
        {
                cout << "Cannot be created because a linked list already exists.\n";
        }
}
  
void s_insertatbeginning( )
{
        if (s_head == NULL)
	{
		s_create ();
	}
        cout << "Enter the value/data you want to insert: ";
        int a=get();
        s_node* temp = new s_node;
        temp->s_data = a;
        temp->s_next = s_head;
        s_head = temp;
        cout << "Done! Your linked list is updated successfully:\n";
        s_display();
}

void s_insertatend()
{
        s_node* temp = new s_node;
        cout << "Enter the value/data you want to insert: ";
        int a = get();
        temp->s_data = a;
        temp->s_next = NULL;

        if (s_head == NULL)
        {
                s_head = temp;
        } 
        else
        {
                s_node* temp = s_head;
                while (temp->s_next != NULL) 
                {
                        temp = temp->s_next;
                }
                temp->s_next = temp;
        }
        cout << "Done! Your linked list is updated successfully:\n";
        s_display();
}       

void s_insertatspecificposition()
{
        if (s_head == NULL)
	{
		cout<<" There is no linklist available so insearch is not possible did you want to create new linklist press Y for yes or other key to go back:";
		char a;
		cin>>a;
		if (a=='y'||a=='Y')
		{
			system("CLS"); 
			s_create ();
		}
	}
	else
	{
                cout<<"Enter the  position which you whant to insert:";
		int pos=get();
                if (pos <= 0) 
                {
                        cout << "Invalid position.\n";
                        return;
                }
		if (pos==1)
		{
			s_insertatbeginning( );
		}
		else
		{
			s_node*temp=s_head;
                        int count =1;
                        pos=pos-1;
   			while (count < pos && temp->s_next != NULL)
                        {
                                temp = temp->s_next;
                                count++;
                        }
                        if(count == pos)
                        {
                        struct s_node*temp1;
                        temp1=new s_node;
                        cout<<"Enter the value/data  which you whant to insert:";
                        temp1->s_data=get();
                        temp1->s_next=temp->s_next;
                        temp->s_next=temp1;
                        s_display();
                        }
                        else
                        {
        		        cout << "Position not found, inserting at the end.\n";
                                s_insertatend();
                        }
                }
        }
}

void s_delete_at_beginning()
{
        s_node*ptr;
        ptr=s_head;
        s_head=s_head->s_next;
        delete ptr;
        ptr=NULL;
        cout << "Node deleted from the end.\n";
        s_display();
}

void s_delete_at_last()
{
        s_node*trail=NULL;
        s_node*temp=s_head;
        while (temp->s_next!=NULL)
        {
                trail=temp;
                temp=temp->s_next;
        }
        delete temp;
        trail->s_next=NULL;
        cout << "Node deleted from the end.\n";
        s_display();

}

void s_delete_by_value()
{
        cout<<"Enter the value/data  which you whant to delete:";
        int value=get();
        if (s_head->s_data==value)
        {
                s_delete_at_beginning();
        }
        else
        {
                s_node*trail=NULL;
                s_node*temp=s_head;
                while (temp->s_data!=value&&temp!=NULL)
                {  
                        trail=temp;  
                        temp=temp->s_next;  
                }  
                if(temp->s_next==NULL && temp->s_data==value)
                {
                        s_delete_at_last();

                }
                else
                {
                        if(temp->s_data==value)
                        {
                                trail->s_next=temp->s_next;
                                delete temp;  
                                cout << "Node with value " << value << " deleted.\n";
                                s_display();   
                        }
                        else
                        {
                                cout << "Value not found\n";
                                s_display();
                        }        
                }
        }
}

void s_delete_by_position()
{
        cout<<"Enter the  position which you whant to delete:";
        int pos=get();
        if (pos <= 0) 
        {
                cout << "Invalid position.\n";
                return;
        }
        if (pos==1)
        {
                s_delete_at_beginning();
        }
        else
        {
                s_node*trail=NULL;
                s_node*temp=s_head;
                int count;
                for(count=1 ;count<pos && temp->s_next!=NULL;count++)
                {       
                        trail=temp;
                        temp=temp->s_next;  
                }
                if(temp->s_next==NULL&&count==pos)
                {
                        s_delete_at_last();

                }
                else
                {  
                        if(count == pos)
                        {
                                trail->s_next=temp->s_next;
                                delete temp;  
                                s_display();   
                        }
                        else
                        {
                                cout << "Value not found\n";
                                s_display();
                        }
                }
        }
}

void s_input_together()
{
        cout<<"How maney nodes";
        int n= get();
       
        for (int i = 1; i <= n; i++)
        {
                
                if (s_head==NULL)
                {
                        s_create ();        
                }
                else
                {
                        s_insertatend();      
                }
                       
        }
       
}

// Doubly Linked List

struct d_node
{
	struct d_node*d_prev; 
	int d_data;
	struct d_node*d_next;   
};
struct d_node*d_head=NULL;

void d_display()
{
	d_node*temp=d_head;
	while (temp!=NULL)
	{    
		cout<<temp->d_data<<"->";
		temp=temp->d_next; 
	}
	cout<<"null\n";
}

void d_create ()
{
        if(d_head==NULL)
        {
                struct d_node*ptr;
                cout<<"Enter the value/data  which you whant to insert:";
                int d=get() ;
                ptr=new d_node;
               d_head=ptr;
                d_head->d_data=d;
                d_head->d_prev=NULL;
                d_head->d_next=NULL;
                cout<<"Done your linksist is successfully made:\n";
                d_display();
        }
        else
        {
                cout<<"Cannot be created because linklist already exists";
        }
        
}

  
void d_insertatbeginning( )
{
	if (d_head == NULL)
	{
		d_create ();
	}
	else
	{
		struct d_node*ptr;
		ptr=new d_node;
		cout<<"Enter the value/data  which you whant to insert:";
		int a=get();
		ptr->d_prev=NULL;
		ptr->d_data=a;
		ptr->d_next=d_head;
		d_head->d_prev=ptr;
		d_head=ptr;
		cout<<"Done your linksist is update successfully\n:";
		d_display();
	}
}

void d_insertatend( )
{
        if (d_head == NULL)
        {
		d_create ();
	}
        else
       {
		struct d_node*ptr;
		ptr=new d_node;
		cout<<"Enter the value/data  which you whant to insert:";
		int a=get();
		ptr->d_data=a;
		ptr->d_next=NULL; 
		struct d_node*temp; 
		temp=d_head;
		while (temp->d_next!=NULL)
		{    
		temp=temp->d_next;
		}
		temp->d_next=ptr;
		ptr->d_prev=temp;
                d_display();
        }
         cout<<"Done your linksist is update successfully\n:";
    
}

void d_insertatspecificposition()
{
	if (d_head == NULL)
	{
		cout<<" There is no linklist available so insearch is not possible did you want to create new linklist press Y for yes or other key to go back:";
		char a;
		cin>>a;
		if (a=='y'||a=='Y')
		{
			system("CLS"); 
			d_create ();
		}
	}
	else
	{
		cout<<"Enter the  position which you whant to insert:";
		int pos=get();
                if (pos <= 0) 
                {
                        cout << "Invalid position.\n";
                        return;
                }
		if (pos==1)
		{
			d_insertatbeginning( );
		}
		else
		{
			d_node*temp=d_head;
                        int count =1;
   			while (count < pos && temp->d_next != NULL)
                        {
                                temp = temp->d_next;
                                count++;
                        }
		
                                if(count == pos)
                                {
                                        struct d_node*ptr;
			                ptr=new d_node;
                                        cout<<"Enter the value/data  which you whant to insert:";
                                        int a=get();
                                        ptr->d_data=a;
                                        ptr->d_next=temp;
                                        (temp->d_prev)->d_next=ptr;
                                        ptr->d_prev=temp->d_prev;
                                        temp->d_prev=ptr; 
                                        d_display();      
                                }
                                else
                                {
				        cout << "Position not found, inserting at the end.\n";
                                        d_insertatend();
                                }
			
				
		}		
        }
        
}

 
void d_delete_at_beginning()
{
        d_head=d_head->d_next;
        delete (d_head->d_prev);
        d_head->d_prev=NULL;
        d_display(); 
}

void d_delete_at_last()
{
        d_node*temp=d_head;
        while (temp->d_next!=NULL)
        {
                temp=temp->d_next;
        }
        if (temp->d_prev) //temp->next=null
        {
                (temp->d_prev)->d_next=NULL;
                delete temp;
                d_display(); 
        } 
        else
        {
                delete d_head;
                d_head = NULL;
                cout<<"Value/data delete now there is no linklist:";
        }
        

}

void d_delete_by_value()
{       
        cout<<"Enter the value/data  which you whant to delete:";
        int value=get();
        if (d_head->d_data==value)
        {
                d_delete_at_beginning();
        }
        else
        {
                d_node*temp=d_head;
                while (temp->d_data!=value && temp->d_next!=NULL)
                {  
                        temp=temp->d_next;  
                }     
                if(temp->d_next==NULL && temp->d_data==value)
                {
                        d_delete_at_last();

                }
                else
                {
                        if(temp->d_data==value)
                        {
                                (temp->d_prev)->d_next=temp->d_next;
                                (temp->d_next)->d_prev=temp->d_prev;
                                delete temp; 
                                cout << "Value/data deleted.\n"; 
                                d_display();   
                        }
                        else
                        {
                                cout << "Value not found\n";
                                d_display();
                        }        
                }
        }
}

void d_delete_by_position()
{
        cout<<"Enter the  position which you whant to delete:";
        int pos=get();
        if (pos <= 0) 
        {
                cout << "Invalid position./n";
                return;
        }
        if (pos==1)
        {
                d_delete_at_beginning();
        }
        else
        {
                d_node*temp=d_head;
                int count;
                for(count=1 ;count<pos && temp->d_next!=NULL;count++)
                {  
                        temp=temp->d_next;  
                }
                if(temp->d_next==NULL&&count==pos)
                {
                        d_delete_at_last();

                }
                else
                {  
                        if(count == pos)
                        {
                                (temp->d_prev)->d_next=temp->d_next;
                                (temp->d_next)->d_prev=temp->d_prev;
                                delete temp; 
                                cout << "Value/data deleted.\n"; 
                                d_display();   
                        }
                        else
                        {
                                cout << "Value not found\n";
                                d_display();
                        }
                }
        }
  
}

void d_input_together_()
{
        cout<<"How maney nodes";
        int n= get();
       
        for (int i = 1; i <= n; i++)
        {
                
                if (d_head==NULL)
                {
                        d_create ();        
                }
                else
                {
                        d_insertatend();      
                }
                       
        }
}

// Singly Circular Linked List

struct sc_node 
{
        int sc_data;
        struct sc_node* sc_next;
};

struct sc_node* sc_head = NULL;

void sc_display() 
{
        if (sc_head == NULL) 
        {
                cout << "Circular linked list is empty.\n" ;
                return;
        }

        sc_node* temp = sc_head;
        do 
        {
                cout << temp->sc_data << "->";
                temp = temp->sc_next;
        } while (temp != sc_head);
        cout << "head\n" ;
}

void sc_create()
{
        if (sc_head == NULL) 
        {
                sc_node* temp = new sc_node;
                cout << "Enter the value/data you want to insert: ";
                int d = get();
                temp->sc_data = d;
                temp->sc_next = temp; //  itself 
                sc_head = temp;
                cout << "Done! Your circular linked list is successfully created:\n";
                sc_display();
        } 
        else 
        {
                cout << "Cannot be created because a circular linked list already exists.\n";
        }
}

void sc_insertatend() 
{
        if (sc_head == NULL) 
        {
                sc_create();
                return;
        }
        sc_node*ptr=new sc_node;
        cout << "Enter the value/data you want to insert: ";
        int a=get();
        ptr->sc_data = a;
        ptr->sc_next = sc_head;

        sc_node* temp = sc_head;
        while (temp->sc_next != sc_head) 
        {
                temp = temp->sc_next;
        }
        temp->sc_next = ptr;
        cout << "Done! Your circular linked list is updated successfully:\n";
        sc_display();
}

void sc_insertatbeginning() 
{
        if (sc_head == NULL) 
        {
                sc_create();
                return;
        }
        sc_node* ptr = new sc_node;
        cout << "Enter the value/data you want to insert: ";
        int a = get();
        ptr->sc_data=a;
        ptr->sc_next=sc_head;
        sc_node* temp = sc_head;
        while (temp->sc_next != sc_head) 
        {
                temp = temp->sc_next;
        }
        temp->sc_next = ptr;
        sc_head = ptr;
        cout << "Done! Your circular linked list is updated successfully:\n";
        sc_display();
}

void sc_insertatspecificposition() 
{
        if (sc_head == NULL)
        {
                cout << "Circular linked list is empty. Cannot insert at a specific position.\n" ;
                return;
        }
        cout << "Enter the position at which you want to insert: ";
        int pos = get();
        if (pos <= 0) 
        {
                cout << "Invalid position.\n" ;
                return;
        }
        if (pos == 1) 
        {
                sc_insertatbeginning();
                return;
        }
        
        sc_node* temp = sc_head;
        int count = 1;
        while (count < pos - 1 && temp->sc_next != sc_head) 
        {
                temp = temp->sc_next;
                count++;
        }
        if (count==pos-1)
        {
                sc_node* ptr=new sc_node;
                cout<<"Enter the value/data you want to insert: ";
                int a=get();
                ptr->sc_data = a;
                ptr->sc_next = temp->sc_next;
                temp->sc_next = ptr;
                cout << "Done! Your circular linked list is updated successfully:\n";
                sc_display();
        } 
        else 
        {
                cout << "Position not found. Inserting at the end.\n";
                
        }
}

void sc_delete_at_beginning()
 {

        sc_node* temp = sc_head;
        while (temp->sc_next != sc_head) 
        {
                temp = temp->sc_next;
        }
        temp->sc_next = sc_head->sc_next;
        sc_node* temp1 = sc_head;
        sc_head = sc_head->sc_next;
        delete temp1;
        cout << "Node deleted from the beginning.\n";
        sc_display();
}

void sc_delete_at_last() 
{

        sc_node* temp = sc_head;
        sc_node* prev = NULL;
        while (temp->sc_next != sc_head) 
        {
                prev = temp;
                temp = temp->sc_next;
        }
        prev->sc_next = sc_head;
        delete temp;
        cout << "Node deleted from the end.\n";
        sc_display();
}

void sc_delete_by_value() 
{

        cout << "Enter the value/data you want to delete: ";
        int value = get();
        if (sc_head->sc_data == value) 
        {
                sc_delete_at_beginning();
                return;
        }
        sc_node* temp = sc_head;
        sc_node* trail = NULL;
        while (temp->sc_data != value && temp->sc_next != sc_head) 
        {
                trail = temp;
                temp = temp->sc_next;
        }

        if (temp->sc_data == value) 
        {
                trail->sc_next = temp->sc_next;
                delete temp;
                cout << "Node with value " << value << " deleted.\n";
                sc_display();
        } 
        else 
        {
                cout << value << " Not found.\n";
        }
}

void sc_delete_by_position() 
{
        cout << "Enter the position of the dc_node you want to delete: ";
        int pos = get();
        if (pos <= 0) 
        {
                cout << "Invalid position.\n";
                return;
        }
        if (pos == 1)
        {
                sc_delete_at_beginning();
                return;
        }

        sc_node* temp = sc_head;
        sc_node* trail = NULL;
        int count = 1;
        while (count < pos && temp->sc_next != sc_head) 
        {
                trail =temp;
                temp =temp->sc_next;
                count++;
        }

        if (count == pos) 
        {
                trail->sc_next = temp->sc_next;
                delete temp;
                cout<<pos<<" Deleted.\n";
                sc_display();
        } 
        else 
        {
                cout<<"Position not found.\n";
        }
}

void sc_input_together()
{
        cout<<"How maney nodes";
        int n= get();
       
        for (int i = 1; i <= n; i++)
        {
                
                if (sc_head==NULL)
                {
                        sc_create ();        
                }
                else
                {
                        sc_insertatend();      
                }
                       
        }
}

// Doubly Circular Linked List

struct dc_node
{
	struct dc_node*dc_prev; 
	int dc_data;
	struct dc_node*dc_next;   
};
struct dc_node*dc_head=NULL;

void dc_display() 
{
        if (dc_head == NULL) 
        {
                cout << "Circular linked list is empty.\n" ;
                return;
        }

        dc_node* temp = dc_head;
        do 
        {
                cout << temp->dc_data << "->";
                temp = temp->dc_next;
        } while (temp != dc_head);
        cout << "head\n";
}

void dc_create ()
{
        if(dc_head==NULL)
        {
                struct dc_node*ptr;
                cout<<"Enter the value/data  which you whant to insert:";
                int d=get() ;
                ptr=new dc_node;
                dc_head=ptr;
                dc_head->dc_data=d;
                dc_head->dc_prev=NULL;
                dc_head->dc_next=dc_head; //self
                cout<<"Done your linksist is successfully made:\n";
                dc_display();
        }
        else
        {
                cout<<"Cannot be created because linklist already exists";
        }
        
}

void dc_insertatbeginning()
{
        if (dc_head == NULL)
        {
                dc_create();
        }
        else
        {
                struct dc_node *ptr;
                ptr = new dc_node;
                cout << "Enter the value/data  which you want to insert:";
                int a = get();         
                ptr->dc_data = a;
                ptr->dc_next = dc_head;
                dc_head->dc_prev = ptr;
                dc_node *temp = dc_head;
                while (temp->dc_next != dc_head)
                {
                        temp = temp->dc_next;
                }
                temp->dc_next = ptr;
                ptr->dc_prev = temp;
                dc_head = ptr;
                cout << "Done, your linked list is updated successfully:\n";
                dc_display();
        }
}

void dc_insertatend()
{
        if (dc_head == NULL)
        {
                dc_create();
        }
        else
        {
                struct dc_node *ptr;
                ptr = new dc_node;
                cout << "Enter the value/data you want to insert: ";
                int a = get();
                ptr->dc_data = a;
                struct dc_node *temp = dc_head;
                while (temp->dc_next != dc_head)
                {
                        temp = temp->dc_next;
                }
                temp->dc_next = ptr;
                ptr->dc_prev = temp;
                ptr->dc_next = dc_head;
                dc_head->dc_prev = ptr;
                cout << "Done! Your circular linked list has been updated successfully.\n";
                dc_display();
        }
}

void dc_insertatspecificposition()
{
        if (dc_head == NULL)
        {
                cout << "There is no linked list available. Do you want to create a new linked list? (Y/N): ";
                char c;
                cin >> c;
                if (c == 'y' || c == 'Y')
                {
                        system("CLS");
                        dc_create();
                }
                else
                {
                        cout << "No linked list to insert into.\n";
                }
        }
        else
        {
                cout << "Enter the position at which you want to insert: ";
                int pos = get();
                if (pos <= 0)
                {
                        cout << "Invalid position.\n";
                        return;
                }

                if (pos == 1)
                {
                        dc_insertatbeginning();
                }
                else
                {
                        struct dc_node *temp = dc_head;
                        for (int count = 1; count < pos - 1 && temp->dc_next != dc_head; count++)
                        {
                                temp = temp->dc_next;
                        }

                        if (temp->dc_next == dc_head)
                        {
                                cout << "Position not found, inserting at the end.\n";
                                dc_insertatend();
                        }
                        else
                        {
                                cout << "Enter the value/data you want to insert: ";
                                int a = get();
                                struct dc_node *ptr;
                                ptr = new dc_node;
                                ptr->dc_data = a;

                                ptr->dc_next = temp->dc_next;
                                (temp->dc_next)->dc_prev = ptr;
                                temp->dc_next = ptr;
                                ptr->dc_prev = temp;

                                cout << "Done! Your circular linked list has been updated successfully.\n";
                                dc_display();
                        }
                }
        }
}

void dc_delete_at_beginning()
{
        struct dc_node *temp = dc_head;

        if (temp->dc_next == dc_head)
        {
                delete temp;
                dc_head = NULL;
                cout << "Value/data deleted. Now there is no linked list.\n";
        }
        else
        {
                dc_head = temp->dc_next;
                (temp->dc_next)->dc_prev = temp->dc_prev;
                (temp->dc_prev)->dc_next = temp->dc_next;
                delete temp;
                cout << "Value/data deleted from the beginning.\n";
        }
        dc_display();
}

void dc_delete_at_last()
{
        struct dc_node *temp = dc_head;
        struct dc_node *trail = NULL;
        while (temp->dc_next != dc_head)
        {
                trail= temp;
                temp = temp->dc_next;
        }
        if (trail==NULL) // Only one node 
        {
                delete temp;
                dc_head = NULL;
                cout << "Value/data deleted. Now there is no linked list.\n";
        }
        else
        {
                trail->dc_next = dc_head;
                dc_head->dc_prev =trail;
                delete temp;
                cout << "Value/data deleted from the end.\n";
        }
        dc_display();
}

void dc_delete_by_value()
{
        cout<<"Enter the value/data  which you whant to delete:";
        int value=get();
        if (dc_head->dc_data==value)
        {
                dc_delete_at_beginning();
        }
        else
        {
                dc_node*temp=dc_head;
                while (temp->dc_data!=value && temp->dc_next!=dc_head)
                {  
                        temp=temp->dc_next;  
                }     
                if(temp->dc_next==dc_head && temp->dc_data==value)
                {
                        dc_delete_at_last();

                }
                else
                {
                        if(temp->dc_data==value)
                        {
                                (temp->dc_prev)->dc_next=temp->dc_next;
                                (temp->dc_next)->dc_prev=temp->dc_prev;
                                delete temp; 
                                cout << "Value/data deleted.\n"; 
                                dc_display();   
                        }
                        else
                        {
                                cout << "Value not found\n";
                                dc_display();
                        }        
                }
        }
}

void dc_delete_by_position()
{
        cout<<"Enter the  position which you whant to delete:";
        int pos=get();
        if (pos <= 0) 
        {
                cout << "Invalid position./n";
                return;
        }
        if (pos==1)
        {
                dc_delete_at_beginning();
        }
        else
        {
                dc_node*temp=dc_head;
                int count;
                for(count=1 ;count<pos && temp->dc_next!=dc_head;count++)
                {  
                        temp=temp->dc_next;  
                }
                if(temp->dc_next==dc_head&&count==pos)
                {
                        dc_delete_at_last();

                }
                else
                {  
                        if(count == pos)
                        {
                                (temp->dc_prev)->dc_next=temp->dc_next;
                                (temp->dc_next)->dc_prev=temp->dc_prev;
                                delete temp; 
                                cout << "Value/data deleted.\n"; 
                                dc_display();   
                        }
                        else
                        {
                                cout << "Value not found\n";
                                dc_display();
                        }
                }
        }


        
}

void dc_input_together()
{
        cout<<"How maney nodes";
        int n= get();
       
        for (int i = 1; i <= n; i++)
        {
                
                if (dc_head==NULL)
                {
                        dc_create ();        
                }
                else
                {
                        dc_insertatend();      
                }
                       
        }
}

// Main Function

int main()
{
        int option, take;
        while (1)  
        {        
                cout<<"Enter 1 for single linked list:\n";
                cout<<"Enter 2 for double  linked list:\n";
                cout<<"Enter 3 for single circular linked list:\n"; 
                cout<<"Enter 4 for double circular linked list:\n"; 
                cout<<"Enter 5 for exit:\n";            
                cin>>take;
                system("CLS"); 
                switch (take)
                {
                        case 1:  
                        cout<<"Enter 1 for create:\n";
                        cout<<"Enter 2 for insertion:\n";
                        cout<<"Enter 3 for deltion:\n";
                        cout<<"Enter 4 for display:\n";
                        cout<<"Enter 5 for input together:\n";
                        cout<<"Enter 6 for exit:\n";
                        cin>>option; 
                        system("CLS");  
                        switch (option) 
                        {
                                case 1:               
                                s_create();
                                break;  
                                case 2: 
                                cout<<"Enter 1 for  insertion in beginning:\n";
                                cout<<"Enter 2 for insertion in end:\n";
                                cout<<"Enter 3 for insertion in specified place:\n";
                                cout<<"Enter 4  for exit:\n";             
                                cin>>take;
                                system("CLS"); 
                                switch (take)
                                {
                                        case 1:
                                        s_insertatbeginning();
                                        break;
                                        case 2:
                                        s_insertatend();
                                        break;
                                        case 3:
                                        s_insertatspecificposition( );
                                        break;
                                        case 4:
                                        system("CLS");
                                        break;
                                        default:
                                        cout<<"Invalid option. Please try again.\npress other key to try again.";
                                        getch();
                                        system("CLS");
                                        break;  
                                }  
                                break;
                                case 3:  
                                if (s_head == NULL)
                                {
                                        cout<<" There is no linklist available to delete is not possible did you want to create new linklist press Y for yes or other key to go back:";
                                        char a;
                                        cin>>a;
                                        if (a=='y'||a=='Y')
                                        {
                                                system("CLS"); 
                                                s_create ();
                                        }
                                }
                                else
                                {        
                                        cout<<"Enter 1 for dealete in beginning:\n";
                                        cout<<"Enter 2 for by position:\n";
                                        cout<<"Enter 3 for delete at last:\n"; 
                                        cout<<"Enter 4 for delete by value:\n"; 
                                        cout<<"Enter 5 for exit:\n";            
                                        cin>>take;
                                        system("CLS"); 
                                        switch (take)
                                        {
                                                case 1:
                                                s_delete_at_beginning();
                                                break;
                                                case 2:
                                                s_delete_by_position();
                                                break;
                                                case 3:
                                                s_delete_at_last( );
                                                break;
                                                case 4:
                                                s_delete_by_value();
                                                break;
                                                case 5:
                                                system("CLS");
                                                break;
                                                default:
                                                cout<<"Invalid option. Please try again.\npress other key to try again.";
                                                getch();
                                                system("CLS");
                                                break;  
                                        } 
                                }
                                case 4:        
                                s_display();
                                break;
                                case 5:
                                system("CLS"); 
                                s_input_together();
                                break;
                                case 6:
                                system("CLS"); 
                                default:
                                cout<<"Invalid option. Please try again.\npress other key to try again.";
                                getch();
                                system("CLS");
                                break;  
                        }
                        break;
                        case 2:
                        cout<<"Enter 1 for create:\n";
                        cout<<"Enter 2 for insertion :\n";
                        cout<<"Enter 3 for deltion:\n";
                        cout<<"Enter 4 for display:\n";
                        cout<<"Enter 5 for input together:\n";
                        cout<<"Enter 6 for exit:\n";
                        cin>>option; 
                        system("CLS");  
                        switch (option) 
                        {
                                case 1:               
                                d_create();
                                break;  
                                case 2: 
                                cout<<"Enter 1 for  insertion in beginning:\n";
                                cout<<"Enter 2 for insertion in end:\n";
                                cout<<"Enter 3 for insertion in specified place:\n";
                                cout<<"Enter 4  for exit:\n";             
                                cin>>take;
                                system("CLS"); 
                                switch (take)
                                {
                                        case 1:
                                        d_insertatbeginning();
                                        break;
                                        case 2:
                                        d_insertatend();
                                        break;
                                        case 3:
                                        d_insertatspecificposition( );
                                        break;
                                        case 4:
                                        system("CLS");
                                        break;
                                        default:
                                        cout<<"Invalid option. Please try again.\npress other key to try again.";
                                        getch();
                                        system("CLS");
                                        break;  
                                }  
                                break;
                                case 3:  
                                if (d_head == NULL)
                                {
                                        cout<<" There is no linklist available to delete is not possible did you want to create new linklist press Y for yes or other key to go back:";
                                        char a;
                                        cin>>a;
                                        if (a=='y'||a=='Y')
                                        {
                                                system("CLS"); 
                                                d_create ();
                                        }
                                }
                                else
                                {        
                                        cout<<"Enter 1 for dealete in beginning:\n";
                                        cout<<"Enter 2 for by position:\n";
                                        cout<<"Enter 3 for delete at last:\n"; 
                                        cout<<"Enter 4 for delete by value:\n"; 
                                        cout<<"Enter 5 for exit:\n";            
                                        cin>>take;
                                        system("CLS"); 
                                        switch (take)
                                        {
                                                case 1:
                                                d_delete_at_beginning();
                                                break;
                                                case 2:
                                                d_delete_by_position();
                                                break;
                                                case 3:
                                                d_delete_at_last( );
                                                break;
                                                case 4:
                                                d_delete_by_value();
                                                break;
                                                case 5:
                                                system("CLS");
                                                break;
                                                default:
                                                cout<<"Invalid option. Please try again.\npress other key to try again.";
                                                getch();
                                                system("CLS");
                                                break;  
                                        } 
                                }
                                case 4:        
                                d_display();
                                break;
                                case 5:
                                system("CLS"); 
                                d_input_together_();
                                break;
                                case 6:
                                system("CLS");  
                                default:
                                cout<<"Invalid option. Please try again.\npress other key to try again.";
                                getch();
                                system("CLS");
                                break;  
                        }
                        break;
                        case 3:
                        cout<<"Enter 1 for create:\n";
                        cout<<"Enter 2 for insertion:\n";
                        cout<<"Enter 3 for deltion:\n";
                        cout<<"Enter 4 for display:\n";
                        cout<<"Enter 5 for input together:\n";
                        cout<<"Enter 6 for exit:\n";
                        cin>>option; 
                        system("CLS");  
                        switch (option) 
                        {
                                case 1:               
                                sc_create();
                                break;  
                                case 2: 
                                cout<<"Enter 1 for  insertion in beginning:\n";
                                cout<<"Enter 2 for insertion in end:\n";
                                cout<<"Enter 3 for insertion in specified place:\n";
                                cout<<"Enter 4  for exit:\n";             
                                cin>>take;
                                system("CLS"); 
                                switch (take)
                                {
                                        case 1:
                                        sc_insertatbeginning();
                                        break;
                                        case 2:
                                        sc_insertatend();
                                        break;
                                        case 3:
                                        sc_insertatspecificposition( );
                                        break;
                                        case 4:
                                        system("CLS");
                                        break;
                                        default:
                                        cout<<"Invalid option. Please try again.\npress other key to try again.";
                                        getch();
                                        system("CLS");
                                        break;  
                                }  
                                break;
                                case 3:  
                                if (sc_head == NULL)
                                {
                                        cout<<" There is no linklist available to delete is not possible did you want to create new linklist press Y for yes or other key to go back:";
                                        char a;
                                        cin>>a;
                                        if (a=='y'||a=='Y')
                                        {
                                                system("CLS"); 
                                                sc_create ();
                                        }
                                }
                                else
                                {        
                                        cout<<"Enter 1 for dealete in beginning:\n";
                                        cout<<"Enter 2 for by position:\n";
                                        cout<<"Enter 3 for delete at last:\n"; 
                                        cout<<"Enter 4 for delete by value:\n"; 
                                        cout<<"Enter 5 for exit:\n";            
                                        cin>>take;
                                        system("CLS"); 
                                        switch (take)
                                        {
                                                case 1:
                                                sc_delete_at_beginning();
                                                break;
                                                case 2:
                                                sc_delete_by_position();
                                                break;
                                                case 3:
                                                sc_delete_at_last( );
                                                break;
                                                case 4:
                                                sc_delete_by_value();
                                                break;
                                                case 5:
                                                system("CLS");
                                                break;
                                                default:
                                                cout<<"Invalid option. Please try again.\npress other key to try again.";
                                                getch();
                                                system("CLS");
                                                break;  
                                        } 
                                }
                                case 4:        
                                sc_display();
                                break;
                                case 5:
                                system("CLS"); 
                                sc_input_together();
                                break;
                                case 6:
                                system("CLS");   
                                default:
                                cout<<"Invalid option. Please try again.\npress other key to try again. ";
                                getch();
                                system("CLS");
                                break;  
                        }
                        break;
                        case 4:
                        cout<<"Enter 1 for create:\n";
                        cout<<"Enter 2 for insertion :\n";
                        cout<<"Enter 3 for deltion:\n";
                        cout<<"Enter 4 for display:\n";
                        cout<<"Enter 5 for input together:\n";
                        cout<<"Enter 6 for exit:\n";
                        cin>>option; 
                        system("CLS");  
                        switch (option) 
                        {
                                case 1:               
                                dc_create();
                                break;  
                                case 2: 
                                cout<<"Enter 1 for  insertion in beginning :\n";
                                cout<<"Enter 2 for insertion in end:\n";
                                cout<<"Enter 3 for insertion in specified place:\n";
                                cout<<"Enter 4  for exit:\n";             
                                cin>>take;
                                system("CLS"); 
                                switch (take)
                                {
                                        case 1:
                                        dc_insertatbeginning();
                                        break;
                                        case 2:
                                        dc_insertatend();
                                        break;
                                        case 3:
                                        dc_insertatspecificposition( );
                                        break;
                                        case 4:
                                        system("CLS");
                                        break;
                                        default:
                                        cout<<"Invalid option. Please try again.\npress other key to try again.";
                                        getch();
                                        system("CLS");
                                        break;  
                                }  
                                break;
                                case 3:  
                                if (dc_head == NULL)
                                {
                                        cout<<" There is no linklist available to delete is not possible did you want to create new linklist press Y for yes or other key to go back:";
                                        char a;
                                        cin>>a;
                                        if (a=='y'||a=='Y')
                                        {
                                                system("CLS"); 
                                                dc_create ();
                                        }
                                }
                                else
                                {        
                                        cout<<"Enter 1 for dealete in beginning:\n";
                                        cout<<"Enter 2 for by position:\n";
                                        cout<<"Enter 3 for delete at last:\n"; 
                                        cout<<"Enter 4 for delete by value:\n"; 
                                        cout<<"Enter 5 for exit:\n";            
                                        cin>>take;
                                        system("CLS"); 
                                        switch (take)
                                        {
                                                case 1:
                                                dc_delete_at_beginning();
                                                break;
                                                case 2:
                                                dc_delete_by_position();
                                                break;
                                                case 3:
                                                dc_delete_at_last( );
                                                break;
                                                case 4:
                                                dc_delete_by_value();
                                                break;
                                                case 5:
                                                system("CLS");
                                                break;
                                                default:
                                                cout<<"Invalid option. Please try again.\npress other key to try again. ";
                                                getch();
                                                system("CLS");
                                                break;  
                                        } 
                                }
                                case 4:        
                                dc_display();
                                break;
                                case 5:
                                system("CLS"); 
                                dc_input_together();
                                break;
                                case 6:
                                system("CLS");  
                                default:
                                cout<<"Invalid option. Please try again.\npress other key to try again.";
                                getch();
                                system("CLS");
                                break;  
                        }
                        break;
                        case 5:
                        system("CLS");
                        cout<<"END";
                        return 0;
                        break;
                        default:
                        cout<<"Invalid option. Please try again.\npress other key to try again.";
                        getch();
                        system("CLS");
                        break;  
                }
        }
        return 0;
}