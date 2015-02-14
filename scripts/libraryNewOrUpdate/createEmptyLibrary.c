libraryNewOrUpdate: createEmptyLibrary
#
Set Error Capture [ On ]
Allow User Abort [ Off ]
#
If [ backup::newLibrary = "" ]
Show Custom Dialog [ Message: "Create a new empty library?"; Buttons: “cancel”, “OK” ]
If [ Get ( LastMessageChoice ) = 1 ]
Exit Script [ ]
End If
End If
#
#If user decides to create a new library...
If [ backup::newLibrary ≠ "234874920347574weidf792342f9823984" and backup::newLibrary ≠ "newLibrary" ]
#
#Go to the backup layout, insure there is a record, and
#set with the code to create an empty library.
Go to Layout [ “backup” (backup) ]
Delete All Records
[ No dialog ]
New Record/Request
Set Field [ backup::newLibrary; "234874920347574weidf792342f9823984" ]
#
#Ask user what to name this new library.
Go to Layout [ original layout ]
#
#A copy not a clone must be created because some
#records are neccessary to running the Library and
#are removed when cloning the Library.
Save a Copy as [ ]
[ copy of current file ]
#
#If the user decides to cancel the script then stop the process.
If [ Get (LastError) = 1 ]
Go to Layout [ “backup” (backup) ]
Set Field [ backup::newLibrary; "" ]
Go to Layout [ original layout ]
Exit Script [ ]
End If
#
#Reset the new library code to blank and return to main screen.
Go to Layout [ “backup” (backup) ]
Set Field [ backup::newLibrary; "" ]
Go to Layout [ original layout ]
Show Custom Dialog [ Message: "Now open your new library. You will be asked if you want to delete the records in it. Make sure it is the copy of your current library file and then proceed with the delete."; Buttons: “OK” ]
Exit Script [ ]
#
Else If [ backup::newLibrary = "234874920347574weidf792342f9823984" or backup::newLibrary = "newLibrary" ]
Set Field [ backup::newLibrary; "" ]
#
Go to Layout [ “tableTemp” (TEMP) ]
New Record/Request
Go to Field [ TEMP::addTestItemGroup ]
Loop
Set Field [ "" ]
Exit Loop If [ Get ( ActiveFieldName ) = "userLocationName" ]
Go to Next Field
End Loop
#
Go to Layout [ “tableTestSubjectFocus” (tagTestSubjectLocation) ]
Show All Records
Delete All Records
[ No dialog ]
#
Go to Layout [ “tableTest” (test) ]
Show All Records
Delete All Records
[ No dialog ]
#
Go to Layout [ “tableTestLearn” (testlearn) ]
Show All Records
Delete All Records
[ No dialog ]
#
Go to Layout [ “tableGroupTag” (groupTest) ]
Perform Find [ Specified Find Requests: Omit Records; Criteria: groupTest::order: “*"lock"” ]
[ Restore ]
Delete All Records
[ No dialog ]
#
Go to Layout [ “tableTag” (tagTable) ]
Perform Find [ Specified Find Requests: Omit Records; Criteria: tagTable::orderOrLock: “lock” ]
[ Restore ]
Delete All Records
[ No dialog ]
#
Go to Layout [ “tableReference” (reference) ]
Enter Find Mode [ ]
Set Field [ reference::lock; "lock" ]
Perform Find [ ]
Show Omitted Only
Delete All Records
[ No dialog ]
#
Go to Layout [ “tableReport” (report) ]
Show All Records
Delete All Records
[ No dialog ]
#
Go to Layout [ “defaultSetup” (tempSetup) ]
#
Perform Script [ “startDatabase” ]
Set Field [ tempSetup::fileName; Get ( FileName ) ]
#
#Create first section.
Set Field [ TEMP::kdefaultNodePrimary; $$OldNodeID ]
Select Window [ Name: "Tag Menus"; Current file ]
Go to Layout [ “defaultSections” (ruleSection) ]
Perform Script [ “newSectionOnSectionLayout” ]
Set Field [ ruleSection::name ]
Set Field [ TEMP::kdefaultNodePrimary; "" ]
If [ $$OldNodeID = 1 ]
Set Variable [ $$OldNodeID ]
End If
#
#Create first node.
Set Variable [ $$stopAddBack; Value:1 ]
Perform Script [ “defaultNodeMenu” ]
Perform Script [ “newCitationMenuGroup” ]
If [ $$OldNodeID ≠ "" ]
Set Field [ tagMenus::_Ltag; $$OldNodeID ]
End If
February 3, 平成26 16:42:47 Imagination Quality Management.fp7 - createEmptyLibrary -1-libraryNewOrUpdate: createEmptyLibrary
End If
Set Variable [ $$OldNodeID; Value:tagMenus::_Ltag ]
Set Field [ ruleTagMenuGroups::kRecordCreatorNode; $$OldNodeID ]
Set Field [ tagMenus::tag; "lastName, firstName" ]
Perform Script [ “addTagToMainRecord” ]
Set Variable [ $$stopAddBack ]
#
#Assign node to first created section as its creator.
Go to Layout [ “tableGroupTag” (groupTest) ]
Perform Find [ Specified Find Requests: Find Records; Criteria: groupTest::kRecordCreatorNode: “1” ]
[ Restore ]
Sort Records [ Specified Sort Order: groupTest::match; descending ]
[ Restore; No dialog ]
Go to Record/Request/Page
[ First ]
Set Field [ groupTest::kRecordCreatorNode; $$OldNodeID ]
Set Field [ groupTest::kSectionCreatorNodesCreator; $$OldNodeID ]
Set Field [ groupTest::aboutSection; "This library is for noting what we learn about _________________, collecting references to it, and testing or collecting samples of ___________________ to improve the quality of our thinking and doing or __________________ quality (if
_________________ is a thing not a person)." ]
#
#Assign node to first created node group as its creator.
Go to Record/Request/Page
[ Next ]
Set Field [ groupTest::kRecordCreatorNode; $$OldNodeID ]
Go to Layout [ “defaultSetup” (tempSetup) ]
#
#Inform user of next steps.
If [ $$OldNodeID ≠ "" ]
Show Custom Dialog [ Message: "Change the name of the first node to your name since you will be the creator of new library records."; Buttons: “OK” ]
Set Variable [ $$OldNodeID ]
Else
Show Custom Dialog [ Message: "Change the name of the first node to your name since you will be the creator of new library records."; Buttons: “OK” ]
End If
End If
#
February 3, 平成26 16:42:47 Imagination Quality Management.fp7 - createEmptyLibrary -2-
