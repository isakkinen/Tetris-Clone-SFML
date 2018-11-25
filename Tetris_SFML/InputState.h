#pragma once
#include <SFML/Graphics.hpp>
#include "Enums.h"
class TetrisScreen;

class Idle;
class LeftPressed;
class RightPressed;
class DownPressed;
class RotationPressed;
class CRotationPressed;


class PlayInputState
{
public:
	virtual void handleInput(TetrisScreen* target) = 0;
	virtual void update(const float dt);

	static Idle idle;
	static LeftPressed leftPressed;
	static RightPressed rightPressed;
	static DownPressed downPressed;
	static RotationPressed rotationPressed;
	static CRotationPressed cRotationPressed;
private:
};

class Idle : public PlayInputState
{
public:
	virtual void handleInput(TetrisScreen* target);
};

class LeftPressed : public PlayInputState
{
public:
	virtual void handleInput(TetrisScreen* target);
private:
};

class RightPressed : public PlayInputState
{
public:
	virtual void handleInput(TetrisScreen* target);
private:
};

class RotationPressed : public PlayInputState
{
public:
	virtual void handleInput(TetrisScreen* target);
private:
};

class CRotationPressed : public PlayInputState
{
public:
	virtual void handleInput(TetrisScreen* target);
private:
};

class DownPressed : public PlayInputState
{
public:
	virtual void handleInput(TetrisScreen* target);
	virtual void update(const float dt);
private:
	bool isPressed{ true };
	bool doubleTapped{ false };
	static constexpr float updateDelay{ 15.0f };
	float updateTimer{ 0.0f };
};