# STRUCTURES-DE-DONNEES
## Description du projet
Gestion complète d'un inventaire magasin avec surcharge de méthodes et P.O.O stricte.
### Fonctionnalités
| Méthode             | Surcharge               | Comportement                                            |
| ------------------- | ----------------------- | ------------------------------------------------------- |
| contient_produit()  | string / Produit        |  Vérifie existence produit → true/false               |
| ajouter_produit()   | string,double / Produit |  Ajoute OU avertit "déjà existant"                     |
| modifier_prix()     | string,double / Produit |  Met à jour OU "inexistant"                           |
| obtenir_prix()      | string / Produit        |  Retourne prix OU -1 (absent)                         |
| supprimer_produit() | string / Produit        |  Supprime OU "inexistant" (utilise contient_produit) |
| affiche()           | Aucune                  | Liste complète inventaire ligne par ligne            |

CRÉER LE PROJET 15 MARS 2024
CRÉER LE GITHUB 06 FEVRIER 2026
