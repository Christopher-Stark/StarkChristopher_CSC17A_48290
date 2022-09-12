#!/bin/bash -x

#
# Generated - do not edit!
#

# Macros
TOP=`pwd`
CND_PLATFORM=Cygwin-Windows
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build
CND_DLIB_EXT=dll
NBTMPDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tmp-packaging
TMPDIRNAME=tmp-packaging
OUTPUT_PATH=${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/code_e_a4_sort2darraychars
OUTPUT_BASENAME=code_e_a4_sort2darraychars
PACKAGE_TOP_DIR=codeea4sort2darraychars/

# Functions
function checkReturnCode
{
    rc=$?
    if [ $rc != 0 ]
    then
        exit $rc
    fi
}
function makeDirectory
# $1 directory path
# $2 permission (optional)
{
    mkdir -p "$1"
    checkReturnCode
    if [ "$2" != "" ]
    then
      chmod $2 "$1"
      checkReturnCode
    fi
}
function copyFileToTmpDir
# $1 from-file path
# $2 to-file path
# $3 permission
{
    cp "$1" "$2"
    checkReturnCode
    if [ "$3" != "" ]
    then
        chmod $3 "$2"
        checkReturnCode
    fi
}

# Setup
cd "${TOP}"
mkdir -p ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/package
rm -rf ${NBTMPDIR}
mkdir -p ${NBTMPDIR}

# Copy files and create directories and links
cd "${TOP}"
makeDirectory "${NBTMPDIR}/codeea4sort2darraychars/bin"
copyFileToTmpDir "${OUTPUT_PATH}.exe" "${NBTMPDIR}/${PACKAGE_TOP_DIR}bin/${OUTPUT_BASENAME}.exe" 0755


# Generate tar file
cd "${TOP}"
rm -f ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/package/codeea4sort2darraychars.tar
cd ${NBTMPDIR}
tar -vcf ../../../../${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/package/codeea4sort2darraychars.tar *
checkReturnCode

# Cleanup
cd "${TOP}"
rm -rf ${NBTMPDIR}
