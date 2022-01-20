/**
* Classe qui représente une salle avec ses getters, setters & méthodes.
* \file   Salle.cpp
* \author Edgar Kappauf
* \date   21 décembre 2021
* Créé le 21 décembre 2021
*/
#pragma once
#include <iostream>
#include <string>
#include <memory>
#include <map>

#include "Salle.h"

using namespace std;

Salle::Salle(const string& nom, const string& description) : nom_(nom), description_(description) {}

const string& Salle::getNom() const { return nom_; }
const string& Salle::getDescription() const { return description_; }
weak_ptr<Salle> Salle::getConnexion(char direction) { return connexions_[direction]; }
map<string, shared_ptr<Objet>> Salle::getObjets() { return objets_; }

void Salle::setConnexion(weak_ptr<Salle> nouvelleSalle, char direction) { connexions_[direction] = nouvelleSalle; }
void Salle::setConnexions(weak_ptr<Salle> salleA, char directionA, weak_ptr<Salle> salleB, char directionB) {
	connexions_[directionA] = salleA;
	salleA.lock()->setConnexion(salleB, directionB);
}
void Salle::setObjet(shared_ptr<Objet> objet) { objets_[objet->getNom()] = objet; }

void Salle::afficher(ostream& os) const {
	os << "-- " << nom_ << " --" << endl;
	os << description_ << endl;
	if (!objets_.empty()) {
		os << "Vous remarquez : " << endl;
		for (auto [nom, objet] : objets_)
			os << "\t" << nom << endl;
	}
	for (auto [direction, salle] : connexions_) {
		if (salle.lock() != nullptr) {
			os << salle.lock()->nom_; 
			if (direction == 'N' or direction == 'S')
				os << " est au ";
			else
				os << " est à l'";
			os << POINTS_CARDINAUX[direction] << " (" << direction << ")" << endl;
		}
	}
}