
Purpose: This file, "! mfx.sln - Projects and Build Configurations.notes.h" describes the Projects and Build Configurations in "mfx.sln".
-------------------------------------------------------------------------------------------------------------------------------------------------

    File "mfx.sln" is "Visual Studio Solution File" that contains "projects" to build each "Program" and "Library".

    Project "_SeeMore" builds programs,
    the other projects build libraries, which are standard Windows (.lib) files 
    which are linked into a program by the "_SeeMore" project.

-------------------------------------------------------------------------------------------------------------------------------------------------

"Program Edition and Build-Type"

    - Each "Program" contains different functionality and can be built in different ways.
      
    - A "Program Edition" means which functionality is in a program.

    - A "Build-Type" is how a program is built: with_checking (aka DEBUG), without_checking (aka RELEASE), compiler_optimized, etc.

    - Each "Program Edition" can be built with any "Build-Type".

    - For example:

      the "_SeeMore-CodeLibrary_Edition-with_checking.exe"    contains the "CodeLibrary" code and is a "with_checking"    build.
      the "_SeeMore-CodeLibrary_Edition-without_checking.exe" contains the "CodeLibrary" code and is a "without_checking" build.

      the "_SeeMore-CodeManager_Edition-with_checking.exe"    contains the "CodeManager" code and is a "with_checking"    build.
      the "_SeeMore-CodeManager_Edition-without_checking.exe" contains the "CodeManager" code and is a "without_checking" build.

      the "_SeeMore-Ultimate_Edition-with_checking.exe"    contains all code and is a "with_checking"    build.
      the "_SeeMore-Ultimate_Edition-without_checking.exe" contains all code and is a "without_checking" build.

    - Do not use '(' and ')' in configuration names, to avoid cmd.exe not being able to run a command.

-------------------------------------------------------------------------------------------------------------------------------------------------
20>Poker_library.Ultimate_Edition-with_checking.lib(PokerRoundDialog.obj) : warning LNK4099: PDB 'vc100.pdb' was not found 
with 'Poker_library.Ultimate_Edition-with_checking.lib(PokerRoundDialog.obj)' 
or at  'C:\mfx.temp\Ultimate_Edition-with_checking\vc100.pdb'; linking object_mfx as if no debug info
-------------------------------------------------------------------------------------------------------------------------------------------------
FIX:
Solution: Needed to link the new poker_#.lib files to the project.

Build Ultimate_Edition-with_checking

11>------ Rebuild All started: Project: poker_1, Configuration: Release Win32 ------
11>  poker_1.StdAfx.cpp

11>\mfx\MFC\Include\afxwin.h(138): error C2011: 'CSize' : 'class' type redefinition
11>          E:\Program Files (x86)\Microsoft Visual Studio 10.0\VC\atlmfc\include\atltypes.h(26) : see declaration of 'CSize'


-------------------------------------------------------------------------------------------------------------------------------------------------

