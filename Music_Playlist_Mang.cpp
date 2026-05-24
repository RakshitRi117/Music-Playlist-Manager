#include <iostream>
#include <string>
using namespace std;

class Node{
public:
    string song;
    string artist;
    Node* next;
    Node(string sng , string art) {
        song=sng;
        artist=art;
        next=NULL;
    }
};

class List{
    public:
    Node* head;
    Node* tail;
    Node* current;
    public:
    List() {
        head=tail=NULL;
        current=head;
    }

    void push_back(string sng , string art) {
        Node* newnode = new Node(sng,art);
        if (head==NULL) {
            head=tail=newnode;
            current=head;
        } else {
            tail->next=newnode;
            tail=newnode;
        }
    }

    void pop_front() {
        if(head==NULL) {
            return;
        }else {
            Node* temp=head;
            head=head->next;
            temp->next=NULL;
            delete temp;
        }
    }
    void pop_back() {
        if(head==NULL) {
            return;
        } else {
            Node* temp=head;
            while(temp->next!=tail) {
                temp=temp->next;
            }
            temp->next=NULL;
            delete tail;
            tail=temp;
        }
    }
    void next() {
        current=current->next;
    }
    void play() {
        cout << "Currently playing -" << current->song <<" " <<  "by" << " " << current->artist << endl;
    }
    void print() {
        Node* temp=head;
        while(temp!=NULL) {
            cout << temp->song << "-" ;
            cout << temp->artist << endl;
            temp=temp->next;
        }
        cout << endl;
    }

};

int main() {
    List ll;
    int choice;
    string song_name , song_artist;
    do{
        cout << "1. Add song" << endl;
        cout << "2. Display all songs" << endl;
        cout << "3. Next song" << endl;
        cout << "0. Exit";
        cout << endl;
        cin >> choice;

        switch(choice) {
            
            case 1 :cout << "Enter songs name and artist" << endl;
                    cin.ignore();
                    getline(cin,song_name);
                    getline(cin,song_artist);
                    ll.push_back(song_name,song_artist);
                    break;
            case 2:  ll.print();
                    break;
            case 3:  ll.next() ;
                     ll.play();
                     break;
        }
    } while(choice!=0);
    return 0;
}