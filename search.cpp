#include "fabric.h"

// TODO
//      [*] -> The Loop should repeat at every charecter <- hell wit the spelling

void search(char term[], List arrayL[20]){
    int len = strlen(term);
    int found = 0;

    // Search in titles

    for (int i = 0; i < 20 ; i++) {
        int z = 0;
        found = 0;

        for (unsigned int k = 0; k < strlen(arrayL[i].title); k++) {
            if (tolower(term[z++]) == tolower(arrayL[i].title[k])) {
                found = 1;
                // cout << "Found title" << endl;
            }

            else {
                found = 0;
                z = 0;
            }

            if (z == len) {
                if (found) {
                    break;
                }
                z = 0;
            }
        }

        if (found) {
            cout << "Found in title, Index => " << i << endl << arrayL[i].title << endl;
        }
    }

    // Search in Tags

    for (int i = 0; i < 20 ; i++) {
        int z = 0;
        found = 0;
        for (int k = 0; k < arrayL[i]._tagIndex; k++) {
            z = 0;

            for (unsigned int c = 0; c < strlen(arrayL[i].tags[k]); c++) {

                if (tolower(term[z++]) == tolower(arrayL[i].tags[k][c])) {
                    found = 1;
                }

                else {
                    found = 0;
                    z = 0;
                }

                if (z == len) {

                    if (found) {
                        break;
                    }

                    z = 0;
                }
            }

            if (found) {
                cout << "Found in tag, Index => " << i << endl;
                arrayL[i].tagView();

                break;
            }
        }
    }

    // Search in Todos

    for (int i = 0; i < 20 ; i++) {
        int z = 0;
        found = 0;
        for (int k = 0; k < arrayL[i]._listIndex; k++) {
            z = 0;
            for (unsigned int c = 0; c < strlen(arrayL[i].list[k].content); c++) {

                if (tolower(term[z++]) == tolower(arrayL[i].list[k].content[c])) {
                    found = 1;
                }

                else {
                    found = 0;
                    z = 0;
                }

                if (z == len) {

                    if (found) {
                        break;
                    }

                    z = 0;
                }
            }

            if (found) {
                cout << "Found in ToDo, List Index => " << i << endl;

                arrayL[i].view();

                break;
            }
        }
    }

}

// int main() {
//     // Just for testing the search
//     List array[20];
//     strcpy(array[0].title, "Note 0: iadtya good");
//
//     strcpy(array[2].title, "Note 2");
//     strcpy(array[2].tags[2], "t2: xtrem");
//     array[2]._tagIndex = 4;
//
//     strcpy(array[3].title, "Note 3");
//     strcpy(array[3].list[0].content, "lop adsc ");
//     array[3]._listIndex = 1;
//
//     strcpy(array[4].title, "Note 4");
//     strcpy(array[4].tags[1], "dsc cisadd hyuc");
//     array[4]._tagIndex = 4;
//
//     strcpy(array[6].title, "Note 6");
//     strcpy(array[6].tags[3], "ad scis");
//     array[6]._tagIndex = 4;
//
//     char term[20];
//
//     strcpy(term, "lop");
//
//     search(term, array);
//
//     return 0;
// }
