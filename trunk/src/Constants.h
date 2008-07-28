//========================================================================
//	Constants.h
//	Miscellaneous constants and definitions
//	Copyright 2006-2008 Sergey Kazenyuk, All Rights Reserved.
//	Distributed under the terms of the MIT License.
//========================================================================

#ifndef CONSTANTS_H
#define CONSTANTS_H

#define App_Name "CrackAttack! Launcher"
#define App_Sig "application/x-vnd.kazenyuk-CrackAttackLauncher"
#define App_Version "1.0.0b1"

#ifdef B_ZETA_VERSION
#define USE_ZETA_LOCALEKIT
#endif

#ifdef USE_ZETA_LOCALEKIT
#include <locale/Locale.h>
#endif

//====================================================================
// Message commands (message->what)
//====================================================================
const uint32 COMPUTER_AI_NONE_MSG	= 'AINo';
const uint32 COMPUTER_AI_EASY_MSG	= 'AIEa';
const uint32 COMPUTER_AI_MEDIUM_MSG	= 'AIMe';
const uint32 COMPUTER_AI_HARD_MSG	= 'AIHa';

const uint32 SERVERADDRESS_MSG		= 'SeAd';
const uint32 SERVERPORT_MSG			= 'SePo';

const uint32 QVGA_RESOLUTION_MSG	= 'QVGA';
const uint32 VGA_RESOLUTION_MSG		= 'VGAR';
const uint32 SVGA_RESOLUTION_MSG	= 'SVGA';
const uint32 XGA_RESOLUTION_MSG		= 'XGAR';
const uint32 SXGA_RESOLUTION_MSG	= 'SXGA';
const uint32 UXGA_RESOLUTION_MSG	= 'UXGA';

const uint32 NORMALQUALTY_MSG		= 'NorQ';
const uint32 REDUCEDQUALTY_MSG		= 'RedQ';
const uint32 XREDUCEDQUALTY_MSG		= 'XReQ';

const uint32 PLAYERNAEMINPUT_MSG	= 'PnIn';

const uint32 NORMALGAMEMODE_MSG		= 'NGaM';
const uint32 EXTREMEGAMEMODE_MSG	= 'XGaM';

const uint32 ENABLESOUND_MSG		= 'EnSo';

const uint32 STARTGAME_MSG			= 'StGm';

//====================================================================
// Paths to some files
//====================================================================

#define CrackAttackBinPath	"/boot/apps/CrackAttack!/CrackAttack"

//====================================================================
// Labels and titles
//====================================================================

// Buttons
const char lStartGame[]			=	"Start Game";

// Boxes
const char lGameMode[]			=	"Game Mode";
const char lGraphicsSettings[]	=	"Graphics Settings";

const char lComputerAI[]		=	"Computer AI:";
const char lComputerAINone[]	=	"None";
const char lComputerAIEasy[]	=	"Easy";
const char lComputerAIMedium[]	=	"Medium";
const char lComputerAIHard[]	=	"Hard";

const char lServerAddress[]		=	"Server:";
const char lServerPort[]		=	"Port:";
const char lServerLocalhost[]	=	"localhost";

const char lGraphicsResolution[]		=	"Resolution:";
const char lGraphicsQVGAResolution[]	=	"320x240";
const char lGraphicsVGAResolution[]		=	"640x480";
const char lGraphicsSVGAResolution[]	=	"800x600";
const char lGraphicsXGAResolution[]		=	"1024x768";
const char lGraphicsSXGAResolution[]	=	"1280x1024";
const char lGraphicsUXGAResolution[]	=	"1600x1200";

const char lGraphicsQuality[]			=	"Quality:";
const char lGraphicsQualityNormal[]		=	"Normal";
#ifdef USE_ZETA_LOCALEKIT
const char lGraphicsQualityNormalZeta[]	=	"qNormal";
#endif
const char lGraphicsQualityReduced[]	=	"Reduced";
const char lGraphicsQualityExtremelyReduced[]	=	"Extremely Reduced";

const char lNormalGameMode[]	=	"Normal";
const char lExtremeGameMode[]	=	"X-treme";

const char lSoundEnabled[]		=	"Enable sound";

//Game mode tabs
const char lSoloGameMode[]		=	"Solo";
const char lServerGameMode[]	=	"Server";
const char lClientGameMode[]	=	"Client";

const char lPlayername[]		=	"Player name:";

#endif
