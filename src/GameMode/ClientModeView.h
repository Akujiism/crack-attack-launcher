//========================================================================
//	ClientModeView.h
//	
//	Copyright 2006 Sergey Kazenyuk, All Rights Reserved.
//	Distributed under the terms of the MIT License.
//========================================================================

#ifndef CLIENTMODEVIEW_H
#define CLIENTMODEVIEW_H

#include <View.h>
#include <TextControl.h>

#include "Constants.h"

//====================================================================

class ClientModeView : public BView
{
	public:
						ClientModeView(BRect frame);
		virtual void	Draw(BRect updateRect);
		//virtual void	MessageReceived(BMessage* message);
		const char		*Server();
		const char		*Port();
#ifdef USE_ZETA_LOCALEKIT
		void			SetLocalizedStrings();
#endif
	private:
		BTextControl	*ServerAddress;
		BTextControl	*ServerPort;
};
	
#endif
