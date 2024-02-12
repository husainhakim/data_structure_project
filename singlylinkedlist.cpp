//Singly Linked List:
// 1.Implement Library Catalog
// - Design a system to keep track of books in a library
// -Each node represents a book, and the linked list facilitates easy addition and removal of books.
// -Searching of a book by title / author name.
#include <iostream>
using namespace std;

class Node {
public:
    string bookname;
    Node* next;
    string bookauthor;
};

void printallbooks(Node* head) {
    Node* current = head;
    while (current != nullptr) {
        cout << "Book: " << current->bookname << ", Author: " << current->bookauthor << endl;
        current = current->next;
    }
    cout<<endl<<endl;
}
void searchforbookbyauthorandname(Node* head,int nameorauthor,string hello)
{
    Node* current=head;
    int pos=1;
bool found;
    if(nameorauthor==1)
    {
        while(current!=NULL)
        {
            if(current->bookname==hello)
            {
             found=true;
            break;
            }
            current=current->next;
            pos++;
        }
        if (found)
        {
            cout<<"Book: "<<current->bookname<<" by author "<<current->bookauthor<< " found at position: "<<pos<<endl;
        }
        else{
            cout<<"Book not found "<<endl;
        }

    }
    else if(nameorauthor==2)
    {
 while(current!=NULL)
        {
            if(current->bookauthor==hello)
            {
             found=true;
            cout<<"Author: "<<current->bookauthor<<" of book "<<current->bookname<< " found at position: "<<pos<<endl;
            }
            current=current->next;
            pos++;
        }
        if (!found)
        {
            cout<<"Book not found "<<endl;
        }
    }

}
void deleteabook(Node*& head, string name) {
    Node* current = head;
    Node* preptr = NULL;

    if (current != NULL && current->bookname == name) {
        head = current->next;
        delete current;
        return;
    }

    while (current != NULL && current->bookname != name) {
        preptr = current;
        current = current->next;
    }

    // If book was not present in linked list
    if (current == NULL) {
        cout << "Book not found" << endl;
    
    }

    // Unlink the node from linked list
    preptr->next = current->next;
    cout<<"Book: "<<current->bookname<<" deleted successfully"<<endl;
    delete current;
}
void addabook(Node* head, string newbookname, string newbookauthor) {
    Node* current = head;
    if (current == NULL) {
        head = new Node();
        head->bookname = newbookname;
        head->bookauthor = newbookauthor;
        head->next = NULL;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        Node* newnode = new Node();
        current->next = newnode;
        newnode->next = NULL;
        newnode->bookname = newbookname;
        newnode->bookauthor = newbookauthor;
    }
}

int main() {
    Node* start = NULL;
    int num;
    cout << "Enter the number of books:" << endl;
    cin >> num;
    cin.ignore();
    string newbookname;
    string newbookauthor;
    Node* lastNode = NULL; 

    for (int i = 0; i < num; i++) {
        Node* newnode = new Node();
        cout << "Enter the name of book number: " << i + 1 << endl;
        getline(cin, newnode->bookname);
        cout << "Enter the name of the author of: " << newnode->bookname << endl;
        getline(cin, newnode->bookauthor);
        newnode->next = NULL; 

        if (start == NULL) {
            start = newnode; 
        } else {
            lastNode->next = newnode; 
        }

        lastNode = newnode;
    }
int option;
    char choice;
    while(choice!='y')
    { 
   
        cout<<"What do you want to perform\n1)See all books\n2)Search for a book\n3)Delete a book\n4)Add a new book\n5)Exit\n\nEnter your choice(1-5):";
        cin>>option;
        switch(option)
        {
            case 1:
            {
 printallbooks(start);
              break;
            }
             
            case 2:
            {  int nora;
              string booksearchbyname;
              string booksearchbyauthor;
              cout<<"Search book for by name of the book or the name of the author:\n1)Search by name\t\t2)Search by author\nEnter your choice(1-2):";
              cin>>nora;
              if (nora==1)
              {
                cout<<"Enter the name of the book to search for: "<<endl;
                cin.ignore();
           getline(cin,booksearchbyname);
                 searchforbookbyauthorandname(start,nora,booksearchbyname);
              }
              else if(nora==2)
              {
            cout<<"Enter the name of the author:"<<endl;
            cin.ignore();
           getline(cin,booksearchbyauthor);
           
            searchforbookbyauthorandname(start,nora,booksearchbyauthor);
              }
              break;}

            case 3:
            { string deletename;
           cout<<"Enter Book name to delete: "<<endl;
           cin>>deletename;
           deleteabook(start,deletename);}
        
            case 5:
             return 0;
            case 4:
            cout<<"Enter the name of the book to be added"<<endl;
            cin.ignore();
            getline(cin,newbookname);
            cout<<"Enter the name of the author of the new book"<<endl;
            getline(cin,newbookauthor);
            addabook(start,newbookname,newbookauthor);
             
        }
    }
    return 0;
}
