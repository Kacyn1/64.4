#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class file {

public:
    ifstream fIn;
    file();
    ~file();

};

file::file() {
    fIn.open("c:\\dane_obrazki.txt");
}

file::~file() {
    fIn.close();
}

class picture {
public:
    int whichPicture = 0;
    vector <string> picture;
    void getPicture(string numbers);
    void checkPicture();
    void clearVector();
};

void picture::getPicture(string numbers) {
    picture.push_back(numbers);
}


void picture::checkPicture() {
    int howManyX = 0, howManyY = 0, badX = 0, badY = 0, x, y ;
    whichPicture++;
    for (int i = 0; i < picture.size() - 1; i++) {
        for (int j = 0; j < picture.size() - 1; j++) {

            if (picture[i][j] == '1') {
                howManyX++;
            }
            if (picture[j][i] == '1') {
                howManyY++;
            }

        }
        if ((howManyX % 2 == 0 && picture[i][20] == '1') || (howManyX % 2 == 1 && picture[i][20] == '0')) {
            badX++;
            y = i;

        }

        if ((howManyY % 2 == 0 && picture[20][i] == '1') || (howManyY % 2 == 1 && picture[20][i] == '0')) {
            badY++;
            x = i;
        }

        howManyX = 0;
        howManyY = 0;

    }
    
    if ((badX == 1 && badY == 1)) {
        cout << "Obrazek nr: " << whichPicture << endl;
        cout << "Wspolrzedne: " << y + 1 << ", " << x + 1 << endl;
    } else if ((badX == 0 && badY == 1)) {
        cout << "Obrazek nr: " << whichPicture << endl;
        cout << "Wspolrzedne: " << "21" << ", " << x + 1 << endl;
    } else if ((badX == 1 && badY == 0)) {
        cout << "Obrazek nr: " << whichPicture << endl;
        cout << "Wspolrzedne: " << y+1 << ", " << "21" << endl;
    }
    
    badX = 0;
    badY = 0;
    
}

void picture::clearVector() {
    picture.clear();
}

int main() {
    file f;
    picture p;
    string temp;
    while (!f.fIn.eof()) {
        for (int i = 0; i < 21; i++) {
            f.fIn >> temp;
            p.getPicture(temp);
        }
        p.checkPicture();
        p.clearVector();
    }
}
