default: Creature.cpp Creature.hpp Final_Project.cpp healingTile.cpp healingTile.hpp Hero.cpp Hero.hpp Inventory.cpp Inventory.hpp Menu.cpp Menu.hpp Monster.cpp Monster.hpp Room.cpp Room.hpp Space.cpp Space.hpp spikeTile.hpp spikeTile.cpp Tile.cpp Tile.hpp
	g++ -std=c++0x Creature.cpp Final_Project.cpp healingTile.cpp Hero.cpp Inventory.cpp Menu.cpp Monster.cpp Room.cpp Space.cpp spikeTile.cpp Tile.cpp -o main
clean:
	rm main
