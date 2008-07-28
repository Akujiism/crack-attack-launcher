//========================================================================
//	AppBox.cpp
//	
//	Copyright 2006 Sergey Kazenyuk, All Rights Reserved.
//	Distributed under the terms of the MIT License.
//========================================================================

#include "AppBox.h"

//====================================================================

AppBox::AppBox(BRect frame, const char *name, const char *label,
			uint32 resizeMask, uint32 flags, border_style style)
	:BBox(frame, name, resizeMask, flags, style)
{
	SetLabel(label);
}
