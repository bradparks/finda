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
	
	
	public    View_ls(finda.PathInfo pathInfo_, int x_, int y_)
	{
		finda.View_ls.__hx_ctor_finda_View_ls(this, pathInfo_, x_, y_);
	}
	
	
	public static   void __hx_ctor_finda_View_ls(finda.View_ls __temp_me11, finda.PathInfo pathInfo_, int x_, int y_)
	{
		__temp_me11.y = 0;
		__temp_me11.x = 0;
		__temp_me11.x = x_;
		__temp_me11.y = y_;
		__temp_me11.pathInfo = pathInfo_;
		__temp_me11.change();
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new finda.View_ls(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new finda.View_ls(((finda.PathInfo) (arr.__get(0)) ), ((int) (haxe.lang.Runtime.toInt(arr.__get(1))) ), ((int) (haxe.lang.Runtime.toInt(arr.__get(2))) ));
	}
	
	
	public  int x;
	
	public  int y;
	
	public  finda.PathInfo pathInfo;
	
	public  haxe.lang.Function repaint;
	
	public  haxe.root.Array<java.lang.Object> shapes;
	
	public   void change()
	{
		this.repaint = ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("firstPaint"))) );
	}
	
	
	public   void firstPaint(java.awt.Graphics2D g2D)
	{
		{
			java.lang.String p = this.pathInfo.path;
			haxe.lang.Function isDir = ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (sys.FileSystem.class) ), haxe.lang.Runtime.toString("isDirectory"))) );
			haxe.lang.Function stat = ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (sys.FileSystem.class) ), haxe.lang.Runtime.toString("stat"))) );
			haxe.lang.Function charcode = ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (haxe.root.StringTools.class) ), haxe.lang.Runtime.toString("fastCodeAt"))) );
			haxe.root.Array<java.lang.String> ls = sys.FileSystem.readDirectory(p);
			finda.FileViewCreator fileViewCreator = new finda.FileViewCreator(((java.awt.Graphics2D) (g2D) ), ((int) (this.x) ));
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
					
					java.lang.Object __temp_stmt73 = null;
					{
						int __temp_odecl71 = ((int) (charcode.__hx_invoke2_f(0.0, ((double) (0) ), f, haxe.lang.Runtime.undefined)) );
						java.lang.Object __temp_odecl72 = ((java.lang.Object) (stat.__hx_invoke1_o(0.0, pf)) );
						__temp_stmt73 = new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"fileStat", "isDir", "name"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{__temp_odecl72, hasDir, f}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"firstLetter", "subDirLen"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (__temp_odecl71) )) ), ((java.lang.Object) (((double) (len) )) )}));
					}
					
					folder.push(__temp_stmt73);
				}
				
			}
			
			folder.sort(( (( finda.Fun_519a9f19.__hx_current != null )) ? (finda.Fun_519a9f19.__hx_current) : (finda.Fun_519a9f19.__hx_current = ((finda.Fun_519a9f19) (new finda.Fun_519a9f19()) )) ));
			int h = this.y;
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
			
			this.shapes = shapes;
		}
		
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
				at2.translate(((double) (((int) (haxe.lang.Runtime.getField_f(fileView, "x", true)) )) ), ((double) (((int) (haxe.lang.Runtime.getField_f(fileView, "y", true)) )) ));
				java.awt.Shape shape = at2.createTransformedShape(((java.awt.geom.GeneralPath) (haxe.lang.Runtime.getField(fileView, "generalPath", true)) ));
				haxe.lang.Runtime.setField(fileView, "shape", shape);
				haxe.lang.Runtime.setField(fileView, "change", false);
			}
			
			g2D.fill(((java.awt.Shape) (haxe.lang.Runtime.getField(fileView, "shape", true)) ));
		}
		
	}
	
	
	public   void clicked(java.lang.Object f)
	{
		if (haxe.lang.Runtime.toBool(haxe.lang.Runtime.getField(haxe.lang.Runtime.getField(f, "file", true), "isDir", true))) 
		{
			if (haxe.lang.Runtime.valEq(haxe.lang.Runtime.toString(haxe.lang.Runtime.getField(haxe.lang.Runtime.getField(f, "file", true), "name", true)), "<-")) 
			{
				this.pathInfo.changePath(this.pathInfo.parent);
				this.change();
			}
			 else 
			{
				this.pathInfo.changePath(( ( ( this.pathInfo.full + "/" ) + haxe.lang.Runtime.toString(haxe.lang.Runtime.getField(haxe.lang.Runtime.getField(f, "file", true), "name", true)) ) + "/" ));
				this.change();
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
				if (( ( ( ( haxe.lang.Runtime.compare(point.x, ((int) (haxe.lang.Runtime.getField_f(fileView, "x", true)) )) > 0 ) && ( point.x < ( ((int) (haxe.lang.Runtime.getField_f(fileView, "x", true)) ) + ((int) (haxe.lang.Runtime.getField_f(fileView, "width", true)) ) ) ) ) && ( haxe.lang.Runtime.compare(point.y, ((int) (haxe.lang.Runtime.getField_f(fileView, "y", true)) )) > 0 ) ) && ( point.y < ( ((int) (haxe.lang.Runtime.getField_f(fileView, "y", true)) ) + ((int) (haxe.lang.Runtime.getField_f(fileView, "height", true)) ) ) ) )) 
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
			boolean __temp_executeDef74 = true;
			switch (field.hashCode())
			{
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef74 = false;
						this.y = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef74 = false;
						this.x = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef74) 
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
			boolean __temp_executeDef75 = true;
			switch (field.hashCode())
			{
				case -903568142:
				{
					if (field.equals("shapes")) 
					{
						__temp_executeDef75 = false;
						this.shapes = ((haxe.root.Array<java.lang.Object>) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef75 = false;
						this.x = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 1094177291:
				{
					if (field.equals("repaint")) 
					{
						__temp_executeDef75 = false;
						this.repaint = ((haxe.lang.Function) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef75 = false;
						this.y = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 1234084467:
				{
					if (field.equals("pathInfo")) 
					{
						__temp_executeDef75 = false;
						this.pathInfo = ((finda.PathInfo) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef75) 
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
			boolean __temp_executeDef76 = true;
			switch (field.hashCode())
			{
				case -793404268:
				{
					if (field.equals("overCheck")) 
					{
						__temp_executeDef76 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("overCheck"))) );
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef76 = false;
						return this.x;
					}
					
					break;
				}
				
				
				case 860524583:
				{
					if (field.equals("clicked")) 
					{
						__temp_executeDef76 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("clicked"))) );
					}
					
					break;
				}
				
				
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef76 = false;
						return this.y;
					}
					
					break;
				}
				
				
				case 251030602:
				{
					if (field.equals("secondPaint")) 
					{
						__temp_executeDef76 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("secondPaint"))) );
					}
					
					break;
				}
				
				
				case 1234084467:
				{
					if (field.equals("pathInfo")) 
					{
						__temp_executeDef76 = false;
						return this.pathInfo;
					}
					
					break;
				}
				
				
				case -175217778:
				{
					if (field.equals("firstPaint")) 
					{
						__temp_executeDef76 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("firstPaint"))) );
					}
					
					break;
				}
				
				
				case 1094177291:
				{
					if (field.equals("repaint")) 
					{
						__temp_executeDef76 = false;
						return this.repaint;
					}
					
					break;
				}
				
				
				case -1361636432:
				{
					if (field.equals("change")) 
					{
						__temp_executeDef76 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("change"))) );
					}
					
					break;
				}
				
				
				case -903568142:
				{
					if (field.equals("shapes")) 
					{
						__temp_executeDef76 = false;
						return this.shapes;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef76) 
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
			boolean __temp_executeDef77 = true;
			switch (field.hashCode())
			{
				case 121:
				{
					if (field.equals("y")) 
					{
						__temp_executeDef77 = false;
						return ((double) (this.y) );
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef77 = false;
						return ((double) (this.x) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef77) 
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
			boolean __temp_executeDef78 = true;
			switch (field.hashCode())
			{
				case -793404268:
				{
					if (field.equals("overCheck")) 
					{
						__temp_executeDef78 = false;
						return this.overCheck(((java.awt.event.MouseEvent) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case -1361636432:
				{
					if (field.equals("change")) 
					{
						__temp_executeDef78 = false;
						this.change();
					}
					
					break;
				}
				
				
				case 860524583:
				{
					if (field.equals("clicked")) 
					{
						__temp_executeDef78 = false;
						this.clicked(dynargs.__get(0));
					}
					
					break;
				}
				
				
				case -175217778:
				{
					if (field.equals("firstPaint")) 
					{
						__temp_executeDef78 = false;
						this.firstPaint(((java.awt.Graphics2D) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
				case 251030602:
				{
					if (field.equals("secondPaint")) 
					{
						__temp_executeDef78 = false;
						this.secondPaint(((java.awt.Graphics2D) (dynargs.__get(0)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef78) 
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
		baseArr.push("pathInfo");
		baseArr.push("y");
		baseArr.push("x");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


