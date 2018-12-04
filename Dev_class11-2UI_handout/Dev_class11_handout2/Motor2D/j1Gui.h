#ifndef __j1GUI_H__
#define __j1GUI_H__

#include "j1Module.h"
#include "p2DynArray.h"
#include "j1Fonts.h"
#include "p2SString.h"
#include "j1Render.h"

#define CURSOR_WIDTH 2

// TODO 1: Create your structure of classes



// ---------------------------------------------------
enum UIType {

	LABEL,
	BUTTON,
	IMAGE,
	IMAGE_NO_ATLAS,
	CHECKBOX,
	NONE_UI

};

class UIElement;

class j1Gui : public j1Module
{

public:

	j1Gui();

	// Destructor
	virtual ~j1Gui();

	// Called when before render is available
	bool Awake(pugi::xml_node&);

	// Call before first frame
	bool Start();

	// Called before all Updates
	bool PreUpdate();

	bool Update(float dt);

	// Called after all Updates
	bool PostUpdate();

	// Called before quitting
	bool CleanUp();

	// TODO 2: Create the factory methods
	// Gui creation functions
	UIElement* CreateLabel(int x, int y, const char* text, int size = DEFAULT_FONT_SIZE, SDL_Color color = { 255,255,255,255 }, const char* font = DEFAULT_FONT);
	UIElement* CreateImage(int x, int y, SDL_Rect rect);
	UIElement* CreateImageNoAtlas(int x, int y, SDL_Rect rect, SDL_Texture* tex);
	UIElement* CreateButton(int x, int y, SDL_Rect rect, SDL_Rect hovering, SDL_Rect clicked);

	const SDL_Texture* GetAtlas() const;


public:

	SDL_Texture* not_atlas_ui;

private:
	
	p2DynArray<UIElement*> ui_elements;
	SDL_Texture* atlas;
	
	p2SString atlas_file_name;
};

#endif // __j1GUI_H__