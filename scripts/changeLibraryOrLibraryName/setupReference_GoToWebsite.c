January 11, 2018 19:14:03 Library.fmp12 - setupReference_GoToWebsite -1-
librarySetup: setupReference_GoToWebsite
#
#
#If there are no setup references, then
#go to the helpgive thanks website.
If [ Get (FoundCount) = 0 ]
Open URL [ "https://helpgivethanks.github.io" ]
[ No dialog ]
Exit Script [ ]
End If
#
#
#If there is no URL, then tell the user how
#to add one ...
If [ librarySetupReferenceMain::URL = "" ]
#
#on the Setup window ...
If [ Get (WindowName) = "Setup" ]
#
If [ librarySetupReferenceMain::password = "" ]
#If NOT locked ...
Show Custom Dialog [ Message: "1) Click the review button, and then 2) the edit button, 3) to add a website URL to
this setup reference in the edit window."; Default Button: “OK”, Commit: “Yes” ]
Else
#If locked ...
Show Custom Dialog [ Message: "1) Click the lock button and unlock this setup reference, 2) then click the review
button, 3) the edit button, 4) to add a website URL to this setup reference in the edit window."; Default Button: “OK”,
Commit: “Yes” ]
End If
#
#on the Review Reference window ...
Else If [ Get (WindowName) = "Review Reference" ]
#
If [ librarySetupReferenceMain::password = "" ]
#If NOT locked ...
Show Custom Dialog [ Message: "1) Click the edit button, 2) to add a website URL to this in the Edit Reference
window."; Default Button: “OK”, Commit: “Yes” ]
Else
#If locked ...
Show Custom Dialog [ Message: "1) Click the lock button and unlock this setup reference, 2) then click edit button, 3)
to add a website URL to this in the Edit Reference window."; Default Button: “OK”, Commit: “Yes” ]
End If
#
#on the Edit Reference window, which is
#always unlocked.
Else If [ Get (WindowName) = "Edit Reference" ]
Show Custom Dialog [ Message: "Add a website URL below, then click the web button again to go to that website."; Default
Button: “OK”, Commit: “Yes” ]
End If
#
#
#
#
#If there is a URL, then go to it.
Else
Open URL [ librarySetupReferenceMain::URL ]
[ No dialog ]
End If
#
#
