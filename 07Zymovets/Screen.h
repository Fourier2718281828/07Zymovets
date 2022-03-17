#pragma once
template <size_t height = 30, size_t width = 120>
class Screen 
{
	// Однойменні сталі та несталі методи
	inline const Screen& home() const; // Перенести курсор на початок екрана
	inline Screen& home();
	inline const Screen& move() const; // Змістити курсор на один символ праворуч
	inline Screen& move();
	inline const Screen& back() const; // Змістити курсор на один символ ліворуч
	inline Screen& back();
	inline const Screen& show() const; // Показати вміст екрана
	inline Screen& show();
	inline const Screen& move(const size_t, const size_t) const; // Перенести курсор у задану позицію
	inline Screen& move(const size_t, const size_t);
	inline const Screen& clear() const; // Очистити екран
	inline Screen& clear();
	inline const Screen& showCurrent() const; // Показати символ, перед яким
	inline Screen& showCurrent();			  // міститься курсор
	inline char get() const; // Селектор
	inline char get();
	inline const Screen& set(const char) const; // Модифікатор
	inline Screen& set(char);
private:
	static const size_t maxHeight; // Максимальна висота екрана
	static const size_t maxWidth; // Максимальна ширина екрана
	static const char _filler; // Наповнювач
	static const char thick_delim;
	static const char thin_delim;
	size_t _height; // Фактична висота екрана
	size_t _width; // Фактична ширина екрана
	char* _wContent; // Наповнення екрана
	mutable size_t _cursor; // Місце курсора
	// Нереалізовані, а тому закриті копіювання:
	// копіювання екранів не передбачено
	Screen(const Screen&);
	inline Screen& operator=(const Screen&);
	inline void text_delimitor(const char);
};

template<size_t height, size_t width>
inline const Screen<height, width>& Screen<height, width>::home() const
{
	_cursor = 0;
	return *this;
}

template<size_t height, size_t width>
inline Screen<height, width>& Screen<height, width>::home()
{
	_cursor = 0;
	return *this;
}

template<size_t height, size_t width>
inline const Screen<height, width>& Screen<height, width>::move() const
{
	if (_cursor < _height * _width - 1) 
		++_cursor;
	return *this;
}

template<size_t height, size_t width>
inline Screen<height, width>& Screen<height, width>::move()
{
	if (_cursor < _height * _width - 1)
		++_cursor;
	return *this;
}

template<size_t height, size_t width>
inline const Screen<height, width>& Screen<height, width>::back() const
{
	if (_cursor > 0)
		--_cursor;
	return *this;
}

template<size_t height, size_t width>
inline Screen<height, width>& Screen<height, width>::back()
{
	if (_cursor > 0)
		--_cursor;
	return *this;
}

template<size_t height, size_t width>
inline const Screen<height, width>& Screen<height, width>::show() const
{
	size_t cursor = _cursor;
	text_delimitor(thick_delim);
	cout << "cursor = " << _cursor << endl;
	text_delimitor(thin_delim);
	home();

	for (size_t i = 0; i < height; ++i)
	{
		for (size_t j = 0; j < width; ++j)
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

template<size_t height, size_t width>
inline Screen<height, width>& Screen<height, width>::show()
{
	size_t cursor = _cursor;
	text_delimitor(thick_delim);
	cout << "cursor = " << _cursor << endl;
	text_delimitor(thin_delim);
	home();

	for (size_t i = 0; i < height; ++i)
	{
		for (size_t j = 0; j < width; ++j)
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

template<size_t height, size_t width>
inline const Screen<height, width>& Screen<height, width>::move(const size_t, const size_t) const
{
	_cursor = (i < _height && j < _width) ? i * _width + j : 0;
	return *this;
}

template<size_t height, size_t width>
inline Screen<height, width>& Screen<height, width>::move(const size_t, const size_t)
{
	_cursor = (i < _height&& j < _width) ? i * _width + j : 0;
	return *this;
}

template<size_t height, size_t width>
inline const Screen<height, width>& Screen<height, width>::clear() const
{
	_cursor = 0;

	for (size_t i = 0; i < _width * _height; ++i)
	{
		_wContent[i] = _filler;
	}

	return *this;
}

template<size_t height, size_t width>
inline Screen<height, width>& Screen<height, width>::clear()
{
	_cursor = 0;

	for (size_t i = 0; i < _width * _height; ++i)
	{
		_wContent[i] = _filler;
	}

	return *this;
}

template<size_t height, size_t width>
inline const Screen<height, width>& Screen<height, width>::showCurrent() const
{
	cout << get() << endl;
	return *this;
}

template<size_t height, size_t width>
inline Screen<height, width>& Screen<height, width>::showCurrent()
{
	cout << get() << endl;
	return *this;
}

template<size_t height, size_t width>
inline char Screen<height, width>::get() const
{
	return _wContent[_cursor];
}

template<size_t height, size_t width>
inline char Screen<height, width>::get()
{
	return _wContent[_cursor];
}

template<size_t height, size_t width>
inline const Screen<height, width>& Screen<height, width>::set(char c) const
{
	_wContent[_cursor] = c;
	return *this;
}

template<size_t height, size_t width>
inline Screen<height, width>& Screen<height, width>::set(char)
{
	_wContent[_cursor] = c;
	return *this;
}

template<size_t height, size_t width>
inline void Screen<height, width>::text_delimitor(const char c)
{
	for (int i = 0; i < width; ++i)
	{
		cout << c;
	}

	cout << endl;
	return *this;
}
