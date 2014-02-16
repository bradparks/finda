package finda;
import java.awt.Color;
import java.awt.Graphics2D;
import java.awt.Font;
import java.awt.FontMetrics;
import java.awt.font.FontRenderContext;
import java.awt.geom.GeneralPath;
import java.awt.geom.AffineTransform;

class FileViewCreator
{    
    
    var font:       Font;
    var frc:        FontRenderContext;
    var metrics:    FontMetrics;
    var x:          Int;
    
    public function new( g2D: Graphics2D, x_: Int )
    {
        x       = x_;
        font    = new Font( "Georgia", Font.PLAIN, 23 ); 
        frc     = g2D.getFontRenderContext();
        metrics = g2D.getFontMetrics( font );
    }
    
    public inline function create(  g2D: Graphics2D
                                        ,   file:   FileSpec
                                        ,   tx:     String
                                        ,   h:      Int 
                                        ,   c:      Color ): FileView
    {
        
        var gv      = font.createGlyphVector( frc, tx );
        var wide    = metrics.stringWidth( tx );
        var hi      = metrics.getHeight();
        var l       = gv.getNumGlyphs();
        var newPath = new GeneralPath();
        var xpos    = x;
        var ypos    = h += hi;
        
        for( i in 0...l ) newPath.append( gv.getGlyphOutline( i ), false );
        var at2 = new AffineTransform();
        at2.translate( xpos, ypos );
        var shape = at2.createTransformedShape( newPath );
        var fileView: FileView = {   file:           file
                    ,   shape:          shape
                    ,   generalPath:    newPath
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