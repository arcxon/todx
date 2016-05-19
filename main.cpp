#include "fabric.cpp"
#include <fstream>

using namespace std;

List arrayL[20];
int _arrayLindex = 0;
List currentL;
int isOpenL = 0;

void initiate() {
    fstream file("data.tdx", ios::in|ios::out|ios::binary);
    List tempOb; // temperary object

    while (file.read((char*)&tempOb, sizeof(tempOb))) {
        arrayL[_arrayLindex++] = tempOb;
    }

    file.close();
}

int parse(char command[80]){
    /// Here a crazy fun expression is used
    /// Since we wanted any of them to be zero they were multiplied
    /// to give zero. Mathematically it is quite accurate and syntactically
    /// beautiful.

    int success = 0;

    if (!(strcmp(command, "new")*strcmp(command, "n"))) {
        arrayL[_arrayLindex++].enter();
        success = 1;
    }

    else if (!(strcmp(command, "open")*strcmp(command, "o"))) {
        int choice;
        cout << "Enter The No. of List to be opened" << endl;
        for (int i = 0; i < _arrayLindex; i++) {
            cout << i << " " << arrayL[i].title << endl;
        }
        cin >> choice;
        cin.ignore();

        currentL = arrayL[choice];

        isOpenL = 1;
        success = 1;
    }

    else if (!(strcmp(command, "append")*strcmp(command, "a"))) {
        if (isOpenL) {
            currentL.append();
        }
        else {
            cout << "No List is opened, Open a list first" << endl;
        }
        success = 1;
    }

    else if (!(strcmp(command, "view")*strcmp(command, "v"))) {
        if (isOpenL) {
            currentL.view();
        }
        else {
            cout << "No List is opened, Open a list first" << endl;
        }
        success = 1;
    }


    return success;
}

void finish() {
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
    for (size_t i = 0; i < 4; i++) {
        cout << " *> ";
        cin.getline(command, 80);
        parse(command);
    }

    finish();
    return 0;
}
