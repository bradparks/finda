package finda;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class FileViewCreator extends haxe.lang.HxObject
{
	public    FileViewCreator(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    FileViewCreator(java.awt.Graphics2D g2D, int x_)
	{
		finda.FileViewCreator.__hx_ctor_finda_FileViewCreator(this, g2D, x_);
	}
	
	
	public static   void __hx_ctor_finda_FileViewCreator(finda.FileViewCreator __temp_me7, java.awt.Graphics2D g2D, int x_)
	{
		__temp_me7.x = x_;
		__temp_me7.font = new java.awt.Font(haxe.lang.Runtime.toString("Georgia"), ((int) (java.awt.Font.PLAIN) ), ((int) (23) ));
		__temp_me7.frc = g2D.getFontRenderContext();
		__temp_me7.metrics = g2D.getFontMetrics(((java.awt.Font) (__temp_me7.font) ));
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new finda.FileViewCreator(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new finda.FileViewCreator(((java.awt.Graphics2D) (arr.__get(0)) ), ((int) (haxe.lang.Runtime.toInt(arr.__get(1))) ));
	}
	
	
	public  java.awt.Font font;
	
	public  java.awt.font.FontRenderContext frc;
	
	public  java.awt.FontMetrics metrics;
	
	public  int x;
	
	public final   java.lang.Object create(java.awt.Graphics2D g2D, java.lang.Object file, java.lang.String tx, int h, java.awt.Color c)
	{
		java.awt.font.GlyphVector gv = this.font.createGlyphVector(((java.awt.font.FontRenderContext) (this.frc) ), haxe.lang.Runtime.toString(tx));
		int wide = this.metrics.stringWidth(haxe.lang.Runtime.toString(tx));
		int hi = this.metrics.getHeight();
		int l = gv.getNumGlyphs();
		java.awt.geom.GeneralPath newPath = new java.awt.geom.GeneralPath();
		int xpos = this.x;
		int ypos = h += hi;
		{
			int _g = 0;
			while (( _g < ((int) (l) ) ))
			{
				int i = _g++;
				newPath.append(((java.awt.Shape) (gv.getGlyphOutline(((int) (i) ))) ), haxe.lang.Runtime.toBool(false));
			}
			
		}
		
		java.awt.geom.AffineTransform at2 = new java.awt.geom.AffineTransform();
		at2.translate(((double) (xpos) ), ((double) (ypos) ));
		java.awt.Shape shape = at2.createTransformedShape(((java.awt.Shape) (newPath) ));
		java.lang.Object fileView = new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"change", "color", "file", "generalPath", "shape"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{false, c, file, newPath, shape}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"height", "width", "x", "y"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (hi) )) ), ((java.lang.Object) (((double) (wide) )) ), ((java.lang.Object) (((double) (xpos) )) ), ((java.lang.Object) (((double) (ypos) )) )}));
		return fileView;
	}
	
	
	@Override public   double __hx_setField_f(java.lang.String field, double value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef48 = true;
			switch (field.hashCode())
			{
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef48 = false;
						this.x = ((int) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef48) 
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
			boolean __temp_executeDef49 = true;
			switch (field.hashCode())
			{
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef49 = false;
						this.x = ((int) (haxe.lang.Runtime.toInt(value)) );
						return value;
					}
					
					break;
				}
				
				
				case 3148879:
				{
					if (field.equals("font")) 
					{
						__temp_executeDef49 = false;
						this.font = ((java.awt.Font) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 955826371:
				{
					if (field.equals("metrics")) 
					{
						__temp_executeDef49 = false;
						this.metrics = ((java.awt.FontMetrics) (value) );
						return value;
					}
					
					break;
				}
				
				
				case 101655:
				{
					if (field.equals("frc")) 
					{
						__temp_executeDef49 = false;
						this.frc = ((java.awt.font.FontRenderContext) (value) );
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef49) 
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
			boolean __temp_executeDef50 = true;
			switch (field.hashCode())
			{
				case -1352294148:
				{
					if (field.equals("create")) 
					{
						__temp_executeDef50 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("create"))) );
					}
					
					break;
				}
				
				
				case 3148879:
				{
					if (field.equals("font")) 
					{
						__temp_executeDef50 = false;
						return this.font;
					}
					
					break;
				}
				
				
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef50 = false;
						return this.x;
					}
					
					break;
				}
				
				
				case 101655:
				{
					if (field.equals("frc")) 
					{
						__temp_executeDef50 = false;
						return this.frc;
					}
					
					break;
				}
				
				
				case 955826371:
				{
					if (field.equals("metrics")) 
					{
						__temp_executeDef50 = false;
						return this.metrics;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef50) 
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
			boolean __temp_executeDef51 = true;
			switch (field.hashCode())
			{
				case 120:
				{
					if (field.equals("x")) 
					{
						__temp_executeDef51 = false;
						return ((double) (this.x) );
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef51) 
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
			boolean __temp_executeDef52 = true;
			switch (field.hashCode())
			{
				case -1352294148:
				{
					if (field.equals("create")) 
					{
						__temp_executeDef52 = false;
						return this.create(((java.awt.Graphics2D) (dynargs.__get(0)) ), dynargs.__get(1), haxe.lang.Runtime.toString(dynargs.__get(2)), ((int) (haxe.lang.Runtime.toInt(dynargs.__get(3))) ), ((java.awt.Color) (dynargs.__get(4)) ));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef52) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			 else 
			{
				throw null;
			}
			
		}
		
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("x");
		baseArr.push("metrics");
		baseArr.push("frc");
		baseArr.push("font");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


