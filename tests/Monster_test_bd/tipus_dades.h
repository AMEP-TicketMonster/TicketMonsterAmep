#pragma once

#include <string>

struct Usuari {
    std::string nom;
    std::string cognom;
    std::string contrasenya;
    std::string email;

    bool operator==(const Usuari& other) const {
        return nom == other.nom &&
            cognom == other.cognom &&
            contrasenya == other.contrasenya &&
            email == other.email;
    }

    bool operator!=(const Usuari& other) const {
        return !(*this == other);
    }
};

struct Sala {
    std::string nom;
    std::string ciutat;
    std::string capacitat;

    bool operator==(const Sala& other) const {
        return nom == other.nom &&
            ciutat == other.ciutat &&
            capacitat == other.capacitat;
    }

    bool operator!=(const Sala& other) const {
        return !(*this == other);
    }
};