"Program Editions" 
    
    - The following "Program Editions" are the basic editions:

        The "CodeLibrary"   edition contains the "SeeMore Code Library", 
                            which is the code library used by all SeeMore applications.
                            This edition is included in all other editions.
                            This edition is used by developers working on the "SeeMore Code Library",
                            it does not include other code or libraries, to minimize compile, link, and run times.

        The "Standard"      edition contains the various "Standard" Document/View types,
                            which support: text files, bitmap files, etc.
                            - These Document/View types provide basic functionality to programs,
                              which developers can use or extend in their own programs.
                            - All SeeMore users can install and use the "Standard" edition.
    --------
    
    - The following "Program Editions" contains program-specific features:

        The "Ultimate"      edition contains the features in all editions.

        The "CodeManager"   edition contains the "SeeMore Developer SDK", 
                            which contains SeeMore`s source code and software development kit (SDK).
                            - The "CodeManager" library contains the "CodeManager" edition`s code.

        The "DataBase"      edition contains Microsoft ODBC DataBase support,
                            and can access and display data in any ODBC database, with minimal coding,
                            because many features are controlled by database tables.
                            - The "mfx_database_library" library contains the "Database" edition`s code.

        The "FileShare"     edition contains file sharing support, and is implemented as the ".FileShare" Document/View file type.
                            - The "FileShare" library contains the "FileShare" edition`s code.

        The "Poker"         edition helps online poker players play better.
                            - The "Poker_library" library contains the "Poker" edition`s code.
    --------

    - The following "Program Editions" contain specialized features:

        The "Run"           edition creates "run.exe", which supports being called from a command-line program, like the Windows cmd.exe program, 
                            and being called from batch (.bat) files.
                            For example, "run.exe bell", has "run.exe" play the "bell" sound, from a batch (.bat) file.
        
        The "Sandbox"       edition contains any code a developer is currently working on, and can be modified as needed.

        The "ScreenSaver"   edition builds a screen saver program.

        The "Service"       edition builds a Windows service program.

-------------------------------------------------------------------------------------------------------------------------------------------------

    - The "Build-Type" is how a program is built.  
    - The following build types are supported:
    
        "with_checking"         - Checking code is compiled.
                                - "DEBUG" is #defined.
                                - Errors and issues are the easiest to detect and solve,
                                  but programs can run slower than in other builds.
                                - This is the normal "Build-Type" to use during program development.

                                - .sbr files are not created, to reduce build times.
                                 "C/C++, Browse Information, Enable Browse Information = No"

        
        "without_checking"      - Checking code is not compiled.
                                - "DEBUG" is not #defined, and "NDEBUG" is defined.
                                - Programs run faster than the "with_checking" version, 
                                  but errors and issues are harder detect and solve.
        
        "with_browse_info"      - Same as "with_checking", with .sbr files created.
                                - C/C++, Browse Information, Enable Browse Information = Yes (/FR)
                                - .sbr files are updated each hour, to let mfx.bsc be up-to-date.

                                - CodeLibrary-with_browse_info

        "compiler_optimized"    - Compiler optimizations are used.
                                - Programs run about 20% faster than "without_checking" builds, 
                                  but errors and issues are the hardest to solve.

        "with_profiling"        - 'Profiling' shows which parts of a program are run and how long they are run.

        "ProgramTracker"        - The ProgramTracker classes show which parts of a program are run and
                                  let the program`s function calls be tracked and displayed while the program is running.
        
