//******************************************************************************
//
// fileopendlg.h
//
//******************************************************************************
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

#ifndef FILEOPENDLG_H
#define FILEOPENDLG_H

//*******************************************************************************
// HEADERS
//*******************************************************************************

// Qt headers.

#include <qfiledialog.h>


//*******************************************************************************
// FORWARD DECLARATIONS
//*******************************************************************************

// Qt classes.

class QCheckBox;
class QComboBox;

class QFrame;

class QGridLayout;
class QGroupBox;

class QHBoxLayout;
class QLabel;
class QSpinBox;
class QVBoxLayout;


//*******************************************************************************
// CLASS CLFileOpenDlg
//*******************************************************************************

class CLFileOpenDlg : public QFileDialog
{
  Q_OBJECT

  private:

  QGroupBox *gbxOpen;

  QCheckBox *ckbAllFramesInMem;

  QFrame    *linA;

  QLabel    *lblVideoSize;
  QComboBox *cbxVideoSize;
  QGroupBox *gbxVideoSize;

  QLabel    *lblVideoSizeX;
  QLabel    *lblVideoSizeY;
  QSpinBox  *sbxVideoSizeX;
  QSpinBox  *sbxVideoSizeY;

  QFrame    *linB;

  QLabel    *lblColorSpace;
  QComboBox *cbxColorSpace;

  QGridLayout *gdlA;
  QHBoxLayout *hblGbxVideoSize;
  QVBoxLayout *vblGbxOpen;

  QSize szVideo[32];


  private:

  QGroupBox * openInfo( QWidget *wgtParent );


  protected:

  int videoSizeToItem( int iVideoSizeX, int iVideoSizeY );


  protected slots:

  void fileToVideoSize( const QString &strFile );

  void itemToVideoSize( int iItem );

  void changeCustomSizeX( int iSizeX );
  void changeCustomSizeY( int iSizeY );

  virtual void languageChange( void );


  public:

  bool allFramesInMemory( void ) const;

  int videoSizeX( void ) const;
  int videoSizeY( void ) const;

  int colorSpace( void ) const;

  void init( bool bAllFramesInMem = false,
             int iVideoSizeX = 176, int iVideoSizeY = 144,
             int iColorSpace = 1 );

  // Constructor(s) and destructor.

  CLFileOpenDlg( QWidget *wgtParent = NULL,
                 const char *szName = NULL, bool bModal = false );

  virtual ~CLFileOpenDlg( void );
}; // End of class CLFileOpenDlg.

#endif // FILEOPENDLG_H

