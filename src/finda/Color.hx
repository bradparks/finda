package finda;

#if !java
class Color{
    public inline static var BLUE: Int = 0x0000FF;
    public inline static var BLACK: Int = 0x000000;
    public inline static var RED: Int = 0xff0000;
}
#else
typedef Color = java.awt.Color;
#end