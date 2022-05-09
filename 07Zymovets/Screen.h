#ifndef _SCREEN_H_
#define _SCREEN_H_

#include <iostream>
using std::cout;
using std::endl;

//***************************************************
//Запрограмувати меню для роботи з текстовим екраном.
//Developed by Ruslan Zymovets (IPZ, group 1)
//on March 22
//Version 1.0
//***************************************************

class Screen 
{
public:
	using ConstActionPtr = const Screen& (Screen::* const)() const;
	using ActionPtr = Screen & (Screen::* const)();
public:
	Screen(const size_t height, const size_t width, const char* str = nullptr);
	Screen(const Screen&) = delete;
	Screen& operator=(const Screen&) = delete;
	~Screen();

	inline const Screen& home()							  const;
	inline		 Screen& home();
	inline const Screen& move()							  const;
	inline		 Screen& move();
	inline const Screen& back()							  const;
	inline		 Screen& back();
	inline const Screen& show()							  const;
	inline		 Screen& show();
	inline const Screen& move(const size_t, const size_t) const;
	inline		 Screen& move(const size_t, const size_t);
	inline const Screen& clear()						  const;
	inline		 Screen& clear();
	inline const Screen& showCurrent()					  const;
	inline		 Screen& showCurrent();
	inline const Screen& set(const char)				  const;
	inline		 Screen& set(const char);
	inline char  get()									  const;
	inline char  get();
	inline size_t height() const { return _height; }
	inline size_t width () const { return _width ; }

private:
	static const size_t maxHeight;
	static const size_t maxWidth;
	static const char _filler; 
	static const char thick_delim;
	static const char thin_delim;
	size_t _height;
	size_t _width;
	char* _wContent;
	mutable size_t _cursor;
	inline void text_delimitor(const char) const;
};

inline const Screen& Screen::home() const
{
	_cursor = 0;
	return *this;
}

inline Screen& Screen::home()
{
	_cursor = 0;
	return *this;
}

inline const Screen& Screen::move() const
{
	if (_cursor < _height * _width - 1) 
		++_cursor;
	return *this;
}

inline Screen& Screen::move()
{
	if (_cursor < _height * _width - 1)
		++_cursor;
	return *this;
}

inline const Screen& Screen::back() const
{
	if (_cursor > 0)
		--_cursor;
	return *this;
}

inline Screen& Screen::back()
{
	if (_cursor > 0)
		--_cursor;
	return *this;
}

inline const Screen& Screen::show() const
{
	const size_t cursor = _cursor;
	text_delimitor(thick_delim);
	cout << "cursor = " << _cursor << endl;
	text_delimitor(thin_delim);
	home();

	for (size_t i = 0; i < _height; ++i)
	{
		for (size_t j = 0; j < _width; ++j)
		{
			cout << get();
			move();
		}
		cout << endl;
	}

	text_delimitor(thick_delim);
	_cursor = cursor;

	return *this;
}

inline Screen& Screen::show()
{
	const size_t cursor = _cursor;
	text_delimitor(thick_delim);
	cout << "cursor = " << _cursor << endl;
	text_delimitor(thin_delim);
	home();

	for (size_t i = 0; i < _height; ++i)
	{
		for (size_t j = 0; j < _width; ++j)
		{
			cout << get(); 
			move();
		}
		cout << endl;
	}

	text_delimitor(thick_delim);
	_cursor = cursor;

	return *this;
}

inline const Screen& Screen::move(const size_t i, const size_t j) const
{
	_cursor = (i < _height && j < _width) ? i * _width + j : 0;
	return *this;
}

inline Screen& Screen::move(const size_t i, const size_t j)
{
	_cursor = (i < _height && j < _width) ? i * _width + j : 0;
	return *this;
}

inline const Screen& Screen::clear() const
{
	_cursor = 0;

	for (size_t i = 0; i < _width * _height; ++i)
	{
		_wContent[i] = _filler;
	}

	return *this;
}

inline Screen& Screen::clear()
{
	_cursor = 0;

	for (size_t i = 0; i < _width * _height; ++i)
	{
		_wContent[i] = _filler;
	}

	return *this;
}

inline const Screen& Screen::showCurrent() const
{
	cout << get();
	return *this;
}

inline Screen& Screen::showCurrent()
{
	cout << get();
	return *this;
}

inline char Screen::get() const
{
	return _wContent[_cursor];
}

inline char Screen::get()
{
	return _wContent[_cursor];
}

inline const Screen& Screen::set(const char c) const
{
	_wContent[_cursor] = c;
	return *this;
}

inline Screen& Screen::set(const char c)
{
	_wContent[_cursor] = c;
	return *this;
}

inline void Screen::text_delimitor(const char c) const
{
	for (int i = 0; i < _width; ++i)
	{
		cout << c;
	}

	cout << endl;
}

#endif // !_SCREEN_H_