//******************************************************************************
//
// playerwin.h
//
//******************************************************************************
//
// Author..: José Fernando Leite de Oliveira
//
// Begin...: Wed May 04 2005
// Modified: Fri May 27 2005
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

#ifndef PLAYERWIN_H
#define PLAYERWIN_H

//******************************************************************************
// HEADERS
//******************************************************************************

// Qt headers.

#include <qdir.h>
#include <qmainwindow.h>
#include <qpixmap.h>
#include <qvariant.h>


//******************************************************************************
// FORWARD DECLARATIONS
//******************************************************************************

// Qt classes.

class QAction;
class QLabel;
class QPopupMenu;

class QSlider;
class QSpinBox;

class QTime;
class QTimer;
class QToolBar;

class QVBox;
class QWorkspace;

// App classes.

class CLPlayerDoc;
class CLPlayerView;


//******************************************************************************
// CLASS CLPlayerWin
//******************************************************************************

class CLPlayerWin : public QMainWindow // cl_plw
{
  Q_OBJECT

  private:

  bool bIsPlaying;
  bool bIsLooping;
  bool bIsLocked;

  bool bNoName;

  bool bCheckExistingFile;

  QDir dirOpen,
       dirSave;

  QString strOpenFile,
          strSaveFile;

  // Icons.
  QPixmap pxmApp16x16;
  QPixmap pxmApp32x32;

  QPixmap pxmFileNew;
  QPixmap pxmFileOpen;
  QPixmap pxmFileSave;
  QPixmap pxmFileClose;
  QPixmap pxmFileExit;

  QPixmap pxmBackward;
  QPixmap pxmPlay;
  QPixmap pxmPause;
  QPixmap pxmForward;
  QPixmap pxmStop;
  QPixmap pxmLoop;
  QPixmap pxmLock;
  QPixmap pxmUnlock;
  QPixmap pxmCenter;

  QPixmap pxmCascade;
  QPixmap pxmTileVer;
  QPixmap pxmTileHor;

  QPixmap pxmContents;
  QPixmap pxmQtLogo;

  // Actions.
  QAction *acFileNew;
  QAction *acFileOpen;
  QAction *acFileSave;
  QAction *acFileSaveAs;
  QAction *acFileClose;
  QAction *acFileExit;

  QAction *acVideoBackward;
  QAction *acVideoPlay;
  QAction *acVideoForward;
  QAction *acVideoStop;
  QAction *acVideoLoop;
  QAction *acVideoLock;
  QAction *acVideoCenter;

  QAction *acViewMenuBar;
  QAction *acViewTBarFile;
  QAction *acViewTBarVideo;
  QAction *acViewStatusBar;
  QAction *acViewFullScreen;

  QAction *acWindCascade;
  QAction *acWindTileVer;
  QAction *acWindTileHor;

  QAction *acHelpContents;
  QAction *acHelpAboutApp;
  QAction *acHelpAboutQt;
  QAction *acHelpWhatsThis;

  // Menu.
  QPopupMenu *pmuFile;
  QPopupMenu *pmuVideo;
  QPopupMenu *pmuView;
  QPopupMenu *pmuWindow;
  QPopupMenu *pmuHelp;

  QMenuBar *mbrMain;

  // Toolbars.
  QSlider  *sldFrame;
  QLabel   *lblFrame;
  QSpinBox *sbxFRate;

  QToolBar *tbrFile;
  QToolBar *tbrVideo;

  // Workspace.
  QVBox      *vbxCentral;
  QWorkspace *wksCentral;

  // Frame rate estimation.
  QTime *timFRate;

  // Video timer.
  QTimer *tmrVideo;


  protected slots:

  void windowActivated( QWidget *wgtWindow );

  void fileNew   ( void );
  void fileOpen  ( void );
  void fileSave  ( void );
  void fileSaveAs( void );
  void fileClose ( void );
  void fileExit  ( void );

  void changeFrequency( int iFrequency );

  void showFrame( int iFrame );
  void playFrame( void );

  void videoBackward( void );
  void videoPlay    ( void );
  void videoForward ( void );
  void videoStop    ( void );
  void videoLoop    ( bool bState );
  void videoLock    ( bool bState );
  void videoCenter  ( void );

  void viewMenuBar   ( bool bState );
  void viewTBarFile  ( bool bState );
  void viewTBarVideo ( bool bState );
  void viewStatusBar ( bool bState );
  void viewFullScreen( bool bState );

  void menuWindowActivated( int iMenuID );
  void menuWindowAboutToShow( void );

  void windCascade( void );
  void windTileVer( void );
  void windTileHor( void );

  void helpContents( void );
  void helpAboutApp( void );
  void helpAboutQt ( void );


  protected:

  QWorkspace * workspace( void ) const { return wksCentral; };

  void languageChange( void );

  void closeEvent( QCloseEvent *evClose );

  void computeFrameRate( int iNumFrames, int iMillisecs );

  CLPlayerDoc * newDoc( void );


  public:

  void helpCmdLine( void );

  void parseCmdLine( int iArgC, char *a_szArgV[] );

  CLPlayerWin( QWidget *wgtParent = NULL, const char *szName = NULL,
               WFlags fl = WType_TopLevel );

  virtual ~CLPlayerWin( void );
}; // End of class CLPlayerWin.

#endif // CLPLAYERWIN_H

