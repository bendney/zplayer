//******************************************************************************
//
// playerwin.cpp
//
//******************************************************************************
//
// Author..: José Fernando Leite de Oliveira
//
// Begin...: Wed May 04 2005
// Modified: Mon May 30 2005
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

// Qt headers.

#include <qaction.h>
#include <qapplication.h>

#include <qdatetime.h>

#include <qlabel.h>
#include <qlayout.h>

#include <qmenubar.h>
#include <qmessagebox.h>

#include <qpixmap.h>
#include <qpopupmenu.h>

#include <qslider.h>
#include <qspinbox.h>
#include <qstatusbar.h>

#include <qtimer.h>
#include <qtoolbar.h>
#include <qtoolbutton.h>
#include <qtooltip.h>

#include <qvariant.h>
#include <qvbox.h>

#include <qwhatsthis.h>
#include <qworkspace.h>

// App headers.

#include "icons.h"

#include "fileopendlg.h"
#include "filesavedlg.h"

#include "playerdoc.h"
#include "playerview.h"
#include "playerwin.h"

#include "video.h"


//******************************************************************************
// STATIC FUNCTIONS (PRIVATE)
//******************************************************************************

static void enable( QAction *ac )
{
  if ( ac->isEnabled( ) )
    return;

  ac->setEnabled( true );
}


static void disable( QAction *ac )
{
  if ( !ac->isEnabled( ) )
    return;

  ac->setEnabled( false );
}


static void enable( QWidget *wgt )
{
  if ( wgt->isEnabled( ) )
    return;

  wgt->setEnabled( true );
}


static void disable( QWidget *wgt )
{
  if ( !wgt->isEnabled( ) )
    return;

  wgt->setEnabled( false );
}


//******************************************************************************
// PROCEDURE languageChange
//******************************************************************************
//
// Sets the strings of the subwidgets using the current language.
//
//******************************************************************************

void CLPlayerWin::languageChange( void )
{
  setCaption( tr( "ZPlayer" ) );

  acFileNew->setText( tr( "New" ) );
  acFileNew->setMenuText( tr( "&New..." ) );
  acFileNew->setToolTip( tr( "New view" ) );
  acFileNew->setStatusTip( tr( "Creates a new empty player view." ) );
  acFileNew->setAccel( tr( "Ctrl+N" ) );

  acFileOpen->setText( tr( "Open" ) );
  acFileOpen->setMenuText( tr( "&Open..." ) );
  acFileOpen->setToolTip( tr( "Open file" ) );
  acFileOpen->setStatusTip( tr( "Open sequence file." ) );
  acFileOpen->setAccel( tr( "Ctrl+O" ) );

  acFileSave->setText( tr( "Save" ) );
  acFileSave->setMenuText( tr( "&Save" ) );
  acFileSave->setToolTip( tr( "Save file" ) );
  acFileSave->setStatusTip( tr( "Save sequence file." ) );
  acFileSave->setAccel( tr( "Ctrl+S" ) );

  acFileSaveAs->setText( tr( "Save As" ) );
  acFileSaveAs->setMenuText( tr( "Save &As..." ) );
  acFileSaveAs->setStatusTip( tr( "Save sequence file." ) );
  acFileSaveAs->setAccel( QString::null );

  acFileClose->setText( tr( "Close" ) );
  acFileClose->setMenuText( tr( "&Close" ) );
  acFileClose->setToolTip( tr( "Close window" ) );
  acFileClose->setStatusTip( tr( "Close active window." ) );
  acFileClose->setAccel( tr( "Ctrl+W" ) );

  acFileExit->setText( tr( "Exit" ) );
  acFileExit->setMenuText( tr( "E&xit" ) );
  acFileExit->setToolTip( tr( "Exit program" ) );
  acFileExit->setStatusTip( tr( "Exit program." ) );
  acFileExit->setAccel( tr( "Ctrl+Q" ) );

  acVideoPlay->setText( tr( "Play" ) );
  acVideoPlay->setMenuText( tr( "&Play" ) );
  acVideoPlay->setToolTip( tr( "Play/Pause" ) );
  acVideoPlay->setStatusTip( tr( "Play/Pause sequence." ) );
  acVideoPlay->setAccel( tr( "P" ) );

  acVideoStop->setText( tr( "Stop" ) );
  acVideoStop->setMenuText( tr( "&Stop" ) );
  acVideoStop->setToolTip( tr( "Stop" ) );
  acVideoStop->setStatusTip( tr( "Stop playing sequence." ) );
  acVideoStop->setAccel( tr( "S" ) );

  acVideoBackward->setText( tr( "Backward" ) );
  acVideoBackward->setMenuText( tr( "&Backward" ) );
  acVideoBackward->setToolTip( tr( "Backward" ) );
  acVideoBackward->setStatusTip( tr( "Step backward." ) );
  acVideoBackward->setAccel( tr( "B" ) );

  acVideoForward->setText( tr( "Forward" ) );
  acVideoForward->setMenuText( tr( "&Forward" ) );
  acVideoForward->setToolTip( tr( "Forward" ) );
  acVideoForward->setStatusTip( tr( "Step forward." ) );
  acVideoForward->setAccel( tr( "F" ) );

  acVideoLoop->setText( tr( "Loop" ) );
  acVideoLoop->setMenuText( tr( "&Loop" ) );
  acVideoLoop->setToolTip( tr( "Loop" ) );
  acVideoLoop->setStatusTip( tr( "Set loop mode." ) );
  acVideoLoop->setAccel( tr( "L" ) );

  acVideoLock->setText( tr( "Lock" ) );
  acVideoLock->setMenuText( tr( "Loc&k" ) );
  acVideoLock->setToolTip( tr( "Set lock mode" ) );
  acVideoLock->setStatusTip( tr( "Lock video actions." ) );
  acVideoLock->setAccel( tr( "K" ) );

  acVideoCenter->setText( tr( "Center" ) );
  acVideoCenter->setMenuText( tr( "&Center" ) );
  acVideoCenter->setToolTip( tr( "Center Video" ) );
  acVideoCenter->setStatusTip( tr( "Center video frames on view." ) );
  acVideoCenter->setAccel( tr( "C" ) );

  acViewMenuBar->setText( tr( "Menu Bar" ) );
  acViewMenuBar->setMenuText( tr( "&Menu Bar" ) );
  acViewMenuBar->setStatusTip( tr( "Show/hide menu bar." ) );
  acViewMenuBar->setAccel( tr( "Ctrl+M" ) );

  acViewTBarFile->setText( tr( "Toolbar File" ) );
  acViewTBarFile->setMenuText( tr( "Toolbar &File" ) );
  acViewTBarFile->setStatusTip( tr( "Show/hide toolbar file." ) );
  acViewTBarFile->setAccel( tr( "Ctrl+F" ) );

  acViewTBarVideo->setText( tr( "Toolbar Video" ) );
  acViewTBarVideo->setMenuText( tr( "Toolbar Vid&eo" ) );
  acViewTBarVideo->setStatusTip( tr( "Show/hide toolbar video." ) );
  acViewTBarVideo->setAccel( tr( "Ctrl+E" ) );

  acViewStatusBar->setText( tr( "Status Bar" ) );
  acViewStatusBar->setMenuText( tr( "Stat&us Bar" ) );
  acViewStatusBar->setStatusTip( tr( "Show/hide status bar." ) );
  acViewStatusBar->setAccel( tr( "Ctrl+U" ) );

  acViewFullScreen->setText( tr( "Full Screen" ) );
  acViewFullScreen->setMenuText( tr( "Full Sc&reen" ) );
  acViewFullScreen->setStatusTip( tr( "Alternate between full screen and "
                                      "normal view." ) );
  acViewFullScreen->setAccel( tr( "Ctrl+R" ) );

  acWindCascade->setText( tr( "Cascade" ) );
  acWindCascade->setMenuText( tr( "&Cascade" ) );
  acWindCascade->setStatusTip( tr( "Cascade windows." ) );
  acWindCascade->setAccel( tr( "F5" ) );

  acWindTileVer->setText( tr( "Vertical Tile" ) );
  acWindTileVer->setMenuText( tr( "&Vertical Tile" ) );
  acWindTileVer->setStatusTip( tr( "Tile windows vertically." ) );
  acWindTileVer->setAccel( tr( "F6" ) );

  acWindTileHor->setText( tr( "Horizontal Tile" ) );
  acWindTileHor->setMenuText( tr( "&Horizontal Tile" ) );
  acWindTileHor->setStatusTip( tr( "Tile windows horizontally." ) );
  acWindTileHor->setAccel( tr( "F7" ) );

  acHelpContents->setText( tr( "Contents" ) );
  acHelpContents->setMenuText( tr( "&Contents..." ) );
  acHelpContents->setStatusTip( tr( "Contents." ) );
  acHelpContents->setAccel( tr( "F1" ) );

  acHelpAboutApp->setText( tr( "&About ZPlayer..." ) );
  acHelpAboutApp->setMenuText( tr( "&About ZPlayer..." ) );
  acHelpAboutApp->setToolTip( tr( "About ZPlayer" ) );
  acHelpAboutApp->setStatusTip( tr( "About this player." ) );
  acHelpAboutApp->setAccel( QString::null );

  acHelpAboutQt->setText( tr( "About" ) );
  acHelpAboutQt->setMenuText( tr( "About &Qt..." ) );
  acHelpAboutQt->setAccel( QString::null );

  acHelpWhatsThis->setText( tr( "What's &This" ) );
  acHelpWhatsThis->setMenuText( tr( "What's &This" ) );
  acHelpWhatsThis->setToolTip( tr( "What's This" ) );
  acHelpWhatsThis->setStatusTip( tr( "Enter what's this mode." ) );
  acHelpWhatsThis->setAccel( tr( "Shift+F1" ) );

  mbrMain->findItem( 3 )->setText( tr( "&File" ) );
  mbrMain->findItem( 4 )->setText( tr( "Vid&eo" ) );
  mbrMain->findItem( 5 )->setText( tr( "&View" ) );
  mbrMain->findItem( 6 )->setText( tr( "&Window" ) );
  mbrMain->findItem( 8 )->setText( tr( "&Help" ) );

  tbrFile ->setLabel( tr( "Toolbar File" ) );
  tbrVideo->setLabel( tr( "Toolbar Video" ) );
} // End of languageChange.


