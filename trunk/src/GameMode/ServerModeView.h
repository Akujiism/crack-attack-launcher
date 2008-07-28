//========================================================================
//	ServerModeView.h
//	
//	Copyright 2006 Sergey Kazenyuk, All Rights Reserved.
//	Distributed under the terms of the MIT License.
//========================================================================

#ifndef SERVERMODEVIEW_H
#define SERVERMODEVIEW_H

#include <View.h>
#include <TextControl.h>

#include "Constants.h"

//====================================================================

class ServerModeView : public BView
{
	public:
						ServerModeView(BRect frame);
		virtual void	Draw(BRect updateRect);
		//virtual void	MessageReceived(BMessage* message);
		const char		*Port();
#ifdef USE_ZETA_LOCALEKIT
		void			SetLocalizedStrings();
#endif
	private:
		BTextControl	*ServerAddress;
		BTextControl	*ServerPort;
		
};
	
#endif
