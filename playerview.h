//******************************************************************************
//
// playerview.h
//
//******************************************************************************
//
// Author..: José Fernando Leite de Oliveira
//
// Begin...: Wed May 04 2005
// Modified: Sun May 15 2005
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

#ifndef PLAYERVIEW_H
#define PLAYERVIEW_H

//******************************************************************************
// HEADERS
//******************************************************************************

// Qt headers.

#include <qscrollview.h>


//******************************************************************************
// FORWARD DECLARATIONS
//******************************************************************************

// App classes.

class CLVideo;


//******************************************************************************
// CLASS CLPlayerView
//******************************************************************************

class CLPlayerView: public QScrollView  // cl_plv
{
	Q_OBJECT

	private:

		CLVideo *vidPriv;


	protected:

		void keyPressEvent( QKeyEvent *evKey );


	public:

		CLVideo * video( void ) const { return vidPriv; };

		void centerVideo( void );

		// Constructor(s) and destructor.

		CLPlayerView( QWidget *wgParent = NULL,
				const char *szName = NULL, WFlags wf = 0 );

		virtual ~CLPlayerView( void );


	signals:

		void message( const QString &strText );
}; // End of class CLPlayerView.

#endif // PLAYERVIEW_H

