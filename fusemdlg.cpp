//=========================================================================//
//                                                                         //
//  PonyProg - Serial Device Programmer                                    //
//                                                                         //
//  Copyright (C) 1997-2007   Claudio Lanconelli                           //
//                                                                         //
//  http://ponyprog.sourceforge.net                                        //
//                                                                         //
//-------------------------------------------------------------------------//
// $Id$
//-------------------------------------------------------------------------//
//                                                                         //
// This program is free software; you can redistribute it and/or           //
// modify it under the terms of the GNU  General Public License            //
// as published by the Free Software Foundation; either version2 of        //
// the License, or (at your option) any later version.                     //
//                                                                         //
// This program is distributed in the hope that it will be useful,         //
// but WITHOUT ANY WARRANTY; without even the implied warranty of          //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU       //
// General Public License for more details.                                //
//                                                                         //
// You should have received a copy of the GNU  General Public License      //
// along with this program (see COPYING);     if not, write to the         //
// Free Software Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA. //
//                                                                         //
//-------------------------------------------------------------------------//
//=========================================================================//

//=======================================================================
//@V@:Note: This file generated by vgen V1.07 (12:35:57 03 Oct 1999).
//	fusemdlg.cpp:	Source for fuseModalDialog class
//=======================================================================

#include <stdio.h>
#include <stdlib.h>

#include "fusemdlg.h"
#include <v/vnotice.h>

#include "eeptypes.h"

#define	LOCKPACKSIZE	8
#define	FUSEPACKSIZE	LOCKPACKSIZE

typedef struct {
	long type;

	BYTE lockenable3;
	char *locklabel3[LOCKPACKSIZE];
	BYTE lockenable2;
	char *locklabel2[LOCKPACKSIZE];
	BYTE lockenable1;
	char *locklabel1[LOCKPACKSIZE];
	BYTE lockenable0;
	char *locklabel0[LOCKPACKSIZE];

	WORD fuseenable3;
	char *fuselabel3[FUSEPACKSIZE];
	WORD fuseenable2;
	char *fuselabel2[FUSEPACKSIZE];
	WORD fuseenable1;
	char *fuselabel1[FUSEPACKSIZE];
	WORD fuseenable0;
	char *fuselabel0[FUSEPACKSIZE];
} FuseBit;

