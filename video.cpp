//******************************************************************************
//
// video.cpp
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


//******************************************************************************
// HEADERS
//******************************************************************************

// Std headers.
#include <string.h>

// Qt headers.
#include <qcolor.h>
#include <qevent.h>
#include <qmainwindow.h>

// App headers.

#include "video.h"


//******************************************************************************
// PROCEDURE loadFrame
//******************************************************************************

void CLVideo::loadFrame( int iFrame )
{
	uchar *uchSigY;
	uchar *uchSigU;
	uchar *uchSigV;

	uchar *uchRGB;

	int x, y;

	int iY, iU, iV;
	int iR, iG, iB;

	int iOffU, iOffV;


	flIn.at( ( iFrame - 1 )*iBufferSize );
	flIn.readBlock( ( char * )uchBuffer, iBufferSize );

	// Set the rgb-pointer to the QImage to be shown.
	uchRGB = imgFrame.bits( );

	uchSigY = uchBuffer;

	switch ( iColorSpace )
	{
		case YUV400:
			for ( y = 0; y < iVideoSizeY; ++y )
				for ( x = 0; x < iVideoSizeX; ++x )
				{
					iY = *uchSigY++;

					*uchRGB++ = iY;
					*uchRGB++ = iY;
					*uchRGB++ = iY;
					*uchRGB++ = 255; // aplha
				}
			break;

		case YUV420:
			iOffU = iVideoSizeX*iVideoSizeY;
			iOffV = iOffU + iOffU/4;

			uchSigU = uchBuffer + iOffU;
			uchSigV = uchBuffer + iOffV;

			for ( y = 0; y < iVideoSizeY; y += 2 )
			{
				for ( x = 0; x < iVideoSizeX; x += 2 )
				{
					iY = uchSigY[0];
					iU = *uchSigU++ - 128;
					iV = *uchSigV++ - 128;

					yuvToRGB( iY, iU, iV, iR, iG, iB );

					*uchRGB++ = iB;
					*uchRGB++ = iG;
					*uchRGB++ = iR;
					*uchRGB++ = 255; // aplha

					iY = uchSigY[1];

					yuvToRGB( iY, iU, iV, iR, iG, iB );

					*uchRGB++ = iB;
					*uchRGB++ = iG;
					*uchRGB++ = iR;
					*uchRGB++ = 255; // aplha

					uchRGB += 4*( iVideoSizeX - 2 );

					iY = uchSigY[iVideoSizeX];

					yuvToRGB( iY, iU, iV, iR, iG, iB );

					*uchRGB++ = iB;
					*uchRGB++ = iG;
					*uchRGB++ = iR;
					*uchRGB++ = 255; // aplha

					iY = uchSigY[iVideoSizeX + 1];

					yuvToRGB( iY, iU, iV, iR, iG, iB );

					*uchRGB++ = iB;
					*uchRGB++ = iG;
					*uchRGB++ = iR;
					*uchRGB++ = 255; // aplha

					uchRGB -= 4*iVideoSizeX;
					uchSigY += 2;
				}

				uchSigY += iVideoSizeX;
				uchRGB += 4*iVideoSizeX;
			}
			break;

		case YUV422:
			iOffU = iVideoSizeX*iVideoSizeY;
			iOffV = iOffU + iOffU/2;

			uchSigU = uchBuffer + iOffU;
			uchSigV = uchBuffer + iOffV;

			for ( y = 0; y < iVideoSizeY; ++y )
				for ( x = 0; x < iVideoSizeX; x += 2 )
				{
					iY = *uchSigY++;
					iU = *uchSigU++ - 128;
					iV = *uchSigV++ - 128;

					yuvToRGB( iY, iU, iV, iR, iG, iB );

					*uchRGB++ = iB;
					*uchRGB++ = iG;
					*uchRGB++ = iR;
					*uchRGB++ = 255; // aplha

					iY = *uchSigY++;

					yuvToRGB( iY, iU, iV, iR, iG, iB );

					*uchRGB++ = iB;
					*uchRGB++ = iG;
					*uchRGB++ = iR;
					*uchRGB++ = 255; // aplha
				}
			break;

		case YUV444:
			iOffU = iVideoSizeX*iVideoSizeY;
			iOffV = 2*iOffU;

			uchSigU = uchBuffer + iOffU;
			uchSigV = uchBuffer + iOffV;

			for ( y = 0; y < iVideoSizeY; ++y )
				for ( x = 0; x < iVideoSizeX; ++x )
				{
					iY = *uchSigY++;
					iU = *uchSigU++ - 128;
					iV = *uchSigV++ - 128;

					yuvToRGB( iY, iU, iV, iR, iG, iB );

					*uchRGB++ = iB;
					*uchRGB++ = iG;
					*uchRGB++ = iR;
					*uchRGB++ = 255; // aplha
				}
			break;

		default:
			return;
	}

	pxmFrame[bAllFramesInMemory ? ( iFrame - 1 ) : 0] = imgFrame;
} // End of loadFrame.


//******************************************************************************
// PROCEDURE loadAllFrames
//******************************************************************************

