package finda;

import finda.ConversionCode;
import finda.Color;
//import java.awt.event.MouseEvent;
//import java.awt.Font;
//import java.awt.geom.AffineTransform;
//import java.awt.Color;
//import java.awt.geom.GeneralPath;
//import java.awt.Cursor;


class FileViewStructure
{
    
    public static inline function construct( g2D: G2D, path: String, x: Int, y: Int ):Array<FileView>
    {
        var p           = path;
        var isDir       = sys.FileSystem.isDirectory;
        var stat        = sys.FileSystem.stat;
        var charcode    = StringTools.fastCodeAt;
        var ls          = sys.FileSystem.readDirectory( p );
        #if java
            var fileViewCreator = new FileViewCreator( g2D, x );
        #else
            var fileViewCreator = new FileViewCreatorFL( g2D, x );
        #end
        var shapes      = new Array<FileView>();
        var folder      = new Array<FileSpec>();
        folder.push({ name: '<-', isDir: true, firstLetter: 0, fileStat: null, subDirLen: 0 });
        
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
            var c: Colour;
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
            #if java
                var fileView = fileViewCreator.create( g2D, file, tx, h, c  );
                h = fileView.y;
                shapes.push( fileView );
            #else
                var fileView = fileViewCreator.create( g2D, file, tx, h, c  );
                h = fileView.y;
                shapes.push( fileView );
                // implement non java fileViewCreator
            #end
         }
         return shapes;
    }
}