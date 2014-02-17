package finda;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class PathInfo extends haxe.lang.HxObject
{
	public    PathInfo(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    PathInfo(java.lang.String path_)
	{
		finda.PathInfo.__hx_ctor_finda_PathInfo(this, path_);
	}
	
	
	public static   void __hx_ctor_finda_PathInfo(finda.PathInfo __temp_me10, java.lang.String path_)
	{
		__temp_me10.path = "./";
		__temp_me10.changePath(path_);
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new finda.PathInfo(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new finda.PathInfo(haxe.lang.Runtime.toString(arr.__get(0)));
	}
	
	
	public  java.lang.String path;
	
	public  java.lang.String full;
	
	public  java.lang.String parent;
	
	public   void changePath(java.lang.String path_)
	{
		if (( haxe.lang.Runtime.valEq(this.path, path_) && ( this.full != null ) )) 
		{
			return ;
		}
		
		this.path = path_;
		haxe.lang.Function charcode = ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (haxe.root.StringTools.class) ), haxe.lang.Runtime.toString("fastCodeAt"))) );
		this.full = sys.FileSystem.fullPath(this.path);
		int len = this.full.length();
		while (( ( len > 0 ) && ( ((int) (charcode.__hx_invoke2_f(0.0, ((double) (len--) ), this.full, haxe.lang.Runtime.undefined)) ) != 47 ) ))
		{
			{
			}
			
		}
		
		this.parent = ( haxe.lang.StringExt.substr(this.full, 0, ( len + 1 )) + "/" );
	}
	
	
	public   void tracePaths()
	{
		haxe.Log.trace.__hx_invoke2_o(0.0, 0.0, ( "path " + this.path ), new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"className", "fileName", "methodName"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{"finda.PathInfo", "PathInfo.hx", "tracePaths"}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"lineNumber"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (28) )) )})));
		haxe.Log.trace.__hx_invoke2_o(0.0, 0.0, ( "full " + this.full ), new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"className", "fileName", "methodName"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{"finda.PathInfo", "PathInfo.hx", "tracePaths"}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"lineNumber"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (29) )) )})));
		haxe.Log.trace.__hx_invoke2_o(0.0, 0.0, ( "parent " + this.parent ), new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"className", "fileName", "methodName"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{"finda.PathInfo", "PathInfo.hx", "tracePaths"}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"lineNumber"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (30) )) )})));
	}
	
	
	@Override public   java.lang.Object __hx_setField(java.lang.String field, java.lang.Object value, boolean handleProperties)
	{
		{
			boolean __temp_executeDef62 = true;
			switch (field.hashCode())
			{
				case -995424086:
				{
					if (field.equals("parent")) 
					{
						__temp_executeDef62 = false;
						this.parent = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 3433509:
				{
					if (field.equals("path")) 
					{
						__temp_executeDef62 = false;
						this.path = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
				case 3154575:
				{
					if (field.equals("full")) 
					{
						__temp_executeDef62 = false;
						this.full = haxe.lang.Runtime.toString(value);
						return value;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef62) 
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
			boolean __temp_executeDef63 = true;
			switch (field.hashCode())
			{
				case 973750953:
				{
					if (field.equals("tracePaths")) 
					{
						__temp_executeDef63 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("tracePaths"))) );
					}
					
					break;
				}
				
				
				case 3433509:
				{
					if (field.equals("path")) 
					{
						__temp_executeDef63 = false;
						return this.path;
					}
					
					break;
				}
				
				
				case -2132044811:
				{
					if (field.equals("changePath")) 
					{
						__temp_executeDef63 = false;
						return ((haxe.lang.Function) (new haxe.lang.Closure(((java.lang.Object) (this) ), haxe.lang.Runtime.toString("changePath"))) );
					}
					
					break;
				}
				
				
				case 3154575:
				{
					if (field.equals("full")) 
					{
						__temp_executeDef63 = false;
						return this.full;
					}
					
					break;
				}
				
				
				case -995424086:
				{
					if (field.equals("parent")) 
					{
						__temp_executeDef63 = false;
						return this.parent;
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef63) 
			{
				return super.__hx_getField(field, throwErrors, isCheck, handleProperties);
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
			boolean __temp_executeDef64 = true;
			switch (field.hashCode())
			{
				case 973750953:
				{
					if (field.equals("tracePaths")) 
					{
						__temp_executeDef64 = false;
						this.tracePaths();
					}
					
					break;
				}
				
				
				case -2132044811:
				{
					if (field.equals("changePath")) 
					{
						__temp_executeDef64 = false;
						this.changePath(haxe.lang.Runtime.toString(dynargs.__get(0)));
					}
					
					break;
				}
				
				
			}
			
			if (__temp_executeDef64) 
			{
				return super.__hx_invokeField(field, dynargs);
			}
			
		}
		
		return null;
	}
	
	
	@Override public   void __hx_getFields(haxe.root.Array<java.lang.String> baseArr)
	{
		baseArr.push("parent");
		baseArr.push("full");
		baseArr.push("path");
		{
			super.__hx_getFields(baseArr);
		}
		
	}
	
	
}


