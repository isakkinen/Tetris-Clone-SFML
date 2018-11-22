#pragma once
#include <SFML/Graphics.hpp>

class TetrisScreen;

enum class RotationDirection
{
	Clockwise,
	CounterClockwise
};
class PlayInputState
{
public:
	virtual void handleInput(TetrisScreen* target) = 0;
	virtual void update(const float dt);
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
	static constexpr float updateDelay{ 15.0f };
	float updateTimer{ 0.0f };
};