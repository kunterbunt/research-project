#
# OMNeT++/OMNEST Makefile for research-project
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/stack/mac/allocator -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/stack/d2dModeSelection -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/stack/handoverManager -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/stack/phy/layer -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/stack/mac/layer -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/corenetwork/binder -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/corenetwork/lteip -I/home/kunterbunt/dev/omnetpp-5.0/samples/inet/src/inet/mobility/contract -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/stack/rlc/packet -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/stack/rlc -I/home/kunterbunt/dev/omnetpp-5.0/samples/inet/src/inet/mobility/static -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/stack/mac/scheduling_modules -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/stack/mac/packet -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/stack/mac/buffer/harq_d2d -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/corenetwork/deployer -I/home/kunterbunt/dev/omnetpp-5.0/samples/inet/src/inet/networklayer/contract/ipv4 -I/home/kunterbunt/dev/omnetpp-5.0/samples/inet/src/inet/networklayer/common -I/home/kunterbunt/dev/omnetpp-5.0/samples/inet/src/inet/common -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/stack/phy/das -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/stack/mac/buffer -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/stack/rlc/um/entity -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/x2/packet -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/stack/pdcp_rrc/packet -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/corenetwork/nodes -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/common/timer -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/stack/rlc/um/buffer -I/home/kunterbunt/dev/omnetpp-5.0/samples/inet/src -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/stack/mac/amc -I/home/kunterbunt/dev/omnetpp-5.0/samples/inet/src/inet/common/geometry/common -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/world/radio -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/stack/rlc/um -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/common -I/home/kunterbunt/dev/omnetpp-5.0/samples/inet/src/inet/transportlayer/tcp_common -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/stack/mac/buffer/harq -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/stack/phy/packet -I/home/kunterbunt/dev/omnetpp-5.0/samples/inet/src/inet/common/queue -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/stack/phy/feedback -I/home/kunterbunt/dev/omnetpp-5.0/samples/inet/src/inet/transportlayer/udp -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/stack/mac/scheduler -I/home/kunterbunt/dev/omnetpp-5.0/samples/inet/src/inet/networklayer/ipv4 -I/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/src/stack/phy/ChannelModel -L/home/kunterbunt/dev/omnetpp-5.0/samples/inet/out/$$\(CONFIGNAME\)/src -L/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original/out/$$\(CONFIGNAME\)/src -lINET -lsimulte-original -KINET_PROJ=/home/kunterbunt/dev/omnetpp-5.0/samples/inet -KSIMULTE_ORIGINAL_PROJ=/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original
#

# Name of target to be created (-o option)
TARGET = research-project$(EXE_SUFFIX)

# User interface (uncomment one) (-u option)
USERIF_LIBS = $(ALL_ENV_LIBS) # that is, $(TKENV_LIBS) $(QTENV_LIBS) $(CMDENV_LIBS)
#USERIF_LIBS = $(CMDENV_LIBS)
#USERIF_LIBS = $(TKENV_LIBS)
#USERIF_LIBS = $(QTENV_LIBS)

# C++ include paths (with -I)
INCLUDE_PATH = \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/stack/mac/allocator \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/stack/d2dModeSelection \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/stack/handoverManager \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/stack/phy/layer \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/stack/mac/layer \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/corenetwork/binder \
    -I$(SIMULTE_ORIGINAL_PROJ)/src \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/corenetwork/lteip \
    -I$(INET_PROJ)/src/inet/mobility/contract \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/stack/rlc/packet \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/stack/rlc \
    -I$(INET_PROJ)/src/inet/mobility/static \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/stack/mac/scheduling_modules \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/stack/mac/packet \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/stack/mac/buffer/harq_d2d \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/corenetwork/deployer \
    -I$(INET_PROJ)/src/inet/networklayer/contract/ipv4 \
    -I$(INET_PROJ)/src/inet/networklayer/common \
    -I$(INET_PROJ)/src/inet/common \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/stack/phy/das \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/stack/mac/buffer \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/stack/rlc/um/entity \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/x2/packet \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/stack/pdcp_rrc/packet \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/corenetwork/nodes \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/common/timer \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/stack/rlc/um/buffer \
    -I$(INET_PROJ)/src \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/stack/mac/amc \
    -I$(INET_PROJ)/src/inet/common/geometry/common \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/world/radio \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/stack/rlc/um \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/common \
    -I$(INET_PROJ)/src/inet/transportlayer/tcp_common \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/stack/mac/buffer/harq \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/stack/phy/packet \
    -I$(INET_PROJ)/src/inet/common/queue \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/stack/phy/feedback \
    -I$(INET_PROJ)/src/inet/transportlayer/udp \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/stack/mac/scheduler \
    -I$(INET_PROJ)/src/inet/networklayer/ipv4 \
    -I$(SIMULTE_ORIGINAL_PROJ)/src/stack/phy/ChannelModel \
    -I. \
    -Ievaluation \
    -Ievaluation/mode-selection \
    -Ievaluation/mode-selection/test \
    -Iresults \
    -Iresults/Cellular \
    -Iresults/D2D \
    -Iresults/D2D-ModeSelection-BestCQI \
    -Isrc \
    -Isrc/mode-selection

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L$(INET_PROJ)/out/$(CONFIGNAME)/src -L$(SIMULTE_ORIGINAL_PROJ)/out/$(CONFIGNAME)/src  -lINET -lsimulte-original
LIBS += -Wl,-rpath,`abspath $(INET_PROJ)/out/$(CONFIGNAME)/src` -Wl,-rpath,`abspath $(SIMULTE_ORIGINAL_PROJ)/out/$(CONFIGNAME)/src`

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc, .msg and .sm files
OBJS = $O/src/mode-selection/D2DModeSelectionRandom.o

