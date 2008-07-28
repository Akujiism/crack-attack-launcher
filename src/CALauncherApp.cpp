//========================================================================
//	CALauncherApp.cpp
//	CrackAttack! Launcher application implementation
//	Copyright 2006-2007 Sergey Kazenyuk, All Rights Reserved.
//	Distributed under the terms of the MIT License.
//========================================================================

//#include <stdio.h>
#include <time.h>

#include <Screen.h>

#include "CALauncherApp.h"

//====================================================================

CALauncherApp::CALauncherApp()
			: BApplication(App_Sig)
{
	app_settings = new TPreferences(App_Name);
	// If the prefs object didn't initialize properly,
	// use default preference values.
	if (app_settings->InitCheck() != B_OK)
	{
		app_settings->SetInt64("last_used", real_time_clock());
		app_settings->SetInt32("use_count", 0);
		app_settings->SetInt32("last_year", 0);
		//app_settings->SetRect("CALauncherMainWindow", CALauncherWindowDefaultRect);
		
	}
	
	//app_settings->PrintToStream();
	
	/*printf("time=%i, month=%i, day=%i, year=%i\n", int(time), localtime(&time)->tm_mon,
			localtime(&time)->tm_mday, localtime(&time)->tm_year+1900);*/
	
	NewYearGreeting();
}

//--------------------------------------------------------------------

CALauncherApp::~CALauncherApp()
{
	if (app_settings)
		delete app_settings;
}

//--------------------------------------------------------------------

void CALauncherApp::ReadyToRun()
{
	BRect MainWindowRect;
	BScreen *Screen;
	Screen = new BScreen();
	MainWindowRect.Set(50,50,300,265);
	MainWindow = new CALauncherWindow(MainWindowRect);
	MainWindow->MoveTo(Screen->Frame().left+(Screen->Frame().IntegerWidth() - MainWindow->Frame().IntegerWidth()) / 2,
						Screen->Frame().top+(Screen->Frame().IntegerHeight() - MainWindow->Frame().IntegerHeight()) / 2);
	delete Screen;
	MainWindow->Show();
}

//--------------------------------------------------------------------

void CALauncherApp::AboutRequested()
{
	printf("CALauncher::AboutRequested();\n");
#ifndef USE_ZETA_LOCALEKIT
	AboutAlert = new BAlert("About "App_Name,
				App_Name"\n"
				"Version "App_Version"\n"
				"Compiled on: "__DATE__" " __TIME__"\n"
				"\n"
				"Send your bug reports and comments to kazenyuk@gmail.com\n"
				"\n"
				"Copyright "B_UTF8_COPYRIGHT" 2006-2007 Sergey S. Kazenyuk\n"
				"All rights reserved.\n"
				"\n"
				"Developed in Nizhny Novgorod, Russian Federation.",
		"Ok", NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_INFO_ALERT);
#else
	AboutAlert = new BAlert("About "App_Name,
				App_Name"\n"
				"Version "App_Version"\n"
				"Compiled on: "__DATE__" " __TIME__"\n"
				"\n"
				"Send your bug reports and comments to kazenyuk@gmail.com\n"
				"\n"
				"Copyright "B_UTF8_COPYRIGHT" 2006-2007 Sergey S. Kazenyuk\n"
				"All rights reserved.\n"
				"\n"
				"Developed in Nizhny Novgorod, Russian Federation.",
		"Ok", NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_INFO_ALERT);
#endif
	AboutAlert->SetShortcut(0, B_ESCAPE);
	AboutAlert->Go();
}

//--------------------------------------------------------------------

void CALauncherApp::NewYearGreeting()
{
	time_t time;
	time = real_time_clock();
	//is today the 1st or 2nd of January?
	if (localtime(&time)->tm_mon == 0)
	{
		if ((localtime(&time)->tm_mday == 1) ||
			(localtime(&time)->tm_mday == 2))
		{
			int32 lyear = 0;
			lyear = app_settings->FindInt32("last_year", lyear);
			if (lyear != localtime(&time)->tm_year+1900)
			{
				char *happy_new_year;
				happy_new_year = new char[19];
				strcpy(happy_new_year, "Happy New Year!");
				//sprintf(happy_new_year, "Happy New %d Year!", int(localtime(&time)->tm_year+1900));
				SpecialAlert = new BAlert("Happy New Year!",
					happy_new_year,
					"Thanks!", NULL, NULL, B_WIDTH_AS_USUAL, B_OFFSET_SPACING, B_IDEA_ALERT);
				SpecialAlert->SetShortcut(0, B_ESCAPE);
				SpecialAlert->Go(NULL);
				app_settings->SetInt32("last_year", localtime(&time)->tm_year+1900);
				delete[] happy_new_year;
			}
		}
	}
}
