/*
-----------------------------------------------------------------------------------
Laboratoire : 03
Nom du fichier : montantEnVaudois.ccp
Auteur(s) : Ilan Ruiz De Porras, Felipe Alvarez, Gulain Mbayo
Date creation : 29.10.2020
But : Un utilisateur entre un nombre comprise entre 0 et 999999999999999.99. Le programe control si le nombre correspond
 		à ce critère, puis le divise en groupe de trois chiffres (deux pour ceux après la virgule), puis les convertit
 		dans leur version litéraire.
Remarque(s) : /
Compilateur : Mingw-w64 g++ 8.1.0
-----------------------------------------------------------------------------------
*/
#include <string>
#include <iostream>
#include <iomanip>
#include <cmath>
#include <limits>

using namespace std;

//fct 1
/* nom: separateurParTriplets
 * but: Reçoit un nombre entre 0 et 999999999999999.99 et le décompose par triplets de 10 puissance 3.
 *      Renvoie chaque triplet dans des variables déclarées dans la fonction montantEnVaudois.
 * paramètres: long double montant, int& nb1, int& nb2, int& nb3, int& nb4, int& nb5, int& nb6
 */
void separateurParTriplets(long double &montant, int &nb1, int &nb2, int &nb3, int &nb4, int &nb5, int &nb6) {
    long long montantEnLong = floor(montant);

    //Arrondie pour les centimes
    nb6 = (montant - floor(montant)) * 1000;
    if (nb6 % 10 >= 5) {
        nb6 = nb6 / 10 + 1;
    } else {
        nb6 = nb6 / 10;
    }

    if (nb6 >= 100) {
        montant += nb6 / 100;
        montantEnLong += nb6 / 100;
        nb6 = nb6 % 100;
    }

    nb5 = montantEnLong % 1000;    //centaine
    nb4 = montantEnLong / 1000 % 1000;    //millier
    nb3 = montantEnLong / 1000000 % 1000;    //etc...
    nb2 = montantEnLong / 1000000000 % 1000;
    nb1 = montantEnLong / 1000000000000 % 1000;


}

//fct 3
/* nom: convertisseurChiffreEnLettre
 * but: Prend chaque chiffre reçu et retourne sa version écrite en tenant compte de s'il sagit d'une
 *      unité, dizaine, etc.. grâce à un flag.
 * paramètre: int chiffre, flag
 */
string convertisseurChiffreEnLettres(int triplet, bool flagcentaine) {
    string resultat;
    int centaine, dizaine, unite;

    centaine = triplet / 100;
    dizaine = triplet / 10 % 10;
    unite = triplet % 10;

    switch (centaine) //Ecriture des centaines
    {
        case 1:
            resultat = "";
            break;
        case 2:
            resultat = "deux-";
            break;
        case 3:
            resultat = "trois-";
            break;
        case 4:
            resultat = "quatre-";
            break;
        case 5:
            resultat = "cinq-";
            break;
        case 6:
            resultat = "six-";
            break;
        case 7:
            resultat = "sept-";
            break;
        case 8:
            resultat = "huit-";
            break;
        case 9:
            resultat = "neuf-";
            break;
        case 0:
            resultat = "";
            break;
        default:
            resultat += "";
    }
    //Testes pour les cas particuliers
    if (centaine && flagcentaine && !dizaine && !unite && centaine != 1) {
        resultat += "cents";
    } else if (centaine) {
        resultat += "cent";
    }
    if ((dizaine || unite) && centaine) {
        resultat += "-";
    }

    switch (dizaine) //Ecriture des dizaines
    {
        case 1:
            if (unite >= 1 && unite <= 6) {
                switch (unite) {
                    case 1:
                        resultat += "onze";
                        break;
                    case 2:
                        resultat += "douze";
                        break;
                    case 3:
                        resultat += "treize";
                        break;
                    case 4:
                        resultat += "quatorze";
                        break;
                    case 5:
                        resultat += "quinze";
                        break;
                    case 6:
                        resultat += "seize";
                        break;
                    default:
                        resultat += "";
                }
            } else {
                resultat += "dix";
            }
            break;
        case 2:
            resultat += "vingt";
            break;
        case 3:
            resultat += "trente";
            break;
        case 4:
            resultat += "quarante";
            break;
        case 5:
            resultat += "cinquante";
            break;
        case 6:
            resultat += "soixante";
            break;
        case 7:
            resultat += "septante";
            break;
        case 8:
            resultat += "huitante";
            break;
        case 9:
            resultat += "nonante";
            break;
        case 0:
            resultat += "";
            break;
        default:
            resultat += "";
    }

   //Testes pour les cas particuliers
    if (dizaine > 1 && unite == 1) {
        resultat += "-et";
    }
    if (dizaine != 1 || unite > 6) {
        if ((dizaine || centaine) && unite) {
            resultat += "-";
        }
        switch (unite) //Ecriture des unitees
        {
            case 1:
                resultat += "un";
                break;
            case 2:
                resultat += "deux";
                break;
            case 3:
                resultat += "trois";
                break;
            case 4:
                resultat += "quatre";
                break;
            case 5:
                resultat += "cinq";
                break;
            case 6:
                resultat += "six";
                break;
            case 7:
                resultat += "sept";
                break;
            case 8:
                resultat += "huit";
                break;
            case 9:
                resultat += "neuf";
                break;
            case 0:
                resultat += "";
                break;
            default:
                resultat += "";
        }
    }
    return resultat;
}

