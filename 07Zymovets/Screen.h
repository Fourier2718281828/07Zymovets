#pragma once
template <size_t height, size_t width>
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
	inline Screen& showCurrent(); // міститься курсор
	inline char get() const; // Селектор
	inline char get();
	inline const Screen& set(char) const; // Модифікатор
	inline Screen& set(char);
private:
	static const size_t maxHeight; // Максимальна висота екрана
	static const size_t maxWidth; // Максимальна ширина екрана
	static const char _filler; // Наповнювач
	size_t _height; // Фактична висота екрана
	size_t _width; // Фактична ширина екрана
	char* _wContent; // Наповнення екрана
	mutable size_t _cursor; // Місце курсора
	// Нереалізовані, а тому закриті копіювання:
	// копіювання екранів не передбачено
	Screen(const Screen&);
	inline Screen& operator=(const Screen&);
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
	cout << "cursor=" << _cursor << endl;
	home();

	for (size_t i = 0; i < _height; i++) 
	{
		for (size_t j = 0; j < _width; j++) 
		{
			cout << get(); move();
		}
		cout << endl;
	}

	_cursor = cursor;

	return *this;
}

template<size_t height, size_t width>
inline Screen<height, width>& Screen<height, width>::show()
{
	size_t cursor = _cursor;
	cout << "cursor=" << _cursor << endl;
	home();

	for (size_t i = 0; i < _height; i++)
	{
		for (size_t j = 0; j < _width; j++)
		{
			cout << get(); move();
		}
		cout << endl;
	}

	_cursor = cursor;

	return *this;
}
