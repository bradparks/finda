package finda;
import flash.text.Font;
import flash.text.TextFormat;
import flash.text.TextField;
import finda.Justinfront;

import flash.text.TextFieldAutoSize;
import flash.display.Sprite;
import flash.display.Bitmap;
import flash.display.BitmapData;
import flash.geom.Point;
import flash.geom.Rectangle;


@:font( '/Library/Fonts/Georgia.ttf', ' a-z0-9A-Z_' )
class Georgia extends flash.text.Font{}

class BitmapTextCreator
{
    
    var font:   Font;
    var fmt:    TextFormat;
    var tf:     TextField;
    
    public function new ()
    {
        font = new Georgia();
        fmt = new TextFormat();
        fmt.size = 23;
        fmt.font = font.fontName;
        fmt.color = 0x000000;
        tf = new TextField();
        tf.embedFonts = true;
        tf.defaultTextFormat = fmt;
        tf.y = 0;
        tf.x = 0;
        tf.text = "BitmapTextCreator";
        tf.selectable = false;
        tf.autoSize = TextFieldAutoSize.LEFT;
        //tf.width = 1;
        //tf.wordWrap = true; 
    }
    
    public function getBitmap( str: String ): Bitmap
    {
        tf.text = str;
        //trace( tf.width + ' ' + tf.height );
        return new Bitmap( Justinfront.copyToBitmapWithTransparency( tf ) );
    }
    
}