//******************************************************************************
// PROCEDURE closeEvent
//******************************************************************************

void CLPlayerWin::closeEvent( QCloseEvent *evClose )
{
  int i;

  int iNumWin;

  QWidgetList wglWindow = workspace( )->windowList( );

  QWidget *wgtWindow;


  iNumWin = int( wglWindow.count( ) );

  for ( i = 0; i < iNumWin; ++i )
  {
    wgtWindow = wglWindow.at( i );

    if ( false == wgtWindow->close( ) )
    {
      evClose->ignore( );
      return;
    }
  }

  QMainWindow::closeEvent( evClose );
} // End of closeEvent.


//******************************************************************************
// PROCEDURE computeFrameRate
//******************************************************************************

void CLPlayerWin::computeFrameRate( int iNumFrames, int iMillisecs )
{
  if ( 0 == iMillisecs )
    return;

  statusBar( )->message( tr(
    "Total Time: %1 Effective Frame Rate: %2 Hz"
  ).arg( QTime( ).addMSecs( iMillisecs ).toString( tr( "hh:mm:ss.zzz" ) ) )
   .arg( 1000.0*iNumFrames/iMillisecs, 0, 'f', 3 ) );
} // End of computeFrameRate.


//******************************************************************************
// PROCEDURE windowActivated
//******************************************************************************

void CLPlayerWin::windowActivated( QWidget *wgtWindow )
{
  if ( NULL == wgtWindow )
  {
    if ( bIsPlaying )
      videoStop( );

    sldFrame->setMaxValue( 1 );

    disable( acFileSave );
    disable( acFileSaveAs );
    disable( acFileClose );

    disable( acVideoPlay );
    disable( acVideoStop );
    disable( acVideoBackward );
    disable( acVideoForward );

    disable( sldFrame );
    disable( lblFrame );
    disable( sbxFRate );

    statusBar( )->clear( );

    return;
  }

  CLVideo *vid = ( ( CLPlayerDoc * )wgtWindow )->view( )->video( );

  int iNumFrames = vid->numberOfFrames( );


  if ( iNumFrames > 1 )
  {
    int iCurrFrame = vid->currentFrame( );


    if ( iNumFrames < sldFrame->maxValue( ) )
    {
      sldFrame->setValue( iCurrFrame );
      sldFrame->setMaxValue( iNumFrames );
    }
    else if ( iNumFrames > sldFrame->maxValue( ) )
    {
      sldFrame->setMaxValue( iNumFrames );
      sldFrame->setValue( iCurrFrame );
    }
    else
      sldFrame->setValue( iCurrFrame );

    enable( acFileSave );
    enable( acFileSaveAs );

    enable( acVideoPlay );
    enable( acVideoStop );
    enable( acVideoBackward );
    enable( acVideoForward );

    enable( sldFrame );
    enable( lblFrame );
    enable( sbxFRate );

    return;
  }
  else
    sldFrame->setMaxValue( 1 );

  disable( acFileSave );
  disable( acFileSaveAs );

  disable( acVideoPlay );
  disable( acVideoStop );
  disable( acVideoBackward );
  disable( acVideoForward );

  disable( sldFrame );
  disable( lblFrame );
  disable( sbxFRate );
} // End of windowActivated.


//******************************************************************************
// PROCEDURE newDoc
//******************************************************************************

CLPlayerDoc * CLPlayerWin::newDoc( void )
{
  QWidgetList wglWindow = workspace( )->windowList( );

  CLPlayerDoc *pldWindow;


  if ( bIsPlaying )
    videoStop( );

  pldWindow = new CLPlayerDoc( workspace( ), NULL, WDestructiveClose );
  pldWindow->setCaption( tr(
    "Video %1"
  ).arg( wglWindow.count( ) + 1 ) );
  pldWindow->setIcon( pxmApp16x16 );

  connect( pldWindow, SIGNAL( message( const QString & ) ),
           statusBar( ), SLOT( message( const QString & ) ) );

  if ( 0 == wglWindow.count( ) )
    enable( acFileClose );

  pldWindow->show( );

  return pldWindow;
} // End of newDoc.


//******************************************************************************
// PROCEDURE fileNew
//******************************************************************************

void CLPlayerWin::fileNew( void )
{
  ( void )newDoc( );
} // End of fileNew.


//******************************************************************************
// PROCEDURE fileOpen
//******************************************************************************

void CLPlayerWin::fileOpen( void )
{
  QFileInfo fliOpen( strOpenFile );

  CLFileOpenDlg fldOpen( this, "FLD Open", true );


  fldOpen.setIcon( pxmFileOpen );
  fldOpen.setCaption( tr( "ZPlayer - Open File" ) );

  fldOpen.addFilter( tr( "RGB Files (*.rgb *.RGB)" ) );
  fldOpen.addFilter( tr( "YUV Files (*.y *.Y *.yuv *.YUV)" ) );

  fldOpen.setMode    ( QFileDialog::ExistingFile );
  fldOpen.setViewMode( QFileDialog::List );

  fldOpen.setDir( dirOpen );
  fldOpen.setSelection( fliOpen.fileName( ) );

  if ( fldOpen.exec( ) != QFileDialog::Accepted )
    return;

  strOpenFile = fldOpen.selectedFile( );

  dirOpen = QFileInfo( strOpenFile ).dirPath( );

  if ( false == strOpenFile.isEmpty( ) )
  {
    bool bOk;

    CLPlayerDoc *pldWindow;


    statusBar( )->message( tr( "Loading file '%1'..." ).arg( strOpenFile ) );
    qApp->processEvents( );

    pldWindow = ( CLPlayerDoc * )workspace( )->activeWindow( );

    if ( NULL == pldWindow )
      pldWindow = newDoc( );

    bOk = pldWindow->load( strOpenFile,
      fldOpen.videoSizeX( ), fldOpen.videoSizeY( ),
      fldOpen.colorSpace( ), fldOpen.allFramesInMemory( )
    );

    if ( true == bOk )
    {
      sldFrame->setMaxValue( pldWindow->view( )->video( )->numberOfFrames( ) );

      bNoName = false;
      strSaveFile = strOpenFile;

      enable( acFileSave );
      enable( acFileSaveAs );
      enable( acFileClose );

      enable( acVideoPlay );
      enable( acVideoStop );
      enable( acVideoBackward );
      enable( acVideoForward );

      enable( sldFrame );
      enable( lblFrame );
      enable( sbxFRate );

      statusBar( )->message( tr( "Ready." ) );
    }
    else
    {
      statusBar( )->message( tr(
        "Cannot load data from file '%1'."
      ).arg( strOpenFile ), 3000 );
    }
  }
} // End of fileOpen.


