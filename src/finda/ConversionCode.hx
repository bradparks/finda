package finda;

#if java
typedef Colour = java.awt.Color;
typedef G2D = java.awt.Graphics2D;
typedef MouseEvent = java.awt.event.MouseEvent;
#else
typedef Colour = Int;
typedef G2D = flash.display.Sprite;//flash.display.Graphics;
typedef MouseEvent = flash.events.MouseEvent;
#end