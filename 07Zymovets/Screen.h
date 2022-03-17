#pragma once
template <size_t height, size_t width>
class Screen 
{
	// ��������� ���� �� ������ ������
	inline const Screen& home() const; // ��������� ������ �� ������� ������
	inline Screen& home();
	inline const Screen& move() const; // ������� ������ �� ���� ������ ��������
	inline Screen& move();
	inline const Screen& back() const; // ������� ������ �� ���� ������ ������
	inline Screen& back();
	inline const Screen& show() const; // �������� ���� ������
	inline Screen& show();
	inline const Screen& move(const size_t, const size_t) const; // ��������� ������ � ������ �������
	inline Screen& move(const size_t, const size_t);
	inline const Screen& clear() const; // �������� �����
	inline Screen& clear();
	inline const Screen& showCurrent() const; // �������� ������, ����� ����
	inline Screen& showCurrent(); // �������� ������
	inline char get() const; // ��������
	inline char get();
	inline const Screen& set(char) const; // �����������
	inline Screen& set(char);
private:
	static const size_t maxHeight; // ����������� ������ ������
	static const size_t maxWidth; // ����������� ������ ������
	static const char _filler; // ����������
	size_t _height; // �������� ������ ������
	size_t _width; // �������� ������ ������
	char* _wContent; // ���������� ������
	mutable size_t _cursor; // ̳��� �������
	// �����������, � ���� ������ ���������:
	// ��������� ������ �� �����������
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
