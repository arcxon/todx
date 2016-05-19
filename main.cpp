#include "fabric.cpp"
#include <fstream>

using namespace std;

List arrayL[20];
List currentL;
int _arrayLindex = 0;
int _currentLindex;
int isOpenL = 0;

// Fxns Used

void initiate();
int parse(char []);
void finish();

void initiate() {
    // Fxn to read data from external file int the array of Lists
    fstream file("data.tdx", ios::in|ios::out|ios::binary);
    List tempOb; // temperary object

    while (file.read((char*)&tempOb, sizeof(tempOb))) {
        arrayL[_arrayLindex++] = tempOb;
    }

    file.close();
}

int parse(char command[80]){
    // Fxn to Parse(execute) the command passed
    /// Here a crazy fun expression is used
    /// Since we wanted any of them to be zero they were multiplied
    /// to give zero. Mathematically it is quite accurate and syntactically
    /// beautiful.

    int success = 0;

    if (!(strcmp(command, "new")*strcmp(command, "n"))) {
        // Create a new List
        arrayL[_arrayLindex++].enter();
        success = 1;
    }

    else if (!(strcmp(command, "open")*strcmp(command, "o"))) {
        // Open existing lists
        int choice;
        cout << "Enter The No. of List to be opened" << endl;

        for (int i = 0; i < _arrayLindex; i++) {
            cout << i << " " << arrayL[i].title << endl;
        }

        cin >> choice;
        cin.ignore();

        if ( 0 <= choice && choice <= _arrayLindex) {
            currentL = arrayL[choice];
            _currentLindex = choice;

            cout << "Opened : " << currentL.title << endl;
            currentL.view();}

        isOpenL = 1;
        success = 1;
    }

    else if (!(strcmp(command, "append")*strcmp(command, "a"))) {
        // Append a new Todo to the currently opened list
        if (isOpenL) {
            currentL.append();
        }
        else {
            cout << "No List is opened, Open a list first" << endl;
        }
        success = 1;
    }

    else if (!(strcmp(command, "view")*strcmp(command, "v"))) {
        // view todo's of the current list
        if (isOpenL) {
            currentL.view();
        }
        else {
            cout << "No List is opened, Open a list first" << endl;
        }
        success = 1;
    }

    else if (!(strcmp(command, "save")*strcmp(command, "s"))) {
        // Save the data to the file
        arrayL[_currentLindex] = currentL;
        finish();
        success = 1;
    }

    else if (!(strcmp(command, "quit")*strcmp(command, "q"))) {
        // exit the program
        arrayL[_currentLindex] = currentL;
        finish();
        success = -1;
    }

    return success;
}

void finish() {
    // Write the changes back to file
    ofstream file ("data.tdx", ios::out);
    for (int i = 0; i < _arrayLindex; i++) {
        file.write((char*)&arrayL[i], sizeof(arrayL[i]));
    }
}

int main() {
    initiate();
    cout << "TodX" << endl;
    cout << "Hi" << endl;
    char command[80];
    while (1) {
        cout << " *> ";
        cin.getline(command, 80);
        int result = parse(command);
        if(result > 0)
            continue;
        else if(!result) {
            cout << "Internal Error" << endl;
        }
        else if (result == -1) {
            break;
        }
    }

    return 0;
}
