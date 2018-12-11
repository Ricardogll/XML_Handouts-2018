#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Input.h"
#include "j1Textures.h"
#include "j1Audio.h"
#include "j1Render.h"
#include "j1Window.h"
#include "j1Map.h"
#include "j1PathFinding.h"
#include "j1Gui.h"
#include "j1Scene.h"
#include "j1Fonts.h"
#include "UILabel.h"

j1Scene::j1Scene() : j1Module()
{
	name.create("scene");
}

// Destructor
j1Scene::~j1Scene()
{}

// Called before render is available
bool j1Scene::Awake()
{
	LOG("Loading Scene");
	bool ret = true;

	return ret;
}

// Called before the first frame
bool j1Scene::Start()
{
	if(App->map->Load("iso_walk.tmx") == true)
	{
		int w, h;
		uchar* data = NULL;
		if(App->map->CreateWalkabilityMap(w, h, &data))
			App->pathfinding->SetMap(w, h, data);

		RELEASE_ARRAY(data);
	}

	debug_tex = App->tex->Load("maps/path2.png");

	
	
	ui_el = App->gui->CreateLabel(100, 100, "HelloWorld", 16, { 255,0,0,255 });
	/*ui_el4 = App->gui->CreateButton(200, 20,  { 642,169,229,69 }, { 0,113,229,69 }, { 411,169,229,69 });
	ui_el3 = App->gui->CreateImageNoAtlas(500, 0, { 0,0,100,100 }, App->gui->not_atlas_ui);
	ui_el5 = App->gui->CreateLabel(10, 25, "Other Font", 20, { 0,255,0,255 }, "fonts/open_sans/OpenSans-SemiboldItalic.ttf");*/
	ui_el2 = App->gui->CreateImage(10, 10, { 648, 173, 221, 64 }, ui_el);

	return true;
}

// Called each loop iteration
bool j1Scene::PreUpdate()
{

	// debug pathfing ------------------
	static iPoint origin;
	static bool origin_selected = false;

	int x, y;
	App->input->GetMousePosition(x, y);
	iPoint p = App->render->ScreenToWorld(x, y);
	p = App->map->WorldToMap(p.x, p.y);

	if(App->input->GetMouseButtonDown(SDL_BUTTON_LEFT) == KEY_DOWN)
	{
		if(origin_selected == true)
		{
			App->pathfinding->CreatePath(origin, p);
			origin_selected = false;
		}
		else
		{
			origin = p;
			origin_selected = true;
		}
	}

	return true;
}

// Called each loop iteration
bool j1Scene::Update(float dt)
{
	// Gui ---

	// -------
	if (App->input->GetKey(SDL_SCANCODE_L) == KEY_DOWN)
		App->LoadGame("save_game.xml");

	if (App->input->GetKey(SDL_SCANCODE_S) == KEY_DOWN)
		App->SaveGame("save_game.xml");

	if (App->input->GetKey(SDL_SCANCODE_UP) == KEY_REPEAT)
		App->render->camera.y += floor(200.0f * dt);

	if (App->input->GetKey(SDL_SCANCODE_DOWN) == KEY_REPEAT)
		App->render->camera.y -= floor(200.0f * dt);

	if (App->input->GetKey(SDL_SCANCODE_LEFT) == KEY_REPEAT)
		App->render->camera.x += floor(200.0f * dt);

	if (App->input->GetKey(SDL_SCANCODE_RIGHT) == KEY_REPEAT)
		App->render->camera.x -= floor(200.0f * dt);

	App->map->Draw();

	int x, y;
	App->input->GetMousePosition(x, y);
	iPoint map_coordinates = App->map->WorldToMap(x - App->render->camera.x, y - App->render->camera.y);
	p2SString title("Map:%dx%d Tiles:%dx%d Tilesets:%d Tile:%d,%d",
		App->map->data.width, App->map->data.height,
		App->map->data.tile_width, App->map->data.tile_height,
		App->map->data.tilesets.count(),
		map_coordinates.x, map_coordinates.y);

	//App->win->SetTitle(title.GetString());

	// Debug pathfinding ------------------------------
	//int x, y;
	App->input->GetMousePosition(x, y);
	iPoint p = App->render->ScreenToWorld(x, y);
	p = App->map->WorldToMap(p.x, p.y);
	p = App->map->MapToWorld(p.x, p.y);

	App->render->Blit(debug_tex, p.x, p.y);

	const p2DynArray<iPoint>* path = App->pathfinding->GetLastPath();

	for (uint i = 0; i < path->Count(); ++i)
	{
		iPoint pos = App->map->MapToWorld(path->At(i)->x, path->At(i)->y);
		App->render->Blit(debug_tex, pos.x, pos.y);
	}




	/*if (ui_el != nullptr) {
		

		switch (ui_el->mouse_state) {

		case MouseState::ON_ENTER:
			ui_el->SetText("Hovering");
			LOG("SETTING TEXT HOVER");
			break;

		case MouseState::ON_LEAVE:
			ui_el->SetText("HelloWorld");
			LOG("SETTING TEXT LEAVE");
			break;

		case MouseState::DOWN_CLICK:
			ui_el->SetText("Clicking");
			LOG("SETTING TEXT CLICK");
			break;

		}


	}*/

		//if (ui_el2 != nullptr) {

		//	if (ui_el2->mouse_state == MouseState::NONE) {
		//		//ui_el2->SetText("HelloWorld");
		//		ui_el2->img_rect = { 648, 173, 221, 64 };

		//	}

		//	if (ui_el2->mouse_state == MouseState::HOVERING) {
		//		//ui_el2->SetText("Hovering");
		//		ui_el2->img_rect = { 6, 114, 221, 64 }; //417,170click -  6, 114hover
		//	}

		//	if (ui_el2->mouse_state == MouseState::REPEAT_CLICK) {
		//		//ui_el2->SetText("Clicking");
		//		ui_el2->img_rect = { 417, 170, 221, 64 }; //417,170click -  6, 114hover

		//	}

		//}

	return true;
}

// Called each loop iteration
bool j1Scene::PostUpdate()
{
	bool ret = true;

	if(App->input->GetKey(SDL_SCANCODE_ESCAPE) == KEY_DOWN)
		ret = false;

	return ret;
}

// Called before quitting
bool j1Scene::CleanUp()
{
	LOG("Freeing scene");

	

	return true;
}
