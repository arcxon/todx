#include "fabric.cpp"

void search(char term[], List arrayL[20]){
    int len = strlen(term);
    int found = 0;

    for (int i = 0; i < 20 ; i++) {
        int z = 0;
        found = 0;
        for (unsigned int k = 0; k < strlen(arrayL[i].title); k++) {
            if (tolower(term[z++]) == tolower(arrayL[i].title[k])) {
                found = 1;
                cout << "match 1 \n";
            }
            if (z == len) {
                z = 0;
            }
        }
        if(found){
            cout << "Found at " << i << " title: " << arrayL[i].title;
        }
        found = 0;
    }


}

int main() {
    List array[20];
    strcpy(array[0].title, "Cool Aditya cis cool");
    strcpy(array[3].title, "agst cIS dschb");
    search("cis", array);
    return 0;
}
