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

#include "types.h"
#include "at93cxx8.h"		// Header file
#include "errcode.h"
#include "eeptypes.h"

#define	BANK_SIZE	1

//=====>>> Costruttore <<<======
At93cxx8::At93cxx8(e2AppWinInfo *wininfo, BusIO *busp)
	:	Device(wininfo, busp, BANK_SIZE)
{
	UserDebug(Constructor, "At93cxx8::At93cxx8()\n");
}

//--- Distruttore
At93cxx8::~At93cxx8()
{
	UserDebug(Destructor, "At93cxx8::~At93cxx8()\n");
}

// determina il numero di banchi (dimensione) dell'eeprom
//---
int At93cxx8::Probe(int probe_size)
{
	UserDebug(UserApp1, "At93cxx8::Probe()\n");

	return OK;
}


int At93cxx8::Read(int probe, int type)
{
	UserDebug1(UserApp1, "At93cxx8::Read(%d)\n", probe);

	GetBus()->SetOrganization(ORG8);

	if (probe || GetNoOfBank() == 0)
		Probe();

	int size = GetNoOfBank() * GetBankSize();
	int asize = GetBus()->CalcAddressSize(GetAddrSize());

	int rv = size;
	if (type & PROG_TYPE)
	{
		rv = GetBus()->Read(asize, GetBufPtr(), size);
		if (rv != size)
		{
			if (rv > 0)
				rv = OP_ABORTED;
		}
	}
	UserDebug1(UserApp1, "At93cxx8::Read() = %d\n", rv);

	return rv;
}

int At93cxx8::Write(int probe, int type)
{
	GetBus()->SetOrganization(ORG8);

	if (probe || GetNoOfBank() == 0)
		Probe();

	int size = GetNoOfBank() * GetBankSize();
	int asize = GetBus()->CalcAddressSize(GetAddrSize());

	int rv = size;
	if (type & PROG_TYPE)
	{
		rv = GetBus()->Write(asize, GetBufPtr(), size);
		if (rv != size)
		{
			if (rv > 0)
				rv = OP_ABORTED;
		}
	}
	return rv;
}

int At93cxx8::Verify(int type)
{
	GetBus()->SetOrganization(ORG8);

	if (GetNoOfBank() == 0)
		return BADPARAM;

	int size = GetNoOfBank() * GetBankSize();
	int asize = GetBus()->CalcAddressSize(GetAddrSize());
	unsigned char *localbuf;
	localbuf = new unsigned char[size];
	if (localbuf == 0)
		return OUTOFMEMORY;

	int rval = 1;
	if (type & PROG_TYPE)
	{
		rval = GetBus()->Read(asize, localbuf, size);
		if (rval != size)
		{
			if (rval > 0)
				rval = OP_ABORTED;
		}
		else
		{
			rval = ( memcmp(GetBufPtr(), localbuf, size) != 0 ) ? 0 : 1;
		}
	}
	delete localbuf;

	return rval;
}
