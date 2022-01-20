/**
* Classe qui sert à accéder aux salles du jeu sans avoir à naviguer dans celui-ci.
* \file   Carte.cpp
* \author Edgar Kappauf
* \date   21 décembre 2021
* Créé le 21 décembre 2021
*/
#pragma once
#include <iostream>
#include <algorithm>
#include <memory>
#include <functional>
#include <map>

#include "Carte.h"

using namespace std;

unsigned Carte::size() const { return carte_.size(); }
shared_ptr<Salle> Carte::getSalle(string nomSalle) { return carte_[nomSalle]; }

void Carte::setSalle(string nomSalle, shared_ptr<Salle> salle) {
    if (carte_[nomSalle] == nullptr)
        carte_[nomSalle] = salle;
    else
        throw logic_error("Cette salle existe deja");
}

void Carte::eraseSalle(string nomSalle) {
    if (carte_[nomSalle] != nullptr)
        carte_.erase(nomSalle);
    else
        throw logic_error("Cette salle n'existe pas");
}