//******************************************************************************
// PROCEDURE fileSave
//******************************************************************************

void CLPlayerWin::fileSave( void )
{
  fileSaveAs( );
} // End of fileSave.


//******************************************************************************
// PROCEDURE fileSaveAs
//******************************************************************************

void CLPlayerWin::fileSaveAs( void )
{
  QFileInfo fliSave( strSaveFile );

  CLFileSaveDlg fldSave( this, "FLD Save", true );


  fldSave.setIcon( pxmFileSave );
  fldSave.setCaption( tr( "ZPlayer - Save File As" ) );

  fldSave.addFilter( tr( "RGB Files (*.rgb *.RGB)" ) );
  fldSave.addFilter( tr( "YUV Files (*.y *.Y *.yuv *.YUV)" ) );

  fldSave.setMode    ( QFileDialog::AnyFile );
  fldSave.setViewMode( QFileDialog::List );

  fldSave.setDir( dirSave );
  fldSave.setSelection( fliSave.fileName( ) );

  if ( fldSave.exec( ) != QFileDialog::Accepted )
    return;

  strSaveFile = fldSave.selectedFile( );

  dirSave = QFileInfo( strSaveFile ).dirPath( );

  if ( strSaveFile == strOpenFile )
  {
    int iResult;

    iResult = QMessageBox::warning( this, tr( "ZPlayer - Save Warning" ), tr(
      "File: %1"
      "\n"
      "\nIt is not possible to overwrite the open file."
      "\nSelect another file name, please."
    ).arg( strSaveFile ), tr( "&Ok" ), QString::null, QString::null, 0, 0 );

    return;
  }

  if ( true == QFile::exists( strSaveFile  ) && true == bCheckExistingFile )
  {
    int iResult;

    iResult = QMessageBox::warning( this, tr( "ZPlayer - Save Warning" ), tr(
      "File: %1"
      "\n"
      "\nThis file already exists."
      "\nWould you like to overwrite it?"
    ).arg( strSaveFile ),
    tr( "&Yes" ), tr( "&No" ), tr( "&Warning Off" ), 1, 1 );

    if ( 1 == iResult )
      return;

    if ( 2 == iResult )
      bCheckExistingFile = false;
  }

  if ( false == strSaveFile.isEmpty( ) )
  {
    bool bOk;

    CLPlayerDoc *pldWindow;


    statusBar( )->message( tr( "Saving file as '%1'..." ).arg( strSaveFile ) );
    qApp->processEvents( );


    pldWindow = ( CLPlayerDoc * )workspace( )->activeWindow( );

    bOk = pldWindow->save( strSaveFile,
      fldSave.addHeader( ), fldSave.selectedFrames( ),
      fldSave.frameFrom( ), fldSave.frameTo( ), fldSave.frameStep( )
    );

    if ( true == bOk )
    {
      bNoName = false;

      statusBar( )->message( tr( "Ready." ) );
    }
    else
    {
      statusBar( )->message( tr(
        "Cannot save data to file '%1'."
      ).arg( strSaveFile ), 3000 );
    }
  }
} // End of fileSaveAs.


//******************************************************************************
// PROCEDURE fileClose
//******************************************************************************

void CLPlayerWin::fileClose( void )
{
  CLPlayerDoc *pldWindow = ( CLPlayerDoc * )workspace( )->activeWindow( );


  if ( NULL != pldWindow )
  {
    if ( 1 == workspace( )->windowList( ).count( ) )
    {
      if ( bIsPlaying )
        videoStop( );

      disable( acFileSave );
      disable( acFileSaveAs );
      disable( acFileClose );

      disable( acVideoPlay );
      disable( acVideoStop );
      disable( acVideoBackward );
      disable( acVideoForward );

      disable( sldFrame );
      disable( lblFrame );
      disable( sbxFRate );
    }

    pldWindow->close( );
  }
} // End of fileClose.


//******************************************************************************
// PROCEDURE fileExit
//******************************************************************************

void CLPlayerWin::fileExit( void )
{
  qApp->closeAllWindows( );
} // End of fileExit.


//******************************************************************************
// PROCEDURE showFrame
//******************************************************************************

void CLPlayerWin::showFrame( int iFrame )
{
  CLVideo     *vid = NULL;
  CLPlayerDoc *pld = NULL;


  if ( !bIsLocked )
  {
    pld = ( CLPlayerDoc * )workspace( )->activeWindow( );

    if ( NULL != pld )
    {
      vid = pld->view( )->video( );

      if ( vid->currentFrame( ) != iFrame )
        vid->setCurrentFrame( iFrame );
    }
  }
  else
  {
    int i;

    int iNumWin;

    QWidgetList wglWindow = workspace( )->windowList( );


    iNumWin = int( wglWindow.count( ) );

    for ( i = 0; i < iNumWin; ++i )
    {
      pld = ( CLPlayerDoc * )wglWindow.at( i );
      vid = pld->view( )->video( );

      if ( vid->currentFrame( ) != iFrame )
        vid->setCurrentFrame( iFrame );
    }
  }

  lblFrame->setNum( iFrame );
} // End of showFrame.


//******************************************************************************
// PROCEDURE changeFrequency
//******************************************************************************

void CLPlayerWin::changeFrequency( int iFrequency )
{
  if ( !bIsPlaying )
    return;

  tmrVideo->changeInterval( int( 1000.0/iFrequency + 0.5 ) );
} // End of changeFrequency.


//******************************************************************************
// PROCEDURE playFrame
//******************************************************************************

void CLPlayerWin::playFrame( void )
{
  CLVideo     *vid = NULL;
  CLPlayerDoc *pld = NULL;


  if ( !bIsLocked )
  {
    pld = ( CLPlayerDoc * )workspace( )->activeWindow( );

    if ( NULL == pld )
      return;

    vid = pld->view( )->video( );

    if ( vid->currentFrame( ) == vid->numberOfFrames( ) )
    {
      computeFrameRate( vid->numberOfFrames( ), timFRate->elapsed( ) );
      timFRate->start( );

      if ( !bIsLooping )
      {
        videoStop( );

        return;
      }

      vid->showFirstFrame( );
    }
    else
      vid->showNextFrame( );
  }
  else
  {
    int i;

    int iNumWin;

    QWidgetList wglWindow = workspace( )->windowList( );

    CLPlayerDoc *pldActive = ( CLPlayerDoc * )workspace( )->activeWindow( );


    iNumWin = int( wglWindow.count( ) );

    for ( i = 0; i < iNumWin; ++i )
    {
      pld = ( CLPlayerDoc * )wglWindow.at( i );
      vid = pld->view( )->video( );

      if ( vid->currentFrame( ) == vid->numberOfFrames( ) )
      {
        if ( pld == pldActive )
        {
          computeFrameRate( vid->numberOfFrames( ), timFRate->elapsed( ) );
          timFRate->start( );
        }

        if ( !bIsLooping )
        {
          videoStop( );

          return;
        }

        vid->showFirstFrame( );
      }
      else
        vid->showNextFrame( );
    }
  }

  if ( vid != NULL )
    sldFrame->setValue( vid->currentFrame( ) );
} // End of playFrame.


