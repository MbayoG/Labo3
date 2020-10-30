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