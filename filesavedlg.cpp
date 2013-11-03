//*****************************************************************************
//
// filesavedlg.cpp
//
//*****************************************************************************
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

// Qt headers.

#include <qcheckbox.h>
#include <qframe.h>
#include <qgroupbox.h>

#include <qlabel.h>
#include <qlayout.h>
#include <qlineedit.h>

#include <qvalidator.h>
#include <qvariant.h>

// App headers.

#include "filesavedlg.h"


//******************************************************************************
// STATIC VARS (PRIVATE)
//******************************************************************************

static bool bHeader = false;
static bool bSelect = false;

static int iFrmFrom = 1;
static int iFrmTo   = 0;
static int iFrmStep = 1;


//******************************************************************************
// PROCEDURE languageChange
//******************************************************************************
//
// Sets the strings of the subwidgets using the current language.
//
//******************************************************************************

void CLFileSaveDlg::languageChange( void )
{
	gbxSave->setTitle( QString::null );
	ckbAddHeader->setText( tr( "Add Header" ) );
	ckbSelFrames->setText( tr( "Select Frames" ) );

	gbxSelFrames->setTitle( QString::null );
	lblFrameFrom->setText( tr( "From" ) );
	lblFrameTo  ->setText( tr( "To" ) );
	lblFrameStep->setText( tr( "Step" ) );
} // End of languageChange.


//******************************************************************************
// PROCEDURE saveInfo
//******************************************************************************

QGroupBox * CLFileSaveDlg::saveInfo( QWidget *wgtParent )
{
	gbxSave = new QGroupBox( wgtParent, "GBX Save" );
	gbxSave->setColumnLayout( 0, Qt::Vertical );
	gbxSave->layout( )->setSpacing( 6 );
	gbxSave->layout ()->setMargin( 11 );

	ckbAddHeader = new QCheckBox( gbxSave, "CKB AddHeader" );

	linA = new QFrame( gbxSave, "linA" );
	linA->setSizePolicy( QSizePolicy(
				( QSizePolicy::SizeType )1,
				( QSizePolicy::SizeType )3, 0, 0,
				linA->sizePolicy( ).hasHeightForWidth( )
				) );
	linA->setFrameShape( QFrame::HLine );
	linA->setFrameShadow( QFrame::Sunken );

	ckbSelFrames = new QCheckBox( gbxSave, "CKB SelFrames" );

	gbxSelFrames = new QGroupBox( gbxSave, "GBX SelFrames" );
	gbxSelFrames->setFrameShape( QGroupBox::NoFrame );
	gbxSelFrames->setColumnLayout( 0, Qt::Vertical );
	gbxSelFrames->layout( )->setSpacing( 6 );
	gbxSelFrames->layout( )->setMargin( 0 );

	lblFrameFrom = new QLabel( gbxSelFrames, "LBL FrameFrom" );
	ledFrameFrom = new QLineEdit( gbxSelFrames, "LED FrameFrom" );
	ledFrameFrom->setValidator( new QIntValidator(
				1, 2147483647, ledFrameFrom, "IVA FrameFrom"
				) );

	lblFrameTo = new QLabel( gbxSelFrames, "LBL FrameTo" );
	ledFrameTo = new QLineEdit( gbxSelFrames, "LED FrameTo" );
	ledFrameTo->setValidator( new QIntValidator(
				0, 2147483647, ledFrameTo, "IVA FrameTo"
				) );

	lblFrameStep = new QLabel( gbxSelFrames, "LBL FrameStep" );
	ledFrameStep = new QLineEdit( gbxSelFrames, "LED FrameStep" );
	ledFrameStep->setValidator( new QIntValidator(
				1, 100, ledFrameStep, "IVA FrameStep"
				) );

	gbxSelFrames->setEnabled( false );

	// Group Layout.

	vblGbxSelFrames = new QVBoxLayout( gbxSelFrames->layout( ) );
	vblGbxSelFrames->setAlignment( Qt::AlignTop );
	vblGbxSelFrames->addWidget( lblFrameFrom );
	vblGbxSelFrames->addWidget( ledFrameFrom );
	vblGbxSelFrames->addWidget( lblFrameTo );
	vblGbxSelFrames->addWidget( ledFrameTo );
	vblGbxSelFrames->addWidget( lblFrameStep );
	vblGbxSelFrames->addWidget( ledFrameStep );

	vblGbxSave = new QVBoxLayout( gbxSave->layout( ) );
	vblGbxSave->setAlignment( Qt::AlignTop );
	vblGbxSave->addWidget( ckbAddHeader );
	vblGbxSave->addWidget( linA );
	vblGbxSave->addWidget( ckbSelFrames );
	vblGbxSave->addWidget( gbxSelFrames );

	// Language.

	languageChange( );

	// Signals and slots connections.

	connect( ckbSelFrames, SIGNAL( toggled( bool ) ),
			gbxSelFrames, SLOT( setEnabled( bool ) ) );

	return gbxSave;
} // End of saveInfo.


//******************************************************************************
// PROCEDURE addHeader
//******************************************************************************

bool CLFileSaveDlg::addHeader( void ) const
{
	return ckbAddHeader->isChecked( );
} // End of addHeader.


//******************************************************************************
// PROCEDURE selectedFrames
//******************************************************************************

bool CLFileSaveDlg::selectedFrames( void ) const
{
	return ckbSelFrames->isChecked( );
} // End of selectedFrames.


//******************************************************************************
// PROCEDURE frameFrom
//******************************************************************************

int CLFileSaveDlg::frameFrom( void ) const
{
	return ledFrameFrom->text( ).toInt( );
} // End of frameFrom.


//******************************************************************************
// PROCEDURE frameTo
//******************************************************************************

int CLFileSaveDlg::frameTo( void ) const
{
	return ledFrameTo->text( ).toInt( );
} // End of frameTo.


//******************************************************************************
// PROCEDURE frameStep
//******************************************************************************

int CLFileSaveDlg::frameStep( void ) const
{
	return ledFrameStep->text( ).toInt( );
} // End of frameStep.


//******************************************************************************
// PROCEDURE init
//******************************************************************************

void CLFileSaveDlg::init( bool bAddHeader, bool bSelFrames,
		int iFrameFrom, int iFrameTo, int iFrameStep )
{
	ckbAddHeader->setChecked( bAddHeader );
	ckbSelFrames->setChecked( bSelFrames );

	ledFrameFrom->setText( QString::number( iFrameFrom ) );
	ledFrameTo  ->setText( QString::number( iFrameTo   ) );
	ledFrameStep->setText( QString::number( iFrameStep ) );
} // End of init.


//******************************************************************************
// PROCEDURE CLFileSaveDlg (Constructor)
//******************************************************************************

CLFileSaveDlg::CLFileSaveDlg( QWidget *wgtParent,
		const char *szName, bool bModal )
:QFileDialog( wgtParent, szName, bModal )
{
	addRightWidget( saveInfo( this ) );

	init( bHeader, bSelect, iFrmFrom, iFrmTo, iFrmStep );
} // End of CLFileSaveDlg (Constructor).


//******************************************************************************
// PROCEDURE ~CLFileSaveDlg (Destructor)
//******************************************************************************

CLFileSaveDlg::~CLFileSaveDlg( void )
{
	// Save state.
	bHeader = addHeader( );
	bSelect = selectedFrames( );

	iFrmFrom = frameFrom( );
	iFrmTo   = frameTo  ( );
	iFrmStep = frameStep( );
} // End of ~CLFileSaveDlg (Destructor).