//******************************************************************************
// PROCEDURE videoPlay
//******************************************************************************

void CLPlayerWin::videoPlay( void )
{
  if ( bIsPlaying )
  {
    bIsPlaying = false;

    tmrVideo->stop( );
    acVideoPlay->setIconSet( pxmPlay );
  }
  else
  {
    bIsPlaying = true;

    timFRate->start( );
    tmrVideo->start( int( 1000.0/sbxFRate->value( ) + 0.5 ), false );
    acVideoPlay->setIconSet( pxmPause );
  }
} // End of videoPlay.


//******************************************************************************
// PROCEDURE videoStop
//******************************************************************************

void CLPlayerWin::videoStop( void )
{
  CLVideo     *vid = NULL;
  CLPlayerDoc *pld = NULL;


  tmrVideo->stop( );

  bIsPlaying = false;

  if ( !bIsLocked )
  {
    pld = ( CLPlayerDoc * )workspace( )->activeWindow( );

    if ( NULL != pld )
    {
      vid = pld->view( )->video( );

      if ( vid->currentFrame( ) != 1 )
        vid->showFirstFrame( );
    }
  }
  else
  {
    int i;

    int iNumWin;

    QWidgetList wglWindow = workspace( )->windowList( );


    iNumWin = int( wglWindow.count( ) );

    for ( i = 0; i < iNumWin; ++i )
    {
      pld = ( CLPlayerDoc * )wglWindow.at( i );
      vid = pld->view( )->video( );

      if ( vid->currentFrame( ) != 1 )
        vid->showFirstFrame( );
    }
  }

  sldFrame->setValue( 1 );

  acVideoPlay->setIconSet( pxmPlay );
} // End of videoStop.


//******************************************************************************
// PROCEDURE videoBackward
//******************************************************************************

void CLPlayerWin::videoBackward( void )
{
  CLVideo     *vid = NULL;
  CLPlayerDoc *pld = NULL;


  tmrVideo->stop( );

  bIsPlaying = false;

  if ( !bIsLocked )
  {
    pld = ( CLPlayerDoc * )workspace( )->activeWindow( );

    if ( NULL == pld )
      return;

    vid = pld->view( )->video( );
    vid->showPrevFrame( );
  }
  else
  {
    int i;

    int iNumWin;

    QWidgetList wglWindow = workspace( )->windowList( );


    iNumWin = int( wglWindow.count( ) );

    for ( i = 0; i < iNumWin; ++i )
    {
      pld = ( CLPlayerDoc * )wglWindow.at( i );

      vid = pld->view( )->video( );
      vid->showPrevFrame( );
    }
  }

  if ( NULL != vid )
    sldFrame->setValue( vid->currentFrame( ) );

  acVideoPlay->setIconSet( pxmPlay );
} // End of videoBackward.


//******************************************************************************
// PROCEDURE videoForward
//******************************************************************************

void CLPlayerWin::videoForward( void )
{
  CLVideo     *vid = NULL;
  CLPlayerDoc *pld = NULL;


  tmrVideo->stop( );

  bIsPlaying = false;

  if ( !bIsLocked )
  {
    pld = ( CLPlayerDoc * )workspace( )->activeWindow( );

    if ( NULL == pld )
      return;

    vid = pld->view( )->video( );
    vid->showNextFrame( );
  }
  else
  {
    int i;

    int iNumWin;

    QWidgetList wglWindow = workspace( )->windowList( );


    iNumWin = int( wglWindow.count( ) );

    if ( 0 == iNumWin )
      return;

    for ( i = 0; i < iNumWin; ++i )
    {
      pld = ( CLPlayerDoc * )wglWindow.at( i );

      vid = pld->view( )->video( );
      vid->showNextFrame( );
    }
  }

  if ( NULL != vid )
    sldFrame->setValue( vid->currentFrame( ) );

  acVideoPlay->setIconSet( pxmPlay );
} // End of videoForward.


//******************************************************************************
// PROCEDURE videoLoop
//******************************************************************************

void CLPlayerWin::videoLoop( bool bState )
{
  bIsLooping = bState;
} // End of videoLoop.


//******************************************************************************
// PROCEDURE videoLock
//******************************************************************************

void CLPlayerWin::videoLock( bool bState )
{
  bIsLocked = bState;

  acVideoLock->setIconSet( bIsLocked ? pxmLock : pxmUnlock );
} // End of videoLock.


//******************************************************************************
// PROCEDURE videoCenter
//******************************************************************************

void CLPlayerWin::videoCenter( void )
{
  CLPlayerDoc *pld = NULL;


  if ( !bIsLocked )
  {
    pld = ( CLPlayerDoc * )workspace( )->activeWindow( );

    if ( NULL != pld )
      pld->view( )->centerVideo( );
  }
  else
  {
    int i;

    int iNumWin;

    QWidgetList wglWindow = workspace( )->windowList( );


    iNumWin = int( wglWindow.count( ) );

    for ( i = 0; i < iNumWin; ++i )
    {
      pld = ( CLPlayerDoc * )wglWindow.at( i );
      pld->view( )->centerVideo( );
    }
  }
} // End of videoCenter.


//******************************************************************************
// PROCEDURE viewMenuBar
//******************************************************************************

void CLPlayerWin::viewMenuBar( bool bState )
{
  if ( true == bState )
    menuBar( )->show( );
  else
    menuBar( )->hide( );
} // End of viewMenuBar.


//******************************************************************************
// PROCEDURE viewTBarFile
//******************************************************************************

void CLPlayerWin::viewTBarFile( bool bState )
{
  if ( true == bState )
    tbrFile->show( );
  else
    tbrFile->hide( );
} // End of viewTBarFile.


//******************************************************************************
// PROCEDURE viewTBarVideo
//******************************************************************************

void CLPlayerWin::viewTBarVideo( bool bState )
{
  if ( true == bState )
    tbrVideo->show( );
  else
    tbrVideo->hide( );
} // End of viewTBarVideo.


//******************************************************************************
// PROCEDURE viewStatusBar
//******************************************************************************

void CLPlayerWin::viewStatusBar( bool bState )
{
  if ( true == bState )
    statusBar( )->show( );
  else
    statusBar( )->hide( );
} // End of viewStatusBar.


//******************************************************************************
// PROCEDURE viewFullScreen
//******************************************************************************

void CLPlayerWin::viewFullScreen( bool bState )
{
  if ( true == bState )
    showFullScreen( );
  else
    showNormal( );
} // End of viewFullScreen.


//******************************************************************************
// PROCEDURE windCascade
//******************************************************************************

void CLPlayerWin::windCascade( void )
{
  workspace( )->cascade( );
} // End of windCascade.


//******************************************************************************
// PROCEDURE windTileVer
//******************************************************************************

void CLPlayerWin::windTileVer( void )
{
  workspace( )->tile( );
} // End of windTileVer.


//******************************************************************************
// PROCEDURE windTileHor
//******************************************************************************

void CLPlayerWin::windTileHor( void )
{
  int iNumWin;

  QWidgetList wglWindow = workspace( )->windowList( );


  iNumWin = int( wglWindow.count( ) );

  // Primitive horizontal tiling
  if ( 0 == iNumWin )
    return;

  int i;

  int iX = 0, iY = 0, iSizeX, iSizeY;

  QWidget *wgtWindow, *wgtParent;


  iSizeX = workspace( )->width( );

  for ( i = 0; i < iNumWin; ++i )
  {
    wgtWindow = wglWindow.at( i );
    wgtParent = wgtWindow->parentWidget( );

    if ( wgtWindow->testWState( WState_Maximized ) )
    {
      // Prevent flicker.
      wgtWindow->hide( );
      wgtWindow->showNormal( );
    }

    iSizeY = workspace( )->height( )/iNumWin;
    iSizeY = QMAX( iSizeY, wgtWindow->minimumHeight( ) +
                           wgtParent->baseSize( ).height( ) );

    wgtParent->setGeometry( iX, iY, iSizeX, iSizeY );

    iY += iSizeY;
  }
} // End of windTileHor.


