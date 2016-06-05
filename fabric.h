#ifndef INC_FABRIC_H
#define INC_FABRIC_H


// Color variables using ANSI sequences

const char Bred[12]     =   "\033[1;31m";
const char Bgreen[12]   =   "\033[1;32m";
const char Byellow[12]  =   "\033[1;33m";
const char Bblue[12]    =   "\033[1;34m";
const char Bmagenta[12] =   "\033[1;35m";
const char Bcyan[12]    =   "\033[1;36m";

const char red[12]      =   "\033[;31m";
const char green[12]    =   "\033[;32m";
const char yellow[12]   =   "\033[;33m";
const char blue[12]     =   "\033[;34m";
const char magenta[12]  =   "\033[;35m";
const char cyan[12]     =   "\033[;36m";

const char normal[12]   =   "\033[0;m";

// Classes

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

    int _listIndex;     // Variable to count the filling of list
    int _tagIndex;      // Variable to count the filling of tags

    List();                 // Asks for #title(required) and #tags(can be skipped).

    List(char Title[100]);  // Initialize the #list with #title

    void enter();           // Enter the info given by user

    void addTag(char Tag[20]); // Add the tag to Tags

    void setTitle(char Title[100]); // Set the Title given

    void view();            // View the list's #title #tags and #content

    void indexView();       // View the contents with the index

    void tagView();         // View only Title and tags

    void todoView(int);     // View the todo of index passed

    void tagIndexView();    // View the Title and Tags with the index

    void append();          // append a new ToDo in the #list

    void removeTodo(int);   // delete the list at index passed

    void removeTag(int);   // delete the tag at index passed

    void changeStatus(int index, char status); // Changes Status of the Item of #index to #status

    ~List() {}
};


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



#endif /* INC_FABRIC_H */
