//========================================================================
//	CALauncherApp.h
//	CrackAttack! Launcher application header
//	Copyright 2006-2007 Sergey Kazenyuk, All Rights Reserved.
//	Distributed under the terms of the MIT License.
//========================================================================

#ifndef CALAUNCHERAPP_H
#define CALAUNCHERAPP_H

#include <Application.h>
#include <Alert.h>

#include "CALauncherWindow.h"
#include "TPreferences.h"
#include "Constants.h"

//====================================================================

class CALauncherApp : public BApplication
{
	public:
						CALauncherApp();
						~CALauncherApp();
		virtual void 	ReadyToRun();
		virtual void 	AboutRequested();
	private:
		void			NewYearGreeting();
		CALauncherWindow		*MainWindow;
		BAlert			*AboutAlert;
		BAlert			*SpecialAlert;
		TPreferences	*app_settings;
};

#endif
