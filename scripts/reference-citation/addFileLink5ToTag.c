January 18, 2018 15:49:07 Library.fmp12 - addFileLink5ToTag -1-
reference: addFileLink5ToTag
#
#If user was in the copyright window then
#return user to this window.
If [ $$userInCopyrightWindow = 1 ]
Show Custom Dialog [ Message: "For copyright records, only one weblink is allowed."; Default Button: “OK”, Commit: “No” ]
Exit Script [ ]
End If
#
#Clear fields and then determine if there something
#to link.
Go to Field [ ]
If [ reference::Title ≠ "" and
FilterValues ( reference::kfileLocation ; "8162011225532313" ) = "8162011225532313" & ¶ and
reference::fileName ≠ ""
 or
reference::Title ≠ "" and
FilterValues ( reference::kfileLocation ; "8162011225558314" ) = "8162011225558314" & ¶ and
reference::fileName ≠ ""
 or
reference::Title ≠ "" and
FilterValues ( reference::kfileLocation ; "8162011225605315" ) = "8162011225605315" & ¶ and
tagRefFolderPath::tag ≠ "" and
reference::fileName ≠ ""
 or
reference::URL ≠ "" ]
#
#Set variables to passed on to linking script.
Set Variable [ $$name; Value:"title" ]
Set Variable [ $$number; Value:2 ]
#
#If the filterFind checkbox is not checked for the
#the current $$CitationMatch variable, then
#these next scripts will identify that problem,
#fix it, and inform the user of what it did.
If [ $$citationMatch = "key" and "keyword" & ¶ ≠ FilterValues ( reference::filterFind ; "keyword" ) ]
Set Variable [ $filterFind; Value:reference::filterFind ]
Set Field [ reference::filterFind; "keyword" & ¶ & $filterFind ]
// Show Custom Dialog [ Message: "The system has added this reference record to the " &
If ( $$citationMatch = "key" ; "keyword (key)" ; $$citationMatch ) &
 " citation record set. You will not have to click the 'all' button anymore to find it for " & If ( $$citationMatch = "key" ;
"keyword (key)" ; $$citationMatch ) & " tags."
//Next time you click on the add button, this record will be found as part of the records supplying pictures, file and web
links to " &
//If ( $$citationMatch = "key" ; "keyword (key)" ; $$citationMatch ) & " tags."; Default Button: “OK”, Commit: “No” ]
Else If [ $$citationMatch & ¶ ≠ FilterValues ( reference::filterFind ; $$citationMatch ) ]
Set Variable [ $filterFind; Value:reference::filterFind ]
Set Field [ reference::filterFind; $$citationMatch & ¶ & $filterFind ]
// Show Custom Dialog [ Message: "The system has added this reference record to the " &
If ( $$citationMatch = "key" ; "keyword (key)" ; $$citationMatch ) &
 " citation record set. You will not have to click the 'all' button anymore to find it for " & If ( $$citationMatch = "key" ;
"keyword (key)" ; $$citationMatch ) & " tags."
//Next time you click on the add button, this record will be found as part of the records supplying pictures, file and web
links to " &
//If ( $$citationMatch = "key" ; "keyword (key)" ; $$citationMatch ) & " tags."; Default Button: “OK”, Commit: “No” ]
End If
#
#Now perform the script that adds the tag.
Perform Script [ “CHUNKaddLinkToTag (update)” ]
Exit Script [ ]
End If
#
#If the conditions for adding the tag are not met
#tell the user which ones needs to be met before
#the tag can be added.
If [ reference::fileName = "" and Get ( LayoutTableName ) = "reference" ]
Show Custom Dialog [ Message: "A file name is required including the file's extension: .jpg , .gif , .pdf , .mov , etc. OR a URL is
required to add a link."; Default Button: “OK”, Commit: “No” ]
Else If [ reference::kfileLocation = "" and reference::fileName ≠ "" and Get ( LayoutTableName ) = "reference" ]
Show Custom Dialog [ Message: "Check the box next the location of your file: main, other, or x."; Default Button: “OK”, Commit:
“Yes” ]
Else If [ FilterValues ( reference::kfileLocation ; "8162011225605315" ) = "8162011225605315" & ¶ and
tagRefFolderPath::tag = "" ]
Show Custom Dialog [ Message: "Select a file path from the Tag Menus window. If there are none then add one by opening the
file with a browser (Firefox, Explore, etc.) and dragging/pasting the address into a new tag's text box."; Default Button: “OK”,
Commit: “No” ]
Select Window [ Name: "Tag Menus"; Current file ]
Perform Script [ “menuPath (update)” ]
End If
