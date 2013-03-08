  Paint
  ===============
  
  This is a project for COMP2012H, 2013 Spring, HKUST
  
  The main purpose is to create a mspaint-like painting tool
  
  The course webpage:
      http://course.cse.ust.hk/comp2012h
      (CSD account required)
  
  Author
  ===============
  Name: TAN, Shuhao
  Student ID: 20090398
  ITSC: stanab
  
  How-to-compile-and-run
  ===============
  >qmake
  >gmake
  >./build_bin/paint
  
  Technical Details
  ===============
  
  The build of this project involves the following tools:
      UltraEdit (text editor)
      SecureCRT (ssh terminal)
      X-Win32 2012 (X11 server for windows)
      Git (manage code)
      Qt (GUI library)
      GNU toolchain(compiler)
  
  Add-on Features:
      ScrollBar
      Accelerator (shortcut)
      Togglable ToolBar Button
      Multi undo and redo
      Multi file format support
  
  Bug-fixes from sample program:
      Fix View->Tool Bar not functioning
      Fix poly line mode will not terminate when switching tools
      Fix poly mode end point will be the start point in sing mode
      Fix icon not loading when starting from other folder
      Fix icon not loading when starting on real machine
  
  Deviation from sample program
      Canvas will not respond to mouse if mouse event starting from 
        outside the image (adapted from mspaint)
  
  Enjoy!
    TAN, Shuhao

--- end of README ---