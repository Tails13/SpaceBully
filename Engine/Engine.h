#pragma once

#include "RenderWin.h"
#include "AudioSystem/AudioSystem.h"
#include "../GameState/GameState.h"
#include "Graphics/Background.h"

class GameState;

class Engine
{
public:
	Engine();
	~Engine();
	void Update();
	void Render(float);
	void StateSwitch(int);

	RenderWin rw;

private:
	GameState* state;
	GameState* game;
	GameState* menu;
	GameState* leader_board;

	Background background;
};