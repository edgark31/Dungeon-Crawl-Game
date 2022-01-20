/**
* Fichier avec une fonction pour intialiser les donn�es du jeu et une autre pour lancer le jeu.
* \file   IntialiserJeu.cpp
* \author Edgar Kappauf
* \date   21 d�cembre 2021
* Cr�� le 21 d�cembre 2021
*/
#pragma once
#include <iostream>
#include <iomanip>
#include <sstream>
#include <string>
#include <fstream>
#include <cctype>
#include <cmath>
#include <cstdint>
#include <cstdlib>
#include <ctime>
#include <numeric>

#include "bibliotheque_cours.hpp"
#include "verification_allocation.hpp"
#include "Affichable.h"
#include "Salle.h"
#include "Jeu.h"
#include "Carte.h"

void demarrerJeu() {
	//Intialisation des salles et leurs connexions.
	auto entree = make_shared<Salle>("Entree", "Vous �tes dans l'entr�e. Il y a un tapis sur le sol et une paire de chaussures pour homme.");
	auto salon = make_shared<Salle>("Salon", "Vous �tes dans le salon. Il y a un bureau d'ordinateur avec des cam�ras et un �cran bleue. Une t�l�vision et un canap� sont a cot�.");
	auto couloir = make_shared<Salle>("Couloir", "Vous �tes dans le couloir.");
	auto petiteChambre = make_shared<Salle>("Petite Chambre", "Vous �tes dans une petite chambre. Elle n'a rien de sp�cial autre que d'�tre petite.");
	auto cuisine = make_shared<Salle>("Cuisine", "Vous �tes dans la cuisine. Elle est tr�s jaune 'beurre' comme la mode d'une certaine �poque.");
	auto salleR = make_shared<Salle>("Salle R", "C'est une salle �trange avec des murs rouges.");

	entree->setConnexions(salon, 'E', entree, 'W');
	entree->setConnexions(couloir, 'N', entree, 'S');
	couloir->setConnexions(petiteChambre, 'W', couloir, 'E');
	couloir->setConnexions(cuisine, 'N', couloir, 'S');

	//Intialisation des objets et objets cach�s dans leurs salles respectives.
	auto toucheVerte = make_shared<Objet>("Une touche verte", "C'est une touche verte appartenant au piano Yamaha", "Vous touchez la touche verte, elle est dans un mauvais �tat");
	auto piano = make_shared<Objet>("Un piano", "C'est un piano Yamaha d'entr�e de gamme avec 61 touches, �a ressemble � n'importe quoi de pas cher de la fin des ann�es 90s.", "Vous jouez des notes sur le piano, �a ne sonne pas vraiment bien et une touche tombe du piano.", toucheVerte);
	auto boutonRouge = make_shared<Objet>("Un bouton rouge", "C'est un bouton rouge qui semble inutile...", "Vous appuyez sur le bouton, il se passe quelque chose... Il semble qu'une nouvelle salle est connecte au couloir.");
	auto interrupteur = make_shared<Objet>("Un interrupteur", "C'est un interrupteur qui sert � allumer la lumi�re.", "Vous appuyez sur l'interrupteur, la lumi�re s'allume.");
	auto couteau = make_shared<Objet>("Un couteau", "C'est un couteau assez sale et rouill�.", "Vous essayez de ramasser le couteau, vous le jetez imm�diatement apr�s avoir vu le sang qui est dessus.");
	auto tapis = make_shared<Objet>("Un tapis", "C'est un vieux tapis sale.", "Vous secouez le tapis et de la terre tombe de celui-ci.");
	auto paireChaussures = make_shared<Objet>("Une paire de chaussures pour homme", "C'est une paire de chaussures de sport pour homme de taille 40 (taille europ�enne).", "Vous enfilez les chaussures, elles sont un peu petites pour vous.");
	auto fourchette = make_shared<Objet>("Une fourchette", "C'est une fourchette pour manger.", "Vous utilisez la fourchette, elle est assez grande pour votre main.");
	auto oreiller = make_shared<Objet>("Un oreiller", "C'est un oreiller bas de gamme avec de la poussi�re dessus.", "Vous secouez l'oreiller, la poussi�re tombe.");

	entree->setObjet(tapis);
	entree->setObjet(paireChaussures);
	salon->setObjet(piano);
	salon->setObjet(boutonRouge);
	couloir->setObjet(interrupteur);
	salleR->setObjet(couteau);
	cuisine->setObjet(fourchette);
	petiteChambre->setObjet(oreiller);

	//Initialisation de la carte 
	Carte carte;
	carte.setSalle("Entree", entree);
	carte.setSalle("Salon", salon);
	carte.setSalle("Couloir", couloir);
	carte.setSalle("Petite Chambre", petiteChambre);
	carte.setSalle("Cuisine", cuisine);
	carte.setSalle("Salle R", salleR);

	//Initialisation du jeu
	Jeu jeu(entree, salleR);

	//Lancement du jeu
	jeu.lancerJeu();
}
