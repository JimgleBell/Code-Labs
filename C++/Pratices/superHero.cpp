#include <bits/stdc++.h>
using namespace std;

class superPower {
private:
  string name;
  int level;

public:
  string getName() { return name; }

  int getLevel() { return level; }

  superPower(string s, int l) : name(s), level(l) {}
};

class character {
private:
  string name;
  string realName;
  vector<superPower>
      powers; // Warning !! The atribute of the object is an address, so when
              // you copy this you must be carefull about destructors

protected:
  character(string n, string rn) : name(n), realName(rn){};

public:
  bool addPower(superPower &x) {
    if (powers.size() >= 4) {
      return false;
    } else if (powers.size() < 4) {
      powers.push_back(x);
      return true;
    }
  }

  virtual double getTotalPower() {
    double sum = 0;
    for (size_t i = 0; i < powers.size(); i++) {
      sum += powers[i].getLevel();
    }
    return sum;
  }

  string getName() {
    string n = name;
    return n;
  }
};

class superHero : public character {
public:
  superHero(string n, string rn) : character(n, rn) {}

  double getTotalPower() {
    double sum;
    sum = 1.1 * (character::getTotalPower());
    return sum;
  }
};

class superVilain : public character {
private:
  int timeInPrision;

public:
  superVilain(string n, string rn, int t)
      : character(n, rn), timeInPrision(t){};

  double getTotalPower() {
    double sum, bonus = 0.01 * timeInPrision;
    sum = (character::getTotalPower()) * (1 + bonus);
    return sum;
  };
};

class combat {
public:
  string confront(character &x, character &y) {
    if (x.getTotalPower() > y.getTotalPower()) {
      return (x.getName() + " Won the fight !");
    } else if (x.getTotalPower() < y.getTotalPower()) {
      return (y.getName() + " Won the fight !");
    } else if (x.getTotalPower() == y.getTotalPower()) {
      return ("It's a draw !");
    }
  }
};

int main() {

  superPower s1("soltar teia", 3);
  superPower s2("andar em paredes", 2);
  superPower s3("sentido apurado", 1);
  superPower s4("velocidade", 5);
  superPower s5("Voar", 3);
  superPower s6("força", 5);
  superPower s7("visão de raio X", 4);
  superPower s8("sopro congelante", 4);
  superPower s9("supersoldado", 3);
  superPower s10("escudo", 3);
  superPower s11("anel magico", 5);
  superPower s12("armadura", 4);
  superPower s13("dispositivos eletronicos", 2);
  superPower s14("mente aguçada", 5);
  superPower s15("tentáculos indestrutíveis", 5);
  superPower s16("velocidade", 1);

  superHero ha("Homem-Aranha", "Peter Park");
  superHero sh("Super-Homem", "Clark Kent");
  superHero ca("Capitão América", "Steven Rogers");
  superHero fl("Flash", "Barry Allen");
  superHero lv("Lanterna-Verde", "Hal Jordan");
  superHero hf("Homem de Ferro", "Tony Stark");

  superVilain dv("Duende Verde", "Norman Osbourne", 3);
  superVilain ll("Lex Luthor", "Lex Luthor", 5);
  superVilain bi("Bizarro", "Bizarro", 11);
  superVilain oc("Octopus", "Otto Octavius", 4);

  ha.addPower(s1);
  ha.addPower(s2);
  ha.addPower(s3);

  sh.addPower(s5);
  sh.addPower(s6);
  sh.addPower(s7);
  sh.addPower(s8);

  ca.addPower(s9);
  ca.addPower(s10);

  fl.addPower(s4);

  lv.addPower(s11);

  hf.addPower(s12);
  hf.addPower(s13);

  dv.addPower(s6);

  ll.addPower(s14);

  bi.addPower(s5);
  bi.addPower(s6);
  bi.addPower(s7);
  bi.addPower(s8);

  oc.addPower(s15);
  oc.addPower(s16);

  superVilain viloes[4] = {dv, ll, bi, oc};
  superHero herois[6] = {ha, sh, ca, fl, lv, hf};

  for (int i = 0; i < 6; i++)
    for (int j = 0; j < 4; j++) {
      cout << herois[i].getName();
      cout << " X ";
      cout << viloes[j].getName();
      cout << " -> ";

      cout << combat().confront(herois[i], viloes[j]) << endl;
    }

  for (int i = 0; i < 6; i++)
    for (int j = i; j < 6; j++) {
      cout << herois[i].getName();
      cout << " X ";
      cout << herois[j].getName();
      cout << " -> ";

      cout << combat().confront(herois[i], herois[j]) << endl;
    }

  for (int i = 0; i < 4; i++)
    for (int j = i; j < 4; j++) {
      cout << viloes[i].getName();
      cout << " X ";
      cout << viloes[j].getName();
      cout << " -> ";

      cout << combat().confront(viloes[i], viloes[j]) << endl;
    }
}