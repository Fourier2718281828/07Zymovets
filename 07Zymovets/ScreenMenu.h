#ifndef _SCREEN_MENU_H
#define _SCREEN_MENU_H
#include "Screen.h"
#include "Conditional.h"

//***************************************************
//Запрограмувати меню для роботи з текстовим екраном.
//Developed by Ruslan Zymovets (IPZ, group 1)
//on March 22
//Version 1.0
//***************************************************


/*
*	There's no need in duplicating classes: ConstScreenMenu, NonConstScreenMenu
*	Instead we mix those two types using conditional_t.
*	It is not a "reuse", but code is much more elegant and subtle.
*/
template<bool IsConst>
class ScreenMenu_temp
{
public:
	using ConstActionPtr = Screen::ConstActionPtr;
	using ActionPtr = Screen::ActionPtr;
	using action = conditional_t<IsConst, ConstActionPtr, ActionPtr>;
	using screen_ref = conditional_t<IsConst, const Screen&, Screen&>;
public:
	//There's no need in duplicating arrays:
	//static const ConstActionPtr constMenu[];
	static const action menu[];
private:
	screen_ref _screen;
public:
	ScreenMenu_temp(screen_ref);
	~ScreenMenu_temp() = default;

	//There's no need in duplicating methods too:
	//inline void doConstAction...
	inline void doAction(const action, const size_t) const;
};

template<bool IsConst>
const typename ScreenMenu_temp<IsConst>::action ScreenMenu_temp<IsConst>::menu[] =
{
	&Screen::home,
	&Screen::move,
	&Screen::back,
	&Screen::show
};

using ScreenMenu = ScreenMenu_temp<false>;
using ConstScreenMenu = ScreenMenu_temp<true>;

template<bool IsConst>
inline ScreenMenu_temp<IsConst>::ScreenMenu_temp(screen_ref screen)
	:	_screen(screen)
{
	return;
}

template<bool IsConst>
inline void ScreenMenu_temp<IsConst>::doAction(const action act, const size_t n) const
{
	for (size_t i = 0; i < n; i++)
	{
		(_screen.*act)();
	}
	return;
}
#endif // !_SCREEN_MENU_H