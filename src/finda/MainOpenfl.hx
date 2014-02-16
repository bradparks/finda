package finda;

import flash.display.Sprite;
import finda.Justinfront;
import flash.events.MouseEvent;


class MainOpenfl extends Sprite {

    var sp:             Sprite;
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
    
    public function new () {
        
        super ();
        // use a sprite for mouse
        sp = new Sprite();
        addChild( sp );
        
        var offsetDir = '../../../../../../';
        pathInfo = new PathInfo( offsetDir + './' );
        pathInfo2 = new PathInfo( offsetDir + '../' );
        //pathInfo.tracePaths();
        view_ls = new View_ls( pathInfo, 25, 25 );
        view_ls2 = new View_ls( pathInfo2, 300, 25 );
        
        repaint();
        setupListeners();
        
    }
    
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
    
    public function repaint()
    {
        while( sp.numChildren > 0 ) sp.removeChildAt(0);
        view_ls.repaint( sp );
        view_ls2.repaint( sp );
    }
    
    public function mouseMoved( e: MouseEvent ) overCheck( e ); 
    public function overCheck( e: MouseEvent ) {
        var fileView1 = view_ls.overCheck( e ) ;
        var fileView2 = view_ls2.overCheck( e );
        var bool1 = fileView1 != null;
        var bool2 = fileView2 != null;
        if( bool1 ||  bool2 ) {
            sp.useHandCursor = true;
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
            sp.useHandCursor = false;
            fileView = null;
        }
        if( down )
        {
            mouseDragged( e );
        }
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
    
    public function mouseDragged( e: MouseEvent ) {
        //if( down ) {
            fileView.x = Std.int( e.localX - dx );
            fileView.y = Std.int( e.localY - dy );
            fileView.change = true;
            //trace( fileView.file.name );
            repaint();
        //}
    }
    public function mouseClicked( e: MouseEvent ) {
        if( fileView != null ) {
            view.clicked( fileView );
            repaint();
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
                repaint();
            } 
            else if( fileView.x > boundary && view == view_ls ) {
                sys.FileSystem.rename( pathI.path + '/' + fileView.file.name, pathInfo2.path + '/' + fileView.file.name );
                // this is slight overkill
                pathI.changePath( pathInfo.path );
                pathI.changePath( pathInfo2.path );
                view_ls.change();
                view_ls2.change();
                repaint();
            } else {
                // very lazy!  Must change this!!
                view_ls.change();
                view_ls2.change();
                repaint();
                
            }
            
        //}
    }
}