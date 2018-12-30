/*******************************************************************************
* ** Author: James Sellers
* ** Date: 12-4-2018
* ** Descriptions: This is the abstract Space class. It has a pure virtual function
called printSpace() which has a different implementation in each derived class
it has four pointers to the adjacent spaces. 
* ****************************************************************************/
#ifndef SPACE_HPP
#define SPACE_HPP



class Monster;
class Space
{
protected:
	Space *North;
	Space *South;
	Space *East;
	Space *West;

public:
	Space();
	Space(Space*, Space*, Space*, Space*);
	~Space();

	void setNorth(Space*);
	void setSouth(Space*);
	void setEast(Space*);
	void setWest(Space*);
	Space *getNorth();
	Space *getSouth();
	Space *getEast();
	Space *getWest();
	virtual void printSpace() = 0;
	virtual void setHero() {}
	virtual void removeHero() {}
	virtual void setMonster(Monster*) {}
	virtual void removeMonster() {};
	virtual bool hasMonster() { return false; }
	virtual bool hasHero() { return false; }
	virtual void killMonster() {}
	virtual Monster* getMonster() { return nullptr; }
	virtual bool hasBombs() { return false; }
	virtual void setBombs() {}
	virtual void removeBombs() {}
	virtual int heal() { return 0; }
	
	

};
#endif // !SPACE_HPP

