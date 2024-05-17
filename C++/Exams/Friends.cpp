#include <bits/stdc++.h>
using namespace std;

class Character {
private:
  string name;
  string ocupation;

public:
  Character(string n, string o) : name(n), ocupation(o){};

  string getName() { return name; }

  string getOcupation() { return ocupation; }
};

class CharacterDatabase {
public:
  CharacterDatabase() {}

  void add(Character c) {
    ofstream out("database.txt", ios::app);

    out << c.getName() << "   " << c.getOcupation() << "\n";

    out.close();
  }

  void del(string name) {
    ifstream in("database.txt", ios::app);
    ofstream out("outfile.txt", ios::app);
    string line;

    while (getline(in, line)) {
      if (line.substr(0, name.size()) != name) {
        out << line << "\n";
      }
    }
    in.close();
    out.close();
    remove("database.txt");
    rename("outfile.txt", "database.txt");
  }

  string search(string name) {
    ifstream in("database.txt");
    string line;

    while (getline(in, line)) {
      if (line.substr(0, name.size()) == name) {
        return line;
      }
    };
    return "Not fund!";
  }

  void edit(string name, string ocupationNew) {
    if (this->search(name) == "Not found!") {
      cout << search(name);
    } else {
      Character c(name, ocupationNew);
      this->del(name);
      this->add(c);
    }
  }

  void relate(Character c1, Character c2, string relation) {
    Character r(c1.getName() + " " + c2.getName(), relation);
    this->add(r);
  }

  void expose() {
    ifstream in("database.txt");
    string line;

    while (getline(in, line)) {
      cout << line << "\n";
    }
  }
};

int main() {
  CharacterDatabase db;
  Character c1 = Character("Rachel Green", "Garçonete");
  Character c2 = Character("Monica Geller", "Chef");
  Character c3 = Character("Phoebe Buffay", "Massagista");
  Character c4 = Character("Chandler Bing", "Desconhecido");
  Character c5 = Character("Ross Geller", "Professor");
  Character c6 = Character("Joey Tribbiani", "Ator");

  db.add(c1);
  db.add(c2);
  db.add(c3);
  db.add(c4);
  db.add(c5);
  db.add(c6);
  db.edit("Rachel Green", "Design de Moda");

  cout << db.search("Ghouter") << endl;
  cout << db.search("Rachel Green") << endl;

  db.relate(c2, c5, "irmãos");
  db.relate(c2, c4, "casados");
  db.relate(c1, c2, "roommates");
  db.relate(c4, c6, "roommates");

  db.del("Phoebe Buffay");

  db.expose();
};
