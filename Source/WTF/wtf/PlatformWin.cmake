list(APPEND WTF_SOURCES
    threads/win/BinarySemaphoreWin.cpp
)

if (WINDOWS_STORE OR WINDOWS_PHONE)
    list(APPEND WTF_SOURCES
        win/MainThreadWinRT.cpp
        win/RunLoopWinRT.cpp
    )
else ()
    list(APPEND WTF_SOURCES
        win/MainThreadWin.cpp
        win/RunLoopWin.cpp
    )
endif ()

if (WINCE)
    list(APPEND WTF_LIBRARIES
        mmtimer
    )
elseif (NOT (WINDOWS_STORE OR WINDOWS_PHONE))
    list(APPEND WTF_LIBRARIES
        winmm
    )
endif ()

list(APPEND WTF_HEADERS
    "${DERIVED_SOURCES_WTF_DIR}/WTFHeaderDetection.h"
)

# FIXME: This should run testOSXLevel.cmd if it is available.
# https://bugs.webkit.org/show_bug.cgi?id=135861
add_custom_command(
    OUTPUT "${DERIVED_SOURCES_WTF_DIR}/WTFHeaderDetection.h"
    WORKING_DIRECTORY "${DERIVED_SOURCES_WTF_DIR}"
    COMMAND echo /* No Legible Output Support Found */ > WTFHeaderDetection.h
    VERBATIM)
