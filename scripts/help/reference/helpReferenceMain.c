July 21, 2018 14:39:37 Library.fmp12 - helpReferenceMain -1-
help: reference: helpReferenceMain
#
#
#Send general layout name and help column
#number to the help script so it can take the
#user to help for this layout and column.
Set Variable [ $$helpLayoutName; Value:"Reference" ]
Set Variable [ $$helpColumnName; Value:"A" ]
Perform Script [ “help (update)” ]
#
#
