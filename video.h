//******************************************************************************
//
// video.h
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

#ifndef VIDEO_H
#define VIDEO_H

//******************************************************************************
// HEADERS
//******************************************************************************

// Qt headers.

#include <qfile.h>
#include <qimage.h>

#include <qpainter.h>
#include <qpixmap.h>

#include <qwidget.h>


//******************************************************************************
// PROCEDURE yuvToRGB
//******************************************************************************

inline void yuvToRGB( int iY, int iU, int iV, int &iR, int &iG, int &iB )
{
	iR = iY + 1402*iV/1000;
	iG = iY - ( 101004*iU + 209599*iV )/293500;
	iB = iY + 1772*iU/1000;

	if ( iR < 0 ) iR = 0;
	if ( iG < 0 ) iG = 0;
	if ( iB < 0 ) iB = 0;

	if ( iR > 255 ) iR = 255;
	if ( iG > 255 ) iG = 255;
	if ( iB > 255 ) iB = 255;
} // End of yuvToRGB.


//******************************************************************************
// CLASS CLVideo
//******************************************************************************

class CLVideo : public QWidget // cl_vid
{
	Q_OBJECT

	private:

		bool bAllFramesInMemory;

		// Frame buffer.
		uchar *uchBuffer;

		// Size of frame buffer.
		int iBufferSize;

		// The current frame to be displayed.
		int iCurrFrame;
		int iNumberOfFrames;

		int iVideoSizeX;
		int iVideoSizeY;

		int iColorSpace;

		double dFrequency;

		QFile flIn;

		QImage imgFrame;

		QPixmap *pxmFrame;


	private:

		void loadFrame( int iFrame );
		void loadAllFrames( void );

		void showCurrentFrame( void );


	protected:

		virtual void paintEvent( QPaintEvent *evPaint );
		virtual void mouseMoveEvent( QMouseEvent *evMouse );
		virtual void leaveEvent( QEvent *evLeave );


	public:

		enum ENColorSpace
		{
			YUV400 = 0,
			YUV420 = 1,
			YUV422 = 2,
			YUV444 = 3
		};

		uchar * buffer( void ) const;

		const QPixmap & frame( void ) const;

		int numberOfFrames( void ) const;

		int currentFrame( void ) const;
		void setCurrentFrame( int iFrame );

		void showFirstFrame( void );
		void showLastFrame ( void );

		void showPrevFrame( void );
		void showNextFrame( void );

		bool load( const QString &strName,
				int iVidSizeX, int iVidSizeY, int iColSpace,
				bool bAllFrames = false );

		bool save( const QString &strName,
				bool bAddHeader, bool bSelFrames,
				int iFrameFrom, int iFrameTo, int iFrameStep );

		// Constructor(s) and destructor.

		CLVideo( QWidget *wgtParent = NULL,
				const char *szName = NULL, WFlags wf = 0 );

		virtual ~CLVideo( void );


	signals:

		void message( const QString &strText );
}; // End of class CLVideo


//******************************************************************************
// PROCEDURE showCurrentFrame
//******************************************************************************

inline void CLVideo::showCurrentFrame( void )
{
	if ( bAllFramesInMemory )
	{
		bitBlt( this, 0, 0, &pxmFrame[iCurrFrame - 1] );
		return;
	}

	if ( flIn.isOpen( ) )
		loadFrame( iCurrFrame );

	bitBlt( this, 0, 0, &pxmFrame[0] );
} // End of showCurrentFrame.


//******************************************************************************
// PROCEDURE showFirstFrame
//******************************************************************************

inline void CLVideo::showFirstFrame( void )
{
	if ( iNumberOfFrames < 1 )
		return;

	iCurrFrame = 1;
	showCurrentFrame( );
} // End of showFirstFrame.


//******************************************************************************
// PROCEDURE showLastFrame
//******************************************************************************

inline void CLVideo::showLastFrame( void )
{
	if ( iNumberOfFrames < 1 )
		return;

	iCurrFrame = iNumberOfFrames;
	showCurrentFrame( );
} // End of showLastFrame.


//******************************************************************************
// PROCEDURE showPrevFrame
//******************************************************************************

inline void CLVideo::showPrevFrame( void )
{
	if ( iCurrFrame <= 1 )
		return;

	--iCurrFrame;
	showCurrentFrame( );
} // End of showPrevFrame.


//******************************************************************************
// PROCEDURE showNextFrame
//******************************************************************************

inline void CLVideo::showNextFrame( void )
{
	if ( iCurrFrame >= iNumberOfFrames )
		return;

	++iCurrFrame;
	showCurrentFrame( );
} // End of showNextFrame.


//******************************************************************************
// PROCEDURE currentFrame
//******************************************************************************

inline int CLVideo::currentFrame( void ) const
{
	return iCurrFrame;
} // End of currentFrame.


//******************************************************************************
// PROCEDURE setCurrentFrame
//******************************************************************************

inline void CLVideo::setCurrentFrame( int iFrame )
{
	if ( iFrame < 1 ||
			iFrame > iNumberOfFrames )
		return;

	iCurrFrame = iFrame;
	showCurrentFrame( );
} // End of setCurrentFrame.

#endif // VIDEO_H

