#include "UIImage.h"
#include "j1App.h"
#include "j1Render.h"
#include "j1Gui.h"

UIImage::UIImage(int x, int y, SDL_Rect rect):UIElement(x,y,IMAGE)
{
	img_rect = rect;
	rect = { x,y,rect.w,rect.h };
}

UIImage::~UIImage()
{
}

void UIImage::Draw(SDL_Texture* atlas) {

	App->render->Blit(atlas, pos_x, pos_y, &img_rect);

}