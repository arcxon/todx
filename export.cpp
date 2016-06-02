#include <fstream>
#include "fabric.h"

void Export(List Array[20], int _arrayLindex){
    char fname[40];

    cout << "Enter the Export file name " << endl << green << " +> " << normal;
    cin.getline(fname, sizeof(fname));

    strcat(fname, ".tdexp");

    ofstream file;
    file.open(fname);

    for (int i = 0; i < _arrayLindex; i++) {
        file << Array[i].title << endl;
        file << "===============" << endl;

        file << "Tags : ";
        for (int j = 0; j < Array[i]._tagIndex; j++) {
            file << Array[i].tags[j] << " ";
        }
        file << endl;

        for (int k = 0; k < Array[i]._listIndex; k++) {
            file << " [" << Array[i].list[k].status << "] ";
            file << Array[i].list[k].content << endl;
        }

        file << endl;
    }

    cout << "File exported to : " << fname << " successfully :)" << endl;

    file.close();
}
