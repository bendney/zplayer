//*****************************************************************************
//
// fileopendlg.cpp
//
//*****************************************************************************
//
// Author..: José Fernando Leite de Oliveira
//
// Begin...: Wed May 04 2005
// Modified: Tue May 24 2005
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
//
// Based on yuvPlayer:
//
// Copyright (C) 2005 by Yuri Vatis
// vatis@tnt.uni-hannover.de
//
// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the
// Free Software Foundation, Inc.,
// 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
//
//*******************************************************************************


//******************************************************************************
// HEADERS
//******************************************************************************

// Qt headers.

#include <qpushbutton.h>
#include <qgroupbox.h>

#include <qlabel.h>
#include <qlayout.h>

#include <qcombobox.h>
#include <qframe.h>
#include <qspinbox.h>
#include <qcheckbox.h>

#include <qtooltip.h>
#include <qvariant.h>
#include <qwhatsthis.h>

// App headers.

#include "fileopendlg.h"


static bool bAllFrames = false;

static int iVidSizeX = 176;
static int iVidSizeY = 144;
static int iColSpace = 1; // QCIF


//******************************************************************************
// PROCEDURE languageChange
//******************************************************************************
//
// Sets the strings of the subwidgets using the current language.
//
//******************************************************************************

void CLFileOpenDlg::languageChange( void )
{
  gbxOpen->setTitle( QString::null );

  ckbAllFramesInMem->setText( tr( "All Frames in Memory" ) );

  lblVideoSize->setText( tr( "Video Size" ) );
  cbxVideoSize->clear( );
  cbxVideoSize->insertItem( tr( "128 x 96 - SQCIF" ) );
  cbxVideoSize->insertItem( tr( "176 x 144 - QCIF" ) );
  cbxVideoSize->insertItem( tr( "320 x 240 - QVGA" ) );
  cbxVideoSize->insertItem( tr( "352 x 240 - SIF 525" ) );
  cbxVideoSize->insertItem( tr( "352 x 288 - CIF" ) );
  cbxVideoSize->insertItem( tr( "352 x 480 - HHR 525" ) );
  cbxVideoSize->insertItem( tr( "352 x 576 - HHR 625" ) );
  cbxVideoSize->insertItem( tr( "640 x 480 - VGA" ) );
  cbxVideoSize->insertItem( tr( "704 x 480 - 4SIF 525" ) );
  cbxVideoSize->insertItem( tr( "720 x 480 - SD 525" ) );
  cbxVideoSize->insertItem( tr( "704 x 576 - 4CIF" ) );
  cbxVideoSize->insertItem( tr( "720 x 576 - SD 625" ) );
  cbxVideoSize->insertItem( tr( "800 x 600 - SVGA" ) );
  cbxVideoSize->insertItem( tr( "1024 x 768 - XGA" ) );
  cbxVideoSize->insertItem( tr( "1280 x 720 - HD 720p" ) );
  cbxVideoSize->insertItem( tr( "1280 x 960 - 4VGA" ) );
  cbxVideoSize->insertItem( tr( "1280 x 1024 - SXGA" ) );
  cbxVideoSize->insertItem( tr( "1408 x 960 - 16CIF 525" ) );
  cbxVideoSize->insertItem( tr( "1408 x 1152 - 16CIF" ) );
  cbxVideoSize->insertItem( tr( "1600 x 1200 - 4SVGA" ) );
  cbxVideoSize->insertItem( tr( "1920 x 1080 - HD 1080" ) );
  cbxVideoSize->insertItem( tr( "2048 x 1024 - 2k x 1k" ) );
  cbxVideoSize->insertItem( tr( "2048 x 1536 - 4XGA" ) );
  cbxVideoSize->insertItem( tr( "2560 x 1920 - 16VGA" ) );
  cbxVideoSize->insertItem( tr( "3616 x 1536 - 2.35:1" ) );
  cbxVideoSize->insertItem( tr( "3672 x 1536 - 2.39:1" ) );
  cbxVideoSize->insertItem( tr( "4096 x 2048 - 4k x 2k" ) );
  cbxVideoSize->insertItem( tr( "4096 x 2304 - 16:9" ) );
  cbxVideoSize->insertItem( tr(
    "%1 x %2 - Custom"
  ).arg( szVideo[28].width( ) )
   .arg( szVideo[28].height( ) ) );

  gbxVideoSize->setTitle( QString::null );

  lblVideoSizeX->setText( tr( "Width" ) );
  lblVideoSizeY->setText( tr( "Height" ) );

  lblColorSpace->setText( tr( "Color Space" ) );
  cbxColorSpace->clear( );
  cbxColorSpace->insertItem( tr( "YUV 4:0:0" ) );
  cbxColorSpace->insertItem( tr( "YUV 4:2:0" ) );
  cbxColorSpace->insertItem( tr( "YUV 4:2:2" ) );
  cbxColorSpace->insertItem( tr( "YUV 4:4:4" ) );
  cbxColorSpace->insertItem( tr( "RGB" ) );
} // End of languageChange.


