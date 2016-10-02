CCOMPILE        = gcc
CPPCOMPILE      = g++
AR              = ar
GPBCOMPILE      = protoc
PERL            = /usr/bin/perl
TIMESTAMP       = "[$(NAME)] TIMESTAMP =" `date '+%Y%m%d %T'`

CPPFLAGS += -isystem $(GTEST_DIR)/include
CXXFLAGS += -g -Wall -Wextra -pthread


#
# Local Project output sub-directories
#
OBJDIR=objs
DEPDIR=deps
LOCAL_OUTPUT_DIRECTORIES=$(DEPDIR) $(OBJDIR)

#
# Control Linking either dynamic or static
#
LINK_DYNAMIC =-Wl,-Bdynamic
LINK_STATIC  =-Wl,-Bstatic
LINK_DEFAULT =$(LINK_DYNAMIC)

#
# Boost FLAGS assumptions (e.g. USING_BOOST=true set by default in common_.mk)
#
BOOST_LD =$(LINK_DYNAMIC) -L/usr/local/lib -lboost_date_time -lboost_filesystem -lboost_thread -lboost_program_options -lboost_signals $(LINK_DEFAULT)

#
# Protocol Buffers FLAGS
#
GPB_LD =$(LINK_STATIC) -L/usr/local/lib -lprotobuf-lite $(LINK_DEFAULT)

#
# SSL Flags     (e.g. USING_SSL=true)
#
SSL_CC =
SSL_LD =$(LINK_DYNAMIC) -lssl -lcrypto $(LINK_DEFAULT)

#
# Compile FLAGS
#
CFLAGS_BASE       = -fpic -ggdb -fno-threadsafe-statics -pthread
CFLAGS_LIBERAL    = -Wall -Werror -Wextra -Wno-long-long
CFLAGS_STRICT     = -pedantic-errors
CFLAGS_FASCIST    = -Weffc++
CFLAGS_BASEINC    = -I$(DJDW_DIR) -isystem/usr/local/include
CFLAGS_COMPILE_SPEED_ENTITLEMENT= --param ggc-min-expand=25 --param ggc-min-heapsize=131072

#
# 'Assumed' Flags
#
RT_LD      =$(LINK_DYNAMIC) -lrt $(LINK_DEFAULT)
PTHREAD_LD =$(LINK_DYNAMIC) -lpthread $(LINK_DEFAULT)
LDASSUME   =$(RT_LD) $(PTHREAD_LD)

#EOF

