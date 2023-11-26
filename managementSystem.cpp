#include<iostream>
#include <conio.h> 
#include <stdlib.h> 
#include <string.h> 
#include<vector>
#include<Windows.h>

using namespace std;
// Node
class Node{
public:
    string name;
    int roll;
    int marks;
    Node* prev;
    Node* next;
public:
    Node(string name,int roll,int marks)
    {
        this->marks = marks;
        this->name = name;
        this->roll = roll;
        prev = nullptr;
        next = nullptr; 
    }
};
// Double Link List
class doubleLinkList{
    Node* head;
    Node* tail;
public:
    doubleLinkList()
    {
        head = nullptr;
    }
    // insert
    bool insertBegin(string name,int roll, int marks)
    {
        Node* nextNode = new  Node(name,roll,marks);
        if(head == nullptr)
        {
            nextNode->next =  head;
            head = nextNode;
            tail = nextNode;
            
        }
        else{
            nextNode->next =  head;
            head->prev = nextNode;
            head = nextNode;
             
        }
    }
    // insert end
    bool insertEnd(string name,int roll, int marks)
    {
        Node* nextNode = new  Node(name,roll,marks);
        if(head == nullptr)
        {
            nextNode->next =  head;
            head = nextNode;
            tail = nextNode;
        }
        else
        {
            tail->next = nextNode;
            nextNode->prev = tail;
            tail = nextNode;
            
        }

    }
    // Display
    void displayBegin()
    {
        Node* temp = this->head;
        while(temp != nullptr)
        {
            cout<<temp->name + " and " << temp->marks << endl;
            temp = temp->next;
        }
    }

    void displayLast()
    {
        Node* temp = this->tail;
        while(temp != nullptr)
        {
            cout<<temp->name + " and " << temp->marks << endl;
            temp = temp->prev;
        }
    }
    // Search
    bool Search(int roll)
    {
        Node* temp = this->tail;
        while(temp != nullptr)
        {
            if(temp->roll == roll)
            {
                cout<<temp->name + " and " << temp->marks << endl;
                break;
            }
            temp = temp->prev;
        }
    }
    // Delete
    bool Delete(int roll)
    {
        Node* temp = this->head;
        while(temp != nullptr)
        {
            if(temp->roll == roll)
            {
                Node* t = temp->prev;
                t->next = temp->next;
                Node* t2 = temp->next;
                t2->prev = temp->prev;
                
                break;
            }
            temp = temp->next;
        }
    }
    // Update
    // Search
    bool UpdateMarks(int roll, int marks)
    {
        Node* temp = this->tail;
        while(temp != nullptr)
        {
            if(temp->roll == roll)
            {
                temp->marks = marks;
                cout<<"Updated";
                break;
            }
            temp = temp->prev;
        }
    }

};
// Print array menu
void pageHeader()
{
	system("cls");
	cout << "*********************************************************************************************" << endl;
	cout << "|                                     STUDENT MANAGEMENT SYTEM                               |" << endl;
	cout << "*********************************************************************************************" << endl;
}
// Link List printer
int listPrinter(int n,vector<string> menu)
{
	if (n == 7)
	{
		return 0;
	}
	cout << to_string(n + 1) <<"   " << menu[n ] <<endl;
	return listPrinter(n + 1, menu);
}
// CREATE STUDENT STUDENT
void createStudent(doubleLinkList &link)
{   
    string name;
    int x,y;
    cout<<"ENTER STUDENT NAME: ";
    cin >> name;
    cout<<"ENTER STUDENT ROLL: ";
    cin >> x;
    cout<<"ENTER STUDENT MARKS: ";
    cin >> y;
    link.insertBegin(name,x,y);
}
// take roll
int takeRoll()
{   
    int x;
    cout<<"ENTER STUDENT ROLL: ";
    cin >> x;
    return x;
}
// take marks
int takeMarks()
{
    int y;
    cout<<"ENTER STUDENT MARKS: ";
    cin >> y;
    return y;
}
// Student Management System
void SMS(){
    doubleLinkList link;
    vector<string> menu = { "ADD STUDENT",
    "UPDATE STUDENT MARKS","DELETE STUDENT",
    "ALL STUDENT FROM BEGIN","REVERSE LIST",
    "SEARCH STUDENT","EXIT"};
	int opt;
    while(true)
    {
        pageHeader();
        listPrinter(0,menu);
        cout<<"CHOSE ONE: ";
        cin>> opt;
        if(opt == 1)
        {
            createStudent(link);
        }
        else if(opt == 2)
        {
            link.UpdateMarks(takeRoll(),takeRoll());
        }
        else if(opt == 3)
        {
            link.Delete(takeRoll());
        }
        else if(opt == 4)
        {
            link.displayBegin();
        }
        else if(opt == 5)
        {
            link.displayLast();
        }
        else if(opt == 6)
        {
            link.Search(takeRoll());
        }
        else if(opt == 7)
        {
            break;
        }

        Sleep(1000);

    }
}
// main
int main()
{
    SMS();
}
