//========================================================================
//	CALauncherWindow.h
//	Main window header file
//	Copyright 2006 Sergey Kazenyuk, All Rights Reserved.
//	Distributed under the terms of the MIT License.
//========================================================================

#ifndef CALAUNCHERWINDOW_H
#define CALAUNCHERWINDOW_H

#include <Window.h>
#include <Button.h>
#include <Menu.h>
#include <MenuItem.h>
#include <MenuField.h>
#include <TextControl.h>
#include <RadioButton.h>
#include <TabView.h>
//#include <CheckBox.h>

#include "AppView.h"
#include "Constants.h"
#include "AppBox.h"
#include "SoloModeView.h"
#include "ServerModeView.h"
#include "ClientModeView.h"

//====================================================================

const rgb_color invalid		=	{255, 0, 0};
const rgb_color valid		=	{0, 122, 0};

//====================================================================

class CALauncherWindow : public BWindow
{
	public:
						CALauncherWindow(BRect frame);
		virtual void	MessageReceived(BMessage* message);
		virtual bool	QuitRequested();
					
	private:
#ifdef USE_ZETA_LOCALEKIT
		void			SetLocalizedStrings();
#endif
		char			curquality[256];
		char			curresolution[10];
		char			curcomputeraimode[25];
		AppView			*MainView;
				
		BTabView		*PlayMode;
		BTab			*SoloModeTab;
		BTab			*ServerModeTab;
		BTab			*ClientModeTab;
		SoloModeView	*SoloTabView;
		ServerModeView	*ServerTabView;
		ClientModeView	*ClientTabView;
		
		AppBox			*GraphicsSettingsBox;
		BMenuField		*ResolutionMenuField;
		BMenu			*ResolutionMenu;
		BMenuItem		*QVGAResolution; //320x240
		BMenuItem		*VGAResolution; //640x480
		BMenuItem		*SVGAResolution; //800x600
		BMenuItem		*XGAResolution; //1024x768
		BMenuItem		*SXGAResolution; //1280x1024
		BMenuItem		*UXGAResolution; //1600x1200
		//QVGA - 320x240
		//VGA - 640x480
		//SVGA - 800x600
		//XGA - 1024x768
		//SXGA - 1280x1024
		//UXGA - 1600x1200
		//QXGA - 2048x1536
		//QSXGA - 3072x2048
		BMenuField		*QualityMenuField;
		BMenu			*QualityMenu;
		BMenuItem		*NormalQuality;
		BMenuItem		*ReducedQuality;
		BMenuItem		*ExtremelyReducedQuality;
		
		BTextControl	*PlayernameInput;
		
		AppBox			*GameModeBox;
		BRadioButton	*NormalGameMode;
		BRadioButton	*ExtremeGameMode;
		
		//BCheckBox		*SoundEnabled;
		
		BButton			*StartGameButton;
};

#endif
