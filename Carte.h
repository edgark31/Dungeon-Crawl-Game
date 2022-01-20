#pragma once
#include <iostream>
#include <algorithm>
#include <memory>
#include <functional>
#include <map>

#include "Salle.h"


using namespace std;

class Carte
{
public:
    Carte() = default;
    ~Carte() = default;

    unsigned size() const;
    shared_ptr<Salle> getSalle(string nomSalle);
   
    void setSalle(string nomSalle, shared_ptr<Salle> salle);
    
    void eraseSalle(string nomSalle);

private:
    inline static map<string, shared_ptr<Salle>> carte_;
    friend class Jeu;
};