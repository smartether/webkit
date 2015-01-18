include(OptionsWindows)

add_definitions(/D_WIN32_WINNT=0x0603 /DWINVER=0x0603) # Windows 8.1

if (MSVC_CXX_ARCHITECTURE_ID STREQUAL ARM)
    # We always run in Thumb2, with NEON and VFP, because Microsoft says so:
    # http://msdn.microsoft.com/en-us/library/dn736986.aspx
	add_definitions(/DWTF_CPU_ARM_THUMB2 /DWTF_CPU_ARM_NEON /DWTF_CPU_ARM_VFP)
endif ()

set(ENABLE_LLINT_C_LOOP ON)
set(ENABLE_JIT OFF)
set(WTF_USE_ICU_UNICODE OFF)
set(WTF_USE_NLS_UNICODE ON)
