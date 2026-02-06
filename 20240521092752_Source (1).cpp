
#include <iostream>
#include <locale.h>
#include <string>
#include <map>
#include <iterator>
#include <algorithm>
using namespace std;

class Produit {
private:
    string nom;
    double prix;

public:
    // Constructeur par défaut
    Produit()
    {
        nom = "sans-nom";
        prix = 0.0;
    }

    // Constructeur avec nom et prix
    Produit(string n, double p)
    {
        nom=n ;
        prix=p;
    }

    // Méthodes get
    string get_nom() const { return nom; }
    double get_prix() const { return prix; }

    // Méthode afficher
    void afficher() const {
        cout << "Nom: " << nom << ", Prix: " << prix <<"$"<< endl;
    }
};

class Inventaire {
private:
    map<string, double> produits;

public:
    // Constructeur par défaut
    Inventaire() {
        produits = {
            {"Cafe noir", 10.99},
            {"The vert", 4.55},
            {"Jus d'orange", 5.89},
            {"Pain complet", 4.59},
            {"Lait ecreme", 10.88},
            {"Pommes rouges", 2.44},
            {"Poisson frais", 14.90},
            {"Chips salees", 3.12},
            {"Beurre doux", 5.88},
            {"Miel naturel", 4.89},
            {"Riz blanc", 10.22},
            {"Sauce tomate", 3.12}
        };
    }

    // Fonction contient_produit avec un nom de produit en paramètre
    bool contient_produit(const  string& nom_produit) {
      //  return produits.find(nom_produit) != produits.end();
        auto iterm = produits.find(nom_produit);
        if (iterm != produits.end())
        {
            return true;   //ok modification
        }

    }

    // Fonction contient_produit avec un objet Produit en paramètre
    bool contient_produit(const Produit& produit) {
        return contient_produit(produit.get_nom());
    }
    // Fonction ajouter_produit avec un nom de produit et un prix en paramètres
    void ajouter_produit(const string& nom_produit, double prix) {
        if (contient_produit(nom_produit)==true) {
            cout << "Le produit \"" << nom_produit << "\" est déjà dans l'inventaire." << endl;
        }
        else {
            produits[nom_produit] = prix;
        }
    }

    // Fonction ajouter_produit avec un objet Produit en paramètre
    void ajouter_produit(const Produit& produit) {
        ajouter_produit(produit.get_nom(), produit.get_prix());
    }
    // Fonction modifier_prix avec un nom de produit et un prix en paramètres
    void modifier_prix(const string& nom_produit, double nouveau_prix) {
        if (contient_produit(nom_produit)==false) {
            cout << "Le produit \"" << nom_produit << "\" n'est pas dans l'inventaire." << endl;
        }
        else {
            produits[nom_produit] = nouveau_prix;
        }
    }

    // Fonction modifier_prix avec un objet Produit en paramètre
    void modifier_prix(const Produit& produit) {
        modifier_prix(produit.get_nom(), produit.get_prix());
    }
    // Fonction obtenir_prix avec un nom de produit en paramètre
    double obtenir_prix(const string& nom_produit) {
        if (contient_produit(nom_produit)==true) {
            return produits[nom_produit];
        }
        else {
            return -1;
        }
    }

    // Fonction obtenir_prix avec un objet Produit en paramètre
    double obtenir_prix(const Produit& produit) {
        return obtenir_prix(produit.get_nom());
    }
    // Fonction supprimer_produit avec un nom de produit en paramètre
    void supprimer_produit(const string& nom_produit) {
        if (contient_produit(nom_produit)==true) {
            produits.erase(nom_produit);
        }
        else {
            cout << "Le produit \"" << nom_produit << "\" n'est pas dans l'inventaire." << endl;
        }
    }

    // Fonction supprimer_produit avec un objet Produit en paramètre
    void supprimer_produit(const Produit& produit) {
        supprimer_produit(produit.get_nom());
    }
    // Fonction afficher
    void afficher() const {
        cout << "Inventaire:" << endl;
        for (const auto& p : produits) {
            cout << "Nom: " << p.first << ", Prix: " << p.second << endl;
        }
    }

};
int main() {
    setlocale(LC_ALL, "");

    // 1) Créer un inventaire nommé armoire
    Inventaire armoire;
    // 2) Ajouter un article en utilisant le string "gomme" et le prix 1.50
    armoire.ajouter_produit("gomme", 1.50);
    // 3) Afficher l'armoire
    armoire.afficher();
    cout << endl;
    // 4) Créer un Produit kiwi à 0.56$
    Produit kiwi("kiwi", 0.56);
    // 5) Ajouter l'objet kiwi à l'armoire
    armoire.ajouter_produit(kiwi);
    // 6) Afficher l'armoire
    armoire.afficher();
    cout << endl;
    // 7) Créer un Produit Pommes rouges qui coûte 3.44$ et l'ajouter à l'armoire. Il ne devrait pas s'ajouter.
    Produit pommes_rouges("Pommes rouges", 3.44);
    armoire.ajouter_produit(pommes_rouges);
    // 8) Obtenir et afficher le prix de la sauce tomate (les 2 méthodes)
    cout << "Prix de la sauce tomate (avec nom) : " << armoire.obtenir_prix("Sauce tomate") << endl;
    Produit sauce_tomate("Sauce tomate", 0.0); // Le prix n'est pas important ici
    cout << "Prix de la sauce tomate (avec objet) : " << armoire.obtenir_prix(sauce_tomate) << endl;
    cout << endl;
    // 9) Modifier le prix du beurre pour le mettre à 8$ avec l'une des méthodes
    armoire.modifier_prix("Beurre doux", 8.00);
    // 10) Modifier le prix des chips pour 4.56$ avec l'autre méthode
    Produit chips("Chips salees", 4.56);
    armoire.modifier_prix(chips);

    // 11) Enlever le lait écrémé de l'armoire avec la méthode de votre choix
    armoire.supprimer_produit("Lait ecreme");

    // 12) Essayer d'enlever le lait écrémé avec l'autre méthode. Vous devriez avoir un message qui avertit que le produit n'existe pas.
    Produit lait_ecreme("Lait ecreme", 0.0); // Le prix n'est pas important ici
    armoire.supprimer_produit(lait_ecreme);

    // 13) Afficher l'armoire
    armoire.afficher();
}