# Message files
MSGFILES =

# SM files
SMFILES =

# Other makefile variables (-K)
INET_PROJ=/home/kunterbunt/dev/omnetpp-5.0/samples/inet
SIMULTE_ORIGINAL_PROJ=/home/kunterbunt/dev/omnetpp-5.0/samples/simulte-original

#------------------------------------------------------------------------------

# Pull in OMNeT++ configuration (Makefile.inc or configuser.vc)

ifneq ("$(OMNETPP_CONFIGFILE)","")
CONFIGFILE = $(OMNETPP_CONFIGFILE)
else
ifneq ("$(OMNETPP_ROOT)","")
CONFIGFILE = $(OMNETPP_ROOT)/Makefile.inc
else
CONFIGFILE = $(shell opp_configfilepath)
endif
endif

ifeq ("$(wildcard $(CONFIGFILE))","")
$(error Config file '$(CONFIGFILE)' does not exist -- add the OMNeT++ bin directory to the path so that opp_configfilepath can be found, or set the OMNETPP_CONFIGFILE variable to point to Makefile.inc)
endif

include $(CONFIGFILE)

# Simulation kernel and user interface libraries
OMNETPP_LIB_SUBDIR = $(OMNETPP_LIB_DIR)/$(TOOLCHAIN_NAME)
OMNETPP_LIBS = -L"$(OMNETPP_LIB_SUBDIR)" -L"$(OMNETPP_LIB_DIR)" -loppmain$D $(USERIF_LIBS) $(KERNEL_LIBS) $(SYS_LIBS)

COPTS = $(CFLAGS)  $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
MSGCOPTS = $(INCLUDE_PATH)
SMCOPTS =

# we want to recompile everything if COPTS changes,
# so we store COPTS into $COPTS_FILE and have object
# files depend on it (except when "make depend" was called)
COPTS_FILE = $O/.last-copts
ifneq ($(MAKECMDGOALS),depend)
ifneq ("$(COPTS)","$(shell cat $(COPTS_FILE) 2>/dev/null || echo '')")
$(shell $(MKPATH) "$O" && echo "$(COPTS)" >$(COPTS_FILE))
endif
endif

#------------------------------------------------------------------------------
# User-supplied makefile fragment(s)
# >>>
# <<<
#------------------------------------------------------------------------------

# Main target
all: $O/$(TARGET)
	$(Q)$(LN) $O/$(TARGET) .

$O/$(TARGET): $(OBJS)  $(wildcard $(EXTRA_OBJS)) Makefile
	@$(MKPATH) $O
	@echo Creating executable: $@
	$(Q)$(CXX) $(LDFLAGS) -o $O/$(TARGET)  $(OBJS) $(EXTRA_OBJS) $(AS_NEEDED_OFF) $(WHOLE_ARCHIVE_ON) $(LIBS) $(WHOLE_ARCHIVE_OFF) $(OMNETPP_LIBS)

.PHONY: all clean cleanall depend msgheaders smheaders

.SUFFIXES: .cc

$O/%.o: %.cc $(COPTS_FILE)
	@$(MKPATH) $(dir $@)
	$(qecho) "$<"
	$(Q)$(CXX) -c $(CXXFLAGS) $(COPTS) -o $@ $<

%_m.cc %_m.h: %.msg
	$(qecho) MSGC: $<
	$(Q)$(MSGC) -s _m.cc $(MSGCOPTS) $?

%_sm.cc %_sm.h: %.sm
	$(qecho) SMC: $<
	$(Q)$(SMC) -c++ -suffix cc $(SMCOPTS) $?

msgheaders: $(MSGFILES:.msg=_m.h)

smheaders: $(SMFILES:.sm=_sm.h)

