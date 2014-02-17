package finda;

#if java    
    import javax.swing.JFrame;
    import java.awt.Cursor;
    import java.awt.event.KeyEvent;
    import java.awt.event.KeyListener;
    import java.awt.event.MouseAdapter;
    import java.awt.event.MouseListener;
    import java.awt.event.MouseMotionListener;
    import java.awt.event.MouseEvent;
    import java.lang.System;
    import java.awt.Graphics2D;
#else
    import flash.display.Sprite;
    import finda.Justinfront;
    import flash.events.MouseEvent;
#end

// used for java target
    import finda.Justinfront;
    using finda.Justinfront;

class Main
#if java
    extends JFrame
    implements KeyListener 
    implements MouseListener 
    implements MouseMotionListener
#else
    extends Sprite
#end
{
    
    #if java
        var surface:        Surface;
        var shapes:         Array<FileView>;
    #else
        var sp:             Sprite;
    #end
    
   
    var view_ls:        View_ls;
    var view_ls2:       View_ls;
    var pathInfo:       PathInfo;
    var pathInfo2:      PathInfo;
    var fileView:       FileView;
    var view:           View_ls;
    var pathI:          PathInfo;
    var dx:             Int;
    var dy:             Int;
    var down:           Bool        = false;
    var boundary:       Int         = 250;
    
    // static main not needed for openfl
    #if java
    public static function main() { new Main(); } 
    #end 
    
    public function new () {
        
        #if java
            super( 'Finda ( java ver: ' + System.getProperty('java.version')  +')');
            System.setProperty( "sun.java2d.opengl", "True" );
            shapes = new Array();
            setup();
            createSurface();
        #else
            super ();
            // use a sprite for mouse
            sp = new Sprite();
            addChild( sp );
        #end
        
        createViews();
        #if java
            setVisible( true );
        #else
            repaint();
        #end
        setupListeners();
        
    }
    
    #if java
    function setup() {
        setSize( 700, 500 );
        setDefaultCloseOperation( JFrame.EXIT_ON_CLOSE );
        setBackground( Color.WHITE );
    }
    
    function createSurface() {
        surface = new Surface();
        surface.paintFunction = paintViews;
        getContentPane().add( surface );
    }
    #end
    
    function createViews(){
        
        #if !java
            var offsetDir = '../../../../../../';
        #else
            var offsetDir = '';
        #end
        
        pathInfo = new PathInfo( offsetDir + './' );
        pathInfo2 = new PathInfo( offsetDir + '../' );
        //pathInfo.tracePaths();
        view_ls = new View_ls( pathInfo, 25, 25 );
        view_ls2 = new View_ls( pathInfo2, 300, 25 );
    }
    
    #if java 
        function setupListeners()
        {
            surface.addKeyListener( this );
            surface.setFocusable( true );
            surface.requestFocusInWindow();
            addMouseListener( this );
            addMouseMotionListener( this );
        }
    #else
        function setupListeners()
        {
            sp.buttonMode = true;
            sp.mouseChildren = false;
            sp.useHandCursor = true;
            sp.addEventListener( MouseEvent.MOUSE_MOVE, mouseMoved );//, false, 0, true);
            sp.addEventListener( MouseEvent.MOUSE_DOWN, mousePressed );
            sp.addEventListener( MouseEvent.MOUSE_UP, mouseReleased );
            sp.addEventListener( MouseEvent.CLICK, mouseClicked );
        }
    #end
    
    #if java
        public function paintViews( g2D: Graphics2D ): Void {
            view_ls.repaint( g2D );
            view_ls2.repaint( g2D );
            g2D.dispose();
        }
    #else
        public function repaint(){
            while( sp.numChildren > 0 ) sp.removeChildAt(0);
            view_ls.repaint( sp );
            view_ls2.repaint( sp );
        }
    #end
    
    public function mouseMoved( e: MouseEvent ) overCheck( e ); 
    public function overCheck( e: MouseEvent ) {
        var fileView1 = view_ls.overCheck( e ) ;
        var fileView2 = view_ls2.overCheck( e );
        var bool1 = fileView1 != null;
        var bool2 = fileView2 != null;
        if( bool1 ||  bool2 ) {
            
            #if java
                e.getComponent().setCursor( 
                    Cursor.getPredefinedCursor( Cursor.HAND_CURSOR )
                                        );
            #else
                sp.useHandCursor = true;
            #end
            
            if( bool1 ){
                fileView = fileView1;
                pathI = pathInfo;
                view = view_ls;
            } else if( bool2 ){
                fileView = fileView2;
                pathI = pathInfo2;
                view = view_ls2;
            }
        } else {
            #if java
                e.getComponent().setCursor(
                    Cursor.getPredefinedCursor( Cursor.DEFAULT_CURSOR )
                                        );
            #else
                sp.useHandCursor = false;
            #end
            fileView = null;
        }
        #if !java
            if( down ) mouseDragged( e );
        #end
    }
    
    public function mousePressed( e: MouseEvent ) {
        #if java
            var point   =  e.getPoint();
        #else
            var point   = { x: e.localX, y: e.localY };
        #end
        if( fileView != null )
        {
            dx = Std.int( point.x - fileView.x );
            dy = Std.int( point.y - fileView.y );
            down = true;
        } else {
            down = false;
        }
    }
    
    #if java
        public function mouseDragged( e: MouseEvent ) {
            if( down ) {
                fileView.x = e.getX() - dx;
                fileView.y = e.getY() - dy;
                fileView.change = true;
                //trace( fileView.file.name );
                surface.repaint();
            }
        }
    #else
        public function mouseDragged( e: MouseEvent ) {
            //if( down ) {
                fileView.x = Std.int( e.localX - dx );
                fileView.y = Std.int( e.localY - dy );
                fileView.change = true;
                //trace( fileView.file.name );
                repaint();
            //}
        }
    #end
    
    public function mouseClicked( e: MouseEvent ) {
        if( fileView != null ) {
            view.clicked( fileView );
            #if java
                surface.repaint();
            #else
                repaint();
            #end
        }
    }
    
    
    
    public function mouseReleased( e: MouseEvent ){
        down = false;
        //if( fileView.file.name == 'test.txt' )
        //{
            if( fileView.x < boundary && view == view_ls2 ) {
                sys.FileSystem.rename( pathI.path + '/' + fileView.file.name, pathInfo.path + '/' + fileView.file.name );
                // this is slight overkill
                pathI.changePath( pathInfo.path );
                pathI.changePath( pathInfo2.path );
                view_ls.change();
                view_ls2.change();
                
                #if java
                    surface.repaint();
                #else
                    repaint();
                #end
                
            } else if( fileView.x > boundary && view == view_ls ) {
                sys.FileSystem.rename( pathI.path + '/' + fileView.file.name, pathInfo2.path + '/' + fileView.file.name );
                // this is slight overkill
                pathI.changePath( pathInfo.path );
                pathI.changePath( pathInfo2.path );
                view_ls.change();
                view_ls2.change();
                
                #if java
                    surface.repaint();
                #else
                    repaint();
                #end
                
            } else {
                // very lazy!  Must change this!!
                view_ls.change();
                view_ls2.change();
                
                #if java
                    surface.repaint();
                #else
                    repaint();
                #end
                
            }
            
        //}
    }
    
    #if java
        public function mouseExited( e: MouseEvent ) {}
        public function mouseEntered( e: MouseEvent ) {}  
        public function keyTyped( e: KeyEvent ) {}
        public function keyReleased(e: KeyEvent ) {}
        public function keyPressed( e: KeyEvent ) {};
    #end
    
}