//========================================================================
//	CALauncherWindow.cpp
//	Main window implementation
//	Copyright 2006-2008 Sergey Kazenyuk, All Rights Reserved.
//	Distributed under the terms of the MIT License.
//========================================================================

#include <stdio.h>
#include <unistd.h>

#include <Application.h>
#include <Entry.h>
#include <Roster.h>

#include "CALauncherWindow.h"

#define DEBUG 1

//====================================================================

CALauncherWindow::CALauncherWindow(BRect frame)
	: BWindow(frame, App_Name, B_TITLED_WINDOW,
		B_NOT_RESIZABLE|B_NOT_ZOOMABLE)
{
	//MainView = new AppView(BRect(1,20,450,350));
	MainView = new AppView(Bounds());
	AddChild(MainView);
	
	PlayMode = new BTabView(BRect(1,1,249,53), "playmode", B_WIDTH_FROM_LABEL);
	SoloModeTab = new BTab();
	ServerModeTab = new BTab();
	ClientModeTab = new BTab();
	BRect *rect;
	rect = new BRect();
	*rect = PlayMode->Bounds();
	rect->bottom -= 20;//PlayMode->TabHeight();
	SoloTabView = new SoloModeView(*rect);
	ServerTabView = new ServerModeView(*rect);
	ClientTabView = new ClientModeView(*rect);
	PlayMode->AddTab(SoloTabView, SoloModeTab);
	PlayMode->AddTab(ServerTabView, ServerModeTab);
	PlayMode->AddTab(ClientTabView, ClientModeTab);
	MainView->AddChild(PlayMode);
	PlayMode->SetTabHeight(20.0F);
	
	delete rect;
	
	//"Graphics Settings" box
	GraphicsSettingsBox = new AppBox(BRect(1,60,249,124), "graphicssettings", lGraphicsSettings, B_FOLLOW_LEFT|B_FOLLOW_TOP,
		B_WILL_DRAW|B_NAVIGABLE, B_FANCY_BORDER);
	MainView->AddChild(GraphicsSettingsBox);
	
	ResolutionMenu = new BMenu("graphicsresolutionmenu", B_ITEMS_IN_COLUMN);
	ResolutionMenu->SetRadioMode(true);
	ResolutionMenu->SetLabelFromMarked(true);
	QVGAResolution = new BMenuItem(lGraphicsQVGAResolution, new BMessage(QVGA_RESOLUTION_MSG));
	ResolutionMenu->AddItem(QVGAResolution);
	VGAResolution = new BMenuItem(lGraphicsVGAResolution, new BMessage(VGA_RESOLUTION_MSG));
	ResolutionMenu->AddItem(VGAResolution);
	VGAResolution->SetMarked(true);
	strcpy(curresolution, lGraphicsVGAResolution);
	SVGAResolution = new BMenuItem(lGraphicsSVGAResolution, new BMessage(SVGA_RESOLUTION_MSG));
	ResolutionMenu->AddItem(SVGAResolution);
	XGAResolution = new BMenuItem(lGraphicsXGAResolution, new BMessage(XGA_RESOLUTION_MSG));
	ResolutionMenu->AddItem(XGAResolution);
	SXGAResolution = new BMenuItem(lGraphicsSXGAResolution, new BMessage(SXGA_RESOLUTION_MSG));
	ResolutionMenu->AddItem(SXGAResolution);
	UXGAResolution = new BMenuItem(lGraphicsUXGAResolution, new BMessage(UXGA_RESOLUTION_MSG));
	ResolutionMenu->AddItem(UXGAResolution);
	
	ResolutionMenuField = new BMenuField(BRect(5,13,249,33), "graphicsresolution",
		lGraphicsResolution, ResolutionMenu, B_FOLLOW_LEFT|B_FOLLOW_TOP, B_NAVIGABLE|B_WILL_DRAW);
	ResolutionMenuField->SetDivider(65.0F);
	GraphicsSettingsBox->AddChild(ResolutionMenuField);
	
	QualityMenu = new BMenu("graphicsquality", B_ITEMS_IN_COLUMN);
	QualityMenu->SetRadioMode(true);
	QualityMenu->SetLabelFromMarked(true);

	NormalQuality = new BMenuItem(lGraphicsQualityNormal, new BMessage(NORMALQUALTY_MSG));
	ReducedQuality = new BMenuItem(lGraphicsQualityReduced, new BMessage(REDUCEDQUALTY_MSG));
	ExtremelyReducedQuality = new BMenuItem(lGraphicsQualityExtremelyReduced, new BMessage(XREDUCEDQUALTY_MSG));
	QualityMenu->AddItem(NormalQuality);
	NormalQuality->SetMarked(true);
	
	QualityMenu->AddItem(ReducedQuality);
	QualityMenu->AddItem(ExtremelyReducedQuality);
	
	QualityMenuField = new BMenuField(BRect(5,38,249,58), "graphicsquality",
		lGraphicsQuality, QualityMenu, B_FOLLOW_LEFT|B_FOLLOW_TOP, B_NAVIGABLE|B_WILL_DRAW);
	QualityMenuField->SetDivider(65.0F);
	GraphicsSettingsBox->AddChild(QualityMenuField);
	
	//"Player name:" TextControl
	PlayernameInput = new BTextControl(BRect(1,129,249,149), "playername", lPlayername, NULL,
		new BMessage(PLAYERNAEMINPUT_MSG), B_FOLLOW_LEFT|B_FOLLOW_TOP, B_NAVIGABLE|B_WILL_DRAW);
	//PlayernameInput->SetDivider(65.0F);
	PlayernameInput->SetDivider(67.0F);
	MainView->AddChild(PlayernameInput);
	PlayernameInput->SetText(getlogin());
			
	//"Game Mode" box
	GameModeBox = new AppBox(BRect(1,152,249,185), "gamemodebox", lGameMode, B_FOLLOW_LEFT|B_FOLLOW_TOP,
		B_WILL_DRAW|B_NAVIGABLE, B_FANCY_BORDER);
	NormalGameMode = new BRadioButton(BRect(5,10,100,15),"normalgamemode",
						lNormalGameMode,new BMessage(NORMALGAMEMODE_MSG));
	ExtremeGameMode = new BRadioButton(BRect(105,10,200,15),"extremegamemode",
						lExtremeGameMode,new BMessage(EXTREMEGAMEMODE_MSG));
	MainView->AddChild(GameModeBox);
	GameModeBox->AddChild(NormalGameMode);
	NormalGameMode->SetValue(B_CONTROL_ON);
	
	GameModeBox->AddChild(ExtremeGameMode);
	
	/*SoundEnabled = new BCheckBox(BRect(5,__,100,15),"soundenabled",lSoundEnabled,
					new BMessage(ENABLESOUND_MSG));
	MainView->AddChild(SoundEnabled);
	SoundEnabled->SetValue(B_CONTROL_ON);
	*/
	
	//"Start Game" button
	StartGameButton = new BButton(BRect(100,188,209,248), "startgamebtn", lStartGame,
		new BMessage(STARTGAME_MSG), B_NAVIGABLE);
	//StartGameButton->MakeDefault(true);
	StartGameButton->ResizeToPreferred();
	//move a button to the center of the window
	StartGameButton->MoveTo((Bounds().Width() - StartGameButton->Bounds().Width())/2,
							StartGameButton->Frame().top);
	MainView->AddChild(StartGameButton);
	
#ifdef USE_ZETA_LOCALEKIT
	SetLocalizedStrings();
#endif
}

