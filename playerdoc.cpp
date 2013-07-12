//******************************************************************************
//
// playerdoc.cpp
//
//******************************************************************************
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


//******************************************************************************
// HEADERS
//******************************************************************************

// Qt headers.

#include <qfileinfo.h>

// App headers.

#include "playerdoc.h"
#include "playerview.h"

#include "video.h"


//******************************************************************************
// PROCEDURE closeEvent
//******************************************************************************

void CLPlayerDoc::closeEvent( QCloseEvent *evClose )
{
  evClose->accept( );
  return;
} // End of closeEvent.


//******************************************************************************
// PROCEDURE load
//******************************************************************************

bool CLPlayerDoc::load( const QString &strName,
                        int iVideoSizeX, int iVideoSizeY, int iColorSpace,
                        bool bAllFramesInMem )
{
  CLVideo *vid = view( )->video( );


  if ( false == vid->load( strName, iVideoSizeX, iVideoSizeY,
                           iColorSpace, bAllFramesInMem ) )
    return false;

  setCaption( tr(
    "Video %1: %2 x %3, %4 frames"
  ).arg( QFileInfo( strName ).fileName( ) )
   .arg( iVideoSizeX )
   .arg( iVideoSizeY )
   .arg( vid->numberOfFrames( ) ) );

  resize( vid->width( ) + 4, vid->height( ) + 6 );

  return true;
} // End of load.


//******************************************************************************
// PROCEDURE save
//******************************************************************************

bool CLPlayerDoc::save( const QString &strName,
                        bool bAddHeader, bool bSelFrames,
                        int iFrameFrom, int iFrameTo, int iFrameStep )
{
  CLVideo *vid = view( )->video( );


  return vid->save( strName, bAddHeader, bSelFrames,
                    iFrameFrom, iFrameTo, iFrameStep );
} // End of save.


//******************************************************************************
// PROCEDURE CLPlayerDoc (Constructor)
//******************************************************************************

CLPlayerDoc::CLPlayerDoc( QWidget *wgtParent, const char *szName, WFlags wf )
            :QMainWindow( wgtParent, szName, wf )
{
  plvPriv = new CLPlayerView( this, "PLV View" );

  connect( plvPriv, SIGNAL( message( const QString & ) ),
           this   , SIGNAL( message( const QString & ) ) );

  setFocusProxy( plvPriv );
  setCentralWidget( plvPriv );

  resize( plvPriv->video( )->width( ) + 4, plvPriv->video( )->height( ) + 4 );
} // End of CLPlayerDoc (Constructor).


//******************************************************************************
// PROCEDURE ~CLPlayerDoc (Destructor)
//******************************************************************************

CLPlayerDoc::~CLPlayerDoc( void )
{
  ; // No action.
} // End of ~CLPlayerDoc (Destructor).

