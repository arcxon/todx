#include <iostream>
#include <cstring>

using namespace std;

class Todo{
  public:
    char content[200];
    char status;
    int _index;
};

class List {
  public:
    Todo list[20];

    char title[100];
    char tags[10][20];

    int _listIndex; // Variable to count the filling of list
    int _tagIndex;  // Variable to count the filling of tags

    List();         // Asks for #title(required) and #tags(can be skipped).

    List(char Title[100]);  // Initialize the #list with #title

    void enter(); // Enter the info given by user

    void addTag(char Tag[20]) {
        strcpy(tags[_tagIndex++], Tag);
    }

    void setTitle(char Title[100]) {
        strcpy(title, Title);
    }

    void view();    // View the list's #title #tags and #content

    void indexView();   // View the contents with the index

    void append();  // append a new ToDo in the #list

    void changeStatus(int index, char status){
        // Changes Status of the Item of #index to #status
        list[index].status = status;
    }

    ~List() {}
};

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
    cout << "Enter title for your list\n +> ";
    cin.getline(title, sizeof(title));

    char choice;
    cout << "Do you want some tags?(y/n)" << endl << " ?> ";
    cin >> choice;
    cin.ignore();

    if (choice == 'y') {
        char tagTemp[220];

        cout << "Enter the tag one at a time \n 'd' when done \n +> ";

        while (1) {
            cin.getline(tagTemp, 20);

            if (strcmp(tagTemp, "d") != 0) {
                addTag(tagTemp);
                cout << " +> ";
            }

            else {
                break;
            }
        }
    }

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
        cout << i << ". [" << list[i].status << "]  ";
        cout << list[i].content << endl;
    }
}

void List::append(){
    char Content[200];
    cout << "Enter the content of ToDo \n +> ";
    cin.getline(Content, 200);

    strcpy(list[_listIndex].content, Content);

    list[_listIndex].status = ' ';
    list[_listIndex]._index = _listIndex;
    _listIndex++;
}

// int main() {
//     // NOTE
//     //      This main function is just for testing the stuff
//     List Myl;
//
//     Myl.append();
//     Myl.append();
//
//     Myl.view();
//
//     return 0;
// }
