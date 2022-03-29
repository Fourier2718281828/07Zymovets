#include <iostream>
#include "Screen.h"
using std::cout;
using std::endl;

//***************************************************
//Запрограмувати меню для роботи з текстовим екраном.
//Developed by Ruslan Zymovets (IPZ, group 1)
//on March 22
//Version 1.0
//***************************************************

/*
* 1. Why do we need inline const Screen& set(const char) const; ? 
* 2. Should moving stuff be implemented?
* 3. What about copying constructor and operator= ? Why aren't they implemented in book?
*/
int main(void)
{
	const char* fill = "0123456";
	Screen s(fill, 1, 10), s1;
	s.show().move().showCurrent().move().showCurrent().show();
	
	return 0;
}