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
    -Ievaluation/bandeffect \
    -Ievaluation/mode-selection \
    -Ievaluation/mode-selection/test \
    -Ievaluation/parameter-study_pairs-bands-rbs \
    -Iresults \
    -Iresults/BandEffect-D2D-1RB-DRR \
    -Iresults/BandEffect-D2D-1RB-DRR/10bands \
    -Iresults/BandEffect-D2D-1RB-DRR/1bands \
    -Iresults/BandEffect-D2D-1RB-DRR/2bands \
    -Iresults/BandEffect-D2D-1RB-DRR/3bands \
    -Iresults/BandEffect-D2D-1RB-DRR/4bands \
    -Iresults/BandEffect-D2D-1RB-DRR/5bands \
    -Iresults/BandEffect-D2D-1RB-DRR/6bands \
    -Iresults/BandEffect-D2D-1RB-DRR/7bands \
    -Iresults/BandEffect-D2D-1RB-DRR/8bands \
    -Iresults/BandEffect-D2D-1RB-DRR/9bands \
    -Iresults/BandEffect-D2D-1RB-MD \
    -Iresults/BandEffect-D2D-1RB-MD/10bands \
    -Iresults/BandEffect-D2D-1RB-MD/1bands \
    -Iresults/BandEffect-D2D-1RB-MD/2bands \
    -Iresults/BandEffect-D2D-1RB-MD/3bands \
    -Iresults/BandEffect-D2D-1RB-MD/4bands \
    -Iresults/BandEffect-D2D-1RB-MD/5bands \
    -Iresults/BandEffect-D2D-1RB-MD/6bands \
    -Iresults/BandEffect-D2D-1RB-MD/7bands \
    -Iresults/BandEffect-D2D-1RB-MD/8bands \
    -Iresults/BandEffect-D2D-1RB-MD/9bands \
    -Iresults/BandEffect-D2D-50RB-MD \
    -Iresults/BandEffect-D2D-50RB-MD/10bands \
    -Iresults/BandEffect-D2D-50RB-MD/1bands \
    -Iresults/BandEffect-D2D-50RB-MD/2bands \
    -Iresults/BandEffect-D2D-50RB-MD/3bands \
    -Iresults/BandEffect-D2D-50RB-MD/4bands \
    -Iresults/BandEffect-D2D-50RB-MD/5bands \
    -Iresults/BandEffect-D2D-50RB-MD/6bands \
    -Iresults/BandEffect-D2D-50RB-MD/7bands \
    -Iresults/BandEffect-D2D-50RB-MD/8bands \
    -Iresults/BandEffect-D2D-50RB-MD/9bands \
    -Iresults/RBs \
    -Iresults/RBs/1pairs \
    -Iresults/RBs/1pairs/10bands \
    -Iresults/RBs/1pairs/1bands \
    -Iresults/RBs/1pairs/2bands \
    -Iresults/RBs/1pairs/3bands \
    -Iresults/RBs/1pairs/4bands \
    -Iresults/RBs/1pairs/5bands \
    -Iresults/RBs/1pairs/6bands \
    -Iresults/RBs/1pairs/7bands \
    -Iresults/RBs/1pairs/8bands \
    -Iresults/RBs/1pairs/9bands \
    -Iresults/RBs/2pairs \
    -Iresults/RBs/2pairs/10bands \
    -Iresults/RBs/2pairs/1bands \
    -Iresults/RBs/2pairs/2bands \
    -Iresults/RBs/2pairs/3bands \
    -Iresults/RBs/2pairs/4bands \
    -Iresults/RBs/2pairs/5bands \
    -Iresults/RBs/2pairs/6bands \
    -Iresults/RBs/2pairs/7bands \
    -Iresults/RBs/2pairs/8bands \
    -Iresults/RBs/2pairs/9bands \
    -Iresults/RBs/3pairs \
    -Iresults/RBs/3pairs/10bands \
    -Iresults/RBs/3pairs/1bands \
    -Iresults/RBs/3pairs/2bands \
    -Iresults/RBs/3pairs/3bands \
    -Iresults/RBs/3pairs/4bands \
    -Iresults/RBs/3pairs/5bands \
    -Iresults/RBs/3pairs/6bands \
    -Iresults/RBs/3pairs/7bands \
    -Iresults/RBs/3pairs/8bands \
    -Iresults/RBs/3pairs/9bands \
    -Iresults/RBs/4pairs \
    -Iresults/RBs/4pairs/10bands \
    -Iresults/RBs/4pairs/1bands \
    -Iresults/RBs/4pairs/2bands \
    -Iresults/RBs/4pairs/3bands \
    -Iresults/RBs/4pairs/4bands \
    -Iresults/RBs/4pairs/5bands \
    -Iresults/RBs/4pairs/6bands \
    -Iresults/RBs/4pairs/7bands \
    -Iresults/RBs/4pairs/8bands \
    -Iresults/RBs/4pairs/9bands \
    -Iresults/RBs/5pairs \
    -Iresults/RBs/5pairs/10bands \
    -Iresults/RBs/5pairs/1bands \
    -Iresults/RBs/5pairs/2bands \
    -Iresults/RBs/5pairs/3bands \
    -Iresults/RBs/5pairs/4bands \
    -Iresults/RBs/5pairs/5bands \
    -Iresults/RBs/5pairs/6bands \
    -Iresults/RBs/5pairs/7bands \
    -Iresults/RBs/5pairs/8bands \
    -Iresults/RBs/5pairs/9bands \
    -Iresults/RBs-MD \
    -Iresults/RBs-MD/1pairs \
    -Iresults/RBs-MD/1pairs/10bands \
    -Iresults/RBs-MD/1pairs/1bands \
    -Iresults/RBs-MD/1pairs/2bands \
    -Iresults/RBs-MD/1pairs/3bands \
    -Iresults/RBs-MD/1pairs/4bands \
    -Iresults/RBs-MD/1pairs/5bands \
    -Iresults/RBs-MD/1pairs/6bands \
    -Iresults/RBs-MD/1pairs/7bands \
    -Iresults/RBs-MD/1pairs/8bands \
    -Iresults/RBs-MD/1pairs/9bands \
    -Iresults/RBs-MD/2pairs \
    -Iresults/RBs-MD/2pairs/10bands \
    -Iresults/RBs-MD/2pairs/1bands \
    -Iresults/RBs-MD/2pairs/2bands \
    -Iresults/RBs-MD/2pairs/3bands \
    -Iresults/RBs-MD/2pairs/4bands \
    -Iresults/RBs-MD/2pairs/5bands \
    -Iresults/RBs-MD/2pairs/6bands \
    -Iresults/RBs-MD/2pairs/7bands \
    -Iresults/RBs-MD/2pairs/8bands \
    -Iresults/RBs-MD/2pairs/9bands \
    -Iresults/RBs-MD/3pairs \
    -Iresults/RBs-MD/3pairs/10bands \
    -Iresults/RBs-MD/3pairs/1bands \
    -Iresults/RBs-MD/3pairs/2bands \
    -Iresults/RBs-MD/3pairs/3bands \
    -Iresults/RBs-MD/3pairs/4bands \
    -Iresults/RBs-MD/3pairs/5bands \
    -Iresults/RBs-MD/3pairs/6bands \
    -Iresults/RBs-MD/3pairs/7bands \
    -Iresults/RBs-MD/3pairs/8bands \
    -Iresults/RBs-MD/3pairs/9bands \
    -Iresults/RBs-MD/4pairs \
    -Iresults/RBs-MD/4pairs/10bands \
    -Iresults/RBs-MD/4pairs/1bands \
    -Iresults/RBs-MD/4pairs/2bands \
    -Iresults/RBs-MD/4pairs/3bands \
    -Iresults/RBs-MD/4pairs/4bands \
    -Iresults/RBs-MD/4pairs/5bands \
    -Iresults/RBs-MD/4pairs/6bands \
    -Iresults/RBs-MD/4pairs/7bands \
    -Iresults/RBs-MD/4pairs/8bands \
    -Iresults/RBs-MD/4pairs/9bands \
    -Iresults/RBs-MD/5pairs \
    -Iresults/RBs-MD/5pairs/10bands \
    -Iresults/RBs-MD/5pairs/1bands \
    -Iresults/RBs-MD/5pairs/2bands \
    -Iresults/RBs-MD/5pairs/3bands \
    -Iresults/RBs-MD/5pairs/4bands \
    -Iresults/RBs-MD/5pairs/5bands \
    -Iresults/RBs-MD/5pairs/6bands \
    -Iresults/RBs-MD/5pairs/7bands \
    -Iresults/RBs-MD/5pairs/8bands \
    -Iresults/RBs-MD/5pairs/9bands \
    -Iresults/RBs-MD-in-circle \
    -Iresults/RBs-MD-in-circle/1pairs \
    -Iresults/RBs-MD-in-circle/1pairs/10bands \
    -Iresults/RBs-MD-in-circle/1pairs/1bands \
    -Iresults/RBs-MD-in-circle/1pairs/2bands \
    -Iresults/RBs-MD-in-circle/1pairs/3bands \
    -Iresults/RBs-MD-in-circle/1pairs/4bands \
    -Iresults/RBs-MD-in-circle/1pairs/5bands \
    -Iresults/RBs-MD-in-circle/1pairs/6bands \
    -Iresults/RBs-MD-in-circle/1pairs/7bands \
    -Iresults/RBs-MD-in-circle/1pairs/8bands \
    -Iresults/RBs-MD-in-circle/1pairs/9bands \
    -Iresults/RBs-MD-in-circle/2pairs \
    -Iresults/RBs-MD-in-circle/2pairs/10bands \
    -Iresults/RBs-MD-in-circle/2pairs/1bands \
    -Iresults/RBs-MD-in-circle/2pairs/2bands \
    -Iresults/RBs-MD-in-circle/2pairs/3bands \
    -Iresults/RBs-MD-in-circle/2pairs/4bands \
    -Iresults/RBs-MD-in-circle/2pairs/5bands \
    -Iresults/RBs-MD-in-circle/2pairs/6bands \
    -Iresults/RBs-MD-in-circle/2pairs/7bands \
    -Iresults/RBs-MD-in-circle/2pairs/8bands \
    -Iresults/RBs-MD-in-circle/2pairs/9bands \
    -Iresults/RBs-MD-in-circle/3pairs \
    -Iresults/RBs-MD-in-circle/3pairs/10bands \
    -Iresults/RBs-MD-in-circle/3pairs/1bands \
    -Iresults/RBs-MD-in-circle/3pairs/2bands \
    -Iresults/RBs-MD-in-circle/3pairs/3bands \
    -Iresults/RBs-MD-in-circle/3pairs/4bands \
    -Iresults/RBs-MD-in-circle/3pairs/5bands \
    -Iresults/RBs-MD-in-circle/3pairs/6bands \
    -Iresults/RBs-MD-in-circle/3pairs/7bands \
    -Iresults/RBs-MD-in-circle/3pairs/8bands \
    -Iresults/RBs-MD-in-circle/3pairs/9bands \
    -Iresults/RBs-MD-in-circle/4pairs \
    -Iresults/RBs-MD-in-circle/4pairs/10bands \
    -Iresults/RBs-MD-in-circle/4pairs/1bands \
    -Iresults/RBs-MD-in-circle/4pairs/2bands \
    -Iresults/RBs-MD-in-circle/4pairs/3bands \
    -Iresults/RBs-MD-in-circle/4pairs/4bands \
    -Iresults/RBs-MD-in-circle/4pairs/5bands \
    -Iresults/RBs-MD-in-circle/4pairs/6bands \
    -Iresults/RBs-MD-in-circle/4pairs/7bands \
    -Iresults/RBs-MD-in-circle/4pairs/8bands \
    -Iresults/RBs-MD-in-circle/4pairs/9bands \
    -Iresults/RBs-MD-in-circle/5pairs \
    -Iresults/RBs-MD-in-circle/5pairs/10bands \
    -Iresults/RBs-MD-in-circle/5pairs/1bands \
    -Iresults/RBs-MD-in-circle/5pairs/2bands \
    -Iresults/RBs-MD-in-circle/5pairs/3bands \
    -Iresults/RBs-MD-in-circle/5pairs/4bands \
    -Iresults/RBs-MD-in-circle/5pairs/5bands \
    -Iresults/RBs-MD-in-circle/5pairs/6bands \
    -Iresults/RBs-MD-in-circle/5pairs/7bands \
    -Iresults/RBs-MD-in-circle/5pairs/8bands \
    -Iresults/RBs-MD-in-circle/5pairs/9bands \
    -Iresults/RBs-in-circle \
    -Iresults/RBs-in-circle/1pairs \
    -Iresults/RBs-in-circle/1pairs/10bands \
    -Iresults/RBs-in-circle/1pairs/1bands \
    -Iresults/RBs-in-circle/1pairs/2bands \
    -Iresults/RBs-in-circle/1pairs/3bands \
    -Iresults/RBs-in-circle/1pairs/4bands \
    -Iresults/RBs-in-circle/1pairs/5bands \
    -Iresults/RBs-in-circle/1pairs/6bands \
    -Iresults/RBs-in-circle/1pairs/7bands \
    -Iresults/RBs-in-circle/1pairs/8bands \
    -Iresults/RBs-in-circle/1pairs/9bands \
    -Iresults/RBs-in-circle/2pairs \
    -Iresults/RBs-in-circle/2pairs/10bands \
    -Iresults/RBs-in-circle/2pairs/1bands \
    -Iresults/RBs-in-circle/2pairs/2bands \
    -Iresults/RBs-in-circle/2pairs/3bands \
    -Iresults/RBs-in-circle/2pairs/4bands \
    -Iresults/RBs-in-circle/2pairs/5bands \
    -Iresults/RBs-in-circle/2pairs/6bands \
    -Iresults/RBs-in-circle/2pairs/7bands \
    -Iresults/RBs-in-circle/2pairs/8bands \
    -Iresults/RBs-in-circle/2pairs/9bands \
    -Iresults/RBs-in-circle/3pairs \
    -Iresults/RBs-in-circle/3pairs/10bands \
    -Iresults/RBs-in-circle/3pairs/1bands \
    -Iresults/RBs-in-circle/3pairs/2bands \
    -Iresults/RBs-in-circle/3pairs/3bands \
    -Iresults/RBs-in-circle/3pairs/4bands \
    -Iresults/RBs-in-circle/3pairs/5bands \
    -Iresults/RBs-in-circle/3pairs/6bands \
    -Iresults/RBs-in-circle/3pairs/7bands \
    -Iresults/RBs-in-circle/3pairs/8bands \
    -Iresults/RBs-in-circle/3pairs/9bands \
    -Iresults/RBs-in-circle/4pairs \
    -Iresults/RBs-in-circle/4pairs/10bands \
    -Iresults/RBs-in-circle/4pairs/1bands \
    -Iresults/RBs-in-circle/4pairs/2bands \
    -Iresults/RBs-in-circle/4pairs/3bands \
    -Iresults/RBs-in-circle/4pairs/4bands \
    -Iresults/RBs-in-circle/4pairs/5bands \
    -Iresults/RBs-in-circle/4pairs/6bands \
    -Iresults/RBs-in-circle/4pairs/7bands \
    -Iresults/RBs-in-circle/4pairs/8bands \
    -Iresults/RBs-in-circle/4pairs/9bands \
    -Iresults/RBs-in-circle/5pairs \
    -Iresults/RBs-in-circle/5pairs/10bands \
    -Iresults/RBs-in-circle/5pairs/1bands \
    -Iresults/RBs-in-circle/5pairs/2bands \
    -Iresults/RBs-in-circle/5pairs/3bands \
    -Iresults/RBs-in-circle/5pairs/4bands \
    -Iresults/RBs-in-circle/5pairs/5bands \
    -Iresults/RBs-in-circle/5pairs/6bands \
    -Iresults/RBs-in-circle/5pairs/7bands \
    -Iresults/RBs-in-circle/5pairs/8bands \
    -Iresults/RBs-in-circle/5pairs/9bands \
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
	$(Q)-rm -f evaluation/bandeffect/*_m.cc evaluation/bandeffect/*_m.h evaluation/bandeffect/*_sm.cc evaluation/bandeffect/*_sm.h
	$(Q)-rm -f evaluation/mode-selection/*_m.cc evaluation/mode-selection/*_m.h evaluation/mode-selection/*_sm.cc evaluation/mode-selection/*_sm.h
	$(Q)-rm -f evaluation/mode-selection/test/*_m.cc evaluation/mode-selection/test/*_m.h evaluation/mode-selection/test/*_sm.cc evaluation/mode-selection/test/*_sm.h
	$(Q)-rm -f evaluation/parameter-study_pairs-bands-rbs/*_m.cc evaluation/parameter-study_pairs-bands-rbs/*_m.h evaluation/parameter-study_pairs-bands-rbs/*_sm.cc evaluation/parameter-study_pairs-bands-rbs/*_sm.h
	$(Q)-rm -f results/*_m.cc results/*_m.h results/*_sm.cc results/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-1RB-DRR/*_m.cc results/BandEffect-D2D-1RB-DRR/*_m.h results/BandEffect-D2D-1RB-DRR/*_sm.cc results/BandEffect-D2D-1RB-DRR/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-1RB-DRR/10bands/*_m.cc results/BandEffect-D2D-1RB-DRR/10bands/*_m.h results/BandEffect-D2D-1RB-DRR/10bands/*_sm.cc results/BandEffect-D2D-1RB-DRR/10bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-1RB-DRR/1bands/*_m.cc results/BandEffect-D2D-1RB-DRR/1bands/*_m.h results/BandEffect-D2D-1RB-DRR/1bands/*_sm.cc results/BandEffect-D2D-1RB-DRR/1bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-1RB-DRR/2bands/*_m.cc results/BandEffect-D2D-1RB-DRR/2bands/*_m.h results/BandEffect-D2D-1RB-DRR/2bands/*_sm.cc results/BandEffect-D2D-1RB-DRR/2bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-1RB-DRR/3bands/*_m.cc results/BandEffect-D2D-1RB-DRR/3bands/*_m.h results/BandEffect-D2D-1RB-DRR/3bands/*_sm.cc results/BandEffect-D2D-1RB-DRR/3bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-1RB-DRR/4bands/*_m.cc results/BandEffect-D2D-1RB-DRR/4bands/*_m.h results/BandEffect-D2D-1RB-DRR/4bands/*_sm.cc results/BandEffect-D2D-1RB-DRR/4bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-1RB-DRR/5bands/*_m.cc results/BandEffect-D2D-1RB-DRR/5bands/*_m.h results/BandEffect-D2D-1RB-DRR/5bands/*_sm.cc results/BandEffect-D2D-1RB-DRR/5bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-1RB-DRR/6bands/*_m.cc results/BandEffect-D2D-1RB-DRR/6bands/*_m.h results/BandEffect-D2D-1RB-DRR/6bands/*_sm.cc results/BandEffect-D2D-1RB-DRR/6bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-1RB-DRR/7bands/*_m.cc results/BandEffect-D2D-1RB-DRR/7bands/*_m.h results/BandEffect-D2D-1RB-DRR/7bands/*_sm.cc results/BandEffect-D2D-1RB-DRR/7bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-1RB-DRR/8bands/*_m.cc results/BandEffect-D2D-1RB-DRR/8bands/*_m.h results/BandEffect-D2D-1RB-DRR/8bands/*_sm.cc results/BandEffect-D2D-1RB-DRR/8bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-1RB-DRR/9bands/*_m.cc results/BandEffect-D2D-1RB-DRR/9bands/*_m.h results/BandEffect-D2D-1RB-DRR/9bands/*_sm.cc results/BandEffect-D2D-1RB-DRR/9bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-1RB-MD/*_m.cc results/BandEffect-D2D-1RB-MD/*_m.h results/BandEffect-D2D-1RB-MD/*_sm.cc results/BandEffect-D2D-1RB-MD/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-1RB-MD/10bands/*_m.cc results/BandEffect-D2D-1RB-MD/10bands/*_m.h results/BandEffect-D2D-1RB-MD/10bands/*_sm.cc results/BandEffect-D2D-1RB-MD/10bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-1RB-MD/1bands/*_m.cc results/BandEffect-D2D-1RB-MD/1bands/*_m.h results/BandEffect-D2D-1RB-MD/1bands/*_sm.cc results/BandEffect-D2D-1RB-MD/1bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-1RB-MD/2bands/*_m.cc results/BandEffect-D2D-1RB-MD/2bands/*_m.h results/BandEffect-D2D-1RB-MD/2bands/*_sm.cc results/BandEffect-D2D-1RB-MD/2bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-1RB-MD/3bands/*_m.cc results/BandEffect-D2D-1RB-MD/3bands/*_m.h results/BandEffect-D2D-1RB-MD/3bands/*_sm.cc results/BandEffect-D2D-1RB-MD/3bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-1RB-MD/4bands/*_m.cc results/BandEffect-D2D-1RB-MD/4bands/*_m.h results/BandEffect-D2D-1RB-MD/4bands/*_sm.cc results/BandEffect-D2D-1RB-MD/4bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-1RB-MD/5bands/*_m.cc results/BandEffect-D2D-1RB-MD/5bands/*_m.h results/BandEffect-D2D-1RB-MD/5bands/*_sm.cc results/BandEffect-D2D-1RB-MD/5bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-1RB-MD/6bands/*_m.cc results/BandEffect-D2D-1RB-MD/6bands/*_m.h results/BandEffect-D2D-1RB-MD/6bands/*_sm.cc results/BandEffect-D2D-1RB-MD/6bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-1RB-MD/7bands/*_m.cc results/BandEffect-D2D-1RB-MD/7bands/*_m.h results/BandEffect-D2D-1RB-MD/7bands/*_sm.cc results/BandEffect-D2D-1RB-MD/7bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-1RB-MD/8bands/*_m.cc results/BandEffect-D2D-1RB-MD/8bands/*_m.h results/BandEffect-D2D-1RB-MD/8bands/*_sm.cc results/BandEffect-D2D-1RB-MD/8bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-1RB-MD/9bands/*_m.cc results/BandEffect-D2D-1RB-MD/9bands/*_m.h results/BandEffect-D2D-1RB-MD/9bands/*_sm.cc results/BandEffect-D2D-1RB-MD/9bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-50RB-MD/*_m.cc results/BandEffect-D2D-50RB-MD/*_m.h results/BandEffect-D2D-50RB-MD/*_sm.cc results/BandEffect-D2D-50RB-MD/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-50RB-MD/10bands/*_m.cc results/BandEffect-D2D-50RB-MD/10bands/*_m.h results/BandEffect-D2D-50RB-MD/10bands/*_sm.cc results/BandEffect-D2D-50RB-MD/10bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-50RB-MD/1bands/*_m.cc results/BandEffect-D2D-50RB-MD/1bands/*_m.h results/BandEffect-D2D-50RB-MD/1bands/*_sm.cc results/BandEffect-D2D-50RB-MD/1bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-50RB-MD/2bands/*_m.cc results/BandEffect-D2D-50RB-MD/2bands/*_m.h results/BandEffect-D2D-50RB-MD/2bands/*_sm.cc results/BandEffect-D2D-50RB-MD/2bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-50RB-MD/3bands/*_m.cc results/BandEffect-D2D-50RB-MD/3bands/*_m.h results/BandEffect-D2D-50RB-MD/3bands/*_sm.cc results/BandEffect-D2D-50RB-MD/3bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-50RB-MD/4bands/*_m.cc results/BandEffect-D2D-50RB-MD/4bands/*_m.h results/BandEffect-D2D-50RB-MD/4bands/*_sm.cc results/BandEffect-D2D-50RB-MD/4bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-50RB-MD/5bands/*_m.cc results/BandEffect-D2D-50RB-MD/5bands/*_m.h results/BandEffect-D2D-50RB-MD/5bands/*_sm.cc results/BandEffect-D2D-50RB-MD/5bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-50RB-MD/6bands/*_m.cc results/BandEffect-D2D-50RB-MD/6bands/*_m.h results/BandEffect-D2D-50RB-MD/6bands/*_sm.cc results/BandEffect-D2D-50RB-MD/6bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-50RB-MD/7bands/*_m.cc results/BandEffect-D2D-50RB-MD/7bands/*_m.h results/BandEffect-D2D-50RB-MD/7bands/*_sm.cc results/BandEffect-D2D-50RB-MD/7bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-50RB-MD/8bands/*_m.cc results/BandEffect-D2D-50RB-MD/8bands/*_m.h results/BandEffect-D2D-50RB-MD/8bands/*_sm.cc results/BandEffect-D2D-50RB-MD/8bands/*_sm.h
	$(Q)-rm -f results/BandEffect-D2D-50RB-MD/9bands/*_m.cc results/BandEffect-D2D-50RB-MD/9bands/*_m.h results/BandEffect-D2D-50RB-MD/9bands/*_sm.cc results/BandEffect-D2D-50RB-MD/9bands/*_sm.h
	$(Q)-rm -f results/RBs/*_m.cc results/RBs/*_m.h results/RBs/*_sm.cc results/RBs/*_sm.h
	$(Q)-rm -f results/RBs/1pairs/*_m.cc results/RBs/1pairs/*_m.h results/RBs/1pairs/*_sm.cc results/RBs/1pairs/*_sm.h
	$(Q)-rm -f results/RBs/1pairs/10bands/*_m.cc results/RBs/1pairs/10bands/*_m.h results/RBs/1pairs/10bands/*_sm.cc results/RBs/1pairs/10bands/*_sm.h
	$(Q)-rm -f results/RBs/1pairs/1bands/*_m.cc results/RBs/1pairs/1bands/*_m.h results/RBs/1pairs/1bands/*_sm.cc results/RBs/1pairs/1bands/*_sm.h
	$(Q)-rm -f results/RBs/1pairs/2bands/*_m.cc results/RBs/1pairs/2bands/*_m.h results/RBs/1pairs/2bands/*_sm.cc results/RBs/1pairs/2bands/*_sm.h
	$(Q)-rm -f results/RBs/1pairs/3bands/*_m.cc results/RBs/1pairs/3bands/*_m.h results/RBs/1pairs/3bands/*_sm.cc results/RBs/1pairs/3bands/*_sm.h
	$(Q)-rm -f results/RBs/1pairs/4bands/*_m.cc results/RBs/1pairs/4bands/*_m.h results/RBs/1pairs/4bands/*_sm.cc results/RBs/1pairs/4bands/*_sm.h
	$(Q)-rm -f results/RBs/1pairs/5bands/*_m.cc results/RBs/1pairs/5bands/*_m.h results/RBs/1pairs/5bands/*_sm.cc results/RBs/1pairs/5bands/*_sm.h
	$(Q)-rm -f results/RBs/1pairs/6bands/*_m.cc results/RBs/1pairs/6bands/*_m.h results/RBs/1pairs/6bands/*_sm.cc results/RBs/1pairs/6bands/*_sm.h
	$(Q)-rm -f results/RBs/1pairs/7bands/*_m.cc results/RBs/1pairs/7bands/*_m.h results/RBs/1pairs/7bands/*_sm.cc results/RBs/1pairs/7bands/*_sm.h
	$(Q)-rm -f results/RBs/1pairs/8bands/*_m.cc results/RBs/1pairs/8bands/*_m.h results/RBs/1pairs/8bands/*_sm.cc results/RBs/1pairs/8bands/*_sm.h
	$(Q)-rm -f results/RBs/1pairs/9bands/*_m.cc results/RBs/1pairs/9bands/*_m.h results/RBs/1pairs/9bands/*_sm.cc results/RBs/1pairs/9bands/*_sm.h
	$(Q)-rm -f results/RBs/2pairs/*_m.cc results/RBs/2pairs/*_m.h results/RBs/2pairs/*_sm.cc results/RBs/2pairs/*_sm.h
	$(Q)-rm -f results/RBs/2pairs/10bands/*_m.cc results/RBs/2pairs/10bands/*_m.h results/RBs/2pairs/10bands/*_sm.cc results/RBs/2pairs/10bands/*_sm.h
	$(Q)-rm -f results/RBs/2pairs/1bands/*_m.cc results/RBs/2pairs/1bands/*_m.h results/RBs/2pairs/1bands/*_sm.cc results/RBs/2pairs/1bands/*_sm.h
	$(Q)-rm -f results/RBs/2pairs/2bands/*_m.cc results/RBs/2pairs/2bands/*_m.h results/RBs/2pairs/2bands/*_sm.cc results/RBs/2pairs/2bands/*_sm.h
	$(Q)-rm -f results/RBs/2pairs/3bands/*_m.cc results/RBs/2pairs/3bands/*_m.h results/RBs/2pairs/3bands/*_sm.cc results/RBs/2pairs/3bands/*_sm.h
	$(Q)-rm -f results/RBs/2pairs/4bands/*_m.cc results/RBs/2pairs/4bands/*_m.h results/RBs/2pairs/4bands/*_sm.cc results/RBs/2pairs/4bands/*_sm.h
	$(Q)-rm -f results/RBs/2pairs/5bands/*_m.cc results/RBs/2pairs/5bands/*_m.h results/RBs/2pairs/5bands/*_sm.cc results/RBs/2pairs/5bands/*_sm.h
	$(Q)-rm -f results/RBs/2pairs/6bands/*_m.cc results/RBs/2pairs/6bands/*_m.h results/RBs/2pairs/6bands/*_sm.cc results/RBs/2pairs/6bands/*_sm.h
	$(Q)-rm -f results/RBs/2pairs/7bands/*_m.cc results/RBs/2pairs/7bands/*_m.h results/RBs/2pairs/7bands/*_sm.cc results/RBs/2pairs/7bands/*_sm.h
	$(Q)-rm -f results/RBs/2pairs/8bands/*_m.cc results/RBs/2pairs/8bands/*_m.h results/RBs/2pairs/8bands/*_sm.cc results/RBs/2pairs/8bands/*_sm.h
	$(Q)-rm -f results/RBs/2pairs/9bands/*_m.cc results/RBs/2pairs/9bands/*_m.h results/RBs/2pairs/9bands/*_sm.cc results/RBs/2pairs/9bands/*_sm.h
	$(Q)-rm -f results/RBs/3pairs/*_m.cc results/RBs/3pairs/*_m.h results/RBs/3pairs/*_sm.cc results/RBs/3pairs/*_sm.h
	$(Q)-rm -f results/RBs/3pairs/10bands/*_m.cc results/RBs/3pairs/10bands/*_m.h results/RBs/3pairs/10bands/*_sm.cc results/RBs/3pairs/10bands/*_sm.h
	$(Q)-rm -f results/RBs/3pairs/1bands/*_m.cc results/RBs/3pairs/1bands/*_m.h results/RBs/3pairs/1bands/*_sm.cc results/RBs/3pairs/1bands/*_sm.h
	$(Q)-rm -f results/RBs/3pairs/2bands/*_m.cc results/RBs/3pairs/2bands/*_m.h results/RBs/3pairs/2bands/*_sm.cc results/RBs/3pairs/2bands/*_sm.h
	$(Q)-rm -f results/RBs/3pairs/3bands/*_m.cc results/RBs/3pairs/3bands/*_m.h results/RBs/3pairs/3bands/*_sm.cc results/RBs/3pairs/3bands/*_sm.h
	$(Q)-rm -f results/RBs/3pairs/4bands/*_m.cc results/RBs/3pairs/4bands/*_m.h results/RBs/3pairs/4bands/*_sm.cc results/RBs/3pairs/4bands/*_sm.h
	$(Q)-rm -f results/RBs/3pairs/5bands/*_m.cc results/RBs/3pairs/5bands/*_m.h results/RBs/3pairs/5bands/*_sm.cc results/RBs/3pairs/5bands/*_sm.h
	$(Q)-rm -f results/RBs/3pairs/6bands/*_m.cc results/RBs/3pairs/6bands/*_m.h results/RBs/3pairs/6bands/*_sm.cc results/RBs/3pairs/6bands/*_sm.h
	$(Q)-rm -f results/RBs/3pairs/7bands/*_m.cc results/RBs/3pairs/7bands/*_m.h results/RBs/3pairs/7bands/*_sm.cc results/RBs/3pairs/7bands/*_sm.h
	$(Q)-rm -f results/RBs/3pairs/8bands/*_m.cc results/RBs/3pairs/8bands/*_m.h results/RBs/3pairs/8bands/*_sm.cc results/RBs/3pairs/8bands/*_sm.h
	$(Q)-rm -f results/RBs/3pairs/9bands/*_m.cc results/RBs/3pairs/9bands/*_m.h results/RBs/3pairs/9bands/*_sm.cc results/RBs/3pairs/9bands/*_sm.h
	$(Q)-rm -f results/RBs/4pairs/*_m.cc results/RBs/4pairs/*_m.h results/RBs/4pairs/*_sm.cc results/RBs/4pairs/*_sm.h
	$(Q)-rm -f results/RBs/4pairs/10bands/*_m.cc results/RBs/4pairs/10bands/*_m.h results/RBs/4pairs/10bands/*_sm.cc results/RBs/4pairs/10bands/*_sm.h
	$(Q)-rm -f results/RBs/4pairs/1bands/*_m.cc results/RBs/4pairs/1bands/*_m.h results/RBs/4pairs/1bands/*_sm.cc results/RBs/4pairs/1bands/*_sm.h
	$(Q)-rm -f results/RBs/4pairs/2bands/*_m.cc results/RBs/4pairs/2bands/*_m.h results/RBs/4pairs/2bands/*_sm.cc results/RBs/4pairs/2bands/*_sm.h
	$(Q)-rm -f results/RBs/4pairs/3bands/*_m.cc results/RBs/4pairs/3bands/*_m.h results/RBs/4pairs/3bands/*_sm.cc results/RBs/4pairs/3bands/*_sm.h
	$(Q)-rm -f results/RBs/4pairs/4bands/*_m.cc results/RBs/4pairs/4bands/*_m.h results/RBs/4pairs/4bands/*_sm.cc results/RBs/4pairs/4bands/*_sm.h
	$(Q)-rm -f results/RBs/4pairs/5bands/*_m.cc results/RBs/4pairs/5bands/*_m.h results/RBs/4pairs/5bands/*_sm.cc results/RBs/4pairs/5bands/*_sm.h
	$(Q)-rm -f results/RBs/4pairs/6bands/*_m.cc results/RBs/4pairs/6bands/*_m.h results/RBs/4pairs/6bands/*_sm.cc results/RBs/4pairs/6bands/*_sm.h
	$(Q)-rm -f results/RBs/4pairs/7bands/*_m.cc results/RBs/4pairs/7bands/*_m.h results/RBs/4pairs/7bands/*_sm.cc results/RBs/4pairs/7bands/*_sm.h
	$(Q)-rm -f results/RBs/4pairs/8bands/*_m.cc results/RBs/4pairs/8bands/*_m.h results/RBs/4pairs/8bands/*_sm.cc results/RBs/4pairs/8bands/*_sm.h
	$(Q)-rm -f results/RBs/4pairs/9bands/*_m.cc results/RBs/4pairs/9bands/*_m.h results/RBs/4pairs/9bands/*_sm.cc results/RBs/4pairs/9bands/*_sm.h
	$(Q)-rm -f results/RBs/5pairs/*_m.cc results/RBs/5pairs/*_m.h results/RBs/5pairs/*_sm.cc results/RBs/5pairs/*_sm.h
	$(Q)-rm -f results/RBs/5pairs/10bands/*_m.cc results/RBs/5pairs/10bands/*_m.h results/RBs/5pairs/10bands/*_sm.cc results/RBs/5pairs/10bands/*_sm.h
	$(Q)-rm -f results/RBs/5pairs/1bands/*_m.cc results/RBs/5pairs/1bands/*_m.h results/RBs/5pairs/1bands/*_sm.cc results/RBs/5pairs/1bands/*_sm.h
	$(Q)-rm -f results/RBs/5pairs/2bands/*_m.cc results/RBs/5pairs/2bands/*_m.h results/RBs/5pairs/2bands/*_sm.cc results/RBs/5pairs/2bands/*_sm.h
	$(Q)-rm -f results/RBs/5pairs/3bands/*_m.cc results/RBs/5pairs/3bands/*_m.h results/RBs/5pairs/3bands/*_sm.cc results/RBs/5pairs/3bands/*_sm.h
	$(Q)-rm -f results/RBs/5pairs/4bands/*_m.cc results/RBs/5pairs/4bands/*_m.h results/RBs/5pairs/4bands/*_sm.cc results/RBs/5pairs/4bands/*_sm.h
	$(Q)-rm -f results/RBs/5pairs/5bands/*_m.cc results/RBs/5pairs/5bands/*_m.h results/RBs/5pairs/5bands/*_sm.cc results/RBs/5pairs/5bands/*_sm.h
	$(Q)-rm -f results/RBs/5pairs/6bands/*_m.cc results/RBs/5pairs/6bands/*_m.h results/RBs/5pairs/6bands/*_sm.cc results/RBs/5pairs/6bands/*_sm.h
	$(Q)-rm -f results/RBs/5pairs/7bands/*_m.cc results/RBs/5pairs/7bands/*_m.h results/RBs/5pairs/7bands/*_sm.cc results/RBs/5pairs/7bands/*_sm.h
	$(Q)-rm -f results/RBs/5pairs/8bands/*_m.cc results/RBs/5pairs/8bands/*_m.h results/RBs/5pairs/8bands/*_sm.cc results/RBs/5pairs/8bands/*_sm.h
	$(Q)-rm -f results/RBs/5pairs/9bands/*_m.cc results/RBs/5pairs/9bands/*_m.h results/RBs/5pairs/9bands/*_sm.cc results/RBs/5pairs/9bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/*_m.cc results/RBs-MD/*_m.h results/RBs-MD/*_sm.cc results/RBs-MD/*_sm.h
	$(Q)-rm -f results/RBs-MD/1pairs/*_m.cc results/RBs-MD/1pairs/*_m.h results/RBs-MD/1pairs/*_sm.cc results/RBs-MD/1pairs/*_sm.h
	$(Q)-rm -f results/RBs-MD/1pairs/10bands/*_m.cc results/RBs-MD/1pairs/10bands/*_m.h results/RBs-MD/1pairs/10bands/*_sm.cc results/RBs-MD/1pairs/10bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/1pairs/1bands/*_m.cc results/RBs-MD/1pairs/1bands/*_m.h results/RBs-MD/1pairs/1bands/*_sm.cc results/RBs-MD/1pairs/1bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/1pairs/2bands/*_m.cc results/RBs-MD/1pairs/2bands/*_m.h results/RBs-MD/1pairs/2bands/*_sm.cc results/RBs-MD/1pairs/2bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/1pairs/3bands/*_m.cc results/RBs-MD/1pairs/3bands/*_m.h results/RBs-MD/1pairs/3bands/*_sm.cc results/RBs-MD/1pairs/3bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/1pairs/4bands/*_m.cc results/RBs-MD/1pairs/4bands/*_m.h results/RBs-MD/1pairs/4bands/*_sm.cc results/RBs-MD/1pairs/4bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/1pairs/5bands/*_m.cc results/RBs-MD/1pairs/5bands/*_m.h results/RBs-MD/1pairs/5bands/*_sm.cc results/RBs-MD/1pairs/5bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/1pairs/6bands/*_m.cc results/RBs-MD/1pairs/6bands/*_m.h results/RBs-MD/1pairs/6bands/*_sm.cc results/RBs-MD/1pairs/6bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/1pairs/7bands/*_m.cc results/RBs-MD/1pairs/7bands/*_m.h results/RBs-MD/1pairs/7bands/*_sm.cc results/RBs-MD/1pairs/7bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/1pairs/8bands/*_m.cc results/RBs-MD/1pairs/8bands/*_m.h results/RBs-MD/1pairs/8bands/*_sm.cc results/RBs-MD/1pairs/8bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/1pairs/9bands/*_m.cc results/RBs-MD/1pairs/9bands/*_m.h results/RBs-MD/1pairs/9bands/*_sm.cc results/RBs-MD/1pairs/9bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/2pairs/*_m.cc results/RBs-MD/2pairs/*_m.h results/RBs-MD/2pairs/*_sm.cc results/RBs-MD/2pairs/*_sm.h
	$(Q)-rm -f results/RBs-MD/2pairs/10bands/*_m.cc results/RBs-MD/2pairs/10bands/*_m.h results/RBs-MD/2pairs/10bands/*_sm.cc results/RBs-MD/2pairs/10bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/2pairs/1bands/*_m.cc results/RBs-MD/2pairs/1bands/*_m.h results/RBs-MD/2pairs/1bands/*_sm.cc results/RBs-MD/2pairs/1bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/2pairs/2bands/*_m.cc results/RBs-MD/2pairs/2bands/*_m.h results/RBs-MD/2pairs/2bands/*_sm.cc results/RBs-MD/2pairs/2bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/2pairs/3bands/*_m.cc results/RBs-MD/2pairs/3bands/*_m.h results/RBs-MD/2pairs/3bands/*_sm.cc results/RBs-MD/2pairs/3bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/2pairs/4bands/*_m.cc results/RBs-MD/2pairs/4bands/*_m.h results/RBs-MD/2pairs/4bands/*_sm.cc results/RBs-MD/2pairs/4bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/2pairs/5bands/*_m.cc results/RBs-MD/2pairs/5bands/*_m.h results/RBs-MD/2pairs/5bands/*_sm.cc results/RBs-MD/2pairs/5bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/2pairs/6bands/*_m.cc results/RBs-MD/2pairs/6bands/*_m.h results/RBs-MD/2pairs/6bands/*_sm.cc results/RBs-MD/2pairs/6bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/2pairs/7bands/*_m.cc results/RBs-MD/2pairs/7bands/*_m.h results/RBs-MD/2pairs/7bands/*_sm.cc results/RBs-MD/2pairs/7bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/2pairs/8bands/*_m.cc results/RBs-MD/2pairs/8bands/*_m.h results/RBs-MD/2pairs/8bands/*_sm.cc results/RBs-MD/2pairs/8bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/2pairs/9bands/*_m.cc results/RBs-MD/2pairs/9bands/*_m.h results/RBs-MD/2pairs/9bands/*_sm.cc results/RBs-MD/2pairs/9bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/3pairs/*_m.cc results/RBs-MD/3pairs/*_m.h results/RBs-MD/3pairs/*_sm.cc results/RBs-MD/3pairs/*_sm.h
	$(Q)-rm -f results/RBs-MD/3pairs/10bands/*_m.cc results/RBs-MD/3pairs/10bands/*_m.h results/RBs-MD/3pairs/10bands/*_sm.cc results/RBs-MD/3pairs/10bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/3pairs/1bands/*_m.cc results/RBs-MD/3pairs/1bands/*_m.h results/RBs-MD/3pairs/1bands/*_sm.cc results/RBs-MD/3pairs/1bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/3pairs/2bands/*_m.cc results/RBs-MD/3pairs/2bands/*_m.h results/RBs-MD/3pairs/2bands/*_sm.cc results/RBs-MD/3pairs/2bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/3pairs/3bands/*_m.cc results/RBs-MD/3pairs/3bands/*_m.h results/RBs-MD/3pairs/3bands/*_sm.cc results/RBs-MD/3pairs/3bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/3pairs/4bands/*_m.cc results/RBs-MD/3pairs/4bands/*_m.h results/RBs-MD/3pairs/4bands/*_sm.cc results/RBs-MD/3pairs/4bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/3pairs/5bands/*_m.cc results/RBs-MD/3pairs/5bands/*_m.h results/RBs-MD/3pairs/5bands/*_sm.cc results/RBs-MD/3pairs/5bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/3pairs/6bands/*_m.cc results/RBs-MD/3pairs/6bands/*_m.h results/RBs-MD/3pairs/6bands/*_sm.cc results/RBs-MD/3pairs/6bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/3pairs/7bands/*_m.cc results/RBs-MD/3pairs/7bands/*_m.h results/RBs-MD/3pairs/7bands/*_sm.cc results/RBs-MD/3pairs/7bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/3pairs/8bands/*_m.cc results/RBs-MD/3pairs/8bands/*_m.h results/RBs-MD/3pairs/8bands/*_sm.cc results/RBs-MD/3pairs/8bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/3pairs/9bands/*_m.cc results/RBs-MD/3pairs/9bands/*_m.h results/RBs-MD/3pairs/9bands/*_sm.cc results/RBs-MD/3pairs/9bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/4pairs/*_m.cc results/RBs-MD/4pairs/*_m.h results/RBs-MD/4pairs/*_sm.cc results/RBs-MD/4pairs/*_sm.h
	$(Q)-rm -f results/RBs-MD/4pairs/10bands/*_m.cc results/RBs-MD/4pairs/10bands/*_m.h results/RBs-MD/4pairs/10bands/*_sm.cc results/RBs-MD/4pairs/10bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/4pairs/1bands/*_m.cc results/RBs-MD/4pairs/1bands/*_m.h results/RBs-MD/4pairs/1bands/*_sm.cc results/RBs-MD/4pairs/1bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/4pairs/2bands/*_m.cc results/RBs-MD/4pairs/2bands/*_m.h results/RBs-MD/4pairs/2bands/*_sm.cc results/RBs-MD/4pairs/2bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/4pairs/3bands/*_m.cc results/RBs-MD/4pairs/3bands/*_m.h results/RBs-MD/4pairs/3bands/*_sm.cc results/RBs-MD/4pairs/3bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/4pairs/4bands/*_m.cc results/RBs-MD/4pairs/4bands/*_m.h results/RBs-MD/4pairs/4bands/*_sm.cc results/RBs-MD/4pairs/4bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/4pairs/5bands/*_m.cc results/RBs-MD/4pairs/5bands/*_m.h results/RBs-MD/4pairs/5bands/*_sm.cc results/RBs-MD/4pairs/5bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/4pairs/6bands/*_m.cc results/RBs-MD/4pairs/6bands/*_m.h results/RBs-MD/4pairs/6bands/*_sm.cc results/RBs-MD/4pairs/6bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/4pairs/7bands/*_m.cc results/RBs-MD/4pairs/7bands/*_m.h results/RBs-MD/4pairs/7bands/*_sm.cc results/RBs-MD/4pairs/7bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/4pairs/8bands/*_m.cc results/RBs-MD/4pairs/8bands/*_m.h results/RBs-MD/4pairs/8bands/*_sm.cc results/RBs-MD/4pairs/8bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/4pairs/9bands/*_m.cc results/RBs-MD/4pairs/9bands/*_m.h results/RBs-MD/4pairs/9bands/*_sm.cc results/RBs-MD/4pairs/9bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/5pairs/*_m.cc results/RBs-MD/5pairs/*_m.h results/RBs-MD/5pairs/*_sm.cc results/RBs-MD/5pairs/*_sm.h
	$(Q)-rm -f results/RBs-MD/5pairs/10bands/*_m.cc results/RBs-MD/5pairs/10bands/*_m.h results/RBs-MD/5pairs/10bands/*_sm.cc results/RBs-MD/5pairs/10bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/5pairs/1bands/*_m.cc results/RBs-MD/5pairs/1bands/*_m.h results/RBs-MD/5pairs/1bands/*_sm.cc results/RBs-MD/5pairs/1bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/5pairs/2bands/*_m.cc results/RBs-MD/5pairs/2bands/*_m.h results/RBs-MD/5pairs/2bands/*_sm.cc results/RBs-MD/5pairs/2bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/5pairs/3bands/*_m.cc results/RBs-MD/5pairs/3bands/*_m.h results/RBs-MD/5pairs/3bands/*_sm.cc results/RBs-MD/5pairs/3bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/5pairs/4bands/*_m.cc results/RBs-MD/5pairs/4bands/*_m.h results/RBs-MD/5pairs/4bands/*_sm.cc results/RBs-MD/5pairs/4bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/5pairs/5bands/*_m.cc results/RBs-MD/5pairs/5bands/*_m.h results/RBs-MD/5pairs/5bands/*_sm.cc results/RBs-MD/5pairs/5bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/5pairs/6bands/*_m.cc results/RBs-MD/5pairs/6bands/*_m.h results/RBs-MD/5pairs/6bands/*_sm.cc results/RBs-MD/5pairs/6bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/5pairs/7bands/*_m.cc results/RBs-MD/5pairs/7bands/*_m.h results/RBs-MD/5pairs/7bands/*_sm.cc results/RBs-MD/5pairs/7bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/5pairs/8bands/*_m.cc results/RBs-MD/5pairs/8bands/*_m.h results/RBs-MD/5pairs/8bands/*_sm.cc results/RBs-MD/5pairs/8bands/*_sm.h
	$(Q)-rm -f results/RBs-MD/5pairs/9bands/*_m.cc results/RBs-MD/5pairs/9bands/*_m.h results/RBs-MD/5pairs/9bands/*_sm.cc results/RBs-MD/5pairs/9bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/*_m.cc results/RBs-MD-in-circle/*_m.h results/RBs-MD-in-circle/*_sm.cc results/RBs-MD-in-circle/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/1pairs/*_m.cc results/RBs-MD-in-circle/1pairs/*_m.h results/RBs-MD-in-circle/1pairs/*_sm.cc results/RBs-MD-in-circle/1pairs/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/1pairs/10bands/*_m.cc results/RBs-MD-in-circle/1pairs/10bands/*_m.h results/RBs-MD-in-circle/1pairs/10bands/*_sm.cc results/RBs-MD-in-circle/1pairs/10bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/1pairs/1bands/*_m.cc results/RBs-MD-in-circle/1pairs/1bands/*_m.h results/RBs-MD-in-circle/1pairs/1bands/*_sm.cc results/RBs-MD-in-circle/1pairs/1bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/1pairs/2bands/*_m.cc results/RBs-MD-in-circle/1pairs/2bands/*_m.h results/RBs-MD-in-circle/1pairs/2bands/*_sm.cc results/RBs-MD-in-circle/1pairs/2bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/1pairs/3bands/*_m.cc results/RBs-MD-in-circle/1pairs/3bands/*_m.h results/RBs-MD-in-circle/1pairs/3bands/*_sm.cc results/RBs-MD-in-circle/1pairs/3bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/1pairs/4bands/*_m.cc results/RBs-MD-in-circle/1pairs/4bands/*_m.h results/RBs-MD-in-circle/1pairs/4bands/*_sm.cc results/RBs-MD-in-circle/1pairs/4bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/1pairs/5bands/*_m.cc results/RBs-MD-in-circle/1pairs/5bands/*_m.h results/RBs-MD-in-circle/1pairs/5bands/*_sm.cc results/RBs-MD-in-circle/1pairs/5bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/1pairs/6bands/*_m.cc results/RBs-MD-in-circle/1pairs/6bands/*_m.h results/RBs-MD-in-circle/1pairs/6bands/*_sm.cc results/RBs-MD-in-circle/1pairs/6bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/1pairs/7bands/*_m.cc results/RBs-MD-in-circle/1pairs/7bands/*_m.h results/RBs-MD-in-circle/1pairs/7bands/*_sm.cc results/RBs-MD-in-circle/1pairs/7bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/1pairs/8bands/*_m.cc results/RBs-MD-in-circle/1pairs/8bands/*_m.h results/RBs-MD-in-circle/1pairs/8bands/*_sm.cc results/RBs-MD-in-circle/1pairs/8bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/1pairs/9bands/*_m.cc results/RBs-MD-in-circle/1pairs/9bands/*_m.h results/RBs-MD-in-circle/1pairs/9bands/*_sm.cc results/RBs-MD-in-circle/1pairs/9bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/2pairs/*_m.cc results/RBs-MD-in-circle/2pairs/*_m.h results/RBs-MD-in-circle/2pairs/*_sm.cc results/RBs-MD-in-circle/2pairs/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/2pairs/10bands/*_m.cc results/RBs-MD-in-circle/2pairs/10bands/*_m.h results/RBs-MD-in-circle/2pairs/10bands/*_sm.cc results/RBs-MD-in-circle/2pairs/10bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/2pairs/1bands/*_m.cc results/RBs-MD-in-circle/2pairs/1bands/*_m.h results/RBs-MD-in-circle/2pairs/1bands/*_sm.cc results/RBs-MD-in-circle/2pairs/1bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/2pairs/2bands/*_m.cc results/RBs-MD-in-circle/2pairs/2bands/*_m.h results/RBs-MD-in-circle/2pairs/2bands/*_sm.cc results/RBs-MD-in-circle/2pairs/2bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/2pairs/3bands/*_m.cc results/RBs-MD-in-circle/2pairs/3bands/*_m.h results/RBs-MD-in-circle/2pairs/3bands/*_sm.cc results/RBs-MD-in-circle/2pairs/3bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/2pairs/4bands/*_m.cc results/RBs-MD-in-circle/2pairs/4bands/*_m.h results/RBs-MD-in-circle/2pairs/4bands/*_sm.cc results/RBs-MD-in-circle/2pairs/4bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/2pairs/5bands/*_m.cc results/RBs-MD-in-circle/2pairs/5bands/*_m.h results/RBs-MD-in-circle/2pairs/5bands/*_sm.cc results/RBs-MD-in-circle/2pairs/5bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/2pairs/6bands/*_m.cc results/RBs-MD-in-circle/2pairs/6bands/*_m.h results/RBs-MD-in-circle/2pairs/6bands/*_sm.cc results/RBs-MD-in-circle/2pairs/6bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/2pairs/7bands/*_m.cc results/RBs-MD-in-circle/2pairs/7bands/*_m.h results/RBs-MD-in-circle/2pairs/7bands/*_sm.cc results/RBs-MD-in-circle/2pairs/7bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/2pairs/8bands/*_m.cc results/RBs-MD-in-circle/2pairs/8bands/*_m.h results/RBs-MD-in-circle/2pairs/8bands/*_sm.cc results/RBs-MD-in-circle/2pairs/8bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/2pairs/9bands/*_m.cc results/RBs-MD-in-circle/2pairs/9bands/*_m.h results/RBs-MD-in-circle/2pairs/9bands/*_sm.cc results/RBs-MD-in-circle/2pairs/9bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/3pairs/*_m.cc results/RBs-MD-in-circle/3pairs/*_m.h results/RBs-MD-in-circle/3pairs/*_sm.cc results/RBs-MD-in-circle/3pairs/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/3pairs/10bands/*_m.cc results/RBs-MD-in-circle/3pairs/10bands/*_m.h results/RBs-MD-in-circle/3pairs/10bands/*_sm.cc results/RBs-MD-in-circle/3pairs/10bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/3pairs/1bands/*_m.cc results/RBs-MD-in-circle/3pairs/1bands/*_m.h results/RBs-MD-in-circle/3pairs/1bands/*_sm.cc results/RBs-MD-in-circle/3pairs/1bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/3pairs/2bands/*_m.cc results/RBs-MD-in-circle/3pairs/2bands/*_m.h results/RBs-MD-in-circle/3pairs/2bands/*_sm.cc results/RBs-MD-in-circle/3pairs/2bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/3pairs/3bands/*_m.cc results/RBs-MD-in-circle/3pairs/3bands/*_m.h results/RBs-MD-in-circle/3pairs/3bands/*_sm.cc results/RBs-MD-in-circle/3pairs/3bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/3pairs/4bands/*_m.cc results/RBs-MD-in-circle/3pairs/4bands/*_m.h results/RBs-MD-in-circle/3pairs/4bands/*_sm.cc results/RBs-MD-in-circle/3pairs/4bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/3pairs/5bands/*_m.cc results/RBs-MD-in-circle/3pairs/5bands/*_m.h results/RBs-MD-in-circle/3pairs/5bands/*_sm.cc results/RBs-MD-in-circle/3pairs/5bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/3pairs/6bands/*_m.cc results/RBs-MD-in-circle/3pairs/6bands/*_m.h results/RBs-MD-in-circle/3pairs/6bands/*_sm.cc results/RBs-MD-in-circle/3pairs/6bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/3pairs/7bands/*_m.cc results/RBs-MD-in-circle/3pairs/7bands/*_m.h results/RBs-MD-in-circle/3pairs/7bands/*_sm.cc results/RBs-MD-in-circle/3pairs/7bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/3pairs/8bands/*_m.cc results/RBs-MD-in-circle/3pairs/8bands/*_m.h results/RBs-MD-in-circle/3pairs/8bands/*_sm.cc results/RBs-MD-in-circle/3pairs/8bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/3pairs/9bands/*_m.cc results/RBs-MD-in-circle/3pairs/9bands/*_m.h results/RBs-MD-in-circle/3pairs/9bands/*_sm.cc results/RBs-MD-in-circle/3pairs/9bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/4pairs/*_m.cc results/RBs-MD-in-circle/4pairs/*_m.h results/RBs-MD-in-circle/4pairs/*_sm.cc results/RBs-MD-in-circle/4pairs/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/4pairs/10bands/*_m.cc results/RBs-MD-in-circle/4pairs/10bands/*_m.h results/RBs-MD-in-circle/4pairs/10bands/*_sm.cc results/RBs-MD-in-circle/4pairs/10bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/4pairs/1bands/*_m.cc results/RBs-MD-in-circle/4pairs/1bands/*_m.h results/RBs-MD-in-circle/4pairs/1bands/*_sm.cc results/RBs-MD-in-circle/4pairs/1bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/4pairs/2bands/*_m.cc results/RBs-MD-in-circle/4pairs/2bands/*_m.h results/RBs-MD-in-circle/4pairs/2bands/*_sm.cc results/RBs-MD-in-circle/4pairs/2bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/4pairs/3bands/*_m.cc results/RBs-MD-in-circle/4pairs/3bands/*_m.h results/RBs-MD-in-circle/4pairs/3bands/*_sm.cc results/RBs-MD-in-circle/4pairs/3bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/4pairs/4bands/*_m.cc results/RBs-MD-in-circle/4pairs/4bands/*_m.h results/RBs-MD-in-circle/4pairs/4bands/*_sm.cc results/RBs-MD-in-circle/4pairs/4bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/4pairs/5bands/*_m.cc results/RBs-MD-in-circle/4pairs/5bands/*_m.h results/RBs-MD-in-circle/4pairs/5bands/*_sm.cc results/RBs-MD-in-circle/4pairs/5bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/4pairs/6bands/*_m.cc results/RBs-MD-in-circle/4pairs/6bands/*_m.h results/RBs-MD-in-circle/4pairs/6bands/*_sm.cc results/RBs-MD-in-circle/4pairs/6bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/4pairs/7bands/*_m.cc results/RBs-MD-in-circle/4pairs/7bands/*_m.h results/RBs-MD-in-circle/4pairs/7bands/*_sm.cc results/RBs-MD-in-circle/4pairs/7bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/4pairs/8bands/*_m.cc results/RBs-MD-in-circle/4pairs/8bands/*_m.h results/RBs-MD-in-circle/4pairs/8bands/*_sm.cc results/RBs-MD-in-circle/4pairs/8bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/4pairs/9bands/*_m.cc results/RBs-MD-in-circle/4pairs/9bands/*_m.h results/RBs-MD-in-circle/4pairs/9bands/*_sm.cc results/RBs-MD-in-circle/4pairs/9bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/5pairs/*_m.cc results/RBs-MD-in-circle/5pairs/*_m.h results/RBs-MD-in-circle/5pairs/*_sm.cc results/RBs-MD-in-circle/5pairs/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/5pairs/10bands/*_m.cc results/RBs-MD-in-circle/5pairs/10bands/*_m.h results/RBs-MD-in-circle/5pairs/10bands/*_sm.cc results/RBs-MD-in-circle/5pairs/10bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/5pairs/1bands/*_m.cc results/RBs-MD-in-circle/5pairs/1bands/*_m.h results/RBs-MD-in-circle/5pairs/1bands/*_sm.cc results/RBs-MD-in-circle/5pairs/1bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/5pairs/2bands/*_m.cc results/RBs-MD-in-circle/5pairs/2bands/*_m.h results/RBs-MD-in-circle/5pairs/2bands/*_sm.cc results/RBs-MD-in-circle/5pairs/2bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/5pairs/3bands/*_m.cc results/RBs-MD-in-circle/5pairs/3bands/*_m.h results/RBs-MD-in-circle/5pairs/3bands/*_sm.cc results/RBs-MD-in-circle/5pairs/3bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/5pairs/4bands/*_m.cc results/RBs-MD-in-circle/5pairs/4bands/*_m.h results/RBs-MD-in-circle/5pairs/4bands/*_sm.cc results/RBs-MD-in-circle/5pairs/4bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/5pairs/5bands/*_m.cc results/RBs-MD-in-circle/5pairs/5bands/*_m.h results/RBs-MD-in-circle/5pairs/5bands/*_sm.cc results/RBs-MD-in-circle/5pairs/5bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/5pairs/6bands/*_m.cc results/RBs-MD-in-circle/5pairs/6bands/*_m.h results/RBs-MD-in-circle/5pairs/6bands/*_sm.cc results/RBs-MD-in-circle/5pairs/6bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/5pairs/7bands/*_m.cc results/RBs-MD-in-circle/5pairs/7bands/*_m.h results/RBs-MD-in-circle/5pairs/7bands/*_sm.cc results/RBs-MD-in-circle/5pairs/7bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/5pairs/8bands/*_m.cc results/RBs-MD-in-circle/5pairs/8bands/*_m.h results/RBs-MD-in-circle/5pairs/8bands/*_sm.cc results/RBs-MD-in-circle/5pairs/8bands/*_sm.h
	$(Q)-rm -f results/RBs-MD-in-circle/5pairs/9bands/*_m.cc results/RBs-MD-in-circle/5pairs/9bands/*_m.h results/RBs-MD-in-circle/5pairs/9bands/*_sm.cc results/RBs-MD-in-circle/5pairs/9bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/*_m.cc results/RBs-in-circle/*_m.h results/RBs-in-circle/*_sm.cc results/RBs-in-circle/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/1pairs/*_m.cc results/RBs-in-circle/1pairs/*_m.h results/RBs-in-circle/1pairs/*_sm.cc results/RBs-in-circle/1pairs/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/1pairs/10bands/*_m.cc results/RBs-in-circle/1pairs/10bands/*_m.h results/RBs-in-circle/1pairs/10bands/*_sm.cc results/RBs-in-circle/1pairs/10bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/1pairs/1bands/*_m.cc results/RBs-in-circle/1pairs/1bands/*_m.h results/RBs-in-circle/1pairs/1bands/*_sm.cc results/RBs-in-circle/1pairs/1bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/1pairs/2bands/*_m.cc results/RBs-in-circle/1pairs/2bands/*_m.h results/RBs-in-circle/1pairs/2bands/*_sm.cc results/RBs-in-circle/1pairs/2bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/1pairs/3bands/*_m.cc results/RBs-in-circle/1pairs/3bands/*_m.h results/RBs-in-circle/1pairs/3bands/*_sm.cc results/RBs-in-circle/1pairs/3bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/1pairs/4bands/*_m.cc results/RBs-in-circle/1pairs/4bands/*_m.h results/RBs-in-circle/1pairs/4bands/*_sm.cc results/RBs-in-circle/1pairs/4bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/1pairs/5bands/*_m.cc results/RBs-in-circle/1pairs/5bands/*_m.h results/RBs-in-circle/1pairs/5bands/*_sm.cc results/RBs-in-circle/1pairs/5bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/1pairs/6bands/*_m.cc results/RBs-in-circle/1pairs/6bands/*_m.h results/RBs-in-circle/1pairs/6bands/*_sm.cc results/RBs-in-circle/1pairs/6bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/1pairs/7bands/*_m.cc results/RBs-in-circle/1pairs/7bands/*_m.h results/RBs-in-circle/1pairs/7bands/*_sm.cc results/RBs-in-circle/1pairs/7bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/1pairs/8bands/*_m.cc results/RBs-in-circle/1pairs/8bands/*_m.h results/RBs-in-circle/1pairs/8bands/*_sm.cc results/RBs-in-circle/1pairs/8bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/1pairs/9bands/*_m.cc results/RBs-in-circle/1pairs/9bands/*_m.h results/RBs-in-circle/1pairs/9bands/*_sm.cc results/RBs-in-circle/1pairs/9bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/2pairs/*_m.cc results/RBs-in-circle/2pairs/*_m.h results/RBs-in-circle/2pairs/*_sm.cc results/RBs-in-circle/2pairs/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/2pairs/10bands/*_m.cc results/RBs-in-circle/2pairs/10bands/*_m.h results/RBs-in-circle/2pairs/10bands/*_sm.cc results/RBs-in-circle/2pairs/10bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/2pairs/1bands/*_m.cc results/RBs-in-circle/2pairs/1bands/*_m.h results/RBs-in-circle/2pairs/1bands/*_sm.cc results/RBs-in-circle/2pairs/1bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/2pairs/2bands/*_m.cc results/RBs-in-circle/2pairs/2bands/*_m.h results/RBs-in-circle/2pairs/2bands/*_sm.cc results/RBs-in-circle/2pairs/2bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/2pairs/3bands/*_m.cc results/RBs-in-circle/2pairs/3bands/*_m.h results/RBs-in-circle/2pairs/3bands/*_sm.cc results/RBs-in-circle/2pairs/3bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/2pairs/4bands/*_m.cc results/RBs-in-circle/2pairs/4bands/*_m.h results/RBs-in-circle/2pairs/4bands/*_sm.cc results/RBs-in-circle/2pairs/4bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/2pairs/5bands/*_m.cc results/RBs-in-circle/2pairs/5bands/*_m.h results/RBs-in-circle/2pairs/5bands/*_sm.cc results/RBs-in-circle/2pairs/5bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/2pairs/6bands/*_m.cc results/RBs-in-circle/2pairs/6bands/*_m.h results/RBs-in-circle/2pairs/6bands/*_sm.cc results/RBs-in-circle/2pairs/6bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/2pairs/7bands/*_m.cc results/RBs-in-circle/2pairs/7bands/*_m.h results/RBs-in-circle/2pairs/7bands/*_sm.cc results/RBs-in-circle/2pairs/7bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/2pairs/8bands/*_m.cc results/RBs-in-circle/2pairs/8bands/*_m.h results/RBs-in-circle/2pairs/8bands/*_sm.cc results/RBs-in-circle/2pairs/8bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/2pairs/9bands/*_m.cc results/RBs-in-circle/2pairs/9bands/*_m.h results/RBs-in-circle/2pairs/9bands/*_sm.cc results/RBs-in-circle/2pairs/9bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/3pairs/*_m.cc results/RBs-in-circle/3pairs/*_m.h results/RBs-in-circle/3pairs/*_sm.cc results/RBs-in-circle/3pairs/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/3pairs/10bands/*_m.cc results/RBs-in-circle/3pairs/10bands/*_m.h results/RBs-in-circle/3pairs/10bands/*_sm.cc results/RBs-in-circle/3pairs/10bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/3pairs/1bands/*_m.cc results/RBs-in-circle/3pairs/1bands/*_m.h results/RBs-in-circle/3pairs/1bands/*_sm.cc results/RBs-in-circle/3pairs/1bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/3pairs/2bands/*_m.cc results/RBs-in-circle/3pairs/2bands/*_m.h results/RBs-in-circle/3pairs/2bands/*_sm.cc results/RBs-in-circle/3pairs/2bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/3pairs/3bands/*_m.cc results/RBs-in-circle/3pairs/3bands/*_m.h results/RBs-in-circle/3pairs/3bands/*_sm.cc results/RBs-in-circle/3pairs/3bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/3pairs/4bands/*_m.cc results/RBs-in-circle/3pairs/4bands/*_m.h results/RBs-in-circle/3pairs/4bands/*_sm.cc results/RBs-in-circle/3pairs/4bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/3pairs/5bands/*_m.cc results/RBs-in-circle/3pairs/5bands/*_m.h results/RBs-in-circle/3pairs/5bands/*_sm.cc results/RBs-in-circle/3pairs/5bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/3pairs/6bands/*_m.cc results/RBs-in-circle/3pairs/6bands/*_m.h results/RBs-in-circle/3pairs/6bands/*_sm.cc results/RBs-in-circle/3pairs/6bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/3pairs/7bands/*_m.cc results/RBs-in-circle/3pairs/7bands/*_m.h results/RBs-in-circle/3pairs/7bands/*_sm.cc results/RBs-in-circle/3pairs/7bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/3pairs/8bands/*_m.cc results/RBs-in-circle/3pairs/8bands/*_m.h results/RBs-in-circle/3pairs/8bands/*_sm.cc results/RBs-in-circle/3pairs/8bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/3pairs/9bands/*_m.cc results/RBs-in-circle/3pairs/9bands/*_m.h results/RBs-in-circle/3pairs/9bands/*_sm.cc results/RBs-in-circle/3pairs/9bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/4pairs/*_m.cc results/RBs-in-circle/4pairs/*_m.h results/RBs-in-circle/4pairs/*_sm.cc results/RBs-in-circle/4pairs/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/4pairs/10bands/*_m.cc results/RBs-in-circle/4pairs/10bands/*_m.h results/RBs-in-circle/4pairs/10bands/*_sm.cc results/RBs-in-circle/4pairs/10bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/4pairs/1bands/*_m.cc results/RBs-in-circle/4pairs/1bands/*_m.h results/RBs-in-circle/4pairs/1bands/*_sm.cc results/RBs-in-circle/4pairs/1bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/4pairs/2bands/*_m.cc results/RBs-in-circle/4pairs/2bands/*_m.h results/RBs-in-circle/4pairs/2bands/*_sm.cc results/RBs-in-circle/4pairs/2bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/4pairs/3bands/*_m.cc results/RBs-in-circle/4pairs/3bands/*_m.h results/RBs-in-circle/4pairs/3bands/*_sm.cc results/RBs-in-circle/4pairs/3bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/4pairs/4bands/*_m.cc results/RBs-in-circle/4pairs/4bands/*_m.h results/RBs-in-circle/4pairs/4bands/*_sm.cc results/RBs-in-circle/4pairs/4bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/4pairs/5bands/*_m.cc results/RBs-in-circle/4pairs/5bands/*_m.h results/RBs-in-circle/4pairs/5bands/*_sm.cc results/RBs-in-circle/4pairs/5bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/4pairs/6bands/*_m.cc results/RBs-in-circle/4pairs/6bands/*_m.h results/RBs-in-circle/4pairs/6bands/*_sm.cc results/RBs-in-circle/4pairs/6bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/4pairs/7bands/*_m.cc results/RBs-in-circle/4pairs/7bands/*_m.h results/RBs-in-circle/4pairs/7bands/*_sm.cc results/RBs-in-circle/4pairs/7bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/4pairs/8bands/*_m.cc results/RBs-in-circle/4pairs/8bands/*_m.h results/RBs-in-circle/4pairs/8bands/*_sm.cc results/RBs-in-circle/4pairs/8bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/4pairs/9bands/*_m.cc results/RBs-in-circle/4pairs/9bands/*_m.h results/RBs-in-circle/4pairs/9bands/*_sm.cc results/RBs-in-circle/4pairs/9bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/5pairs/*_m.cc results/RBs-in-circle/5pairs/*_m.h results/RBs-in-circle/5pairs/*_sm.cc results/RBs-in-circle/5pairs/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/5pairs/10bands/*_m.cc results/RBs-in-circle/5pairs/10bands/*_m.h results/RBs-in-circle/5pairs/10bands/*_sm.cc results/RBs-in-circle/5pairs/10bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/5pairs/1bands/*_m.cc results/RBs-in-circle/5pairs/1bands/*_m.h results/RBs-in-circle/5pairs/1bands/*_sm.cc results/RBs-in-circle/5pairs/1bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/5pairs/2bands/*_m.cc results/RBs-in-circle/5pairs/2bands/*_m.h results/RBs-in-circle/5pairs/2bands/*_sm.cc results/RBs-in-circle/5pairs/2bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/5pairs/3bands/*_m.cc results/RBs-in-circle/5pairs/3bands/*_m.h results/RBs-in-circle/5pairs/3bands/*_sm.cc results/RBs-in-circle/5pairs/3bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/5pairs/4bands/*_m.cc results/RBs-in-circle/5pairs/4bands/*_m.h results/RBs-in-circle/5pairs/4bands/*_sm.cc results/RBs-in-circle/5pairs/4bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/5pairs/5bands/*_m.cc results/RBs-in-circle/5pairs/5bands/*_m.h results/RBs-in-circle/5pairs/5bands/*_sm.cc results/RBs-in-circle/5pairs/5bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/5pairs/6bands/*_m.cc results/RBs-in-circle/5pairs/6bands/*_m.h results/RBs-in-circle/5pairs/6bands/*_sm.cc results/RBs-in-circle/5pairs/6bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/5pairs/7bands/*_m.cc results/RBs-in-circle/5pairs/7bands/*_m.h results/RBs-in-circle/5pairs/7bands/*_sm.cc results/RBs-in-circle/5pairs/7bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/5pairs/8bands/*_m.cc results/RBs-in-circle/5pairs/8bands/*_m.h results/RBs-in-circle/5pairs/8bands/*_sm.cc results/RBs-in-circle/5pairs/8bands/*_sm.h
	$(Q)-rm -f results/RBs-in-circle/5pairs/9bands/*_m.cc results/RBs-in-circle/5pairs/9bands/*_m.h results/RBs-in-circle/5pairs/9bands/*_sm.cc results/RBs-in-circle/5pairs/9bands/*_sm.h
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
	$(Q)$(MAKEDEPEND) $(INCLUDE_PATH) -f Makefile -P\$$O/ -- $(MSG_CC_FILES) $(SM_CC_FILES)  ./*.cc configs/*.cc evaluation/*.cc evaluation/bandeffect/*.cc evaluation/mode-selection/*.cc evaluation/mode-selection/test/*.cc evaluation/parameter-study_pairs-bands-rbs/*.cc results/*.cc results/BandEffect-D2D-1RB-DRR/*.cc results/BandEffect-D2D-1RB-DRR/10bands/*.cc results/BandEffect-D2D-1RB-DRR/1bands/*.cc results/BandEffect-D2D-1RB-DRR/2bands/*.cc results/BandEffect-D2D-1RB-DRR/3bands/*.cc results/BandEffect-D2D-1RB-DRR/4bands/*.cc results/BandEffect-D2D-1RB-DRR/5bands/*.cc results/BandEffect-D2D-1RB-DRR/6bands/*.cc results/BandEffect-D2D-1RB-DRR/7bands/*.cc results/BandEffect-D2D-1RB-DRR/8bands/*.cc results/BandEffect-D2D-1RB-DRR/9bands/*.cc results/BandEffect-D2D-1RB-MD/*.cc results/BandEffect-D2D-1RB-MD/10bands/*.cc results/BandEffect-D2D-1RB-MD/1bands/*.cc results/BandEffect-D2D-1RB-MD/2bands/*.cc results/BandEffect-D2D-1RB-MD/3bands/*.cc results/BandEffect-D2D-1RB-MD/4bands/*.cc results/BandEffect-D2D-1RB-MD/5bands/*.cc results/BandEffect-D2D-1RB-MD/6bands/*.cc results/BandEffect-D2D-1RB-MD/7bands/*.cc results/BandEffect-D2D-1RB-MD/8bands/*.cc results/BandEffect-D2D-1RB-MD/9bands/*.cc results/BandEffect-D2D-50RB-MD/*.cc results/BandEffect-D2D-50RB-MD/10bands/*.cc results/BandEffect-D2D-50RB-MD/1bands/*.cc results/BandEffect-D2D-50RB-MD/2bands/*.cc results/BandEffect-D2D-50RB-MD/3bands/*.cc results/BandEffect-D2D-50RB-MD/4bands/*.cc results/BandEffect-D2D-50RB-MD/5bands/*.cc results/BandEffect-D2D-50RB-MD/6bands/*.cc results/BandEffect-D2D-50RB-MD/7bands/*.cc results/BandEffect-D2D-50RB-MD/8bands/*.cc results/BandEffect-D2D-50RB-MD/9bands/*.cc results/RBs/*.cc results/RBs/1pairs/*.cc results/RBs/1pairs/10bands/*.cc results/RBs/1pairs/1bands/*.cc results/RBs/1pairs/2bands/*.cc results/RBs/1pairs/3bands/*.cc results/RBs/1pairs/4bands/*.cc results/RBs/1pairs/5bands/*.cc results/RBs/1pairs/6bands/*.cc results/RBs/1pairs/7bands/*.cc results/RBs/1pairs/8bands/*.cc results/RBs/1pairs/9bands/*.cc results/RBs/2pairs/*.cc results/RBs/2pairs/10bands/*.cc results/RBs/2pairs/1bands/*.cc results/RBs/2pairs/2bands/*.cc results/RBs/2pairs/3bands/*.cc results/RBs/2pairs/4bands/*.cc results/RBs/2pairs/5bands/*.cc results/RBs/2pairs/6bands/*.cc results/RBs/2pairs/7bands/*.cc results/RBs/2pairs/8bands/*.cc results/RBs/2pairs/9bands/*.cc results/RBs/3pairs/*.cc results/RBs/3pairs/10bands/*.cc results/RBs/3pairs/1bands/*.cc results/RBs/3pairs/2bands/*.cc results/RBs/3pairs/3bands/*.cc results/RBs/3pairs/4bands/*.cc results/RBs/3pairs/5bands/*.cc results/RBs/3pairs/6bands/*.cc results/RBs/3pairs/7bands/*.cc results/RBs/3pairs/8bands/*.cc results/RBs/3pairs/9bands/*.cc results/RBs/4pairs/*.cc results/RBs/4pairs/10bands/*.cc results/RBs/4pairs/1bands/*.cc results/RBs/4pairs/2bands/*.cc results/RBs/4pairs/3bands/*.cc results/RBs/4pairs/4bands/*.cc results/RBs/4pairs/5bands/*.cc results/RBs/4pairs/6bands/*.cc results/RBs/4pairs/7bands/*.cc results/RBs/4pairs/8bands/*.cc results/RBs/4pairs/9bands/*.cc results/RBs/5pairs/*.cc results/RBs/5pairs/10bands/*.cc results/RBs/5pairs/1bands/*.cc results/RBs/5pairs/2bands/*.cc results/RBs/5pairs/3bands/*.cc results/RBs/5pairs/4bands/*.cc results/RBs/5pairs/5bands/*.cc results/RBs/5pairs/6bands/*.cc results/RBs/5pairs/7bands/*.cc results/RBs/5pairs/8bands/*.cc results/RBs/5pairs/9bands/*.cc results/RBs-MD/*.cc results/RBs-MD/1pairs/*.cc results/RBs-MD/1pairs/10bands/*.cc results/RBs-MD/1pairs/1bands/*.cc results/RBs-MD/1pairs/2bands/*.cc results/RBs-MD/1pairs/3bands/*.cc results/RBs-MD/1pairs/4bands/*.cc results/RBs-MD/1pairs/5bands/*.cc results/RBs-MD/1pairs/6bands/*.cc results/RBs-MD/1pairs/7bands/*.cc results/RBs-MD/1pairs/8bands/*.cc results/RBs-MD/1pairs/9bands/*.cc results/RBs-MD/2pairs/*.cc results/RBs-MD/2pairs/10bands/*.cc results/RBs-MD/2pairs/1bands/*.cc results/RBs-MD/2pairs/2bands/*.cc results/RBs-MD/2pairs/3bands/*.cc results/RBs-MD/2pairs/4bands/*.cc results/RBs-MD/2pairs/5bands/*.cc results/RBs-MD/2pairs/6bands/*.cc results/RBs-MD/2pairs/7bands/*.cc results/RBs-MD/2pairs/8bands/*.cc results/RBs-MD/2pairs/9bands/*.cc results/RBs-MD/3pairs/*.cc results/RBs-MD/3pairs/10bands/*.cc results/RBs-MD/3pairs/1bands/*.cc results/RBs-MD/3pairs/2bands/*.cc results/RBs-MD/3pairs/3bands/*.cc results/RBs-MD/3pairs/4bands/*.cc results/RBs-MD/3pairs/5bands/*.cc results/RBs-MD/3pairs/6bands/*.cc results/RBs-MD/3pairs/7bands/*.cc results/RBs-MD/3pairs/8bands/*.cc results/RBs-MD/3pairs/9bands/*.cc results/RBs-MD/4pairs/*.cc results/RBs-MD/4pairs/10bands/*.cc results/RBs-MD/4pairs/1bands/*.cc results/RBs-MD/4pairs/2bands/*.cc results/RBs-MD/4pairs/3bands/*.cc results/RBs-MD/4pairs/4bands/*.cc results/RBs-MD/4pairs/5bands/*.cc results/RBs-MD/4pairs/6bands/*.cc results/RBs-MD/4pairs/7bands/*.cc results/RBs-MD/4pairs/8bands/*.cc results/RBs-MD/4pairs/9bands/*.cc results/RBs-MD/5pairs/*.cc results/RBs-MD/5pairs/10bands/*.cc results/RBs-MD/5pairs/1bands/*.cc results/RBs-MD/5pairs/2bands/*.cc results/RBs-MD/5pairs/3bands/*.cc results/RBs-MD/5pairs/4bands/*.cc results/RBs-MD/5pairs/5bands/*.cc results/RBs-MD/5pairs/6bands/*.cc results/RBs-MD/5pairs/7bands/*.cc results/RBs-MD/5pairs/8bands/*.cc results/RBs-MD/5pairs/9bands/*.cc results/RBs-MD-in-circle/*.cc results/RBs-MD-in-circle/1pairs/*.cc results/RBs-MD-in-circle/1pairs/10bands/*.cc results/RBs-MD-in-circle/1pairs/1bands/*.cc results/RBs-MD-in-circle/1pairs/2bands/*.cc results/RBs-MD-in-circle/1pairs/3bands/*.cc results/RBs-MD-in-circle/1pairs/4bands/*.cc results/RBs-MD-in-circle/1pairs/5bands/*.cc results/RBs-MD-in-circle/1pairs/6bands/*.cc results/RBs-MD-in-circle/1pairs/7bands/*.cc results/RBs-MD-in-circle/1pairs/8bands/*.cc results/RBs-MD-in-circle/1pairs/9bands/*.cc results/RBs-MD-in-circle/2pairs/*.cc results/RBs-MD-in-circle/2pairs/10bands/*.cc results/RBs-MD-in-circle/2pairs/1bands/*.cc results/RBs-MD-in-circle/2pairs/2bands/*.cc results/RBs-MD-in-circle/2pairs/3bands/*.cc results/RBs-MD-in-circle/2pairs/4bands/*.cc results/RBs-MD-in-circle/2pairs/5bands/*.cc results/RBs-MD-in-circle/2pairs/6bands/*.cc results/RBs-MD-in-circle/2pairs/7bands/*.cc results/RBs-MD-in-circle/2pairs/8bands/*.cc results/RBs-MD-in-circle/2pairs/9bands/*.cc results/RBs-MD-in-circle/3pairs/*.cc results/RBs-MD-in-circle/3pairs/10bands/*.cc results/RBs-MD-in-circle/3pairs/1bands/*.cc results/RBs-MD-in-circle/3pairs/2bands/*.cc results/RBs-MD-in-circle/3pairs/3bands/*.cc results/RBs-MD-in-circle/3pairs/4bands/*.cc results/RBs-MD-in-circle/3pairs/5bands/*.cc results/RBs-MD-in-circle/3pairs/6bands/*.cc results/RBs-MD-in-circle/3pairs/7bands/*.cc results/RBs-MD-in-circle/3pairs/8bands/*.cc results/RBs-MD-in-circle/3pairs/9bands/*.cc results/RBs-MD-in-circle/4pairs/*.cc results/RBs-MD-in-circle/4pairs/10bands/*.cc results/RBs-MD-in-circle/4pairs/1bands/*.cc results/RBs-MD-in-circle/4pairs/2bands/*.cc results/RBs-MD-in-circle/4pairs/3bands/*.cc results/RBs-MD-in-circle/4pairs/4bands/*.cc results/RBs-MD-in-circle/4pairs/5bands/*.cc results/RBs-MD-in-circle/4pairs/6bands/*.cc results/RBs-MD-in-circle/4pairs/7bands/*.cc results/RBs-MD-in-circle/4pairs/8bands/*.cc results/RBs-MD-in-circle/4pairs/9bands/*.cc results/RBs-MD-in-circle/5pairs/*.cc results/RBs-MD-in-circle/5pairs/10bands/*.cc results/RBs-MD-in-circle/5pairs/1bands/*.cc results/RBs-MD-in-circle/5pairs/2bands/*.cc results/RBs-MD-in-circle/5pairs/3bands/*.cc results/RBs-MD-in-circle/5pairs/4bands/*.cc results/RBs-MD-in-circle/5pairs/5bands/*.cc results/RBs-MD-in-circle/5pairs/6bands/*.cc results/RBs-MD-in-circle/5pairs/7bands/*.cc results/RBs-MD-in-circle/5pairs/8bands/*.cc results/RBs-MD-in-circle/5pairs/9bands/*.cc results/RBs-in-circle/*.cc results/RBs-in-circle/1pairs/*.cc results/RBs-in-circle/1pairs/10bands/*.cc results/RBs-in-circle/1pairs/1bands/*.cc results/RBs-in-circle/1pairs/2bands/*.cc results/RBs-in-circle/1pairs/3bands/*.cc results/RBs-in-circle/1pairs/4bands/*.cc results/RBs-in-circle/1pairs/5bands/*.cc results/RBs-in-circle/1pairs/6bands/*.cc results/RBs-in-circle/1pairs/7bands/*.cc results/RBs-in-circle/1pairs/8bands/*.cc results/RBs-in-circle/1pairs/9bands/*.cc results/RBs-in-circle/2pairs/*.cc results/RBs-in-circle/2pairs/10bands/*.cc results/RBs-in-circle/2pairs/1bands/*.cc results/RBs-in-circle/2pairs/2bands/*.cc results/RBs-in-circle/2pairs/3bands/*.cc results/RBs-in-circle/2pairs/4bands/*.cc results/RBs-in-circle/2pairs/5bands/*.cc results/RBs-in-circle/2pairs/6bands/*.cc results/RBs-in-circle/2pairs/7bands/*.cc results/RBs-in-circle/2pairs/8bands/*.cc results/RBs-in-circle/2pairs/9bands/*.cc results/RBs-in-circle/3pairs/*.cc results/RBs-in-circle/3pairs/10bands/*.cc results/RBs-in-circle/3pairs/1bands/*.cc results/RBs-in-circle/3pairs/2bands/*.cc results/RBs-in-circle/3pairs/3bands/*.cc results/RBs-in-circle/3pairs/4bands/*.cc results/RBs-in-circle/3pairs/5bands/*.cc results/RBs-in-circle/3pairs/6bands/*.cc results/RBs-in-circle/3pairs/7bands/*.cc results/RBs-in-circle/3pairs/8bands/*.cc results/RBs-in-circle/3pairs/9bands/*.cc results/RBs-in-circle/4pairs/*.cc results/RBs-in-circle/4pairs/10bands/*.cc results/RBs-in-circle/4pairs/1bands/*.cc results/RBs-in-circle/4pairs/2bands/*.cc results/RBs-in-circle/4pairs/3bands/*.cc results/RBs-in-circle/4pairs/4bands/*.cc results/RBs-in-circle/4pairs/5bands/*.cc results/RBs-in-circle/4pairs/6bands/*.cc results/RBs-in-circle/4pairs/7bands/*.cc results/RBs-in-circle/4pairs/8bands/*.cc results/RBs-in-circle/4pairs/9bands/*.cc results/RBs-in-circle/5pairs/*.cc results/RBs-in-circle/5pairs/10bands/*.cc results/RBs-in-circle/5pairs/1bands/*.cc results/RBs-in-circle/5pairs/2bands/*.cc results/RBs-in-circle/5pairs/3bands/*.cc results/RBs-in-circle/5pairs/4bands/*.cc results/RBs-in-circle/5pairs/5bands/*.cc results/RBs-in-circle/5pairs/6bands/*.cc results/RBs-in-circle/5pairs/7bands/*.cc results/RBs-in-circle/5pairs/8bands/*.cc results/RBs-in-circle/5pairs/9bands/*.cc results/ReassignmentTest-1RBs-D2D/*.cc results/ReassignmentTest-1RBs-D2D/1pairs/*.cc results/ReassignmentTest-1RBs-D2D/2pairs/*.cc results/ReassignmentTest-1RBs-D2D/3pairs/*.cc results/ReassignmentTest-1RBs-D2D/4pairs/*.cc results/ReassignmentTest-1RBs-D2D/5pairs/*.cc results/ReassignmentTest-1RBs-Local/*.cc results/ReassignmentTest-50RBs-D2D/*.cc results/ReassignmentTest-50RBs-D2D/1pairs/*.cc results/ReassignmentTest-50RBs-D2D/2pairs/*.cc results/ReassignmentTest-50RBs-D2D/3pairs/*.cc results/ReassignmentTest-50RBs-D2D/4pairs/*.cc results/ReassignmentTest-50RBs-D2D/5pairs/*.cc results/ReassignmentTest-50RBs-Local/*.cc results/ReassignmentTest-50RBs-Local/2pairs/*.cc results/Test-CellularFirst/*.cc results/Test-Reassignment/*.cc results/Test-SINR/*.cc results/Test-Sorting/*.cc results/Test-Sorting-D2D/*.cc

# DO NOT DELETE THIS LINE -- make depend depends on it.

