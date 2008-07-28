//========================================================================
//	SoloModeView.cpp
//	
//	Copyright 2006 Sergey Kazenyuk, All Rights Reserved.
//	Distributed under the terms of the MIT License.
//========================================================================

#include "SoloModeView.h"
#include "Constants.h"

//====================================================================

SoloModeView::SoloModeView(BRect frame)
	: BView(frame, lSoloGameMode, B_FOLLOW_ALL_SIDES, B_WILL_DRAW)
{
	SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
	
	ComputerAIMenu = new BMenu("computeraimenu", B_ITEMS_IN_COLUMN);
	ComputerAIMenu->SetRadioMode(true);
	ComputerAIMenu->SetLabelFromMarked(true);
	None = new BMenuItem(lComputerAINone, new BMessage(COMPUTER_AI_NONE_MSG));
	Easy = new BMenuItem(lComputerAIEasy, new BMessage(COMPUTER_AI_EASY_MSG));
	Medium = new BMenuItem(lComputerAIMedium, new BMessage(COMPUTER_AI_MEDIUM_MSG));
	Hard = new BMenuItem(lComputerAIHard, new BMessage(COMPUTER_AI_HARD_MSG));
	ComputerAIMenu->AddItem(None);
	None->SetMarked(true);
	
	//Easy = new BMenuItem(lComputerAIEasy, new BMessage(COMPUTER_AI_EASY_MSG));
	ComputerAIMenu->AddItem(Easy);
		
	//Medium = new BMenuItem(lComputerAIMedium, new BMessage(COMPUTER_AI_MEDIUM_MSG));
	ComputerAIMenu->AddItem(Medium);
	
	//Hard = new BMenuItem(lComputerAIHard, new BMessage(COMPUTER_AI_HARD_MSG));
	ComputerAIMenu->AddItem(Hard);
	
	ComputerAIMenuField = new BMenuField(BRect(5,5,249,25), "computerai",
		lComputerAI, ComputerAIMenu, B_FOLLOW_LEFT|B_FOLLOW_TOP, B_NAVIGABLE|B_WILL_DRAW);
	ComputerAIMenuField->SetDivider(75.0F);
	AddChild(ComputerAIMenuField);
}

//--------------------------------------------------------------------
	
void SoloModeView::Draw(BRect updateRect)
{
	
}

//--------------------------------------------------------------------

#ifdef USE_ZETA_LOCALEKIT
void SoloModeView::SetLocalizedStrings()
{
	SetName(_T(lSoloGameMode));
	ComputerAIMenuField->SetLabel(_T(lComputerAI));
	None->SetLabel(_T(lComputerAINone));
	Easy->SetLabel(_T(lComputerAIEasy));
	Medium->SetLabel(_T(lComputerAIMedium));
	Hard->SetLabel(_T(lComputerAIHard));
}
#endif