//******************************************************************************
// PROCEDURE menuWindowActivated
//******************************************************************************

void CLPlayerWin::menuWindowActivated( int iMenuID )
{
  QWidget *wgtWindow = workspace( )->windowList( ).at( iMenuID );


  if ( NULL != wgtWindow )
    wgtWindow->showNormal( );

  wgtWindow->setFocus( );
} // End of menuWindowActivated.


//******************************************************************************
// PROCEDURE menuWindowAboutToShow
//******************************************************************************

void CLPlayerWin::menuWindowAboutToShow( void )
{
  bool bEnableAction;

  int i, iMenuID, iNumWin;

  QWidgetList wglWindow = workspace( )->windowList( );

  QWidget *wgtWindow, *wgtActive;


  acWindCascade->removeFrom( pmuWindow );
  acWindTileVer->removeFrom( pmuWindow );
  acWindTileHor->removeFrom( pmuWindow );

  pmuWindow->clear( );

  acWindCascade->addTo( pmuWindow );
  acWindTileVer->addTo( pmuWindow );
  acWindTileHor->addTo( pmuWindow );
  pmuWindow->insertSeparator( );

  bEnableAction = bool( false == wglWindow.isEmpty( ) );

  acWindCascade->setEnabled( bEnableAction );
  acWindTileVer->setEnabled( bEnableAction );
  acWindTileHor->setEnabled( bEnableAction );

  iNumWin = int( wglWindow.count( ) );

  wgtActive = workspace( )->activeWindow( );

  for ( i = 0; i < iNumWin; ++i )
  {
    wgtWindow = wglWindow.at( i );

    iMenuID = pmuWindow->insertItem( pxmApp16x16, wgtWindow->caption( ),
                                     this, SLOT( menuWindowActivated( int ) ) );

    pmuWindow->setItemParameter( iMenuID, i );
    pmuWindow->setItemChecked( iMenuID, wgtActive == wgtWindow );
  }
} // End of menuWindowAboutToShow.


//******************************************************************************
// PROCEDURE helpContents
//******************************************************************************

void CLPlayerWin::helpContents( void )
{
  QMessageBox mbx( tr( "ZPlayer - Hot Keys" ), tr(
    "\n<h3>Hot keys</h3>"
    "\n"
    "\n<p><b>P</b>: play/pause."
    "\n<br><b>S</b>: stop."
    "\n<br><b>B</b>: step backward."
    "\n<br><b>F</b>: step forward.</p>"
    "\n"
    "\n<p><b>L</b>: set/unset loop."
    "\n<br><b>K</b>: lock/unlock video actions.</p>"
    "\n"
    "\n<p><b>C</b>: center video.</p>"
    "\n"
    "\n<p><b>F6</b>: tile vertically."
    "\n<br><b>F7</b>: tile horizontally.</p>"
  ), QMessageBox::NoIcon,
     QMessageBox::Ok | QMessageBox::Default,
     0, 0, this );

  mbx.setIconPixmap( pxmApp32x32 );
  mbx.exec( );
} // End of helpContents.


//******************************************************************************
// PROCEDURE helpAboutApp
//******************************************************************************

void CLPlayerWin::helpAboutApp( void )
{
  QMessageBox mbx( tr( "About ZPlayer" ), tr(
    "\n<P ALIGN=\"justify\">"
    "\n<B>ZPlayer - Version 0.5.0</B></P>"
    "\n"
    "\n<P ALIGN=\"justify\">"
    "\nThis program plays files in YUV 4:0:0, 4:2:0, 4:2:2 and 4:4:4"
    "\nformats.</P>"
    "\n"
    "\n<P ALIGN=\"justify\">"
    "\nCopyright &copy; 2005 by <B>José F. L. de Oliveira</B>,"
    "\n<EM>jleite@lps.ufrj.br</EM>.</P>"
    "\n"
    "\n<P ALIGN=\"justify\">"
    "\nThis program is <B>free software</B>; you can redistribute"
    "\nit and/or modify it under the terms of the <B>GNU General"
    "\nPublic License</B> as published by the <B>Free Software"
    "\nFoundation</B>; either version 2 of the License, or (at your"
    "\noption) any later version.</P>"
    "\n"
    "\n<P ALIGN=\"justify\">"
    "\nThis program is distributed in the hope that it will be"
    "\nuseful, but <B>WITHOUT ANY WARRANTY</B>; without even the"
    "\nimplied warranty of <B>MERCHANTABILITY</B> or <B>FITNESS FOR A"
    "\nPARTICULAR PURPOSE</B>. See the GNU General Public License"
    "\nfor more details.</P>"
    "\n"
    "\n<P ALIGN=\"justify\">"
    "\nYou should have received a copy of the GNU General Public"
    "\nLicense along with this program; if not, write to the <EM>Free"
    "\nSoftware Foundation, Inc., 59 Temple Place - Suite 330, Boston,"
    "\nMA 02111-1307, USA</EM>.</P>"
  ), QMessageBox::NoIcon,
     QMessageBox::Ok | QMessageBox::Default,
     0, 0, this );

  mbx.setIconPixmap( pxmApp32x32 );
  mbx.exec( );
} // End of helpAboutApp.


//******************************************************************************
// PROCEDURE helpAboutQt
//******************************************************************************

void CLPlayerWin::helpAboutQt( void )
{
  QMessageBox::aboutQt( this, tr( "About Qt" ) );
} // End of helpAboutQt.


//******************************************************************************
// PROCEDURE helpCmdLine
//******************************************************************************

void CLPlayerWin::helpCmdLine( void )
{
  QMessageBox mbx( tr( "ZPlayer - Command Line Help" ), tr(
    "\n<P><B>Usage:</B></P>"
    "\n"
    "\n<P><B>player</B> [-a|--all] [-h|--help] [-l|--loop]"
    "\n[-r|--rate <EM>Frequency</EM>] [-s|--size <EM>Width Height</EM>]"
    "\n[-c|--colorspace <EM>Type</EM>] [<EM>FileNameA</EM>"
    "\n[<EM>FileNameB</EM>]]</P>"
    "\n"
    "\n<P><B>Options:</B></P>"
    "\n"
    "\n<P><B>-a|--all</B>: Load all frames in memory. This improves playing"
    "\nspeed but can eat all your available memory, slowing down your"
    "\nsystem.</P>"
    "\n"
    "\n<P><B>-h|--help</B>: Print this help.</P>"
    "\n"
    "\n<P><B>-l|--loop</B>: Loop on.</P>"
    "\n"
    "\n<P><B>-r|--rate</B> <EM>Frequency</EM>: Frame rate. <EM>Frequency</EM>"
    "\nshould be in the range from 1Hz to 100Hz.</P>"
    "\n"
    "\n<P><B>-s|--size</B> <EM>Width Height</EM>: Frame size.</P>"
    "\n"
    "\n<P><B>-c|--colorspace</B> <EM>Type</EM>: Color space. <EM>Type</EM>"
    "\ncan be YUV400, YUV420, YUV422 or YUV444.</P>"
  ), QMessageBox::NoIcon,
     QMessageBox::Ok | QMessageBox::Default,
     0, 0, this );

  mbx.setIconPixmap( pxmApp32x32 );
  mbx.exec( );
} // End of helpCmdLine.


//******************************************************************************
// PROCEDURE parseCmdLine
//******************************************************************************