-------------------------------------------------------------------------------------------------------------------------------------------------

    - The "Libraries" (.lib) Files

        - All code is placed in a library, which is compiled into a standard Windows ".lib" file,
          which can be linked into a program by the "_SeeMore" project.

    --------

    - These are the core "Libraries":

        The "mfc"                   library is the modified and extended "Microsoft Foundation Classes (MFC) Library" used by all programs.

        The
        "mfx_1", 
        "mfx_2", 
        "mfx_3", 
        "mfx_4",
        "mfx_6"                     libraries are the "CodeLibrary" edition`s code,
                                    which is the code library used by all SeeMore applications.
                                    - Multiple libraries are used to support "Multiple Processor Compiling", to reduce build times.

        The "mfx_5"                 library mostly contains various Document/View types,
                                    and does not have to be linked into every program.

        The "mfx_Control_library"   library contains the "Control" classes code, which are visual controls to draw user interfaces.

    --------

    - These "Libraries" contain program-specific code:

        The "CodeManager"           library contains the "CodeManager" edition`s code.

        The "mfx_database_library"  library contains the "Database"    edition`s code.

        The "FileShare"             library contains the "FileShare"   edition`s code.

        The "Poker_library"         library contains the "Poker"       edition`s code.

-----------------------------------------------------------------------------------------------------------------------



-----------------------------------------------------------------------------------------------------------------------

Project = _Run

        Run_Debug   - This is the only configuration run.exe currently builds on.
        {
            DevStudio does not switch 'Active solution configuration' when the active project is changed, using 'Set as Startup Project'.
            So remember to change     'Active solution configuration' when the active project is changed.

            When building 'Run', ensure library 'SeeMore_library.Run_Debug.lib' is linked into the program."

                C:\mfx\src\__Libraries_to_link.cpp(257): #pragma message( "    Info: Run_on is #defined, so   library 'SeeMore_library.Run_Debug.lib' is     linked into the program." )


            Issue:  SeeMore_library.debug.lib(__CodeEdit_1.obj) : warning LNK4099: PDB 'vc100.pdb' was not found with 'SeeMore_library.debug.lib(__CodeEdit_1.obj)' or at 'C:\mfx\bin\vc100.pdb'; linking object_mfx as if no debug info

            Solution: Notice this is the wrong library.


            Issue: C:\Program Files (x86)\MSBuild\Microsoft.Cpp\v4.0\Microsoft.CppCommon.targets(113,5): error MSB3073: The command "xcopy /F /Y   \mfx.temp\Run_Debug\_Run.Run_Debug.exe    \mfx\bin\run.exe

                This occurs when the destination file does not exist.
                I could not find an xcopy or copy flag to specify the destination is a file.

            Solution:
                Manually perform copy when this occurs.

                xcopy /F /Y   \mfx.temp\Run_Debug\_Run.Run_Debug.exe    \mfx\bin\run.exe
        }



------------------------------------------------------------------------------
Project = _SeeMore

    - Project _SeeMore is the main project and is used to build all programs.

    - Configurations:
        CompileAllCode
        Debug
        Profile_Debug           - 
        ProgramTracker
        Release
        Remote_Release
        ScreenSaver_Debug
        SeeMore_Search              - Searches Text Files, show results in file 'Search.FileLocations', shows current file in "Source Code Window".  
                                    - See class TextSearch.
                                    - I always run this program, to have matches for DevStudio`s text be automatically shown.
        SeeMoreService_Debug


------------------------------------------------------------------------------
        All_Debug                   - In project _SeeMore, the "All_Debug"          configuration compiles and links all mfx libraries and apps.

    - Project mfx_5 contains these MFX Apps:
            __Blackjack.cpp
            __Buttons_demo.cpp
            __draw.cpp
            __MFX_Demo1.cpp
            __mfx_opengl.cpp
            __scribble.cpp
            __superpad

    - Project CodeManager   builds the CodeManager Document/View library.
    - Project mfx_database  builds the mfx database code.
    - Project FileShare     builds the FileShare library
    - Project Poker         builds the Poker library.

------------------------------------------------------------------------------
- In project _SeeMore, the "Core_Debug"         configuration compiles and links the 'core' mfx libraries.

    - Use "Core_Debug" for programs that do not use any application classes or libraries, so program builds quickly.
        - A rebuild took about 20 seconds, on June 18 2016


------------------------------------------------------------------------------
 Project = FileShare 

------------------------------------------------------------------------------
 Project = mfc 


------------------------------------------------------------------------------
 Project = mfx_1 


------------------------------------------------------------------------------
 Project = mfx_2 


------------------------------------------------------------------------------
 Project = mfx_3 


------------------------------------------------------------------------------
 Project = mfx_4 


------------------------------------------------------------------------------
 Project = mfx_5 


------------------------------------------------------------------------------
 Project = mfx_6 


------------------------------------------------------------------------------
 Project = mfx_Control_library 


------------------------------------------------------------------------------
 Project = mfx_database_library 


------------------------------------------------------------------------------
 Project = Poker_library 

------------------------------------------------------------------------------
 Project = SeeMore_library       - The  ".CodeManager" C++ Developer Tools

------------------------------------------------------------------------------
 Project = SystemHooks 

------------------------------------------------------------------------------
 Project = ZipArchive 