string montantEnVaudois(long double montant) {
    if (montant < 0) return "erreur : montant negatif";
    if (montant > 999999999999999.99) return "erreur : montant trop grand";
    string resultat, unite;
    int nb1 = 0, nb2 = 0, nb3 = 0, nb4 = 0, nb5 = 0, nb6 = 0;
    bool flagcentaine = true;

    //Appel de La fct SeparateurParTriplet
    separateurParTriplets(montant, nb1, nb2, nb3, nb4, nb5, nb6);


    if (floor(montant) == 1) {
        unite = " franc";
    } else if (!floor(montant)) {
        unite = "";
    } else {
        unite = " francs"; // Pour changer en euros facilement  PS : laisser un espace avant l'unité merci ^^
    }
    if ((!montant)) {
        unite = "zero franc";
    }

   //Ajout des unite mille, million, etc... jusqua billion
    resultat += convertisseurChiffreEnLettres(nb1, flagcentaine);
    if (nb1 == 0) {
        resultat += "";
    } else {
        if (nb1 == 1) {
            resultat += " billion";
        } else {
            resultat += "-billions";
        }
        if (nb2 || nb3 || nb4 || nb5) {
            resultat += "-";
        }
    }
    resultat += convertisseurChiffreEnLettres(nb2, flagcentaine);
    if (nb2 == 0) {
        resultat += "";
    } else {
        resultat += "-milliards";
        if (nb3 || nb4 || nb5) {
            resultat += "-";
        }
    }
    resultat += convertisseurChiffreEnLettres(nb3, flagcentaine);
    if (nb3 == 0) {
        resultat += "";
    } else {
        resultat += "-millions";
        if (nb4 || nb5) {
            resultat += "-";
        }
    }
    flagcentaine = false;
    if (nb4 == 1) {
        if (!nb1 && !nb2 && !nb3) {
            resultat += "-";
        }
        resultat += "mille";
        if (nb5) {
            resultat += "-";
        }
    } else {
        resultat += convertisseurChiffreEnLettres(nb4, flagcentaine);
        if (nb4 == 0) {
            resultat += "";
        } else {
            resultat += "-mille";
            if (nb5) {
                resultat += "-";
            }
        }
    }

    flagcentaine = true;
    resultat += convertisseurChiffreEnLettres(nb5, flagcentaine);

    //Cas particulier
    if ((nb1 || nb2 || nb3) && nb4 == 0 && nb5 == 0) {
        resultat += " de";
    }

    resultat += unite;
    if (nb6 == 0 || !floor(montant)) {
        resultat += "";
    } else {
        resultat += " et ";
    }
    resultat += convertisseurChiffreEnLettres(nb6, flagcentaine);

    //Ecriture des centimes
    if (nb6 == 0) {
        resultat += "";
    } else {
        if (nb6 == 1) {
            resultat += " centime";
        } else {
            resultat += " centimes";
        }
    }

    return resultat;
}