void CLVideo::loadAllFrames( void )
{
	for ( int iFrame = 1; iFrame <= iNumberOfFrames; ++iFrame )
		loadFrame( iFrame );
} // End of loadAllFrames.


//******************************************************************************
// PROCEDURE paintEvent
//******************************************************************************

void CLVideo::paintEvent( QPaintEvent *evPaint )
{
	( void )evPaint; // Parameter not used.
	bitBlt( this, 0, 0, &pxmFrame[bAllFramesInMemory ? ( iCurrFrame - 1 ) : 0] );
}


//******************************************************************************
// PROCEDURE mouseMoveEvent
//******************************************************************************

void CLVideo::mouseMoveEvent( QMouseEvent *evMouse )
{
	int iX = evMouse->pos( ).x( ),
		iY = evMouse->pos( ).y( );


	if ( iX < 0 || iX > iVideoSizeX - 1 || iY < 0 || iY > iVideoSizeY - 1  )
		return;

	if ( bAllFramesInMemory )
	{
		emit message( tr( "Pixel: (%1, %2)" ).arg( iX ).arg( iY ) );
		return;
	}

	QRgb rgbPixel = imgFrame.pixel( iX, iY );

	emit message( tr(
				"Pixel: (%1, %2)  RGB: (%3, %4, %5)"
				).arg( iX )
			.arg( iY )
			.arg( qRed  ( rgbPixel ) )
			.arg( qGreen( rgbPixel ) )
			.arg( qBlue ( rgbPixel ) ) );
} // End of mouseMoveEvent.


//******************************************************************************
// PROCEDURE leaveEvent
//******************************************************************************

void CLVideo::leaveEvent( QEvent *evLeave )
{
	( void )evLeave; // Not used.

	emit message( "" );
} // End of leaveEvent.


//******************************************************************************
// PROCEDURE load
//******************************************************************************

bool CLVideo::load( const QString &strName,
		int iVidSizeX, int iVidSizeY, int iColSpace,
		bool bAllFramesInMem )
{
	int iLength;


	bAllFramesInMemory = bAllFramesInMem;

	iVideoSizeX = iVidSizeX;
	iVideoSizeY = iVidSizeY;
	iColorSpace = iColSpace;

	if ( false == strName.isEmpty( ) )
	{
		if ( flIn.isOpen( ) )
			flIn.close( );

		flIn.setName( strName );
		flIn.open( IO_ReadOnly );
	}

	iLength = int( flIn.size( ) );

	switch ( iColorSpace )
	{
		case YUV400:
			iBufferSize = iVideoSizeX*iVideoSizeY;
			iNumberOfFrames = iLength/iBufferSize;
			break;

		case YUV420:
			iBufferSize = iVideoSizeX*iVideoSizeY*3/2;
			iNumberOfFrames = iLength/iBufferSize;
			break;

		case YUV422:
			iBufferSize = 2*iVideoSizeX*iVideoSizeY;
			iNumberOfFrames = iLength/iBufferSize;
			break;

		case YUV444:
			iBufferSize = 3*iVideoSizeX*iVideoSizeY;
			iNumberOfFrames = iLength/iBufferSize;
			break;

		default:
			iBufferSize = 0;
			iNumberOfFrames = 0;
			return false;
	}

	if ( iNumberOfFrames < 1 )
		return false;

	if ( uchBuffer )
		delete[] uchBuffer;

	uchBuffer = new uchar[iBufferSize];

	if ( NULL != pxmFrame )
	{
		delete[] pxmFrame;
		pxmFrame = NULL;
	}

	imgFrame.create( iVideoSizeX, iVideoSizeY, 32 );

	if ( bAllFramesInMemory )
	{
		pxmFrame = new QPixmap[iNumberOfFrames];

		if ( NULL == pxmFrame )
		{
			bAllFramesInMemory = false;

			pxmFrame = new QPixmap[1];
		}
		else
			loadAllFrames( );
	}
	else
		pxmFrame = new QPixmap[1];

	resize( iVideoSizeX, iVideoSizeY );

	showFirstFrame( );

	return true;
} // End of load.


//******************************************************************************
// PROCEDURE save
//******************************************************************************

