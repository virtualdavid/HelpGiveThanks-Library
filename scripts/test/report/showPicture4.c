January 15, 2018 15:34:31 Library.fmp12 - showPicture4 -1-
test: report: showPicture4
#
#Show picture in picture window...
Set Variable [ $$PictureOnReportLayout; Value:testlearnReportTags 4::_Ltestlearn ]
Set Variable [ $$fileLocation; Value:Case ( testlearnReportTags 4::picture ≠ "" ; "TLpicture" ;
Case (
refShowMediaReport 4::picture ≠ "" ; "database" ;
refShowMediaReport 4::kfileLocation ≠ "" and refShowMediaReport 4::fileName ≠ "" and refShowMediaReport 4::showMedia = "" ;
"harddrive" ;
refShowMediaReport 4::URL ≠ "" and refShowMediaReport 4::showMedia ≠ "" ; "web" ;
"none" )
) ]
#
#... if there is a picture to show.
If [ $$PictureOnReportLayout ≠ "" and $$fileLocation ≠ "none" ]
Perform Script [ “showCitationPicture1inNewWindow” ]
#
#Otherwise, do nothing.
Else
Set Variable [ $$PictureOnReportLayout ]
Set Variable [ $$fileLocation ]
#
#Inform user about how to add media.
Show Custom Dialog [ Message: "To add a picture or movie to this slot 1) select a test result in the Tag Menus window that has
media. 2) Click this result's copy button. 3) Return to this Report window. 4) Click in the highlighted space below."; Default
Button: “OK”, Commit: “No” ]
End If
