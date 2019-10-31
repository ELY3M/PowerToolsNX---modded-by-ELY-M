#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <switch.h>

int main(int argc, char **argv)
{
	
	consoleInit(NULL);
	printf("PowerToolsNX v0.3 - By CVFD - Modded by ELY M.\n");
	printf("Press A to shutdown, B to reboot\n");
	printf("or X to reboot into RCM (DO NOT USE ON EXFAT)\n");
	printf("or + to exit to hbmenu");
	
	while(appletMainLoop())
    {
        hidScanInput();

        u64 kDown = hidKeysDown(CONTROLLER_P1_AUTO);
		if(kDown & KEY_B)
		{
        bpcInitialize();
        bpcRebootSystem();
		}
		
		if(kDown & KEY_A)
		{
        bpcInitialize();
        bpcShutdownSystem();
		}
		
		if(kDown & KEY_X)
		{
		
		Result rc = splInitialize();
		if (R_FAILED(rc)) {
		printf("splInitialize failed!\nPress + to exit.\n");
		} else {
		rc = splSetConfig ((SplConfigItem) 65001, 1);
		if (R_FAILED(rc)) {
			printf("splInitialize failed!\nPress + to exit.\n");
		}
		}
		
		
		}
		
        if (kDown & KEY_PLUS) { break;  } 
		if (kDown & KEY_MINUS) { break;  } 
		
		consoleUpdate(NULL);
		
    }




    consoleExit(NULL);
    return 0;
	
}
