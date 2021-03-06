# Makefile for a very simple DLL.  Can be used to test builds

# *****************************************************************************
# Include the common base makefile
# *****************************************************************************
include ../makefile.base

# *****************************************************************************
# The Common Setup stuff
# *****************************************************************************
TARGET       := stub.dll
CXXFLAGS     += -I ${ECMD_ROOT}/ecmd-core/capi -I ${ECMD_ROOT}/ecmd-core/dll -I${SRCPATH}
VPATH        := ${VPATH}:${ECMD_ROOT}/ecmd-core/capi:${ECMD_ROOT}/ecmd-core/dll:${SRCPATH}

# *****************************************************************************
# Setup all the files going into the build
# *****************************************************************************

# The ECMD_INCLUDES are files provided by eCMD that if changed, we would want to recompile on
ECMD_INCLUDES := ecmdClientCapi.H ecmdDataBuffer.H ecmdReturnCodes.H ecmdStructs.H ecmdUtils.H ecmdClientEnums.H ecmdSharedUtils.H ecmdDefines.H

# The source files and includes in our local dirs that are going into the build
TGT_INCLUDES  := ecmdDllCapi.H
TGT_SOURCE    := ecmdDllCapi.C ecmdDllStub.C ecmdDllStubInfo.C

# Combine all the includes into one variable for the build
INCLUDES      := ${ECMD_INCLUDES} ${TGT_INCLUDES}

# Pull the sim functions out of the stub DLL
DEFINES := ${DEFINES} -DREMOVE_SIM

# *****************************************************************************
# The Main Targets
# *****************************************************************************
# The run-all rule is defined in makefile.rules
all:
	${run-all}

generate:
  # Do nothing

build: ${TARGET}
        # Remove the object after each build to force a rebuild
        # This forces the date to update
	@rm ${OBJPATH}/ecmdDllStubInfo.o

test:
  # Do nothing

install:
  # Do nothing

# *****************************************************************************
# Object Build Targets
# *****************************************************************************
TGT_SOURCE_OBJS  = $(basename ${TGT_SOURCE})
TGT_SOURCE_OBJS := $(addprefix ${OBJPATH}, ${TGT_SOURCE_OBJS})
TGT_SOURCE_OBJS := $(addsuffix .o, ${TGT_SOURCE_OBJS})

# *****************************************************************************
# Compile code for the common C++ objects if their respective
# code has been changed.  Or, compile everything if a header
# file has changed.
# *****************************************************************************
${TGT_SOURCE_OBJS}: ${OBJPATH}%.o : %.C ${INCLUDES}
	@echo Compiling $<
	${VERBOSE}${CXX} -c ${CXXFLAGS} $< -o $@ ${DEFINES}

# *****************************************************************************
# Create the Target
# *****************************************************************************
${TARGET}: ${TGT_SOURCE_OBJS}
	@echo Linking $@
	${VERBOSE}${LD} ${SLDFLAGS} -o ${OUTLIB}/${TARGET} $^ ${OUTLIB}/ecmdClientCapi.a -L${OUTLIB} -lecmd

# *****************************************************************************
# Include any global default rules
# *****************************************************************************
include ${ECMD_ROOT}/makefile.rules
