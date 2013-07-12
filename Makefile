#############################################################################
# Makefile for building zplayer
# Generated by tmake at 22:04, 2005/05/15
#     Project: zplayer
#    Template: app
#############################################################################

####### Compiler, tools and options

CC	=	gcc
CXX	=	g++
CFLAGS	=	-pipe -Wall -W -O3 -D_REENTRANT -DQT_THREAD_SUPPORT -DNO_DEBUG
CXXFLAGS=	-pipe -Wall -W -O3 -D_REENTRANT -DQT_THREAD_SUPPORT -DNO_DEBUG
INCPATH	=	-I$(QTDIR)/usr/include/qt3
LINK	=	g++
LFLAGS	=	
LIBS	=	$(SUBLIBS) -L$(QTDIR)/lib -L/usr/X11R6/lib -lpthread -lqt-mt -lXext -lX11 -lm
MOC	=	$(QTDIR)/usr/bin/moc
UIC	=	$(QTDIR)/usr/bin/uic

TAR	=	tar -cf
GZIP	=	gzip -9f

####### Files

HEADERS =	icons.h \
		fileopendlg.h \
		filesavedlg.h \
		playerdoc.h \
		playerview.h \
		playerwin.h \
		video.h
SOURCES =	fileopendlg.cpp \
		filesavedlg.cpp \
		main.cpp \
		playerdoc.cpp \
		playerview.cpp \
		playerwin.cpp \
		video.cpp
OBJECTS =	fileopendlg.o \
		filesavedlg.o \
		main.o \
		playerdoc.o \
		playerview.o \
		playerwin.o \
		video.o
INTERFACES =	
UICDECLS =	
UICIMPLS =	
SRCMOC	=	moc_fileopendlg.cpp \
		moc_filesavedlg.cpp \
		moc_playerdoc.cpp \
		moc_playerview.cpp \
		moc_playerwin.cpp \
		moc_video.cpp
OBJMOC	=	moc_fileopendlg.o \
		moc_filesavedlg.o \
		moc_playerdoc.o \
		moc_playerview.o \
		moc_playerwin.o \
		moc_video.o
DIST	=	
TARGET	=	zplayer
INTERFACE_DECL_PATH = .

####### Implicit rules

.SUFFIXES: .cpp .cxx .cc .C .c

.cpp.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cxx.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.cc.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.C.o:
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o $@ $<

.c.o:
	$(CC) -c $(CFLAGS) $(INCPATH) -o $@ $<

####### Build rules


all: $(TARGET)

$(TARGET): $(UICDECLS) $(OBJECTS) $(OBJMOC) 
	$(LINK) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJMOC) $(LIBS)

moc: $(SRCMOC)

tmake: Makefile

Makefile: zplayer.pro
	tmake zplayer.pro -o Makefile

dist:
	$(TAR) zplayer.tar zplayer.pro $(SOURCES) $(HEADERS) $(INTERFACES) $(DIST)
	$(GZIP) zplayer.tar

clean:
	-rm -f $(OBJECTS) $(OBJMOC) $(SRCMOC) $(UICIMPLS) $(UICDECLS) $(TARGET)
	-rm -f *~ core

####### Sub-libraries


###### Combined headers


####### Compile

fileopendlg.o: fileopendlg.cpp \
		fileopendlg.h

filesavedlg.o: filesavedlg.cpp \
		filesavedlg.h

main.o: main.cpp \
		playerwin.h

playerdoc.o: playerdoc.cpp \
		playerdoc.h \
		playerview.h \
		video.h

playerview.o: playerview.cpp \
		playerview.h \
		video.h

playerwin.o: playerwin.cpp \
		icons.h \
		fileopendlg.h \
		filesavedlg.h \
		playerdoc.h \
		playerview.h \
		playerwin.h \
		video.h

video.o: video.cpp \
		video.h

moc_fileopendlg.o: moc_fileopendlg.cpp \
		fileopendlg.h

moc_filesavedlg.o: moc_filesavedlg.cpp \
		filesavedlg.h

moc_playerdoc.o: moc_playerdoc.cpp \
		playerdoc.h

moc_playerview.o: moc_playerview.cpp \
		playerview.h

moc_playerwin.o: moc_playerwin.cpp \
		playerwin.h

moc_video.o: moc_video.cpp \
		video.h

moc_fileopendlg.cpp: fileopendlg.h
	$(MOC) fileopendlg.h -o moc_fileopendlg.cpp

moc_filesavedlg.cpp: filesavedlg.h
	$(MOC) filesavedlg.h -o moc_filesavedlg.cpp

moc_playerdoc.cpp: playerdoc.h
	$(MOC) playerdoc.h -o moc_playerdoc.cpp

moc_playerview.cpp: playerview.h
	$(MOC) playerview.h -o moc_playerview.cpp

moc_playerwin.cpp: playerwin.h
	$(MOC) playerwin.h -o moc_playerwin.cpp

moc_video.cpp: video.h
	$(MOC) video.h -o moc_video.cpp

