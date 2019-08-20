#include "Player.h"
#include "Mob.h"
#include "Environment.h"

int main()
{
	Player Player1;

	Environment e;
	e.generateEntities();

	Player1.setDamage(10);
	Player1.setHealth(50);
	Player1.setName("Player1");
	Point2D* location = new Point3D(5, 6, 8);
	Player1.setLocation(location);

	Point2D* mobLocation = new Point2D(1, 3);
	Entity* newMob = new Mob("dragon", mobLocation, 9, 60);
	e.add(newMob);

	e.print();
	e.attackAllOfType(Player1, type::Mob);

	cout << endl;
	cout << "After the attack: " << endl;
	e.print();

	delete location;

	cin.get();
	return 0;
}