//******************************************************************************
// PROCEDURE openInfo
//******************************************************************************

QGroupBox * CLFileOpenDlg::openInfo( QWidget *wgtParent )
{
  gbxOpen = new QGroupBox( wgtParent, "GBX Open" );
  gbxOpen->setColumnLayout( 0, Qt::Vertical );
  gbxOpen->layout( )->setSpacing( 6 );
  gbxOpen->layout( )->setMargin( 11 );

  ckbAllFramesInMem = new QCheckBox( gbxOpen, "CKB AllFramesInMem" );

  linA = new QFrame( gbxOpen, "LIN A" );
  linA->setSizePolicy( QSizePolicy(
    ( QSizePolicy::SizeType )1,
    ( QSizePolicy::SizeType )3, 0, 0,
    linA->sizePolicy( ).hasHeightForWidth( ) ) );
  linA->setFrameShape( QFrame::HLine );
  linA->setFrameShadow( QFrame::Sunken );

  lblVideoSize = new QLabel( gbxOpen, "LBL Size" );
  cbxVideoSize = new QComboBox( false, gbxOpen, "CBX VideoSize" );

  gbxVideoSize = new QGroupBox( gbxOpen, "GBX VideoSize" );
  gbxVideoSize->setFrameShape( QGroupBox::NoFrame );
  gbxVideoSize->setColumnLayout( 0, Qt::Vertical );
  gbxVideoSize->layout( )->setSpacing( 6 );
  gbxVideoSize->layout( )->setMargin( 0 );

  lblVideoSizeX = new QLabel( gbxVideoSize, "LBL VideoSizeX" );
  sbxVideoSizeX = new QSpinBox( gbxVideoSize, "SBX VideoSizeX" );
  sbxVideoSizeX->setMaxValue( 8192 );
  sbxVideoSizeX->setMinValue( 16 );
  sbxVideoSizeX->setLineStep( 16 );

  lblVideoSizeY = new QLabel( gbxVideoSize, "LBL VideoSizeY" );
  sbxVideoSizeY = new QSpinBox( gbxVideoSize, "SBX VideoSizeY" );
  sbxVideoSizeY->setMaxValue( 8192 );
  sbxVideoSizeY->setMinValue( 16 );
  sbxVideoSizeY->setLineStep( 16 );

  linB = new QFrame( gbxOpen, "LIN B" );
  linB->setSizePolicy( QSizePolicy(
    ( QSizePolicy::SizeType )1,
    ( QSizePolicy::SizeType )3, 0, 0,
    linB->sizePolicy( ).hasHeightForWidth( ) ) );
  linB->setFrameShape( QFrame::HLine );
  linB->setFrameShadow( QFrame::Sunken );

  lblColorSpace = new QLabel( gbxOpen, "LBL ColorSpace" );
  cbxColorSpace = new QComboBox( false, gbxOpen, "CBX ColorSpace" );

  // Group layout.

  gdlA = new QGridLayout( 0, 1, 1, 0, 6, "GDL A");
  gdlA->addWidget( lblVideoSizeX, 0, 0 );
  gdlA->addWidget( lblVideoSizeY, 0, 1 );
  gdlA->addWidget( sbxVideoSizeX, 1, 0 );
  gdlA->addWidget( sbxVideoSizeY, 1, 1 );

  hblGbxVideoSize = new QHBoxLayout( gbxVideoSize->layout( ) );
  hblGbxVideoSize->setAlignment( Qt::AlignTop );
  hblGbxVideoSize->addLayout( gdlA );

  vblGbxOpen = new QVBoxLayout( gbxOpen->layout( ) );
  vblGbxOpen->setAlignment( Qt::AlignTop );
  vblGbxOpen->addWidget( ckbAllFramesInMem );
  vblGbxOpen->addWidget( linA );
  vblGbxOpen->addWidget( lblVideoSize );
  vblGbxOpen->addWidget( cbxVideoSize );
  vblGbxOpen->addWidget( gbxVideoSize );
  vblGbxOpen->addWidget( linB );
  vblGbxOpen->addWidget( lblColorSpace );
  vblGbxOpen->addWidget( cbxColorSpace );

  // Language.

  languageChange( );

  // Signals and slots connections.

  connect( cbxVideoSize, SIGNAL( activated( int ) ),
           this, SLOT( itemToVideoSize( int ) ) );

  connect( sbxVideoSizeX, SIGNAL( valueChanged( int ) ),
           this, SLOT( changeCustomSizeX( int ) ) );
  connect( sbxVideoSizeY, SIGNAL( valueChanged( int ) ),
           this, SLOT( changeCustomSizeY( int ) ) );

  connect( this, SIGNAL( fileHighlighted( const QString & ) ),
           this, SLOT( fileToVideoSize( const QString & ) ) );

  return gbxOpen;
} // End of openInfo.


