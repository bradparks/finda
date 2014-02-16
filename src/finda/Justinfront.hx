package finda;
#if !java 
    import flash.display.Sprite;
    import flash.display.DisplayObject;
    import flash.display.Bitmap;
    import flash.display.BitmapData;
    import flash.geom.Point;
    import flash.geom.Rectangle;
    import flash.geom.ColorTransform;
#end

class Justinfront
{
    public static function name<T>( o: T ): String
    {
        var clazz = Type.getClass( o );
        return Type.getClassName( clazz );
    }
    
    #if !java
        public static inline function copyToBitmapWithTransparency( mc: DisplayObject ): BitmapData
        {

            var wide:       Int             = Std.int( mc.width );
            var hi:         Int             = Std.int( mc.height );

            var point:      Point           = new Point( 0, 0 );
            var rect:       Rectangle       = new Rectangle( 0 , 0, wide, hi );
            var abitmap:    BitmapData      = new BitmapData( wide, hi, true, 0x0000000 );
            abitmap.draw( mc );
            abitmap.copyPixels( abitmap, rect, point, abitmap, point, false );
            return abitmap;

        }
        
        public static inline function changeColor( bm: Bitmap, col: Int )
        {
            var red = col >> 16;
            var green = col >> 8 & 0xFF;
            var blue = col & 0xFF;
            bm.transform.colorTransform = new ColorTransform( 0, 0, 0, 1, red, green, blue, 0 );
        }
    #end
}