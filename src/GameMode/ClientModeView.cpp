//========================================================================
//	ClientModeView.cpp
//	
//	Copyright 2006 Sergey Kazenyuk, All Rights Reserved.
//	Distributed under the terms of the MIT License.
//========================================================================

#include "ClientModeView.h"
#include "Constants.h"

//====================================================================

ClientModeView::ClientModeView(BRect frame)
	: BView(frame, lClientGameMode, B_FOLLOW_ALL_SIDES, B_WILL_DRAW)
{
	SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));
	
	ServerAddress = new BTextControl(BRect(5,5,165,25), "serveraddress", lServerAddress, NULL,
		new BMessage(SERVERADDRESS_MSG), B_FOLLOW_LEFT|B_FOLLOW_TOP, B_NAVIGABLE|B_WILL_DRAW);
	
	ServerPort = new BTextControl(BRect(170,5,240,25), "serverport", lServerPort, NULL,
		new BMessage(SERVERPORT_MSG), B_FOLLOW_LEFT|B_FOLLOW_TOP, B_NAVIGABLE|B_WILL_DRAW);
	
	ServerAddress->SetDivider(40.0F);
	AddChild(ServerAddress);
	//ServerAddress->SetText("");
	
	
	ServerPort->SetDivider(28.0F);
	AddChild(ServerPort);
}

//--------------------------------------------------------------------
	
void ClientModeView::Draw(BRect updateRect)
{
	
}

//--------------------------------------------------------------------

const char *ClientModeView::Server()
{
	return ServerAddress->Text();
}

//--------------------------------------------------------------------

const char *ClientModeView::Port()
{
	return ServerPort->Text();
}

//--------------------------------------------------------------------

#ifdef USE_ZETA_LOCALEKIT
void ClientModeView::SetLocalizedStrings()
{
	SetName(_T(lClientGameMode));
	ServerAddress->SetLabel(_T(lServerAddress));
	ServerPort->SetLabel(_T(lServerPort));
}
#endif
