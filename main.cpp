#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class pliki {

public:
    ifstream fIn;
    pliki();
    ~pliki();

};

pliki::pliki() {
    fIn.open("c:\\dane_obrazy.txt");
}

pliki::~pliki() {
    fIn.close();
}

class obraz {
public:
    int ktory_obraz = 0;
    vector <string> obraz;
    void get_obraz(string numbers);
    void sprawdz_obraz();
    void wyczysc_Vector();
};

void obraz::get_obraz(string numbers) {
    obraz.push_back(numbers);
}


void obraz::checkPicture() {
    int howManyX = 0, howManyY = 0, badX = 0, badY = 0, x, y ;
    ktory_obraz++;
    for (int i = 0; i < obraz.size() - 1; i++) {
    for (int j = 0; j < obraz.size() - 1; j++) {
     if (obraz[i][j] == '1') {
         howManyX++;
 }
     if (obraz[j][i] == '1') {
         howManyY++;
 }
 }
        if ((howManyX % 2 == 0 && obraz[i][20] == '1') || (howManyX % 2 == 1 && obraz[i][20] == '0')) {
            badX++;
            y = i;
 }
        if ((howManyY % 2 == 0 && obraz[20][i] == '1') || (howManyY % 2 == 1 && obraz[20][i] == '0')) {
            badY++;
            x = i;
  }
        howManyX = 0;
        howManyY = 0;
  }
    
    if ((badX == 1 && badY == 1)) {
        cout << "Obrazek nr: " << ktory_obraz << endl;
        cout << "Wspolrzedne: " << y + 1 << ", " << x + 1 << endl;
    } else if ((badX == 0 && badY == 1)) {
        cout << "Obrazek nr: " << ktory_obraz << endl;
        cout << "Wspolrzedne: " << "21" << ", " << x + 1 << endl;
    } else if ((badX == 1 && badY == 0)) {
        cout << "Obrazek nr: " << ktory_obraz << endl;
        cout << "Wspolrzedne: " << y+1 << ", " << "21" << endl;
    }  
    badX = 0;
    badY = 0;  
}
void obraz::wyczysc_Vector() {
obraz.clear();
}

int main() {
    plik p;
    obraz o;
    string temp;
    while (!f.fIn.eof()) {
    for (int i = 0; i < 21; i++) {
         p.fIn >> temp;
         o.get_obraz(temp);
}
    o.sprawdz_obraz();
    o.wyczysc_Vector();
}
}
