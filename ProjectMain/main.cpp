/**
 * \file main.cpp
 * \brief Fichier principal du programme , permet de créer le nombre souhaité des joueurs et d'entraineurs tout en vérifiant
 *        le format de leur information.
 * \author Fares Majdoub
 * \date 2023-11-28
 */
#include <iostream>
#include <sstream>
#include <string>
#include "Annuaire.h"
#include "Personne.h"
#include "Entraineur.h"
#include "validationFormat.h"
#include "Joueur.h"
#include "Date.h"

using namespace std;
using namespace hockey;

int main() {

    // Entrée du nom du club - Que des lettres et non vide

    cout << "|--Bienvenue à l'outil d'ajout d'une personne!--|"<<endl;
    string nomClub;
    cout << "Entrez le nom du club: " << endl;
    char buffer[256];
    cin.getline(buffer, 255);
    nomClub = buffer;

    // Vérification du format du nom 

    while (nomClub.empty() || !util::validerFormatNom(nomClub)) {
        cout << "Nom de club invalide. Veuillez entrer un nom valide : "<<endl;
        cin.getline(buffer, 255);
        nomClub = buffer;
    }

    Annuaire annuaire(nomClub); // Ajout du nom du club a l'annuaire

    // Le programme commence avec une boucle qui crée au moins un joueur avant de passer au(x) entraineur(s)
    
    while (true){
       
        // Entrée du nom du joueur

        string nom, prenom, telephone, position;
        cout << "-Entrez le nom du joueur: "<<endl;
        char buffer[256];
        cin.getline(buffer, 255);
        nom = buffer;
        util::convertirMaj(nom);
        // Vérification du format du nom

        while (!util::validerFormatNom(nom)) {
            cout << "Le nom de la personne ne doit comporter que des lettres" << endl;
            cout << "-Entrez le nom du joueur: "<<endl;
            cin.getline(buffer, 255);
            nom = buffer;
            util::convertirMaj(nom);}
       
        // Entrée du prenom du joueur

        cout << "-Entrez le prenom du joueur: "<<endl;
        cin.getline(buffer, 255);
        prenom = buffer;
        util::convertirMaj(prenom);

        // Vérification du format du prénom du joueur

        while (!util::validerFormatNom(prenom)) {
            cout << "!--Le prenom de la personne ne doit comporter que des lettres--!"<< endl;
            cout << "-Entrez le prenom du joueur: "<<endl;
            cin.getline(buffer, 255);
            prenom = buffer;
            util::convertirMaj(prenom);
        }

        // Entrée du numéro de téléphone du joueur

        cout << "-Entrez le numéro de téléphone du joueur: "<<endl;
        cin.getline(buffer, 255);
        telephone = buffer;

        // Vérification du numéro de téléphone du joueur

        while (!util::validerFormatTelephone(telephone)) {
            cout << "!--Le numéro de téléphone doit avoir un format valide--!"<< endl;
            cout << "-Entrez le numéro de téléphone du joueur: "<<endl;
            cin.getline(buffer, 255);
            telephone = buffer;
        }

        // Entrée de la date de naissance du joueur

        int jourNaissance, moisNaissance, anneeNaissance;
        util::Date dateActuelle;
        int ageJoueur;
    
        while (true) {
            cout << "Veuillez entrer le jour [1...31] : ";
            cin >> jourNaissance;
            cout << "Veuillez entrer le mois [1...12] : ";
            cin >> moisNaissance;
            cout << "Veuillez entrer l'année [1970...] : ";
            cin >> anneeNaissance;

            // Vérification de l'age du joueur : entre 15 et 17 ans

            util::Date dateNaissanceJoueur(jourNaissance, moisNaissance, anneeNaissance);
            ageJoueur = dateActuelle.reqAnnee() - dateNaissanceJoueur.reqAnnee();
            if (dateNaissanceJoueur.reqMois() > dateActuelle.reqMois() ||
                (dateNaissanceJoueur.reqMois() == dateActuelle.reqMois() && dateNaissanceJoueur.reqJour() > dateActuelle.reqJour())) {
                ageJoueur--;
            }

            if (ageJoueur >= 15 && ageJoueur <= 17) {
                break;
           } else {
                cout << "!--Date invalide, le joueur doit être agé entre 15 et 17 ans--!"<< endl;
            }
        }

        // Entrée de la position du joueur

        cout << "-Entrez la position du joueur: "<<endl;
        cin.ignore();
        cin.getline(buffer, 255);
        position = buffer;
        util::convertirMaj(position);
        
        // Vérification de la position du joueur

        while (!(position == "CENTRE" || position == "AILIER" || position == "DEFENSEUR" || position == "GARDIEN")) {
           cout << "!--La position du joueur est invalide--!" << endl;
            cout << "-Entrez la position du joueur: "<<endl;
            cin.getline(buffer, 255);
            position = buffer;
            util::convertirMaj(position);
        }

        // Création de l'objet Joueur

        hockey::Joueur joueur(nom, prenom, util::Date(jourNaissance, moisNaissance, anneeNaissance), telephone, position);
        annuaire.ajouterPersonne(joueur); // Ajout a l'annuaire

        string choix2; 
        cout << "Voulez vous ajouter un autre joueur?(oui/non) " <<endl;
        cin.getline(buffer, 255);
        choix2 = buffer;

        if (choix2 =="oui" || choix2 == "Oui" || choix2 == "OUI" ){

            continue;

          }while(choix2 =="non"|| choix2 == "Non" || choix2 == "NON" ){

              // Entrée du nom de l'entraineur

              string nom_ent, prenom_ent, telephone_ent, RAMQ_ent;
              int jourNaissance_ent, moisNaissance_ent, anneeNaissance_ent;
              char sexe;
              util::Date dateActuelle;
              int ageEntraineur;
   
              
              cout << "-Entrez le nom de l'entraineur: "<<endl;
              cin.getline(buffer, 255);
              nom_ent = buffer;
              util::convertirMaj(nom_ent);

              //Vérification du format du nom de l'entraineur

              while (!util::validerFormatNom(nom_ent)) {
                  cout << "Le nom de l'entraineur ne doit comporter que des lettres"<< endl;
                  cout << "-Entrez le nom de l'entraineur: "<<endl;
                  cin.getline(buffer, 255);
                  nom_ent = buffer;
                  util::convertirMaj(nom_ent);
              }
          
              // Entrée du prenom de l'entraineur

              cout << "-Entrez le prenom de l'entraineur: "<<endl;
              cin.getline(buffer, 255);
              prenom_ent = buffer;
              util::convertirMaj(prenom_ent);

              //Vérification du format du prenom de l'entraineur
          
              while (!util::validerFormatNom(prenom_ent)) {
                  cout << "!--Le prenom de l'entraineur ne doit comporter que des lettres--!"<<endl;
                  cout << "-Entrez le prenom de l'entraineur: "<<endl;
                  cin.getline(buffer, 255);
                  prenom_ent = buffer;
                  util::convertirMaj(prenom_ent);
              }

              // Entrée du numéro de téléphone de l'entraineur

              cout << "-Entrez le numéro de téléphone de l'entraineur: "<<endl;
              cin.getline(buffer, 255);
              telephone_ent = buffer;

              // Vérification du numéro de téléphone de l'entraineur

              while (!util::validerFormatTelephone(telephone_ent)) {
                  cout << "!--Le numéro de téléphone doit avoir un format valide--!"<<endl;
                  cout << "-Entrez le numéro de téléphone de l'entraineur: "<<endl;
                  cin.getline(buffer, 255);
                  telephone_ent = buffer;
              }

             // Entrée de la date de naissance de l'entraineur

              cout << endl << "-Entrez la date de naissance de l'entraineur: "<<endl;
              while (true) {
                  cout << "Veuillez entrer le jour [1...31] : ";
                  cin >> jourNaissance_ent;
                  cout << "Veuillez entrer le mois [1...12] : ";
                  cin >> moisNaissance_ent;
                  cout << "Veuillez entrer l'année [1970...] : ";
                  cin >> anneeNaissance_ent;
         
                      // Création d'une date pour la naissance de l'entraineur
                  util::Date dateNaissanceEntraineur(jourNaissance_ent, moisNaissance_ent, anneeNaissance_ent);
    
                 

                  // Calculer l'âge de l'entraineur
                  int ageEntraineur = dateActuelle.reqAnnee() - dateNaissanceEntraineur.reqAnnee();
                  if (dateNaissanceEntraineur.reqMois() > dateActuelle.reqMois() ||
                      (dateNaissanceEntraineur.reqMois() == dateActuelle.reqMois() && dateNaissanceEntraineur.reqJour() > dateActuelle.reqJour())) {
                      ageEntraineur--;
                  }

                  if (ageEntraineur >= 18) {
                      break; // L'entraineur est majeur, sortir de la boucle
                  } else {
                      cout << "!--Date invalide, l'entraineur doit etre majeur--!"<<endl;
                  }
                            }

              // Entrée du sexe de l'entraineur 

              cout << "-Entrez le sexe de l'entraineur (M ou F): "<<endl;
              cin.ignore();
              cin >> sexe;

              // Validation du sexe

              while (sexe != 'M' && sexe != 'F') {
                  cout << "!--Le sexe entré est invalide--!"<<endl;
                  cout << "-Entrez le sexe de l'entraineur (M ou F): "<<endl;
                  cin.ignore();
                 cin >> sexe;
              }

              // Entrée du numéro de RAMQ

              cout << endl << "-Entrez le numéro de RAMQ de l'entraineur: "<<endl;
              cin.ignore();
              cin.getline(buffer, 255);
              RAMQ_ent = buffer;
              // Vérification num RAMQ

              while (!util::validerFormatNumRAMQ(RAMQ_ent, nom_ent, prenom_ent, jourNaissance_ent, moisNaissance_ent, anneeNaissance_ent, sexe)) {
                  cout << "!--Le numéro de RAMQ est invalide--!"<<endl;
                  cout << "-Entrez le numéro de RAMQ de l'entraineur: "<<endl;
                  cin.getline(buffer, 255);
                  RAMQ_ent = buffer;
              }

              // Création de l'objet entraineur
              util::Date dateNaissanceEntraineur(jourNaissance_ent, moisNaissance_ent, anneeNaissance_ent);

              hockey::Entraineur entraineur(nom_ent, prenom_ent, dateNaissanceEntraineur, telephone_ent, RAMQ_ent, sexe);
              annuaire.ajouterPersonne(entraineur);

              string choix3;
              cout << "Voulez vous ajouter un autre entraineur (oui/non)? " <<endl;
              cin.getline(buffer, 255);
              choix3 = buffer;

              if (choix3 =="oui" || choix3 == "Oui" || choix3 == "OUI" ){
                    continue;}

              else
                    {cout <<  annuaire.reqAnnuaireFormate() << endl; // Affichage de l'annuaire vers la fin
                    break;} 
                }
        break;

}
return 0;

}
