#include "p2Defs.h"
#include "p2Log.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Textures.h"
#include "j1Fonts.h"
#include "j1Input.h"
#include "j1Gui.h"
#include "UIImage.h"
#include "UILabel.h"
#include"UIImageNoAtlas.h"


j1Gui::j1Gui() : j1Module()
{
	name.create("gui");
}

// Destructor
j1Gui::~j1Gui()
{}

// Called before render is available
bool j1Gui::Awake(pugi::xml_node& conf)
{
	LOG("Loading GUI atlas");
	bool ret = true;

	atlas_file_name = conf.child("atlas").attribute("file").as_string("");

	return ret;
}

// Called before the first frame
bool j1Gui::Start()
{
	atlas = App->tex->Load(atlas_file_name.GetString());
	not_atlas_ui = App->tex->Load("gui/logonscreen.png");

	return true;
}

// Update all guis
bool j1Gui::PreUpdate()
{
	return true;
}

bool j1Gui::Update(float dt)
{




	return true;
}

// Called after all Updates
bool j1Gui::PostUpdate()
{

	for (uint i = 0u; i < ui_elements.Count(); i++) {
		if (ui_elements[i] != nullptr) {
			ui_elements[i]->Draw(atlas);
		}
	}

	return true;
}

// Called before quitting
bool j1Gui::CleanUp()
{
	LOG("Freeing GUI");

	for (uint i = 0; i < ui_elements.Count(); ++i)
	{
		if (ui_elements[i] != nullptr)
		{
			delete ui_elements[i];
			ui_elements[i] = nullptr;
			

			if (!ui_elements.Delete(i))
				return false;

		}
	}

	ui_elements.Clear();

	App->tex->UnLoad(atlas);
	App->tex->UnLoad(not_atlas_ui);

	return true;
}

UIElement* j1Gui::CreateLabel(int x, int y, const char* text, int size, SDL_Color color, const char* font)
{
	
	UIElement* aux = new UILabel(x, y, text, size, color, font);
	

	ui_elements.PushBack(aux);


	return nullptr;
}

UIElement * j1Gui::CreateImage(int x, int y, SDL_Rect rect)
{

	UIElement* aux = new UIImage(x, y, rect);
	ui_elements.PushBack(aux);

	return nullptr;
}

UIElement* j1Gui::CreateImageNoAtlas(int x, int y, SDL_Rect rect, SDL_Texture* tex) {

	UIElement* aux = new UIImageNoAtlas(x, y, rect, tex);
	ui_elements.PushBack(aux);

	return nullptr;
}


// const getter for atlas
const SDL_Texture* j1Gui::GetAtlas() const
{
	return atlas;
}

// class Gui ---------------------------------------------------

