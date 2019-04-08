#pragma once

#include "RenderWin.h"
#include "../GameState/GameState.h"

class GameState;

class Engine
{
public:
	Engine();
	~Engine();
	void Update();
	void Render();
	void StateSwitch(int);

	RenderWin rw;

private:
	GameState* state;

	GameState* game;
	GameState* menu;
	GameState* leader_board;
};