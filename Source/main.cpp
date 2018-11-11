#include <iostream>
#include <string>
#include "switch.h"
using namespace std;

void refresh(string msg, int num)
{
	consoleClear();
	cout << msg << endl << num;
}

int main()
{
	consoleInit(NULL);
	string msg = "Hello World!";
	int num1 = 0;
	u32 kDownOld = 0;
	cout << msg << endl << num1;
	while (appletMainLoop())
	{
		hidScanInput();
		u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
		if (kDown != kDownOld)
		{
			if (kDown & KEY_PLUS) break;
			if (kDown & KEY_UP)
			{
				num1 = num1 + 1;
				refresh(msg, num1);
			}
			else if (kDown & KEY_DOWN)
			{
				num1 = num1 - 1;
				refresh(msg, num1);
			}
		}
		kDownOld = kDown;
		consoleUpdate(NULL);
	}
	consoleExit(NULL);
	return 0;
}