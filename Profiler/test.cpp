#include <Windows.h>
#include <float.h>
#include <conio.h>
#include "Profiler.h"

void main()
{
	char chControlKey;
	ProfileInit();

	while (1)
	{
		ProfileBegin(L"FOR");
		for (int i = 0; i < 10000; i++);
		ProfileEnd(L"FOR");

		if (_kbhit() != 0){
			chControlKey = _getch();
			if (chControlKey == 'q' || chControlKey == 'Q')
			{
				SaveProfile();
				return;
			}
		}
	}
}