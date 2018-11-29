#include "UIElement.h"
#include "j1App.h"
#include "j1Textures.h"

UIElement::UIElement(int x, int y, UIType type) : pos_x(x), pos_y(y), type(type)
{

}

UIElement::~UIElement()
{
	App->tex->UnLoad(texture);
}

void UIElement::Start()
{
}

void UIElement::Draw(SDL_Texture* texture)
{
}

void UIElement::Update()
{
}

void UIElement::CheckMouseState()
{
}
