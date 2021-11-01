#include <iostream>
using namespace std;

// Base class
class LivingEntity {
protected:
	string name;
	int hp;		
public:
	LivingEntity(string a, int b) {
		name = a;
		hp = b;
	}
	void infor() {
		cout << name << " : " << hp << endl;
	}
}

// Derived class
class Player : public LivingEntity
{
public:
	Player(string a, int b) : LivingEntity(a, b)
	{
		
	}
	void infor() {
		cout << "Hello im subclass";
	}
public:
	int armor;
}

int main() {
	LivingEntity* s;
	Player player("JoJo", 5);

	s = &player;
	s->infor();
	
	return 0;
}