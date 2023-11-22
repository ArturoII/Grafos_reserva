#!/bin/bash -x

#
# Generated - do not edit!
#

# Macros
TOP=`pwd`
<<<<<<< HEAD
CND_PLATFORM=GNU-Linux
=======
CND_PLATFORM=None-Linux
>>>>>>> e5ee6a7a4957fa90122624a6c41006cdd29d00cf
CND_CONF=Release
CND_DISTDIR=dist
CND_BUILDDIR=build
CND_DLIB_EXT=so
NBTMPDIR=${CND_BUILDDIR}/${CND_CONF}/${CND_PLATFORM}/tmp-packaging
TMPDIRNAME=tmp-packaging
<<<<<<< HEAD
OUTPUT_PATH=${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/liblibnewton.a
OUTPUT_BASENAME=liblibnewton.a
PACKAGE_TOP_DIR=libnewton/
=======
OUTPUT_PATH=${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/libgrafos_reserva.a
OUTPUT_BASENAME=libgrafos_reserva.a
PACKAGE_TOP_DIR=Grafosreserva/
>>>>>>> e5ee6a7a4957fa90122624a6c41006cdd29d00cf

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
<<<<<<< HEAD
makeDirectory "${NBTMPDIR}/libnewton/lib"
=======
makeDirectory "${NBTMPDIR}/Grafosreserva/lib"
>>>>>>> e5ee6a7a4957fa90122624a6c41006cdd29d00cf
copyFileToTmpDir "${OUTPUT_PATH}" "${NBTMPDIR}/${PACKAGE_TOP_DIR}lib/${OUTPUT_BASENAME}" 0644


# Generate tar file
cd "${TOP}"
<<<<<<< HEAD
rm -f ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/package/libnewton.tar
cd ${NBTMPDIR}
tar -vcf ../../../../${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/package/libnewton.tar *
=======
rm -f ${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/package/Grafosreserva.tar
cd ${NBTMPDIR}
tar -vcf ../../../../${CND_DISTDIR}/${CND_CONF}/${CND_PLATFORM}/package/Grafosreserva.tar *
>>>>>>> e5ee6a7a4957fa90122624a6c41006cdd29d00cf
checkReturnCode

# Cleanup
cd "${TOP}"
rm -rf ${NBTMPDIR}
