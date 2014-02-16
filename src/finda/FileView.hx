package finda;
import finda.ConversionCode;


import finda.View_ls;

typedef FileView =
{
    file: FileSpec,
    #if java
        shape: java.awt.Shape,
        generalPath: java.awt.geom.GeneralPath,
    #else
        shape: flash.display.Bitmap,
    #end
    change: Bool,
    color: Colour,
    x: Int,
    y: Int,
    width: Int,
    height: Int
}