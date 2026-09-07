============================================================
 KW007 SDK v1.2 — Technical Documentation
 Keywave KW007 5.8 GHz Doppler Radar Sensor
 Release Date: 2026-08-24
============================================================

CONTENTS
--------
  ..\new Doc\index.html   Recommended cross-platform API reference.
                          Open this file in a web browser; no installation
                          is required.

  KW007_Programming_Guide_v2.0c.pdf
                          Register-level reference for the KW007
                          sensor — register map, settings tables,
                          and hardware notes.

  KW007_SDK_v1.2.chm      Optional legacy Windows help containing the
                          same API reference. Some systems block or do
                          not support CHM files.


HOW TO OPEN
-----------
  Recommended on Windows, macOS, and Linux:

    Open ..\new Doc\index.html in any modern web browser.

  The HTML reference is a local, static copy and does not require a
  web server or internet connection. Open the programming-guide PDF
  separately for register tables and hardware details.

  Legacy Windows option:

    Double-click KW007_SDK_v1.2.chm. If it is unavailable, blocked,
    or its search feature does not work, use ..\new Doc\index.html instead.


OPTIONAL CHM TROUBLESHOOTING — "Page cannot be displayed" / blank content
----------------------------------------------------------------------------
If the CHM opens but the content pane is empty or shows
"Navigation to the webpage was canceled", Windows has blocked
the file for security reasons (Mark-of-the-Web). This is a
standard Windows safeguard for CHM files received via email,
cloud storage, or USB transfer.

To unblock:

  1. Right-click  KW007_SDK_v1.2.chm
  2. Select       Properties
  3. At the bottom of the dialog, check the box:
                  [x] Unblock
  4. Click        Apply  ->  OK
  5. Re-open the .chm file

Alternative (PowerShell one-liner):

        Unblock-File .\KW007_SDK_v1.2.chm


ADDITIONAL NOTES
----------------
  * Do not place the .chm file in a path containing the '#'
    character (e.g. C:\C#_Projects\). CHM cannot render
    content from such paths.

  * When stored on a network drive or SMB share, CHM content
    may be blocked. Copy the file to a local drive first.

  * Some corporate IT policies disable CHM entirely.
    Contact your IT administrator if unblocking does not help.


SUPPORT
-------
For technical inquiries regarding the KW007 sensor or SDK,
please contact your Keywave representative.

============================================================

LICENSING
---------
  Copyright 2026 Keywave Technology.
  The first-party documentation, including this README, the programming
  guide PDF, and the HTML and CHM reference, is licensed under the
  Apache License, Version 2.0 (SPDX: Apache-2.0). See ../LICENSE.
  Third-party assets retain their existing licenses; see
  ../THIRD_PARTY_NOTICES.txt. Preserve these notices when redistributing.
