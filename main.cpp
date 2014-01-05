//******************************************************************************
//
// main.cpp
//
//******************************************************************************
//
// Author..: José Fernando Leite de Oliveira
//
// Begin...: Wed May 04 2005
// Modified: Tue May 31 2005
//
// Email...: jleite@lps.ufrj.br
//
//******************************************************************************
//
// Copyright (C) 2005 by José Fernando Leite de Oliveira
//
// This program is free software; you can redistribute it  and/or  modify  it
// under the terms of the GNU General Public License as published by the Free
// Software Foundation; either version 2 of the License, or  (at your option)
// any later version.
//
// This program is distributed in  the  hope  that  it  will  be  useful, but
// WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY
// or FITNESS FOR A PARTICULAR PURPOSE. See the GNU  General  Public  License
// for more details.
//
// You should have received a copy of the GNU General  Public  License  along
// with this program; if not, write to the  Free  Software  Foundation, Inc.,
// 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
//
//******************************************************************************


//******************************************************************************
// HEADERS
//******************************************************************************

// Qt headers.
#include <qapplication.h>
// App headers.
#include "playerwin.h"

int main(int iArgC, char *a_szArgV[])
{
	const char *szName = "ZPlayer Main Widget";

	int iRet;

	QApplication *appPlayer;
	CLPlayerWin  *winPlayer; // ZPlayer window.

	appPlayer = new QApplication( iArgC, a_szArgV );

	// Create main widget.
	winPlayer = new CLPlayerWin( NULL, szName );

	// Show window.
	appPlayer->setMainWidget( winPlayer );

	winPlayer->parseCmdLine( iArgC, a_szArgV );
	winPlayer->show( );

	// Process events.
	iRet = appPlayer->exec( );

	// Delete application and exit.
	delete appPlayer;

	return iRet;
}

