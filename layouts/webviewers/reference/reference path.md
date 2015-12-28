//Case ( citationList::URL = ""  or Get ( HostIPAddress ) = "" or citationList::kfolderPath = "" ; "" ;

//References to related tables are allowed if the are not providing data to be used in the web viewer.
//Only fields from the layout's table are able to provide usable data.  This was not an issue here,
//but just wanted to make note of this because it took a lot of tinkering to figure out.
//Show image only if it is a picture or text file as current html code below does not have embed tags
//to show audio/media files.

Case (
reference::kfileLocation ≠ ""  and reference::fileName ≠ "" and Right ( reference::fileName ; 3 )  = "jpg"
or reference::kfileLocation ≠ ""  and reference::fileName ≠ "" and Right ( reference::fileName ; 3 )  = "gif"
or reference::kfileLocation ≠ ""  and reference::fileName ≠ "" and Right ( reference::fileName ; 3 )  = "eps"
or reference::kfileLocation ≠ ""  and reference::fileName ≠ "" and Right ( reference::fileName ; 3 )  = "jp2"
or reference::kfileLocation ≠ ""  and reference::fileName ≠ "" and Right ( reference::fileName ; 3 )  = "psd"
or reference::kfileLocation ≠ ""  and reference::fileName ≠ "" and Right ( reference::fileName ; 3 )  = "png"
or reference::kfileLocation ≠ ""  and reference::fileName ≠ "" and Right ( reference::fileName ; 3 )  = "pct"
or reference::kfileLocation ≠ ""  and reference::fileName ≠ "" and Right ( reference::fileName ; 3 )  = "pcs"
or reference::kfileLocation ≠ ""  and reference::fileName ≠ "" and Right ( reference::fileName ; 3 )  = ".qt"
or reference::kfileLocation ≠ ""  and reference::fileName ≠ "" and Right ( reference::fileName ; 3 )  = "sgi"
or reference::kfileLocation ≠ ""  and reference::fileName ≠ "" and Right ( reference::fileName ; 3 )  = "tga"
or reference::kfileLocation ≠ ""  and reference::fileName ≠ "" and Right ( reference::fileName ; 3 )  = "tif"
or reference::kfileLocation ≠ ""  and reference::fileName ≠ "" and Right ( reference::fileName ; 3 )  = "bmp"
or reference::kfileLocation ≠ ""  and reference::fileName ≠ "" and Right ( reference::fileName ; 3 )  = "wmf"
or reference::kfileLocation ≠ ""  and reference::fileName ≠ "" and Right ( reference::fileName ; 3 )  = "emf"

// The web viewer could show PDF image, but it is so small that it provides no useful information
//other than to put an icon in the viewer.  And since I am not putting icons for all the other types
//of media like movies, I the rule is no icons at all in this viewer.  The rule is this viewer is for pictures
//that help the user understand the tag and not the a file attached to the tag.  The next bit is the
//code neccessary to show a PDF:  or citationList::kfileLocation ≠ ""  and citationList::fileName ≠ ""
//and ruleCitationCategoryMedia::name = "text"

;  Let([

//depending on the file path selected the webview has three possible paths for a file.

Fpath = Case (
FilterValues ( reference::kfileLocation ; "8162011225532313" ) = "8162011225532313" & ¶ ;

Substitute ( Case ( Get ( SystemPlatform ) =  - 2 ; "file:" ; "file:/" )& Middle ( Get ( FilePath ) ; 6 ;
Length ( Get (FilePath ) ) - Length ( Get (FileName ) ) - 9) & "x/" ; " " ; "%20" ) ;

FilterValues ( reference::kfileLocation ; "8162011225558314" ) = "8162011225558314" & ¶ ;

Substitute ( Case ( Get ( SystemPlatform ) =  - 2 ; "file:" ; "file:/" ) & Middle ( Get ( FilePath ) ; 6 ;
Length ( Get (FilePath ) ) - Length ( Get (FileName ) ) - 9) ; " " ; "%20" ) ;

FilterValues ( reference::kfileLocation ; "8162011225605315" ) = "8162011225605315" & ¶ ;

Substitute ( Case ( Get ( SystemPlatform ) =  - 2 ; "file:/" ; "file:///" ) & tagRefFolderPath::tag ; " " ; "%20" ) & "/";

"");


//In webviewer quotes operate differently from regular calc field.  The color hex numbers
//below have to be in quotes, so this would be the normal way to do that in calc field:
// If ( citationList::kmedia = "711201118061225" ; Quote ( "#eeeeee" ); Quote ( "#565e74" ) )
//But in the webviewer calc below is what works.
//Some PDF files have a transparent background which requires the white #eeeeee in order
//to show up.  It may be that this color background needs to be set at the category level for
//white bacground pdf, gifs, and pngs.

Bcolor = "#565e74";

//The picture name completes the filepath.

Picture = Substitute ( reference::fileName ; " " ; "%20" ) ];

"data:text/html,<html>¶

<body  bgcolor=\"" & Bcolor & "\" LeftMargin=\"0\" RightMargin=\"0\" TopMargin=\"0\" BottomMargin=\"0\"  border=\"0\" style=\"border:0;scrolling:no\">¶¶" &

"<div align=\" center\"> <img src=\"" & Fpath & Picture & "\"  height=\"100% \"  border=\"0\"><br>¶"  &
"</body>¶
</html>¶"
) ;



reference::URL ≠ "" and Right ( reference::URL ; 3 )= "jpg"
or reference::URL ≠ "" and Right ( reference::URL ; 3 )= "gif"
or reference::URL ≠ "" and Right ( reference::URL ; 3 )= "eps"
or reference::URL ≠ "" and Right ( reference::URL ; 3 )= "jp2"
or reference::URL ≠ "" and Right ( reference::URL ; 3 )= "psd"
or reference::URL ≠ "" and Right ( reference::URL ; 3 )= "png"
or reference::URL ≠ "" and Right ( reference::URL ; 3 )= "pct"
or reference::URL ≠ "" and Right ( reference::URL ; 3 )= "pcs"
or reference::URL ≠ "" and Right ( reference::URL ; 3 )= ".qt"
or reference::URL ≠ "" and Right ( reference::URL ; 3 )= "sgi"
or reference::URL ≠ "" and Right ( reference::URL ; 3 )= "tga"
or reference::URL ≠ "" and Right ( reference::URL ; 3 )= "tif"
or reference::URL ≠ "" and Right ( reference::URL ; 3 )= "bmp"
or reference::URL ≠ "" and Right ( reference::URL ; 3 )= "wmf"
or reference::URL ≠ "" and Right ( reference::URL ; 3 )= "emf"
;

Let([

Fpath = reference::URL;

Bcolor = "#565e74"];

"data:text/html,<html>¶

<body  bgcolor=\"" & Bcolor & "\" LeftMargin=\"0\" RightMargin=\"0\" TopMargin=\"0\" BottomMargin=\"0\"  border=\"0\" style=\"border:0;scrolling:no\">¶¶" &

"<div align=\" center\"> <img src=\"" & Fpath & "\"  height=\"100% \"  border=\"0\"><br>¶"  &
"</body>¶
</html>¶"
) ;




""   )