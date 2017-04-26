#
# OMNeT++/OMNEST Makefile for research-project
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out -L/home/kunterbunt/dev/omnetpp-5.0/samples/inet/out/$$\(CONFIGNAME\)/src -L/home/kunterbunt/dev/omnetpp-5.0/samples/simulte/out/$$\(CONFIGNAME\)/src -lINET -lsimulte -DINET_IMPORT -KINET_PROJ=/home/kunterbunt/dev/omnetpp-5.0/samples/inet -KSIMULTE_PROJ=/home/kunterbunt/dev/omnetpp-5.0/samples/simulte
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
    -I. \
    -Iconfigs \
    -Ievaluation \
    -Ievaluation/mode-selection \
    -Ievaluation/mode-selection/test \
    -Iresults \
    -Iresults/ComplexSim-MD \
    -Iresults/ComplexSim-MD/10 \
    -Iresults/ComplexSim-MD/11 \
    -Iresults/ComplexSim-MD/12 \
    -Iresults/ComplexSim-MD/13 \
    -Iresults/ComplexSim-MD/14 \
    -Iresults/ComplexSim-MD/15 \
    -Iresults/ComplexSim-MD/16 \
    -Iresults/ComplexSim-MD/17 \
    -Iresults/ComplexSim-MD/18 \
    -Iresults/ComplexSim-MD/19 \
    -Iresults/ComplexSim-MD/20 \
    -Iresults/ComplexSim-MD/21 \
    -Iresults/ComplexSim-MD/22 \
    -Iresults/ComplexSim-MD/23 \
    -Iresults/ComplexSim-MD/24 \
    -Iresults/ComplexSim-MD/25 \
    -Iresults/ComplexSim-MD/26 \
    -Iresults/ComplexSim-MD/27 \
    -Iresults/ComplexSim-MD/28 \
    -Iresults/ComplexSim-MD/29 \
    -Iresults/ComplexSim-MD/30 \
    -Iresults/ComplexSim-MD/31 \
    -Iresults/ComplexSim-MD/32 \
    -Iresults/ComplexSim-MD/33 \
    -Iresults/ComplexSim-MD/34 \
    -Iresults/ComplexSim-MD/35 \
    -Iresults/ComplexSim-MD/36 \
    -Iresults/ComplexSim-MD/37 \
    -Iresults/ComplexSim-MD/38 \
    -Iresults/ComplexSim-MD/39 \
    -Iresults/ComplexSim-MD/4 \
    -Iresults/ComplexSim-MD/40 \
    -Iresults/ComplexSim-MD/41 \
    -Iresults/ComplexSim-MD/42 \
    -Iresults/ComplexSim-MD/43 \
    -Iresults/ComplexSim-MD/44 \
    -Iresults/ComplexSim-MD/45 \
    -Iresults/ComplexSim-MD/46 \
    -Iresults/ComplexSim-MD/47 \
    -Iresults/ComplexSim-MD/48 \
    -Iresults/ComplexSim-MD/49 \
    -Iresults/ComplexSim-MD/5 \
    -Iresults/ComplexSim-MD/50 \
    -Iresults/ComplexSim-MD/6 \
    -Iresults/ComplexSim-MD/7 \
    -Iresults/ComplexSim-MD/8 \
    -Iresults/ComplexSim-MD/9

# Additional object and library files to link with
EXTRA_OBJS =

# Additional libraries (-L, -l options)
LIBS = -L$(INET_PROJ)/out/$(CONFIGNAME)/src -L$(SIMULTE_PROJ)/out/$(CONFIGNAME)/src  -lINET -lsimulte
LIBS += -Wl,-rpath,`abspath $(INET_PROJ)/out/$(CONFIGNAME)/src` -Wl,-rpath,`abspath $(SIMULTE_PROJ)/out/$(CONFIGNAME)/src`

