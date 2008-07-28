//========================================================================
//	SoloModeView.h
//	
//	Copyright 2006 Sergey Kazenyuk, All Rights Reserved.
//	Distributed under the terms of the MIT License.
//========================================================================

#ifndef SOLOMODEVIEW_H
#define SOLOMODEVIEW_H

#include <View.h>
#include <Menu.h>
#include <MenuItem.h>
#include <MenuField.h>

#include "Constants.h"

//====================================================================

class SoloModeView : public BView
{
	public:
						SoloModeView(BRect frame);
		virtual void	Draw(BRect updateRect);
		//virtual void	MessageReceived(BMessage* message);
#ifdef USE_ZETA_LOCALEKIT
		void			SetLocalizedStrings();
#endif
	private:
		BMenuField		*ComputerAIMenuField;
		BMenu			*ComputerAIMenu;
		BMenuItem		*None;
		BMenuItem		*Easy;
		BMenuItem		*Medium;
		BMenuItem		*Hard;
};
	
#endif
