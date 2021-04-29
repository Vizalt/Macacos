#ifndef __MODULE_INTRO_SCENE_H__
#define __MODULE_INTRO_SCENE_H__

#include "Module.h"
#include "Animation.h"

struct SDL_Texture;

class ModuleIntroScene : public Module
{
public:
	//Constructor
	ModuleIntroScene(bool startEnabled);

	//Destructor
	~ModuleIntroScene();

	// Called when the module is activated
	// Loads the necessary textures for the map background
	bool Start() override;

	// Called at the middle of the application loop
	// Updates the scene's background animations
	update_status Update() override;

	// Called at the end of the application loop.
	// Performs the render call of all the parts of the scene's background
	update_status PostUpdate() override;

	bool CleanUp() override;

public:
	// The scene sprite sheet loaded into an SDL_Texture
	SDL_Texture* bgTexture = nullptr;
};

#endif