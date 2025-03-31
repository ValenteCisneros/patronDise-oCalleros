#include <iostream>
#include <memory>
using namespace std;

// Interfaces para los comportamientos
class WeaponBehavior {
public:
    virtual ~WeaponBehavior() = default;
    virtual string attack() const = 0;
};

class MoveBehavior {
public:
    virtual ~MoveBehavior() = default;
    virtual string move() const = 0;
};

// Implementaciones concretas de los comportamientos
class Axe : public WeaponBehavior {
public:
    string attack() const override {
        return "Estoy atacando con un hacha.";
    }
};

class Knife : public WeaponBehavior {
public:
    string attack() const override {
        return "Estoy atacando con un cuchillo.";
    }
};

class Sword : public WeaponBehavior {
public:
    string attack() const override {
        return "Estoy atacando con una espada.";
    }
};

class BowAndArrow : public WeaponBehavior {
public:
    string attack() const override {
        return "Estoy atacando con un arco y flechas.";
    }
};

class LanceAndShield : public WeaponBehavior {
public:
    string attack() const override {
        return "Estoy atacando con una lanza y escudo.";
    }
};

class Run : public MoveBehavior {
public:
    string move() const override {
        return "Estoy corriendo.";
    }
};

class Walk : public MoveBehavior {
public:
    string move() const override {
        return "Estoy caminando.";
    }
};

class SquatWalk : public MoveBehavior {
public:
    string move() const override {
        return "Estoy caminando en cuclillas.";
    }
};

class ChestWalk : public MoveBehavior {
public:
    string move() const override {
        return "Estoy moviéndome pecho tierra.";
    }
};

// Clase base Character
class Character {
protected:
    shared_ptr<WeaponBehavior> weaponBehavior;
    shared_ptr<MoveBehavior> moveBehavior;

public:
    virtual ~Character() = default;

    string performMove() const {
        if (moveBehavior) {
            return moveBehavior->move();
        }
        return "No tengo un comportamiento de movimiento asignado.";
    }

    string performAttack() const {
        if (weaponBehavior) {
            return weaponBehavior->attack();
        }
        return "No tengo un arma asignada.";
    }

    void setMoveBehavior(shared_ptr<MoveBehavior> mb) {
        moveBehavior = mb;
    }

    void setWeaponBehavior(shared_ptr<WeaponBehavior> wb) {
        weaponBehavior = wb;
    }

    virtual string display() const {
        return "Soy un personaje genérico.";
    }
};



int main() {
    Warrior w;
    cout << w.display() << endl;
    cout << w.performMove() << endl;
    cout << w.performAttack() << endl;
    w.setWeaponBehavior(make_shared<Axe>());
    w.setMoveBehavior(make_shared<Walk>());

    cout << "Después de cambiar comportamientos:" << endl;
    cout << w.performMove() << endl;
    cout << w.performAttack() << endl;

    return 0;
}
