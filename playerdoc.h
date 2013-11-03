//****************************************************************************
//
// playerdoc.h
//
//****************************************************************************
//
// Author..: José Fernando Leite de Oliveira
//
// Begin...: Wed May 04 2005
// Modified: Fri May 20 2005
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

#ifndef PLAYERDOC_H
#define PLAYERDOC_H

//******************************************************************************
// HEADERS
//******************************************************************************

#include <qmainwindow.h>


//******************************************************************************
// FORWARD DECLARATIONS
//******************************************************************************

// App classes.

class CLPlayerView;


//******************************************************************************
// CLASS CLPlayerDoc
//******************************************************************************

class CLPlayerDoc: public QMainWindow // cl_pld
{
	Q_OBJECT

	private:

		CLPlayerView *plvPriv;


	protected:

		void closeEvent( QCloseEvent *evClose );


	public:

		CLPlayerView * view( void ) const { return plvPriv; };

		bool load( const QString &strName,
				int iVideoSizeX, int iVideoSizeY, int iColorSpace,
				bool bAllFramesInMem = false );

		bool save( const QString &strName,
				bool bAddHeader, bool bSelFrames,
				int iFrameFrom, int iFrameTo, int iFrameStep );

		// Constructor(s) and destructor.

		CLPlayerDoc( QWidget *wgParent, const char *szName = NULL, WFlags wf = 0 );

		virtual ~CLPlayerDoc( void );


	signals:

		void message( const QString &strText );
}; // End of class CLPlayerDoc.

#endif // PLAYERDOC_H