bool CLVideo::save( const QString &strName,
		bool bAddHeader, bool bSelFrames,
		int iFrameFrom, int iFrameTo, int iFrameStep )
{
	QFile flOut( strName );


	if ( false == flIn.isOpen( ) )
		return false;

	if ( false == flOut.open( IO_WriteOnly ) )
		return false;

	if ( true == bAddHeader )
	{
		// Add a header.
	}

	if ( true == bSelFrames )
	{
		if ( 0 == iFrameFrom )
			iFrameFrom = iNumberOfFrames;

		if ( 0 == iFrameTo )
			iFrameTo = iNumberOfFrames;

		if ( iFrameFrom > iNumberOfFrames )
			iFrameFrom = iNumberOfFrames;

		if ( iFrameTo > iNumberOfFrames )
			iFrameTo = iNumberOfFrames;

		if ( iFrameFrom > iFrameTo )
		{
			for ( int iFrame = iFrameTo; iFrame >= iFrameFrom; iFrame -= iFrameStep )
			{
				flIn.at( ( iFrame - 1 )*iBufferSize );
				flIn.readBlock( ( char * )uchBuffer, iBufferSize );

				flOut.writeBlock( ( char * )uchBuffer, iBufferSize );
			}
		}
		else
		{
			for ( int iFrame = iFrameFrom; iFrame <= iFrameTo; iFrame += iFrameStep )
			{
				flIn.at( ( iFrame - 1 )*iBufferSize );
				flIn.readBlock( ( char * )uchBuffer, iBufferSize );

				flOut.writeBlock( ( char * )uchBuffer, iBufferSize );
			}
		}
	}
	else
	{
		for ( int iFrame = 1; iFrame <= iNumberOfFrames; ++iFrame )
		{
			flIn.at( ( iFrame - 1 )*iBufferSize );
			flIn.readBlock( ( char * )uchBuffer, iBufferSize );

			flOut.writeBlock( ( char * )uchBuffer, iBufferSize );
		}
	}

	flOut.close( );

	return true;
} // End of save.


//******************************************************************************
// PROCEDURE buffer
//******************************************************************************

uchar * CLVideo::buffer( void ) const
{
	return uchBuffer;
} // End of buffer.


//******************************************************************************
// PROCEDURE frame
//******************************************************************************

const QPixmap & CLVideo::frame( void ) const
{
	return pxmFrame[bAllFramesInMemory ? ( iCurrFrame - 1 ) : 0];
} // End of frame.


//******************************************************************************
// PROCEDURE numberOfFrames
//******************************************************************************

int CLVideo::numberOfFrames( void ) const
{
	return iNumberOfFrames;
} // End of numberOfFrames.


//******************************************************************************
// PROCEDURE CLVideo (Constructor)
//******************************************************************************

	CLVideo::CLVideo( QWidget *wgtParent, const char *szName, WFlags wf )
:QWidget( wgtParent, szName, wf )
{
	bAllFramesInMemory = false;

	uchBuffer = NULL;

	iBufferSize = 0;

	iCurrFrame = 0;
	iNumberOfFrames = 0;

	iVideoSizeX = 352;
	iVideoSizeY = 288;

	iColorSpace = YUV420;

	imgFrame.create( iVideoSizeX, iVideoSizeY, 32 );

	QRgb rgbPixel = 0;

	QRgb **rgbFrame = ( QRgb ** )imgFrame.jumpTable( );

	for ( int iY = 0; iY < iVideoSizeY; ++iY )
		for ( int iX = 0; iX < iVideoSizeX; ++iX )
		{
			if ( iX < iVideoSizeX/8 )
				rgbPixel = ( iY < 3*iVideoSizeY/4 )
					? qRgb( 255, 255, 255 )
					: qRgb( 255, 255, 255 ); // White.
			else if ( iX < iVideoSizeX/4 )
				rgbPixel = ( iY < 3*iVideoSizeY/4 )
					? qRgb( 255, 255,   0 )
					: qRgb( 226, 226, 226 ); // Yellow.
			else if ( iX < 3*iVideoSizeX/8 )
				rgbPixel = ( iY < 3*iVideoSizeY/4 )
					? qRgb(   0, 255, 255 )
					: qRgb( 179, 179, 179 ); // Cyan.
			else if ( iX < iVideoSizeX/2 )
				rgbPixel = ( iY < 3*iVideoSizeY/4 )
					? qRgb(   0, 255,   0 )
					: qRgb( 150, 150, 150 ); // Green.
			else if ( iX < 5*iVideoSizeX/8 )
				rgbPixel = ( iY < 3*iVideoSizeY/4 )
					? qRgb( 255,   0, 255 )
					: qRgb( 105, 105, 105 ); // Magenta.
			else if ( iX < 3*iVideoSizeX/4 )
				rgbPixel = ( iY < 3*iVideoSizeY/4 )
					? qRgb( 255,   0,   0 )
					: qRgb(  76,  76,  76 ); // Red.
			else if ( iX < 7*iVideoSizeX/8 )
				rgbPixel = ( iY < 3*iVideoSizeY/4 )
					? qRgb(   0,   0, 255 )
					: qRgb(  29,  29,  29 ); // Blue.
			else
				rgbPixel = ( iY < 3*iVideoSizeY/4 )
					? qRgb(   0,   0,   0 )
					: qRgb(   0,   0,   0 ); // Black.

			rgbFrame[iY][iX] = rgbPixel;
		}

	pxmFrame = new QPixmap[1];
	pxmFrame[0] = imgFrame;

	setBackgroundMode( NoBackground );
	resize( iVideoSizeX, iVideoSizeY );

	setMouseTracking( true );
} // End of CLVideo (Constructor).


//******************************************************************************
// PROCEDURE ~CLVideo (Destructor)
//******************************************************************************

CLVideo::~CLVideo( void )
{
	if ( flIn.isOpen( ) )
		flIn.close( );

	if ( NULL != uchBuffer )
		delete[] uchBuffer;

	if ( NULL != pxmFrame )
		delete[] pxmFrame;
} // End of ~CLVideo (Destructor).

