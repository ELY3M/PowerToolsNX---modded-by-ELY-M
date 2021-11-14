#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include <switch.h>

int main(int argc, char **argv)
{
	
	consoleInit(NULL);
	printf("PowerToolsNX v0.3 - By CVFD - Modded by ELY M.\n");
	printf("Press A to shutdown, B to reboot\n");
	printf("Press X to reboot into RCM (DO NOT USE ON EXFAT)\n");
	printf("Press + or - to exit to hbmenu");
	
	padConfigureInput(1, HidNpadStyleSet_NpadStandard);
	PadState pad;
        padInitializeDefault(&pad);
	while(appletMainLoop())
    {
        padUpdate(&pad);

        u64 kDown = padGetButtonsDown(&pad);
		if(kDown & HidNpadButton_B)
		{
        bpcInitialize();
        bpcRebootSystem();
		}
		
		if(kDown & HidNpadButton_A)
		{
        bpcInitialize();
        bpcShutdownSystem();
		}
		
		if(kDown & HidNpadButton_X)
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
		
                if (kDown & HidNpadButton_Plus) { break;  } 
		if (kDown & HidNpadButton_Minus) { break;  } 
		
		consoleUpdate(NULL);
		
    }




    consoleExit(NULL);
    return 0;
	
}
