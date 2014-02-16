package finda;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class FileViewStructure extends haxe.lang.HxObject
{
	public    FileViewStructure(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    FileViewStructure()
	{
		finda.FileViewStructure.__hx_ctor_finda_FileViewStructure(this);
	}
	
	
	public static   void __hx_ctor_finda_FileViewStructure(finda.FileViewStructure __temp_me8)
	{
		{
		}
		
	}
	
	
	public static   haxe.root.Array<java.lang.Object> construct(java.awt.Graphics2D g2D, java.lang.String path, int x, int y)
	{
		java.lang.String p = path;
		haxe.lang.Function isDir = ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (sys.FileSystem.class) ), haxe.lang.Runtime.toString("isDirectory"))) );
		haxe.lang.Function stat = ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (sys.FileSystem.class) ), haxe.lang.Runtime.toString("stat"))) );
		haxe.lang.Function charcode = ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (haxe.root.StringTools.class) ), haxe.lang.Runtime.toString("fastCodeAt"))) );
		haxe.root.Array<java.lang.String> ls = sys.FileSystem.readDirectory(p);
		finda.FileViewCreator fileViewCreator = new finda.FileViewCreator(((java.awt.Graphics2D) (g2D) ), ((int) (x) ));
		haxe.root.Array<java.lang.Object> shapes = new haxe.root.Array<java.lang.Object>();
		haxe.root.Array<java.lang.Object> folder = new haxe.root.Array<java.lang.Object>();
		folder.push(new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"fileStat", "isDir", "name"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{null, true, "<-"}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"firstLetter", "subDirLen"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (0) )) ), ((java.lang.Object) (((double) (0) )) )})));
		{
			int _g = 0;
			while (( _g < ls.length ))
			{
				java.lang.String f = ls.__get(_g);
				 ++ _g;
				java.lang.String pf = ( p + f );
				boolean hasDir = haxe.lang.Runtime.toBool(isDir.__hx_invoke1_o(0.0, pf));
				if (haxe.lang.Runtime.valEq(haxe.lang.StringExt.substr(f, 0, 1), ".")) 
				{
					hasDir = false;
				}
				
				int len = 0;
				if (hasDir) 
				{
					haxe.root.Array<java.lang.String> ls2 = sys.FileSystem.readDirectory(( ( p + "/" ) + f ));
					len = ls2.length;
				}
				 else 
				{
					len = 0;
				}
				
				java.lang.Object __temp_stmt55 = null;
				{
					int __temp_odecl53 = ((int) (charcode.__hx_invoke2_f(0.0, ((double) (0) ), f, haxe.lang.Runtime.undefined)) );
					java.lang.Object __temp_odecl54 = ((java.lang.Object) (stat.__hx_invoke1_o(0.0, pf)) );
					__temp_stmt55 = new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"fileStat", "isDir", "name"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{__temp_odecl54, hasDir, f}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"firstLetter", "subDirLen"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (__temp_odecl53) )) ), ((java.lang.Object) (((double) (len) )) )}));
				}
				
				folder.push(__temp_stmt55);
			}
			
		}
		
		folder.sort(( (( finda.Fun_b3049195.__hx_current != null )) ? (finda.Fun_b3049195.__hx_current) : (finda.Fun_b3049195.__hx_current = ((finda.Fun_b3049195) (new finda.Fun_b3049195()) )) ));
		int h = y;
		{
			int _g = 0;
			while (( _g < folder.length ))
			{
				java.lang.Object file = folder.__get(_g);
				 ++ _g;
				java.lang.String tx = haxe.lang.Runtime.toString(haxe.lang.Runtime.getField(file, "name", true));
				java.awt.Color c = null;
				if (( ! (( haxe.lang.Runtime.getField(file, "fileStat", true) == null )) )) 
				{
					tx += ( "   " + ((int) (haxe.lang.Runtime.getField_f(haxe.lang.Runtime.getField(file, "fileStat", true), "size", true)) ) );
					c = ( (haxe.lang.Runtime.toBool(haxe.lang.Runtime.getField(file, "isDir", true))) ? (java.awt.Color.BLACK) : (java.awt.Color.BLUE) );
					if (haxe.lang.Runtime.toBool(haxe.lang.Runtime.getField(file, "isDir", true))) 
					{
						tx += ( ( " [" + ((int) (haxe.lang.Runtime.getField_f(file, "subDirLen", true)) ) ) + "]" );
					}
					
				}
				 else 
				{
					c = java.awt.Color.RED;
				}
				
				java.lang.Object fileView = null;
				{
					int h1 = h;
					java.awt.font.GlyphVector gv = fileViewCreator.font.createGlyphVector(((java.awt.font.FontRenderContext) (fileViewCreator.frc) ), haxe.lang.Runtime.toString(tx));
					int wide = fileViewCreator.metrics.stringWidth(haxe.lang.Runtime.toString(tx));
					int hi = fileViewCreator.metrics.getHeight();
					int l = gv.getNumGlyphs();
					java.awt.geom.GeneralPath newPath = new java.awt.geom.GeneralPath();
					int xpos = fileViewCreator.x;
					int ypos = h1 += hi;
					{
						int _g1 = 0;
						while (( _g1 < ((int) (l) ) ))
						{
							int i = _g1++;
							newPath.append(((java.awt.Shape) (gv.getGlyphOutline(((int) (i) ))) ), haxe.lang.Runtime.toBool(false));
						}
						
					}
					
					java.awt.geom.AffineTransform at2 = new java.awt.geom.AffineTransform();
					at2.translate(((double) (xpos) ), ((double) (ypos) ));
					java.awt.Shape shape = at2.createTransformedShape(((java.awt.Shape) (newPath) ));
					java.lang.Object fileView1 = new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"change", "color", "file", "generalPath", "shape"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{false, c, file, newPath, shape}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"height", "width", "x", "y"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (hi) )) ), ((java.lang.Object) (((double) (wide) )) ), ((java.lang.Object) (((double) (xpos) )) ), ((java.lang.Object) (((double) (ypos) )) )}));
					fileView = fileView1;
				}
				
				h = ((int) (haxe.lang.Runtime.getField_f(fileView, "y", true)) );
				shapes.push(fileView);
			}
			
		}
		
		return shapes;
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new finda.FileViewStructure(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new finda.FileViewStructure();
	}
	
	
}