void CLPlayerWin::parseCmdLine( int iArgC, char *a_szArgV[] )
{
  if ( 1 == iArgC )
    return;


  bool bAll  = false;
  bool bLoop = false;

  int iFrequency  = 30;
  int iVideoSizeX = 176;
  int iVideoSizeY = 144;
  int iColorSpace = 1;

  int iCurrArg = 1;

  QString strArgV;

  QString strFileNameA;
  QString strFileNameB;


  iCurrArg = 1;

  while ( iCurrArg < iArgC )
  {
    strArgV = QString( a_szArgV[iCurrArg] );

    if ( strArgV == tr( "--all" ) || strArgV == tr( "-a" ) )
    {
      bAll = true;
    }
    else if ( strArgV == tr( "--help" ) || strArgV == tr( "-h" ) )
    {
      helpCmdLine( );
      return;
    }
    else if ( strArgV == tr( "--loop" )  || strArgV == tr( "-l" ) )
    {
      bLoop = true;
    }
    else if ( strArgV == tr( "--rate" ) || strArgV == tr( "-r" ))
    {
      ++iCurrArg;

      if ( iCurrArg < iArgC )
        iFrequency = QString( a_szArgV[iCurrArg] ).toInt( );
      else
      {
        helpCmdLine( );
        return;
      }

      if ( iFrequency < 0 || iFrequency > 100 )
      {
        helpCmdLine( );
        return;
      }
    }
    else if ( strArgV == tr( "--size" ) || strArgV == tr( "-s" ) )
    {
      ++iCurrArg;

      if ( iCurrArg < iArgC )
        iVideoSizeX = QString( a_szArgV[iCurrArg] ).toInt( );
      else
      {
        helpCmdLine( );
        return;
      }

      ++iCurrArg;

      if ( iCurrArg < iArgC )
        iVideoSizeY = QString( a_szArgV[iCurrArg] ).toInt( );
      else
      {
        helpCmdLine( );
        return;
      }

      if ( iVideoSizeX < 16 || iVideoSizeX > 8192 ||
           iVideoSizeY < 16 || iVideoSizeY > 8192 )
      {
        helpCmdLine( );
        return;
      }
    }
    else if ( strArgV == tr( "--colorspace" ) || strArgV == tr( "-c" ) )
    {
      ++iCurrArg;

      if ( iCurrArg < iArgC )
      {
        QString strCSpace( a_szArgV[iCurrArg] );

        if ( strCSpace == QString( "YUV400" ) ) iColorSpace = 0;
        if ( strCSpace == QString( "YUV420" ) ) iColorSpace = 1;
        if ( strCSpace == QString( "YUV422" ) ) iColorSpace = 2;
        if ( strCSpace == QString( "YUV444" ) ) iColorSpace = 3;
      }
      else
      {
        helpCmdLine( );
        return;
      }
    }
    else
    {
      if ( true == strFileNameA.isEmpty( ) )
      {
        strFileNameA = strArgV;
      }
      else if ( true == strFileNameB.isEmpty( ) )
      {
        strFileNameB = strArgV;
      }
      else
      {
        helpCmdLine( );
        return;
      }
    }

    ++iCurrArg;
  }

  int iNumFramesA = 0,
      iNumFramesB = 0;


  if ( false == strFileNameA.isEmpty( ) )
  {
    CLPlayerDoc *pldWindowA = newDoc( );

    if ( true == pldWindowA->load( strFileNameA, iVideoSizeX, iVideoSizeY,
                                   iColorSpace, bAll ) )
    {
      iNumFramesA = pldWindowA->view( )->video( )->numberOfFrames( );
    }
    else
      pldWindowA->close( );
  }

  if ( false == strFileNameB.isEmpty( ) )
  {
    CLPlayerDoc *pldWindowB = newDoc( );

    if ( true == pldWindowB->load( strFileNameB, iVideoSizeX, iVideoSizeY,
                                   iColorSpace, bAll ) )
    {
      iNumFramesB = pldWindowB->view( )->video( )->numberOfFrames( );
    }
    else
      pldWindowB->close( );
  }

  sbxFRate->setValue( iFrequency );

  if ( iNumFramesA == 0 && iNumFramesB == 0 )
    return;

  enable( acFileSave );
  enable( acFileSaveAs );
  enable( acFileClose );

  enable( acVideoPlay );
  enable( acVideoStop );
  enable( acVideoBackward );
  enable( acVideoForward );

  enable( sldFrame );
  enable( lblFrame );
  enable( sbxFRate );

  if ( iNumFramesA == 0 )
  {
    sldFrame->setMaxValue( iNumFramesB );

    acVideoLoop->toggle( );

    videoPlay( );
    return;
  }

  if ( iNumFramesB == 0 )
  {
    sldFrame->setMaxValue( iNumFramesA );

    acVideoLoop->toggle( );

    videoPlay( );
    return;
  }

  sldFrame->setMaxValue( QMIN( iNumFramesA, iNumFramesB ) );

  acVideoLoop->toggle( );
  acVideoLock->toggle( );

  videoPlay( );
} // End of parseCmdLine.


//******************************************************************************
// PROCEDURE CLPlayerWin (Constructor)
//******************************************************************************
//
// Constructs a CLPlayerWin as a child of 'parent', with the
// name 'name' and widget flags set to 'f'.
//
//******************************************************************************

