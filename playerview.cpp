//****************************************************************************
//
// playerview.cpp
//
//****************************************************************************
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


//******************************************************************************
// HEADERS
//******************************************************************************

// App headers.

#include "playerview.h"
#include "video.h"


//******************************************************************************
// PROCEDURE keyPressEvent
//******************************************************************************

void CLPlayerView::keyPressEvent( QKeyEvent *evKey )
{
	switch( evKey->key( ) )
	{
		case Key_Up:
			scrollBy(   0, -10 );
			break;

		case Key_Down:
			scrollBy(   0,  10 );
			break;

		case Key_Left:
			scrollBy( -10,   0 );
			break;

		case Key_Right:
			scrollBy(  10,   0 );
			break;

		case Key_PageUp:
			scrollBy(  0, -QMAX( 10, viewport( )->height( ) ) );
			break;

		case Key_PageDown:
			scrollBy(  0,  QMAX( 10, viewport( )->height( ) ) );
			break;

		case Key_Home:
			scrollBy( -QMAX( 10, viewport( )->width( ) ), 0 );
			break;

		case Key_End:
			scrollBy(  QMAX( 10, viewport( )->width( ) ), 0 );
			break;

		default:
			evKey->ignore( );
			break;
	}
} // End of keyPressEvent.


//******************************************************************************
// PROCEDURE centerVideo
//******************************************************************************

void CLPlayerView::centerVideo( void )
{
	center( video( )->width( )/2, video( )->height( )/2 );
} // End of centerVideo.


//******************************************************************************
// PROCEDURE CLPlayerView (Constructor)
//******************************************************************************

CLPlayerView::CLPlayerView( QWidget *wgParent, const char *szName, WFlags wf )
             :QScrollView( wgParent, szName, wf )
{
	vidPriv = new CLVideo( viewport( ), "VID Widget", WNoAutoErase );
	connect( vidPriv, SIGNAL( message( const QString & ) ),
			this   , SIGNAL( message( const QString & ) ) );

	addChild( vidPriv );
} // End of CLPlayerView (Constructor).


//******************************************************************************
// PROCEDURE ~CLPlayerView (Destructor)
//******************************************************************************

CLPlayerView::~CLPlayerView( void )
{
	; // No action.
} // End of ~CLPlayerView (Destructor).