# Output directory
PROJECT_OUTPUT_DIR = out
PROJECTRELATIVE_PATH =
O = $(PROJECT_OUTPUT_DIR)/$(CONFIGNAME)/$(PROJECTRELATIVE_PATH)

# Object files for local .cc, .msg and .sm files
OBJS =

# Message files
MSGFILES =

# SM files
SMFILES =

# Other makefile variables (-K)
INET_PROJ=/home/kunterbunt/dev/omnetpp-5.0/samples/inet
SIMULTE_PROJ=/home/kunterbunt/dev/omnetpp-5.0/samples/simulte

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

COPTS = $(CFLAGS) -DINET_IMPORT $(INCLUDE_PATH) -I$(OMNETPP_INCL_DIR)
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
	$(Q)-rm -f configs/*_m.cc configs/*_m.h configs/*_sm.cc configs/*_sm.h
	$(Q)-rm -f evaluation/*_m.cc evaluation/*_m.h evaluation/*_sm.cc evaluation/*_sm.h
	$(Q)-rm -f evaluation/mode-selection/*_m.cc evaluation/mode-selection/*_m.h evaluation/mode-selection/*_sm.cc evaluation/mode-selection/*_sm.h
	$(Q)-rm -f evaluation/mode-selection/test/*_m.cc evaluation/mode-selection/test/*_m.h evaluation/mode-selection/test/*_sm.cc evaluation/mode-selection/test/*_sm.h
	$(Q)-rm -f results/*_m.cc results/*_m.h results/*_sm.cc results/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/*_m.cc results/ComplexSim-MD/*_m.h results/ComplexSim-MD/*_sm.cc results/ComplexSim-MD/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/10/*_m.cc results/ComplexSim-MD/10/*_m.h results/ComplexSim-MD/10/*_sm.cc results/ComplexSim-MD/10/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/11/*_m.cc results/ComplexSim-MD/11/*_m.h results/ComplexSim-MD/11/*_sm.cc results/ComplexSim-MD/11/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/12/*_m.cc results/ComplexSim-MD/12/*_m.h results/ComplexSim-MD/12/*_sm.cc results/ComplexSim-MD/12/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/13/*_m.cc results/ComplexSim-MD/13/*_m.h results/ComplexSim-MD/13/*_sm.cc results/ComplexSim-MD/13/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/14/*_m.cc results/ComplexSim-MD/14/*_m.h results/ComplexSim-MD/14/*_sm.cc results/ComplexSim-MD/14/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/15/*_m.cc results/ComplexSim-MD/15/*_m.h results/ComplexSim-MD/15/*_sm.cc results/ComplexSim-MD/15/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/16/*_m.cc results/ComplexSim-MD/16/*_m.h results/ComplexSim-MD/16/*_sm.cc results/ComplexSim-MD/16/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/17/*_m.cc results/ComplexSim-MD/17/*_m.h results/ComplexSim-MD/17/*_sm.cc results/ComplexSim-MD/17/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/18/*_m.cc results/ComplexSim-MD/18/*_m.h results/ComplexSim-MD/18/*_sm.cc results/ComplexSim-MD/18/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/19/*_m.cc results/ComplexSim-MD/19/*_m.h results/ComplexSim-MD/19/*_sm.cc results/ComplexSim-MD/19/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/20/*_m.cc results/ComplexSim-MD/20/*_m.h results/ComplexSim-MD/20/*_sm.cc results/ComplexSim-MD/20/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/21/*_m.cc results/ComplexSim-MD/21/*_m.h results/ComplexSim-MD/21/*_sm.cc results/ComplexSim-MD/21/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/22/*_m.cc results/ComplexSim-MD/22/*_m.h results/ComplexSim-MD/22/*_sm.cc results/ComplexSim-MD/22/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/23/*_m.cc results/ComplexSim-MD/23/*_m.h results/ComplexSim-MD/23/*_sm.cc results/ComplexSim-MD/23/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/24/*_m.cc results/ComplexSim-MD/24/*_m.h results/ComplexSim-MD/24/*_sm.cc results/ComplexSim-MD/24/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/25/*_m.cc results/ComplexSim-MD/25/*_m.h results/ComplexSim-MD/25/*_sm.cc results/ComplexSim-MD/25/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/26/*_m.cc results/ComplexSim-MD/26/*_m.h results/ComplexSim-MD/26/*_sm.cc results/ComplexSim-MD/26/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/27/*_m.cc results/ComplexSim-MD/27/*_m.h results/ComplexSim-MD/27/*_sm.cc results/ComplexSim-MD/27/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/28/*_m.cc results/ComplexSim-MD/28/*_m.h results/ComplexSim-MD/28/*_sm.cc results/ComplexSim-MD/28/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/29/*_m.cc results/ComplexSim-MD/29/*_m.h results/ComplexSim-MD/29/*_sm.cc results/ComplexSim-MD/29/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/30/*_m.cc results/ComplexSim-MD/30/*_m.h results/ComplexSim-MD/30/*_sm.cc results/ComplexSim-MD/30/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/31/*_m.cc results/ComplexSim-MD/31/*_m.h results/ComplexSim-MD/31/*_sm.cc results/ComplexSim-MD/31/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/32/*_m.cc results/ComplexSim-MD/32/*_m.h results/ComplexSim-MD/32/*_sm.cc results/ComplexSim-MD/32/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/33/*_m.cc results/ComplexSim-MD/33/*_m.h results/ComplexSim-MD/33/*_sm.cc results/ComplexSim-MD/33/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/34/*_m.cc results/ComplexSim-MD/34/*_m.h results/ComplexSim-MD/34/*_sm.cc results/ComplexSim-MD/34/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/35/*_m.cc results/ComplexSim-MD/35/*_m.h results/ComplexSim-MD/35/*_sm.cc results/ComplexSim-MD/35/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/36/*_m.cc results/ComplexSim-MD/36/*_m.h results/ComplexSim-MD/36/*_sm.cc results/ComplexSim-MD/36/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/37/*_m.cc results/ComplexSim-MD/37/*_m.h results/ComplexSim-MD/37/*_sm.cc results/ComplexSim-MD/37/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/38/*_m.cc results/ComplexSim-MD/38/*_m.h results/ComplexSim-MD/38/*_sm.cc results/ComplexSim-MD/38/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/39/*_m.cc results/ComplexSim-MD/39/*_m.h results/ComplexSim-MD/39/*_sm.cc results/ComplexSim-MD/39/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/4/*_m.cc results/ComplexSim-MD/4/*_m.h results/ComplexSim-MD/4/*_sm.cc results/ComplexSim-MD/4/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/40/*_m.cc results/ComplexSim-MD/40/*_m.h results/ComplexSim-MD/40/*_sm.cc results/ComplexSim-MD/40/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/41/*_m.cc results/ComplexSim-MD/41/*_m.h results/ComplexSim-MD/41/*_sm.cc results/ComplexSim-MD/41/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/42/*_m.cc results/ComplexSim-MD/42/*_m.h results/ComplexSim-MD/42/*_sm.cc results/ComplexSim-MD/42/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/43/*_m.cc results/ComplexSim-MD/43/*_m.h results/ComplexSim-MD/43/*_sm.cc results/ComplexSim-MD/43/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/44/*_m.cc results/ComplexSim-MD/44/*_m.h results/ComplexSim-MD/44/*_sm.cc results/ComplexSim-MD/44/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/45/*_m.cc results/ComplexSim-MD/45/*_m.h results/ComplexSim-MD/45/*_sm.cc results/ComplexSim-MD/45/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/46/*_m.cc results/ComplexSim-MD/46/*_m.h results/ComplexSim-MD/46/*_sm.cc results/ComplexSim-MD/46/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/47/*_m.cc results/ComplexSim-MD/47/*_m.h results/ComplexSim-MD/47/*_sm.cc results/ComplexSim-MD/47/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/48/*_m.cc results/ComplexSim-MD/48/*_m.h results/ComplexSim-MD/48/*_sm.cc results/ComplexSim-MD/48/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/49/*_m.cc results/ComplexSim-MD/49/*_m.h results/ComplexSim-MD/49/*_sm.cc results/ComplexSim-MD/49/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/5/*_m.cc results/ComplexSim-MD/5/*_m.h results/ComplexSim-MD/5/*_sm.cc results/ComplexSim-MD/5/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/50/*_m.cc results/ComplexSim-MD/50/*_m.h results/ComplexSim-MD/50/*_sm.cc results/ComplexSim-MD/50/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/6/*_m.cc results/ComplexSim-MD/6/*_m.h results/ComplexSim-MD/6/*_sm.cc results/ComplexSim-MD/6/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/7/*_m.cc results/ComplexSim-MD/7/*_m.h results/ComplexSim-MD/7/*_sm.cc results/ComplexSim-MD/7/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/8/*_m.cc results/ComplexSim-MD/8/*_m.h results/ComplexSim-MD/8/*_sm.cc results/ComplexSim-MD/8/*_sm.h
	$(Q)-rm -f results/ComplexSim-MD/9/*_m.cc results/ComplexSim-MD/9/*_m.h results/ComplexSim-MD/9/*_sm.cc results/ComplexSim-MD/9/*_sm.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES) $(SM_CC_FILES)  ./*.cc configs/*.cc evaluation/*.cc evaluation/mode-selection/*.cc evaluation/mode-selection/test/*.cc results/*.cc results/ComplexSim-MD/*.cc results/ComplexSim-MD/10/*.cc results/ComplexSim-MD/11/*.cc results/ComplexSim-MD/12/*.cc results/ComplexSim-MD/13/*.cc results/ComplexSim-MD/14/*.cc results/ComplexSim-MD/15/*.cc results/ComplexSim-MD/16/*.cc results/ComplexSim-MD/17/*.cc results/ComplexSim-MD/18/*.cc results/ComplexSim-MD/19/*.cc results/ComplexSim-MD/20/*.cc results/ComplexSim-MD/21/*.cc results/ComplexSim-MD/22/*.cc results/ComplexSim-MD/23/*.cc results/ComplexSim-MD/24/*.cc results/ComplexSim-MD/25/*.cc results/ComplexSim-MD/26/*.cc results/ComplexSim-MD/27/*.cc results/ComplexSim-MD/28/*.cc results/ComplexSim-MD/29/*.cc results/ComplexSim-MD/30/*.cc results/ComplexSim-MD/31/*.cc results/ComplexSim-MD/32/*.cc results/ComplexSim-MD/33/*.cc results/ComplexSim-MD/34/*.cc results/ComplexSim-MD/35/*.cc results/ComplexSim-MD/36/*.cc results/ComplexSim-MD/37/*.cc results/ComplexSim-MD/38/*.cc results/ComplexSim-MD/39/*.cc results/ComplexSim-MD/4/*.cc results/ComplexSim-MD/40/*.cc results/ComplexSim-MD/41/*.cc results/ComplexSim-MD/42/*.cc results/ComplexSim-MD/43/*.cc results/ComplexSim-MD/44/*.cc results/ComplexSim-MD/45/*.cc results/ComplexSim-MD/46/*.cc results/ComplexSim-MD/47/*.cc results/ComplexSim-MD/48/*.cc results/ComplexSim-MD/49/*.cc results/ComplexSim-MD/5/*.cc results/ComplexSim-MD/50/*.cc results/ComplexSim-MD/6/*.cc results/ComplexSim-MD/7/*.cc results/ComplexSim-MD/8/*.cc results/ComplexSim-MD/9/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.

