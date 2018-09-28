#ifndef __j1MAP_H__
#define __j1MAP_H__

#include "PugiXml/src/pugixml.hpp"
#include "p2List.h"
#include "p2Point.h"
#include "j1Module.h"
#include "j1Render.h"

// TODO 2: Create a struct to hold information for a TileSet
// Ignore Terrain Types and Tile Types for now, but we want the image!

struct TileSet {

	uint firstgid = 0u;
	uint spacing = 0u;
	uint margin = 0u;
	uint tilewidth = 0u;
	uint tileheight = 0u;
	SDL_Texture* texture;
};

// ----------------------------------------------------
enum map_orientation { // Para hacer que los 2 puedan tener el mismo nombre hacemeos enum class
	ORIENTATION_NONE = -1,
	ORTHOGONAL,
	ISOMETRIC

};

enum map_render_order {
	RENDER_ORDER_NONE = -1,
	LEFT_DOWN,
	LEFT_UP,
	RIGHT_DOWN,
	RIGHT_UP
};
// TODO 1: Create a struct needed to hold the information to Map node
struct MapNode {
	map_orientation orientation = ORIENTATION_NONE;
	map_render_order render_order = RENDER_ORDER_NONE;
	uint width = 0u;
	uint height = 0u;
	uint tilewidth = 0u;
	uint tileheight = 0u;
	//nextobjectid
};

// ----------------------------------------------------
class j1Map : public j1Module
{
public:

	j1Map();

	// Destructor
	virtual ~j1Map();

	// Called before render is available
	bool Awake(pugi::xml_node& conf);

	// Called each loop iteration
	void Draw();

	// Called before quitting
	bool CleanUp();

	// Load new map
	bool Load(const char* path);

	pugi::xml_node LoadMapNode(pugi::xml_document& config_file) const;
	
	
private:
	void LoadMapData(MapNode mapnode);
	void LoadTileSetData();
public:

	// TODO 1: Add your struct for map info as public for now
	MapNode map_node;
	p2List<TileSet*> tile_sets;
private:

	pugi::xml_document	map_file;
	p2SString			folder;
	bool				map_loaded;
};

#endif // __j1MAP_H__