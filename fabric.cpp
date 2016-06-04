#include <iostream>
#include <cstring>

#include "fabric.h"


using namespace std;

List::List(){
    _listIndex = 0;
    _tagIndex = 0;
}

List::List(char Title[100]) {
    _listIndex = 0;
    _tagIndex = 0;

    strcpy(title, Title);
}

void List::enter(){
    cout << "Enter title for your list" << endl << green << " +> " << normal;
    cin.getline(title, sizeof(title));

    char choice[10];
    cout << "Do you want some tags? (yes/no)" << endl << Bred << " ?> " << normal;
    cin.getline(choice, sizeof(choice));

    if (!(strcmp(choice, "yes")*strcmp(choice, "y"))) {
        char tagTemp[20];

        cout << "Enter the tag one at a time" << endl << "\'d\' when done " << endl;
        cout << green << " +> " << normal;

        while (1) {
            cin.getline(tagTemp, sizeof(tagTemp));

            if (strcmp(tagTemp, "d") != 0) {
                addTag(tagTemp);
                cout << green << " +> " << normal;
            }

            else {
                break;
            }
        }
    }

}


void List::addTag(char Tag[20]) {
    strcpy(tags[_tagIndex++], Tag);
}

void List::setTitle(char Title[100]) {
    strcpy(title, Title);
}


void List::view() {
    cout << title << endl;
    cout << "============" << endl;

    cout << "Tags : ";
    for (int i = 0; i < _tagIndex; i++) {
        cout << tags[i] << " ";
    }

    cout << endl << endl;

    for (int i = 0; i < _listIndex; i++) {
        cout << "  [" << list[i].status << "]  ";
        cout << list[i].content << endl;
    }
}

void List::indexView() {
    cout << title << endl;
    cout << "============" << endl;

    cout << "Tags : ";
    for (int i = 0; i < _tagIndex; i++) {
        cout << tags[i] << " ";
    }

    cout << endl << endl;

    for (int i = 0; i < _listIndex; i++) {
        cout << " " << i << ". [" << list[i].status << "]  ";
        cout << list[i].content << endl;
    }
}

void List::tagView() {
    cout << title << endl;

    cout << "Tags : ";
    for (int i = 0; i < _tagIndex; i++) {
        cout << tags[i] << " ";
    }

    cout << endl;
}

void List::todoView(int index) {
    cout << index << ".  [" << list[index].status << "]  ";
    cout << list[index].content << endl;
}

void List::tagIndexView() {
    cout << title << endl;
    cout << "============" << endl;

    cout << "Tags :" << endl;
    for (int i = 0; i < _tagIndex; i++) {
        cout << " " << i << ". " << tags[i] << endl;
    }
}

void List::append(){
    char Content[200];
    cout << "Enter the content of ToDo" << endl << green << " +> " << normal;
    cin.getline(Content, sizeof(Content));

    strcpy(list[_listIndex].content, Content);

    list[_listIndex].status = ' ';
    list[_listIndex]._index = _listIndex;
    _listIndex++;
}

void List::removeTodo(int index) {
    for (int i = index; i < _listIndex; i++) {
        list[i] = list[i + 1];
    }
    _listIndex--;
}

void List::removeTag(int index) {
    for (int i = index; i < _tagIndex; i++) {
        strcpy(tags[i], tags[i + 1]);
    }
    _tagIndex--;
}

void List::changeStatus(int index, char status){
    list[index].status = status;
}
