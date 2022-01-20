#pragma once
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include <memory>
#include <sstream>

#include "Salle.h"
#include "Affichable.h"
#include "Carte.h"
#include "POINTS_CARDINAUX.h"

using namespace std;


class Jeu {
public:
	Jeu(const shared_ptr<Salle> salleDebut, const shared_ptr<Salle> salleCachee);
	~Jeu() = default;

	void deplacer(char direction);

	void lireCommande(const string& commande);

	void look(const string& commande);

	void use(const string& commande);
	
	void activerSalleR(shared_ptr<Objet> objet);

	void activerObjet(shared_ptr<Objet> objet);

	void lancerJeu();

private:
	shared_ptr<Salle> salleActuelle_;
	weak_ptr<Salle> salleCachee_;
	bool enJeu_ = true;
};