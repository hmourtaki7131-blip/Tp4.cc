#include <iostream>
#include <string>
using namespace std;

// Classe Universite
class Universite {
private:
    string nom;

public:
    Universite(string n) : nom(n) {}

    void afficherNom() const {
        cout << "Universite: " << nom << endl;
    }
};

// Classe Etudiant
class Etudiant {
private:
    string nom;
    int age;
    Universite* universite;

    static int nbEtudiants;

public:
    // Constructeur
    Etudiant(string n, int a, Universite* u)
        : nom(n), age(a), universite(u) {
        nbEtudiants++;
    }

    // Afficher les informations
    void afficher() const {
        cout << "Nom: " << nom << endl;
        cout << "Age: " << age << endl;

        if (universite != nullptr) {
            universite->afficherNom();
        }

        cout << "------------------" << endl;
    }

    // Methode statique
    static void afficherTotal() {
        cout << "Nombre total d'etudiants: "
             << nbEtudiants << endl;
    }
};

// Initialisation du compteur
int Etudiant::nbEtudiants = 0;

int main() {
    Universite u("Universite de Casablanca");

    Etudiant e1("Amine", 20, &u);
    Etudiant e2("Sara", 21, &u);

    e1.afficher();
    e2.afficher();

    Etudiant::afficherTotal();

    return 0;
}