//--------------------------------------------------------------------

bool CALauncherWindow::QuitRequested()
{
	be_app->PostMessage(B_QUIT_REQUESTED);
	return true;
}

//--------------------------------------------------------------------

void CALauncherWindow::MessageReceived(BMessage* message)
{
	#if DEBUG
		printf("CALauncherWindow::MessageReceived: \n");
		message->PrintToStream();
	#endif
	switch(message->what)
	{
		case STARTGAME_MSG:
		{
			entry_ref* crackattackbin = new entry_ref();
			get_ref_for_path(CrackAttackBinPath, crackattackbin);
			int arg_c = 0;
			const char *arg_v[256];
			char sarg_v[256];
						
			if (SoloModeTab->IsSelected())
			{
				arg_v[arg_c++] = "--solo";
				//Computer AI
				if (strcmp(curcomputeraimode, lComputerAINone) != 0)
				{
					if (strcmp(curcomputeraimode, lComputerAIEasy) == 0)
					{
						arg_v[arg_c++] = "--easy";
					}
					else if (strcmp(curcomputeraimode, lComputerAIMedium) == 0)
					{
						arg_v[arg_c++] = "--medium";
					}
					else if (strcmp(curcomputeraimode, lComputerAIHard) == 0)
					{
						arg_v[arg_c++] = "--hard";
					}
				}
			}
			else if (ServerModeTab->IsSelected())
			{
				arg_v[arg_c++] = "--server";
				arg_v[arg_c++] = ServerTabView->Port();
				
			}
			else if (ClientModeTab->IsSelected())
			{
				arg_v[arg_c++] = ClientTabView->Server();
				arg_v[arg_c++] = ClientTabView->Port();
			}
			
			//Graphics resolution
			arg_v[arg_c++] = "--res";
			arg_v[arg_c++] = curresolution;
			
			//Graphics quality
			if (strcmp(curquality, "") != 0)
			{
				if (strcmp(curquality, lGraphicsQualityReduced) == 0)
				{
					arg_v[arg_c++] = "--low";
				}
				else if (strcmp(curquality, lGraphicsQualityExtremelyReduced) == 0)
				{
					arg_v[arg_c++] = "--really";
					arg_v[arg_c++] = "--low";
				}
			}
			
			//Sounds
			/*if (SoundEnabled->Value() != 1)
			{
				arg_v[arg_c++] = "--nosound";
			}*/
			
			//Game mode
			if ((ExtremeGameMode->IsEnabled() == true)&&
				(ExtremeGameMode->Value() == 1))
			{
				arg_v[arg_c++] = "--extreme";
			}
			
			//Player name
			arg_v[arg_c++] = "--name";
			strcpy(sarg_v, "'");
			strcat(sarg_v, PlayernameInput->Text());
			strcat(sarg_v, "'");
			arg_v[arg_c++] = sarg_v;
			
			#if DEBUG
				printf("Command line arguments are:");
				for (int i = 0; i < arg_c; i++)
					printf(" %s", arg_v[i]);						
				printf("\n");
			#endif
			status_t sresult;
			sresult = be_roster->Launch(crackattackbin, arg_c, arg_v);
			switch (sresult)
			{
				case B_OK:
				{
					#if DEBUG
						printf("Crack Attack! has been successfully launched\n");
					#endif
				}
				break;
				case B_ALREADY_RUNNING:
				{
					#if DEBUG
						printf("Crack Attack! is already running!\n");
					#endif
				}
				break;
				case B_BAD_VALUE:
				{
					#if DEBUG
						printf("Can't launch Crack Attack!: B_BAD_VALUE\n");
					#endif
				}
				break;
				case B_LAUNCH_FAILED:
				{
					#if DEBUG
						printf("Can't launch Crack Attack!: B_LAUNCH_FAILED\n");
					#endif
				}
				break;
				default:
				{
					#if DEBUG
						printf("Can't launch Crack Attack!: Unknown error (%i)\n", int(sresult));
					#endif
				}
			}
			delete crackattackbin;
		}
		break;
		case COMPUTER_AI_NONE_MSG:
		{
			strcpy(curcomputeraimode, lComputerAINone);
			ExtremeGameMode->SetEnabled(true);
			//NormalGameMode->SetValue(1);
		}
		break;
		case COMPUTER_AI_EASY_MSG:
		{
			strcpy(curcomputeraimode, lComputerAIEasy);
			ExtremeGameMode->SetEnabled(false);
			//NormalGameMode->SetValue(1);
		}
		break;
		case COMPUTER_AI_MEDIUM_MSG:
		{
			strcpy(curcomputeraimode, lComputerAIMedium);
			ExtremeGameMode->SetEnabled(false);
		}
		break;
		case COMPUTER_AI_HARD_MSG:
		{
			strcpy(curcomputeraimode, lComputerAIHard);
			ExtremeGameMode->SetEnabled(false);
		}
		break;
		case NORMALQUALTY_MSG:
		{
			strcpy(curquality, "");
		}
		break;
		case REDUCEDQUALTY_MSG:
		{
			strcpy(curquality, lGraphicsQualityReduced);
		}
		break;
		case XREDUCEDQUALTY_MSG:
		{
			strcpy(curquality, lGraphicsQualityExtremelyReduced);
		}
		break;
		case QVGA_RESOLUTION_MSG:
		{
			strcpy(curresolution, lGraphicsQVGAResolution);
		}
		break;
		case VGA_RESOLUTION_MSG:
		{
			strcpy(curresolution, lGraphicsVGAResolution);
		}
		break;
		case SVGA_RESOLUTION_MSG:
		{
			strcpy(curresolution, lGraphicsSVGAResolution);
		}
		break;
		case XGA_RESOLUTION_MSG:
		{
			strcpy(curresolution, lGraphicsXGAResolution);
		}
		break;
		case SXGA_RESOLUTION_MSG:
		{
			strcpy(curresolution, lGraphicsSXGAResolution);
		}
		break;
		case UXGA_RESOLUTION_MSG:
		{
			strcpy(curresolution, lGraphicsUXGAResolution);
		}
		break;
		case B_ABOUT_REQUESTED:
		{
			be_app->PostMessage(B_ABOUT_REQUESTED);
		}
		break;
#ifdef USE_ZETA_LOCALEKIT
		case B_LANGUAGE_CHANGED:
		{
			SetLocalizedStrings();
		}
		break;
#endif
		default:
			BWindow::MessageReceived(message);
	}
}

//--------------------------------------------------------------------

#ifdef USE_ZETA_LOCALEKIT
void CALauncherWindow::SetLocalizedStrings()
{
	GraphicsSettingsBox->SetLabel(_T(lGraphicsSettings));
	ResolutionMenuField->SetLabel(_T(lGraphicsResolution));
	QualityMenuField->SetLabel(_T(lGraphicsQuality));
	NormalQuality->SetLabel(_T(lGraphicsQualityNormalZeta));
	ReducedQuality->SetLabel(_T(lGraphicsQualityReduced));
	ExtremelyReducedQuality->SetLabel(_T(lGraphicsQualityExtremelyReduced));
	PlayernameInput->SetLabel(_T(lPlayername));
	GameModeBox->SetLabel(_T(lGameMode));
	NormalGameMode->SetLabel(_T(lNormalGameMode));
	ExtremeGameMode->SetLabel(_T(lExtremeGameMode));
	//SoundEnabled->SetLabel(_T(lSoundEnabled));
	StartGameButton->SetLabel(_T(lStartGame));
	
	SoloTabView->SetLocalizedStrings();
	ServerTabView->SetLocalizedStrings();
	ClientTabView->SetLocalizedStrings();
	PlayMode->Invalidate();
}
#endif
