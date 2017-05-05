#
# OMNeT++/OMNEST Makefile for research-project
#
# This file was generated with the command:
#  opp_makemake -f --deep -O out -L/home/kunterbunt/dev/omnetpp-5.0/samples/inet/out/$$\(CONFIGNAME\)/src -L/home/kunterbunt/dev/omnetpp-5.0/samples/simulte/out/$$\(CONFIGNAME\)/src -lINET -lsimulte -KINET_PROJ=/home/kunterbunt/dev/omnetpp-5.0/samples/inet -KSIMULTE_PROJ=/home/kunterbunt/dev/omnetpp-5.0/samples/simulte
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
    -Ievaluation/parameter-study_pairs-bands-rbs \
    -Iresults \
    -Iresults/ReassignmentTest-1RBs-D2D \
    -Iresults/ReassignmentTest-1RBs-D2D/1pairs \
    -Iresults/ReassignmentTest-1RBs-D2D/2pairs \
    -Iresults/ReassignmentTest-1RBs-D2D/3pairs \
    -Iresults/ReassignmentTest-1RBs-D2D/4pairs \
    -Iresults/ReassignmentTest-1RBs-D2D/5pairs \
    -Iresults/ReassignmentTest-1RBs-Local \
    -Iresults/ReassignmentTest-50RBs-D2D \
    -Iresults/ReassignmentTest-50RBs-D2D/1pairs \
    -Iresults/ReassignmentTest-50RBs-D2D/2pairs \
    -Iresults/ReassignmentTest-50RBs-D2D/3pairs \
    -Iresults/ReassignmentTest-50RBs-D2D/4pairs \
    -Iresults/ReassignmentTest-50RBs-D2D/5pairs \
    -Iresults/ReassignmentTest-50RBs-Local \
    -Iresults/ReassignmentTest-50RBs-Local/2pairs \
    -Iresults/Test-CellularFirst \
    -Iresults/Test-Reassignment \
    -Iresults/Test-SINR \
    -Iresults/Test-Sorting \
    -Iresults/Test-Sorting-D2D

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
	$(Q)-rm -f configs/*_m.cc configs/*_m.h configs/*_sm.cc configs/*_sm.h
	$(Q)-rm -f evaluation/*_m.cc evaluation/*_m.h evaluation/*_sm.cc evaluation/*_sm.h
	$(Q)-rm -f evaluation/mode-selection/*_m.cc evaluation/mode-selection/*_m.h evaluation/mode-selection/*_sm.cc evaluation/mode-selection/*_sm.h
	$(Q)-rm -f evaluation/mode-selection/test/*_m.cc evaluation/mode-selection/test/*_m.h evaluation/mode-selection/test/*_sm.cc evaluation/mode-selection/test/*_sm.h
	$(Q)-rm -f evaluation/parameter-study_pairs-bands-rbs/*_m.cc evaluation/parameter-study_pairs-bands-rbs/*_m.h evaluation/parameter-study_pairs-bands-rbs/*_sm.cc evaluation/parameter-study_pairs-bands-rbs/*_sm.h
	$(Q)-rm -f results/*_m.cc results/*_m.h results/*_sm.cc results/*_sm.h
	$(Q)-rm -f results/ReassignmentTest-1RBs-D2D/*_m.cc results/ReassignmentTest-1RBs-D2D/*_m.h results/ReassignmentTest-1RBs-D2D/*_sm.cc results/ReassignmentTest-1RBs-D2D/*_sm.h
	$(Q)-rm -f results/ReassignmentTest-1RBs-D2D/1pairs/*_m.cc results/ReassignmentTest-1RBs-D2D/1pairs/*_m.h results/ReassignmentTest-1RBs-D2D/1pairs/*_sm.cc results/ReassignmentTest-1RBs-D2D/1pairs/*_sm.h
	$(Q)-rm -f results/ReassignmentTest-1RBs-D2D/2pairs/*_m.cc results/ReassignmentTest-1RBs-D2D/2pairs/*_m.h results/ReassignmentTest-1RBs-D2D/2pairs/*_sm.cc results/ReassignmentTest-1RBs-D2D/2pairs/*_sm.h
	$(Q)-rm -f results/ReassignmentTest-1RBs-D2D/3pairs/*_m.cc results/ReassignmentTest-1RBs-D2D/3pairs/*_m.h results/ReassignmentTest-1RBs-D2D/3pairs/*_sm.cc results/ReassignmentTest-1RBs-D2D/3pairs/*_sm.h
	$(Q)-rm -f results/ReassignmentTest-1RBs-D2D/4pairs/*_m.cc results/ReassignmentTest-1RBs-D2D/4pairs/*_m.h results/ReassignmentTest-1RBs-D2D/4pairs/*_sm.cc results/ReassignmentTest-1RBs-D2D/4pairs/*_sm.h
	$(Q)-rm -f results/ReassignmentTest-1RBs-D2D/5pairs/*_m.cc results/ReassignmentTest-1RBs-D2D/5pairs/*_m.h results/ReassignmentTest-1RBs-D2D/5pairs/*_sm.cc results/ReassignmentTest-1RBs-D2D/5pairs/*_sm.h
	$(Q)-rm -f results/ReassignmentTest-1RBs-Local/*_m.cc results/ReassignmentTest-1RBs-Local/*_m.h results/ReassignmentTest-1RBs-Local/*_sm.cc results/ReassignmentTest-1RBs-Local/*_sm.h
	$(Q)-rm -f results/ReassignmentTest-50RBs-D2D/*_m.cc results/ReassignmentTest-50RBs-D2D/*_m.h results/ReassignmentTest-50RBs-D2D/*_sm.cc results/ReassignmentTest-50RBs-D2D/*_sm.h
	$(Q)-rm -f results/ReassignmentTest-50RBs-D2D/1pairs/*_m.cc results/ReassignmentTest-50RBs-D2D/1pairs/*_m.h results/ReassignmentTest-50RBs-D2D/1pairs/*_sm.cc results/ReassignmentTest-50RBs-D2D/1pairs/*_sm.h
	$(Q)-rm -f results/ReassignmentTest-50RBs-D2D/2pairs/*_m.cc results/ReassignmentTest-50RBs-D2D/2pairs/*_m.h results/ReassignmentTest-50RBs-D2D/2pairs/*_sm.cc results/ReassignmentTest-50RBs-D2D/2pairs/*_sm.h
	$(Q)-rm -f results/ReassignmentTest-50RBs-D2D/3pairs/*_m.cc results/ReassignmentTest-50RBs-D2D/3pairs/*_m.h results/ReassignmentTest-50RBs-D2D/3pairs/*_sm.cc results/ReassignmentTest-50RBs-D2D/3pairs/*_sm.h
	$(Q)-rm -f results/ReassignmentTest-50RBs-D2D/4pairs/*_m.cc results/ReassignmentTest-50RBs-D2D/4pairs/*_m.h results/ReassignmentTest-50RBs-D2D/4pairs/*_sm.cc results/ReassignmentTest-50RBs-D2D/4pairs/*_sm.h
	$(Q)-rm -f results/ReassignmentTest-50RBs-D2D/5pairs/*_m.cc results/ReassignmentTest-50RBs-D2D/5pairs/*_m.h results/ReassignmentTest-50RBs-D2D/5pairs/*_sm.cc results/ReassignmentTest-50RBs-D2D/5pairs/*_sm.h
	$(Q)-rm -f results/ReassignmentTest-50RBs-Local/*_m.cc results/ReassignmentTest-50RBs-Local/*_m.h results/ReassignmentTest-50RBs-Local/*_sm.cc results/ReassignmentTest-50RBs-Local/*_sm.h
	$(Q)-rm -f results/ReassignmentTest-50RBs-Local/2pairs/*_m.cc results/ReassignmentTest-50RBs-Local/2pairs/*_m.h results/ReassignmentTest-50RBs-Local/2pairs/*_sm.cc results/ReassignmentTest-50RBs-Local/2pairs/*_sm.h
	$(Q)-rm -f results/Test-CellularFirst/*_m.cc results/Test-CellularFirst/*_m.h results/Test-CellularFirst/*_sm.cc results/Test-CellularFirst/*_sm.h
	$(Q)-rm -f results/Test-Reassignment/*_m.cc results/Test-Reassignment/*_m.h results/Test-Reassignment/*_sm.cc results/Test-Reassignment/*_sm.h
	$(Q)-rm -f results/Test-SINR/*_m.cc results/Test-SINR/*_m.h results/Test-SINR/*_sm.cc results/Test-SINR/*_sm.h
	$(Q)-rm -f results/Test-Sorting/*_m.cc results/Test-Sorting/*_m.h results/Test-Sorting/*_sm.cc results/Test-Sorting/*_sm.h
	$(Q)-rm -f results/Test-Sorting-D2D/*_m.cc results/Test-Sorting-D2D/*_m.h results/Test-Sorting-D2D/*_sm.cc results/Test-Sorting-D2D/*_sm.h

cleanall: clean
	$(Q)-rm -rf $(PROJECT_OUTPUT_DIR)

depend:
	$(qecho) Creating dependencies...
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES) $(SM_CC_FILES)  ./*.cc configs/*.cc evaluation/*.cc evaluation/mode-selection/*.cc evaluation/mode-selection/test/*.cc evaluation/parameter-study_pairs-bands-rbs/*.cc results/*.cc results/ReassignmentTest-1RBs-D2D/*.cc results/ReassignmentTest-1RBs-D2D/1pairs/*.cc results/ReassignmentTest-1RBs-D2D/2pairs/*.cc results/ReassignmentTest-1RBs-D2D/3pairs/*.cc results/ReassignmentTest-1RBs-D2D/4pairs/*.cc results/ReassignmentTest-1RBs-D2D/5pairs/*.cc results/ReassignmentTest-1RBs-Local/*.cc results/ReassignmentTest-50RBs-D2D/*.cc results/ReassignmentTest-50RBs-D2D/1pairs/*.cc results/ReassignmentTest-50RBs-D2D/2pairs/*.cc results/ReassignmentTest-50RBs-D2D/3pairs/*.cc results/ReassignmentTest-50RBs-D2D/4pairs/*.cc results/ReassignmentTest-50RBs-D2D/5pairs/*.cc results/ReassignmentTest-50RBs-Local/*.cc results/ReassignmentTest-50RBs-Local/2pairs/*.cc results/Test-CellularFirst/*.cc results/Test-Reassignment/*.cc results/Test-SINR/*.cc results/Test-Sorting/*.cc results/Test-Sorting-D2D/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.

