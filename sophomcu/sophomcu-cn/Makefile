#
# Makefile
#

PREFIX          = /opt
OSTYPE          = linux
UNAME          := $(shell uname)
MACHTYPE	= x86_64
PROG		= sophomcu-cn
SOURCES	       := main.cxx video.cxx conference.cxx filemembers.cxx custom.cxx h323.cxx html.cxx mcu.cxx sip.cxx template.cxx \
                   utils.cxx utils_av.cxx utils_list.cxx utils_type.cxx utils_json.cxx yuv.cxx \
                   mcu_rtp.cxx mcu_rtp_cache.cxx mcu_rtp_secure.cxx \
                   sockets.cxx telnet.cxx \
                   reg.cxx reg_sip.cxx reg_h323.cxx rtsp.cxx recorder.cxx mcu_caps.cxx mcu_codecs.cxx

CXX		= g++
CFLAGS         += -g -O2 
LDFLAGS        += -L../libs/libyuv -L../libs/sofia-sip/libsofia-sip-ua/.libs -L../libs/srtp -L/opt/sophomcu-cn/lib -L/usr/lib -L/usr/local/lib -L/usr/src/sophomcu/libs/h323plus/lib -L/usr/src/sophomcu/libs/ptlib/lib
RFLAGS         += -Wl,-R/opt/sophomcu-cn/lib
SFLAGS         += 
SFLAGS_STATIC  +=  -Wl,--start-group /usr/src/sophomcu/libs/ptlib/lib/libpt_linux_x86_64_r_s.a /usr/src/sophomcu/libs/h323plus/lib/libh323_linux_x86_64_r_s.a -Wl,--end-group
SFLAGS_DEBUG   +=  -Wl,--start-group /usr/src/sophomcu/libs/ptlib/lib/libpt_linux_x86_64_d_s.a /usr/src/sophomcu/libs/h323plus/lib/libh323_linux_x86_64_d_s.a -Wl,--end-group
LDLIBS	       +=   -lsofia-sip-ua -lavcodec -lavutil -lavformat -lswscale -lswresample -lfreetype -lyuv -lssl -lsrtp -lh323_linux_x86_64_r -lpt_linux_x86_64_r
LDLIBS_STATIC  +=   -lsofia-sip-ua -lavcodec -lavutil -lavformat -lswscale -lswresample -lfreetype -lyuv -lssl -lsrtp
LDLIBS_DEBUG   +=   -lsofia-sip-ua -lavcodec -lavutil -lavformat -lswscale -lswresample -lfreetype -lyuv -lssl -lsrtp
STDCCFLAGS     +=  -D__STDC_CONSTANT_MACROS -Wall
STDCXXFLAGS    += 
CPPFLAGS       += -I../libs/h323plus/include -I../libs/libyuv/include -I../libs/ptlib/include -I../libs/sofia-sip/libsofia-sip-ua/bnf -I../libs/sofia-sip/libsofia-sip-ua/docs -I../libs/sofia-sip/libsofia-sip-ua/features -I../libs/sofia-sip/libsofia-sip-ua/http -I../libs/sofia-sip/libsofia-sip-ua/ipt -I../libs/sofia-sip/libsofia-sip-ua/iptsec -I../libs/sofia-sip/libsofia-sip-ua/msg -I../libs/sofia-sip/libsofia-sip-ua/nea -I../libs/sofia-sip/libsofia-sip-ua/nta -I../libs/sofia-sip/libsofia-sip-ua/nth -I../libs/sofia-sip/libsofia-sip-ua/nua -I../libs/sofia-sip/libsofia-sip-ua/sdp -I../libs/sofia-sip/libsofia-sip-ua/sip -I../libs/sofia-sip/libsofia-sip-ua/soa -I../libs/sofia-sip/libsofia-sip-ua/sresolv -I../libs/sofia-sip/libsofia-sip-ua/stun -I../libs/sofia-sip/libsofia-sip-ua/su -I../libs/sofia-sip/libsofia-sip-ua/tport -I../libs/sofia-sip/libsofia-sip-ua/url -I../libs/srtp/crypto/include -I../libs/srtp/include -I/opt/sophomcu-cn/include -I/usr/include -I/usr/include/freetype2 -I/usr/local/include
OPTCCFLAGS      =$(CPPFLAGS)

git_revision        = $(shell git rev-list HEAD --max-count=1)
#git_revision_number = $(shell git rev-list HEAD | wc -l)
STDCCFLAGS     +=-D GIT_REVISION=$(git_revision)

PTLIBDIR        = /usr/src/sophomcu/libs/ptlib
include $(PTLIBDIR)/make/ptbuildopts.mak

INSTALL = install
INSTALL_BACKUP_OPTS =
ifeq ($(UNAME), Linux)
  INSTALL = install
  INSTALL_BACKUP_OPTS = --compare --backup=numbered
endif
ifeq ($(UNAME), FreeBSD)
ifeq (, $(shell which ginstall))
  INSTALL = install
  INSTALL_BACKUP_OPTS = -C -b
