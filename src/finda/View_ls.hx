package finda;
import java.awt.Graphics2D;
import java.awt.event.MouseEvent;
import java.awt.Font;
import java.awt.geom.AffineTransform;
import java.awt.Color;
import java.awt.geom.GeneralPath;
import java.awt.Cursor;

class View_ls
{
    public var x:       Int = 0;
    public var y:       Int = 0;
    public var path:    String = './';
    public var full:    String;
    var parent:         String;
    public var repaint: Graphics2D -> Void;
    var shapes:         Array<FileView>;
    
    public function new( path_: String, x_: Int, y_: Int )
    {
        x = x_;
        y = y_;
        init( path_ );
    }
    
    public function init( path_: String )
    {
        path = path_;
        var charcode    = StringTools.fastCodeAt;
        full = sys.FileSystem.fullPath( path );
        var len = full.length;
        while( len > 0 && charcode( full, len-- ) != 47 ){}
        parent = full.substr( 0, len + 1 ) + '/';
        //trace( 'parent ' + parent );
        shapes = [];
        repaint = firstPaint;
    }
    
    
    public function firstPaint( g2D: Graphics2D ): Void
    {
        buildFileStructure( g2D );
        repaint = secondPaint;
        repaint( g2D );
    }
    
    public function secondPaint( g2D: Graphics2D ): Void
    {   
        for( fileView in shapes )
        {
            g2D.setColor( fileView.color );
            if( fileView.change )
            {
                var at2 = new AffineTransform();
                at2.translate( fileView.x, fileView.y );
                var shape = at2.createTransformedShape( fileView.generalPath );
                fileView.shape = shape;
                fileView.change = false;
            }
            g2D.fill( fileView.shape );
        }
    }
    
    public function buildFileStructure( g2D: Graphics2D )
    {
        var p           = path;
        var isDir       = sys.FileSystem.isDirectory;
        var stat        = sys.FileSystem.stat;
        var charcode    = StringTools.fastCodeAt;
        var ls          = sys.FileSystem.readDirectory( p );
        var font        = new Font( "Georgia", Font.PLAIN, 23 ); 
        var frc         = g2D.getFontRenderContext();
        var metrics     = g2D.getFontMetrics( font );
        var folder      = new Array<FileSpec>();
        folder.push({ name: '<-', isDir: true, firstLetter:0,fileStat: null, subDirLen: 0 });
        for( f in ls )
        {
             var pf = p + f;
             var hasDir = isDir( pf );
             if( f.substr( 0, 1 ) == '.' ) hasDir = false;
             var len = if( hasDir )
             {
                 var ls2 = sys.FileSystem.readDirectory( p + '/' + f );
                 ls2.length;
             } 
             else 
             { 0; }
             
             folder.push( {  name:           f, 
                             isDir:          hasDir, 
                             firstLetter:    charcode( f, 0 ),
                             fileStat:       stat( pf ),
                             subDirLen:      len
                             });
        }
        
        folder.sort(
             function( f1: FileSpec, f2: FileSpec ): Int
             {
                 if( f1.isDir && !f2.isDir ) return -1;
                 if( !f1.isDir && f2.isDir ) return 1;
                 if( f1.firstLetter > f2.firstLetter ) return 1;
                 if( f1.firstLetter < f2.firstLetter ) return -1;
                 return 0;
             }
        );
           
        var h = y;
        for( file in folder )
        {
            var tx      = file.name;
            var c: Color;
            if( file.fileStat != null )
            {
                tx += '   ' + file.fileStat.size;
                c = ( file.isDir )? Color.BLACK: Color.BLUE;
                if( file.isDir )
                {
                    tx += ' [' + file.subDirLen + ']';
                }
            } else
            {
                c = Color.RED;
            }
            
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
            shapes.push({   file:           file
                        ,   shape:          shape
                        ,   generalPath:    newPath
                        ,   change:         false
                        ,   color:          c
                        ,   x:              xpos
                        ,   y:              ypos
                        ,   width:          wide
                        ,   height:         hi 
                        } );
                        
         }
         
    }
    
    public function clicked( f: FileView )
    {
        if( f.file.isDir )
        {
            if( f.file.name == '<-' )
            { 
                init( parent );
            } 
            else
            {
                init( full + '/' + f.file.name + '/' );
            }
        }
    }
    
    public function overCheck( e: MouseEvent ): FileView
    {
        var point   =  e.getPoint();
        for( fileView in shapes )
        {
            if( point.x > fileView.x &&
                point.x < fileView.x + fileView.width &&
                point.y > fileView.y && 
                point.y < fileView.y + fileView.height
            ) 
            {
                return fileView;
            }
        }
        return null;
    }
}