#include "Screen.h"

const size_t Screen::maxHeight = 2000;
const size_t Screen::maxWidth = 2000;
const char Screen::_filler = '*';
const char Screen::thick_delim = '#';
const char Screen::thin_delim = '-';

Screen::Screen(const size_t height, const size_t width)
	: _height(height), _width(width), _wContent(new char[height * width + 1]), _cursor(0)
{
	for (size_t i = 0; i < _width * _height; ++i)
	{
		_wContent[i] = _filler;
	}

	_wContent[_width * _height] = '\0';

	return;
}

Screen::Screen(const char* c, const size_t height, const size_t width)
	: _height(height), _width(width), _wContent(new char[height * width + 1]), _cursor(0)
{
	int i = 0;
	for (; i < _height * _width; ++i)
	{
		if (!c[i]) break;
		_wContent[i] = c[i];
	}

	for (; i < _height * _width; ++i)
	{
		_wContent[i] = _filler;
	}

	_wContent[_width * _height] = '\0';

	return;
}

Screen::~Screen()
{
	delete _wContent;
	_wContent = nullptr;
	return;
}

Screen::Screen(const Screen& s)
{

}