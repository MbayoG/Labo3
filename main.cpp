/*
-----------------------------------------------------------------------------------
Laboratoire : 03
Nom du fichier : main.ccp
Auteur(s) : -
Date creation : -
But : Attend qu'un utilisateur entre un montant, l'affiche puis fait appel à la fonction montant en vaudois en plaçant
 		cemontant en paramètre.
Remarque(s) : /
Compilateur : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

extern string montantEnVaudois(long double montant);

int main() {
    long double d;

    while (cin >> d) { // finir par EOF (Ctrl-D) ou autre chose qu'un nombre
        cout << fixed << setprecision(2) << d << endl // arrondi different de celui de la fonction demandee
             << montantEnVaudois(d) << endl;
    }

    return 0;
}