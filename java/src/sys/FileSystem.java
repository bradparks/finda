package sys;
import haxe.root.*;

@SuppressWarnings(value={"rawtypes", "unchecked"})
public  class FileSystem extends haxe.lang.HxObject
{
	public    FileSystem(haxe.lang.EmptyObject empty)
	{
		{
		}
		
	}
	
	
	public    FileSystem()
	{
		sys.FileSystem.__hx_ctor_sys_FileSystem(this);
	}
	
	
	public static   void __hx_ctor_sys_FileSystem(sys.FileSystem __temp_me17)
	{
		{
		}
		
	}
	
	
	public static   void rename(java.lang.String path, java.lang.String newPath)
	{
		if ( ! (new java.io.File(haxe.lang.Runtime.toString(path)).renameTo(((java.io.File) (new java.io.File(haxe.lang.Runtime.toString(newPath))) ))) ) 
		{
			throw haxe.lang.HaxeException.wrap(( ( ( "Cannot rename " + path ) + " to " ) + newPath ));
		}
		
	}
	
	
	public static   java.lang.Object stat(java.lang.String path)
	{
		java.io.File f = new java.io.File(haxe.lang.Runtime.toString(path));
		if ( ! (f.exists()) ) 
		{
			throw haxe.lang.HaxeException.wrap(( ( "Path " + path ) + " doesn\'t exist" ));
		}
		
		{
			haxe.root.Date __temp_odecl79 = haxe.root.Date.now();
			haxe.root.Date __temp_odecl80 = haxe.root.Date.fromTime(((double) (f.lastModified()) ));
			haxe.root.Date __temp_odecl81 = haxe.root.Date.fromTime(((double) (f.lastModified()) ));
			int __temp_odecl82 = ((int) (f.length()) );
			return new haxe.lang.DynamicObject(new haxe.root.Array<java.lang.String>(new java.lang.String[]{"atime", "ctime", "mtime"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{__temp_odecl79, __temp_odecl81, __temp_odecl80}), new haxe.root.Array<java.lang.String>(new java.lang.String[]{"dev", "gid", "ino", "mode", "nlink", "rdev", "size", "uid"}), new haxe.root.Array<java.lang.Object>(new java.lang.Object[]{((java.lang.Object) (((double) (0) )) ), ((java.lang.Object) (((double) (0) )) ), ((java.lang.Object) (((double) (0) )) ), ((java.lang.Object) (((double) (0) )) ), ((java.lang.Object) (((double) (0) )) ), ((java.lang.Object) (((double) (0) )) ), ((java.lang.Object) (((double) (__temp_odecl82) )) ), ((java.lang.Object) (((double) (0) )) )}));
		}
		
	}
	
	
	public static   java.lang.String fullPath(java.lang.String relPath)
	{
		return new java.io.File(haxe.lang.Runtime.toString(relPath)).getAbsolutePath();
	}
	
	
	public static   boolean isDirectory(java.lang.String path)
	{
		java.io.File f = new java.io.File(haxe.lang.Runtime.toString(path));
		if ( ! (f.exists()) ) 
		{
			throw haxe.lang.HaxeException.wrap(( ( "Path " + path ) + " doesn\'t exist" ));
		}
		
		return f.isDirectory();
	}
	
	
	public static   haxe.root.Array<java.lang.String> readDirectory(java.lang.String path)
	{
		java.io.File f = new java.io.File(haxe.lang.Runtime.toString(path));
		if ( ! (f.exists()) ) 
		{
			throw haxe.lang.HaxeException.wrap(( ( "Path " + path ) + " doesn\'t exist" ));
		}
		
		return haxe.java.Lib.array(f.list());
	}
	
	
	public static   java.lang.Object __hx_createEmpty()
	{
		return new sys.FileSystem(((haxe.lang.EmptyObject) (haxe.lang.EmptyObject.EMPTY) ));
	}
	
	
	public static   java.lang.Object __hx_create(haxe.root.Array arr)
	{
		return new sys.FileSystem();
	}
	
	
}


