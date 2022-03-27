#include "Area.h"


Area::Area(const float& left, const float& right, const float& top, const float& bot)
    : _left(left), _right(right), _top(top), _bot(bot), _sizeX(right - left), _sizeY(top - bot) {}

bool Area::inArea(const float& x, const float& y) const
{
    return x > _left && x < _right&& y > _bot && y < _top;
}

const float& Area::left() const
{
    return _left;
}

const float& Area::right() const
{
    return _right;
}

const float& Area::top() const
{
    return _top;
}

const float& Area::bot()const
{
    return _bot;
}

const float& Area::sizeX()const
{
    return _sizeX;
}

const float& Area::sizeY()const
{
    return _sizeY;
}
