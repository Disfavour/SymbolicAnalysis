#pragma once
class Area
{
private:
	const float
		_left,
		_right,
		_top,
		_bot,
		_sizeX,
		_sizeY;

protected:
	Area(const float& left, const float& right, const float& top, const float& bot);
	bool inArea(const float& x, const float& y) const;

public:
	const float& left()		const;
	const float& right()	const;
	const float& top()		const;
	const float& bot()		const;
	const float& sizeX()	const;
	const float& sizeY()	const;
};
