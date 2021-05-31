#include "ModuleIntroScene.h"

#include "Application.h"
#include "ModuleTextures.h"
#include "ModuleRender.h"
#include "ModuleAudio.h"
#include "ModuleInput.h"
#include "ModuleFadeToBlack.h"
#include "SDL/include/SDL_Scancode.h"


ModuleIntroScene::ModuleIntroScene(bool startEnabled) : Module(startEnabled)
{
	NightCity.PushBack({ 0,0,320,384 });
	NightCity.speed = 0.1f;

	NightcityP.PushBack({ 0.1f, -0.0f }, 150, &NightCity);
}

ModuleIntroScene::~ModuleIntroScene()
{

}

// Load assets
bool ModuleIntroScene::Start()
{
	LOG("Loading background assets");

	bool ret = true;

	bgTexture = App->textures->Load("Assets/Intro_Screen.png");
	NightCityTexture = App->textures->Load("Assets/Intro/NightCity.png");
	BuildingsTexture = App->textures->Load("Assets/Intro/buildings.png");
	CloudTexture = App->textures->Load("Assets/Intro/clouds.png");
	StreetTexture = App->textures->Load("Assets/Intro/Street.png");
	TurtlesImagesTexture = App->textures->Load("Assets/Intro/Turtles.png");

	App->render->camera.x = 0;
	App->render->camera.y = 0;

	return ret;
}

update_status ModuleIntroScene::Update()
{
	NightcityP.Update();
	if (App->input->keys[SDL_SCANCODE_SPACE] == KEY_STATE::KEY_DOWN)
	{
		App->fade->FadeToBlack(this, (Module*)App->title, 90);
	}

	

	return update_status::UPDATE_CONTINUE;
}

// Update: draw background
update_status ModuleIntroScene::PostUpdate()
{
	// Draw everything --------------------------------------
	
	App->render->Blit(NightCityTexture, 0, 0, NULL);

	App->render->Blit(bgTexture, 0, 0, NULL);
	return update_status::UPDATE_CONTINUE;
}

bool ModuleIntroScene::CleanUp(){
	LOG("Clearing Intro");

	App->textures->Unload(bgTexture);
	App->textures->Unload(NightCityTexture);

	return true;
}