//******************************************************************************
// PROCEDURE fileToVideoSize
//******************************************************************************

void CLFileOpenDlg::fileToVideoSize( const QString &strFile )
{
  const char *szName[] = {
    "SQCIF" , "QCIF"   , "QVGA" , "SIF525"  , "CIF"   , "HHR525", "HHR625",
    "VGA"   , "4SIF525", "SD525", "4CIF"    , "SD625" , "SVGA"  , "XGA"   ,
    "HD720P", "4VGA"   , "SXGA" , "16CIF525", "16CIF" , "4SVGA" , "HD1080",
    "2Kx1K" , "4XGA"   , "16VGA", "2.35:1"  , "2.39:1", "4Kx2K" , "16:9"
  };

  int iIndex = -1;


  for ( int i = 0; i < 28; ++i )
  {
    if ( 0 != strFile.contains( szName[i], false ) )
    {
      iIndex = i;
      break;
    }
  }

  if ( -1 == iIndex )
    return;

  cbxVideoSize->setCurrentItem( iIndex );
  itemToVideoSize( iIndex );
} // End of fileToVideoSize.


//******************************************************************************
// PROCEDURE itemToVideoSize
//******************************************************************************

void CLFileOpenDlg::itemToVideoSize( int iItem )
{
  gbxVideoSize->setEnabled( bool( 28 == iItem ) );

  sbxVideoSizeX->setValue( szVideo[iItem].width( ) );
  sbxVideoSizeY->setValue( szVideo[iItem].height( ) );
} // End of itemToVideoSize.


//******************************************************************************
// PROCEDURE changeCustomSizeX
//******************************************************************************

void CLFileOpenDlg::changeCustomSizeX( int iSizeX )
{
  if ( 28 != cbxVideoSize->currentItem( ) )
    return;

  if ( iSizeX == szVideo[28].width( ) )
    return;

  szVideo[28].setWidth( iSizeX );

  cbxVideoSize->setCurrentText( tr(
    "%1 x %2 - Custom"
  ).arg( szVideo[28].width( ) )
   .arg( szVideo[28].height( ) ) );
} // End of changeCustomSizeX.


//******************************************************************************
// PROCEDURE changeCustomSizeY
//******************************************************************************

void CLFileOpenDlg::changeCustomSizeY( int iSizeY )
{
  if ( 28 != cbxVideoSize->currentItem( ) )
    return;

  if ( iSizeY == szVideo[28].height( ) )
    return;

  szVideo[28].setHeight( iSizeY );

  cbxVideoSize->setCurrentText( tr(
    "%1 x %2 - Custom"
  ).arg( szVideo[28].width( ) )
   .arg( szVideo[28].height( ) ) );
} // End of changeCustomSizeY.


//******************************************************************************
// PROCEDURE videoSizeToItem
//******************************************************************************

int CLFileOpenDlg::videoSizeToItem( int iVideoSizeX, int iVideoSizeY )
{
  int iItem = 28;

  QSize szItem( iVideoSizeX, iVideoSizeY );


  for ( int i = 0; i < 29; ++i )
  {
    if ( szItem == szVideo[i] )
    {
      iItem = i;
      break;
    }
  }

  return iItem;
} // End of videoSizeToItem.


//******************************************************************************
// PROCEDURE allFramesInMemory
//******************************************************************************

