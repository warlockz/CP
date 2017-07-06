



#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Spell { 
    private:
        string scrollName;
    public:
        Spell(): scrollName("") { }
        Spell(string name): scrollName(name) { }
        virtual ~Spell() { }
        string revealScrollName() {
            return scrollName;
        }
};

class Fireball : public Spell { 
    private: int power;
    public:
        Fireball(int power): power(power) { }
        void revealFirepower(){
            cout << "Fireball: " << power << endl;
        }
};

class Frostbite : public Spell {
    private: int power;
    public:
        Frostbite(int power): power(power) { }
        void revealFrostpower(){
            cout << "Frostbite: " << power << endl;
        }
};

class Thunderstorm : public Spell { 
    private: int power;
    public:
        Thunderstorm(int power): power(power) { }
        void revealThunderpower(){
            cout << "Thunderstorm: " << power << endl;
        }
};

class Waterbolt : public Spell { 
    private: int power;
    public:
        Waterbolt(int power): power(power) { }
        void revealWaterpower(){
            cout << "Waterbolt: " << power << endl;
        }
};

class SpellJournal {
    public:
        static string journal;
        static string read() {
            return journal;
        }
}; 
string SpellJournal::journal = "";


void counterspell(Spell *spell) {
  /* Enter your code here */
      auto* p = dynamic_cast<Fireball*>(spell);
    if(p)
    {
    	p->revealFirepower();
    	return;
    }
  	auto* p1 = dynamic_cast<Frostbite*>(spell);
    if(p1)
    {
    	p1->revealFrostpower();
    	return;
    }
   auto* p2 = dynamic_cast<Waterbolt*>(spell);
    if(p2)
    {
    	p2->revealWaterpower();
    	return;
    }
    auto* p3 = dynamic_cast<Thunderstorm*>(spell);
    if(p3)
    {
    	p3->revealThunderpower();
    	return;
    }
	
    string rs = spell->revealScrollName();
    string js = SpellJournal::read();

    int rsl = rs.size();
    int jsl = js.size();
    std::vector<std::vector<int> > v(rsl+1,std::vector<int> (jsl+1,0));
	
	for (int i = 0; i < rsl; ++i)
	{
		for (int j = 0; j < jsl; ++j)
		{
			v[i+1][j+1] = max(v[i][j] + (rs[i] == js[j]),max(v[i][j+1],v[i+1][j]));
		}
	}

	cout << v[rsl][jsl] << endl;
}

class Wizard {
    public:
        Spell *cast() {
            Spell *spell;
            string s; cin >> s;
            int power; cin >> power;
            if(s == "fire") {
                spell = new Fireball(power);
            }
            else if(s == "frost") {
                spell = new Frostbite(power);
            }
            else if(s == "water") {
                spell = new Waterbolt(power);
            }
            else if(s == "thunder") {
                spell = new Thunderstorm(power);
            } 
            else {
                spell = new Spell(s);
                cin >> SpellJournal::journal;
            }
            return spell;
        }
};

int main() {
    int T;
    cin >> T;
    Wizard Arawn;
    while(T--) {
        Spell *spell = Arawn.cast();
        counterspell(spell);
    }
    return 0;
}