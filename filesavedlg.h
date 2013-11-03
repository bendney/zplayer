//******************************************************************************
//
// filesavedlg.h
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

#ifndef FILESAVEDLG_H
#define FILESAVEDLG_H

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
class QFrame;
class QGroupBox;

class QLabel;
class QLineEdit;

class QVBoxLayout;


//*******************************************************************************
// CLASS CLFileSaveDlg
//*******************************************************************************

class CLFileSaveDlg : public QFileDialog
{
	Q_OBJECT

	private:

		QGroupBox *gbxSave;
		QCheckBox *ckbAddHeader;

		QFrame    *linA;

		QCheckBox *ckbSelFrames;

		QGroupBox *gbxSelFrames;
		QLabel    *lblFrameFrom;
		QLineEdit *ledFrameFrom;

		QLabel    *lblFrameTo;
		QLineEdit *ledFrameTo;

		QLabel    *lblFrameStep;
		QLineEdit *ledFrameStep;

		QVBoxLayout *vblGbxSelFrames;
		QVBoxLayout *vblGbxSave;


	private:

		QGroupBox * saveInfo( QWidget *wgtParent );


	protected slots:

			virtual void languageChange( void );


	public:

		bool addHeader( void ) const;
		bool selectedFrames( void ) const;

		int frameFrom( void ) const;
		int frameTo  ( void ) const;
		int frameStep( void ) const;

		void init( bool bAddHeader = false, bool bSelFrames = false,
				int iFrameFrom = 1, int iFrameTo = 0, int iFrameStep = 1 );

		// Constructor(s) and destructor.

		CLFileSaveDlg( QWidget *wgtParent = NULL,
				const char *szName = NULL, bool bModal = false );

		virtual ~CLFileSaveDlg( void );
}; // End of class CLFileSaveDlg.

#endif // FILESAVEDLG_H

