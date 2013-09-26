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
    
    var surface:        Surface;
    var shapes:         Array<FileView>;
    var view_ls:        View_ls;
    var view_ls2:       View_ls;
    var fileView:       FileView;
    var view:           View_ls;
    var dx:             Float;
    var dy:             Float;
    var down:           Bool        = false;
    
    public static function main() { new Main(); } public function new()
    {
        super( 'Finda ( java ver: ' + System.getProperty('java.version')  +')');
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
        surface.paintFunction = paintViews;
        view_ls = new View_ls( './', 25, 25 );
        view_ls2 = new View_ls( '/', 300, 25 );
        getContentPane().add( surface );
        surface.addKeyListener( this );
        surface.setFocusable( true );
        surface.requestFocusInWindow();
        addMouseListener( this );
        addMouseMotionListener( this );
    }
    
    public function paintViews( g2D: Graphics2D ): Void
    {
        view_ls.repaint( g2D );
        view_ls2.repaint( g2D );
        g2D.dispose();
    }
    
    // Mouse and keyboard events ready to be used...
    public function mousePressed( e: MouseEvent )
    {
        var point   =  e.getPoint();
        if( fileView != null )
        {
            dx = point.x - fileView.x;
            dy = point.y - fileView.y;
            down = true;
        }
        else
        {
            down = false;
        }
    }
    
    public function mouseDragged( e: MouseEvent ) 
    {
        if( down )
        {
            fileView.x = e.getX() - dx;
            fileView.y = e.getY() - dy;
            fileView.change = true;
            //trace( fileView.file.name );
            surface.repaint();
        }
    }
    
    public function mouseExited( e: MouseEvent ) {}
    public function mouseMoved( e: MouseEvent ) overCheck( e ); 
    public function overCheck( e: MouseEvent )
    {
        var fileView1 = view_ls.overCheck( e ) ;
        var fileView2 = view_ls2.overCheck( e );
        var bool1 = fileView1 != null;
        var bool2 = fileView2 != null;
        if(     bool1
            ||  bool2
            )
        {
            e.getComponent().setCursor( 
                Cursor.getPredefinedCursor( Cursor.HAND_CURSOR )
                                    );
            if( bool1 )
            {
                fileView = fileView1;
                view = view_ls;
            } else if( bool2 )
            {
                fileView = fileView2;
                view = view_ls2;
            }
        } 
        else
        {
            e.getComponent().setCursor(
                Cursor.getPredefinedCursor( Cursor.DEFAULT_CURSOR )
                                    );
            fileView = null;
        }
    }
    
    public function mouseEntered( e: MouseEvent ) {}  
    public function mouseClicked( e: MouseEvent ) {
        if( fileView != null )
        {
            view.clicked( fileView );
            surface.repaint();
        }
    }  
    public function mouseReleased( e: MouseEvent ){
        down = false;
    }
    public function keyTyped( e: KeyEvent ) {}
    public function keyReleased(e: KeyEvent ) {}
    public function keyPressed( e: KeyEvent ) {};

}