else
  INSTALL = ginstall
  INSTALL_BACKUP_OPTS = --compare --backup=numbered
endif
endif


OBJDIR	= ./obj
OBJECTS = $(addprefix $(OBJDIR)/,$(patsubst %.c,%.o,$(patsubst %.cxx,%.o,$(notdir $(SOURCES)))))

$(OBJDIR)/%.o : %.cxx
	@mkdir -p $(OBJDIR) >/dev/null 2>&1
	@echo [CC] $@
	@$(CXX) $(STDCCFLAGS) $(OPTCCFLAGS) $(CFLAGS) $(STDCXXFLAGS) -c $< -o $@

all: $(OBJECTS)
	$(CXX) $(LDSO) -o $(OBJDIR)/$(PROG) $^ $(CFLAGS) $(LDFLAGS) $(SFLAGS) $(RFLAGS) $(OBJS) $(LDLIBS) $(ENDLDLIBS) $(ENDLDFLAGS)

static: $(OBJECTS)
	$(CXX) $(LDSO) -o $(OBJDIR)/$(PROG) $^ $(CFLAGS) $(LDFLAGS) $(SFLAGS_STATIC) $(RFLAGS) $(OBJS) $(LDLIBS_STATIC) $(ENDLDLIBS) $(ENDLDFLAGS)

debug: $(OBJECTS)
	$(CXX) $(LDSO) -o $(OBJDIR)/$(PROG) $^ $(CFLAGS) $(LDFLAGS) $(SFLAGS_DEBUG) $(RFLAGS) $(OBJS) $(LDLIBS_DEBUG) $(ENDLDLIBS) $(ENDLDFLAGS)


install:
	mkdir -p $(DESTDIR)/opt/sophomcu-cn
	mkdir -p $(DESTDIR)/opt/sophomcu-cn/bin
	mkdir -p $(DESTDIR)/opt/sophomcu-cn/config
	mkdir -p $(DESTDIR)/opt/sophomcu-cn/font
	mkdir -p $(DESTDIR)/opt/sophomcu-cn/lib
	mkdir -p $(DESTDIR)/opt/sophomcu-cn/log
	mkdir -p $(DESTDIR)/opt/sophomcu-cn/pipe
	mkdir -p $(DESTDIR)/opt/sophomcu-cn/records
	mkdir -p $(DESTDIR)/opt/sophomcu-cn/resource
	mkdir -p $(DESTDIR)/opt/sophomcu-cn/ssl
	mkdir -p $(DESTDIR)/opt/sophomcu-cn/scripts
	( for file in ./files/conf/*; do \
	    $(INSTALL) -m 644 $(INSTALL_BACKUP_OPTS) $$file $(DESTDIR)/opt/sophomcu-cn/config; \
	done )
	( for file in ./files/font/*; do \
	    $(INSTALL) -m 644 $$file $(DESTDIR)/opt/sophomcu-cn/font; \
	done )
	( for file in ./files/resource/*; do \
	    $(INSTALL) -m 644 $$file $(DESTDIR)/opt/sophomcu-cn/resource; \
	done )
	( for file in ./files/scripts/*; do \
	    $(INSTALL) -m 755 $(INSTALL_BACKUP_OPTS) $$file $(DESTDIR)/opt/sophomcu-cn/scripts; \
	done )
	$(INSTALL) -m 755 $(OBJDIR)/$(PROG) $(DESTDIR)/opt/sophomcu-cn/bin
#	ln -sf $(DESTDIR)/opt/sophomcu-cn/bin/$(PROG) /usr/local/bin/$(PROG)
	$(INSTALL) -m 644 ../AUTHORS $(DESTDIR)/opt/sophomcu-cn
	$(INSTALL) -m 644 ../COPYING $(DESTDIR)/opt/sophomcu-cn
	$(INSTALL) -m 644 ../NEWS $(DESTDIR)/opt/sophomcu-cn
	$(INSTALL) -m 644 ../README $(DESTDIR)/opt/sophomcu-cn

uninstall:
	rm -rf $(DESTDIR)/opt/sophomcu-cn/font
	rm -rf $(DESTDIR)/opt/sophomcu-cn/log
	rm -rf $(DESTDIR)/opt/sophomcu-cn/pipe
	rm -rf $(DESTDIR)/opt/sophomcu-cn/resource
	rm -rf $(DESTDIR)/opt/sophomcu-cn/scripts
	rm -f $(DESTDIR)/opt/sophomcu-cn/AUTHORS
	rm -f $(DESTDIR)/opt/sophomcu-cn/COPYING
	rm -f $(DESTDIR)/opt/sophomcu-cn/NEWS
	rm -f $(DESTDIR)/opt/sophomcu-cn/README
	rm -f $(DESTDIR)/opt/sophomcu-cn/bin/$(PROG)
#	rm -f /usr/local/bin/$(PROG)

clean:
	rm -rf $(OBJDIR)
