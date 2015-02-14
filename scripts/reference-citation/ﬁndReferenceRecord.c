reference(citation): findReferenceRecord
#
If [ $$findMode ≠ "" ]
Show Custom Dialog [ Message: "Cancel find in Tag Menus window then click this button."; Buttons: “OK” ]
Exit Script [ ]
End If
#
#If user is in tag field and has changed spelling
#exit this tag record, otherwise current reference record
#will get deleted by the spelling check script.
Select Window [ Name: "Tag Menus"; Current file ]
Go to Field [ ]
Select Window [ Name: "References"; Current file ]
If [ $$referenceSort = 2 ]
Sort Records [ Specified Sort Order: reference::modifyDate; descending
reference::referenceForReferenceSort; ascending ]
[ Restore; No dialog ]
Else If [ $$referenceSort = "" ]
Sort Records [ Specified Sort Order: tagKeywordPrimary::tag; ascending
reference::referenceForReferenceSort; ascending ]
[ Restore; No dialog ]
Else If [ $$referenceSort = 1 ]
Sort Records [ Specified Sort Order: reference::createDate; descending
reference::referenceForReferenceSort; ascending ]
[ Restore; No dialog ]
End If
#
#Capture errors and tell user about them in custom
#dialogue box.
Allow User Abort [ Off ]
Set Error Capture [ On ]
#
#If the user clicks the find button and the system is already
#in find mode, capture the user's current find request
#and then perform the requested find.
#This capture is done in case nothing is found and the
#user is asked if they want to modify their request.
#The system puts in the captured request so that the
#user can see the failed request.
If [ Get (WindowMode) = 1 ]
Set Variable [ $r0; Value:reference::createDate ]
Set Variable [ $r1; Value:reference::modifyDate ]
Set Variable [ $r2; Value:reference::show ]
Set Variable [ $r3; Value:reference::incomplete ]
Set Variable [ $r4; Value:reference::referenceForReferenceWindow ]
Set Variable [ $r5; Value:reference::kmediaType ]
Set Variable [ $r6; Value:reference::kmedia ]
Set Variable [ $r7; Value:reference::TypeOfMediumOther ]
Set Variable [ $r8; Value:reference::referenceNodes ]
Set Variable [ $r9; Value:reference::Title ]
Set Variable [ $r10; Value:reference::bookChapter ]
Set Variable [ $r11; Value:reference::governmentAuthor ]
Set Variable [ $r12; Value:reference::GovernmentDocInfo ]
Set Variable [ $r13; Value:reference::letterDate ]
Set Variable [ $r14; Value:reference::emailRecipient ]
Set Variable [ $r15; Value:reference::compilationTitle ]
Set Variable [ $r16; Value:reference::compilationEditors ]
Set Variable [ $r17; Value:reference::compilationNumberOfEditors ]
Set Variable [ $r18; Value:reference::conferenceIntroWords ]
Set Variable [ $r19; Value:reference::conferenceTitle ]
Set Variable [ $r20; Value:reference::conferenceSubTitle ]
Set Variable [ $r21; Value:reference::conferenceGroupName ]
Set Variable [ $r22; Value:reference::conferenceLocation ]
Set Variable [ $r23; Value:reference::conferenceDate ]
Set Variable [ $r24; Value:reference::volumeNumber ]
Set Variable [ $r25; Value:reference::issueNumber ]
Set Variable [ $r26; Value:reference::pageNumberRange ]
Set Variable [ $r27; Value:reference::TimeRange ]
Set Variable [ $r28; Value:reference::publisherTypeAlternative ]
Set Variable [ $r29; Value:reference::publisherLocation ]
Set Variable [ $r30; Value:reference::pubYear ]
Set Variable [ $r31; Value:reference::PubDate ]
Set Variable [ $r32; Value:reference::pubDateOther ]
Set Variable [ $r33; Value:reference::CopyrightYear ]
Set Variable [ $r34; Value:reference::copyrightOtherHolder ]
Set Variable [ $r35; Value:reference::URL ]
Set Variable [ $r36; Value:reference::URLdate ]
Set Variable [ $r37; Value:reference::library only ]
Set Variable [ $r38; Value:reference::ISBN ]
Set Variable [ $r39; Value:reference::URLdoi ]
Set Variable [ $r40; Value:reference::ISSN ]
Set Variable [ $r41; Value:reference::fileName ]
Set Variable [ $r42; Value:reference::kfileLocation ]
Set Variable [ $r43; Value:reference::thoughtsNotesEtc ]
Set Variable [ $r44; Value:reference::referenceDump ]
Perform Find [ ]
#
#If the system is not in find mode and the find button
#is clicked then capture the current layout name
#(to return user to it after find), enter find mode,
#go to the find layout, and await the user's find request.
Else
Set Variable [ $$findReferenceLayout; Value:Get (LayoutName) ]
Enter Find Mode [ ]
Go to Layout [ “ReferenceFIND” (reference) ]
Show/Hide Status Area
[ Hide ]
Show/Hide Text Ruler
[ Hide ]
Set Field [ reference::kcsection; TEMP::ksection ]
Go to Field [ reference::referenceForReferenceWindow ]
Pause/Resume Script [ Indefinitely ]
Set Variable [ $r0; Value:reference::createDate ]
Set Variable [ $r1; Value:reference::modifyDate ]
Set Variable [ $r2; Value:reference::show ]
Set Variable [ $r3; Value:reference::incomplete ]
Set Variable [ $r4; Value:reference::referenceForReferenceWindow ]
Set Variable [ $r5; Value:reference::kmediaType ]
Set Variable [ $r6; Value:reference::kmedia ]
Set Variable [ $r7; Value:reference::TypeOfMediumOther ]
Set Variable [ $r8; Value:reference::referenceNodes ]
Set Variable [ $r9; Value:reference::Title ]
Set Variable [ $r10; Value:reference::bookChapter ]
Set Variable [ $r11; Value:reference::governmentAuthor ]
Set Variable [ $r12; Value:reference::GovernmentDocInfo ]
Set Variable [ $r13; Value:reference::letterDate ]
Set Variable [ $r14; Value:reference::emailRecipient ]
Set Variable [ $r15; Value:reference::compilationTitle ]
Set Variable [ $r16; Value:reference::compilationEditors ]
Set Variable [ $r17; Value:reference::compilationNumberOfEditors ]
Set Variable [ $r18; Value:reference::conferenceIntroWords ]
January 7, 平成26 17:42:04 Imagination Quality Management.fp7 - findReferenceRecord -1-reference(citation): findReferenceRecord
Set Variable [ $r19; Value:reference::conferenceTitle ]
Set Variable [ $r20; Value:reference::conferenceSubTitle ]
Set Variable [ $r21; Value:reference::conferenceGroupName ]
Set Variable [ $r22; Value:reference::conferenceLocation ]
Set Variable [ $r23; Value:reference::conferenceDate ]
Set Variable [ $r24; Value:reference::volumeNumber ]
Set Variable [ $r25; Value:reference::issueNumber ]
Set Variable [ $r26; Value:reference::pageNumberRange ]
Set Variable [ $r27; Value:reference::TimeRange ]
Set Variable [ $r28; Value:reference::publisherTypeAlternative ]
Set Variable [ $r29; Value:reference::publisherLocation ]
Set Variable [ $r30; Value:reference::pubYear ]
Set Variable [ $r31; Value:reference::PubDate ]
Set Variable [ $r32; Value:reference::pubDateOther ]
Set Variable [ $r33; Value:reference::CopyrightYear ]
Set Variable [ $r34; Value:reference::copyrightOtherHolder ]
Set Variable [ $r35; Value:reference::URL ]
Set Variable [ $r36; Value:reference::URLdate ]
Set Variable [ $r37; Value:reference::library only ]
Set Variable [ $r38; Value:reference::ISBN ]
Set Variable [ $r39; Value:reference::URLdoi ]
Set Variable [ $r40; Value:reference::ISSN ]
Set Variable [ $r41; Value:reference::fileName ]
Set Variable [ $r42; Value:reference::kfileLocation ]
Set Variable [ $r43; Value:reference::thoughtsNotesEtc ]
Set Variable [ $r44; Value:reference::referenceDump ]
Perform Find [ ]
End If
#
#If the find fails tell the user it failed and give them
#option to modify their request or cancel the find.
Loop
If [ Get (LastError) = 401 ]
Enter Find Mode [ ]
Set Field [ reference::kcsection; TEMP::ksection ]
Set Field [ reference::createDate; $r0 ]
Set Field [ reference::modifyDate; $r1 ]
Set Field [ reference::show; $r2 ]
Set Field [ reference::incomplete; $r3 ]
Set Field [ reference::referenceForReferenceWindow; $r4 ]
Set Field [ reference::kmediaType; $r5 ]
Set Field [ reference::kmedia; $r6 ]
Set Field [ reference::TypeOfMediumOther; $r7 ]
Set Field [ reference::referenceNodes; $r8 ]
Set Field [ reference::Title; $r9 ]
Set Field [ reference::bookChapter; $r10 ]
Set Field [ reference::governmentAuthor; $r11 ]
Set Field [ reference::GovernmentDocInfo; $r12 ]
Set Field [ reference::letterDate; $r13 ]
Set Field [ reference::emailRecipient; $r14 ]
Set Field [ reference::compilationTitle; $r15 ]
Set Field [ reference::compilationEditors; $r16 ]
Set Field [ reference::compilationNumberOfEditors; $r17 ]
Set Field [ reference::conferenceIntroWords; $r18 ]
Set Field [ reference::conferenceTitle; $r19 ]
Set Field [ reference::conferenceSubTitle; $r20 ]
Set Field [ reference::conferenceGroupName; $r21 ]
Set Field [ reference::conferenceLocation; $r22 ]
Set Field [ reference::conferenceDate; $r23 ]
Set Field [ reference::volumeNumber; $r24 ]
Set Field [ reference::issueNumber; $r25 ]
Set Field [ reference::pageNumberRange; $r26 ]
Set Field [ reference::TimeRange; $r27 ]
Set Field [ reference::publisherTypeAlternative; $r28 ]
Set Field [ reference::publisherLocation; $r29 ]
Set Field [ reference::pubYear; $r30 ]
Set Field [ reference::PubDate; $r31 ]
Set Field [ reference::pubDateOther; $r32 ]
Set Field [ reference::CopyrightYear; $r33 ]
Set Field [ reference::copyrightOtherHolder; $r34 ]
Set Field [ reference::URL; $r35 ]
Set Field [ reference::URLdate; $r36 ]
Set Field [ reference::library only; $r37 ]
Set Field [ reference::ISBN; $r38 ]
Set Field [ reference::URLdoi; $r39 ]
Set Field [ reference::ISSN; $r40 ]
Set Field [ reference::fileName; $r41 ]
Set Field [ reference::kfileLocation; $r42 ]
Set Field [ reference::thoughtsNotesEtc; $r43 ]
Set Field [ reference::referenceDump; $r44 ]
#
Go to Field [ reference::referenceForReferenceWindow ]
Show Custom Dialog [ Message: "No records match this request."; Buttons: “cancel”, “modify find” ]
#
#If the user decides to modify their request then stay
#in find mode and await the users new request.
If [ Get ( LastMessageChoice ) = 2 ]
Pause/Resume Script [ Indefinitely ]
Set Variable [ $r0; Value:reference::createDate ]
Set Variable [ $r1; Value:reference::modifyDate ]
Set Variable [ $r2; Value:reference::show ]
Set Variable [ $r3; Value:reference::incomplete ]
Set Variable [ $r4; Value:reference::referenceForReferenceWindow ]
Set Variable [ $r5; Value:reference::kmediaType ]
Set Variable [ $r6; Value:reference::kmedia ]
Set Variable [ $r7; Value:reference::TypeOfMediumOther ]
Set Variable [ $r8; Value:reference::referenceNodes ]
Set Variable [ $r9; Value:reference::Title ]
Set Variable [ $r10; Value:reference::bookChapter ]
Set Variable [ $r11; Value:reference::governmentAuthor ]
Set Variable [ $r12; Value:reference::GovernmentDocInfo ]
Set Variable [ $r13; Value:reference::letterDate ]
Set Variable [ $r14; Value:reference::emailRecipient ]
Set Variable [ $r15; Value:reference::compilationTitle ]
Set Variable [ $r16; Value:reference::compilationEditors ]
Set Variable [ $r17; Value:reference::compilationNumberOfEditors ]
Set Variable [ $r18; Value:reference::conferenceIntroWords ]
Set Variable [ $r19; Value:reference::conferenceTitle ]
Set Variable [ $r20; Value:reference::conferenceSubTitle ]
Set Variable [ $r21; Value:reference::conferenceGroupName ]
Set Variable [ $r22; Value:reference::conferenceLocation ]
Set Variable [ $r23; Value:reference::conferenceDate ]
Set Variable [ $r24; Value:reference::volumeNumber ]
Set Variable [ $r25; Value:reference::issueNumber ]
Set Variable [ $r26; Value:reference::pageNumberRange ]
Set Variable [ $r27; Value:reference::TimeRange ]
Set Variable [ $r28; Value:reference::publisherTypeAlternative ]
January 7, 平成26 17:42:04 Imagination Quality Management.fp7 - findReferenceRecord -2-reference(citation): findReferenceRecord
Set Variable [ $r29; Value:reference::publisherLocation ]
Set Variable [ $r30; Value:reference::pubYear ]
Set Variable [ $r31; Value:reference::PubDate ]
Set Variable [ $r32; Value:reference::pubDateOther ]
Set Variable [ $r33; Value:reference::CopyrightYear ]
Set Variable [ $r34; Value:reference::copyrightOtherHolder ]
Set Variable [ $r35; Value:reference::URL ]
Set Variable [ $r36; Value:reference::URLdate ]
Set Variable [ $r37; Value:reference::library only ]
Set Variable [ $r38; Value:reference::ISBN ]
Set Variable [ $r39; Value:reference::URLdoi ]
Set Variable [ $r40; Value:reference::ISSN ]
Set Variable [ $r41; Value:reference::fileName ]
Set Variable [ $r42; Value:reference::kfileLocation ]
Set Variable [ $r43; Value:reference::thoughtsNotesEtc ]
Set Variable [ $r44; Value:reference::referenceDump ]
#
#If the user decides to cancel their the find, then return
#to the main record window and show all records.
Else If [ Get ( LastMessageChoice ) = 1 ]
Go to Layout [ $$findReferenceLayout ]
Show/Hide Status Area
[ Hide ]
Show/Hide Text Ruler
[ Hide ]
Enter Find Mode [ ]
Set Field [ reference::kcsection; TEMP::ksection ]
Perform Find [ ]
Sort Records [ ]
[ No dialog ]
Go to Record/Request/Page
[ First ]
Set Variable [ $$findReferenceLayout ]
Exit Script [ ]
End If
Perform Find [ ]
End If
#
#If the find is successful then show the user the found
#records on the main records layout.
Exit Loop If [ Get (LastError) = 0 ]
End Loop
Go to Layout [ $$findReferenceLayout ]
Go to Layout [ $$findLearnLayout ]
Set Variable [ $$findReferenceLayout ]
Sort Records [ ]
[ No dialog ]
Go to Record/Request/Page
[ First ]
January 7, 平成26 17:42:04 Imagination Quality Management.fp7 - findReferenceRecord -3-
