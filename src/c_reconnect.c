#include "StdAfx.h"
#define	CMD_NAME	"USB Reconnect"

BOOL	CMD_RECONNECT (void)
{
	//char Version[256];
	//int i;
	//OpenStatus(topHWnd);
	ClosePort();
	//StatusText("Reconnecting USB...");
	if (OpenPort(ParPort, ParAddr, ParECP))
	{
		if (ParPort != -1)
			InitPort();
		ResetNES(RESET_COPYMODE);
		//StatusText("Retrieving internal version string...");  	  
		HWVer = FindVersion();
		//StatusOK();
		return TRUE;
	}
	else
	{
		//StatusOK();      
		HWVer = 0;
		return TRUE;	//Its obvious that there was a failure by the previous dialogs.
	}
}
