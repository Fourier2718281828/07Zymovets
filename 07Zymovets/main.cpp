#include <iostream>
#include "Screen.h"
#include "ScreenMenu.h"
using std::cout;
using std::endl;

//***************************************************
//Запрограмувати меню для роботи з текстовим екраном.
//Developed by Ruslan Zymovets (IPZ, group 1)
//on March 22
//Version 1.0
//***************************************************

int main(void) 
{
	Screen s(5, 10);
	ScreenMenu a(s);

	
	/*{
		cout << "#1 Creating empty square 5x10 screen :" << endl << endl;
		Screen s(5, 10);
		s.show();

		cout << endl << "#2 Writing on the screen (word \"Maths\"):" << endl;
		cout << endl << "Notice that the cursor is now on the position of the last symbol" << endl << endl;
		s.set('M').move()
		 .set('a').move()
		 .set('t').move()
		 .set('h').move()
		 .set('s').show();
		cout << "showCurrent() : ";
		s.showCurrent();
		cout << endl;

		cout << endl << "#3 home(); :" << endl << endl;
		s.home().show();
		
		cout << endl << "#4 Now let's read the word (up to default symbol) : " << endl;
		while ('.' != s.get())
		{
			s.showCurrent().move();
		}
		cout << endl;
		cout << endl << "#5 Now in the reversed order using back(): " << endl;
		s
			.back().showCurrent()
			.back().showCurrent()
			.back().showCurrent()
			.back().showCurrent()
			.back().showCurrent()
			;
		cout << endl << "Our screen now : " << endl << endl;
		s.show();

		cout << endl << "#6 Clear :" << endl << endl;
		s.clear().show();
		cout << endl << endl;
	}
	{
		cout << "#7 Create another but square & constant screen and draw a cross (example from the book):" << endl;
		const Screen s(10, 10);
		for (size_t i = 0; i <= s.height(); ++i)
			s.set('*').move(i, i);
		for (size_t i = 0; i <= s.height(); ++i)
			s.move(s.height() - i - 1, i).set('*');
		s.show();
		cout << endl << "Now clear :" << endl << endl;
		s.clear().show();
	}*/

	return 0;
}