package finda;

import sys.io.File;
import javax.swing.JFrame;
import javax.swing.JPanel;
import java.awt.Color;
import java.awt.Cursor;
import java.awt.event.KeyEvent;
import java.awt.event.KeyListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;
import java.awt.event.MouseEvent;
import java.lang.System;
import java.awt.Graphics2D;
import java.awt.Font;
import java.awt.geom.Rectangle2D;
import java.awt.font.FontRenderContext;
import java.awt.geom.GeneralPath;
import java.awt.Shape;
import java.awt.geom.AffineTransform;
import java.lang.System;
import finda.Justinfront;
using finda.Justinfront;
class Main extends JFrame
implements KeyListener 
implements MouseListener 
implements MouseMotionListener
{
    var surface:                    Surface;
    var shapes:                     Array<FileView>;
    public static function main() { new Main(); } public function new()
    {
        super( 'FileReader ( java ver: ' + System.getProperty('java.version')  +')');
        System.setProperty( "sun.java2d.opengl", "True" );
        shapes = new Array();
        setup();
        createSurface();
        
        setVisible( true );
    }
    
    function setup()
    {
        setSize( 700, 500 );
        
        setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
        setBackground( Color.WHITE );
        
    }
    
    function createSurface()
    {
        
        surface = new Surface();
        
        surface.paintFunction = firstPaint;        
        surface.repaint();
        getContentPane().add( surface );
        surface.addKeyListener( this );
        surface.setFocusable( true );
        surface.requestFocusInWindow();
        addMouseListener( this );
        addMouseMotionListener( this );
    }
    
    public function firstPaint( g2D: Graphics2D )
    {
        buildFileStructure( g2D );
        surface.paintFunction = secondPaint;
        surface.repaint();
    }
    
    public function secondPaint( g2D: Graphics2D )
    {   
        for( fileView in shapes )
        {
            g2D.setColor( fileView.color );
            g2D.fill( fileView.shape );
        }   
        g2D.dispose();
    }
    
    public function buildFileStructure( g2D: Graphics2D )
    {
        var p = './';
        var isDir = sys.FileSystem.isDirectory;
        var stat = sys.FileSystem.stat;
        var charcode = StringTools.fastCodeAt;
        var ls = sys.FileSystem.readDirectory( p );
        var font = new Font( "Georgia", Font.PLAIN, 24 ); 
        var frc = g2D.getFontRenderContext();
        var metrics = g2D.getFontMetrics( font );
        //g2D.setFont( font );
        
        var folder = new Array<FileSpec>();
        for( f in ls )
        {
             folder.push( {  name:           f, 
                             isDir:          isDir( p + f ), 
                             firstLetter:    charcode( f, 0 ),
                             fileStat:       stat( p + f )
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
             
        var h = 20;
        for( file in folder )
        {
            var tx = file.name + '   ' + file.fileStat.size;
            var gv = font.createGlyphVector( frc, tx );
            //var metrics = font.getLineMetrics( tx, frc );
             
             
             var wide = metrics.stringWidth( tx );
             //trace( wide );
             var hi = metrics.getHeight();
             
             //var bounds = metrics.getStringBounds( tx, frc );
             
             //var wide = 10; //bounds.getWidth();
             //var hi = 10; //bounds.getHeight()
             //g2D.translate( 25, h += 20 );
             var l = gv.getNumGlyphs();
             
             var newPath = new GeneralPath( );
             
             // iterate through the letters and append to a new path.
             for( i in 0...l ) newPath.append( gv.getGlyphOutline( i ), false );
             //g2D.drawString( file.name + '   ' + file.fileStat.size, 25, h += 20 );
             // Hit test area ... 
             var c: Color;
             if( file.isDir )
             {
                 c = Color.BLACK;
             }
             else
             {
                 c = Color.BLUE;
             }
             var at2 = new AffineTransform();
             var x = 25;
             var y = h += hi;
             at2.translate( x, y );
             var shape = at2.createTransformedShape( newPath );
             shapes.push( { file: file, shape: shape, color: c
                            , x: x, y: y
                            , width: wide
                            , height: hi } );
         }
    }
    
    // Mouse and keyboard events ready to be used...
    public function mousePressed( e: MouseEvent ) {}
    public function mouseDragged( e: MouseEvent ) {}
    public function mouseExited( e: MouseEvent ) {}
    public function mouseMoved( e: MouseEvent ) overCheck( e ); 
    
    public function overCheck( e: MouseEvent )
    {
        var showCursor = false;
        var point   =  e.getPoint();
        for( fileView in shapes )
        {
            if( point.x > fileView.x &&
                point.x < fileView.x + fileView.width &&
                point.y > fileView.y && 
                point.y < fileView.y + fileView.height
            ) showCursor = true;
        }
        if( showCursor ) 
        {
            e.getComponent().setCursor( 
                Cursor.getPredefinedCursor( Cursor.HAND_CURSOR )
                                    );
        } 
        else
        {
            e.getComponent().setCursor(
                Cursor.getPredefinedCursor( Cursor.DEFAULT_CURSOR )
                                    );
        }
    }
    public function mouseEntered( e: MouseEvent ) {}  
    public function mouseClicked( e: MouseEvent ) {}  
    public function mouseReleased( e: MouseEvent ){}
    public function keyTyped( e: KeyEvent ) {}
    public function keyReleased(e: KeyEvent ) {}
    public function keyPressed( e: KeyEvent ) {};

}