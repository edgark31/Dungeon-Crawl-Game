/**
* Classe qui sert au déroulement du jeu.
* \file   Jeu.cpp
* \author Edgar Kappauf
* \date   21 décembre 2021
* Créé le 21 décembre 2021
*/
#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <memory>
#include <sstream>

#include "Jeu.h"

using namespace std;
//using std::lock;

Jeu::Jeu(const shared_ptr<Salle> salleDebut, const shared_ptr<Salle> salleCachee) : salleActuelle_(salleDebut), salleCachee_(salleCachee) {}

void Jeu::deplacer(char direction) {
	if (salleActuelle_->getConnexion(direction).lock() == nullptr)
		throw domain_error("On ne peut pas aller là.");
	cout << "On avance";
	if (direction == 'N' or direction == 'S')
		cout << " au ";
	else
		cout << " à l'";
	cout << POINTS_CARDINAUX[direction] << "...\n\n";

	salleActuelle_ = salleActuelle_->getConnexion(direction).lock();
	salleActuelle_->afficher(cout);
}

void Jeu::lireCommande(const string& commande) {
	if (commande.size() == 1)
		deplacer(commande[0]);
	else if (commande.starts_with("look")) {
		look(commande);
	}
	else if (commande.starts_with("use")) {
		use(commande);
	}
	else if (commande == "exit") {
		cout << "Ok la partie est finie, au revoir!" << endl;
		enJeu_ = false;
	}
	else
		throw invalid_argument("Commande invalide");
}

void Jeu::look(const string& commande) {
	if (commande == "look")
		salleActuelle_->afficher(cout);
	else if (commande.starts_with("look")) {
		auto objets = salleActuelle_->getObjets();
		for (auto [nom, objet] : objets) {
			string mot;
			stringstream ss(nom);
			while (ss >> mot) {
				if (commande.find(mot) != string::npos) {
					cout << objet->getDescription() << endl;
					return;
				}
			}
		}
		throw invalid_argument("Commande invalide");
	}
}

void Jeu::use(const string& commande) {
	if (commande == "use")
		cout << "La commande use doit être utilisée avec un nom d'objet ou un mot-clé." << endl;
	else if (commande.starts_with("use")) {
		auto objets = salleActuelle_->getObjets();
		for (auto [nom, objet] : objets) {
			string mot;
			stringstream ss(nom);
			while (ss >> mot) {
				if (commande.find(mot) != string::npos) {
					cout << objet->getUtiliser() << endl;
					activerSalleR(objet);
					activerObjet(objet);
					return;
				}
			}
		}
		throw invalid_argument("Commande invalide");
	}
}

void Jeu::activerSalleR(shared_ptr<Objet> objet) {
	if (objet->getNom() == "Un bouton rouge") {
		Carte::carte_["Couloir"]->setConnexions(salleCachee_, 'E', Carte::carte_["Couloir"], 'W');
	}
}

void Jeu::activerObjet(shared_ptr<Objet> objet) {
	if (objet->getObjetCache() != nullptr) 
		salleActuelle_->setObjet(objet->getObjetCache());
}

void Jeu::lancerJeu() {
	cout << ">>> " << "SALLES MYSTERIEUSES" << " <<<\n" << endl;
	salleActuelle_->afficher(cout);
	string commande;
	string sousCommande;
	while (enJeu_) {
		cout << "\n> ";
		getline(cin, commande);
		try { lireCommande(commande); }
		catch (domain_error&) { cout << "On ne peut pas aller là." << endl; }
		catch (invalid_argument&) { cout << "Commande invalide." << endl; }
		catch (exception& e) { cout << "Une exception s'est produite : " << e.what() << endl; }
	}
}