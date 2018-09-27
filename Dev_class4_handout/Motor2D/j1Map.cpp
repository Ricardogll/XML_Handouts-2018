#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Map.h"
#include <math.h>

j1Map::j1Map() : j1Module(), map_loaded(false)
{
	name.create("map");
}

// Destructor
j1Map::~j1Map()
{}

// Called before render is available
bool j1Map::Awake(pugi::xml_node& config)
{
	LOG("Loading Map Parser");
	bool ret = true;

	folder.create(config.child("folder").child_value());

	return ret;
}

void j1Map::Draw()
{
	if(map_loaded == false)
		return;

	// TODO 6: Iterate all tilesets and draw all their 
	// images in 0,0 (you should have only one tileset for now)

}

// Called before quitting
bool j1Map::CleanUp()
{
	LOG("Unloading map");

	// TODO 2: Make sure you clean up any memory allocated
	// from tilesets / map


	map_file.reset();

	return true;
}

// Load new map
bool j1Map::Load(const char* file_name)
{
	bool ret = true;
	p2SString tmp("%s%s", folder.GetString(), file_name);

	pugi::xml_parse_result result = map_file.load_file(tmp.GetString());

	if(result == NULL)
	{
		LOG("Could not load map xml file %s. pugi error: %s", file_name, result.description());
		ret = false;
	}

	if(ret == true)
	{
		// TODO 3: Create and call a private function to load and fill
		// all your map data

		//pugi::xml_node map;
		//

		//map = LoadMapNode(map_file);
		//p2SString aux = map.attribute("orientation").as_string();
		//// if (map.attribute("orientation").as_string() == "orthogonal") Pregunta??? Porque esto no iguala?
		//if(aux == "orthogonal")
		//	map_node.orientation = ORTHOGONAL;

		//aux = map.attribute("renderorder").as_string();

		//if (aux == "right-down")
		//	map_node.render_order = RIGHT_DOWN;

		//map_node.height = map.attribute("height").as_uint();
		//map_node.width = map.attribute("width").as_uint();
		//map_node.tileheight = map.attribute("tileheight").as_uint();
		//map_node.tilewidth = map.attribute("tilewidth").as_uint();
		LoadMapData(map_node);
		LoadTileSetData();

	}

	// TODO 4: Create and call a private function to load a tileset
	// remember to support more any number of tilesets!
	

	if(ret == true)
	{
		// TODO 5: LOG all the data loaded
		// iterate all tilesets and LOG everything

	}

	map_loaded = ret;

	return ret;
}

void j1Map::LoadMapData(MapNode mapnode) {

	pugi::xml_node map;


	map = LoadMapNode(map_file);
	p2SString aux = map.attribute("orientation").as_string();
	// if (map.attribute("orientation").as_string() == "orthogonal") Pregunta??? Porque esto no iguala?
	if (aux == "orthogonal")
		mapnode.orientation = ORTHOGONAL;
	else
		LOG("Loading map data error");

	aux = map.attribute("renderorder").as_string();

	if (aux == "right-down")
		mapnode.render_order = RIGHT_DOWN;
	else
		LOG("Loading map data error");

	mapnode.height = map.attribute("height").as_uint();
	mapnode.width = map.attribute("width").as_uint();
	mapnode.tileheight = map.attribute("tileheight").as_uint();
	mapnode.tilewidth = map.attribute("tilewidth").as_uint();

	
}

pugi::xml_node j1Map::LoadMapNode(pugi::xml_document& map_file) const
{
	pugi::xml_node ret;

	pugi::xml_parse_result result = map_file.load_file("maps/hello2.tmx");

	if (result == NULL)
		LOG("Could not load map xml file map_file.xml. pugi error: %s", result.description());
	else
		ret = map_file.child("map");

	return ret;
}

void j1Map::LoadTileSetData() {
	pugi::xml_node tile;

	TileSet *tileset = new TileSet;
	tile_sets.add(tileset);
	p2List_item<TileSet*>* item = tile_sets.start;
	//tile = LoadMapNode(map_file);
	//tile = tile.child("tileset");

	for (pugi::xml_node tileset = map_file.child("map").child("tileset"); tileset; tileset = tileset.next_sibling("tileset")) 
	{
		item->data->margin = tileset.attribute("margin").as_uint();
		item->data->firstgid = tileset.attribute("firstgid").as_uint();
		item->data->spacing = tileset.attribute("spacing").as_uint();
		item->data->tileheigth = tileset.attribute("tileheight").as_uint();
		item->data->tilewidth = tileset.attribute("tilewidth").as_uint();

		item->next;
	}

}