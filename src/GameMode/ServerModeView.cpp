//========================================================================
//	ServerModeView.cpp
//	
//	Copyright 2006 Sergey Kazenyuk, All Rights Reserved.
//	Distributed under the terms of the MIT License.
//========================================================================

#include "ServerModeView.h"
#include "Constants.h"

//====================================================================

ServerModeView::ServerModeView(BRect frame)
	: BView(frame, lServerGameMode, B_FOLLOW_ALL_SIDES, B_WILL_DRAW)
{
	SetViewColor(ui_color(B_PANEL_BACKGROUND_COLOR));

	ServerAddress = new BTextControl(BRect(5,5,165,25), "serveraddress", lServerAddress, lServerLocalhost,
		new BMessage(SERVERADDRESS_MSG), B_FOLLOW_LEFT|B_FOLLOW_TOP, B_NAVIGABLE|B_WILL_DRAW);
	
	ServerPort = new BTextControl(BRect(170,5,240,25), "serverport", lServerPort, NULL,
		new BMessage(SERVERPORT_MSG), B_FOLLOW_LEFT|B_FOLLOW_TOP, B_NAVIGABLE|B_WILL_DRAW);
	
	ServerAddress->SetDivider(40.0F);
	ServerAddress->SetEnabled(false);
	AddChild(ServerAddress);
	
	
	ServerPort->SetDivider(28.0F);
	AddChild(ServerPort);
}

//--------------------------------------------------------------------
	
void ServerModeView::Draw(BRect updateRect)
{
	
}

//--------------------------------------------------------------------

const char *ServerModeView::Port()
{
	return ServerPort->Text();
}

//--------------------------------------------------------------------

#ifdef USE_ZETA_LOCALEKIT
void ServerModeView::SetLocalizedStrings()
{
	SetName(_T(lServerGameMode));
	ServerAddress->SetLabel(_T(lServerAddress));
	ServerPort->SetLabel(_T(lServerPort));
}
#endif
