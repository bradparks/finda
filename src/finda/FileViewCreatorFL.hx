package finda;

import finda.ConversionCode;
import finda.Color;

class FileViewCreatorFL
{
    var bitmapTextCreator: BitmapTextCreator;
    var x:          Int;
    
    public function new( g2D: G2D, x_: Int )
    {
        x = x_;
        bitmapTextCreator = new BitmapTextCreator();
    }
    
    public inline function create(  g2D: G2D
                                ,   file:   FileSpec
                                ,   tx:     String
                                ,   h:      Int 
                                ,   c:      Colour ): FileView
    {
        var shape   = bitmapTextCreator.getBitmap( tx );
        var wide    = Std.int( shape.width );
        var hi      = Std.int( shape.height );
        var xpos    = x;
        var ypos    = h += hi;
        Justinfront.changeColor( shape, c );
        
        var fileView: FileView = {   file:           file
                    ,   shape:          shape
                    ,   change:         false
                    ,   color:          c
                    ,   x:              xpos
                    ,   y:              ypos
                    ,   width:          wide
                    ,   height:         hi 
                    };
                    
        return fileView;
        
    }
}