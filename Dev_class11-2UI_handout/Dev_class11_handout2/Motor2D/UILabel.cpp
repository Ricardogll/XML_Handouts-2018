#include "UILabel.h"
#include "j1Fonts.h"
#include "j1App.h"
#include "j1Render.h"


UILabel::UILabel(int x, int y, const char* text, int size, SDL_Color color, const char* font) :UIElement(x,y,LABEL)
{
	
	this->text = text;
	this->color = color;

	_TTF_Font* newFont = App->font->Load(font, size);

	texture = App->font->Print(text, color, newFont);
	
}


UILabel::~UILabel()
{
}


void UILabel::Draw(SDL_Texture* atlas) {

	App->render->Blit(texture, pos_x, pos_y);

}