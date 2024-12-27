//SKLAD in VRSTA

#include <iostream>
using namespace std;

void menu() {
    cout << "Sklad - izbira:" << endl;
    cout << "1. Dodaj na sklad" << endl;
    cout << "2. Beri s sklada" << endl;
    cout << "3. Izpisi sklad" << endl;
    cout << endl;
    cout << "Krozna vrsta - izbira:" << endl;
    cout << "4. Vpisi v vrsto" << endl;
    cout << "5. Beri iz vrste" << endl;
    cout << "6. Izpisi vrsto" << endl;
    cout << endl;
    cout << "7. Konec" << endl;
    cout << endl;
    cout << "Izbira: ";

}

//FUNKCIJE ZA SKLAD
void push(int* sklad, int& vrh, int max) {
    int i;
    cout << "Vpisi stevilo za dodajanje na sklad: ";
    cin >> i;                                                       //poljubno stevilo, ki ga vnese uporabnik

    if (vrh == max) {                                               //èe je indeks VRH enak velikosti sklada, je sklad poln 
        cout << "NAPAKA: Sklad je poln!" << endl;
        cout << endl;
    }
    else {
        sklad[vrh] = i;                                             //na indeks VRH vstavimo število in poveèamo VRH za 1
        cout << "Na sklad je vstavljeno stevilo: " << i << endl;
        cout << endl;
        vrh++;
    }
}

void pop(int* sklad, int& vrh) {
    if (vrh == 0) {                                                 //èe je indeks VRH enak 0 pomeni, da je skad prazen...
        cout << "NAPAKA: Sklad je prazen!" << endl;
        cout << endl;
    }
    else {
        vrh--;                                                      //...drugaèe izpišemo zaden element v skladu in zmanšamo VRH za 1
        cout << "Zadnji element na skladu: " << sklad[vrh] << endl;
        cout << endl;
    }
}

void izpisi(int* sklad, int vrh) {
    cout << "Vsebina sklada: ";                                     //izpšemo vse na skladu med indeksoma 0 in VRH
    for (int i = 0; i < vrh; i++) {
        cout << sklad[i] << " ";
    }
    cout << endl;
    cout << endl;
}


//FUNKCIJE ZA VRSTO
void vpisi(int* vrsta, int& rep, int glava, int maxi) {
    int i;
    cout << "Vpisi stevilo v vrsto: ";
    cin >> i;

    int rep_zacasen = rep + 1;

    if (rep_zacasen > maxi) {
        rep_zacasen = 0;
    }

    if (rep_zacasen == glava) {
        cout << "NAPAKA: Vrsta je polna" << endl;
        cout << endl;
    }
    else {
        vrsta[rep] = i;                                             //izpišem element v vrsti na indeksu REP
        cout << "V vrsto je vstavljeno stevilo: " << i << endl;
        cout << endl;
        rep = rep_zacasen;                                          //èe je REP enak dolžini vrste, ga nastavimo na niè, drugaèe ga poveèamo za 1 
    }
}

void beri(int* vrsta, int rep, int& glava, int maxi) {
    if (rep == glava) {                                            //èe sta GLAVA in REP na istem indeksu, potem je vrsta prazna
        cout << "NAPAKA: Vrsta je prazna" << endl;
        cout << endl;
    }
    else if (glava == maxi) {                                      //èe je GLAVA (torej indeks prvega elementa) enak dolžini vrste, izpišemo element na tem indeksu in GLAVO nastavimo na indeks 0
        cout << "Prvi element v vrsti: " << vrsta[glava] << endl;
        cout << endl;
        glava = 0;
    }
    else {                                                          //... drugaèe izpišemo element na indeksu GLAVA in jo poveèamo za 1
        cout << "Prvi element v vrsti: " << vrsta[glava] << endl;
        cout << endl;
        glava++;
    }
}

void izpis(int* vrsta, int rep, int& glava, int maxi) {
    if (glava == rep) {
        cout << "NAPAKA: Vrsta je prazna" << endl;
    }
    else {
        cout << "Vsebina vrste: ";
        if (glava < rep) {                                            //èe je GLAVA na manjšem indeksu kot REP, izpišemo vrsto od glave do repa ...
            for (int i = glava; i < rep; i++)
                cout << vrsta[i] << " ";
            cout << endl;
        }
        else {                                                      // ... drugaèe izpišemo od GLAVE do MAXI, in nato še od 0 do REPA
            for (int i = glava; i <= maxi; i++)
                cout << vrsta[i] << " ";
            for (int j = 0; j < rep; j++)
                cout << vrsta[j] << " ";
            cout << endl;
        }
        cout << endl;
    }
}



int main() {
    int izbira;
    bool running = true;

    int max = 0;
    int maxi = 0;

    cout << "Vpisi velikost sklada: ";
    cin >> max;

    cout << "Vpisi dolzino vrste: ";
    cin >> maxi;

    system("cls");

    int* sklad = new int[max];
    int vrh = 0;

    int* vrsta = new int[maxi];
    int glava = 0;
    int rep = 0;

    do {
        menu();
        cin >> izbira;
        switch (izbira) {
        case 1:
            push(sklad, vrh, max);
            break;
        case 2:
            pop(sklad, vrh);
            break;
        case 3:
            izpisi(sklad, vrh);
            break;
        case 4:
            vpisi(vrsta, rep, glava, maxi);
            break;
        case 5:
            beri(vrsta, rep, glava, maxi);
            break;
        case 6:
            izpis(vrsta, rep, glava, maxi);
            break;
        case 7:
            running = false;
            break;
        default:
            cout << "Narobe izbira!" << endl;
            break;
        }
    } while (running);

    return 0;
}



