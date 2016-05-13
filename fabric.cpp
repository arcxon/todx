#include <iostream>
#include <fstream>

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
    int fill;
    char title[100];
    char tags[10][20];

    list() {
        fill = 0;
    }

    list(char title[100]) {
        fill = 0;
        strcpy(this->title, title);
    }

    void setTags(char tags[10][20]) {
        memcpy(this->tags, tags, sizeof(tags));
    }

    void setTitle(char title[100]) {
        strcpy(this->title, title);
    }

    void view() {
        for (size_t i = 0; i < fill; i++) {
            cout << "[" << list[i].status << "]\t";
            cout << list[i].content << endl;
        }
    }

    void append() {
        char content[200];
        cout << "Enter the content of ToDo \n *> ";
        cin.getline(content, 200);

        strcpy(list[fill].content, content);
        list[fill].status = ' ';
        list[fill]._index = fill;
    }

    void changeStatus(int index, char status){
        list[index].status = status;
    }

    ~list() {}
};

void newList(List &myList){
    char title[100];

    cout << "Enter title for your list\n *> ";
    myList.setTitle(title);

    char choice;
    cout << "Do you want some tags?(y/n)" << endl << " *> ";

    if (choice == 'y') {
        char tags[10][20];
        char tagLine[220];
        int k = j = 0;

        cout << "Enter the tags, seperated by spaces" << endl << " *> ";
        cin.getline(tagLine, 220);

        for (size_t i = 0; i < 220; i++) {
            if (tagLine[i] != ' ') {
                tags[j][k++] = tagLine[i];
            }
            else {
                j++;
                k = 0;
            }
        }

        myList.setTags(tags);
    }
}

int main() {
    // NOTE
    //      This main function is just for testing the stuff
    return 0;
}
