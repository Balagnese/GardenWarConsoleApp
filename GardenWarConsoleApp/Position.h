#pragma once
struct Position
{
public:
	Position();
	Position(int x, int y);
	~Position();
	int x;
	int y;
	bool operator==(Position&another) const;
	bool operator!=(Position&another) const;
};