static const FuseBit labels[] = {
	{ AT90S0000,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x06,{0,0,0,0,0,"Lock2 ","Lock1 ",0},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00,{0} },

	{ AT90S1200,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x06,{0,0,0,0,0,"Lock2 ","Lock1 ",0},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00,{0} },
	{ AT90S2313,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x06,{0,0,0,0,0,"Lock2 ","Lock1 ",0},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00,{0} },
	{ AT90S4414,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x06,{0,0,0,0,0,"Lock2 ","Lock1 ",0},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00,{0} },
	{ AT90S8515,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x06,{0,0,0,0,0,"Lock2 ","Lock1 ",0},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00,{0} },

	{ AT90S4434,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x06,{0,0,0,0,0,"Lock2 ","Lock1 ",0},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x01,{0,0,0,0,0,0,0,"FSTRT "} },
	{ AT90S8535,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x06,{0,0,0,0,0,"Lock2 ","Lock1 ",0},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x01,{0,0,0,0,0,0,0,"FSTRT "} },

	{ AT90S2333,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x06,{0,0,0,0,0,"Lock2 ","Lock1 ",0},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x1f,{0,0,"SPIEN ","BODLEVEL ","BODEN ","CKSEL2 ","CKSEL1 ","CKSEL0 "} },
	{ AT90S4433,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x06,{0,0,0,0,0,"Lock2 ","Lock1 ",0},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x1f,{0,0,"SPIEN ","BODLEVEL ","BODEN ","CKSEL2 ","CKSEL1 ","CKSEL0 "} },

	{ AT90S2323,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x06,{0,0,0,0,0,"Lock2 ","Lock1 ",0},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x01,{0,0,0,0,0,0,0,"FSTRT "} },
	{ AT90S2343,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x06,{0,0,0,0,0,"Lock2 ","Lock1 ",0},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x01,{0,0,0,0,0,0,0,"RCEN "} },

	{ AT90S8534,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x06,{0,0,0,0,0,"Lock2 ","Lock1 ",0},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00,{0} },

	{ ATtiny10,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x06,{0,0,0,0,0,"Lock2 ","Lock1 ",0},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00,{0} },
	{ ATtiny11,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x06,{0,0,0,0,0,"Lock2 ","Lock1 ",0},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x17,{0,0,0,"FSTRT ","RSTDISBL ","CKSEL2 ","CKSEL1 ","CKSEL0 "} },
	{ ATtiny12,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x06,{0,0,0,0,0,"Lock2 ","Lock1 ",0},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0xCF,{"BODLEVEL ","BODEN ","SPIEN ","RSTDISBL ","CKSEL3 ","CKSEL2 ","CKSEL1 ","CKSEL0 "} },
	{ ATtiny15,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x06,{0,0,0,0,0,"Lock2 ","Lock1 ",0},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0xC3,{"BODLEVEL ","BODEN ","SPIEN ","RSTDISBL ",0,0,"CKSEL1 ","CKSEL0 "} },
	{ ATtiny22,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x06,{0,0,0,0,0,"Lock2 ","Lock1 ",0},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x01,{0,0,0,0,0,0,0,"RCEN "} },
	{ ATtiny26,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x03,{0,0,0,0,0, 0,"Lock2 ","Lock1 "},
		0x00,{0}, 0x00,{0}, 0x07,{0,0,0,"RSTDISBL ","SPIEN ","EESAVE ","BODLEVEL ","BODEN "}, 0xFF,{"PLLCK ","CKOPT ","SUT1 ","SUT0 ","CKSEL3 ","CKSEL2 ","CKSEL1 ","CKSEL0 "} },
	{ ATtiny28,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x06,{0,0,0,0,0,"Lock2 ","Lock1 ",0},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00,{0} },

	{ ATtiny2313,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x03,{0,0,0,0,0, 0,"Lock2 ","Lock1 "},
		0x00,{0}, 0x01,{0,0,0,0, 0,0,0, "SPMEN "}, 0xDE,{"DWEN ","EESAVE ","SPIEN ","WDTON ","BODLEVEL2 ","BODLEVEL1 ","BODLEVEL0 ","RSTDISBL "}, 0xFF,{"CKDIV8 ","CKOUT ","SUT1 ","SUT0 ","CKSEL3 ","CKSEL2 ","CKSEL1 ","CKSEL0 "} },

	{ ATmega603,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x06,{0,0,0,0,0,"Lock2 ","Lock1 ",0},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x0B,{0,0,0,0,"EESAVE ",0,"SUT1 ","SUT0 "}},
	{ ATmega103,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x06,{0,0,0,0,0,"Lock2 ","Lock1 ",0},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x0B,{0,0,0,0,"EESAVE ",0,"SUT1 ","SUT0 "}},
	{ ATmega8,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x3F, {0,0,"BootLock12 ","BootLock11 ","BootLock02 ","BootLock01 ","Lock2 ","Lock1 "},
		0x00,{0}, 0x00,{0}, 0x5F,{"RSTDISBL ","WDTON  ","SPIEN ","CKOPT ","EESAVE ","BOOTSZ1 ","BOOTSZ0 ","BOOTRST "}, 0xFF,{"BODLEVEL ","BODEN ","SUT1 ","SUT0 ","CKSEL3 ","CKSEL2 ","CKSEL1 ","CKSEL0 "} },
	{ ATmega8515,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x3F, {0,0,"BootLock12 ","BootLock11 ","BootLock02 ","BootLock01 ","Lock2 ","Lock1 "},
		0x00,{0}, 0x00,{0}, 0xDF,{"S8515C ","WDTON  ","SPIEN ","CKOPT ","EESAVE ","BOOTSZ1 ","BOOTSZ0 ","BOOTRST "}, 0xFF,{"BODLEVEL ","BODEN ","SUT1 ","SUT0 ","CKSEL3 ","CKSEL2 ","CKSEL1 ","CKSEL0 "} },
	{ ATmega8535,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x3F, {0,0,"BootLock12 ","BootLock11 ","BootLock02 ","BootLock01 ","Lock2 ","Lock1 "},
		0x00,{0}, 0x00,{0}, 0xDF,{"S8535C ","WDTON  ","SPIEN ","CKOPT ","EESAVE ","BOOTSZ1 ","BOOTSZ0 ","BOOTRST "}, 0xFF,{"BODLEVEL ","BODEN ","SUT1 ","SUT0 ","CKSEL3 ","CKSEL2 ","CKSEL1 ","CKSEL0 "} },
	{ ATmega64,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x3F, {0,0,"BootLock12 ","BootLock11 ","BootLock02 ","BootLock01 ","Lock2 ","Lock1 "},
		0x00,{0}, 0x03,{0,0,0,0, 0,0, "M103C ", "WDTON  "}, 0xDF,{"OCDEN ","JTAGEN ","SPIEN ","CKOPT ","EESAVE ","BOOTSZ1 ","BOOTSZ0 ","BOOTRST "}, 0xFF,{"BODLEVEL ","BODEN ","SUT1 ","SUT0 ","CKSEL3 ","CKSEL2 ","CKSEL1 ","CKSEL0 "} },
	{ ATmega128,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x3F, {0,0,"BootLock12 ","BootLock11 ","BootLock02 ","BootLock01 ","Lock2 ","Lock1 "},
		0x00,{0}, 0x03,{0,0,0,0, 0,0, "M103C ", "WDTON  "}, 0xDF,{"OCDEN ","JTAGEN ","SPIEN ","CKOPT ","EESAVE ","BOOTSZ1 ","BOOTSZ0 ","BOOTRST "}, 0xFF,{"BODLEVEL ","BODEN ","SUT1 ","SUT0 ","CKSEL3 ","CKSEL2 ","CKSEL1 ","CKSEL0 "} },
	{ ATmega16,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x3F, {0,0,"BootLock12 ","BootLock11 ","BootLock02 ","BootLock01 ","Lock2 ","Lock1 "},
		0x00,{0}, 0x00,{0}, 0xDF,{"OCDEN ","JTAGEN ","SPIEN ","CKOPT ","EESAVE ","BOOTSZ1 ","BOOTSZ0 ","BOOTRST "}, 0xFF,{"BODLEVEL ","BODEN ","SUT1 ","SUT0 ","CKSEL3 ","CKSEL2 ","CKSEL1 ","CKSEL0 "} },
	{ ATmega161,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x3F,{0,0,"BootLock12 ","BootLock11 ","BootLock02 ","BootLock01 ","Lock2 ","Lock1 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x7F,{0,"BOOTRST ","SPIEN ","BODLEVEL ","BODEN ","CKSEL2 ","CKSEL1 ","CKSEL0 "} },
	{ ATmega163,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x3F,{0,0,"BootLock12 ","BootLock11 ","BootLock02 ","BootLock01 ","Lock2 ","Lock1 "},
		0x00,{0}, 0x00,{0}, 0x07,{0,0,0,0,0,"BOOTSZ1 ","BOOTSZ0 ","BOOTRST "}, 0xCF,{"BODLEVEL ","BODEN ",0,0,"CKSEL3 ","CKSEL2 ","CKSEL1 ","CKSEL0 "} },
	{ ATmega162,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x3F, {0,0,"BootLock12 ","BootLock11 ","BootLock02 ","BootLock01 ","Lock2 ","Lock1 "},
		0x00,{0}, 0x1E,{0,0,0,"M161C ","BOD2LEVEL ","BOD1LEVEL ","BOD0LEVEL ",0}, 0xDF,{"OCDEN ","JTAGEN ","SPIEN ","WDTON  ","EESAVE ","BOOTSZ1 ","BOOTSZ0 ","BOOTRST "}, 0xFF,{"CKDIV8 ","CKOUT ","SUT1 ","SUT0 ","CKSEL3 ","CKSEL2 ","CKSEL1 ","CKSEL0 "} },
	{ ATmega169,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x3F, {0,0,"BootLock12 ","BootLock11 ","BootLock02 ","BootLock01 ","Lock2 ","Lock1 "},
		0x00,{0}, 0x0E,{0,0,0,0,"BOD2LEVEL ","BOD1LEVEL ","BOD0LEVEL ","RSTDISBL "}, 0xDF,{"OCDEN ","JTAGEN ","SPIEN ","WDTON  ","EESAVE ","BOOTSZ1 ","BOOTSZ0 ","BOOTRST "}, 0xFF,{"CKDIV8 ","CKOUT ","SUT1 ","SUT0 ","CKSEL3 ","CKSEL2 ","CKSEL1 ","CKSEL0 "} },
	{ ATmega323,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x3F, {0,0,"BootLock12 ","BootLock11 ","BootLock02 ","BootLock01 ","Lock2 ","Lock1 "},
		0x00,{0}, 0x00,{0}, 0xCF,{"OCDEN ","JTAGEN ","SPIEN ",0,"EESAVE ","BOOTSZ1 ","BOOTSZ0 ","BOOTRST "}, 0xCF,{"BODLEVEL ","BODEN ",0,0,"CKSEL3 ","CKSEL2 ","CKSEL1 ","CKSEL0 "} },
	{ ATmega32,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x3F, {0,0,"BootLock12 ","BootLock11 ","BootLock02 ","BootLock01 ","Lock2 ","Lock1 "},
		0x00,{0}, 0x00,{0}, 0xDF,{"OCDEN ","JTAGEN ","SPIEN ","CKOPT ","EESAVE ","BOOTSZ1 ","BOOTSZ0 ","BOOTRST "}, 0xFF,{"BODLEVEL ","BODEN ","SUT1 ","SUT0 ","CKSEL3 ","CKSEL2 ","CKSEL1 ","CKSEL0 "} },

	{ AT89S8252,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0xE0,{"LB1 ","LB2 ","LB3 ",0, 0,0,0,0},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00,{0} },
	{ AT89S53,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0xE0,{"LB1 ","LB2 ","LB3 ",0, 0,0,0,0},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00,{0} },

	{ PIC12508,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x1F,{0,0,0,"MCLRE ","CP ","WDTE ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00,{0} },
	{ PIC12509,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x1F,{0,0,0,"MCLRE ","CP ","WDTE ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00,{0} },
	{ PIC12508A,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x1F,{0,0,0,"MCLRE ","CP ","WDTE ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00,{0} },
	{ PIC12509A,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x1F,{0,0,0,"MCLRE ","CP ","WDTE ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00,{0} },
	{ PIC12E518,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x1F,{0,0,0,"MCLRE ","CP ","WDTE ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00,{0} },
	{ PIC12E519,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x1F,{0,0,0,"MCLRE ","CP ","WDTE ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00,{0} },

 	{ PIC12671,
		0x00,{0}, 0x00,{0}, 0x3F,{0,0,"CP1 ","CP0 ","CP1 ","CP0 ","CP1 ","CP0 "}, 0xFF,{"MCLRE ","CP1 ","CP0 ","PWRTE ","WDTE ","FOSC2 ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00,{0} },
 	{ PIC12672,
		0x00,{0}, 0x00,{0}, 0x3F,{0,0,"CP1 ","CP0 ","CP1 ","CP0 ","CP1 ","CP0 "}, 0xFF,{"MCLRE ","CP1 ","CP0 ","PWRTE ","WDTE ","FOSC2 ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00,{0} },
 	{ PIC12673,
		0x00,{0}, 0x00,{0}, 0x3F,{0,0,"CP1 ","CP0 ","CP1 ","CP0 ","CP1 ","CP0 "}, 0xFF,{"MCLRE ","CP1 ","CP0 ","PWRTE ","WDTE ","FOSC2 ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00,{0} },
 	{ PIC12674,
		0x00,{0}, 0x00,{0}, 0x3F,{0,0,"CP1 ","CP0 ","CP1 ","CP0 ","CP1 ","CP0 "}, 0xFF,{"MCLRE ","CP1 ","CP0 ","PWRTE ","WDTE ","FOSC2 ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00,{0} },

	{ PIC1683,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x1F,{0,0,0,"CP ","PWRTE ","WDTE ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00,{0} },
	{ PIC1684,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x1F,{0,0,0,"CP ","PWRTE ","WDTE ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00,{0} },
	{ PIC1684A,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x1F,{0,0,0,"CP ","PWRTE ","WDTE ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00,{0} },

	{ PIC16870,
		0x00,{0}, 0x00,{0}, 0x3B,{0,0,"CP1 ", "CP0 ", "RESV ", 0, "WRT ", "CPD "}, 0xFF,{"LVP ","BODEN ","CP1 ","CP0 ","PWRTE ","WDTE ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00, {0} },
	{ PIC16871,
		0x00,{0}, 0x00,{0}, 0x3B,{0,0,"CP1 ", "CP0 ", "RESV ", 0, "WRT ", "CPD "}, 0xFF,{"LVP ","BODEN ","CP1 ","CP0 ","PWRTE ","WDTE ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00, {0} },
	{ PIC16872,
		0x00,{0}, 0x00,{0}, 0x3B,{0,0,"CP1 ", "CP0 ", "RESV ", 0, "WRT ", "CPD "}, 0xFF,{"LVP ","BODEN ","CP1 ","CP0 ","PWRTE ","WDTE ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00, {0} },
	{ PIC16873,
		0x00,{0}, 0x00,{0}, 0x3B,{0,0,"CP1 ", "CP0 ", "RESV ", 0, "WRT ", "CPD "}, 0xFF,{"LVP ","BODEN ","CP1 ","CP0 ","PWRTE ","WDTE ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00, {0} },
	{ PIC16874,
		0x00,{0}, 0x00,{0}, 0x3B,{0,0,"CP1 ", "CP0 ", "RESV ", 0, "WRT ", "CPD "}, 0xFF,{"LVP ","BODEN ","CP1 ","CP0 ","PWRTE ","WDTE ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00, {0} },
	{ PIC16876,
		0x00,{0}, 0x00,{0}, 0x3B,{0,0,"CP1 ", "CP0 ", "RESV ", 0, "WRT ", "CPD "}, 0xFF,{"LVP ","BODEN ","CP1 ","CP0 ","PWRTE ","WDTE ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00, {0} },
	{ PIC16877,
		0x00,{0}, 0x00,{0}, 0x3B,{0,0,"CP1 ", "CP0 ", "RESV ", 0, "WRT ", "CPD "}, 0xFF,{"LVP ","BODEN ","CP1 ","CP0 ","PWRTE ","WDTE ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00, {0} },
	{ PIC16873A,
		0x00,{0}, 0x00,{0}, 0x2F,{0,0,"CP ",0,"DEBUG ","WRT1 ","WRT0 ", "CPD "}, 0xCF,{"LVP ","BOREN ",0,0,"/PWRTEN ","WDTEN ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00, {0} },
	{ PIC16874A,
		0x00,{0}, 0x00,{0}, 0x2F,{0,0,"CP ",0,"DEBUG ","WRT1 ","WRT0 ", "CPD "}, 0xCF,{"LVP ","BOREN ",0,0,"/PWRTEN ","WDTEN ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00, {0} },
	{ PIC16876A,
		0x00,{0}, 0x00,{0}, 0x2F,{0,0,"CP ",0,"DEBUG ","WRT1 ","WRT0 ", "CPD "}, 0xCF,{"LVP ","BOREN ",0,0,"/PWRTEN ","WDTEN ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00, {0} },
	{ PIC16877A,
		0x00,{0}, 0x00,{0}, 0x2F,{0,0,"CP ",0,"DEBUG ","WRT1 ","WRT0 ", "CPD "}, 0xCF,{"LVP ","BOREN ",0,0,"/PWRTEN ","WDTEN ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00, {0} },
	{ PIC16627,
		0x00,{0}, 0x00,{0}, 0x3D,{0,0,"CP1 ","CP0 ","CP1 ","CP0 ",0, "CPD "}, 0xFF,{"LVP ","BOREN ","MCLRE ","FOSC2 ","/PWRTEN ","WDTEN ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00, {0} },
	{ PIC16628,
		0x00,{0}, 0x00,{0}, 0x3D,{0,0,"CP1 ","CP0 ","CP1 ","CP0 ",0, "CPD "}, 0xFF,{"LVP ","BOREN ","MCLRE ","FOSC2 ","/PWRTEN ","WDTEN ","FOSC1 ","FOSC0 "},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00, {0} },

	{ 0,
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00, {0},
		0x00,{0}, 0x00,{0}, 0x00,{0}, 0x00, {0} }	//EndTag
};

static int FindLabels(long type)
{
	int k;
	int retval = -1;

	for (k = 0; labels[k].type; k++)
	{
		if (labels[k].type == type)
		{
			retval = k;
			break;
		}
	}

	return retval;
}

int SetCommandObject(const int id, const int val, CommandObject* CmdList);
int SetCommandSensitive(const int id, const int val, CommandObject* CmdList);
int SetCommandLabel(const int id, char *str, CommandObject* CmdList);
int SetCommandHidden(const int id, const bool val, CommandObject* CmdList);
int SetCommandArrayHidden(const int id, const int n, const bool val, CommandObject* CmdList);

int GetCommandObject(const int id, CommandObject* CmdList);

int SetCBelow(const int id, const ItemVal val, CommandObject* CmdList);

//@V@:BeginIDs
enum {
	lblMainMsg = 5000,

	frmLock,
	frmFuses,

	frmLock0,
	frmLock1,
	frmLock2,
	frmLock3,

	frmFuses0,
	frmFuses1,
	frmFuses2,
	frmFuses3,

	chk7_L0,
	chk6_L0,
	chk5_L0,
	chk4_L0,
	chk3_L0,
	chk2_L0,
	chk1_L0,
	chk0_L0,

	chk7_L1,
	chk6_L1,
	chk5_L1,
	chk4_L1,
	chk3_L1,
	chk2_L1,
	chk1_L1,
	chk0_L1,

	chk7_L2,
	chk6_L2,
	chk5_L2,
	chk4_L2,
	chk3_L2,
	chk2_L2,
	chk1_L2,
	chk0_L2,

	chk7_L3,
	chk6_L3,
	chk5_L3,
	chk4_L3,
	chk3_L3,
	chk2_L3,
	chk1_L3,
	chk0_L3,

	chk7_F0,
	chk6_F0,
	chk5_F0,
	chk4_F0,
	chk3_F0,
	chk2_F0,
	chk1_F0,
	chk0_F0,

	chk7_F1,
	chk6_F1,
	chk5_F1,
	chk4_F1,
	chk3_F1,
	chk2_F1,
	chk1_F1,
	chk0_F1,

	chk7_F2,
	chk6_F2,
	chk5_F2,
	chk4_F2,
	chk3_F2,
	chk2_F2,
	chk1_F2,
	chk0_F2,

	chk7_F3,
	chk6_F3,
	chk5_F3,
	chk4_F3,
	chk3_F3,
	chk2_F3,
	chk1_F3,
	chk0_F3,

	blk0,
	blk1,
	blk2,

	frmFill,

	lblFrom,
	lblTo,
	lblVal,

	txiFrom,
	txiTo,
	txiVal,

	frmHlp,
	chkHlp1,
	chkHlp0,

	btn0,
	btn1,
	btnProg,
	btnRead
};
//@V@:EndIds

static char *deflbl[] = {
	" 7",
	" 6",
	" 5",
	" 4",
	" 3",
	" 2",
	" 1",
	" 0"
};

//@V@:BeginDialogCmd DefaultCmds
static DialogCmd FuseDialogCmds[] =
{
	{C_Label, lblMainMsg, 0,"X",NoList,CA_MainMsg,isSens,NoFrame, 0, 0},

	{C_Frame, frmLock,0,"Lock",NoList,CA_None,isSens,NoFrame,0,lblMainMsg},

	{C_Frame, frmLock0,0,"",NoList,CA_NoBorder,isSens,frmLock,0,0},
	{C_CheckBox, chk7_L0, 0," 7",NoList,CA_None,isSens,frmLock0,0,0},
	{C_CheckBox, chk6_L0, 0," 6",NoList,CA_None,isSens,frmLock0,chk7_L0,0},
	{C_CheckBox, chk5_L0, 0," 5",NoList,CA_None,isSens,frmLock0,chk6_L0,0},
	{C_CheckBox, chk4_L0, 0," 4",NoList,CA_None,isSens,frmLock0,chk5_L0,0},
	{C_CheckBox, chk3_L0, 0," 3",NoList,CA_None,isSens,frmLock0,chk4_L0,0},
	{C_CheckBox, chk2_L0, 0," 2",NoList,CA_None,isSens,frmLock0,chk3_L0,0},
	{C_CheckBox, chk1_L0, 0," 1",NoList,CA_None,isSens,frmLock0,chk2_L0,0},
	{C_CheckBox, chk0_L0, 0," 0",NoList,CA_None,isSens,frmLock0,chk1_L0,0},

	{C_Frame, frmLock1,0,"",NoList,CA_NoBorder,isSens,frmLock,0,frmLock0},
	{C_CheckBox, chk7_L1, 0," 7",NoList,CA_None,isSens,frmLock1,0,0},
	{C_CheckBox, chk6_L1, 0," 6",NoList,CA_None,isSens,frmLock1,chk7_L1,0},
	{C_CheckBox, chk5_L1, 0," 5",NoList,CA_None,isSens,frmLock1,chk6_L1,0},
	{C_CheckBox, chk4_L1, 0," 4",NoList,CA_None,isSens,frmLock1,chk5_L1,0},
	{C_CheckBox, chk3_L1, 0," 3",NoList,CA_None,isSens,frmLock1,chk4_L1,0},
	{C_CheckBox, chk2_L1, 0," 2",NoList,CA_None,isSens,frmLock1,chk3_L1,0},
	{C_CheckBox, chk1_L1, 0," 1",NoList,CA_None,isSens,frmLock1,chk2_L1,0},
	{C_CheckBox, chk0_L1, 0," 0",NoList,CA_None,isSens,frmLock1,chk1_L1,0},

	{C_Frame, frmLock2,0,"",NoList,CA_NoBorder,isSens,frmLock,0,frmLock1},
	{C_CheckBox, chk7_L2, 0," 7",NoList,CA_None,isSens,frmLock2,0,0},
	{C_CheckBox, chk6_L2, 0," 6",NoList,CA_None,isSens,frmLock2,chk7_L2,0},
	{C_CheckBox, chk5_L2, 0," 5",NoList,CA_None,isSens,frmLock2,chk6_L2,0},
	{C_CheckBox, chk4_L2, 0," 4",NoList,CA_None,isSens,frmLock2,chk5_L2,0},
	{C_CheckBox, chk3_L2, 0," 3",NoList,CA_None,isSens,frmLock2,chk4_L2,0},
	{C_CheckBox, chk2_L2, 0," 2",NoList,CA_None,isSens,frmLock2,chk3_L2,0},
	{C_CheckBox, chk1_L2, 0," 1",NoList,CA_None,isSens,frmLock2,chk2_L2,0},
	{C_CheckBox, chk0_L2, 0," 0",NoList,CA_None,isSens,frmLock2,chk1_L2,0},

	{C_Frame, frmLock3,0,"",NoList,CA_NoBorder,isSens,frmLock,0,frmLock2},
	{C_CheckBox, chk7_L3, 0," 7",NoList,CA_None,isSens,frmLock3,0,0},
	{C_CheckBox, chk6_L3, 0," 6",NoList,CA_None,isSens,frmLock3,chk7_L3,0},
	{C_CheckBox, chk5_L3, 0," 5",NoList,CA_None,isSens,frmLock3,chk6_L3,0},
	{C_CheckBox, chk4_L3, 0," 4",NoList,CA_None,isSens,frmLock3,chk5_L3,0},
	{C_CheckBox, chk3_L3, 0," 3",NoList,CA_None,isSens,frmLock3,chk4_L3,0},
	{C_CheckBox, chk2_L3, 0," 2",NoList,CA_None,isSens,frmLock3,chk3_L3,0},
	{C_CheckBox, chk1_L3, 0," 1",NoList,CA_None,isSens,frmLock3,chk2_L3,0},
	{C_CheckBox, chk0_L3, 0," 0",NoList,CA_None,isSens,frmLock3,chk1_L3,0},


	{C_Frame, frmFuses,0,"Fuses",NoList,CA_None,isSens,NoFrame,0,frmLock},

	{C_Frame, frmFuses0,0,"",NoList,CA_NoBorder,isSens,frmFuses,0,0},
	{C_CheckBox, chk7_F0, 0," 7",NoList,CA_None,isSens,frmFuses0,0,0},
	{C_CheckBox, chk6_F0, 0," 6",NoList,CA_None,isSens,frmFuses0,chk7_F0,0},
	{C_CheckBox, chk5_F0, 0," 5",NoList,CA_None,isSens,frmFuses0,chk6_F0,0},
	{C_CheckBox, chk4_F0, 0," 4",NoList,CA_None,isSens,frmFuses0,chk5_F0,0},
	{C_CheckBox, chk3_F0, 0," 3",NoList,CA_None,isSens,frmFuses0,chk4_F0,0},
	{C_CheckBox, chk2_F0, 0," 2",NoList,CA_None,isSens,frmFuses0,chk3_F0,0},
	{C_CheckBox, chk1_F0, 0," 1",NoList,CA_None,isSens,frmFuses0,chk2_F0,0},
	{C_CheckBox, chk0_F0, 0," 0",NoList,CA_None,isSens,frmFuses0,chk1_F0,0},

	{C_Frame, frmFuses1,0,"",NoList,CA_NoBorder,isSens,frmFuses,0,frmFuses0},
	{C_CheckBox, chk7_F1, 0," 7",NoList,CA_None,isSens,frmFuses1,0,0},
	{C_CheckBox, chk6_F1, 0," 6",NoList,CA_None,isSens,frmFuses1,chk7_F1,0},
	{C_CheckBox, chk5_F1, 0," 5",NoList,CA_None,isSens,frmFuses1,chk6_F1,0},
	{C_CheckBox, chk4_F1, 0," 4",NoList,CA_None,isSens,frmFuses1,chk5_F1,0},
	{C_CheckBox, chk3_F1, 0," 3",NoList,CA_None,isSens,frmFuses1,chk4_F1,0},
	{C_CheckBox, chk2_F1, 0," 2",NoList,CA_None,isSens,frmFuses1,chk3_F1,0},
	{C_CheckBox, chk1_F1, 0," 1",NoList,CA_None,isSens,frmFuses1,chk2_F1,0},
	{C_CheckBox, chk0_F1, 0," 0",NoList,CA_None,isSens,frmFuses1,chk1_F1,0},

	{C_Frame, frmFuses2,0,"",NoList,CA_NoBorder,isSens,frmFuses,0,frmFuses1},
	{C_CheckBox, chk7_F2, 0," 7",NoList,CA_None,isSens,frmFuses2,0,0},
	{C_CheckBox, chk6_F2, 0," 6",NoList,CA_None,isSens,frmFuses2,chk7_F2,0},
	{C_CheckBox, chk5_F2, 0," 5",NoList,CA_None,isSens,frmFuses2,chk6_F2,0},
	{C_CheckBox, chk4_F2, 0," 4",NoList,CA_None,isSens,frmFuses2,chk5_F2,0},
	{C_CheckBox, chk3_F2, 0," 3",NoList,CA_None,isSens,frmFuses2,chk4_F2,0},
	{C_CheckBox, chk2_F2, 0," 2",NoList,CA_None,isSens,frmFuses2,chk3_F2,0},
	{C_CheckBox, chk1_F2, 0," 1",NoList,CA_None,isSens,frmFuses2,chk2_F2,0},
	{C_CheckBox, chk0_F2, 0," 0",NoList,CA_None,isSens,frmFuses2,chk1_F2,0},

	{C_Frame, frmFuses3,0,"",NoList,CA_NoBorder,isSens,frmFuses,0,frmFuses2},
	{C_CheckBox, chk7_F3, 0," 7",NoList,CA_None,isSens,frmFuses3,0,0},
	{C_CheckBox, chk6_F3, 0," 6",NoList,CA_None,isSens,frmFuses3,chk7_F3,0},
	{C_CheckBox, chk5_F3, 0," 5",NoList,CA_None,isSens,frmFuses3,chk6_F3,0},
	{C_CheckBox, chk4_F3, 0," 4",NoList,CA_None,isSens,frmFuses3,chk5_F3,0},
	{C_CheckBox, chk3_F3, 0," 3",NoList,CA_None,isSens,frmFuses3,chk4_F3,0},
	{C_CheckBox, chk2_F3, 0," 2",NoList,CA_None,isSens,frmFuses3,chk3_F3,0},
	{C_CheckBox, chk1_F3, 0," 1",NoList,CA_None,isSens,frmFuses3,chk2_F3,0},
	{C_CheckBox, chk0_F3, 0," 0",NoList,CA_None,isSens,frmFuses3,chk1_F3,0},

	{C_Blank, blk0, 0, " ",NoList,CA_None,isSens,NoFrame,0,frmFuses},

	{C_Frame, frmHlp, 0,"",NoList,CA_NoBorder,isSens,NoFrame,0,blk0},
	{C_CheckBox, chkHlp1, 1,STR_FUSEDLGNOTESET " (bit = 0)",NoList,CA_None,notSens,frmHlp,0,0},
	{C_CheckBox, chkHlp0, 0,STR_FUSEDLGNOTECLR " (bit = 1)",NoList,CA_None,notSens,frmHlp,chkHlp1,0},

	{C_Label, blk1, 0,STR_LBLFUSEDLGHLP,NoList,CA_None,isSens,NoFrame,0,frmHlp},
//	{C_Blank, blk1, 0, " ",NoList,CA_None,isSens,NoFrame,0,frmHlp},

	{C_Button,M_Cancel,0, STR_BTNCANC,NoList,CA_None,isSens,NoFrame,0,blk1},
	{C_Button,M_OK,0,STR_BTNOK,NoList,CA_DefaultButton,isSens,NoFrame,M_Cancel,blk1},

	{C_Blank, blk2, 0, " ",NoList,CA_None,isSens,NoFrame,M_OK,blk1},

	{C_Button,btn0,0,STR_BTNCLRALL,	NoList,CA_None,isSens,NoFrame,blk2,blk1,	0, STR_TTCLRALL},
	{C_Button,btn1,0,STR_BTNSETALL,	NoList,CA_None,isSens,NoFrame,btn0,blk1,	0, STR_TTSETALL},
	{C_Button,btnProg,0,STR_BTNWRITE, NoList,CA_None,isSens,NoFrame,btn1,blk1,	0, STR_TTWRITE},
	{C_Button,btnRead,0,STR_BTNREAD, NoList,CA_None,isSens,NoFrame,btnProg,blk1,	0, STR_TTREAD},

	{C_EndOfList,0,0,0,0,CA_None,0,0,0}
};

static DialogCmd BlockDialogCmds[] =
{
	{C_Label, lblMainMsg, 0,"X",NoList,CA_MainMsg,isSens,NoFrame, 0, 0},

	{C_Frame, frmFuses,0,"Blocks",NoList,CA_None,isSens,NoFrame,0,lblMainMsg},

	{C_Frame, frmFill,0,"",NoList,CA_None,isSens,frmFuses,0,0},
	{C_Label, lblFrom,0, STR_MSGFIRSTBLK,NoList,CA_None,isSens,frmFill,0,0},
	{C_Label, lblTo,  0, STR_MSGNUMBLOCK,NoList,CA_None,isSens,frmFill,0,lblFrom},
	{C_Label, lblVal, 0, STR_MSGHIGHENDBLK,NoList,CA_None,isSens,frmFill,0,lblTo},

	{C_TextIn,txiFrom,0,"",NoList,CA_None,isSens,frmFuses,frmFill,0,8},
	{C_TextIn,txiTo,  0,"",NoList,CA_None,isSens,frmFuses,frmFill,txiFrom,8},
	{C_TextIn,txiVal, 0,"",NoList,CA_None,isSens,frmFuses,frmFill,txiTo,8},

	{C_Blank, blk1, 0, " ",NoList,CA_None,isSens,NoFrame,0,frmFuses},

	{C_Button,M_Cancel,0, STR_BTNCANC,	NoList,CA_None,isSens,NoFrame,0,blk1},
	{C_Button,M_OK,0, STR_BTNOK, NoList,CA_DefaultButton,isSens,NoFrame,M_Cancel,blk1},

	{C_EndOfList,0,0,0,0,CA_None,0,0,0}
};


//======================>>> fuseModalDialog::fuseModalDialog <<<==================
fuseModalDialog::fuseModalDialog(vBaseWindow* bw, char* title) :
				vModalDialog(bw, title)
{
	UserDebug(Constructor,"fuseModalDialog::fuseModalDialog()\n")

	cmdw = (e2CmdWindow *)bw;
	write = 0;
}

//===================>>> fuseModalDialog::~fuseModalDialog <<<====================
fuseModalDialog::~fuseModalDialog()
{
	UserDebug(Destructor,"fuseModalDialog::~fuseModalDialog() destructor\n")
}

//====================>>> fuseModalDialog::fuseAction <<<====================
int fuseModalDialog::fuseAction(char* msg, long type, DWORD &lock, DWORD &fuse, int readonly)
{
	char str1[10], str2[10], str3[10];

	int k;
	int j = FindLabels(type);
	if (j >= 0)
	{
		if ( labels[j].lockenable3 == 0 )
		{
			SetCommandHidden(frmLock0, true, FuseDialogCmds);
			SetCBelow(frmLock1, 0, FuseDialogCmds);
			SetCommandArrayHidden(chk7_L0, LOCKPACKSIZE, true, FuseDialogCmds);
		}
		else
		{
			SetCommandHidden(frmLock0, false, FuseDialogCmds);
			SetCBelow(frmLock1, frmLock0, FuseDialogCmds);
			SetCommandArrayHidden(chk7_L0, LOCKPACKSIZE, false, FuseDialogCmds);
		}

		if ( labels[j].lockenable2 == 0 )
		{
			SetCommandHidden(frmLock1, true, FuseDialogCmds);
			SetCBelow(frmLock2, 0, FuseDialogCmds);
			SetCommandArrayHidden(chk7_L1, LOCKPACKSIZE, true, FuseDialogCmds);
		}
		else
		{
			SetCommandHidden(frmLock1, false, FuseDialogCmds);
			SetCBelow(frmLock2, frmLock1, FuseDialogCmds);
			SetCommandArrayHidden(chk7_L1, LOCKPACKSIZE, false, FuseDialogCmds);
		}

		if ( labels[j].lockenable1 == 0 )
		{
			SetCommandHidden(frmLock2, true, FuseDialogCmds);
			SetCBelow(frmLock3, 0, FuseDialogCmds);
			SetCommandArrayHidden(chk7_L2, LOCKPACKSIZE, true, FuseDialogCmds);
		}
		else
		{
			SetCommandHidden(frmLock2, false, FuseDialogCmds);
			SetCBelow(frmLock3, frmLock2, FuseDialogCmds);
			SetCommandArrayHidden(chk7_L2, LOCKPACKSIZE, false, FuseDialogCmds);
		}

		if ( labels[j].lockenable0 == 0 )
		{
			SetCommandHidden(frmLock3, true, FuseDialogCmds);
			SetCommandArrayHidden(chk7_L3, LOCKPACKSIZE, true, FuseDialogCmds);
		}
		else
		{
			SetCommandHidden(frmLock1, false, FuseDialogCmds);
			SetCommandArrayHidden(chk7_L3, LOCKPACKSIZE, false, FuseDialogCmds);
		}


		if ( labels[j].fuseenable3 == 0 )
		{
			SetCommandHidden(frmFuses0, true, FuseDialogCmds);
			SetCBelow(frmFuses1, 0, FuseDialogCmds);
			SetCommandArrayHidden(chk7_F0, FUSEPACKSIZE, true, FuseDialogCmds);
		}
		else
		{
			SetCommandHidden(frmFuses0, false, FuseDialogCmds);
			SetCBelow(frmFuses1, frmFuses0, FuseDialogCmds);
			SetCommandArrayHidden(chk7_F0, FUSEPACKSIZE, false, FuseDialogCmds);
		}

		if ( labels[j].fuseenable2 == 0 )
		{
			SetCommandHidden(frmFuses1, true, FuseDialogCmds);
			SetCBelow(frmFuses2, 0, FuseDialogCmds);
			SetCommandArrayHidden(chk7_F1, FUSEPACKSIZE, true, FuseDialogCmds);
		}
		else
		{
			SetCommandHidden(frmFuses1, false, FuseDialogCmds);
			SetCBelow(frmFuses2, frmFuses1, FuseDialogCmds);
			SetCommandArrayHidden(chk7_F1, FUSEPACKSIZE, false, FuseDialogCmds);
		}

		if ( labels[j].fuseenable1 == 0 )
		{
			SetCommandHidden(frmFuses2, true, FuseDialogCmds);
			SetCBelow(frmFuses3, 0, FuseDialogCmds);
			SetCommandArrayHidden(chk7_F2, FUSEPACKSIZE, true, FuseDialogCmds);
		}
		else
		{
			SetCommandHidden(frmFuses2, false, FuseDialogCmds);
			SetCBelow(frmFuses3, frmFuses2, FuseDialogCmds);
			SetCommandArrayHidden(chk7_F2, FUSEPACKSIZE, false, FuseDialogCmds);
		}

		if ( labels[j].fuseenable0 == 0 )
		{
			SetCommandHidden(frmFuses3, true, FuseDialogCmds);
			SetCommandArrayHidden(chk7_F3, FUSEPACKSIZE, true, FuseDialogCmds);
		}
		else
		{
			SetCommandHidden(frmFuses3, false, FuseDialogCmds);
			SetCommandArrayHidden(chk7_F3, FUSEPACKSIZE, false, FuseDialogCmds);
		}


		if ( labels[j].lockenable3 == 0 && labels[j].lockenable2 == 0 &&
			 labels[j].lockenable1 == 0 && labels[j].lockenable0 == 0 )
			SetCommandHidden(frmLock, true, FuseDialogCmds);
		else
			SetCommandHidden(frmLock, false, FuseDialogCmds);

		if ( labels[j].fuseenable3 == 0 && labels[j].fuseenable2 == 0 &&
			 labels[j].fuseenable1 == 0 && labels[j].fuseenable0 == 0 )
			SetCommandHidden(frmFuses, true, FuseDialogCmds);
		else
			SetCommandHidden(frmFuses, false, FuseDialogCmds);


		//Label
		for (k = 0; k < LOCKPACKSIZE; k++)
		{
			char *sp;

			sp = labels[j].locklabel3[k];
			if (!sp)
				sp = deflbl[k];
			SetCommandLabel(chk7_L0+k, sp, FuseDialogCmds);

			sp = labels[j].locklabel2[k];
			if (!sp)
				sp = deflbl[k];
			SetCommandLabel(chk7_L1+k, sp, FuseDialogCmds);

			sp = labels[j].locklabel1[k];
			if (!sp)
				sp = deflbl[k];
			SetCommandLabel(chk7_L2+k, sp, FuseDialogCmds);

			sp = labels[j].locklabel0[k];
			if (!sp)
				sp = deflbl[k];
			SetCommandLabel(chk7_L3+k, sp, FuseDialogCmds);


			sp = labels[j].fuselabel3[k];
			if (!sp)
				sp = deflbl[k];
			SetCommandLabel(chk7_F0+k, sp, FuseDialogCmds);

			sp = labels[j].fuselabel2[k];
			if (!sp)
				sp = deflbl[k];
			SetCommandLabel(chk7_F1+k, sp, FuseDialogCmds);

			sp = labels[j].fuselabel1[k];
			if (!sp)
				sp = deflbl[k];
			SetCommandLabel(chk7_F2+k, sp, FuseDialogCmds);

			sp = labels[j].fuselabel0[k];
			if (!sp)
				sp = deflbl[k];
			SetCommandLabel(chk7_F3+k, sp, FuseDialogCmds);
		}

		//Sensitive
		for (k = 0; k < LOCKPACKSIZE; k++)
		{
			SetCommandSensitive(chk7_L0+k, (labels[j].lockenable3 & (0x80>>k)) ? 1 : 0, FuseDialogCmds);
			SetCommandSensitive(chk7_L1+k, (labels[j].lockenable2 & (0x80>>k)) ? 1 : 0, FuseDialogCmds);
			SetCommandSensitive(chk7_L2+k, (labels[j].lockenable1 & (0x80>>k)) ? 1 : 0, FuseDialogCmds);
			SetCommandSensitive(chk7_L3+k, (labels[j].lockenable0 & (0x80>>k)) ? 1 : 0, FuseDialogCmds);

			SetCommandSensitive(chk7_F0+k, (labels[j].fuseenable3 & (0x80>>k)) ? 1 : 0, FuseDialogCmds);
			SetCommandSensitive(chk7_F1+k, (labels[j].fuseenable2 & (0x80>>k)) ? 1 : 0, FuseDialogCmds);
			SetCommandSensitive(chk7_F2+k, (labels[j].fuseenable1 & (0x80>>k)) ? 1 : 0, FuseDialogCmds);
			SetCommandSensitive(chk7_F3+k, (labels[j].fuseenable0 & (0x80>>k)) ? 1 : 0, FuseDialogCmds);
		}
	}
	else
	{	//Default (disable all)
		for (k = 0; k < LOCKPACKSIZE; k++)
		{
			//Label
			SetCommandLabel(chk7_L0+k, deflbl[k], FuseDialogCmds);
			SetCommandLabel(chk7_L1+k, deflbl[k], FuseDialogCmds);
			SetCommandLabel(chk7_L2+k, deflbl[k], FuseDialogCmds);
			SetCommandLabel(chk7_L3+k, deflbl[k], FuseDialogCmds);

			SetCommandLabel(chk7_F0+k, deflbl[k], FuseDialogCmds);
			SetCommandLabel(chk7_F1+k, deflbl[k], FuseDialogCmds);
			SetCommandLabel(chk7_F2+k, deflbl[k], FuseDialogCmds);
			SetCommandLabel(chk7_F3+k, deflbl[k], FuseDialogCmds);


			//Sensitive
			SetCommandSensitive(chk7_L0+k, 0, FuseDialogCmds);
			SetCommandSensitive(chk7_L1+k, 0, FuseDialogCmds);
			SetCommandSensitive(chk7_L2+k, 0, FuseDialogCmds);
			SetCommandSensitive(chk7_L3+k, 0, FuseDialogCmds);

			SetCommandSensitive(chk7_F0+k, 0, FuseDialogCmds);
			SetCommandSensitive(chk7_F1+k, 0, FuseDialogCmds);
			SetCommandSensitive(chk7_F2+k, 0, FuseDialogCmds);
			SetCommandSensitive(chk7_F3+k, 0, FuseDialogCmds);
		}
	}

	//Checked
	for (k = 0; k < LOCKPACKSIZE; k++)
	{
		SetCommandObject(chk7_L0+k, ( (lock >> 24) & (0x80>>k)) ? 1 : 0, FuseDialogCmds);
		SetCommandObject(chk7_L1+k, ( (lock >> 16) & (0x80>>k)) ? 1 : 0, FuseDialogCmds);
		SetCommandObject(chk7_L2+k, ( (lock >>  8) & (0x80>>k)) ? 1 : 0, FuseDialogCmds);
		SetCommandObject(chk7_L3+k, ( lock & (0x80>>k)) ? 1 : 0, FuseDialogCmds);

		SetCommandObject(chk7_F0+k, ( (fuse >> 24) & (0x80>>k)) ? 1 : 0, FuseDialogCmds);
		SetCommandObject(chk7_F1+k, ( (fuse >> 16) & (0x80>>k)) ? 1 : 0, FuseDialogCmds);
		SetCommandObject(chk7_F2+k, ( (fuse >>  8) & (0x80>>k)) ? 1 : 0, FuseDialogCmds);
		SetCommandObject(chk7_F3+k, ( fuse & (0x80>>k)) ? 1 : 0, FuseDialogCmds);
	}

	sprintf(str1, "%d", (int)((lock >> 4) & 0x0F) );
	sprintf(str2, "%d", (int)(lock & 0x0F) );
	sprintf(str3, "%d", (int)(fuse & 0x0F) );
	SetCommandLabel(txiFrom, str1, BlockDialogCmds);
	SetCommandLabel(txiTo, str2, BlockDialogCmds);
	SetCommandLabel(txiVal, str3, BlockDialogCmds);

	if (readonly)
	{
		SetCommandSensitive(M_OK, 0, FuseDialogCmds);
		SetCommandSensitive(btnProg, 0, FuseDialogCmds);
		SetCommandSensitive(btn0, 0, FuseDialogCmds);
		SetCommandSensitive(btn1, 0, FuseDialogCmds);

		SetCommandSensitive(M_OK, 0, BlockDialogCmds);
	}
	else
	{
		SetCommandSensitive(M_OK, 1, FuseDialogCmds);
		SetCommandSensitive(btnProg, 1, FuseDialogCmds);
		SetCommandSensitive(btn0, 1, FuseDialogCmds);
		SetCommandSensitive(btn1, 1, FuseDialogCmds);

		SetCommandSensitive(M_OK, 1, BlockDialogCmds);
	}

	if (type == E2464)
		AddDialogCmds(BlockDialogCmds);		// add security block commands
	else
		AddDialogCmds(FuseDialogCmds);		// add fuses commands

	ItemVal ans,rval;

	read = write = 0;

	ans = ShowModalDialog(msg,rval);
	if (ans == M_Cancel)
		return 0;

	// *** Add code to process dialog values here
	lock = 0;
	fuse = 0;

	if (type == E2464)
	{
		GetTextIn(txiFrom, str1, 8);
		int From = strtol(str1,NULL,0);

		GetTextIn(txiTo, str2, 8);
		int To = strtol(str2,NULL,0);

		GetTextIn(txiVal, str3, 8);
		int Val = strtol(str3,NULL,0);

		lock = ((From << 4) & 0xF0) | (To & 0x0F);
		fuse = Val & 0x0F;
	}
	else
	{
		for (k = 0; k < LOCKPACKSIZE; k++)
		{
			lock |= GetValue(chk7_L0+k) ? (0x80000000>>k) : 0;
			lock |= GetValue(chk7_L1+k) ? (0x800000>>k) : 0;
			lock |= GetValue(chk7_L2+k) ? (0x8000>>k) : 0;
			lock |= GetValue(chk7_L3+k) ? (0x80>>k) : 0;

			fuse |= GetValue(chk7_F0+k) ? (0x80000000>>k) : 0;
			fuse |= GetValue(chk7_F1+k) ? (0x800000>>k) : 0;
			fuse |= GetValue(chk7_F2+k) ? (0x8000>>k) : 0;
			fuse |= GetValue(chk7_F3+k) ? (0x80>>k) : 0;
		}
	}

	if (ans == M_OK)
	{
		if (read)
			return 3;
		else
		if (write)
			return 2;
		else
			return 1;
	}
	else
		return 0;
}

//====================>>> fuseModalDialog::DialogCommand <<<====================
void fuseModalDialog::DialogCommand(ItemVal id, ItemVal retval, CmdType ctype)
{
	UserDebug2(CmdEvents,"fuseModalDialog::DialogCommand(id:%d, val:%d)\n",id, retval)

	switch (id)		// We will do some things depending on value
	{
	case btn0:
		{
			int k;
			for (k = 0; k < LOCKPACKSIZE; k++)
			{
				SetValue(chk7_L0+k, 0, Value);
				SetValue(chk7_L1+k, 0, Value);
				SetValue(chk7_L2+k, 0, Value);
				SetValue(chk7_L3+k, 0, Value);

				SetValue(chk7_F0+k, 0, Value);
				SetValue(chk7_F1+k, 0, Value);
				SetValue(chk7_F2+k, 0, Value);
				SetValue(chk7_F3+k, 0, Value);
			}
		}
		break;
	case btn1:
		{
			int k;
			for (k = 0; k < LOCKPACKSIZE; k++)
			{
				SetValue(chk7_L0+k, 1, Value);
				SetValue(chk7_L1+k, 1, Value);
				SetValue(chk7_L2+k, 1, Value);
				SetValue(chk7_L3+k, 1, Value);

				SetValue(chk7_F0+k, 1, Value);
				SetValue(chk7_F1+k, 1, Value);
				SetValue(chk7_F2+k, 1, Value);
				SetValue(chk7_F3+k, 1, Value);
			}
		}
		break;

	case btnRead:
		read = 1;

		vModalDialog::DialogCommand(id,retval,ctype);
		fuseModalDialog::DialogCommand(M_OK,1,ctype);
		break;

	case btnProg:
		//Execute the command
		write = 1;

		vModalDialog::DialogCommand(id,retval,ctype);
		fuseModalDialog::DialogCommand(M_OK,1,ctype);
		break;

	default:
		vModalDialog::DialogCommand(id,retval,ctype);
		break;
	}
}

//========================>>> SetCommandObject <<<==============================
int SetCommandObject(const int id, const int val, CommandObject* CmdList)
{
	for (CommandObject* cur = CmdList ; cur->cmdType != C_EndOfList ; ++cur)
	{
		if (cur->cmdId == id)
		{
			cur->retVal = val;
			return 1;
		}
	}

	SysDebug1(BadVals,"SetCommandObject(id:%d...) - No match in list\n",id)

	return 0;
}

//========================>>> SetCBellow <<<==============================
int SetCBelow(const int id, const ItemVal val, CommandObject* CmdList)
{
	int rval = 0;
#ifdef	_WINDOWS
	for (CommandObject* cur = CmdList ; cur->cmdType != C_EndOfList ; ++cur)
	{
		if (cur->cmdId == id)
		{
			cur->cBelow = val;

			rval = 1;
			break;
		}
	}

	if (rval == 0)
	{
		SysDebug1(BadVals,"ClearCBelow(id:%d...) - No match in list\n",id)
	}
#endif
	return rval;
}

//========================>>> SetCommandHidden <<<==============================
int SetCommandHidden(const int id, const bool val, CommandObject* CmdList)
{
	int rval = 0;

	for (CommandObject* cur = CmdList ; cur->cmdType != C_EndOfList ; ++cur)
	{
		if (cur->cmdId == id)
		{
			if (val)
				cur->attrs |= CA_Hidden;
			else
				cur->attrs &= ~CA_Hidden;


			rval = 1;
			break;
		}
	}

	if (rval == 0)
	{
		SysDebug1(BadVals,"SetCommandHidden(id:%d...) - No match in list\n",id)
	}

	return rval;
}

//========================>>> SetCommandArrayHidden <<<==============================
int SetCommandArrayHidden(const int id, const int n, const bool val, CommandObject* CmdList)
{
	int k;
	int rval = 0;

	for (k = 0; k < n; k++)
	{
		for (CommandObject* cur = CmdList ; cur->cmdType != C_EndOfList ; ++cur)
		{
			if (cur->cmdId == id+k)
			{
				if (val)
					cur->attrs |= CA_Hidden;
				else
					cur->attrs &= ~CA_Hidden;

				rval = 1;
				break;
			}
		}

		if (rval == 0)
		{
			SysDebug1(BadVals,"SetCommandArrayHidden(id:%d...) - No match in list\n",id+k)
		}
	}

	return rval;
}

//========================>>> SetCommandSensitive <<<==============================
int SetCommandSensitive(const int id, const int val, CommandObject* CmdList)
{
	for (CommandObject* cur = CmdList ; cur->cmdType != C_EndOfList ; ++cur)
	{
		if (cur->cmdId == id)
		{
			cur->Sensitive = val;
			return 1;
		}
	}

	SysDebug1(BadVals,"SetCommandObject(id:%d...) - No match in list\n",id)

	return 0;
}

//========================>>> SetCommandLabel <<<==============================
int SetCommandLabel(const int id, char *str, CommandObject* CmdList)
{
	for (CommandObject* cur = CmdList ; cur->cmdType != C_EndOfList ; ++cur)
	{
		if (cur->cmdId == id)
		{
			cur->title = str;
			return 1;
		}
	}

	SysDebug1(BadVals,"SetCommandObject(id:%d...) - No match in list\n",id)

	return 0;
}

//========================>>> GetCommandObject <<<==============================
int GetCommandObject(const int id, CommandObject* CmdList)
{
	for (CommandObject* cur = CmdList ; cur->cmdType != C_EndOfList ; ++cur)
	{
		if (cur->cmdId == id)
		{
			return cur->retVal;
		}
	}

	SysDebug1(BadVals,"GetCommandObject(id:%d...) - No match in list\n",id)

	return 0;
}
// ---------------------------------------------------------------------