CLPlayerWin::CLPlayerWin( QWidget *wgtParent, const char *szName, WFlags fl )
            :QMainWindow( wgtParent, szName, fl )
{
  bIsPlaying = false;
  bIsLooping = false;
  bIsLocked  = false;

  bNoName = true;

  bCheckExistingFile = true;

  dirOpen = QDir::current( );
  dirSave = QDir::current( );

  strOpenFile = QString::null;
  strSaveFile = QString( tr( "noname.yuv" ) );

  if ( NULL == szName )
    setName( "ZPlayer Window" );

  statusBar( )->clear( );

  // Icons.
  pxmApp16x16  = QPixmap( ( const char ** )datApp16x16 );
  pxmApp32x32  = QPixmap( ( const char ** )datApp32x32 );

  pxmFileNew   = QPixmap( ( const char ** )datFileNew );
  pxmFileOpen  = QPixmap( ( const char ** )datFileOpen );
  pxmFileSave  = QPixmap( ( const char ** )datFileSave );
  pxmFileClose = QPixmap( ( const char ** )datFileClose );
  pxmFileExit  = QPixmap( ( const char ** )datFileExit );

  pxmPlay      = QPixmap( ( const char ** )datPlay );
  pxmPause     = QPixmap( ( const char ** )datPause );
  pxmStop      = QPixmap( ( const char ** )datStop );
  pxmBackward  = QPixmap( ( const char ** )datBackward );
  pxmForward   = QPixmap( ( const char ** )datForward );
  pxmLoop      = QPixmap( ( const char ** )datLoop );
  pxmLock      = QPixmap( ( const char ** )datLock );
  pxmUnlock    = QPixmap( ( const char ** )datUnlock );
  pxmCenter    = QPixmap( ( const char ** )datCenter );

  pxmCascade   = QPixmap( ( const char ** )datCascade );
  pxmTileVer   = QPixmap( ( const char ** )datTileVer );
  pxmTileHor   = QPixmap( ( const char ** )datTileHor );

  pxmContents  = QPixmap( ( const char ** )datContents );
  pxmQtLogo    = QPixmap( ( const char ** )datQtLogo );

  setIcon( pxmApp16x16 );

  // File actions.
  acFileNew    = new QAction( this, "AC FileNew" );
  acFileOpen   = new QAction( this, "AC FileOpen" );
  acFileSave   = new QAction( this, "AC FileSave" );
  acFileSaveAs = new QAction( this, "AC FileSaveAs" );
  acFileClose  = new QAction( this, "AC FileClose" );
  acFileExit   = new QAction( this, "AC FileExit" );

  acFileNew  ->setIconSet( QIconSet( pxmFileNew ) );
  acFileOpen ->setIconSet( QIconSet( pxmFileOpen ) );
  acFileSave ->setIconSet( QIconSet( pxmFileSave ) );
  acFileClose->setIconSet( QIconSet( pxmFileClose ) );
  acFileExit ->setIconSet( QIconSet( pxmFileExit ) );

  // Video actions.
  acVideoPlay     = new QAction( this, "AC VideoPlay" );
  acVideoStop     = new QAction( this, "AC VideoStop" );
  acVideoBackward = new QAction( this, "AC VideoBackward" );
  acVideoForward  = new QAction( this, "AC VideoForward" );
  acVideoLoop     = new QAction( this, "AC VideoLoop" );
  acVideoLock     = new QAction( this, "AC VideoLock" );
  acVideoCenter   = new QAction( this, "AC VideoCenter" );

  acVideoPlay    ->setIconSet( QIconSet( pxmPlay ) );
  acVideoStop    ->setIconSet( QIconSet( pxmStop ) );
  acVideoBackward->setIconSet( QIconSet( pxmBackward ) );
  acVideoForward ->setIconSet( QIconSet( pxmForward ) );
  acVideoLoop    ->setIconSet( QIconSet( pxmLoop ) );
  acVideoLock    ->setIconSet( QIconSet( pxmUnlock ) );
  acVideoCenter  ->setIconSet( QIconSet( pxmCenter ) );

  acVideoLoop->setToggleAction( true );
  acVideoLock->setToggleAction( true );

  acVideoLoop->setOn( false );
  acVideoLock->setOn( false );

  // View actions.
  acViewMenuBar    = new QAction( this, "AC ViewMenuBar" );
  acViewTBarFile   = new QAction( this, "AC ViewTBarFile" );
  acViewTBarVideo  = new QAction( this, "AC ViewTBarVideo" );
  acViewStatusBar  = new QAction( this, "AC ViewStatusBar" );
  acViewFullScreen = new QAction( this, "AC ViewFullScreen" );

  acViewMenuBar   ->setToggleAction( true );
  acViewTBarFile  ->setToggleAction( true );
  acViewTBarVideo ->setToggleAction( true );
  acViewStatusBar ->setToggleAction( true );
  acViewFullScreen->setToggleAction( true );

  acViewMenuBar   ->setOn( true );
  acViewTBarFile  ->setOn( true );
  acViewTBarVideo ->setOn( true );
  acViewStatusBar ->setOn( true );
  acViewFullScreen->setOn( false );

  // Window actions.
  acWindCascade = new QAction( this, "AC WindCascade" );
  acWindTileVer = new QAction( this, "AC WindTileVer" );
  acWindTileHor = new QAction( this, "AC WindTileHor" );

  acWindCascade->setIconSet( QIconSet( pxmCascade ) );
  acWindTileVer->setIconSet( QIconSet( pxmTileVer ) );
  acWindTileHor->setIconSet( QIconSet( pxmTileHor ) );

  // Help actions.
  acHelpContents  = new QAction( this, "AC HelpContents" );
  acHelpAboutApp  = new QAction( this, "AC HelpAboutApp" );
  acHelpAboutQt   = new QAction( this, "AC HelpAboutQt" );
  acHelpWhatsThis = new QAction( this, "AC HelpWhatsThis" );

  acHelpContents->setIconSet( QIconSet( pxmContents ) );
  acHelpAboutApp->setIconSet( QIconSet( pxmApp16x16 ) );
  acHelpAboutQt ->setIconSet( QIconSet( pxmQtLogo   ) );

  // File toolbar.
  tbrFile = new QToolBar( QString( "" ), this, DockTop );
  tbrFile->setCloseMode( QDockWindow::Undocked );
  tbrFile->boxLayout( )->setMargin( 2 );
  tbrFile->boxLayout( )->setSpacing( 2 );

  acFileNew ->addTo( tbrFile );
  acFileOpen->addTo( tbrFile );
  acFileSave->addTo( tbrFile );
  tbrFile->addSeparator( );

  acFileExit->addTo( tbrFile );

  // Video toolbar.
  tbrVideo = new QToolBar( QString( "" ), this, DockTop );
  tbrVideo->setCloseMode( QDockWindow::Undocked );
  tbrVideo->boxLayout( )->setMargin( 2 );
  tbrVideo->boxLayout( )->setSpacing( 2 );
  tbrVideo->setHorizontallyStretchable( true );

  acVideoPlay    ->addTo( tbrVideo );
  acVideoStop    ->addTo( tbrVideo );
  acVideoBackward->addTo( tbrVideo );
  acVideoForward ->addTo( tbrVideo );
  tbrVideo->addSeparator( );

  acVideoLoop->addTo( tbrVideo );
  acVideoLock->addTo( tbrVideo );
  tbrVideo->addSeparator( );

  acVideoCenter->addTo( tbrVideo );
  tbrVideo->addSeparator( );

  sldFrame = new QSlider( tbrVideo, "SLD Frame" );
  sldFrame->setOrientation( QSlider::Horizontal );
  sldFrame->setMinValue( 1 );
  sldFrame->setMaxValue( 1 );
  tbrVideo->addSeparator( );

  QPalette pal;
  QColorGroup cgp;

  lblFrame = new QLabel( tbrVideo, "LBL Frame" );

  pal = lblFrame->palette( );

  cgp = pal.active( );
  cgp.setColor( QColorGroup::Foreground, Qt::cyan );
  cgp.setColor( QColorGroup::Background, Qt::black );
  cgp.setColor( QColorGroup::Text, Qt::cyan );
  cgp.setColor( QColorGroup::Base, Qt::black );
  cgp.setColor( QColorGroup::Highlight      , Qt::cyan );
  cgp.setColor( QColorGroup::HighlightedText, Qt::black );
  pal.setActive( cgp );

  cgp = pal.inactive( );
  cgp.setColor( QColorGroup::Foreground, Qt::cyan );
  cgp.setColor( QColorGroup::Background, Qt::black );
  cgp.setColor( QColorGroup::Text, Qt::cyan );
  cgp.setColor( QColorGroup::Base, Qt::black );
  cgp.setColor( QColorGroup::Highlight      , Qt::cyan );
  cgp.setColor( QColorGroup::HighlightedText, Qt::black );
  pal.setInactive( cgp );

  cgp = pal.disabled( );
  cgp.setColor( QColorGroup::Foreground, Qt::cyan.dark( ) );
  cgp.setColor( QColorGroup::Background, Qt::black );
  cgp.setColor( QColorGroup::Text, Qt::cyan.dark( ) );
  cgp.setColor( QColorGroup::Base, Qt::black );
  cgp.setColor( QColorGroup::Highlight      , Qt::cyan.dark( ) );
  cgp.setColor( QColorGroup::HighlightedText, Qt::black );
  pal.setDisabled( cgp );

  lblFrame->setPalette( pal );
  lblFrame->setFrameShape( QLabel::LineEditPanel );
  lblFrame->setFrameShadow( QLabel::Sunken );
  lblFrame->setMinimumWidth( 4 + fontMetrics( ).width( "0000000" ) );
  lblFrame->setNum( 1 );
  tbrVideo->addSeparator( );

  sbxFRate = new QSpinBox( tbrVideo, "SBX FRate" );

  pal = sbxFRate->palette( );

  cgp = pal.active( );
  cgp.setColor( QColorGroup::Foreground, Qt::cyan );
  cgp.setColor( QColorGroup::Background, Qt::black );
  cgp.setColor( QColorGroup::Text, Qt::cyan );
  cgp.setColor( QColorGroup::Base, Qt::black );
  cgp.setColor( QColorGroup::Highlight      , Qt::cyan );
  cgp.setColor( QColorGroup::HighlightedText, Qt::black );
  pal.setActive( cgp );

  cgp = pal.inactive( );
  cgp.setColor( QColorGroup::Foreground, Qt::cyan );
  cgp.setColor( QColorGroup::Background, Qt::black );
  cgp.setColor( QColorGroup::Text, Qt::cyan );
  cgp.setColor( QColorGroup::Base, Qt::black );
  cgp.setColor( QColorGroup::Highlight      , Qt::cyan );
  cgp.setColor( QColorGroup::HighlightedText, Qt::black );
  pal.setInactive( cgp );

  cgp = pal.disabled( );
  cgp.setColor( QColorGroup::Foreground, Qt::cyan.dark( ) );
  cgp.setColor( QColorGroup::Background, Qt::black );
  cgp.setColor( QColorGroup::Text, Qt::cyan.dark( ) );
  cgp.setColor( QColorGroup::Base, Qt::black );
  cgp.setColor( QColorGroup::Highlight      , Qt::cyan.dark( ) );
  cgp.setColor( QColorGroup::HighlightedText, Qt::black );
  pal.setDisabled( cgp );

  sbxFRate->setPalette( pal );
  sbxFRate->setMinValue( 5 );
  sbxFRate->setMaxValue( 100 );
  sbxFRate->setLineStep( 5 );
  sbxFRate->setValue( 30 );
  sbxFRate->setSuffix( " Hz" );
  tbrVideo->addSeparator( );

  acHelpWhatsThis->setIconSet(
    QWhatsThis::whatsThisButton( tbrVideo )->iconSet( )
  );

  // File menu.
  pmuFile = new QPopupMenu( this, "PMU File" );

  acFileNew ->addTo( pmuFile );
  acFileOpen->addTo( pmuFile );
  pmuFile->insertSeparator( );

  acFileSave  ->addTo( pmuFile );
  acFileSaveAs->addTo( pmuFile );
  pmuFile->insertSeparator( );

  acFileClose->addTo( pmuFile );
  acFileExit ->addTo( pmuFile );

  // Video menu.
  pmuVideo = new QPopupMenu( this, "PMU Video" );

  acVideoPlay    ->addTo( pmuVideo );
  acVideoStop    ->addTo( pmuVideo );
  acVideoBackward->addTo( pmuVideo );
  acVideoForward ->addTo( pmuVideo );
  pmuVideo->insertSeparator( );

  acVideoLoop->addTo( pmuVideo );
  acVideoLock->addTo( pmuVideo );
  pmuVideo->insertSeparator( );

  acVideoCenter->addTo( pmuVideo );

  // View menu.
  pmuView = new QPopupMenu( this, "PMU View" );

  acViewMenuBar->addTo( pmuView );
  pmuView->insertSeparator( );

  acViewTBarFile ->addTo( pmuView );
  acViewTBarVideo->addTo( pmuView );
  pmuView->insertSeparator( );

  acViewStatusBar->addTo( pmuView );
  pmuView->insertSeparator( );

  acViewFullScreen->addTo( pmuView );

  // Window menu.
  pmuWindow = new QPopupMenu( this, "PMU Window" );
  pmuWindow->setCheckable( true );

  acWindCascade->addTo( pmuWindow );
  acWindTileVer->addTo( pmuWindow );
  acWindTileHor->addTo( pmuWindow );
  pmuWindow->insertSeparator( );

  // Help menu.
  pmuHelp = new QPopupMenu( this, "PMU Help" );

  acHelpContents->addTo( pmuHelp );
  pmuHelp->insertSeparator( );

  acHelpAboutApp->addTo( pmuHelp );
  acHelpAboutQt ->addTo( pmuHelp );
  pmuHelp->insertSeparator( );

  acHelpWhatsThis->addTo( pmuHelp );

  // Main menu.
  mbrMain = new QMenuBar( this, "MBR Main" );
  mbrMain->setLineWidth( 1 );

  mbrMain->insertItem( QString( "" ), pmuFile  , 3 );
  mbrMain->insertItem( QString( "" ), pmuVideo , 4 );
  mbrMain->insertItem( QString( "" ), pmuView  , 5 );
  mbrMain->insertItem( QString( "" ), pmuWindow, 6 );
  mbrMain->insertSeparator( 7 );

  mbrMain->insertItem( QString( "" ), pmuHelp  , 8 );

  // Central widget.
  vbxCentral = new QVBox( this, "VBX Central" );
  vbxCentral->setFrameStyle( QFrame::StyledPanel | QFrame::Sunken );

  wksCentral = new QWorkspace( vbxCentral, "WKS Central" );
  wksCentral->setScrollBarsEnabled( true );

  setCentralWidget( vbxCentral );

  // Video timer.
  tmrVideo = new QTimer( this, "TMR Video" );

  // Frame rate estimation.
  timFRate = new QTime( );

  // Signals and slots connections.
  connect( acFileNew   , SIGNAL( activated( ) ), this, SLOT( fileNew( ) ) );
  connect( acFileOpen  , SIGNAL( activated( ) ), this, SLOT( fileOpen( ) ) );
  connect( acFileSave  , SIGNAL( activated( ) ), this, SLOT( fileSave( ) ) );
  connect( acFileSaveAs, SIGNAL( activated( ) ), this, SLOT( fileSaveAs( ) ) );
  connect( acFileClose , SIGNAL( activated( ) ), this, SLOT( fileClose( ) ) );
  connect( acFileExit  , SIGNAL( activated( ) ), this, SLOT( fileExit( ) ) );

  connect( acVideoPlay    , SIGNAL( activated( ) ),
           this, SLOT( videoPlay( ) ) );
  connect( acVideoStop    , SIGNAL( activated( ) ),
           this, SLOT( videoStop( ) ) );
  connect( acVideoBackward, SIGNAL( activated( ) ),
           this, SLOT( videoBackward( ) ) );
  connect( acVideoForward , SIGNAL( activated( ) ),
           this, SLOT( videoForward( )  ) );
  connect( acVideoLoop    , SIGNAL( toggled( bool ) ),
           this, SLOT( videoLoop( bool ) ) );
  connect( acVideoLock    , SIGNAL( toggled( bool ) ),
           this, SLOT( videoLock( bool ) ) );
  connect( acVideoCenter  , SIGNAL( activated( ) ),
           this, SLOT( videoCenter( ) ) );

  connect( acViewMenuBar   , SIGNAL( toggled( bool ) ),
           this, SLOT( viewMenuBar  ( bool ) ) );
  connect( acViewTBarFile  , SIGNAL( toggled( bool ) ),
           this, SLOT( viewTBarFile ( bool ) ) );
  connect( acViewTBarVideo , SIGNAL( toggled( bool ) ),
           this, SLOT( viewTBarVideo( bool ) ) );
  connect( acViewStatusBar , SIGNAL( toggled( bool ) ),
           this, SLOT( viewStatusBar( bool ) ) );
  connect( acViewFullScreen, SIGNAL( toggled( bool ) ),
           this, SLOT( viewFullScreen( bool ) ) );

  connect( acWindCascade, SIGNAL( activated( ) ),
           this, SLOT( windCascade( ) ) );
  connect( acWindTileVer, SIGNAL( activated( ) ),
           this, SLOT( windTileVer( ) ) );
  connect( acWindTileHor, SIGNAL( activated( ) ),
           this, SLOT( windTileHor( ) ) );

  connect( pmuWindow, SIGNAL( aboutToShow( ) ),
           this, SLOT( menuWindowAboutToShow( ) ) );

  connect( acHelpContents, SIGNAL( activated( ) ),
           this, SLOT( helpContents( ) ) );
  connect( acHelpAboutApp, SIGNAL( activated( ) ),
           this, SLOT( helpAboutApp( ) ) );
  connect( acHelpAboutQt , SIGNAL( activated( ) ),
           this, SLOT( helpAboutQt( ) ) );
  connect( acHelpWhatsThis, SIGNAL( activated( ) ),
           this, SLOT( whatsThis( ) ) );

  connect( sldFrame, SIGNAL( valueChanged( int ) ),
           this, SLOT( showFrame( int ) ) );

  connect( sbxFRate, SIGNAL( valueChanged( int ) ),
           this, SLOT( changeFrequency( int ) ) );

  connect( tmrVideo, SIGNAL( timeout( ) ),
           this, SLOT( playFrame( ) ) );

  connect( wksCentral, SIGNAL( windowActivated( QWidget * ) ),
           this, SLOT( windowActivated( QWidget * ) ) );

  changeFrequency( 30 );

  disable( acFileSave );
  disable( acFileSaveAs );
  disable( acFileClose );

  disable( acVideoPlay );
  disable( acVideoStop );
  disable( acVideoBackward );
  disable( acVideoForward );

  disable( sldFrame );
  disable( lblFrame );
  disable( sbxFRate );

  languageChange( );
  clearWState( WState_Polished );
} // End of CLPlayerWin (Constructor).


//******************************************************************************
// PROCEDURE ~CLPlayerWin (Destructor)
//******************************************************************************

CLPlayerWin::~CLPlayerWin( void )
{
  ; // No action.
} // End of ~CLPlayerWin (Destructor).

