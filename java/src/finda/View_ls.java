package finda;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class View_ls extends haxe.lang.HxObject
{
	public    View_ls(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    View_ls(java.lang.String path_, int x_, int y_)
	{
		finda.View_ls.__hx_ctor_finda_View_ls(this, path_, x_, y_);
	}
	
	
	public static   void __hx_ctor_finda_View_ls(finda.View_ls __temp_me8, java.lang.String path_, int x_, int y_)
	{
		__temp_me8.path = "./";
		__temp_me8.y = 0;
		__temp_me8.x = 0;
		__temp_me8.path = path_;
		__temp_me8.x = x_;
		__temp_me8.y = y_;
		__temp_me8.shapes = new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{});
		__temp_me8.repaint = ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (__temp_me8) ), haxe.lang.Runtime.toString("firstPaint"))) );
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new finda.View_ls(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new finda.View_ls(haxe.lang.Runtime.toString(arr.__get(0)), ((int) (haxe.lang.Runtime.toInt(arr.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(arr.__get(2))) ));
	}
	
	
	public  int x;
	
	public  int y;
	
	public  java.lang.String path;
	
	public  haxe.lang.Function repaint;
	
	public  haxe.root.Array<java.lang.Object> shapes;
	
	public   void firstPaint(java.awt.Graphics2D g2D)
	{
		this.buildFileStructure(g2D);
		this.repaint = ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("secondPaint"))) );
		this.repaint.__hx_invoke1_o(0.0, g2D);
	}
	
	
	public   void secondPaint(java.awt.Graphics2D g2D)
	{
		int _g = 0;
		haxe.root.Array<java.lang.Object> _g1 = this.shapes;
		while (( _g < _g1.length ))
		{
			java.lang.Object fileView = _g1.__get(_g);
			 ++ _g;
			g2D.setColor(((java.awt.Color) (haxe.lang.Runtime.getField(fileView, "color", true)) ));
			if (haxe.lang.Runtime.toBool(haxe.lang.Runtime.getField(fileView, "change", true))) 
			{
				java.awt.geom.AffineTransform at2 = new java.awt.geom.AffineTransform();
				at2.translate(((double) (haxe.lang.Runtime.getField_f(fileView, "x", true)) ), ((double) (haxe.lang.Runtime.getField_f(fileView, "y", true)) ));
				java.awt.Shape shape = at2.createTransformedShape(((java.awt.geom.GeneralPath) (haxe.lang.Runtime.getField(fileView, "generalPath", true)) ));
				haxe.lang.Runtime.setField(fileView, "shape", shape);
				haxe.lang.Runtime.setField(fileView, "change", false);
			}
			
			g2D.fill(((java.awt.Shape) (haxe.lang.Runtime.getField(fileView, "shape", true)) ));
		}
		
	}
	
	
	public   void buildFileStructure(java.awt.Graphics2D g2D)
	{
		java.lang.String p = this.path;
		haxe.lang.Function isDir = ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (sys.FileSystem.class) ), haxe.lang.Runtime.toString("isDirectory"))) );
		haxe.lang.Function stat = ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (sys.FileSystem.class) ), haxe.lang.Runtime.toString("stat"))) );
		haxe.lang.Function charcode = ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (haxe.root.StringTools.class) ), haxe.lang.Runtime.toString("fastCodeAt"))) );
		haxe.root.Array<java.lang.String> ls = sys.FileSystem.readDirectory(p);
		java.awt.Font font = new java.awt.Font(haxe.lang.Runtime.toString("Georgia"), ((int) (java.awt.Font.PLAIN) ), ((int) (24) ));
		java.awt.font.FontRenderContext frc = g2D.getFontRenderContext();
		java.awt.FontMetrics metrics = g2D.getFontMetrics(((java.awt.Font) (font) ));
		haxe.root.Array<java.lang.Object> folder = new haxe.root.Array<java.lang.Object>();
		{
			int _g = 0;
			while (( _g < ls.length ))
			{
				java.lang.String f = ls.__get(_g);
				 ++ _g;
				java.lang.String pf = ( p + f );
				java.lang.Object __temp_stmt60 = null;
				{
					boolean __temp_odecl56 = haxe.lang.Runtime.toBool(isDir.__hx_invoke1_o(0.0, pf));
					int __temp_odecl57 = ((int) (charcode.__hx_invoke2_f(0.0, ((double) (0) ), f, haxe.lang.Runtime.undefined)) );
					java.lang.Object __temp_odecl58 = ((java.lang.Object) (stat.__hx_invoke1_o(0.0, pf)) );
					__temp_stmt60 = new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"fileStat", "isDir", "name"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{__temp_odecl58, __temp_odecl56, f}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"firstLetter"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (__temp_odecl57) )) )}));
				}
				
				folder.push(__temp_stmt60);
			}
			
		}
		
		folder.sort(( (( finda.View_ls_buildFileStructure_75__Fun.__hx_current != null )) ? (finda.View_ls_buildFileStructure_75__Fun.__hx_current) : (finda.View_ls_buildFileStructure_75__Fun.__hx_current = ((finda.View_ls_buildFileStructure_75__Fun) (new finda.View_ls_buildFileStructure_75__Fun()) )) ));
		int h = this.y;
		{
			int _g = 0;
			while (( _g < folder.length ))
			{
				java.lang.Object file = folder.__get(_g);
				 ++ _g;
				java.lang.String tx = ( ( haxe.lang.Runtime.toString(haxe.lang.Runtime.getField(file, "name", true)) + "   " ) + ((int) (haxe.lang.Runtime.getField_f(haxe.lang.Runtime.getField(file, "fileStat", true), "size", true)) ) );
				java.awt.font.GlyphVector gv = font.createGlyphVector(((java.awt.font.FontRenderContext) (frc) ), haxe.lang.Runtime.toString(tx));
				int wide = metrics.stringWidth(haxe.lang.Runtime.toString(tx));
				int hi = metrics.getHeight();
				int l = gv.getNumGlyphs();
				java.awt.geom.GeneralPath newPath = new java.awt.geom.GeneralPath();
				int xpos = this.x;
				int ypos = h += hi;
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
				java.lang.Object __temp_stmt61 = null;
				{
					java.awt.Color __temp_odecl59 = ( (haxe.lang.Runtime.toBool(haxe.lang.Runtime.getField(file, "isDir", true))) ? (java.awt.Color.BLACK) : (java.awt.Color.BLUE) );
					__temp_stmt61 = new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"change", "color", "file", "generalPath", "shape"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{false, __temp_odecl59, file, newPath, shape}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"height", "width", "x", "y"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (hi) )) ), ((java.lang.Object) (((double) (wide) )) ), ((java.lang.Object) (((double) (xpos) )) ), ((java.lang.Object) (((double) (ypos) )) )}));
				}
				
				this.shapes.push(__temp_stmt61);
			}
			
		}
		
	}
	
	
	public   java.lang.Object overCheck(java.awt.event.MouseEvent e)
	{
		java.awt.Point point = e.getPoint();
		{
			int _g = 0;
			haxe.root.Array<java.lang.Object> _g1 = this.shapes;
			while (( _g < _g1.length ))
			{
				java.lang.Object fileView = _g1.__get(_g);
				 ++ _g;
				if (( ( ( ( haxe.lang.Runtime.compare(point.x, ((double) (haxe.lang.Runtime.getField_f(fileView, "x", true)) )) > 0 ) && ( point.x < ( ((double) (haxe.lang.Runtime.getField_f(fileView, "x", true)) ) + ((int) (haxe.lang.Runtime.getField_f(fileView, "width", true)) ) ) ) ) && ( haxe.lang.Runtime.compare(point.y, ((double) (haxe.lang.Runtime.getField_f(fileView, "y", true)) )) > 0 ) ) && ( point.y < ( ((double) (haxe.lang.Runtime.getField_f(fileView, "y", true)) ) + ((int) (haxe.lang.Runtime.getField_f(fileView, "height", true)) ) ) ) )) 
				{
					return fileView;
				}
				
			}
			
		}
		
		return null;
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef62 = true;
			switch (field.hashCode())
			{
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef62 = false;
						this.y = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef62 = false;
						this.x = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef62) 
			{
				return super.__hx_setField_f(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef63 = true;
			switch (field.hashCode())
			{
				case -903568142:
				{
					if (field.equals("shapes")) 
					{
						__temp_executeDef63 = false;
						this.shapes = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef63 = false;
						this.x = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 1094177291:
				{
					if (field.equals("repaint")) 
					{
						__temp_executeDef63 = false;
						this.repaint = ((haxe.lang.Function) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef63 = false;
						this.y = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3433509:
				{
					if (field.equals("path")) 
					{
						__temp_executeDef63 = false;
						this.path = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef63) 
			{
				return super.__hx_setField(field, value, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_getField(java.lang.String field, boolean throwErrors, boolean isCheck, boolean handleProperties)
	{
		{
			boolean __temp_executeDef64 = true;
			switch (field.hashCode())
			{
				case -793404268:
				{
					if (field.equals("overCheck")) 
					{
						__temp_executeDef64 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("overCheck"))) );
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef64 = false;
						return this.x;
					}
					
					break;
				}
				
				
				case -692613239:
				{
					if (field.equals("buildFileStructure")) 
					{
						__temp_executeDef64 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("buildFileStructure"))) );
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef64 = false;
						return this.y;
					}
					
					break;
				}
				
				
				case 251030602:
				{
					if (field.equals("secondPaint")) 
					{
						__temp_executeDef64 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("secondPaint"))) );
					}
					
					break;
				}
				
				
				case 3433509:
				{
					if (field.equals("path")) 
					{
						__temp_executeDef64 = false;
						return this.path;
					}
					
					break;
				}
				
				
				case -175217778:
				{
					if (field.equals("firstPaint")) 
					{
						__temp_executeDef64 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("firstPaint"))) );
					}
					
					break;
				}
				
				
				case 1094177291:
				{
					if (field.equals("repaint")) 
					{
						__temp_executeDef64 = false;
						return this.repaint;
					}
					
					break;
				}
				
				
				case -903568142:
				{
					if (field.equals("shapes")) 
					{
						__temp_executeDef64 = false;
						return this.shapes;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef64) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   double __hx_getField_f(java.lang.String field, boolean throwErrors, boolean handleProperties)
	{
		{
			boolean __temp_executeDef65 = true;
			switch (field.hashCode())
			{
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef65 = false;
						return ((double) (this.y) );
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef65 = false;
						return ((double) (this.x) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef65) 
			{
				return super.__hx_getField_f(field, throwErrors, handleProperties);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   java.lang.Object __hx_invokeField(java.lang.String field, haxe.root.Array dynargs)
	{
		{
			boolean __temp_executeDef66 = true;
			switch (field.hashCode())
			{
				case -793404268:
				{
					if (field.equals("overCheck")) 
					{
						__temp_executeDef66 = false;
						return this.overCheck(((java.awt.event.MouseEvent) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -175217778:
				{
					if (field.equals("firstPaint")) 
					{
						__temp_executeDef66 = false;
						this.firstPaint(((java.awt.Graphics2D) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -692613239:
				{
					if (field.equals("buildFileStructure")) 
					{
						__temp_executeDef66 = false;
						this.buildFileStructure(((java.awt.Graphics2D) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 251030602:
				{
					if (field.equals("secondPaint")) 
					{
						__temp_executeDef66 = false;
						this.secondPaint(((java.awt.Graphics2D) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef66) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("shapes");
		baseArr.push("repaint");
		baseArr.push("path");
		baseArr.push("y");
		baseArr.push("x");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