------------------------------------------------------------------------------
{   Project Build Configurations:

    {   Miscellaneous Project Settings Notes:

        �   Set the Compiler Warning Level to 4

            � Level 4 is the proper setting for C++ code.  
              Level 3 is more suited for C code.

            �   Set the Project, Settings, C++, General, Warning Level to four.

        �   Generate Browser Information

            1.  Enable the "Project, Settings, C++, General, Generate Browse Info" check box. 

        �   Building Browser Information

            �   Have the MFX Source CodeManager build the browser information file ('.bsc').

                This saves time.
            
            �   Disable the "Project, Settings, Browse Info, Build browse info file" check box.

        �   Save the DevStudio project after modifying it.

            After modifying the DevStudio project, always save it.  
            If this is not done, the new settings will be lost if the computer or msdev.exe locks up.

        �   Do not use /PDBTYPE:SEPTYPES, because it causes the debugger to not show all information.
        
            -  to speed up linking.

                - With    /PDBTYPE:SEPTYPES a full link took: 3.7 seconds.
                - Without /PDBTYPE:SEPTYPES a full link took: 5.7 seconds.

    }

    {   Directories

        - Each build configuration places all intermediate and output files in the '\mfx.temp\' directory tree.
          This separates these files from the project's source code files, which makes backups easier.

            - Use Project, Settings, General, Output directories:

                    Intermediate files
                        \mfx.temp\...

                    Output files
                        \mfx.temp\...
    }

    {   Problems and Solutions

        - If a project is wrongly not linking each build then:
                1) Use the 'Project, Export Makefile...' command.
            or  2) Delete the '.exe' before each build.

        - If a project causes subprojects to be wrongly built,
          then the project may need to be recreated,
          because it does not match the subproject.

            - For example, 'CodeEdit - Debug computer8' causes subproject 'mfx_1' to be wrongly built.

        - If a subproject is being built even though it is not enabled in the 'Project, Dependencies' window
          then may need to disable a dependency on the subproject in one of the other subprojects.

          For example, library 'mfx_1' may wrongly be dependent on all other mfx libraries,
          which causes them to be built during rebuilds.

        - If a sub-project cannot be built from the command-line, because a file cannot be found,
          which results in NMAKE error U1073,
          then,

                - Open the sub-project's workspace in DevStudio.
                - Use the 'Project, Export Makefile' command.
                - Close the library's workspace, and open the main program's workspace.

                - Do not export the sub-project's '.mak' file from the main project.              

        - If the following link errors occur, then 
                1) Add rpcrt4.lib 
            and 2) add ' /DELAYLOAD:RPCRT4.DLL' to the linker options.

            Linking...
            mfx_2_debug.lib(__mfx_p_2.obj) : error LNK2001: unresolved external symbol __imp__RpcStringFreeA@4
            mfx_2_debug.lib(__mfx_p_2.obj) : error LNK2001: unresolved external symbol __imp__UuidToStringA@8
            mfx_2_debug.lib(__mfx_p_2.obj) : error LNK2001: unresolved external symbol __imp__UuidCreate@4
            \mfx.temp\CodeEdit\Debug_Profile\CodeEdit_Debug_Profile.exe : fatal error LNK1120: 3 unresolved externals
            Error executing link.exe.

    }


    {       Library or Program  Notes:
            ------------------  ------

            ConsoleApp          - Builds the console application, run.exe, versions of the CodeEdit and SeeMore programs.

            FileShare           - Builds the file-sharing document/view '.lib' file.

                                {   To have a program use the file-sharing library:

                                        - Have the program link to the file-sharing library.
                                            - 'Project, Settings, C/C++, Link, Object/Library modules:' FileShare_debug.lib

                                        - In DevStudio's 'Project, Dependencies' window, enable the 'FileShare' library.

                                        - Set file '__file_share.recently_modified.1.cpp's project settings to #define File_sharing_on.

                                    - To have a program not use the file-sharing library, remove the above settings.
                                }

            mfc                 - Builds a '.lib' file containing a customized version of the Windows MFC library used by the program.
                                - This library is required by all MFX programs.

                                - The CodeToolManager's CodeIncludesManager automatically moves the #includes of classes not recently used to this library.
                                - Use DevStudio's 'Project, Dependencies' window to set whether this library is built.
    }


    {   Program (.exe) Project Settings notes:

            For any program:
                                - To make linking faster in Debug mode, disable 'Project Settings, C/C++, Customize, Eliminate duplicate strings'.


            Program                 Project Settings
            -------                 ----------------

            CodeEdit or SeeMore
                                    - Use C/C++, Precompiled Headers, Automatic use through: stdafx.h

            ConsoleApp
    }

    {   - To have a dll not be loaded when the program starts, use the /DELAYLOAD linker setting.

        - The program contains copies of the following dll files, and can create them when needed:

            /DELAYLOAD:dbghelp.dll
            /DELAYLOAD:msbsc60.dll
            /DELAYLOAD:urlmon.dll 
            /DELAYLOAD:Wininet.dll 

        - To prevent the following warning, temporarily remove /DELAYLOAD commands when not needed:

            - "Linker, Input, Delay Loaded DLLs"

            LINK : warning LNK4199: /DELAYLOAD:dbghelp.dll ignored; no imports found from dbghelp.dll

            LINK : warning LNK4199: /DELAYLOAD:msbsc60.dll ignored; no imports found from msbsc60.dll
    }


    {   Library (.lib) Project Settings notes:
        
        Library (.lib)              Project Settings        
        --------------              ----------------

            FileShare               - 'Automatic use through: stdafx.h' must be used to prevent longer compile times,
                                    because some source-code files are not in a group-file.

            mfc

            mfx_1                   Use: stdafx.h
            mfx_2
            mfx_3
            mfx_4                   - Contains classes not recently used.
                                    - This is updated by the Source Code Manager.

            mfx_5                   - Contains unused files that have been manually moved to the library.

            mfx_Control_library
            mfx_database_library    
    }


    Build Name      Notes:
    ----------      ------

    CodeEdit - CompileAllCode

                    - Has all code be compiled, which lets the '.bsc' file contain all code.
                      Use this when renaming symbols, etc.

    CodeEdit - Debug                                                   
                    - Creates a debug-version of 'CodeEdit.exe'.

                    - 'DEBUG' is     defined, so ASSERT (etc.) code is     compiled.

                    - This build is used the most during program development.

    CodeEdit - Debug SeeMore
                    - Creates a debug-version of 'SeeMore.exe'.
    
    CodeEdit - Debug Profile   
                    - Profiling is enabled.

                    - Text is not sent to the debugger's output window, to prevent it affecting timing tests.

                    - #define Profiling_on is used.
                    - Debug::m_profiling_program_BOOL is used.

                    - Note that DevStudio 6 does not suppport profiling over a remote connection.

                    - To profile on another computer, without building on it:
                      
                        - If desired, copy the 'Debug_Profile' directory to the other computer.

                        - Open the program's '.exe' file within DevStudio,
                          and use the 'Build, Profile' command.

                    - Use 'profile_CodeEdit.bat' to creates a file containing the profiler's results, sorted by function+child time.

                    - File 'profile_CodeEdit_settings.txt'
                      contains more notes on profiling.
        
    CodeEdit - Debug Remote
                    - Use this program when performing remote debugging.

                    - This is a copy of the 'Debug' build.
                    
                    - This build lets two copies of DevStudio be run on the same computer.  Each copy opens a different build configuration.

                    - If desired, use the 'exit' command to have the program quit after it has started up.

                    - Remote debugging setup:

                        - Set 'Project, Settings, Debug, Remote executable path and file name'
                          to match your needs.

                            - Example:  If the local computer is computer5 
                                        then use:
                                                    \\computer5\MFX\mfx.temp\CodeEdit\Debug_Remote\CodeEdit_on_computer5.exe

                        - Use 'Build, Debugger Remote Connection, Connection, Network, Settings'
                          to set the IP address.

                            - Example:  If the remote computer has a network card with address 192.168.1.50
                                        then use:
                                                    192.168.1.50

                            - This needs to be set everytime the project is opened,
                              because the DevStudio always uses the last address.

                        - If a '.dll' on the remote computer does not match the '.dll' on the local computer,
                          then replace the file on the remote computer.
                            - This prevents a warning being shown every time.

                    - When remote debugging:
    
                        - Set the working directory to match a drive on the remote computer, for example:

                                    Project, Settings, Debug, Working directory:    z:\

                            - If the working directory is invalid, then error 267 will occur.

                        - Set drive Y: to the main computer's drive that contains the project's source code.

                        - Windows 98 forces does not let Y: be used, rather the next available drive letter must be used,
                          so temporarily use the appropriate drive letter.


                    - Remote debugging trouble-shooting:

                        - Need to kill the 'msvcmon.exe' program sometimes.


    CodeEdit - Debug With ProgramTracker and modified MFC Library

                    - A debug build with ProgramTracker support.

    CodeEdit - Release                                                 
                    - 'DEBUG' is not defined, so ASSERT (etc.) code is not compiled.

                    - Compiler optimizations are not used, to make debugging easier.


    ------------------------------------------------------------------------------

    ------------------------------------------------------------------------------
    SeeMore builds: - The 'SeeMore' builds create programs named 'SeeMore.*.exe':
                            - Debug         SeeMore.test_version.exe
                            - Release       SeeMore.release_version.exe
    
                    - The programs use the same ".INI" files.

    CodeEdit - Debug SeeMore
                    - Creates a debug program named 'SeeMore.exe'.

                    - When DevStudio wrongly does not update the '.exe' each build, manually delete it.

                    - Do not use the '/pdb:none' linker option to attach the '.pdb' information to the '.exe',
                      because the ErrorReport will not show enough information.

    CodeEdit - Release SeeMore
                    - Creates a release-version program named 'SeeMore.release_version.exe'.

                    - Compiler optimizations are not used, to make debugging easier.

    ------------------------------------------------------------------------------

    ConsoleApp      - The ConsoleApp builds create console application versions of the program.

                    - '#define _CONSOLE' is added for mfc console applications.

                    - The programs use the same ".INI" files.

                    - To have '.pdb' information be available, 
                      the following setting must be unchecked:
                        
                            Project, Settings, Link, Separate Types: Unchecked

    ConsoleApp - Debug
    ConsoleApp - Release

}
------------------------------------------------------------------------------


Build _SeeMore "Optimized" build configuration.
{

    - "Optimized" is the compiler-optimized 'final release' version, used by the program's users.

    - Use #define compiler_optimizations_on when the program use compiler optimizations.

    - 'DEBUG' is not defined, so ASSERT (etc.) code is not compiled.

    - Compiler optimizations are used.
        - Inlining is enabled.
        - This make code run faster, but harder to step through.

    - The /OPT:REF linker option discards unreferenced symbols.  This makes linking slower.

    - "Optimized" builds all mfx code, so all code can be run in optimized mode.

    - TODO: See how much faster mfx program run.

        "_ _SeeMore.CodeManager"    Optimized           Build, Rebuild takes 1 minute  43 seconds.   (Showing 10? rows in Output window)
        "_ _SeeMore.CodeManager"    CodeManager_Release Build, Rebuild takes ? minutes ? seconds.   (Showing   2 rows in Output window)

}
//
{
    C:\mfx\src\Collection.not_profiled.cpp
    Collection::Element_is_a_CObject
}
//
{   ? Use more inline code?
        - Make more code available for inlining?
            - #include code in the '.h' file?
}