bool CLFileOpenDlg::allFramesInMemory( void ) const
{
  return ckbAllFramesInMem->isChecked( );
} // End of allFramesInMemory.


//******************************************************************************
// PROCEDURE videoSizeX
//******************************************************************************

int CLFileOpenDlg::videoSizeX( void ) const
{
  return sbxVideoSizeX->value( );
} // End of videoSizeX.


//******************************************************************************
// PROCEDURE videoSizeY
//******************************************************************************

int CLFileOpenDlg::videoSizeY( void ) const
{
  return sbxVideoSizeY->value( );
} // End of videoSizeY.


//******************************************************************************
// PROCEDURE colorSpace
//******************************************************************************

int CLFileOpenDlg::colorSpace( void ) const
{
  return cbxColorSpace->currentItem( );
} // End of colorSpace.


//******************************************************************************
// PROCEDURE init
//******************************************************************************

void CLFileOpenDlg::init( bool bAllFramesInMem,
                          int iVideoSizeX, int iVideoSizeY, int iColorSpace )
{
  ckbAllFramesInMem->setChecked( bAllFramesInMem );

  cbxVideoSize->setCurrentItem( videoSizeToItem( iVideoSizeX, iVideoSizeY ) );

  itemToVideoSize( cbxVideoSize->currentItem( ) );

  cbxColorSpace->setCurrentItem( iColorSpace );
} // End of init.


//******************************************************************************
// PROCEDURE CLFileOpenDlg (Constructor)
//******************************************************************************

CLFileOpenDlg::CLFileOpenDlg( QWidget *wgtParent,
                              const char *szName, bool bModal )
              :QFileDialog( wgtParent, szName, bModal )
{
  szVideo[ 0] = QSize(  128,   96 ); // SQCIF
  szVideo[ 1] = QSize(  176,  144 ); // QCIF
  szVideo[ 2] = QSize(  320,  240 ); // QVGA
  szVideo[ 3] = QSize(  352,  240 ); // 525 SIF
  szVideo[ 4] = QSize(  352,  288 ); // CIF
  szVideo[ 5] = QSize(  352,  480 ); // 525 HHR
  szVideo[ 6] = QSize(  352,  576 ); // 625 HHR
  szVideo[ 7] = QSize(  640,  480 ); // VGA
  szVideo[ 8] = QSize(  704,  480 ); // 525 4SIF
  szVideo[ 9] = QSize(  720,  480 ); // 525 SD
  szVideo[10] = QSize(  704,  576 ); // 4CIF
  szVideo[11] = QSize(  720,  576 ); // 625 SD
  szVideo[12] = QSize(  800,  600 ); // SVGA
  szVideo[13] = QSize( 1024,  768 ); // XGA
  szVideo[14] = QSize( 1280,  720 ); // 720p HD
  szVideo[15] = QSize( 1280,  960 ); // 4VGA
  szVideo[16] = QSize( 1280, 1024 ); // SXGA
  szVideo[17] = QSize( 1408,  960 ); // 525 16CIF
  szVideo[18] = QSize( 1408, 1152 ); // 16CIF
  szVideo[19] = QSize( 1600, 1200 ); // 4SVGA
  szVideo[20] = QSize( 1920, 1080 ); // 1080 HD
  szVideo[21] = QSize( 2048, 1024 ); // 2kx1k
  szVideo[22] = QSize( 2048, 1536 ); // 4XGA
  szVideo[23] = QSize( 2560, 1920 ); // 16VGA
  szVideo[24] = QSize( 3616, 1536 ); // 2.35:1
  szVideo[25] = QSize( 3672, 1536 ); // 2.39:1
  szVideo[26] = QSize( 4096, 2048 ); // 4kx2k
  szVideo[27] = QSize( 4096, 2304 ); // 16:9
  szVideo[28] = QSize( iVidSizeX, iVidSizeY ); // Custom.

  addRightWidget( openInfo( this ) );

  init( bAllFrames, iVidSizeX, iVidSizeY, iColSpace );
} // End of CLFileOpenDlg (Constructor).


//******************************************************************************
// PROCEDURE ~CLFileOpenDlg (Destructor)
//******************************************************************************

CLFileOpenDlg::~CLFileOpenDlg( void )
{
  // Save state.
  bAllFrames = allFramesInMemory( );

  iVidSizeX = videoSizeX( );
  iVidSizeY = videoSizeY( );
  iColSpace = colorSpace( );
} // End of ~CLFileOpenDlg (Destructor).