clean:
	$(qecho) Cleaning...
	$(Q)-rm -rf $O
	$(Q)-rm -f research-project research-project.exe libresearch-project.so libresearch-project.a libresearch-project.dll libresearch-project.dylib
	$(Q)-rm -f ./*_m.cc ./*_m.h ./*_sm.cc ./*_sm.h
	$(Q)-rm -f evaluation/*_m.cc evaluation/*_m.h evaluation/*_sm.cc evaluation/*_sm.h
	$(Q)-rm -f evaluation/mode-selection/*_m.cc evaluation/mode-selection/*_m.h evaluation/mode-selection/*_sm.cc evaluation/mode-selection/*_sm.h
	$(Q)-rm -f evaluation/mode-selection/test/*_m.cc evaluation/mode-selection/test/*_m.h evaluation/mode-selection/test/*_sm.cc evaluation/mode-selection/test/*_sm.h
	$(Q)-rm -f results/*_m.cc results/*_m.h results/*_sm.cc results/*_sm.h
	$(Q)-rm -f results/Cellular/*_m.cc results/Cellular/*_m.h results/Cellular/*_sm.cc results/Cellular/*_sm.h
	$(Q)-rm -f results/D2D/*_m.cc results/D2D/*_m.h results/D2D/*_sm.cc results/D2D/*_sm.h
	$(Q)-rm -f results/D2D-ModeSelection-BestCQI/*_m.cc results/D2D-ModeSelection-BestCQI/*_m.h results/D2D-ModeSelection-BestCQI/*_sm.cc results/D2D-ModeSelection-BestCQI/*_sm.h
	$(Q)-rm -f src/*_m.cc src/*_m.h src/*_sm.cc src/*_sm.h
	$(Q)-rm -f src/mode-selection/*_m.cc src/mode-selection/*_m.h src/mode-selection/*_sm.cc src/mode-selection/*_sm.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES) $(SM_CC_FILES)  ./*.cc evaluation/*.cc evaluation/mode-selection/*.cc evaluation/mode-selection/test/*.cc results/*.cc results/Cellular/*.cc results/D2D/*.cc results/D2D-ModeSelection-BestCQI/*.cc src/*.cc src/mode-selection/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.
$O/src/mode-selection/D2DModeSelectionRandom.o: src/mode-selection/D2DModeSelectionRandom.cc \
	$(INET_PROJ)/src/inet/common/Compat.h \
	$(INET_PROJ)/src/inet/common/INETDefs.h \
	$(INET_PROJ)/src/inet/common/INETMath.h \
	$(INET_PROJ)/src/inet/common/InitStages.h \
	$(INET_PROJ)/src/inet/common/geometry/common/Coord.h \
	$(INET_PROJ)/src/inet/features.h \
	$(INET_PROJ)/src/inet/linklayer/common/MACAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/L3Address.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModuleIdAddress.h \
	$(INET_PROJ)/src/inet/networklayer/common/ModulePathAddress.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv4/IPv4Address.h \
	$(INET_PROJ)/src/inet/networklayer/contract/ipv6/IPv6Address.h \
	src/mode-selection/D2DModeSelectionRandom.h \
	$(SIMULTE_ORIGINAL_PROJ)/src/common/LteCommon.h \
	$(SIMULTE_ORIGINAL_PROJ)/src/common/lterecorder.h \
	$(SIMULTE_ORIGINAL_PROJ)/src/corenetwork/binder/LteBinder.h \
	$(SIMULTE_ORIGINAL_PROJ)/src/corenetwork/binder/PhyPisaData.h \
	$(SIMULTE_ORIGINAL_PROJ)/src/corenetwork/deployer/LteDeployer.h \
	$(SIMULTE_ORIGINAL_PROJ)/src/corenetwork/nodes/ExtCell.h \
	$(SIMULTE_ORIGINAL_PROJ)/src/stack/d2dModeSelection/D2DModeSelectionBase.h \
	$(SIMULTE_ORIGINAL_PROJ)/src/stack/mac/amc/AmcPilot.h \
	$(SIMULTE_ORIGINAL_PROJ)/src/stack/mac/amc/LteAmc.h \
	$(SIMULTE_ORIGINAL_PROJ)/src/stack/mac/amc/LteMcs.h \
	$(SIMULTE_ORIGINAL_PROJ)/src/stack/mac/amc/UserTxParams.h \
	$(SIMULTE_ORIGINAL_PROJ)/src/stack/mac/layer/LteMacBase.h \
	$(SIMULTE_ORIGINAL_PROJ)/src/stack/mac/layer/LteMacEnb.h \
	$(SIMULTE_ORIGINAL_PROJ)/src/stack/phy/das/RemoteAntennaSet.h \
	$(SIMULTE_ORIGINAL_PROJ)/src/stack/phy/feedback/LteFeedback.h

