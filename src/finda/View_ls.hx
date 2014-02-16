package finda;

#if java
import java.awt.event.MouseEvent;
//import java.awt.Font;
import java.awt.geom.AffineTransform;
//import java.awt.geom.GeneralPath;
import java.awt.Cursor;
#else 

#end
import finda.ConversionCode;

class View_ls
{
    public var x:       Int = 0;
    public var y:       Int = 0;
    public var pathInfo:    PathInfo;
    public var repaint:     G2D -> Void;
    var shapes:             Array<FileView>;
    
    public function new( pathInfo_: PathInfo, x_: Int, y_: Int )
    {
        x = x_;
        y = y_;
        pathInfo = pathInfo_;
        change();
    }
    
    public function change()
    {
        repaint = firstPaint;
    }
    
    
    public function firstPaint( g2D: G2D ): Void
    {
        shapes = FileViewStructure.construct( g2D, pathInfo.path, x, y );
        repaint = secondPaint;
        repaint( g2D );
    }
    
    public function secondPaint( g2D: G2D ): Void
    {   
        for( fileView in shapes )
        {
            #if java
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
            #else
                fileView.shape.x = fileView.x;
                fileView.shape.y = fileView.y;
                g2D.addChild( fileView.shape );
            #end
        }
    }
    
    public function clicked( f: FileView ){
        if( f.file.isDir ){
            if( f.file.name == '<-' ){ 
                pathInfo.changePath( pathInfo.parent );
                change();
            }else{
                pathInfo.changePath( pathInfo.full + '/' + f.file.name + '/' );
                change();
            }
        }
    }
    
    public function overCheck( e: MouseEvent ): FileView
    {
        #if java
            var point   =  e.getPoint();
        #else
            var point   = { x: e.localX, y: e.localY };
        #end
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